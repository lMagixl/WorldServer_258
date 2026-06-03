# Administración de Personajes — Rakion World Server

Este documento cubre toda la funcionalidad de administración de personajes en el Rakion World Server, extraída del binario C++ descompilado (Ghidra). Detalla el ciclo de vida completo de las operaciones de personaje, desde la recepción del paquete de red hasta el procesamiento en BD y la respuesta.

> **Archivos relacionados:**
> - `login_flow.md` — flujo login completo (game → DB → DB Response → cliente)
> - `03_packet_opcodes.md` — tabla completa de 86 opcodes de red con handlers
> - `RAKION_RE_MASTER.md` — documento maestro (arquitectura, estructuras C++, DB, PRTCLIB crypto)
> - `lobby_phase.md` — [Fase Lobby/Sala] continuación después de seleccionar personaje
> - `01_functions_list.md` — lista de funciones con nombres reales anotados
> - `funcs/` — 151 archivos .c decompilados

---

## Contenido

1. [Visión General de la Arquitectura](#visión-general-de-la-arquitectura)
2. [Esquema Completo de Base de Datos](#esquema-completo-de-base-de-datos)
3. [Estructura del Paquete 0x0C+0x0D (Login Response + Character Data)](#estructura-del-paquete-0x0c0x0d-login-response--character-data)
4. [Crear Personaje (Opcode 0x12)](#crear-personaje-opcode-0x12)
5. [Eliminar Personaje (Opcode 0x13)](#eliminar-personaje-opcode-0x13)
6. [Seleccionar Personaje (Opcode 0x14)](#seleccionar-personaje-opcode-0x14)
7. [Registrar Nombre (Opcode 0x15)](#registrar-nombre-opcode-0x15)
8. [Cambiar Nombre (Opcode 0x19)](#cambiar-nombre-opcode-0x19)
9. [Tutorial Completado (Opcode 0x1A)](#tutorial-completado-opcode-0x1a)
10. [Códigos de Error](#códigos-de-error)
11. [Resumen de Formatos de Paquete](#resumen-de-formatos-de-paquete)
12. [Funciones Auxiliares Clave](#funciones-auxiliares-clave)
13. [Offsets de la Estructura Field](#offsets-de-la-estructura-field)

---

## Visión General de la Arquitectura

La gestión de personajes sigue un **pipeline de tres etapas** para cada operación:

```
Cliente → [Manejador de Red] → Cola BD → [Manejador BD] → [Manejador Respuesta BD] → Cliente
```

1. **Manejador de Red** (FUN_0041fcd0 / FUN_0041fe10 / etc.): Recibe el paquete crudo del cliente, valida el estado de la sesión, analiza el payload, y envía el trabajo a la cola de BD.
2. **Manejador BD** (FUN_00412280 / FUN_00412530 / etc.): Se ejecuta en el hilo trabajador de BD, realiza consultas SQL, y devuelve códigos de resultado.
3. **Manejador de Respuesta BD** (FUN_0041c3d0 / FUN_0041c4d0 / etc.): Lee los resultados de BD, actualiza la estructura del field del jugador, y envía el paquete de respuesta al cliente.

### Validación de Estado de Sesión

La mayoría de los manejadores validan dos campos críticos antes de procesar:

- `field+0x1460` — loginId (debe ser != 0, significa que el jugador está conectado)
- `field+0x14a4` — personaje seleccionado (debe ser 0 para crear/eliminar, significa que no hay personaje activo)

Si alguna validación falla, el manejador llama a `FUN_0041eb20` con un código de error, lo que desconecta al jugador.

### Cola de Envío BD (FUN_0041b940)

Todas las operaciones BD fluyen a través de esta función:

- Verifica `this+0x5368` (modo de cola BD)
- **Modo 1**: Usa `FUN_0042e630` (push directo con reintento + Sleep 10ms si cola llena)
  - Incrementa `this+0x51dc` (contador de reintentos)
  - Establece `this+0x59cc` = `0x23` (estado esperando), luego `0x24` (reintentando)
- **Modo 0**: Usa `FUN_0042e720` (push simple)
- Después del push: llama a `SetEvent(this+0xf4)` para despertar el hilo trabajador BD
- Incrementa `field+0x1488` (contador de transacciones de sesión)

### Formato de Entrada BD

Todas las entradas de la cola BD siguen este formato base:

```
[retOpcode:2][dbOpcode:2][datos...]
```

---

## Crear Personaje (Opcode 0x12)

### Resumen del Flujo

```
Cliente envía solicitud crear → FUN_0041fcd0 valida → envía a BD con opcode 7
→ FUN_00412280 ejecuta SQL → FUN_0041c3d0 caso 7 envía respuesta
```

### Manejador de Red — FUN_0041fcd0

**Firma:**
```cpp
void FUN_0041fcd0(CField* field, int param_2, LPCSTR param_3)
```

**Validación de Entrada:**
```cpp
if (field->loginId == 0 || field->characterSelected != 0) {
    FUN_0041eb20(field, 1, 0x19); // error: estado inválido
    return;
}
```

**Formato del Paquete (leído de param_3):**
```
[contador:2][7:2][sessionId:2][nombre:str\0][clase:1][slot:1]
```

**Lógica de Análisis:**
```cpp
int nameLen = lstrlenA(param_3);
if (nameLen > 12) { // >= 13 inválido
    FUN_0041eb20(field, 1, 0x1A); // error: nombre muy largo
    return;
}

BYTE charClass = param_3[nameLen + 1];
BYTE slot = param_3[nameLen + 2];

if (charClass >= 5) {
    FUN_0041eb20(field, 1, 0x1B); // error: clase inválida
    return;
}

if (slot >= 6) {
    FUN_0041eb20(field, 1, 0x19); // error: estado inválido
    return;
}
```

**Copia del Nombre:**
```cpp
char local_ffc[12]; // buffer local
lstrcpyA(local_ffc, param_3);
```

**Push a BD:**
```cpp
// Formato: [contador:2][7:2][sessionId:2][nombre\0][clase:1][slot:1]
FUN_0041b940(field, nameLen + 0x0B, local_ffc);
// Total: nameLen + 11 bytes base
```

**Códigos de Error:**
- `0x19` — Estado inválido (loginId==0 o personaje ya seleccionado)
- `0x1A` — Nombre muy largo (>12 caracteres)
- `0x1B` — Clase inválida (>=5)

---

### Manejador BD — FUN_00412280

**Firma:**
```cpp
void FUN_00412280(CField* field, int dbResult, int param_3, LPBYTE param_4)
```

**Entrada:** `retOpcode == 7` de la cola BD.

**Datos de Entrada (param_4):**
```
[loginId:4][nombre\0][clase:1][slot:1]
```

**Análisis:**
```cpp
int loginId = *(int*)param_4;
char local_1414[12]; // buffer nombre
lstrcpyA(local_1414, param_4 + 4);

int nameLen = strlen(local_1414);
BYTE bVar1 = param_4[nameLen + 5]; // clase
BYTE bVar2 = param_4[nameLen + 6]; // slot
```

**Lógica de Validación:**

```sql
-- 1. Verificación de slot inválido
IF bVar2 >= 6 THEN resultado = 1

-- 2. Slot ya ocupado
SELECT slot FROM CharacterInfo WHERE id = <loginId>
-- Si alguna fila coincide con el mismo slot → resultado = 2

-- 3. Demasiados personajes
-- Si row count > 5 → resultado = 3

-- 4. Nombre duplicado
SELECT id FROM CharacterInfo WHERE name = '<nombre>'
-- Si se encuentra → resultado = 4
```

**Ejecución SQL (en éxito):**
```sql
INSERT INTO CharacterInfo (name, userid, auth, class, slot, createtime, changetime)
VALUES ('<nombre>', <loginId>, 1, <clase>, <slot>, NOW(), NOW());

-- Obtener id insertado
int charId = mysql_insert_id();

UPDATE UserGameInfo SET charname = '<nombre>' WHERE id = <loginId>;
```

**Códigos de Resultado:**
| Código | Significado |
|--------|-------------|
| 0 | Éxito |
| 1 | Error BD (o slot inválido) |
| 2 | Slot ya ocupado |
| 3 | Demasiados personajes (>5) |
| 4 | Nombre ya existe |

**Salida de Respuesta BD:**
```cpp
// Éxito (resultado == 0):
// [retOpcode:2][7:2][resultado:1][charId:4][slot:1][clase:1][nombre:str\0]
// Total: 5 + nameLen + 7 = nameLen + 12 bytes

// Fracaso (resultado != 0):
// [retOpcode:2][7:2][resultado:1]
// Total: 5 bytes
```

---

### Manejador de Respuesta BD — FUN_0041c3d0 (Caso 7)

**Firma:**
```cpp
void FUN_0041c3d0(CField* field, LPBYTE param_3, int param_4)
```

**Análisis de Respuesta:**
```cpp
BYTE resultado = param_3[0]; // código de resultado
```

**Ruta de Éxito (resultado == 0):**
```cpp
BYTE slot = param_3[1];
int charId = *(int*)(param_3 + 2); // 4 bytes en offset 2
BYTE charClass = param_3[6];
char* nombre = param_3 + 7;
```

**Actualización de Estructura Field:**
```cpp
int slotOffset = slot * 0xD8; // 216 bytes por slot
int slotBase = slotOffset * 4; // 0x360 por slot en field

// Poner a cero el slot
memset(field + slotBase, 0, 0x360);

// Escribir datos del personaje
// Nombre al inicio del slot (20 bytes máx)
// Clase en slotBase + 0x355
// Flag activo en slotBase + 0x356 = 1
// Campo desconocido en slotBase + 0xD2*4 = 0x1A
```

**Respuesta de Red:**
```cpp
// Enviar al cliente
// [opcode=0x12:2][resultado:1][charId:4]
// Total: 7 bytes
```

**Distribución del slot en field (por personaje, 0xD8 = 216 bytes, repetido 4 veces = 0x360):**

| Offset | Tamaño | Campo |
|--------|--------|-------|
| 0x00 | 4 | charId (int) |
| 0x04 | 20 | nombre (char[20]) |
| ... | ... | ... |
| 0xD2*4 | 4 | Desconocido (se establece a 0x1A al crear) |
| 0xD4*4 | 4 | Desconocido |
| 0xD5*4 | 4 | Desconocido |
| 0xD6*4 | 1 | Desconocido |
| 0xD7*4 | 1 | charClass |
| 0xD8*4 | 1 | activeFlag (se establece a 1) |

---

## Eliminar Personaje (Opcode 0x13)

### Resumen del Flujo

```
Cliente envía solicitud eliminar → FUN_0041fe10 valida → envía BD con opcode 8
→ FUN_00412530 ejecuta SQL (manejador masivo ~500 líneas) → FUN_0041c4d0 caso 8 envía respuesta
```

### Manejador de Red — FUN_0041fe10

**Firma:**
```cpp
void FUN_0041fe10(CField* field, int param_2, LPCSTR param_3)
```

**Validación de Entrada:**
```cpp
if (field->loginId == 0 || field->characterSelected != 0) {
    FUN_0041eb20(field, 1, 0x1C); // error: estado inválido
    return;
}
```

**Análisis del Paquete:**
```cpp
// param_3 = [charId:4][nombre:11 máx\0]
int charId = *(int*)param_3;

char local_ff8[11]; // buffer nombre (máx 11 chars)
lstrcpynA(local_ff8, param_3 + 4, 0x0B); // máx 11 bytes
```

**Push a BD:**
```cpp
// Formato: [contador:2][8:2][charId:4][nombre\0]
FUN_0041b940(field, nameLen + 0x0D, local_ffc);
// Total: nameLen + 13 bytes
```

**Códigos de Error:**
- `0x1C` — Estado inválido (loginId==0 o personaje ya seleccionado)

---

### Manejador BD — FUN_00412530

**Firma:**
```cpp
void FUN_00412530(CField* field, int dbResult, int param_3, LPBYTE param_4)
```

**Entrada:** `retOpcode == 8` de la cola BD.

**Datos de Entrada:**
```
[charId:4][nombre:str\0]
```

Este es un **manejador masivo (~500 líneas** de código descompilado) con múltiples rutas de ejecución basadas en el nivel del personaje.

**Consulta Inicial:**
```sql
SELECT name, level, used, ..., deletekey, email, ..., userid
FROM CharacterInfo
WHERE id = <charId>
```

**Pasos de Validación:**

1. **Coincidencia de User ID** — `userid` debe coincidir con el `loginId` del jugador conectado
2. **Coincidencia de Nombre** — El nombre del personaje debe coincidir con el nombre proporcionado
3. **Restricciones de Nivel/Uso** — Verifica el flag `used` y el valor `level`

**Dos Rutas de Ejecución:**

#### Ruta A: Nivel < 15 (Eliminación Dura)
```sql
-- Eliminación permanente inmediata
DELETE FROM CharacterInfo WHERE id = <charId>;
DELETE FROM UserItemInfo WHERE id = <charId>;
DELETE FROM UserStageInfo WHERE id = <charId>;
```

#### Ruta B: Nivel >= 15 (Eliminación Suave con Sistema DeleteKey)
```cpp
// Establece auth=10, used=0 (eliminación suave / restauración posible)
UPDATE CharacterInfo SET auth = 10, used = 0, deletekey = <generado> WHERE id = <charId>;

INSERT INTO LogDeleteCharacter (...) VALUES (...);
// Registra la eliminación con timestamp para posible recuperación
```

**Códigos de Resultado:**
| Código | Significado |
|--------|-------------|
| 0 | Éxito (eliminación dura) |
| 1 | Error BD |
| 2 | Personaje no encontrado |
| 3 | En uso/restringido (personaje en uso o restricciones de nivel) |
| 4 | UserID no coincide (no es tu personaje) |
| 5 | DeleteKey no coincide |
| 6 | Email no encontrado (para verificación) |
| 7 | Email enviado (verificación pendiente) |
| 9 | Nombre no coincide |

**Salida de Respuesta BD:**
```cpp
// [retOpcode:2][8:2][resultado:1][charId:4][userid:4 si éxito]
```

---

## Seleccionar Personaje (Opcode 0x14)

### Resumen del Flujo

```
Cliente envía solicitud seleccionar → FUN_0041fef0 valida → carga datos del slot al workspace
→ llama entrada al canal → envía respuesta → transiciona a estado LOBBY (0x1440 = 0x02)
```

**ESTE ES EL PUNTO DE ENTRADA CRÍTICO AL LOBBY** — transiciona al jugador desde la pantalla de selección de personaje al sistema de lobby/canal.

### Manejador de Red — FUN_0041fef0

**Firma:**
```cpp
void FUN_0041fef0(CField* field, int param_2, int* param_3)
```

**Validación de Entrada:**
```cpp
if (field->loginId == 0 || field->characterSelected != 0) {
    FUN_0041eb20(field, 1, 0x1D); // error: estado inválido
    return;
}
```

**Análisis del Paquete:**
```cpp
int charId = *param_3; // desreferencia el primer elemento como int
```

**Iteración de Slots:**
```cpp
// Itera a través de 6 slots de personaje
// Cada slot es 0xD8 bytes
// Total: 6 * 0xD8 = 0x6C0 bytes
// En field: los slots están a stride 0xD8 * 4 = 0x360 cada uno

int iVar2;
for (iVar2 = 0; iVar2 < 6; iVar2++) {
    int slotBase = iVar2 * 0xD8 * 4; // o 0x360 por slot en field
    
    // Cada estructura de slot:
    // [charId:4][nombre:str(max20)][...0x360 bytes total...]
    int slotCharId = *(int*)(field + slotBase);
    
    if (slotCharId == charId) {
        // Coincidencia encontrada
        break;
    }
}
```

**En Coincidencia Encontrada (iVar2 < 6):**

Tres llamadas críticas ocurren en secuencia:

```cpp
// Paso 1: Cargar datos del personaje al workspace del field
FUN_0040be30(field, nombre, equipItemsPtr, skillPtr, ...);
// Copia datos del slot al área de personaje activo del field

// Paso 2: Validar acceso al slot de poción
FUN_0040d3f0(field, &resultado, &potionSlot);

// Paso 3: Establecer personaje activo + inicializar todas las estadísticas
FUN_0040ac30(field, charId, masterFlag, clase, raceVariant, ...);

// Paso 4: Establecer clase de personaje
field->charClassAt2368 = field->slotClass; // de slot[0xD7]
```

**Sin Coincidencia:**
```cpp
if (iVar2 == 6) {
    resultado = 2; // personaje no encontrado
}
```

**Respuesta de Red:**
```cpp
// Enviar: [opcode=0x14][resultado:1]
// Total: 3 bytes
```

**Entrada al Canal Post-Selección:**
```cpp
FUN_0041b8b0(field, fieldId);
// Encuentra canal y mete al jugador
```

**Códigos de Error:**
- `0x1D` — Estado inválido (loginId==0 o personaje ya seleccionado)
- Resultado 2 — Personaje no encontrado en ningún slot

---

## Registrar Nombre (Opcode 0x15)

### Manejador de Red — FUN_00420120

**Firma:**
```cpp
void FUN_00420120(CField* field, int param_2, LPCSTR param_3)
```

**Validación de Entrada:**
```cpp
if (field->loginId == 0) {
    return; // fallo silencioso si no está conectado
}
```

**Análisis del Paquete:**
```cpp
// param_3 = [nombre\0]
char local_ffc[12];
lstrcpyA(local_ffc, param_3);

int nameLen = lstrlenA(local_ffc);
if (nameLen >= 13) { // >= 0x0D
    return; // fallo silencioso si nombre muy largo
}
```

**Push a BD:**
```cpp
// Formato: [contador:2][0x0B:2][nombre\0]
FUN_0041b940(field, nameLen + 5, local_ffc);
// Total: nameLen + 5 bytes (2+2+nameLen+1)
```

---

## Cambiar Nombre (Opcode 0x19)

### Manejador de Red — FUN_00420760

**Firma:**
```cpp
void FUN_00420760(CField* field, int param_2, LPCSTR param_3)
```

**Validación de Entrada:**
```cpp
if (field->loginId == 0) {
    return; // fallo silencioso si no está conectado
}
```

**Análisis del Paquete:**
```cpp
// param_3 = [nuevoNombre\0]
char newName[12];
lstrcpyA(newName, param_3);

int nameLen = lstrlenA(newName);
if (nameLen >= 13) { // >= 0x0D
    return; // fallo silencioso si nombre muy largo
}
```

**Push a BD:**
```cpp
// Formato: [contador:2][0x0D:2][nuevoNombre\0]
FUN_0041b940(field, nameLen + 5, newName);
// Total: nameLen + 5 bytes (2+2+nameLen+1)
```

---

### Manejador BD — Cambiar Nombre (FUN_004144f0, BD Opcode 0x11)

**Firma:**
```cpp
void FUN_004144f0(CField* field, int dbResult, int param_3, LPBYTE param_4)
```

**Entrada:** `retOpcode == 0x11` de la cola BD.

**Datos de Entrada:**
```
[nuevoNombre\0]
```

**Validación:**

```sql
-- Verificar si el nombre ya existe
SELECT COUNT(*) FROM CharacterInfo WHERE name = '<nuevoNombre>';
-- Si COUNT > 0 → resultado = 1 (nombre existe)
```

**Obtención del Nombre Antiguo (vía JOIN):**
```sql
-- Obtiene nombre antiguo e info del usuario
SELECT c.name, u.id, u.cash FROM CharacterInfo c
JOIN UserGameInfo u ON u.id = c.userid
WHERE c.id = <charId>
```

**Cálculo del Costo:**
- Costo base: 2000 cash
- El precio puede modificarse basado en el **uso de cupón** (flag `cVar1`)
  - Si se usa cupón: `DELETE FROM UserItemInfo WHERE ...` (consume el ítem cupón)
  - `INSERT INTO logcoupon ...` (registra uso de cupón)

**Ejecución SQL (en validación de costo):**
```sql
UPDATE CharacterInfo SET name = '<nuevoNombre>' WHERE id = <charId>;
UPDATE Cash SET cash = cash - <costo> WHERE id = '<username>';
UPDATE UserGameInfo SET charname = '<nuevoNombre>' WHERE charname = '<nombreAntiguo>';
```

**Sistema de Regalo/Bonus:**
- Ítems de regalo aleatorios pueden darse al cambiar nombre
- `INSERT INTO ...` para ítems de regalo al inventario

**Registro:**
```sql
INSERT INTO LogChangeCharName (...) VALUES (...);
```

**Códigos de Resultado:**
| Código | Significado |
|--------|-------------|
| 0 | Éxito |
| 1 | El nombre ya existe |
| 2 | Cash insuficiente |
| 0x0B | Error BD |

**Formato de Salida:**
```cpp
// [retOpcode:2][0x11:2][resultado:1][cashReembolso:4][nuevoNombre\0][cuponUsado:1][cantRegalos:1][IDsRegalo...]
```

---

## Tutorial Completado (Opcode 0x1A)

### Manejador de Red — FUN_00420840

**Firma:**
```cpp
void FUN_00420840(CField* field, int param_2, int param_3)
```

**Sin respuesta al cliente** — solo se realiza una actualización en BD.

```cpp
int sessionId = field->sessionIdAt1488;

// Push BD: [contador:2][0x0E:2][sessionId:4]
// Total: 8 bytes (2+2+4)
FUN_0041b940(field, 8, &sessionId);
```

---

### Manejador BD — Tutorial (FUN_00413b00, BD Opcode 0x0E)

**Firma:**
```cpp
void FUN_00413b00(CField* field, int dbResult, int param_3, LPBYTE param_4)
```

**SQL:**
```sql
UPDATE UserGameInfo SET tutorial = 1 WHERE id = <userId>;
```

**Respuesta:**
```cpp
// [retOpcode:2][0x0E:2]
// Solo 4 bytes, sin payload
```

---

## Códigos de Error

### Códigos de Error de Manejadores (vía FUN_0041eb20)

| Código | Constante | Significado | Disparado Por |
|--------|-----------|-------------|---------------|
| 0x19 | 25 | Estado inválido (loginId==0 o personaje seleccionado) | Crear, Eliminar |
| 0x1A | 26 | Nombre muy largo (>12 caracteres) | Crear |
| 0x1B | 27 | Clase inválida (>=5) | Crear |
| 0x1C | 28 | Estado inválido (loginId==0 o personaje seleccionado) | Eliminar |
| 0x1D | 29 | Estado inválido (loginId==0 o personaje seleccionado) | Seleccionar |

### Códigos de Resultado BD

#### Crear Personaje
| Código | Significado |
|--------|-------------|
| 0 | Éxito |
| 1 | Error BD o slot inválido |
| 2 | Slot ya ocupado |
| 3 | Demasiados personajes (>5) |
| 4 | Nombre ya existe |

#### Eliminar Personaje
| Código | Significado |
|--------|-------------|
| 0 | Éxito (eliminación dura) |
| 1 | Error BD |
| 2 | Personaje no encontrado |
| 3 | En uso/restringido |
| 4 | UserID no coincide |
| 5 | DeleteKey no coincide |
| 6 | Email no encontrado |
| 7 | Email enviado (verificación) |
| 9 | Nombre no coincide |

#### Cambiar Nombre de Personaje
| Código | Significado |
|--------|-------------|
| 0 | Éxito |
| 1 | El nombre ya existe |
| 2 | Cash insuficiente |
| 0x0B | Error BD |

---

## Resumen de Formatos de Paquete

### Paquetes de Red Entrantes

| Opcode | Nombre | Formato |
|--------|--------|---------|
| 0x12 | Crear | `[contador:2][7:2][sessionId:2][nombre:str\0][clase:1][slot:1]` |
| 0x13 | Eliminar | `[charId:4][nombre:11 máx\0]` |
| 0x14 | Seleccionar | `[charId:4]` (accedido como puntero int) |
| 0x15 | Registrar Nombre | `[nombre\0]` |
| 0x19 | Cambiar Nombre | `[nuevoNombre\0]` |
| 0x1A | Tutorial | `[sessionId:4]` (vía acceso a field, no del paquete) |

### Paquetes de Red Salientes

| Opcode | Nombre | Formato | Tamaño |
|--------|--------|---------|--------|
| 0x12 | Respuesta Crear | `[resultado:1][charId:4][slot:1][clase:1][0x07:1]` | 8 bytes |
| 0x13 | Respuesta Eliminar | `[resultado:1][charId:4]` | 5 bytes |
| 0x14 | Respuesta Seleccionar | `[resultado:1]` | 1 byte |
| 0x15 | Eco Nombre | `[resultado:1][nombre:13\0][nombre:13\0]` | 27 bytes |
| 0x1E | ChannelCharacterState | `[resultado:1][cantidad:1][nombreCanal:13\0][...entradas jugador...]` | Variable |
| 0x1F | ChannelEnter | `[resultado:1][channelIdx:1][fieldId:2][nombre:13\0][flag:1]` | 18 bytes |

### Formato de Entrada Cola BD (cabecera común)

```
[retOpcode:2][dbOpcode:2][datos...]
```

### Formato de Respuesta BD por Operación

| BD Opcode | Operación | Formato Éxito | Formato Fracaso |
|-----------|-----------|----------------|-----------------|
| 7 | Crear | `[ret:2][7:2][0:1][charId:4][slot:1][clase:1][nombre\0]` | `[ret:2][7:2][err:1]` |
| 8 | Eliminar | `[ret:2][8:2][0:1][charId:4][userId:4]` | `[ret:2][8:2][err:1]` |
| 0x0B | Registrar Nombre | `[ret:2][0xB:2][resultado:1][nombre\0]` | `[ret:2][0xB:2][err:1]` |
| 0x0D | Cambiar Nombre | `[ret:2][0xD:2][0:1][cashReembolso:4][nombre\0][cupon:1][cantRegalos:1][IDsRegalo...]` | `[ret:2][0xD:2][err:1]` |
| 0x0E | Tutorial | `[ret:2][0xE:2]` | — |

---

## Funciones Auxiliares Clave

### FUN_0040be30 — Cargar Datos del Personaje al Workspace del Field

Copia los datos del slot del personaje desde el área de almacenamiento persistente al área de trabajo activa de la estructura field.

```cpp
void FUN_0040be30(CField* field, char* nombre, int* equipItems, int* skills, ...) {
    // Copiar nombre del jugador a field+0x14a8
    strcpy(field + 0x14a8, nombre);
    
    // Copiar 19 IDs de ítems (0x13 * 4 = 0x4C bytes) a field+0x157c
    memcpy(field + 0x157c, equipItems, 0x4C);
    
    // Copiar 9 valores de habilidad a field+0x17a8
    memcpy(field + 0x17a8, skills, 9 * 4);
    
    // Copiar bloque de ítems especiales (4 dwords + 2 bytes) a field+0x17ce
    memcpy(field + 0x17ce, specialItems, 18);
    
    // Copiar 19 IDs de equipo a field+0x17e4
    memcpy(field + 0x17e4, equipment, 0x4C);
    
    // Copiar 100 ítems de inventario a field+0x2174
    memcpy(field + 0x2174, inventory, 100 * 4);
    
    // Copiar 25 entradas de ítem a field+0x2304
    memcpy(field + 0x2304, itemEntries, 25 * 4);
}
```

### FUN_0040d3f0 — Validación de Slot de Poción

Valida y ajusta el slot de poción del jugador basado en la clase del personaje.

```cpp
void FUN_0040d3f0(CField* field, int* resultado, int* potionSlot) {
    BYTE charClass = *(BYTE*)(field + 0x1530);
    
    // PotionSlot = clase * 0x69 + id_item_pocion
    *potionSlot = charClass * 0x69 + GetPotionItemId(field);
    
    // Ajustar potionSlot contra el máximo permitido de la tabla de ítems del servidor
    int maxSlot = GetMaxPotionSlot(charClass);
    if (*potionSlot > maxSlot) {
        *potionSlot = maxSlot + 1; // ajustar al máximo anterior + 1
    }
}
```

### FUN_0040ac30 — Establecer Personaje Activo (SetChannelInfo / SetFieldChar)

Inicializa todas las estadísticas y el estado del jugador cuando se selecciona un personaje.

```cpp
void FUN_0040ac30(CField* field, int charId, int masterFlag, int charClass,
                  int raceVariant, int expGold, int hp, int mp, int level,
                  int atk1, int atk2, int defBlock) {
    // Identidad
    field->charId = charId;                     // +0x146c (también: flag host/maestro)
    field->uniqueId = charId;                   // +0x14a4 (personaje seleccionado)
    
    // Información de clase
    field->charClass = charClass;               // +0x1530
    field->raceVariant = raceVariant;           // +0x1531
    field->level = level;                       // +0x1540
    
    // Recursos
    field->expGold = expGold;                   // +0x1534
    field->hp = hp;                             // +0x1538
    field->mp = mp;                             // +0x153c
    
    // Estadísticas (11 ushorts consecutivos en +0x1550 a +0x1566)
    // [golpes, crit, hp, ap, velocidad, def, ...]
    ushort* stats = (ushort*)(field + 0x1550);
    InitializeDefaultStats(stats);
    
    // Configuración de combate
    field->attackSetting1 = atk1;               // +0x1544
    field->attackSetting2 = atk2;               // +0x1548
    field->defenseBlock = defBlock;             // +0x154c
    
    // Duplicado del workspace (0x17F dwords = 0x5FC bytes)
    memcpy(field + 0x1b78, field + 0x157c, 0x5FC);
    
    // Convertir nombre del jugador a minúsculas
    char* nombre = field + 0x14a8;
    char* lowerName = field + 0x14b5;
    ToLowercase(nombre, lowerName);
}
```

### FUN_0040ae90 — Resolvedor de Offsets del Field

Devuelve punteros a la estructura field para varios bloques de datos.

```cpp
void FUN_0040ae90(CField* field, char** out1, int** out2, int** out3,
                  int** out4, int** out5, int** out6, int** out7,
                  int** out8, int** out9, int** out10, int** out11) {
    *out1  = field + 0x14a8;  // nombre del jugador (char*)
    *out2  = field + 0x157c;  // IDs de ítems (19 dwords)
    *out3  = field + 0x17a8;  // habilidades (9 dwords)
    *out4  = field + 0x17ce;  // ítems especiales (4 dwords + 2 bytes)
    *out5  = field + 0x17e4;  // equipo (19 dwords)
    *out6  = field + 0x15c8;  // bloque de datos desconocido
    *out7  = field + 0x1830;  // bloque de datos desconocido
    *out8  = field + 0x1920;  // bloque de datos desconocido
    *out9  = field + 0x1998;  // bloque de datos desconocido
    *out10 = field + 0x2174;  // inventario (100 dwords)
    *out11 = field + 0x2304;  // entradas de ítem (25 dwords)
}
```

### FUN_0040af60 — Establecer Información de Canal

Transiciona al jugador al estado de lobby después de la selección de personaje.

```cpp
void FUN_0040af60(CField* field, int channelId, int fieldId) {
    field->channelId = channelId;   // +0x148c
    field->channelStatus = 1;       // +0x148d (flags)
    field->state = 0x02;            // +0x1440 = ESTADO LOBBY
    
    // Log: "RW......CUser::SetChannelInfo..."
    Log("RW......CUser::SetChannelInfo...");
}
```

### FUN_0041b8b0 — Buscador de Canal Post-Selección

Itera los canales disponibles y encuentra uno que acepte al jugador.

```cpp
void FUN_0041b8b0(CField* field, int fieldId) {
    CChannel* channels = (CChannel*)(field + 0xdc);
    int channelCount = *(int*)(field + 0xd8);
    
    for (int i = 0; i < channelCount; i++) {
        int resultado;
        if (FUN_00404fc0(&channels[i], null, fieldId, 1, &resultado)) {
            // El canal nos aceptó
            FUN_0040af60(field, i, fieldId);
            return;
        }
    }
}
```

### FUN_00404fc0 — Entrada a Canal / Estado del Personaje en Canal

Valida la capacidad del canal y mete al jugador.

```cpp
bool FUN_00404fc0(CChannel* channel, void* unk, int fieldId, int flag, int* resultado) {
    // Verificar estado abierto/cerrado del canal
    if (channel->state != 1) return false; // byte en this+1
    
    // Verificar cantidad de jugadores vs capacidad
    if (channel->playerCount >= channel->capacity) return false;
    // +0x35 = playerCount, +0x34 = capacity
    
    // Verificar contraseña (si se requiere)
    if (channel->password[0] != 0 && !CheckPassword(channel, unk)) return false;
    // +0x2b = password
    
    // Encontrar slot libre (100 slots * 8 bytes cada uno en +0x38)
    int slot = FindFreeSlot(channel);
    if (slot == -1) return false;
    
    // Enviar 0x1F (ChannelEnter)
    // [0x1F:2][resultado:1][channelSlot:1][fieldId:2] + nombre del jugador
    FUN_0040afb0(channel, field);
    
    // Enviar 0x1E (ChannelCharacterState)
    // [0x1E:2][nombreCanal] + nombres de jugadores
    FUN_0040afb0(channel, field);
    
    // Reiniciar temporizadores de interacción
    FUN_0040b670(field);
    
    return true;
}
```

### FUN_0040afb0 — Copiar Información del Jugador para Paquete de Canal

```cpp
int FUN_0040afb0(CField* field, BYTE* salida) {
    char* nombre = field + 0x14a8;
    int nameLen = strlen(nombre);
    
    // Copiar nombre del jugador
    memcpy(salida, nombre, nameLen + 1);
    
    // Anexar variante de clase/raza
    salida[nameLen + 1] = *(BYTE*)(field + 0x1531);
    
    // Anexar flag maestro/anfitrión
    salida[nameLen + 2] = *(int*)(field + 0x146c);
    
    // Anexar flag desconocido
    salida[nameLen + 3] = *(int*)(field + 0x14d0);
    
    return nameLen + 4; // nameLen + 1 + 3 bytes extra
}
```

### FUN_0040b670 — Reiniciar Estado de Lobby

```cpp
void FUN_0040b670(CField* field) {
    // Poner a cero el estado de interacción (11 bytes de +0x148e a +0x1499)
    memset(field + 0x148e, 0, 0x1499 - 0x148e + 1);
    
    // Establecer temporizador de inactividad al máximo
    field->inactivityTimer = 0xFFFFFFFF; // +0x149c
}
```

### FUN_0041eb20 — Manejador de Error / Desconexión

```cpp
void FUN_0041eb20(CField* field, int param_2, int errorCode) {
    // Registrar nombre de la función + estado del field
    char buffer[256];
    sprintf(buffer, "FUN_0041eb20: field state=%d, error=0x%X", field->state, errorCode);
    FUN_0041d380(buffer);
    
    if (field->loginId != 0) {
        FUN_0041ba00(field); // limpieza previa a desconexión
        
        if (param_2 == 1) { // desconectar
            // Enviar desconexión a BD: [contador:2][4:2][loginId:4][resultId:2]
            FUN_0041b940(field, 10, ...);
            
            // Formatear registro de desconexión
            char discBuffer[256];
            sprintf(discBuffer, "___%d__DISC__%d", field->id, errorCode);
            
            // Cerrar socket
            FUN_004038b0(field->socket);
            
            // Liberar recursos del field
            FUN_0040a8e0(field);
        }
    }
}
```

### FUN_0041ba00 — Limpieza Previa a Desconexión

```cpp
void FUN_0041ba00(CField* field) {
    // Serializar datos del jugador
    int dataSize = FUN_0040daf0(field, dataBuffer);
    
    if (dataSize > 0) {
        // Enviar guardado a BD: subTipo=0x22
        FUN_0041b940(field, dataSize + 4, dataBuffer);
    }
    
    // Si está en lobby (state 0x02)
    if (field->state == 0x02) {
        int channelIdx = FUN_0040af90(field); // obtener asignación de canal
        FUN_00405240(field, channelIdx);       // eliminar del canal
    }
    
    // Si está en sala (state 0x03)
    if (field->state == 0x03) {
        BroadcastRoomLeave(field);
        FUN_004091e0(field); // eliminar de la sala
    }
    
    // Liberar recursos del jugador
    FUN_0040d750(field);
}
```

---

## Offsets de la Estructura Field

### Campos de Estado Central

| Offset | Tamaño | Tipo | Descripción |
|--------|--------|------|-------------|
| +0x1440 | 1 | BYTE | **Estado**: 0x02=Lobby, 0x03=Sala |
| +0x1460 | 4 | int | **loginId** (distinto de cero = conectado) |
| +0x146c | 4 | int | **masterFlag** / charId (flag de anfitrión) |
| +0x1488 | 4 | int | **sessionId** / contador de transacciones |
| +0x148c | 1 | BYTE | **channelId** |
| +0x148d | 1 | BYTE | **channelStatus** (flags) |
| +0x148e | 11 | BYTE[] | **interactionState** (se pone a cero al entrar al lobby) |
| +0x149c | 4 | int | **inactivityTimer** (0xFFFFFFFF = inactivo) |
| +0x14a4 | 4 | int | **characterSelected** (uniqueId, 0=ninguno) |
| +0x14a8 | 13 | char[] | **playerName** |
| +0x14b5 | 13 | char[] | **playerNameLower** (copia en minúsculas) |
| +0x14d0 | 4 | int | **unknownFlag** |

### Estadísticas del Personaje

| Offset | Tamaño | Tipo | Descripción |
|--------|--------|------|-------------|
| +0x1530 | 1 | BYTE | **charClass** |
| +0x1531 | 1 | BYTE | **raceVariant** |
| +0x1534 | 4 | int | **expGold** (acumulado) |
| +0x1538 | 4 | int | **hp** |
| +0x153c | 4 | int | **mp** |
| +0x1540 | 4 | int | **level** |
| +0x1544 | 4 | int | **attackSetting1** |
| +0x1548 | 4 | int | **attackSetting2** |
| +0x154c | 4 | int | **defenseBlock** |
| +0x1550-0x1566 | 22 | ushort[11] | **stats** (golpes, crit, hp, ap, velocidad, etc.) |

### Bloques de Datos

| Offset | Tamaño | Descripción |
|--------|--------|-------------|
| +0x157c | 0x4C (76) | **itemIds** (19 dwords) |
| +0x15c8 | — | **unknownBlock1** |
| +0x17a8 | 0x24 (36) | **skills** (9 dwords) |
| +0x17ce | 18 | **specialItems** (4 dwords + 2 bytes) |
| +0x17e4 | 0x4C (76) | **equipment** (19 dwords) |
| +0x1830 | — | **unknownBlock2** |
| +0x1920 | — | **unknownBlock3** |
| +0x1998 | — | **unknownBlock4** |
| +0x1b78 | 0x5FC | **workspaceDuplicate** (copia de datos +0x157c) |
| +0x2174 | 400 | **inventory** (100 dwords) |
| +0x2304 | 100 | **itemEntries** (25 dwords) |
| +0x2368 | 1 | **charClassAt2368** (duplicado de +0x1530) |

### Distribución del Slot de Personaje (en field, 0x360 por slot, 6 slots total)

| Offset dentro del slot | Tamaño | Descripción |
|------------------------|--------|-------------|
| +0x00 | 4 | **charId** (int) |
| +0x04 | 20 | **nombre** (char[20]) |
| ... | ... | ... |
| +0xD2*4 | 4 | **desconocido** (se establece a 0x1A al crear) |
| +0xD7*4 | 1 | **charClass** |
| +0xD8*4 | 1 | **activeFlag** (1 = activo) |

### Array de Canales

| Offset | Tamaño | Descripción |
|--------|--------|-------------|
| +0xd8 | 4 | **channelCount** (int) |
| +0xdc | 0x358 * N | **Array CChannel** (cada entrada 0x358 bytes) |

#### Estructura por Canal (0x358 bytes cada uno)

| Offset | Tamaño | Descripción |
|--------|--------|-------------|
| +0x01 | 1 | **state** (abierto/cerrado) |
| +0x2b | 32 | **password** (char[32]) |
| +0x34 | 1 | **capacity** (máx jugadores) |
| +0x35 | 1 | **playerCount** |
| +0x38 | 800 | **playerSlots** (100 entradas * 8 bytes cada una) |

---

## Caso 8 de Respuesta BD (FUN_0041c4d0) — Respuesta de Selección de Personaje

**Firma:**
```cpp
void FUN_0041c4d0(CField* field, LPBYTE param_3, int param_4)
```

Se llama cuando BD devuelve resultado para selección de personaje (sub-tipo 0x14).

**Procesamiento:**
```cpp
BYTE resultado = param_3[0];

if (resultado == 0) {
    // Obtener punteros a la estructura field
    char* nombre; int* items; int* skills; /* etc */
    FUN_0040ae90(field, &nombre, &items, &skills, /* ... 11 salidas */);
    
    // Analizar bloque masivo de datos de param_3 comenzando en offset 0x1C
    // param_3+0x1C = nombre del jugador (strlen-1)
    // 19 items en field+0x157c
    // 9 habilidades en field+0x17a8
    // Varios bloques de datos de item/habilidad
    // Total: 0x14C8 bytes copiados
    
    // Inicializar personaje activo con estadísticas completas
    FUN_0040ac30(field, charId, masterFlag, /* ... stats */);
}

// Enviar al cliente
// [0x14:2][resultado:1][datos...0x69A bytes]
FUN_004038e0(field, buffer, dataSize);

// Entrar al canal
FUN_0041b8b0(field, fieldId);
```

---

## Transiciones de Estado del Field Completas

### Flujo de Creación de Personaje
```
Estado: Conectado (loginId != 0, charSelected == 0)
  → Cliente envía 0x12 (Crear)
  → Validar: loginId != 0 ✓, charSelected == 0 ✓
  → Analizar: nombre, clase, slot
  → Enviar a BD (opcode 7)
  → BD valida/INSERTa
  → Manejador de respuesta actualiza estructura de slot en field
  → Enviar respuesta al cliente
  → Estado: Todavía en pantalla de selección de personaje
```

### Flujo de Eliminación de Personaje
```
Estado: Conectado (loginId != 0, charSelected == 0)
  → Cliente envía 0x13 (Eliminar)
  → Validar: loginId != 0 ✓, charSelected == 0 ✓
  → Analizar: charId, nombre
  → Enviar a BD (opcode 8)
  → BD valida (verificación de nivel, propiedad)
  → Eliminación dura (nivel < 15) o eliminación suave (nivel >= 15)
  → Enviar respuesta al cliente
  → Estado: Todavía en pantalla de selección de personaje
```

### Flujo de Selección de Personaje (CRÍTICO — Entrada al Lobby)
```
Estado: Conectado (loginId != 0, charSelected == 0)
  → Cliente envía 0x14 (Seleccionar)
  → Validar: loginId != 0 ✓, charSelected == 0 ✓
  → Analizar: charId de param_3[0]
  → Iterar 6 slots para encontrar charId coincidente
  → Si se encuentra:
      FUN_0040be30: Cargar datos del personaje al workspace
      FUN_0040d3f0: Validar slot de poción
      FUN_0040ac30: Establecer personaje activo, inicializar todas las stats
      Establecer field+0x2368 = clase de personaje
  → Si no se encuentra: resultado = 2
  → Enviar respuesta
  → FUN_0041b8b0: Encontrar canal y entrar
  → FUN_0040af60: ESTABLECE ESTADO = 0x02 (LOBBY)
  → El jugador ahora está en el lobby
```

### Flujo de Desconexión / Error
```
Cualquier estado de error
  → Se llama a FUN_0041eb20 con código de error
  → Registra el error
  → Si está conectado:
      → FUN_0041ba00: Limpieza previa a desconexión
        → Serializar y guardar datos del jugador (si está en lobby/sala)
        → Eliminar del canal (si state == 0x02)
        → Eliminar de la sala (si state == 0x03)
        → Liberar recursos del jugador
      → Enviar desconexión a BD
      → Registrar desconexión con código de error
      → Cerrar socket de red
      → Liberar recursos del field
```

---

## Esquema Completo de Base de Datos

Todas las queries SQL fueron extraídas directamente de Ghidra (`FUN_004107d0.c` = DBCommandLogin, 42KB + otras funciones de BD en `funcs/`).

### Tabla: `user` — Autenticación de Login
```sql
SELECT password, country, NoCountryUpdate FROM user WHERE id='%s'
```
| Columna | Tipo | Descripción |
|---------|------|-------------|
| id | varchar(?) | Nombre de usuario (PK) |
| password | varchar(?) | Hash de contraseña |
| country | varchar(?) | País del usuario |
| NoCountryUpdate | tinyint | Flag para no actualizar país |

### Tabla: `UserGameInfo` — Datos Principales de Cuenta

**Query de login (carga TODO lo de la cuenta):**
```sql
SELECT id, (bandate>now()), clanid, clanpoint, clanrank, buddyname, powertime,
       powerlevelpoint, ban, charname, treeuppername, treerank, (createtime=0),
       gold, tutorial, slot, bag
FROM UserGameInfo WHERE name='%s'
```

| # | Columna | Tipo | Descripción |
|---|---------|------|-------------|
| 0 | id | int | Account ID auto-increment (FK desde CharacterInfo.userid) |
| 1 | (bandate>now()) | bool | 0=no baneado, 1=baneado |
| 2 | clanid | int | ID del clan (0=sin clan) |
| 3 | clanpoint | int | Puntos de contribución al clan |
| 4 | clanrank | int | Rango dentro del clan |
| 5 | buddyname | varchar(?) | Nombre del amigo/buddy |
| 6 | powertime | int | Minutos restantes de Power User |
| 7 | powerlevelpoint | int | Puntos de Power Level |
| 8 | ban | varchar(?) | Razón de ban / flag |
| 9 | charname | varchar(?) | Nombre del personaje activo |
| 10 | treeuppername | varchar(?) | Nombre en mayúsculas para búsqueda |
| 11 | treerank | int | Rango de árbol |
| 12 | (createtime=0) | bool | 1=primer login (INSERT inicial) |
| 13 | **gold** | int | **ORO del jugador** |
| 14 | tutorial | int | 0 o 1 (tutorial completado) |
| 15 | **slot** | int | **Slots de personaje disponibles** (default 5, máximo 10) |
| 16 | bag | int | Tamaño de mochila/inventario |

**Otras queries de UserGameInfo encontradas en Ghidra:**
```sql
-- Stage level free
SELECT stagelevelfree FROM usergameinfo WHERE id=%u
UPDATE usergameinfo SET stagelevelfree=%u WHERE id=%i

-- Rank grade
UPDATE UserGameInfo SET rankgrade=%u WHERE id=%u

-- Gold: INCREMENTO
UPDATE usergameinfo SET gold=gold+%u WHERE id=%u

-- Gold: DECREMENTO CON VALIDACIÓN
UPDATE UserGameInfo SET gold=gold-%u WHERE id=%u AND gold>=%u

-- Gold: LECTURA
SELECT gold FROM UserGameInfo WHERE id=%u
SELECT name, gold FROM UserGameInfo WHERE id=%u

-- Power User
SELECT gold, powertime FROM UserGameInfo WHERE id=%u
SELECT powertime FROM UserGameInfo WHERE id=%u
UPDATE UserGameInfo SET powertime=..., powerlevelpoint=%u WHERE id=%u
UPDATE usergameinfo SET powerlevelpoint=%u WHERE id=%u

-- Gestión de slots y mochila
UPDATE UserGameInfo SET slot=%u WHERE id=%u
UPDATE UserGameInfo SET bag=%u WHERE id=%u

-- Buddy system
UPDATE UserGameInfo SET buddyname='%s' WHERE id=%u
SELECT name, buddyname FROM usergameinfo WHERE clanid<>0 AND clanid=%u ...

-- Tutorial
UPDATE UserGameInfo SET tutorial=1 WHERE id=%u

-- Gestión de nombre de personaje
UPDATE usergameinfo SET charname='%s' WHERE id=%u and charname='%s'
UPDATE Usergameinfo SET charname='%s' WHERE charname='' AND id=%u

-- Ban
UPDATE UserGameInfo SET BanDate=DATE_ADD(now(), INTERVAL %u DAY) WHERE id=%u

-- Conexión
UPDATE UserGameInfo SET lastconnect=now(),country=%u WHERE id=%u
UPDATE UserGameInfo SET createtime=now() WHERE id=%u
UPDATE UserGameInfo SET UserCount=UserCount+1 WHERE id=%u
```

### Tabla: `Cash` — Dinero Cash (tabla SEPARADA, clave = STRING username)

```sql
SELECT cash FROM Cash WHERE id='%s'   -- %s = username, NO accountId numérico!
```

| Columna | Tipo | Descripción |
|---------|------|-------------|
| id | varchar(?) | Nombre de usuario (mismo que `user.id`) |
| cash | int | Cantidad de cash |

**Importante:** La tabla `Cash` usa el **username string** como clave, NO el accountId numérico. Hay **6 referencias idénticas** a esta query en distintas direcciones del binario, confirmando que el cash se usa en múltiples operaciones.

**Queries de mutación de Cash:**
```sql
-- Decremento con verificación de saldo suficiente
UPDATE Cash SET cash=cash-%u WHERE id='%s'
UPDATE Cash SET cash=cash-%u WHERE id='%s' AND cash>=%u
UPDATE cash SET cash = cash - %u WHERE id='%s' AND cash >= %u
```

### Tabla: `CharacterInfo` — Datos de Cada Personaje (hasta 10 por cuenta)

**Query de lista de personajes (durante login):**
```sql
SELECT slot, id, name, auth, class, level, exp, levelpoint,
       hit1, hit2, hit3, hit4, chit, hp, ap, attackspeed, speed, maxcp,
       rankgrade, win, lose, draw, totalrank, classrank, potionslot
FROM CharacterInfo WHERE userid=%u and auth<>%u
```

| # | Columna | Tipo | Offset en slot 0x360 | Descripción |
|---|---------|------|----------------------|-------------|
| 0 | slot | int | índice (0-9) | Número de slot del personaje |
| 1 | id | int | base+0x00 (4 bytes) | ID único del personaje |
| 2 | name | varchar(23) | base+0x04 | Nombre del personaje |
| 3 | auth | tinyint | base+0x354 | Nivel de auth (flag delete key) |
| 4 | class | tinyint | base+0x355 | Clase del personaje (0-4) |
| 5 | level | int | base+0x358 | Nivel |
| 6 | exp | int | base+0x35C | Experiencia acumulada |
| 7 | levelpoint | int | base+0x360 | Puntos de nivel |
| 8 | hit1 | smallint | base+0x364 | Estadística hit1 |
| 9 | hit2 | smallint | base+0x366 | Estadística hit2 |
| 10 | hit3 | smallint | base+0x368 | Estadística hit3 |
| 11 | hit4 | smallint | base+0x36A | Estadística hit4 |
| 12 | chit | smallint | base+0x36C | Golpe crítico |
| 13 | hp | smallint | base+0x36E | Puntos de vida |
| 14 | ap | smallint | base+0x370 | Puntos de habilidad |
| 15 | attackspeed | smallint | base+0x372 | Velocidad de ataque |
| 16 | speed | smallint | base+0x374 | Velocidad de movimiento |
| 17 | maxcp | smallint | base+0x376 | Puntos de combo máximos |
| 18 | rankgrade | tinyint | — | Grado de rango |
| 19 | win | int | — | Victorias |
| 20 | lose | int | — | Derrotas |
| 21 | draw | int | — | Empates |
| 22 | totalrank | int | — | Rango total |
| 23 | classrank | int | — | Rango de clase |
| 24 | potionslot | smallint | — | Slot de poción |

**Query de CharacterInfo usada en FUN_00412280 (crear personaje):**
```sql
INSERT INTO CharacterInfo (name, userid, auth, class, slot, createtime, changetime)
VALUES ('<name>', <loginId>, 1, <class>, <slot>, NOW(), NOW());
```

**Query de CharacterInfo usada en FUN_00412530 (eliminar personaje):**
```sql
SELECT name, level, used, auth, deletekey, email, userid
FROM CharacterInfo WHERE id = <charId>
```

### Tabla: `UserItemInfo` — Todos los Ítems

**Query de login (carga TODOS los ítems de la cuenta):**
```sql
SELECT id, characterid, itemid, level, limittime, slot, exp
FROM UserItemInfo WHERE userid=%u
```

| # | Columna | Tipo | Descripción |
|---|---------|------|-------------|
| 0 | id | int | PK del registro de ítem |
| 1 | characterid | int | **0 = compartido (global)**, >0 = FK a CharacterInfo.id |
| 2 | itemid | int | FK a ItemInfo.id (catálogo de ítems) |
| 3 | level | int | Nivel del ítem |
| 4 | limittime | int | Timestamp de expiración (0 = permanente) |
| 5 | slot | int | Posición en el inventario |
| 6 | exp | int | Experiencia del ítem |

**Query de items durante SELECT de personaje (opcode 0x14):**
```sql
SELECT slot, characterid, id, itemid, level, exp, limittime
FROM UserItemInfo WHERE userid=%u AND (characterid=0 OR characterid=%u)
```
Esta query carga TANTO items compartidos (characterid=0) COMO items del personaje seleccionado.

**Limpieza de items expirados:**
```sql
DELETE FROM UserItemInfo WHERE userid=%u AND limittime>0 AND limittime<%u
```

### Tabla: `UserStageInfo` — Progresión de Escenarios

```sql
SELECT stage, id, rank FROM UserStageInfo WHERE characterid=%u
```

| Columna | Tipo | Descripción |
|---------|------|-------------|
| characterid | int | FK a CharacterInfo.id |
| id | int | PK |
| stage | int | Número de escenario |
| rank | tinyint | Mejor rango obtenido (S/A/B/C/D) |

### Tabla: `ClanInfo` — Datos de Clan

```sql
SELECT rank, members, point, name, masterid FROM ClanInfo WHERE id=%u
```

| Columna | Tipo | Descripción |
|---------|------|-------------|
| id | int | ID del clan |
| rank | int | Rango del clan |
| members | int | Cantidad de miembros |
| point | int | Puntos del clan |
| name | varchar(?) | Nombre del clan |
| masterid | int | ID del maestro del clan |

### Otras Tablas de Log/Registro

| Tabla | Propósito | Query de Ejemplo |
|-------|-----------|------------------|
| `pendingpresents` | Regalos pendientes | `SELECT count(id) FROM pendingpresents WHERE user_id=%u` |
| `loggoldpresents` | Regalos de oro | `SELECT gold FROM loggoldpresents WHERE user_id=%u AND process_flg=0` |
| `LogUserConnect` | Login/logout | INSERT al conectar/desconectar |
| `LogCharStateClear` | Reseteo de stats | INSERT al resetear |
| `LogChangeCharName` | Cambio de nombre | INSERT al cambiar nombre |
| `LogBuyCashItem` | Compras cash | INSERT al comprar con cash |
| `LogUserItem` | Transacciones de items | INSERT al comprar/vender |
| `LogDeleteCharacter` | Eliminación de personaje | INSERT al eliminar (nivel >= 15) |
| `LogDiePlayer` | Muertes PvP | INSERT al morir en PvP |
| `LogStageClear` | Escenarios completados | INSERT al completar escenario |
| `logcoupon` | Uso de cupones | INSERT al usar cupón |
| `logpresent` | Envío de regalos | INSERT al enviar regalo |
| `logbuypoweruser` | Compras Power User | INSERT al comprar Power User |
| `lotto` | Boletos de lotería | SELECT/INSERT |
| `loglottery` | Resultados de lotería | INSERT |

### Tablas Estáticas (cargadas al iniciar el servidor)

```sql
-- AdminInfo: IPs y clases de admin
SELECT ... FROM AdminInfo

-- StageInfo: Definiciones de escenarios
SELECT ... FROM StageInfo

-- ClassLevelInfo: Tablas de EXP por nivel y clase
SELECT ... FROM ClassLevelInfo

-- ClassInfo: Estadísticas base por clase
SELECT ... FROM ClassInfo

-- NPCInfo: Definiciones de NPCs
SELECT slot, type, map FROM NPCInfo ...

-- ItemInfo: Catálogo de ítems
SELECT id, type, class, level, shop, gold, cash, hit1, hit2, hit3, hit4, chit, ap, hp, maxcp, power FROM ItemInfo

-- couponinfo: Definiciones de cupones
SELECT ... FROM couponinfo
```

La tabla `ItemInfo` es crítica — los items tienen campos `type` y `class` que determinan:
- **type**: Tipo de ítem (arma, armadura, poción, mascota, etc.)
- **class**: Clase restringida (0=todas, 1-4=clase específica)
- **shop**: Si se vende en tienda
- **gold/cash**: Precio en oro o cash

---

## Estructura del Paquete 0x0C+0x0D (Login Response + Character Data)

### Paquete 0x0C — Header + Lista de Personajes

El paquete 0x0C (login response) contiene:

```
[cabecera varios bytes]
[slotCount:1]           — cantidad de personajes
  por cada personaje:
  [charId:4]
  [charName\0]
  [win:8]              — long long (8 bytes)
  [lose:8]
  [draw:8]
  [rankgrade:1]
  [level+class+auth:4]  — packed
  [potionslot:8]        — long long (8 bytes)
  [class:1]
  [auth:1]
  [userAuth:1]
  [level:4]
  [exp:2]
  [levelpoint:2]
  [hit1..maxcp:10×2=20 bytes]  — 10 shorts
  [potionslot:2]        — short duplicado
  [9 skills:9×4=36 bytes]
  [skillExtra:2 bytes]
  [4 special items:4×4=16 bytes + 2 bytes]
  [19 equipment IDs:19×4=76 bytes]
  [19 backup item IDs:19×4=76 bytes]
  [19 item instance IDs:19×4=76 bytes]
  [25 item entries:25×4=100 bytes]
  [100 inventory items:100×4=400 bytes]
  [extra:1 byte]
```

**Total por personaje: 0x360 (864) bytes exactos.**

### Paquete 0x0D — Items Globales de Cuenta

Después de los personajes, el paquete 0x0D contiene los items compartidos:

```
[120 item IDs:120×4=480 bytes]     — global item IDs por slot
[120 item levels:120×1=120 bytes]  — niveles
[120 item exp:120×4=480 bytes]     — experiencia
[120 limittime:120×4=480 bytes]    — expiración
[120 DB IDs:120×4=480 bytes]       — IDs de base de datos
```

Los items con `characterid=0` en `UserItemInfo` van aquí. Son accesibles por cualquier personaje de la cuenta.

### Distribución Completa del Slot 0x360 (Personaje en Paquete de Red)

| Offset | Tamaño | Campo | Origen BD |
|--------|--------|-------|-----------|
| +0x00 | 4 | charId | CharacterInfo.id |
| +0x04 | string | name | CharacterInfo.name |
| tras name | 8 | win | CharacterInfo.win |
| +8 | 8 | lose | CharacterInfo.lose |
| +16 | 8 | draw | CharacterInfo.draw |
| +24 | 1 | rankgrade | CharacterInfo.rankgrade |
| +25 | 4 | level+class+auth (packed) | CharacterInfo.level, class, auth |
| +29 | 8 | potionslot (long long) | CharacterInfo.potionslot |
| +37 | 1 | class | CharacterInfo.class |
| +38 | 1 | auth | CharacterInfo.auth |
| +39 | 1 | userAuth | derivado |
| +40 | 4 | level | CharacterInfo.level |
| +44 | 2 | exp | CharacterInfo.exp |
| +46 | 2 | levelpoint | CharacterInfo.levelpoint |
| +48 | 20 | hit1, hit2, hit3, hit4, chit, hp, ap, attackspeed, speed, maxcp | CharacterInfo (10 shorts) |
| +0x32 | 2 | potionslot (short duplicado) | CharacterInfo.potionslot |
| +0x34 | 36 | **9 Skill IDs** (9×4) | UserItemInfo WHERE type=skill |
| +0x5A | 18 | **4 Special Items** (4×4 + 2 bytes) | UserItemInfo WHERE type=special |
| +0x6B | 76 | **19 Equipment IDs** (19×4) | UserItemInfo WHERE characterid=? |
| +0xB7 | 76 | **19 Backup Item IDs** (19×4) | UserItemInfo backup |
| +0x103 | 76 | **19 Item Instance IDs (dbId)** (19×4) | UserItemInfo.id |
| +0x14F | 100 | **25 Item Entries** (25×4) | UserItemInfo entries |
| +0x1B3 | 400 | **100 Inventory Item IDs** (100×4) | UserItemInfo WHERE slot<100 |
| +0x343 | 1 | byte extra | — |

**Nota:** Este slot de 0x360 bytes es LO QUE SE ENVÍA EN EL PAQUETE y también LO QUE SE ALMACENA EN MEMORIA. No es la estructura interna del servidor — es el formato serializado para la red.

### Workspace del Personaje (después de Seleccionar, Opcode 0x14)

Cuando el jugador selecciona un personaje, FUN_0040be30 copia los datos del slot serializado al workspace activo:

| Offset Field | Tamaño | Contenido | Origen en Slot 0x360 |
|-------------|--------|-----------|---------------------|
| +0x14a8 | 23 | playerName | Slot.name |
| +0x157c | 76 | 19 itemIds equipados | Slot+0x6B (equipment IDs) |
| +0x17a8 | 38 | 9 skills + 2 bytes | Slot+0x34 |
| +0x17ce | 18 | 4 specials + 2 bytes | Slot+0x5A |
| +0x17e4 | 76 | 19 equipment IDs (duplicado) | Slot+0x6B |
| +0x2174 | 400 | 100 inventory items | Slot+0x1B3 |
| +0x2304 | 100 | 25 item entries | Slot+0x14F |

### Items Compartidos de Cuenta (Global Inventory)

Los items con `characterid=0` en `UserItemInfo` son **compartidos entre todos los personajes de la cuenta**.

Se almacenan en el paquete 0x0D como 5 arrays paralelos de 120 slots:

| Array | Tamaño | Descripción |
|-------|--------|-------------|
| globalItemIds[120] | 4 bytes c/u | ID del ítem (ItemInfo.id) |
| globalItemLevels[120] | 1 byte c/u | Nivel del ítem |
| globalItemExp[120] | 4 bytes c/u | Experiencia del ítem |
| globalItemLimitTime[120] | 4 bytes c/u | Timestamp de expiración |
| globalItemDbId[120] | 4 bytes c/u | ID en UserItemInfo.id |

### Manejo de Oro (Gold)

El oro se carga de `UserGameInfo.gold` durante el login. Todas las operaciones que modifican oro usan **UPDATE con validación**:

```sql
-- Restar oro (con verificación de saldo suficiente)
UPDATE UserGameInfo SET gold=gold-%u WHERE id=%u AND gold>=%u

-- Sumar oro
UPDATE UserGameInfo SET gold=gold+%u WHERE id=%u

-- Leer oro
SELECT gold FROM UserGameInfo WHERE id=%u
SELECT name, gold FROM UserGameInfo WHERE id=%u
```

### Manejo de Cash

El cash está en una tabla **SEPARADA** de UserGameInfo. Usa el **username string** como clave:

```sql
-- Leer cash
SELECT cash FROM Cash WHERE id='%s'

-- Restar cash (con verificación)
UPDATE Cash SET cash=cash-%u WHERE id='%s' AND cash>=%u
```

No se encontró query para INSERT inicial en Cash — probablemente se crea la fila en el registro de usuario o tiene default 0.

### Pets / Crias

**NO EXISTEN como tabla separada.** Ghidra confirma cero resultados para "pet", "Pet", "PetInfo", "cria", "UserPetInfo". Las mascotas son simplemente **ítems regulares en UserItemInfo** con un `itemid` que apunta a un registro en `ItemInfo` donde `type` indica que es una mascota. Se cargan igual que cualquier otro ítem (equipment, inventory, o global).

### Sistema Power User

Campos en UserGameInfo:
- `powertime`: Minutos restantes de Power User (se decrementa con el tiempo)
- `powerlevelpoint`: Puntos de Power Level (se acumulan)

Queries:
```sql
SELECT gold, powertime FROM UserGameInfo WHERE id=%u
SELECT powertime FROM UserGameInfo WHERE id=%u
UPDATE UserGameInfo SET powertime=%u, powerlevelpoint=%u WHERE id=%u
UPDATE usergameinfo SET powerlevelpoint=%u WHERE id=%u
```

### Slots de Personaje por Cuenta

El campo `UserGameInfo.slot` controla **cuántos personajes puede tener la cuenta**. Valor default: 5. Máximo: 10.

```sql
-- Leer slots disponibles
SELECT slot FROM UserGameInfo WHERE id=%u

-- Actualizar slots (compra de slots adicionales)
UPDATE UserGameInfo SET slot=%u WHERE id=%u
```

El manejador de crear personaje (`FUN_00412280`) verifica `row count > UserGameInfo.slot` para el error 3 (demasiados personajes).

---

> **Siguiente fase:** Después de seleccionar personaje (opcode 0x14 con resultado 0), el jugador entra al LOBBY. Ver `lobby_phase.md` para los 14 opcodes de la fase Lobby/Sala, incluyendo movimiento, whisper, tienda, equipar, comprar, crear/unirse a salas, y lotería.
