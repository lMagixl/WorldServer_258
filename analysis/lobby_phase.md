# Fase de Lobby / Sala — Rakion World Server

Este documento cubre toda la funcionalidad de la fase de Lobby y Sala en el Rakion World Server, extraída del binario C++ descompilado (Ghidra). Detalla el ciclo de vida completo de las operaciones de lobby desde la recepción del paquete de red hasta la respuesta/difusión.

> **Archivos relacionados:**
> - `character_management.md` — antes de entrar al lobby: selección de personaje, DB schema, gold/cash/pets
> - `login_flow.md` — flujo login completo con transición a lobby
> - `03_packet_opcodes.md` — tabla completa de 86 opcodes de red con handlers
> - `RAKION_RE_MASTER.md` — documento maestro (arquitectura, estructuras C++, DB, PRTCLIB crypto)
> - `01_functions_list.md` — lista de funciones con nombres reales anotados
> - `funcs/` — 151 archivos .c decompilados
> - `shop_inventory_refinery.md` — sistema de tienda, inventario y refinería (Buy 0x74, Equip 0x73, Sell, Enchant, PowerUser)

---

## Contenido

1. [Visión General de la Máquina de Estados](#visión-general-de-la-máquina-de-estados)
2. [Lista de Salas (Opcode 0x36)](#lista-de-salas-opcode-0x36)
3. [Crear Sala (Opcode 0x2E / 0x3B)](#crear-sala-opcode-0x2e--0x3b)
4. [Unirse a Sala (Opcode 0x29 / 0x38)](#unirse-a-sala-opcode-0x29--0x38)
5. [Salir de Sala (Opcode 0x3E)](#salir-de-sala-opcode-0x3e)
6. [Invitar / Observar Sala (Opcode 0x2A)](#invitar--observar-sala-opcode-0x2a)
7. [Unión Rápida (Opcode 0x39)](#unión-rápida-opcode-0x39)
8. [Movimiento en Lobby (Opcode 0x31)](#movimiento-en-lobby-opcode-0x31)
9. [Mensaje Privado / Whisper (Opcode 0x16)](#mensaje-privado--whisper-opcode-0x16)
10. [Tienda / Lista de Ítems (Opcode 0x2F)](#tienda--lista-de-ítems-opcode-0x2f)
11. [Equipar / Desequipar (Opcode 0x73)](#equipar--desequipar-opcode-0x73)
12. [Comprar Ítem (Opcode 0x74)](#comprar-ítem-opcode-0x74)
13. [Lotería / Caja de Ítems (Opcode 0x75)](#lotería--caja-de-ítems-opcode-0x75)
14. [Códigos de Error](#códigos-de-error)
15. [Resumen de Formatos de Paquete](#resumen-de-formatos-de-paquete)
16. [Offsets de la Estructura de Sala](#offsets-de-la-estructura-de-sala)

---

## Visión General de la Máquina de Estados

El estado del jugador se rastrea en `field+0x1440`:

| Valor | Estado | Descripción |
|-------|--------|-------------|
| 0x00 | INIT | Estado inicial después de la conexión |
| 0x01 | CONECTANDO | Durante la autenticación |
| 0x02 | LOBBY | Después de seleccionar personaje, en el lobby |
| 0x03 | SALA | Dentro de una sala de juego |
| 0x04 | ADMIN | Modo admin/GameMaster |
| 0x05 | SUPER_ADMIN | Modo superadmin |

Después de seleccionar personaje (opcode 0x14), el jugador está en LOBBY (0x02).
Todos los manejadores de la fase lobby verifican que `field+0x1440 == 0x02` antes de procesar.

**Transiciones de estado durante operaciones de sala:**
- Crear/Unirse a Sala → el estado cambia a SALA (0x03) vía `FUN_0040b7b0`
- Salir de Sala → el estado vuelve a LOBBY (0x02) vía `FUN_004075a0`
- Desconexión → el estado se reinicia vía `FUN_0040b670` (limpia interacción + estado)

**Precondiciones para todos los manejadores de lobby:**
- `field+0x1460` (loginId) debe ser distinto de cero
- `field+0x14a4` (charId, personaje activo) debe ser distinto de cero
- `field+0x1440` (estado) debe coincidir con el valor esperado (generalmente 0x02 para lobby)

---

## Lista de Salas (Opcode 0x36)

**Manejador:** `FUN_00422c90`
**Archivo:** `funcs/FUN_00422c90.c` (216 líneas)
**Push BD:** No (solo memoria, itera slots de sala del canal)

### Validación de Estado
1. `field+0x1460 == 0` O `field+0x14a4 == 0` → error 0x46
2. `field+0x1440 != 0x02` (no LOBBY) → error 0x47

### Payload del Cliente (10 bytes)
```
[pageCount:1][pageIndex:2][modeFilter:1][raceFilter:1][minLevel:1][maxLevel:1][classFilter:1][gameTypeFilter:1][desconocido:1]
```
- `pageCount`: máx salas a devolver por página (debe ser ≤ 10, si no error 0x48)
- `pageIndex`: índice de página basado en 0 (debe ser < DAT_00455824 = maxSalas, si no error 0x49)
- `modeFilter`: 0 = filtro desactivado, valores distintos de cero activan modo específico
- `raceFilter`: filtro de restricción de raza
- `minLevel` / `maxLevel`: filtro de rango de nivel
- `classFilter`: filtro de clase
- `gameTypeFilter`: tipo de juego (0 = normal, ver switch abajo)
- `desconocido`: flag de filtro adicional

### Lógica de Filtrado de Salas
El manejador llama a `FUN_0040b6c0` para procesar los filtros, luego itera los slots de sala.

Cuando `gameTypeFilter == 0`:
- Itera la página de salas
- Verifica que la sala esté activa (+0x08 != 0)
- Si raceFilter == 0: llama a `FUN_0041b830` (verificación de disponibilidad de raza)
- Llama a `FUN_00405920` (verificación de compatibilidad clase/raza contra field+0x1531)
- Cambia según room+0x119 (tipo de juego):
  - 0 (PVP/VS): si modeFilter != 0, verifica estado de sala == 0x02 (esperando)
  - 1: coincide con bVar2 (filtro todos contra todos)
  - 2: coincide con bVar4
  - 3: coincide con bVar5
  - 4: coincide con bVar6
- Cuenta las salas que coinciden

Cuando `gameTypeFilter != 0`:
- Cambia según room+0x119 para coincidir con filtros de tipo de juego específicos de la misma manera

### Construcción de la Respuesta
Después del filtrado, el manejador construye la lista de salas:

```
[opcode=0x36:2][roomCount:1]
  [roomIndex:2][roomData:...]  (repetido roomCount veces)
```

Para cada sala que coincide:
1. Escribe el índice de sala (2 bytes) en el buffer en offset `uVar18`
2. Llama a `FUN_00405790(room, buffer+uVar18+2)` — serializa los datos de la sala al buffer
3. Avanza la posición del buffer por el tamaño de los datos de la sala

La serialización de sala `FUN_00405790` produce un bloque de longitud variable que contiene:
- Nombre de la sala (terminado en nulo)
- Estado de la sala (anfitrión, jugadores, etc.)
- Configuración de la sala (mapa, modo, flag de contraseña, rango de nivel, etc.)

### Envío de la Respuesta
```
FUN_004038e0(this+0x118, param_1, totalSize, &respuesta)
```
Transmite la lista de salas al jugador solicitante a través de su conexión.

---

## Crear Sala (Opcode 0x2E / 0x3B)

### Variante A: Creación Simple (Opcode 0x2E)

**Manejador:** `FUN_00421210`
**Archivo:** `funcs/FUN_00421210.c` (208 líneas)
**Push BD:** Sí (sub-opcode 0x14)

#### Validación de Estado
1. `field+0x1460 == 0` O `field+0x14a4 == 0` → error 0x36
2. `field+0x1440 != 0x02` (no LOBBY) → error 0x37

#### Payload del Cliente
```
[roomType:2][raceRestrict:1][gameMode:1][quickSlot:1]
```
- `roomType`: debe ser < `this+0x108` (máx tipos de sala), si no error 0x37
- `raceRestrict`: 0 = cualquier raza, distinto de cero = raza específica
- `gameMode`: `\x01` = modo batalla rápida (afecta cómo se establece el modo de juego)
- `quickSlot`: solo se usa cuando gameMode == 1

#### Flujo de Procesamiento
1. Llama a `FUN_0040cb10(this_00, roomType, raceRestrict, ...)` — crea estructuras de datos de sala:
   - Devuelve tablas `char*` (ítems disponibles en la tienda de la sala)
   - Devuelve arrays `ushort*` (cantidades de entrada de ítem)
   - Devuelve estructuras de datos similares a inventario
2. Si la creación falla (retorno != 0): envía error `[0x2E][errorCode:1]` (3 bytes)
3. Si tiene éxito: construye push BD para guardar la creación de la sala

#### Formato de Push BD (sub-opcode 0x14)
```
[sessionCounter:2][0x14:2][loginId:4][charId:4][roomType:2][raceRestrict:1][gameMode:1]
```
Más datos de ítem/entrada de longitud variable de la creación de la sala:
- `itemCount:1` + `itemTable[itemCount]`
- `entryCount:1` + `entryTable[entryCount]`
- `inventoryCount:1` + `inventoryTable[inventoryCount]` (de `FUN_0040cb10`)

#### Códigos de Error (0x2E)
- 0x36: No conectado/estado inválido
- 0x37: Tipo de sala o estado incorrecto
- El valor de retorno de `FUN_0040cb10` se usa directamente como código de error en el paquete de respuesta

---

### Variante B: Creación Completa (Opcode 0x3B)

**Manejador:** `FUN_00423580`
**Archivo:** `funcs/FUN_00423580.c` (203 líneas)
**Push BD:** Sí (sub-opcode 0x25)

#### Validación de Estado
1. `field+0x1460 == 0` O `field+0x14a4 == 0` → error 0x52
2. `field+0x1440 != 0x02` (no LOBBY) → error 0x53

#### Payload del Cliente (cadenas terminadas en nulo + datos binarios)
```
[nombreSala\0][contraseña\0][nombreMapa\0][mode:1][subMode:1][mapId:2][minLevel:1][maxLevel:1][raceRestrict:1][levelRange:1]
```
- `nombreSala`: máx 40 caracteres (0x28), si no error 0x54
- `contraseña`: máx 8 caracteres, si no error 0x55
- `nombreMapa`: máx 200 caracteres (0xC8), si no error 0x56
- `mode`: byte de modo de juego (0 = normal/rápido, 1-4 = personalizado con validación de mapa)
- `subMode`: sub-modo (debe ser < 5, si no error 0x5B)
- `mapId`: identificador de mapa de 2 bytes (validado dependiendo de subMode)
- `minLevel`/`maxLevel`: rango de nivel (0 o 1-99, si no error 0x59)

#### Validación de Modo (agrupada por subMode)

Cuando `subMode == 0`:
- `mode` debe ser < 100 (si no error 0x57)
- `mode` se usa como índice en la tabla de tipos de sala en `this+0xe8`
- Si la tabla de tipos de sala en `[mode*3]` es inválida: error 0x58

Cuando `subMode == 1`:
- `mapId` debe estar entre 0x122-0x4BA inclusive (si no error 0xCB)
- minLevel debe estar entre 13-30 inclusive (si no error 0xCC)
- Luego pasa a la validación general

Cuando `subMode == 2`:
- Misma validación mapId+minLevel que el modo 1

Cuando `subMode == 3`:
- minLevel debe estar entre 19-50 (0x13-0x32) inclusive (si no error 0xCC)
- Luego pasa a la validación general

Cuando `subMode == 4`:
- Misma validación mapId+minLevel que el modo 1

**Validación general después de la verificación del modo:**
- minLevel debe ser 0 o maxLevel debe ser 1-99
- minLevel debe ser <= field+0x1531 (clase del jugador)
- field+0x1531 debe ser <= maxLevel
- Si no error 0x5A

#### Ruta de Éxito
1. Encuentra un slot de sala vacío (itera `DAT_00455824` salas, verifica `+0x08 == 0`)
2. Llama a `FUN_0040af90` + `FUN_00405240` — búsqueda de canal + asignación de jugador
3. Llama a `FUN_00405440` — inicialización de la sala con todos los parámetros:
   - nombre de sala, contraseña, nombre de mapa, modo, subModo, mapId, minLevel, maxLevel
   - fieldId del jugador, raceRestrict, levelRange
4. Llama a `FUN_0040b7b0(field, roomIndex, masterFlag)`:
   - Establece room+0x08 byte activo (0x13 si masterFlag=0x01, si no 0)
   - Establece field+0x1440 = 0x03 (estado SALA)
   - Establece field+0x1458 = roomIndex
   - Establece field+0x1451 = masterFlag
5. Envía respuesta de éxito: `[0x3B:2][resultado:1][roomIndex:2]` (5 bytes)

#### Formato de Push BD (sub-opcode 0x25)
```
[sessionCounter:2][0x25:2][loginId:4][nombreSala\0][contraseña\0][nombreMapa\0][mode:1][subMode:1][mapId:2][minLevel:1][maxLevel:1][raceRestrict:1][levelRange:1]
```

---

## Unirse a Sala (Opcode 0x29 / 0x38)

### Variante A: Unión Simple (Opcode 0x29)

**Manejador:** `FUN_00420c20`
**Archivo:** `funcs/FUN_00420c20.c` (24 líneas)
**Push BD:** No (delega a `FUN_00406240`)

#### Validación de Estado
1. `field+0x1460 == 0` O `field+0x14a4 == 0` → error 0x2E
2. `field+0x1440 != 0x03` (no estado SALA) — NOTA: ¡esto espera estado SALA!

#### Payload del Cliente
```
[roomIndex:2][contraseña?]
```
- `roomIndex`: debe ser < `DAT_00455824` (máx salas), si no error 0x2F

#### Flujo de Procesamiento
1. Obtiene puntero a la sala: `this->+0xe4 + roomIndex * 0x3c0`
2. Verifica room+0x08 flag activo
3. Llama a `FUN_00406240(room, playerFieldId, contraseña)` — lógica de unión a sala:
   - Valida coincidencia de contraseña
   - Añade jugador a los slots de jugadores de la sala
   - Transmite la unión del jugador a los miembros de la sala
   - Actualiza el estado de la sala

**Nota:** El opcode 0x29 espera que el jugador ya esté en estado SALA (0x03). Esto sugiere que se usa para cambiar de sala o reconectar, no para la transición inicial lobby→sala.

---

### Variante B: Unión con Contraseña (Opcode 0x38)

**Manejador:** `FUN_00423100`
**Archivo:** `funcs/FUN_00423100.c` (74 líneas)
**Push BD:** Sí (sub-opcode 0x26) O unión directa a sala

#### Validación de Estado
1. `field+0x1460 == 0` O `field+0x14a4 == 0` → error 0x4A
2. `field+0x1440 != 0x02` (no LOBBY) → envía error `[0x38][0x05:1]` (3 bytes)

#### Payload del Cliente
```
[roomIndex:2][contraseña\0]
```
- `roomIndex`: debe ser < `DAT_00455824` (máx salas), si no error 0x4C
- `contraseña`: terminada en nulo, máx 8 caracteres, si no error 0x4D

#### Flujo de Procesamiento
1. Obtiene puntero a la sala: `this->+0xe4 + roomIndex * 0x3c0`
2. Verifica room+0x119 (tipo de juego):
   - Si tipo de juego == 0 (normal): **Ruta push BD**
     - Construye paquete: `[sessionCounter:2][0x26:2][loginId:4][roomIndex:2][contraseña\0]`
     - Envía a BD vía `FUN_0041b940`
   - Si tipo de juego != 0 (personalizado): **Ruta de unión directa**
     - Llama a `FUN_00406f40(room, 0, contraseña, fieldId, resultFlag, 0)` — valida + une
     - Si tiene éxito:
       - `FUN_0040af90(field, channelIndex, channelSlot)` — asignación de canal
       - `FUN_00405240(channel, slotByte)` — actualiza slot de jugador en canal
       - `FUN_0040b7b0(field, roomIndex, masterFlag)` — establece estado de sala + flag

---

### Bonus: Unión Rápida (Opcode 0x39)

**Manejador:** `FUN_00423300`
**Archivo:** `funcs/FUN_00423300.c`
**Push BD:** No

Unión rápida/auto-match que encuentra una sala disponible que coincida con los criterios del jugador y se une a ella.

---

## Salir de Sala (Opcode 0x3E)

**Manejador:** `FUN_00423b70`
**Archivo:** `funcs/FUN_00423b70.c` (21 líneas)
**Push BD:** No (delega a `FUN_004075a0`)

#### Validación de Estado
1. `field+0x1460 == 0` O `field+0x14a4 == 0` → error 0x62
2. `field+0x1440 != 0x03` (no SALA) → error 99 (0x63)

#### Flujo de Procesamiento
```
FUN_0040b7d0(field, &roomIndex, &channelIndex);
FUN_004075a0(room, channelIndex, 0);
```
1. `FUN_0040b7d0` — extrae el índice de sala y el índice de canal del field
2. `FUN_004075a0` — lógica de salida de sala:
   - Elimina al jugador del slot de la sala
   - Actualiza el contador de jugadores de la sala
   - Transmite la salida del jugador a los miembros restantes de la sala
   - Establece field+0x1440 = 0x02 (de vuelta a LOBBY)
   - Limpia las entradas del field relacionadas con la sala

---

## Invitar / Observar Sala (Opcode 0x2A)

**Manejador:** `FUN_00420cb0`
**Archivo:** `funcs/FUN_00420cb0.c` (44 líneas)
**Push BD:** No

#### Payload del Cliente
```
[targetPlayerId:2]
```
- `targetPlayerId`: el índice del slot del field del jugador a invitar/observar

#### Flujo de Procesamiento
1. Si el objetivo está en el lobby (estado 0x02):
   - Construye paquete de invitación: 8 bytes que contienen datos de invitación
   - Envía al jugador objetivo

---

## Movimiento en Lobby (Opcode 0x31)

**Manejador:** `FUN_00421870`
**Archivo:** `funcs/FUN_00421870.c` (102 líneas)
**Push BD:** No (transmite a otros jugadores en el lobby)

#### Validación de Estado
1. `field+0x1460 == 0` O `field+0x14a4 == 0` → error 0x3C
2. `field+0x1440 != 0x02` (no LOBBY) → error 0x3D

#### Payload del Cliente (4 bytes)
```
[x:1][y:1][z:1][w:1]
```
- Coordenadas de posición

#### Validación de Coordenadas
- Si x == 0: x debe ser < 0x78 (120), si no error 0x3E
- Si x != 0: x debe ser < 0x13 (19), si no error 0x3E
- Si z == 0: w debe ser < 0x78 (120), si no error 0x3E
- Si z != 0: w debe ser < 0x13 (19), si no error 0x3E

#### Flujo de Procesamiento
1. Llama a `FUN_0040cf10(field, x, y, z, w, &outX, &outY, &outZ, &outZ2, &outW, &outW2)`:
   - Procesa las coordenadas de movimiento
   - Devuelve flags/estado para el paquete de difusión
2. Construye paquete de difusión:
```
[opcode=0x31:2][playerX:1][playerY:1][z:1][w:1][derivado1:1][x2:4][y2:4][z2:4][w2:4][flags:?][resultado2:?]
```
3. Llama a `FUN_004038e0(broadcastList, senderFieldId, packetSize, &paquete)`:
   - Transmite el movimiento a TODOS los demás jugadores en el mismo lobby
   - El remitente recibe su propio eco de movimiento (fieldId = param_1)

**El tamaño del paquete siempre es 0x15 (21) bytes incluyendo el opcode.**

---

## Mensaje Privado / Whisper (Opcode 0x16)

**Manejador:** `FUN_00420200`
**Archivo:** `funcs/FUN_00420200.c` (72 líneas)
**Push BD:** No (envía directamente al jugador objetivo)

#### Validación de Estado
1. `field+0x1460 == 0` O `field+0x14a4 == 0` → error 0x21

#### Payload del Cliente (dos cadenas terminadas en nulo)
```
[nombreObjetivo\0][mensaje\0]
```
- `nombreObjetivo`: máx 12 caracteres, si no error 0x22
- `mensaje`: máx 128 caracteres (0x80), si no error 0x23

#### Flujo de Procesamiento
1. Copia nombreObjetivo al buffer local
2. Copia mensaje (comienza después del terminador nulo de nombreObjetivo)
3. Itera TODOS los jugadores conectados (DAT_00456030 máx):
   - Para cada jugador con estado != 0, loginId != 0, charId != 0:
     - Llama a `FUN_0040af20(jugador, nombreObjetivo)` — comparación de nombres
     - Si coincide Y el masterFlag del remitente != 1:
       - Construye paquete de whisper:
```
[opcode=0x16:2][resultado=0x00:1]
[nombreRemitente\0][mensaje\0]
```
       - Envía al OBJETIVO: `FUN_004038e0(this->0x118, targetFieldId, size, &paquete)`
       - Envía al REMITENTE: `FUN_004038e0(this->0x118, senderFieldId, size, &paquete)`
       - Retorna (éxito)
4. Si no se encuentra el objetivo: envía paquete de error:
```
[opcode=0x16:2][resultado=0x01:1]
```
   - Enviado solo al remitente (3 bytes total)

**Nota:** El sistema de eco de paquete significa que tanto el remitente como el receptor ven el mensaje.
El byte de resultado 0x00 = encontrado, 0x01 = no encontrado.

---

## Tienda / Lista de Ítems (Opcode 0x2F)

**Manejador:** `FUN_004215a0`
**Archivo:** `funcs/FUN_004215a0.c` (151 líneas)
**Push BD:** Sí (sub-opcode 0x15)

#### Validación de Estado
1. `field+0x1460 == 0` O `field+0x14a4 == 0` → error 0x39
2. `field+0x1440 != 0x02` (no LOBBY) → error 0x3A

#### Payload del Cliente
```
[shopCategory:1]
```
- `shopCategory`: debe ser < 0x78 (120), si no error 0x3B

#### Flujo de Procesamiento
1. Llama a `FUN_0040cd70(field, category, ...)` — consulta ítems de la tienda:
   - Devuelve arrays de ítems disponibles para compra en esta categoría
   - Devuelve cantidad de ítems de la categoría + valores de flag
2. Si se devuelve error: envía `[0x2F][errorCode:1]` (3 bytes)
3. En éxito, construye push BD:

#### Formato de Push BD (sub-opcode 0x15)
```
[sessionCounter:2][0x15:2][loginId:4][charId:4][category:1][datosSubCategoria:?][itemIds...][precios...][cantidades...]
```
- Datos de ítem de longitud variable de `FUN_0040cd70`:
  - Primer array: IDs de ítem de 4 bytes (`itemCount` ítems)
  - Seguido por: IDs de formato variable para cada ítem
  - Segundo array: valores de grupo/entrada de 4 bytes (`itemCount` ítems)
  - Tercer array: datos de inventario/tienda de 4 bytes
  - Luego un byte de flag para `hasSubItems` + datos de sub-ítem opcionales

**Nota:** "Push BD" significa que la solicitud de tienda se registra/procesa a través del hilo BD, no que los datos de la tienda se almacenen. El catálogo real de ítems se carga desde la memoria del servidor.

---

## Equipar / Desequipar (Opcode 0x73)

**Manejador:** `FUN_00421a50`
**Archivo:** `funcs/FUN_00421a50.c` (193 líneas)
**Push BD:** Sí (sub-opcode 0x27)

#### Validación de Estado
1. `field+0x1460 == 0` O `field+0x14a4 == 0` → error 0xDE
2. `field+0x1440 != 0x02` (no LOBBY) → error 0xDF

#### Payload del Cliente
```
[itemSlot:1][equipSlot:1]
```
- `itemSlot`: slot del inventario del ítem a equipar (debe ser < 0x78)
- `equipSlot`: slot de equipo donde equipar (debe ser < 0x78)

**Nota:** Si equipSlot >= 0x78 → error 0xE0
Si itemSlot >= 0x78 → error 0xE1

#### Flujo de Procesamiento
1. Llama a `FUN_0040ca50(field, ...)` — obtiene el estado actual de equipo/inventario:
   - Devuelve lista de ítems equipados (19 entradas)
   - Devuelve cantidades de ítems (5 entradas)
   - Devuelve ítems de inventario (100 entradas)
   - Devuelve cantidades de entrada (30 entradas)
   - Devuelve flags de estado de equipamiento del personaje
 2. Llama a `FUN_0040c140(field, itemSlot, equipSlot, ...)` — realiza equipar/desequipar (ver `shop_inventory_refinery.md §5.3` para análisis detallado):
   - Valida que el ítem se pueda equipar en el slot objetivo
   - Devuelve arrays de equipo actualizados
   - Devuelve código de éxito/fracaso
3. Si equipar falla: envía `[0x73][errorCode:1]` (3 bytes)
4. En éxito, construye push BD:

#### Formato de Push BD (sub-opcode 0x27)
```
[sessionCounter:2][0x27:2][loginId:4][charId:4][itemSlot:1][equipSlot:1][equipData:76 bytes?][countData:20 bytes?][inventoryData:...][flags...]
```
- Serialización de longitud variable de:
  - Array de equipo actualizado (entradas itemSlot × 4 bytes)
  - Arrays de cantidad actualizados
  - Ítems de inventario actualizados
  - Arrays de entrada actualizados
  - Flags de estado del personaje
  - Información de origen del personaje (loginId + charId eco)

---

## Comprar Ítem (Opcode 0x74)

**Manejador:** `FUN_00421e10`
**Archivo:** `funcs/FUN_00421e10.c` (221 líneas)
**Push BD:** Sí (sub-opcode 0x28)

#### Validación de Estado
1. `field+0x1460 == 0` O `field+0x14a4 == 0` → error 0xE2
2. `field+0x1440 != 0x02` (no LOBBY) → error 0xE3

#### Payload del Cliente (longitud variable)
```
[itemId:2][shopSlot:1][count:1][params:count*1]
```
- `itemId`: el identificador del ítem a comprar
- `shopSlot`: en qué slot de la tienda está el ítem
- `count`: número de bytes de parámetros adicionales (debe ser < 4, si no error 0xE4)
- `params`: si count > 0, bytes adicionales (ej., cantidad para ítems apilables)

#### Flujo de Procesamiento
1. Obtiene el estado actual de equipo/inventario vía `FUN_0040ca50`
2. Llama a `FUN_0040c310(field, itemId, shopSlot, count, params, ...)` — lógica de compra:
   - Valida que el jugador tenga suficiente oro/cash
   - Crea registro del ítem en el inventario del jugador
   - Cobra el costo
   - Devuelve inventarios actualizados
   - Devuelve datos de precio del ítem
3. Si la compra falla (retorno != 0): envía `[0x74][errorCode:1]` (3 bytes)
4. En éxito, construye push BD:

#### Formato de Push BD (sub-opcode 0x28)
```
[sessionCounter:2][0x28:2][loginId:4][charId:4][itemId:2][shopSlot:1][count:1][params...]
[itemData:4 bytes][precioOro:4][precioCash:4][totalOro:4]
[equipData...][inventoryData...][flags...]
```
- Serialización de longitud variable con el mismo patrón que el manejador de equipar:
  - Ítems equipados (4 bytes cada uno)
  - Cantidades de ítems (4 bytes cada uno)
  - Ítems de inventario (4 bytes cada uno)
  - Cantidades de entrada (4 bytes cada uno)
  - Datos de slot de poción
  - Información de inicio de sesión del personaje + contador de sesión

---

## Lotería / Caja de Ítems (Opcode 0x75)

**Manejador:** `FUN_004222a0`
**Archivo:** `funcs/FUN_004222a0.c`
**Push BD:** Sí

#### Payload del Cliente
```
[moneyType:1][...]
```
- `moneyType`: 0 = oro, 1 = cash

#### Flujo de Procesamiento
1. Valida el dinero:
   - Si es oro: debe ser < 1000
   - Si es cash: debe ser < 100
2. Verifica colisiones de números con entradas de lotería existentes
3. O bien:
   - Envía datos de lotería directamente (si es simple)
   - Envía a BD vía `FUN_0041b940` (para almacenamiento persistente)
4. Actualiza el saldo de dinero del jugador

**Nota:** Este es el sistema gacha/lotería donde los jugadores compran cajas de ítems aleatorios.

---

## Códigos de Error

### Errores Comunes de Lobby (opcodes 0x16, 0x31, 0x36, 0x2E, 0x3B, 0x38, 0x3E, 0x2F, 0x73, 0x74)

| ID Error | Hex | Descripción | Condición de Disparo |
|----------|-----|-------------|----------------------|
| InvalidLogin | varía | No conectado | `field+0x1460 == 0` o `field+0x14a4 == 0` |
| InvalidState | varía | Estado incorrecto para la operación | `field+0x1440` no coincide con lo esperado |

### IDs de Error por Opcode

| Opcode | Hex | Err ID | Hex | Descripción |
|--------|-----|--------|-----|-------------|
| 0x16 | Whisper | 0x21 | No conectado | |
| | | 0x22 | Nombre muy largo (>= 13) | |
| | | 0x23 | Mensaje muy largo (>= 129) | |
| 0x31 | Movimiento | 0x3C | No conectado | |
| | | 0x3D | No en estado LOBBY | |
| | | 0x3E | Coordenadas inválidas | |
| 0x36 | Lista Salas | 0x46 | No conectado | |
| | | 0x47 | No en estado LOBBY | |
| | | 0x48 | pageCount > 10 | |
| | | 0x49 | pageIndex >= maxSalas | |
| 0x2E | Crear Simple | 0x36 | No conectado | |
| | | 0x37 | Tipo de sala o estado inválido | |
| 0x3B | Crear Completo | 0x52 | No conectado | |
| | | 0x53 | No en estado LOBBY | |
| | | 0x54 | Nombre sala >= 40 chars | |
| | | 0x55 | Contraseña >= 9 chars | |
| | | 0x56 | Nombre mapa >= 201 chars | |
| | | 0x57 | Modo >= 100 (subMode=0) | |
| | | 0x58 | Tipo de sala inválido (subMode=0) | |
| | | 0x59 | Rango de nivel inválido | |
| | | 0x5A | Nivel fuera del rango del jugador | |
| | | 0x5B | Modo >= 5 (subMode!=0) | |
| | | 0xCA | Tipo de mapa >= 22 | |
| | | 0xCB | MapId fuera de rango (0x122-0x4BA) | |
| | | 0xCC | MinLevel fuera de rango | |
| 0x38 | Unir c/ PW | 0x4A | No conectado | |
| | | 0x4C | roomIndex >= maxSalas | |
| | | 0x4D | Contraseña >= 9 chars | |
| 0x3E | Salir | 0x62 | No conectado | |
| | | 0x63 | No en estado SALA | |
| 0x2F | Tienda | 0x39 | No conectado | |
| | | 0x3A | No en estado LOBBY | |
| | | 0x3B | Categoría >= 120 | |
| 0x73 | Equipar | 0xDE | No conectado | |
| | | 0xDF | No en estado LOBBY | |
| | | 0xE0 | equipSlot >= 120 | |
| | | 0xE1 | itemSlot >= 120 | |
| 0x74 | Comprar | 0xE2 | No conectado | |
| | | 0xE3 | No en estado LOBBY | |
| | | 0xE4 | count >= 4 | |

---

## Resumen de Formatos de Paquete

| Opcode | Hex | Manejador | Payload Cliente (bytes) | Payload Servidor | Push BD |
|--------|-----|-----------|-------------------------|------------------|---------|
| 22 | 0x16 | FUN_00420200 | `[nombre\0][msg\0]` (variable) | 3-132+ bytes | No |
| 46 | 0x2E | FUN_00421210 | `[roomType:2][raza:1][mode:1][slot:1]` | 3 bytes error / variable | Sí (0x14) |
| 47 | 0x2F | FUN_004215a0 | `[category:1]` | 3 bytes error / variable | Sí (0x15) |
| 41 | 0x29 | FUN_00420c20 | `[roomIdx:2][pw?]` | Variable | No |
| 42 | 0x2A | FUN_00420cb0 | `[targetId:2]` | 8 bytes | No |
| 49 | 0x31 | FUN_00421870 | `[x:1][y:1][z:1][w:1]` | 21 bytes (broadcast) | No |
| 54 | 0x36 | FUN_00422c90 | `[page:1][idx:2][filtros:7]` | Lista salas variable | No |
| 56 | 0x38 | FUN_00423100 | `[roomIdx:2][pw\0]` | 3 bytes / variable | Sí (0x26) |
| 57 | 0x39 | FUN_00423300 | Desconocido | Variable | No |
| 59 | 0x3B | FUN_00423580 | `[nombre\0][pw\0][mapa\0][campos:8]` | 5 bytes | Sí (0x25) |
| 62 | 0x3E | FUN_00423b70 | ninguno | Variable (broadcast salida) | No |
| 115 | 0x73 | FUN_00421a50 | `[itemSlot:1][equipSlot:1]` | 3 bytes / variable | Sí (0x27) |
| 116 | 0x74 | FUN_00421e10 | `[itemId:2][shopSlot:1][cnt:1][p:cnt]` | 3 bytes / variable | Sí (0x28) |
| 117 | 0x75 | FUN_004222a0 | `[moneyType:1]` | Variable | Sí |

---

## Offsets de la Estructura de Sala

Las estructuras de sala se asignan en `this+0xe4` con tamaño `0x3C0` (960) bytes cada una.

| Offset | Tamaño | Campo | Descripción |
|--------|--------|-------|-------------|
| +0x00 | 4 | id | ID / índice de la sala |
| +0x04 | 4 | flags | Flags de la sala |
| +0x08 | 1 | active | Flag activo (0 = vacío, 0x13 = maestro, si no normal) |
| +0x09 | 3 | _pad | Relleno |
| +0x0C | variable | players | Array de slots de jugadores |
| +0x114 | 1 | playerCount | Cantidad actual de jugadores (byte alto) |
| +0x115 | 1 | playerCount2 | Cantidad actual de jugadores (byte bajo) |
| +0x116 | 1 | maxPlayers | Cantidad máxima de jugadores (byte alto) |
| +0x117 | 1 | maxPlayers2 | Cantidad máxima de jugadores (byte bajo) |
| +0x119 | 1 | gameType | Tipo/modo de juego (0=VS/PVP, 1-4=otro) |
| +0x11A | 1 | state | Estado de la sala (0x02 = esperando) |
| ... | | | El nombre de sala, contraseña, configuración de mapa siguen |

Estructuras de canal: `this+0xdc`, tamaño 0x358 (856) bytes cada uno, `this+0xd8` cantidad.
Datos de sala en `this+0xe4`, máximo de salas en `DAT_00455824`, tamaño de sala 0x3C0 (960) bytes.

---

## Funciones Auxiliares Clave

| Función | Archivo | Propósito |
|---------|---------|-----------|
| FUN_0040b6c0 | funcs/FUN_0040b6c0.c | Procesador de filtros de lista de salas |
| FUN_00405920 | — | Verificación de compatibilidad clase/raza |
| FUN_0041b830 | funcs/FUN_0041b830.c | Verificación de disponibilidad de raza |
| FUN_00405790 | — | Serializar datos de sala al buffer |
| FUN_0040cb10 | — | Crear estructuras de datos de sala + tablas de ítems |
| FUN_0040ca50 | — | Obtener estado actual de equipo/inventario |
| FUN_0040c140 | `funcs/FUN_0040c140.c` | Realizar operación de equipar/desequipar |
| FUN_0040c310 | — | Lógica de compra de ítem (validar + cobrar + añadir a inv) |
| FUN_0040cf10 | — | Procesar coordenadas de movimiento |
| FUN_0040af90 | — | Buscador de canal |
| FUN_00405240 | — | Actualizar slot de jugador en canal |
| FUN_00405440 | — | Inicializar estructura de sala |
| FUN_0040b7b0 | funcs/FUN_0040b7b0.c | Establecer estado de sala + flag maestro (field -> SALA) |
| FUN_0040b7d0 | — | Extraer sala/canal del field |
| FUN_004075a0 | — | Salir de sala (estado -> LOBBY) |
| FUN_00406f40 | — | Unirse a sala con validación de contraseña |
| FUN_0040af20 | — | Comparación de nombres de jugador para whispers |
| FUN_0040cd70 | — | Consulta de ítems de tienda por categoría |
| FUN_004038e0 | — | Enviar/transmitir paquete al jugador |
| FUN_0041eb20 | funcs/FUN_0041eb20.c | Manejador de paquete de error |

---

## Patrón de Construcción de Respuesta

Todos los manejadores de lobby siguen este patrón:

1. **Validar estado** (login + charId + flag de estado)
   - Fracaso → `FUN_0041eb20(this, fieldId, errorId, 0x01, 1)` → desconexión/error
2. **Analizar payload** (leer bytes del buffer del cliente)
   - Fracaso → `FUN_0041eb20` con error específico
3. **Procesar** (operaciones en memoria sobre datos de field/sala/canal)
   - Fracaso → enviar paquete de error de 3 bytes `[opcode:2][errorCode:1]` vía `FUN_004038e0` O enviar error a BD
4. **Construir respuesta** (buffer de paquete de longitud variable)
5. **Enviar** (vía `FUN_004038e0`) para respuestas inmediatas
   **O Enviar a BD** (vía `FUN_0041b940`) para respuestas mediadas por BD

### Patrón de difusión (0x31, eventos de sala)
Para operaciones que afectan a otros jugadores, se llama a `FUN_004038e0` con el puntero de la lista de difusión (`this+0x118`) y el fieldId del remitente. La función maneja el envío a todos los demás jugadores conectados en el mismo lobby/sala.

---

> **Siguiente fase:** Después de unirse a una sala y presionar "Iniciar" (opcode 0x46), comienza la fase IN-GAME. Ver `03_packet_opcodes.md` sección "FASE 6: In-Game" para los opcodes 0x50-0x77. Ver `RAKION_RE_MASTER.md` sección 3.4 para el flujo completo del servidor.  
> **Documentación detallada de compra/venta/equip/enchant:** Ver `shop_inventory_refinery.md` para el análisis completo de opcodes 0x73-0x75 con handlers decompilados.
