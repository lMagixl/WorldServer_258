# Rakion World Server — Emulador C# + Ingeniería Inversa

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

> **Reversing y emulador del servidor original RakionWorldServ.exe (Softnyx, 2007)**
> 
> Proyecto open-source para construir un servidor emulador funcional de Rakion en C# .NET 8,
> basado en decompilación completa vía Ghidra + análisis de protocolo.

---

## 🎥 Video Demostrativo

https://github.com/0xcmetatron/rakion-world-server/raw/main/test.mp4

*(Si el video no carga directamente arriba, puedes [descargarlo aquí](https://github.com/0xcmetatron/rakion-world-server/raw/main/test.mp4))*

---

## 📋 Tabla de Contenidos

- [Estado del Proyecto](#-estado-del-proyecto)
- [Requisitos](#-requisitos)
- [Instalación Rápida](#-instalación-rápida)
- [Configuración Paso a Paso](#-configuración-paso-a-paso)
- [BrokenServer (Broker)](#-brokenserver-broker)
- [Estructura del Proyecto](#-estructura-del-proyecto)
- [Lo Que Funciona](#-lo-que-funciona)
- [Problemas Conocidos](#-problemas-conocidos)
- [Lo Que Falta Trabajar](#-lo-que-falta-trabajar)
- [Arquitectura del Servidor](#-arquitectura-del-servidor)
- [Herramientas Necesarias para Contribuir](#-herramientas-necesarias-para-contribuir)
- [Cómo Contribuir](#-cómo-contribuir)
- [Documentación Técnica](#-documentación-técnica)
- [Agradecimientos](#-agradecimientos)

---

## 🟢 Estado del Proyecto

| Sistema | Progreso | Estado |
|---------|----------|--------|
| ✅ **Login/Autenticación** | 100% documentado, 90% implementado | Funcional |
| ✅ **Character Management** | 100% documentado, 85% implementado | Funcional (crear/listar/borrar/seleccionar) |
| ✅ **Shop/Inventory/Refinery** | 100% documentado, 60% implementado | Parcial (Buy stub, Sell no, Equip no) |
| ✅ **Lobby/Room** | 100% documentado, 40% implementado | Parcial (entrar lobby, listar campos) |
| 🟡 **Crypto/Protocolo** | 100% documentado | Funcional (AES-ECB 0x7FC4) |
| 🔴 **Battle/P2P/UDP** | 0% documentado, 0% implementado | **No empezado** |
| 🔴 **NPC/AI** | 5% documentado, 0% implementado | **No empezado** |
| 🔴 **Clan/Guild** | 10% documentado, 0% implementado | **No empezado** |
| 🔴 **IOCP/Networking real** | 60% documentado, 0% implementado | **No empezado** (usa async TCP) |
| 🔴 **Emulador C# completo** | 13/86 opcodes implementados | **15%** |

---

## 📦 Requisitos

### Para Ejecutar el Servidor
- **Windows 10/11** o Linux con Wine
- **.NET 8.0 Runtime** o SDK → [Descargar](https://dotnet.microsoft.com/download/dotnet/8.0)
- **MySQL 5.7+** o **MariaDB 10+** → [XAMPP](https://www.apachefriends.org/) recomendado
- **BrokenServer.exe** → Broker de conexión (ver sección abajo)

### Para Desarrollo / Reversing
- **Ghidra 12.1+** → [Descargar](https://ghidra-sre.org/)
- **Ghidra MCP** → https://github.com/bethington/ghidra-mcp
- **OpenCode** / **Claude Code** / **Antigravity CLI** — asistentes AI con Ghidra MCP
- **Python 3.8+** — para scripts de captura de paquetes

---

## 🚀 Instalación Rápida

### 1. Base de Datos
```sql
-- 1. Crear base de datos
CREATE DATABASE rakion CHARACTER SET utf8 COLLATE utf8_general_ci;

-- 2. Importar schema
mysql -u root -p rakion < "C:\RakionWorldServ\rakion.sql"

-- 3. Verificar que las tablas se crearon
mysql -u root -p rakion -e "SHOW TABLES;"
-- Deberías ver ~20 tablas: user, usergameinfo, characterinfo, useriteminfo, etc.
```

### 2. Configurar worldserver.ini
Edita `worldserver.ini` con tus datos:
```ini
[Server]
ServerId=1
MaxUser=2000
MaxField=500
Port=40708

[Broker]
IP=192.168.1.x          # ← TU IP local
Port=40706

[DB]
IP=localhost
Port=3306
User=root
Pass=123456             # ← TU contraseña MySQL
Name=rakion

[UDP]
Port1=40708
Port2=40709
```

### 3. Compilar y Ejecutar
```bash
cd analysis\src
dotnet build -c Release
dotnet run --project RakionWorldServer.csproj
```

### 4. Conectar el Cliente
1. Inicia **BrokenServer.exe** (broker en puerto 40706)
2. Inicia el servidor emulador
3. Abre el cliente Rakion y modifica el launcher para apuntar a `127.0.0.1:80`
4. El servidor web auth debe estar corriendo (XAMPP con los PHP de `Xampp\Web\`)

---

## 🔧 Configuración Paso a Paso

### worldserver.ini — Explicación completa

```ini
[FlexDbConn]
MaxDbConnection=50       # Conexiones DB simultáneas
DbConnAdjustFreq=50      # Frecuencia de ajuste de pool

[Server]
ServerId=1               # ID de este servidor en la red
MaxUser=2000             # Usuarios máximos concurrentes
MaxField=500             # Campos/salas máximos
Port=40708               # Puerto TCP principal

[Authentication]
Type=0                   # 0=web auth, 1=directo
Host=192.168.1.x         # IP del servidor web auth
Port=80                  # Puerto HTTP
AuthPage=/auth.asp       # Endpoint de autenticación
Secured=1                # 0=sin hash, 1=con hash MD5

[Client]
MD5_1=D                  # Token MD5 para handshake
MD5_2=709F1058DC30EB...  # Segundo token

[ServerList]
Count=1                  # Número de servidores en lista
IP0=192.168.1.x          # IP del servidor de juego
Port0=40706              # Puerto del broker

[Broker]
IP=192.168.1.x           # IP del broker
Port=40706               # Puerto del broker (BrokenServer.exe)

[DB]
IP=localhost             # Host MySQL
Port=3306                # Puerto MySQL
User=root                # Usuario MySQL
Pass=123456              # Contraseña MySQL
Name=rakion              # Base de datos

[UDP]
Port1=40708              # Puerto UDP 1 (batalla)
Port2=40709              # Puerto UDP 2 (batalla)

[Queue]
DbRecvQueue=100          # Cola de recepción DB
DbSendQueue=100          # Cola de envío DB
TcpRecvQueue=50          # Cola de recepción TCP
TcpSendPoolSize=50       # Pool de envío TCP
UdpRecvQueue=50          # Cola de recepción UDP
```

---

## 🌐 BrokenServer (Broker)

**BrokenServer.exe** es el broker que actúa como intermediario entre el cliente Rakion y el servidor world. Se ejecuta en el puerto **40706**.

### Dónde conseguirlo
- El código fuente está en `BrokenServer_SRC.rar` en la carpeta de descargas.
- Extrae con WinRAR y compila con Visual Studio / MSBuild.

### Cómo funciona
```
Cliente Rakion → BrokenServer:40706 → WorldServer:40708
```
- El cliente se conecta al broker (puerto 40706 configurado en `ServerList` del .ini)
- El broker reenvía/responde según la lógica de broken
- El world server escucha en el puerto 40708

---

## 📁 Estructura del Proyecto

```
rakion-world-server/
├── Binario/                     # Archivos del servidor original
│   ├── RakionWorldServ.exe      # Binario ORIGINAL (PE32, 2007)
│   ├── worldserver.ini          # Configuración del servidor
│   ├── WorldServerDll.dll       # PRTCLIB crypto DLL
│   └── ggauth*.dll              # Librerías de GameGuard
│
├── broken_bin/                  # Broker / Emulador intermediario
│   ├── BrokenServer.exe         # Servidor broker (puerto 40706)
│   └── Settings/                # Configuración del broker
│
├── analysis/                    # Reversing y Emulador C#
│   ├── funcs/                   # 151 archivos .c decompilados de Ghidra
│   │   ├── FUN_004107d0.c       # DBCommandLogin (42 KB)
│   │   ├── FUN_0042cee0.c       # CWorld::Idle (68 KB, main loop)
│   │   ├── FUN_0040c310.c       # Buy + Enchant (700 líneas)
│   │   ├── FUN_0042ab40.c       # Game Dispatcher (86 opcodes)
│   │   ├── FUN_0041ae50.c       # DBWorker Dispatcher (40 opcodes)
│   │   ├── FUN_0042bd70.c       # Main IOCP loop
│   │   └── ... (151 archivos)
│   │
│   ├── src/                     # Código fuente del emulador C#
│   │   ├── Program.cs           # ~1600 líneas — EMULADOR PRINCIPAL
│   │   ├── RakionWorldServer.csproj  # .NET 8 project
│   │   └── bin/Release/net8.0/  # Binarios compilados
│   │
│   ├── RAKION_RE_MASTER.md      # Documento MAESTRO (58 KB)
│   ├── 01_functions_list.md     # Lista de 1046 funciones
│   ├── 03_packet_opcodes.md     # 86 opcodes de red documentados
│   ├── login_flow.md            # Flujo de login completo
│   ├── lobby_phase.md           # Fase Lobby/Sala (14 opcodes)
│   ├── character_management.md  # Character Management 100%
│   ├── shop_inventory_refinery.md # Shop/Inventory/Refinery 100%
│   ├── program_info.md          # Info del binario PE
│   └── SESSION_LOG.md           # Historial de sesiones
│
├── README.md                    # Este documento
└── test.mp4                     # Video demostrativo
```

> **Nota:** Solo el binario original `RakionWorldServ.exe` y `worldserver.ini` son necesarios para reversing. Los demás archivos (DLLs, SQL, scripts) se documentan aquí pero se pueden regenerar.
>
> Todo el proyecto está empaquetado en `RakionWorldServ.zip` (~2.4 MB comprimido) listo para subir a GitHub.
>
> Sistemas como Battle/Stage, NPC, Clan, etc. se irán agregando a la documentación a medida que se analicen vía Ghidra MCP. Cualquier función del binario se puede decompilar bajo demanda usando `GET /decompile_function?address=0xADDR`.
│   ├── funcs/                   # 151 archivos .c decompilados de Ghidra
│   │   ├── FUN_004107d0.c       # DBCommandLogin (42 KB)
│   │   ├── FUN_0042cee0.c       # CWorld::Idle (68 KB, main loop)
│   │   ├── FUN_0040c310.c       # Buy + Enchant (700 líneas)
│   │   ├── FUN_0042ab40.c       # Game Dispatcher (86 opcodes)
│   │   ├── FUN_0041ae50.c       # DBWorker Dispatcher (40 opcodes)
│   │   ├── FUN_0042bd70.c       # Main IOCP loop
│   │   └── ... (151 archivos)
│   │
│   ├── src/                     # Código fuente del emulador C#
│   │   ├── Program.cs           # ~1600 líneas — EMULADOR PRINCIPAL
│   │   ├── RakionWorldServer.csproj  # .NET 8 project
│   │   └── bin/Release/net8.0/  # Binarios compilados
│   │
│   ├── RAKION_RE_MASTER.md      # Documento MAESTRO (58 KB)
│   ├── 01_functions_list.md     # Lista de 1046 funciones
│   ├── 03_packet_opcodes.md     # 86 opcodes de red documentados
│   ├── login_flow.md            # Flujo de login completo
│   ├── lobby_phase.md           # Fase Lobby/Sala (14 opcodes)
│   ├── character_management.md  # Character Management 100%
│   ├── shop_inventory_refinery.md # Shop/Inventory/Refinery 100%
│   ├── program_info.md          # Info del binario PE
│   └── SESSION_LOG.md           # Historial de sesiones
│
├── Xampp/                       # Servidor web auth
│   └── Web/                     # PHP endpoints (login, fetch, file check)
│       ├── launcherlogin.php    # Autenticación de usuarios
│       ├── config.php           # Config DB
│       ├── fetch.php            # Sistema de parches
│       └── file.php             # Verificación MD5 de archivos
│
└── old/                         # Backups de binarios anteriores
```

---

## ✅ Lo Que Funciona

El emulador C# (`analysis/src/Program.cs`) actualmente maneja **13 opcodes**:

| Opcode | Handler | Estado |
|--------|---------|--------|
| `0x0001` | InitialCheck | ✅ Funcional |
| `0x0002` | ServerInfoAndMd5 | ✅ Funcional |
| `0x000B` | ClientMd5Echo | ✅ Funcional |
| `0x000C` | Login | ✅ Funcional (crea usuario auto si no existe) |
| `0x000E` | LobbyServerInfo | ✅ Funcional |
| `0x000F` | KeepAlive | ✅ Funcional |
| `0x0012` | CharacterCreate | ✅ Funcional |
| `0x0013` | CharacterDelete | ✅ Funcional |
| `0x0014` | CharacterSelect | ⚠️ Parcial (no carga items del personaje) |
| `0x0015` | CharacterNameEcho | ✅ Funcional |
| `0x001A` | TutorialComplete | ✅ Funcional |
| `0x002C` | InventoryEnter | ⚠️ Parcial (solo envía header, no items reales) |
| `0x0036` | FieldList | ⚠️ Stub (envía respuesta fija) |

### Protocolo de Red
- ✅ Encriptación AES-ECB (clave estática `0xE13A7EF5...`)
- ✅ Formato de frame: `[len:2][bloques encriptados]`
- ✅ Encoding/decoding de bloques 16 → 12 bytes (0x7FC4)
- ✅ Handshake MD5 con tokens

### Base de Datos
- ✅ Conexión MySQL vía MySqlConnector
- ✅ Auto-limpieza de slots duplicados
- ✅ Auto-creación de usuarios al login
- ✅ Consultas de personajes

---

## ❌ Problemas Conocidos

### 1. Items no aparecen al seleccionar personaje ⚠️
**Síntoma:** Al seleccionar un personaje y entrar al lobby, el personaje aparece sin items/equipo.
**Causa:** `HandleCharacterSelectAsync` envía `ChannelEnter` (0x1F) y `ChannelCharacterState` (0x1E) pero **NUNCA consulta `UserItemInfo`** para cargar los items del personaje. El servidor real envía paquetes de equipamiento (slot items, enchant levels, durabilidad) después del select.
**Solución:** Implementar consulta a `UserItemInfo WHERE userid=%u` después del select, y enviar paquetes 0x17/0x18/0x1C con datos de items serializados.

### 2. Shop no funcional 🛒
**Síntoma:** Los opcodes 0x2F (shop), 0x73 (equip), 0x74 (buy), 0x75 (sell) no están implementados.
**Causa:** No hay handlers para estos opcodes en el dispatcher.
**Solución:** Implementar usando la documentación en `shop_inventory_refinery.md` que tiene TODO el flujo decompilado.

### 3. InventoryEnter no carga items reales 📦
**Síntoma:** El paquete 0x2C solo envía un header de 9 bytes con timestamp y contador, sin datos reales de items.
**Causa:** `HandleInventoryEnterAsync` es un stub.
**Solución:** Consultar `UserItemInfo` y serializar correctamente los 120 slots de inventario.

### 4. UDP Echo Server sin lógica real 🌐
**Síntoma:** Los puertos UDP son ecos simples que devuelven lo que reciben.
**Causa:** La lógica P2P/UDP de batalla no está implementada.
**Solución:** Requiere análisis completo del sistema de batalla (opcodes 0x50-0x77).

### 5. FieldList es un stub 🏟️
**Síntoma:** Devuelve respuesta fija con 1 campo.
**Causa:** No hay lógica real de campos/salas.
**Solución:** Implementar sistema de CField con array de salas y estado.

### 6. DB cleanup puede causar problemas 🧹
**Síntoma:** La auto-limpieza de slots elimina personajes que comparten slot.
**Causa:** El trigger MySQL en `characterinfo` reasigna slots pero el cleanup del emulador no lo respeta.
**Solución:** Usar slot virtual (como dice character_management.md) en vez de depender del trigger.

### 7. No hay manejo de GameGuard 🛡️
**Síntoma:** El servidor no responde correctamente a los checks de GameGuard.
**Causa:** No hay implementación del opcode 0x10 (GameGuard check).
**Solución:** Implementar stub que responda siempre OK o analizar ggauth60.dll.

### 8. Lobby sin rooms/salas 🚪
**Síntoma:** Después de entrar al lobby, no se pueden crear o unirse a salas.
**Causa:** Opcodes de sala (0x2D-0x4F) no implementados.
**Solución:** 25 handlers con helpers decompilados pero no implementados en C#.

---

## 🔴 Lo Que Falta Trabajar

### Prioridad CRÍTICA (Sin esto el juego no avanza)

| # | Sistema | Opcodes | Complejidad |
|---|---------|---------|-------------|
| 1 | **Cargar items al seleccionar personaje** | 0x17, 0x18, 0x1C | Media |
| 2 | **Shop (comprar items)** | 0x2F, 0x74 → FUN_00421e10, FUN_0040c310 | Alta |
| 3 | **Equipar/Desequipar items** | 0x73 → FUN_00421a50, FUN_0040c140 | Media |
| 4 | **Vender items** | 0x75 → FUN_00421f60 | Media |
| 5 | **Inventario real (120 slots)** | 0x2C (completar) | Media |

### Prioridad ALTA (Sistema de batalla)

| # | Sistema | Opcodes | Estado |
|---|---------|---------|--------|
| 6 | **Sala/Crear sala + Stage** | 0x3B → FUN_00425010 | 25 helpers decompilados, 0 en C# |
| 7 | **Battle/Stage (P2P/UDP)** | 0x50-0x77 | Pendiente de decompilar con Ghidra MCP |
| 8 | **Unirse a sala** | 0x38 → FUN_00406f40 | Helper decompilado |
| 9 | **Lista de salas** | 0x36 → FUN_004244f0 | Stub en C# |
| 10 | **Sala lista/inicio** | 0x3D, 0x43 | Helpers decompilados |
| 11 | **Daño, skills, movimiento** | (UDP) | Pendiente de decompilar con Ghidra MCP |
| 12 | **Resultado de partida** | 0x5D, 0x5E → FUN_0040a420 | Helpers decompilados |

### Prioridad MEDIA

| # | Sistema | Estado |
|---|---------|--------|
| 13 | **NPC/AI** | Solo tabla NPCInfo conocida |
| 14 | **Clan/Guild** | FUN_0040f610 decompilada |
| 15 | **Lotería** | FUN_0040f0a0 + FUN_0040ec50 decompiladas |
| 16 | **EventHandler/Objetos de sala** | FUN_0040cb10 decompilada (crear sala + items) |
| 17 | **PowerUser** | FUN_00415cb0 decompilada |
| 18 | **Compra ranuras inventario/pociones** | FUN_00415590, FUN_00417800 decompiladas |
| 19 | **Chat** | 0x47, 0x56 — stubs disponibles |
| 20 | **Stage Rank Clear** | FUN_004184a0 decompilada |

### Prioridad BAJA (Sistema/Infraestructura)

| # | Sistema | Estado |
|---|---------|--------|
| 21 | **IOCP callback real** | No encontrado (GetQueuedCompletionStatus) |
| 22 | **CWorld::Idle (FUN_0042cee0, 68KB)** | Decompilado, no confirmado |
| 23 | **DB opcodes sin mapear (~30)** | No identificados |
| 24 | **DB response sub-opcodes (~26)** | No documentados |
| 25 | **WorldServerDll.dll** | No analizado (solo interfaz conocida) |
| 26 | **GameGuard ggauth60.dll** | No analizado |
| 27 | **13 offsets desconocidos en CField** | Sin propósito identificado |

### Totales
| Categoría | Cantidad |
|-----------|----------|
| Game opcodes sin handler en C# | 73/86 |
| Helpers decompilados no implementados | ~25 |
| DB opcodes sin mapear | ~30 |
| DB response sub-opcodes sin documentar | ~26 |
| Funciones con nombre real conocido sin .c | 8 |
| Funciones con nombre real sin dirección | 8 |

---

## 🏗️ Arquitectura del Servidor

### Modelo de Hilos (Original C++)
```
TCP Socket (AcceptEx)
    ↓
TcpRecvQueue (Receive Queue)
    ↓
CWorld::Idle → FUN_0042cee0 (Main Loop, 68 KB, ~10000 líneas)
    ├── Procesa TcpRecvQueue
    ├── Game Dispatcher → FUN_0042ab40 (86 opcodes)
    │   └── Handler por opcode (ej: 0x0C=Login, 0x74=Buy)
    ├── DBWorker queue → FUN_0041ae50 (40 opcodes DB)
    │   └── DB Response → FUN_004295c0 (~32 sub-opcodes)
    └── UDP sockets (P2P battle relay)
```

### Modelo C# Actual
```
TCP Listener (async)
    ↓
ProcessFrameAsync (switch de 13 opcodes)
    ↓
Handler por opcode → consultas DB directas síncronas
```

### Flujo de Login (Completo)
```
Cliente → 0x01 (InitialCheck) → Server responde 0x00
Cliente → 0x02 (ServerInfo) → Server envía MD5 tokens + info
Cliente → 0x0B (ClientMd5Echo) → Server verifica y responde
Cliente → 0x0C (Login) → Server consulta DB, responde 0x0C+0x0D
Cliente → 0x0E (LobbyServerInfo) → Server envía 0x0E+0x10
Cliente → 0x12 (CreateChar) → Server INSERT DB, responde
Cliente → 0x13 (DeleteChar) → Server UPDATE DB, responde
Cliente → 0x14 (SelectChar) → Server carga personaje + items
Cliente → 0x2C (InventoryEnter) → Server envía items del inventario
Cliente → 0x36 (FieldList) → Server lista salas disponibles
Cliente → 0x3B (CreateField) → Server crea sala
Cliente → 0x38 (JoinField) → Server une a sala
... → Battle → UDP → Game Result → Lobby
```

---

## 🛠️ Herramientas Necesarias para Contribuir

### Para Decompilar (Entender el servidor original)
```
Ghidra 12.1 + Ghidra MCP Server (bethington/ghidra-mcp)
    ↓
Bridge MCP: python bridge_mcp_ghidra.py
    ↓
OpenCode / Claude Code / Antigravity CLI (cliente MCP)
    ↓
Herramientas: decompile_function, list_functions, analyze_function_full
    ↓
Recibe: código C decompilado
    ↓
Documenta en los .md correspondientes
    ↓
Implementa en Program.cs
```

### Configuración de Ghidra MCP
1. Clona: `git clone https://github.com/bethington/ghidra-mcp.git`
2. Instala dependencias: `python -m tools.setup ensure-prereqs --ghidra-path "C:\ghidra_12.1_PUBLIC"`
3. Compila: `python -m tools.setup build`
4. Despliega: `python -m tools.setup deploy --ghidra-path "C:\ghidra_12.1_PUBLIC"`
5. Abre Ghidra, activa el plugin: **File > Configure > GhidraMCP**
6. Inicia: **Tools > GhidraMCP > Start MCP Server**
7. Inicia el bridge: `python bridge_mcp_ghidra.py`
8. Verifica: `curl http://127.0.0.1:8089/check_connection`

### Herramientas MCP de Ghidra Disponibles
El servidor expone **245 herramientas MCP** para análisis. Las más usadas:

| Herramienta | Descripción |
|-------------|-------------|
| `list_functions` | Lista todas las funciones (1046) |
| `decompile_function` | Decompila función a C |
| `get_function_callers` | Quién llama a una función |
| `get_function_xrefs` | Cross-references de una función |
| `analyze_function_full` | Análisis completo de función |
| `analyze_function_completeness` | Score de documentación (0-100%) |
| `search_functions_enhanced` | Búsqueda avanzada con filtros |
| `get_bulk_function_hashes` | Hashing de funciones en lote |
| `get_function_hash` | SHA-256 hash para matching cross-version |
| `read_memory` | Leer bytes raw de memoria |
| `search_byte_patterns` | Buscar patrones de bytes |
| `rename_function_by_address` | Renombrar función por dirección |
| `set_decompiler_comment` | Agregar comentarios al código |
| `batch_decompile` | Decompilar múltiples funciones |
| `get_full_call_graph` | Grafo completo de llamadas |
| `create_struct` | Crear estructuras personalizadas |

**Nota:** Ghidra MCP usa el protocolo MCP estándar (Model Context Protocol), NO endpoints HTTP simples. El bridge corre en `http://127.0.0.1:8089/` y entiende comandos como `decompile_function`, `list_functions`, etc.

**Todo el binario está disponible para decompilar bajo demanda.** Actualmente hay 151 funciones ya decompiladas en `analysis/funcs/`, incluyendo el main loop (68 KB), el dispatcher de 86 opcodes, y todos los handlers de shop/inventory/refinery. Cualquier función que falte se puede decompilar al instante con Ghidra MCP — solo se necesita la dirección.

Sistemas grandes como **Battle/Stage (opcodes 0x50-0x77, P2P/UDP)**, **NPC/AI**, **Clan/Guild** y **Stage System** están pendientes de análisis. A medida que se vayan documentando, se agregarán al repositorio nuevos archivos .c y secciones en los .md. Cualquier contribuyente puede decompilar funciones del battle system con Ghidra MCP y compartir los resultados.

### Stack Tecnológico Recomendado
- **Lenguaje:** C# .NET 8 (console application)
- **DB:** MySQL + MySqlConnector (ya agregado vía NuGet)
- **Crypto:** AES-ECB implementado en `RakionPacketCodec`
- **No usar:** Entity Framework, SignalR, ASP.NET — mantener minimalista
- **No usar:** WPF, WinForms — solo consola

---

## 🤝 Cómo Contribuir

Este proyecto es **open-source** y cualquier persona puede contribuir. La meta es trabajar como comunidad para reconstruir el servidor completo.

### Formas de Ayudar
1. **Implementar handlers** — Traducir código C decompilado a C#
2. **Decompilar funciones** — Usar Ghidra MCP para generar más .c
3. **Documentar** — Mejorar los .md con análisis más detallados
4. **Testear** — Probar el emulador con el cliente Rakion real
5. **Reportar bugs** — Abrir issues con logs y capturas de paquete

### Flujo de Trabajo
```bash
# 1. Fork el repositorio
# 2. Clona tu fork
git clone https://github.com/0xcmetatron/rakion-world-server.git

# 3. Crea una rama
git checkout -b feature/mi-mejora

# 4. Haz cambios, compila y prueba
cd analysis/src
dotnet build -c Release

# 5. Commit y push
git commit -m "Añadido handler para opcode 0x..."
git push origin feature/mi-mejora

# 6. Abre Pull Request
```

### Guías
- **No uses Entity Framework** — SQL directo vía MySqlConnector
- **Sigue el patrón** de los handlers existentes en Program.cs
- **Documenta** cualquier descubrimiento en los .md correspondientes
- **No subas** el cliente Rakion completo al repo (solo el servidor)
- **Usa .gitignore** para evitar subir `bin/`, `obj/`, `logs/`, `*.dmp`

---

## 📚 Documentación Técnica

Toda la documentación de reversing está en `analysis/`:

| Documento | Contenido | Peso |
|-----------|-----------|------|
| [`RAKION_RE_MASTER.md`](analysis/RAKION_RE_MASTER.md) | Documento maestro — arquitectura, estructuras C++ (CWorld, CField, CUser), DB schema, PRTCLIB crypto | 58 KB |
| [`01_functions_list.md`](analysis/01_functions_list.md) | Lista de 1046 funciones con nombres reales descubiertos | 52 KB |
| [`03_packet_opcodes.md`](analysis/03_packet_opcodes.md) | Tabla de 86 opcodes de red con handlers, payloads y respuestas | 24 KB |
| [`login_flow.md`](analysis/login_flow.md) | Flujo login completo: Game → DBWorker → DBResponse → Cliente | 23 KB |
| [`character_management.md`](analysis/character_management.md) | Sistema de personajes 100%: DB, slots, gold, cash, 0x360 offset map | 54 KB |
| [`lobby_phase.md`](analysis/lobby_phase.md) | Fase Lobby/Sala: 14 opcodes, room structure, shop, equip, whisper | 31 KB |
| [`shop_inventory_refinery.md`](analysis/shop_inventory_refinery.md) | Shop/Inventory/Refinery 100%: Buy, Equip, Sell, Enchant, Lotto | 38 KB |
| [`program_info.md`](analysis/program_info.md) | Info del binario PE, secciones, entry point, strings útiles | 4 KB |
| [`SESSION_LOG.md`](analysis/SESSION_LOG.md) | Historial de 9 sesiones de análisis | 18 KB |

### Archivos .c Decompilados (151)

Los archivos `.c` en `analysis/funcs/` son la salida directa de Ghidra MCP. Los más importantes:

| Archivo | Función | Descripción |
|---------|---------|-------------|
| `FUN_0042cee0.c` | CWorld::Idle | Main loop del servidor (68 KB) |
| `FUN_0042ab40.c` | Game Dispatcher | Switch de 86 opcodes |
| `FUN_0041ae50.c` | DBWorker Dispatcher | Switch de 40 opcodes DB |
| `FUN_004295c0.c` | DBResponseDispatch | ~32 sub-opcodes de respuesta |
| `FUN_0042bd70.c` | IOCP Loop | Procesamiento de colas |
| `FUN_004107d0.c` | DBCommandLogin | Login handler DB (42 KB) |
| `FUN_0040c310.c` | Buy + Enchant | Compra items + refinería (700 líneas) |
| `FUN_00419a40.c` | DBCommandInventoryBuy | Compra en DB (578 líneas) |
| `FUN_0041a900.c` | DBCommandInventorySell | Venta en DB (239 líneas) |
| `FUN_00421e10.c` | Buy Handler (0x74) | Handler de opcode compra |
| `FUN_00421a50.c` | Equip Handler (0x73) | Handler de opcode equipar |
| `FUN_0040c140.c` | EquipProcessing | Lógica de equipar (swap slots, validar tipo) |
| `FUN_0040f0a0.c` | Lotto Draw | Sorteo de lotería con DB |
| `FUN_0040ec50.c` | Lotto Buy | Compra de ticket de lotería |

---

## 💡 Tips para Desarrolladores

### Cómo depurar el protocolo
1. Los logs del servidor muestran cada paquete TX/RX con prefijo `TCP TX`/`TCP RX`
2. El código C decompilado en `analysis/funcs/` muestra EXACTAMENTE qué bytes envía el servidor original

### Entendiendo el AES-ECB 0x7FC4
```
Bloque de 16 bytes encriptados:
  [0x7F, 0xC4, ?, ?, 12 bytes de datos, padding]
  └──────┘  └────┘  └─────────────┘
   header    seq?    payload real (12 bytes)
   
Cada 16 bytes encriptados → 12 bytes de datos útiles
Clave estática: E1 3A 7E F5 37 2C 10 4D 4E CE B3 0C 56 26 A4 8E
```

### Mapeo de tipos de item
```
Items 1000-7999   → Armas
Items 8000-8999   → Armaduras
Items 11000-11999 → Shop items (precio = itemId * 8000/100 o *12000/100)
Items 12000-12999 → Items de evento/quest (swap directo en equip)
Scroll 0x32C9-0x32CD → Enchant scrolls (+1 a +5)
Catalizador 0x36B1-0x36B3 → Catalizadores (C1, C2, C3)
Slots 0-2         → Equip activo (arma, armadura, accesorio)
Slots 3-9         → Equip extendido/mascotas
Slots 10-119      → Inventario general
```

---

## 📄 Licencia

Este proyecto está licenciado bajo **GNU General Public License v3.0**.

El binario `RakionWorldServ.exe` y `WorldServerDll.dll` son propiedad de **Softnyx Co., Ltd.** y se incluyen SOLO con fines de investigación/educativos. No se permite su redistribución comercial.

---

## 🙏 Agradecimientos

- A la comunidad de reversing de juegos online clásicos
- A los desarrolladores de Ghidra (NSA) y GhidraMCP (schriftgestalt)
- A Softnyx por crear Rakion (2005-2014)

---

> **¿Preguntas?** Abre un issue en GitHub o contacta a los mantenedores.
>
> **¿Quieres ayudar?** Empieza por leer los documentos en `analysis/` y elige un opcode sin implementar.
