# Rakion World Server

> **Archivos relacionados:**
> - `RAKION_RE_MASTER.md` — documento maestro (arquitectura)
> - `03_packet_opcodes.md` — tabla de opcodes descubiertos
> - `login_flow.md` — flujo login completo
> - `character_management.md` — Character Management 100%
> - `lobby_phase.md` — fase Lobby/Sala
> - `program_info.md` — info del binario PE

---

## Sesión 8 — 2026-05-29 (shop/inventory/refinery)
**Herramientas:** Análisis de archivos .c existentes (Ghidra MCP no disponible) · **Archivos .c:** 151

### Resumen
Documentación completa del sistema de tienda, inventario y refinería en `shop_inventory_refinery.md` (~750 líneas). Análisis detallado de los handlers decompilados: Buy (0x74→FUN_00421e10→FUN_0040c310), Equip (0x73→FUN_00421a50→FUN_0040c140), Sell (FUN_0041a900), BuyBag (FUN_00414e70), BuyPowerUser (FUN_00415cb0). **Descubrimiento crítico:** El sistema de Refinery/Enchant fue ENCONTRADO dentro de FUN_0040c310.c (700+ líneas) con scrolls 0x32C9-0x32CD, catalizadores 0x36B1-0x36B3, fórmula de probabilidad con tabla pp[] + seed. Cross-references actualizados en todos los .md.

### Completado (`shop_inventory_refinery.md`)
- **Sistema de Compra (0x74):** flujo completo cliente→handler→DB con FUN_0040c310 como núcleo, buffer subopcode 0x28, DBCommandInventoryBuy (FUN_00419a40).
- **Refinería/Enchant:** ubicado en FUN_0040c310 (antes marcado como NO ENCONTRADO). Scrolls: 0x32C9 (+1) a 0x32CD (+5). Catalizadores: 0x36B1 (C1), 0x36B2 (C2), 0x36B3 (C3). Fórmula: pp[0..5] según nivel (thresholds 7, 9, 15) + catalystBonus. Resultados: 0=no enchant, 1=éxito, 2=fallo.
- **Sistema de Venta:** DBCommandInventorySell (FUN_0041a900): DELETE slot + UPDATE gold + log.
- **Sistema de Equip (0x73):** FUN_00421a50→FUN_0040c140 (MISSING), buffer subopcode 0x27.
- **BuyBag (FUN_00414e70):** compra de bolsa de items aleatorios con INSERT + pendingpresents.
- **BuyPowerUser (FUN_00415cb0):** UPDATE powertime + generación de 0-4 regalos aleatorios con _rand() + INSERT pendingpresents/logpresent.
- **Shop Category Loader (FUN_0040cd70):** carga items por rango de ID (1000-7999=armas, 8000-8999=armaduras, 12000-12999=evento).
- **SQL Patterns:** todas las queries atomicas (UPDATE gold WHERE gold>=precio), DELETE por slot, INSERT con logs.
- **12 funciones MISSING** listadas para cuando Ghidra MCP esté disponible.
- **Códigos de error:** 0xDE-0xE4 + 0x00-0x01 para shop/equip.
- **Actualizados cross-refs:** RAKION_RE_MASTER.md, lobby_phase.md, 03_packet_opcodes.md, 01_functions_list.md.
- **Corregido SESSION_LOG.md:** enchant ya no es "NO ENCONTRADO" — está en FUN_0040c310.c con scrolls+catalizadores.

## Sesión 7 — 2026-05-29 (final, consolidación)
**Herramientas:** Ghidra MCP (análisis existente) · **Archivos .c:** 151 en `analysis/funcs/`

### Resumen
Expansión de Character Management al 100% con esquema BD completo, slot 0x360 mapeado offset por offset, todas las queries SQL exactas del binario, oro/cash/pets/clan/PowerUser. Consolidación cross-reference entre todos los .md.

### Completado en Character Management (`character_management.md`)
- Esquema BD completo: 12+ tablas con columnas exactas, tipos, PKs, FKs
- Todas las queries SQL extraídas (auth, UserGameInfo, CharacterInfo, UserItemInfo, Cash, StageInfo, ClanInfo)
- Slot 0x360 mapeado offset por offset campo por campo
- Items compartidos de cuenta (UserItemInfo.characterid=0 → paquete 0x0D, 120 slots)
- Oro atómico (UPDATE ... SET gold=gold-%u WHERE gold>=%u)
- Cash keyeado por username string (NO accountId numérico)
- Pets = items en UserItemInfo (no tabla separada)
- Sistema Power User (powertime + powerlevelpoint)
- Slots de personaje controlados por UserGameInfo.slot (default 5, máx 10)
- Tabla ItemInfo con columnas exactas
- 15+ tablas de log

### Completado en cross-referencing
- Todos los .md ahora se referencian entre sí correctamente
- login_flow.md → character_management.md, lobby_phase.md
- 03_packet_opcodes.md → character_management.md, login_flow.md
- RAKION_RE_MASTER.md → character_management.md, lobby_phase.md
- program_info.md conteo actualizado (128→151 .c)
- SESSION_LOG.md con Sesión 7 agregada

### Pendiente global
- ❌ Sistema de encantamiento/reinforce — NO ENCONTRADO en el binario
- ❌ Sistema P2P/UDP battle
- ❌ Callback IOCP real (GetQueuedCompletionStatus)
- ❌ Implementar emulador C# (login + personajes + lobby ya documentados)
- ❌ Fase In-Game (opcodes 0x50-0x77) — solo stubs
- ❌ Sistema NPC (spawn, AI, interacciones)

---

## Sesión 6 — 2026-05-29 (tarde)
**Herramientas:** Ghidra MCP headless

### Resumen
Descubrimiento de **PRTCLIB** — la capa de cifrado delegada a `WorldServerDll.dll`. Se encontraron 6 funciones PRTC vía strings + GetProcAddress en `FUN_004304f0`. Corrección de errores de sesiones anteriores.

### Funciones PRTCLIB descubiertas
| Función | Propósito |
|---------|-----------|
| `PrtcGetVersion` | Obtener versión del protocolo |
| `PrtcGetAuthQuery` | Obtener query de autenticación |
| `PrtcCheckAuthAnswer` | Verificar respuesta de auth |
| **`PrtcEncryptQuery`** | **Cifrar paquetes salientes (AES)** |
| **`PrtcDecryptAnswer`** | **Descifrar paquetes entrantes (AES)** |
| `PrtcUpdateTimer` | Actualizar timer del protocolo |

### Correcciones a sesiones anteriores
- ❌ "AES no existe" → CORREGIDO: `PrtcEncryptQuery`/`PrtcDecryptAnswer` existen en WorldServerDll.dll
- ❌ "0x000C no es login" → CORREGIDO: 0x0C post-switch → FUN_0041f6c0 (game handler para login normal)
- ❌ "Opcode 4 bytes" → CORREGIDO: dispatcher recibe `ushort param_2` (2 bytes)
- ✅ El codec AES-ECB + 0x7FC4 del usuario es CORRECTO

### Pendiente
- ❌ Verificar formato exacto cabecera TcpRecvQueue (FUN_004038d0)
- ❌ Callback IOCP real (GetQueuedCompletionStatus)
- ❌ Sistema de encantamiento/reinforce
- ❌ Sistema P2P/UDP battle
- ❌ Implementar emulador C# con flujo login + personajes

---

## Sesión 5 — 2026-05-29
**Herramientas:** Ghidra MCP headless (v5.12.0) · **Archivos .c:** 128 en `analysis/funcs/` (~586 KB)

### Resumen
Decompilación masiva de **todos los handlers del dispatcher principal** (86 opcodes) + descubrimiento de **~25 nombres reales** de funciones vía xrefs a strings de debug.

### Opcodes y Handlers
| Opcode | Handler | Nombre Real | Estado |
|--------|---------|-------------|--------|
| 0x01-0x05, 0x08-0x0C, 0x0E-0x1C, 0x1E, 0x20, 0x22, 0x29-0x2F, 0x31-0x36, 0x38-0x43, 0x45-0x4D, 0x4F-0x50, 0x53, 0x56-0x5E, 0x60-0x62, 0x64-0x65, 0x6B-0x79 | 86 handlers decompilados | NetworkMessageFieldReady/Create/List/Exit/Chat/QuickEnter, CWorld::NetworkMessageDisconnect, CWorld::DBPS | ✅ Todos en analysis/funcs/ |
| 0x47 | FUN_004244f0 | **NetworkMessageFieldList** | ✅ |
| 0x4F | FUN_00424a20 | **NetworkMessageFieldQuickEnter** | ✅ |
| 0x53 | FUN_00425010 | **NetworkMessageFieldCreate** | ✅ |
| 0x61 | FUN_0041c270 | **NetworkMessageFieldReady** | ✅ |
| 0x79 | FUN_00422270 | **CWorld::NetworkMessageDisconnect** | ✅ |
| 0x08 | FUN_00429030 | **CWorld::DBPS** | ✅ |

### Nombres Reales Descubiertos vía Strings
**CWorld**: `NetworkMessageDisconnect`, `Idle`, `DBPS`, `ProcessUserDisconnect`, `GetRandomPresentIndex`, `DBCommandBuyLotto`, `DBCommandAskLotto`, `DBCommandLogin1`

**CDB/DBCommand**: `DBCommandLogin`, `DBCommandCharacterCreate/Delete/List/Select/GetUserName/StateClear/ChangeCharName`, `DBCommandInventoryEnter/Buy/Sell/BuyBag/BuySlot/BuyPowerUser/BuyPotionSlot/BuyStageRankClear/StageLevelFree`, `DBCommandAdminBan`, `DBCommandBuyLotto/AskLotto/LottoResult`, `DBCommandAskClan`, `DBCommandFieldCreateStage`, `DBCommandPresentAccept`

### Archivos generados
- `03_packet_opcodes.md` — tabla completa 86 opcodes + DBWorker
- `FUN_0042ab40_dispatcher.c` — switch del dispatcher completo
- 86 handlers del dispatcher como archivos .c individuales (incluyendo 9 que estaban inline)
- Anotaciones de nombres reales en `01_functions_list.md`
- RAKION_RE_MASTER.md actualizado

### Correcciones a sesiones anteriores
- ❌ 87 opcodes → **86 opcodes reales** (el case 7 repetido contaba doble)
- ❌ Varias funciones marcadas como "no guardadas" ahora están decompiladas
- ✅ Nuevo conocimiento: el binario tiene strings de debug con nombres de clase (CWorld::, CDB::)

### Pendiente
- Callbacks IOCP reales (GetQueuedCompletionStatus)
- Sistema de encantamiento/reinforce
- Sistema P2P/UDP battle
- Handlers de field/stage restantes
- Empezar emulador C# con flujo login + personajes

---

## Sesión 4b — 2026-05-28 (noche, continuación)

## Sesión 4b — 2026-05-28 (noche, continuación)
**Herramientas:** Ghidra MCP

### Funciones decompiladas (10 nuevas, archivos .c guardados)
| Función | Archivo .c | Propósito |
|---------|-----------|-----------|
| FUN_0041fcd0 | `FUN_0041fcd0.c` | Game opcode 0x12 — Character create confirmation (push DB opcode 7) |
| FUN_0041fe10 | `FUN_0041fe10.c` | Game opcode 0x13 — Character delete confirmation (push DB opcode 8) |
| FUN_0041fef0 | `FUN_0041fef0.c` | Game opcode 0x14 — Character select (itera slots 0x360 bytes c/u) |
| FUN_0041f5c0 | `FUN_0041f5c0.c` | Game opcode 0x09 — Item info display (array 0x3C0 en this+0xE4) |
| FUN_0041c3d0 | `FUN_0041c3d0.c` | DB Response case 7 — Character select response (carga char data en field) |
| FUN_00413cd0 | `FUN_00413cd0.c` | DB opcode 0x10 — Character state clear / level up (power level points + cash) |
| FUN_00413bd0 | `FUN_00413bd0.c` | DB opcode 0x0F — LogDiePlayer (inserta log de muerte) |
| FUN_00413b00 | `FUN_00413b00.c` | DB opcode 0x0E — Tutorial update |
| FUN_0040f610 | `FUN_0040f610.c` | DB opcode 0x2B — Clan/buddy list query |
| FUN_0041f480 | `FUN_0041f480.c` | Game opcode 0x0B — MD5 config setup |

### Hallazgos

**1. Handlers de personajes mapeados:**
- **Create** (game 0x12 → DB opcode 7): formato `[counter:2][7:2][userId:4][name\0][class:1][slot:1]`
- **Delete** (game 0x13 → DB opcode 8): formato `[counter:2][8:2][charId:4][name\0]`
- **Select** (game 0x14): procesa slot array de 0x360 bytes por personaje en field

**2. Character select flow completo:**
```
Client → game opcode 0x14 → FUN_0041fef0 (valida field+0x1460, busca charId en slots)
  → FUN_0040be30 (load char data) → FUN_0040d3f0 (access check)
  → push DB command → DB opcode 0x10? → DB Response case 7 (FUN_0041c3d0)
  → FUN_004038e0 → client
```

**3. Sistema de encantamiento NO ENCONTRADO:** ninguna función del binario referencia "enchant", "reinforce", "LevelUp" en strings. Posiblemente en game opcodes 0x15–0x1C o 0x29–0x36 sin decompilar.

### Archivos .c nuevos
- `FUN_0041fcd0.c`, `FUN_0041fe10.c`, `FUN_0041fef0.c`, `FUN_0041f5c0.c`
- `FUN_0041c3d0.c`, `FUN_00413cd0.c`, `FUN_00413bd0.c`, `FUN_00413b00.c`
- `FUN_0040f610.c`, `FUN_0041f480.c`
- `handlers_summary_session4b.c`

---

## Sesión 4a — 2026-05-28 (noche, primera parte)
**Herramientas:** Ghidra MCP

### Funciones decompiladas (17, archivos .c guardados)
| Función | Archivo .c | Propósito |
|---------|-----------|-----------|
| FUN_0041ee00 | `FUN_0041ee00.c` | Game opcode 0x01 — Admin IP check |
| FUN_0041ef00 | `FUN_0041ef00.c` | Game opcode 0x02 — Server info response |
| FUN_0041f1a0 | `FUN_0041f1a0.c` | Game opcode 0x04 — DB login command sender |
| FUN_00410650 | `FUN_00410650.c` | DB opcode 0x01 — Admin ban handler |
| FUN_004107d0 | `FUN_004107d0.c` | **DB opcode 0x02 — Login response builder (~4000 líneas)** |
| FUN_00412140 | `FUN_00412140.c` | DB opcode 0x04 — LogUserConnect disconnect update |
| FUN_004121e0 | — | DB opcode 0x05 — LogUserConnect RealIP update |
| FUN_00412280 | — | DB opcode 0x07 — Character create |
| FUN_00412530 | — | DB opcode 0x08 — Character delete |
| FUN_0041fb30 | `FUN_0041fb30.c` | Game opcode 0x0F — Heartbeat/timeout check |
| FUN_0041fc00 | `FUN_0041fc00.c` | Game opcode 0x10 — GameGuard/state check |
| FUN_0041ae50 | `FUN_0041ae50.c` | **DB dispatcher** (40 opcodes) |
| FUN_004295c0 | `FUN_004295c0_DBResponseDispatch.c` | **DB Response dispatch** (30+ sub-opcodes) |
| FUN_00426b30 | `FUN_00426b30.c` | DB Response case 2 — Login response processor |
| FUN_00426290 | `FUN_00426290.c` | DB Response case 3 — Character data processor |
| FUN_004261d0 | — | DB Response case 1 — Auth duplicate check |
| FUN_0042a310 | — | Post-switch handler — admin/GM HTTP auth |

### Hallazgos clave
  - **Tres dispatch tables separadas:** game (86), DB (40), DB Response (30+)
- **Flujo login completo:** game 0x04 → DB opcode 2 → DB Resp case 2 → cliente
- **Formatos de cola DB:** command `[retOpcode:2][dbOpcode:2][payload:N]`, response `[fieldId:2][size:2][retOpcode:2][subType:2][payload:N]`
- **Login result codes:** 0=ok, 1=DB err, 2=not found, 3=wrong pw, 6=banned, 0x1A=success
- **Estructuras C++:** CWorld (0x5F44), CField (0x23B4), TcpListener (0x24), recv buf (0x68)

### Archivos generados
- `login_flow.md` — documento completo del flujo de login
- 10 archivos .c nuevos (ver tabla arriba)

---

## Sesión 3 — 2026-05-28 (tarde)
**Herramientas:** Ghidra MCP

### Funciones decompiladas
FUN_0042bd70 (IOCP loop), FUN_0042ab40 (game dispatcher), FUN_0041ae50 (DB dispatcher),
FUN_0041b940 (DB command sender), FUN_0041b520 (DBWorker init), FUN_0040da80 (AcceptEx callback),
FUN_00404a10 (AcceptEx completion), FUN_004047f0 (WSARecv poster)

### Hallazgos importantes
- 3-thread model: IOCP loop, DBWorker, GameGuard
- PerfLib::IoCompletionPort/ThreadPool = dead code
- Queue format: [fieldId:2][dataSize:2][opcode+payload:N]
- FUN_004038e0 = SEND (not queue writer)
- Estructuras: CField offsets (+0x1440 state, +0x146e seq, +0x1480 connectTime)
- TcpListener struct (0x24), recv buffer struct (0x68, state 0-4)

---

## Sesión 2 — 2026-05-28 (mañana)
**Herramientas:** Ghidra MCP

### Funciones decompiladas (24 archivos .c)
| Archivo | Propósito |
|---------|-----------|
| `FUN_00401670.c` | Inicialización |
| `FUN_004087d0.c` | Procesamiento de datos |
| `FUN_00409940.c` | DB query builder |
| `FUN_004107d0.c` | Login response builder (42 KB) |
| `FUN_004129f0.c` | DB handler |
| `FUN_00415cb0.c` | Handler |
| `FUN_00416d90.c` | Handler |
| `FUN_0041ae50.c` | DB dispatcher (5.1 KB) |
| `FUN_0041b700.c` | Handler |
| `FUN_00426290.c` | DB Response case 3 |
| `FUN_00426b30.c` | DB Response case 2 |
| `FUN_00429a70.c` | Handler |
| `FUN_0042a670.c` | Handler |
| `FUN_0042a810.c` | CWorld creator |
| `FUN_0042aad0.c` | CWorld singleton getter |
| `FUN_0042ab40.c` | Game dispatcher (12.6 KB) |
| `FUN_0042bd70.c` | IOCP loop (19.8 KB) |
| `FUN_0042cc10.c` | Handler |
| `FUN_0042cd50.c` | Handler |
| `FUN_0042cee0.c` | Server init (68 KB, función más grande) |
| `FUN_0042f280.c` | Logging |
| `FUN_00431020.c` | Handler |

### Hallazgos clave
- 1046 funciones totales, binario completamente stripped
- 86 game opcodes + 40 DB opcodes extraídos
- Endpoint `search_functions_by_name` roto

---

## Sesión 1 — [fecha sin registro]
**Herramientas:** Análisis estático básico

### Hallazgos importantes
- Headers PE parseados, ~600 strings extraídos
- 30+ tablas MySQL mapeadas
- Clases principales identificadas
- Dependencias DLL mapeadas
- Sistema de tiempo documentado

---

## RESUMEN GENERAL — Archivos .c en analysis/funcs/ (151 archivos, ~700 KB)

### Sesión 2 (base, 22 archivos)
FUN_00401670, FUN_004087d0, FUN_00409940, FUN_004107d0, FUN_004129f0,
FUN_00415cb0, FUN_00416d90, FUN_0041ae50, FUN_0041b700, FUN_00426290,
FUN_00426b30, FUN_00429a70, FUN_0042a670, FUN_0042a810, FUN_0042aad0,
FUN_0042ab40, FUN_0042bd70, FUN_0042cc10, FUN_0042cd50, FUN_0042cee0,
FUN_0042f280, FUN_00431020

### Sesión 3 (nuevos, ~8 archivos)
FUN_0042bd70 (ya existía), FUN_0042ab40 (ya existía), FUN_0041ae50 (ya existía),
FUN_0041b940, FUN_0041b520, FUN_0040da80, FUN_00404a10, FUN_004047f0

### Sesión 4a (nuevos, 12 archivos)
FUN_0041ee00.c, FUN_0041ef00.c, FUN_0041f1a0.c, FUN_00410650.c,
FUN_004107d0.c (ya existía), FUN_00412140.c, FUN_004295c0_DBResponseDispatch.c,
FUN_00426b30.c (ya existía), FUN_00426290.c (ya existía),
FUN_0041fb30.c, FUN_0041fc00.c, login_flow.md

### Sesión 4b (nuevos, 10 archivos)
FUN_0041fcd0.c, FUN_0041fe10.c, FUN_0041fef0.c, FUN_0041f5c0.c,
FUN_0041c3d0.c, FUN_00413cd0.c, FUN_00413bd0.c, FUN_00413b00.c,
FUN_0040f610.c, FUN_0041f480.c, handlers_summary_session4b.c

### Sesión 5 (nuevos, ~86 archivos)
FUN_0042ab40_dispatcher.c — switch completo con 86 cases
Handlers de todos los opcodes game (FUN_0041ee00 hasta FUN_0041bde0)
Incluye los que antes eran inline: FUN_004292b0, FUN_004293f0, FUN_00428520,
FUN_00421a50, FUN_004222a0, FUN_004225d0, FUN_0041be60, FUN_0041bde0, FUN_00422270

### Inline NO guardados como .c (restantes)
FUN_004138b0, FUN_00413980, FUN_0040f0a0, FUN_0040ec50

### PENDIENTE GLOBAL (Actualizado Sesión 9)
- ❌ Sistema P2P/UDP battle — sin analizar
- ❌ Callback IOCP real (GetQueuedCompletionStatus)
- ❌ Implementar emulador C# — login + personajes + lobby + shop ya documentados al 100%
- ❌ Fase In-Game (opcodes 0x50-0x77) — solo stubs, helpers no decompilados
- ❌ Sistema NPC (spawn, AI, interacciones) — solo NPCInfo table conocida
- ❌ Identificar `CWorld::Idle` (FUN_0042cee0, 68 KB)
- ✅ ~~12 funciones shop/inventory/refinery MISSING~~ — **TODAS DECOMPILADAS vía Ghidra MCP (2026-05-29)**
- ✅ ~~Descompilar con Ghidra MCP~~ — **COMPLETADO: Ghidra MCP operativo (port 8089), 12/12 funciones decompiladas**
