# TABLA DE OPCODES — Rakion World Server
## Dispatcher: FUN_0042ab40 (86 cases)

> **Archivos relacionados:**
> - `01_functions_list.md` — lista completa de funciones con nombres reales anotados
> - `login_flow.md` — flujo login completo (game → DB → DB Response → cliente)
> - `character_management.md` — análisis completo de Character Management (6 opcodes, DB schema, slot 0x360)
> - `lobby_phase.md` — análisis completo de fase Lobby/Sala (14 opcodes, room structure, shop, equip)
> - `shop_inventory_refinery.md` — análisis detallado de Buy (0x74), Equip (0x73), Sell, Enchant/Refinery
> - `RAKION_RE_MASTER.md` — documento maestro (arquitectura, estructuras C++, DB, PRTCLIB crypto)
> - `funcs/FUN_0042ab40_dispatcher.c` — código del switch decompilado

> **Correcciones importantes (Sesión 6):**
> - El cifrado AES-ECB 0x7FC4 SÍ existe, delegado a WorldServerDll.dll (PrtcEncryptQuery/PrtcDecryptAnswer)
> - Opcode 0x0C no es solo "DB Response" — bifurca entre game handler (ruta normal) y DB handler
> - Opcode 0x04 es login ADMIN, el login normal va por 0x0C post-switch → FUN_0041f6c0
> - El opcode es `ushort` (2 bytes), no uint32

### Pipeline de red completo
```
Wire TCP: [AES_encrypted_blocks_0x7FC4]
  → PrtcDecryptAnswer (WorldServerDll.dll) → datos descifrados
  → TcpRecvQueue push → FUN_0042bd70 (main loop pop)
  → FUN_0042ab40 (dispatcher, 86 opcodes)
  → handler → FUN_004038e0 (SEND)
  → PrtcEncryptQuery (WorldServerDll.dll) → AES re-cifrado
  → WSASend → wire
```

### Formato de cola (TcpRecvQueue, pop en FUN_004038d0)
```
Offset  Tipo     Campo
------  -------  ------
0x00    ushort   fieldId (índice de conexión/jugador)
0x02    ushort   dataSize (bytes totales de opcode + payload)
0x04    uint32   seqNum/header (4 bytes de cabecera interna)
0x08    ushort   opcode (2 bytes)
0x0A    ...      payload (dataSize - 2 bytes)
```

### Llamada al dispatcher
```
FUN_0042ab40(world, fieldId, opcode, dataSize, dataPtr)
```
Donde `opcode` es `ushort` (2 bytes), `dataSize` es `uint`, `dataPtr` apunta al payload.

### Cifrado
El cifrado AES-ECB con bloque 0x7FC4 se delega a `WorldServerDll.dll` vía:
- **`PrtcEncryptQuery`** (struct+0x24) — encrypt de paquetes salientes
- **`PrtcDecryptAnswer`** (struct+0x28) — decrypt de paquetes entrantes

Ver `RAKION_RE_MASTER.md` sección 5 para detalles completos de PRTCLIB.

---

## Flujo completo: Login → Channel → Personajes → Lobby → Sala → Juego

```
Login normal (0x0C post-switch → FUN_0041f6c0) 
    o Admin login (0x04 → FUN_0041f1a0)
  → DB opcode 2 → DB Resp case 2 (login + char list)
  → DB Resp case 3 (char data chunks)
Channel Select (0x05)
  → Busca canal por nombre → envía info del canal

Char Management (0x12, 0x13, 0x14, 0x15, 0x19, 0x1A)
  → Crear, borrar, seleccionar personaje
  → Character select (0x14) → transición a estado LOBBY (0x1440 = 0x02)

Lobby (0x1440 = 0x02)
  → Movimiento (0x31)
  → Equipar/comprar items (0x73, 0x74)
  → Listar salas (0x36)
  → Crear sala (0x2E, 0x3B)
  → Unirse a sala (0x29, 0x38, 0x39)
  → Tienda/lotto (0x2F, 0x75)
  → Guardar skills/quests (0x6F, 0x70, 0x71)

Sala/Room (0x1440 = 0x03)
  → Ready/Unready (0x42, 0x43)
  → Cambiar equipo (0x4A-0x4D)
  → Cambiar settings (0x3D, 0x41, 0x40)
  → Iniciar juego (0x46)
  → Chat (0x56)

Juego (dentro del socket UDP / game dispatcher)
  → Acciones de juego (0x57, 0x59, 0x5A)
  → Resultado (0x5D, 0x5E)
```

### Estados del field (offset +0x1440)
| State | Descripción |
|-------|-------------|
| 0x00 | Vacío/init |
| 0x01 | Conectando |
| 0x02 | **Lobby** — personaje seleccionado, en el hub |
| 0x03 | **Sala/Room** — dentro de una sala de juego |
| 0x04 | Admin autenticado |
| 0x05 | Superadmin |

---

## Tabla completa de 86 opcodes de red

### FASE 1: Autenticación / Admin (states 0x04-0x05)

| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 1 | 0x01 | `FUN_0041ee00` | **Admin IP check** — verifica IP del cliente contra lista de admins. Setea field state a 4 (admin) o 5 (superadmin). Primer paso antes del login | ✅ | ❌ |
| 2 | 0x02 | `FUN_0041ef00` | **Server info response** — requiere estado ≥4. Devuelve flags del server, nombre, URL auth, puerto, counts | ✅ | ❌ |
| 3 | 0x03 | `FUN_0041f060` | **Server open/close** — superadmin only. Toggle flag global `this+0x50`. Al cerrar, kickea a todos los no-admin | ✅ | ❌ |
| 8 | 0x08 | `FUN_00429030` | **CWorld::DBPS** — señal de heartbeat/DB ping | ❌ | ❌ |

### FASE 2: Login / Channel Entry

| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 4 | 0x04 | `FUN_0041f1a0` | **Admin Login** — requiere field state 5 o subState 1/4 (admin). Pushea username a DB opcode 2 | ❌ | ✅ sub=1, dbOp=2 |
| 5 | 0x05 | `FUN_0041f290` | **Channel search/enter** — busca canal por nombre (≤12 chars). Si name vacío, broadcast a todos los fields. Si name dado, busca match vía `FUN_0040c870`. Envía opcode 99 (0x63) al field del canal | ✅ opcode 99 | ❌ |
| 10 | 0x0A | `FUN_00429140` | **Item data query** — requiere estado ≥2. Lee count + item IDs del payload, lookup en tabla de items del server (`this + id*4 + 0x51c8`). IDs ≥0x200 devuelven 0 | ✅ opcode 0x0A | ❌ |
| 11 | 0x0B | `FUN_0041f480` | **MD5 config setup** — configuración de hash MD5 para conexión | ❌ | ❌ |
| 15 | 0x0F | `FUN_0041fb30` | **Heartbeat/timeout** — verifica estado de conexión | ❌ | ❌ |
| 16 | 0x10 | `FUN_0041fc00` | **GameGuard/state check** — verificación anti-cheat | ❌ | ❌ |

### Opcode especial DB Response

| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 12 | 0x0C | `FUN_0041fa40` | **Post-switch handler** — hace `break`, cae al código post-switch. Bifurca según `this+0x5b18`: **0→game handler (`FUN_0041f6c0`, login normal)** o **≠0→DB response dispatch (`FUN_0042a310`)**. Opcode principal para operaciones normales de juego | ❌ | ❌ |
| 14 | 0x0E | `FUN_0041fa40` | (misma función que 0x0C) | ❌ | ❌ |

### FASE 3: Character Management

**Archivo detallado:** `character_management.md` — análisis completo con todas las funciones decompiladas, formatos exactos de paquete y códigos de error.

| Opcode | Hex | Handler | Función | Payload Cliente | Payload Servidor | DB |
|--------|-----|---------|---------|----------------|------------------|----|
| 18 | 0x12 | `FUN_0041fcd0` | **Character create** — lee name (null-term, ≤12) + class(<5) + slot(<6). Pushea DB opcode 7 | `[name\0][class:1][slot:1]` | `[result:1][charId:4][slot:1][class:1][0x07:1]` (8 bytes) | ✅ dbOp=7 |
| 19 | 0x13 | `FUN_0041fe10` | **Character delete** — lee charId(4) + name(≤11, null-term). Pushea DB opcode 8 | `[charId:4][name:str\0]` | `[result:1][charId:4]` (5 bytes) | ✅ dbOp=8 |
| 20 | 0x14 | `FUN_0041fef0` | **Character select** — lee charId. Itera 6 slots (0x360 bytes c/u). Carga stats/items/equip via `FUN_0040ac30`/`FUN_0040be30`. **Transición a lobby** → envía 0x1F+0x1E | `[charId:4]` | **`[result:1]` (SOLO 1 BYTE!)** | ❌ (in-memory) |
| 21 | 0x15 | `FUN_00420120` | **Character name registration** — echo del nombre del personaje | `[name:str\0]` | `[result:1][name:13\0][name:13\0]` (27 bytes) | ✅ sub=0x0b |
| 25 | 0x19 | `FUN_00420760` | **Character name change** — lee nuevo nombre (≤12 chars). Pushea DB con sub=0x0d | `[newName:str\0]` | response via DB | ✅ sub=0x0d |
| 26 | 0x1A | `FUN_00420840` | **Tutorial complete** — lee session ID de field+0x1488. Pushea DB sub=0x0e (8 bytes) | (empty) | ninguno (solo DB) | ✅ sub=0x0e |

**Nota:** Character Select (0x14) envía SOLO 1 byte de payload al cliente (`[result:1]`), NO 3 bytes como se pensaba inicialmente. Luego invoca `FUN_0041b8b0` → `FUN_00404fc0` que construye y envía paquetes 0x1F (ChannelEnter, 18 bytes) y 0x1E (ChannelCharacterState, variable) para completar la entrada al lobby.

**Códigos de error:**
- **Character Create (0x12):** 0=ok, 1=DB error/invalid slot, 2=slot occupied, 3=too many chars, 4=name taken
  - Network errors: 0x1A (name too long), 0x1B (class ≥5), 0xEA (slot ≥6), 0x19 (invalid state)
- **Character Delete (0x13):** 0=ok, 1=DB err, 2=not found, 3=used, 4=userid mismatch, 5=key mismatch, 6=email, 7=email sent, 9=name mismatch
  - Network error: 0x1C (invalid state)
- **Character Select (0x14):** 0=ok, 2=not found
  - Network error: 0x1D (invalid state)
| 30 | 0x1E | `FUN_00429230` | — **OUTGOING**: ChannelCharacterState — enviado por el servidor después de char select | ✅ opcode 0x1E | ❌ |
| 31 | 0x1F | `FUN_00404fc0` (inner) | — **OUTGOING**: ChannelEnter — enviado por el servidor después de char select | ✅ opcode 0x1F | ❌ |

### FASE 4: Lobby Operations (state 0x1440 = 0x02)

#### Lobby — Chat/Social
| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 22 | 0x16 | `FUN_00420200` | **Whisper** — payload `[targetName\0][msg\0]` (name≤12, msg≤128). Busca player vía `FUN_0040af20`. Reenvía `[0x16][0x00][sender\0][msg\0]` a TARGET y SENDER. No encontrado → `[0x16][0x01]` al sender | ✅ opcode 0x16 | ❌ |
| 24 | 0x18 | `FUN_00420520` | **Player lookup by name** — lee name (≤12 chars). Busca player, devuelve nombre + tipo de field (0=lobby, 1=room) + datos específicos | ✅ opcode 0x18 | ❌ |
| 114 | 0x72 | `FUN_00428520` | **Whisper/private message** — reenvía mensaje a otro player en sala | ✅ opcode 0x72 | ❌ |

#### Lobby — Items / Shop
| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 27 | 0x1B | `FUN_004208e0` | **Item buyback** — lee item type byte + index ushort. Busca buyback vía `FUN_0040bd80`. Pushea DB con sub=0x10/0x17 | ✅ error 3 bytes | ✅ sub=0x10/0x17 |
| 28 | 0x1C | `FUN_00420a40` | **Item buy from NPC shop** — copia nombre del item, type byte + index. Vía `FUN_0040bd80`. Pushea DB con sub=0x11 | ✅ error 3 bytes | ✅ sub=0x11 |
| 47 | 0x2F | `FUN_004215a0` | **Shop / item list request** — lee categoría de shop byte (<120). Vía `FUN_0040cd70`. Pushea DB con sub=0x15 | ✅ error 3 bytes | ✅ sub=0x15 |
| 50 | 0x32 | `FUN_004226b0` | **Lobby item/equip query** — vía `FUN_0040b080`. Pushea DB en éxito | ✅ error | ✅ (vía 0x1b940) |
| 53 | 0x35 | `FUN_00422850` | **Lobby item/list request** — similar a 0x32, vía `FUN_0040b1a0`. Pushea DB | ✅ error | ✅ (vía 0x1b940) |
| 115 | 0x73 | `FUN_00421a50` | **Equip/unequip** — payload `[itemSlot:1][equipSlot:1]` (ambos<0x78). Calls `FUN_0040c140` to process. DB sub=0x27 con full equip+inv+stats serialization | ✅ `[0x73][err:1]` | ✅ sub=0x27 |
| 116 | 0x74 | `FUN_00421e10` | **Buy item** — payload `[itemId:2][shopSlot:1][cnt:1][params:cnt]` (cnt<4). Calls `FUN_0040c310`. DB sub=0x28 con full state serialization + precio | ✅ `[0x74][err:1]` | ✅ sub=0x28 |

#### Lobby — Lotto
| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 117 | 0x75 | `FUN_004222a0` | **Buy lotto ticket** — valida money (<1000 gold o <100 cash). Chequea colisiones de números. Envía datos de lotto o pushea DB | ✅ opcode 0x75 | ✅ (vía 0x1b940) |

#### Lobby — Movement / Position
| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 49 | 0x31 | `FUN_00421870` | **Lobby movement** — payload `[x:1][y:1][z:1][w:1]` (coords valid: x<0x78 if 0 else <0x13, z<0x78 if 0 else <0x13). Procesa vía `FUN_0040cf10`. Broadcast 21 bytes `[0x31][coords+derived:19]` a TODOS en lobby (incluye sender echo) | ✅ 21 bytes broadcast | ❌ |
| 51 | 0x33 | `FUN_004229f0` | **Generic lobby query** — vía `FUN_0040b3d0`. Envía respuesta | ✅ (vía 0x038e0) | ❌ |
| 52 | 0x34 | `FUN_00422b10` | **Dual-param item/action** — vía `FUN_0040b2c0` con type+flag. Pushea DB si éxito | ✅ error | ✅ (vía 0x1b940) |

#### Lobby — Room list / Create room
| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 44 | 0x2C | `FUN_00420de0` | **Ready / create room from lobby** — vía `FUN_0040b000`. Si falla validation: SEND 7 bytes. Si pasa: pushea DB sub=0x12 | ✅ 7 bytes | ✅ sub=0x12 |
| 45 | 0x2D | `FUN_00420f10` | **Enter game / start battle** — vía `FUN_0040c960` (item/equip data). Builds packet con items + equip. Pushea DB sub=0x13 | ✅ error 3 bytes | ✅ sub=0x13 |
| 46 | 0x2E | `FUN_00421210` | **Create room (simple)** — payload `[roomType:2][race:1][mode:1][slot:1]`. Calls `FUN_0040cb10` for room creation. DB sub=0x14 | ✅ `[0x2E][err:1]` | ✅ sub=0x14 |
| 54 | 0x36 | `FUN_00422c90` | **Room list query** — payload `[pageCount:1][pageIndex:2][7 filters:7]` (10 bytes). Escanea slots (0x3c0 entries) en canal. Filtra por class, race, level range, gameType. Res: `[0x36][roomCount:1][rooms...]` | ✅ broadcast | ❌ |
| 59 | 0x3B | `FUN_00423580` | **Create room (full)** — payload `[name\0][pw\0][map\0][mode:1][sub:1][mapId:2][minLvl:1][maxLvl:1][race:1][lvlRng:1]`. Valida campos extensivamente (name<40, pw<9, map<201). Crea room + asigna slot. Res: `[0x3B][result:1][roomIdx:2]` (5 bytes) | ✅ 5 bytes | ✅ sub=0x25 |

#### Lobby — Save data / DB sync
| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 107 | 0x6B | `FUN_004286a0` | **Push player basic info to DB** — sub-opcode 0x1e. Sin state check | ❌ | ✅ sub=0x1e |
| 108 | 0x6C | `FUN_00428750` | **Push full inventory+equip+stats to DB** — serializa todos los items equipados + inventario. Sin state check | ❌ | ✅ sub=? |
| 109 | 0x6D | `FUN_00428a10` | **Push single item to DB** — sub-opcode 0x20. Sin state check | ❌ | ✅ sub=0x20 |
| 111 | 0x6F | `FUN_00428d80` | **Save skill tree to DB** — chequea class en field+0x2368 (0x03/0x04/0x05). Pushea sub=0x21 | ❌ | ✅ sub=0x21 |
| 112 | 0x70 | `FUN_004292b0` | **Save quest/special data to DB** — selecciona data source según level bracket (<10, 10-20, 21-40, >40). sub=0x23 | ❌ | ✅ sub=0x23 |
| 113 | 0x71 | `FUN_004293f0` | **Save achievement/collection data to DB** — sub=0x24 | ❌ | ✅ sub=0x24 |
| 118 | 0x76 | `FUN_004225d0` | **Push simple data to DB** — envía 1 byte con sub=0x2a | ❌ | ✅ sub=0x2a |
| 120 | 0x78 | `FUN_0041bde0` | **Push extended player data to DB** — lee datos de field+0x14d0. sub=0x2c | ❌ | ✅ sub=0x2c |

### FASE 5: Room Operations (state 0x1440 = 0x03)

#### Room — Join / Leave / Kick
| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 41 | 0x29 | `FUN_00420c20` | **Join room (in-room)** — payload `[roomIdx:2][pw?]`. Valida room activa (offset 8). Calls `FUN_00406240`. NOTA: solo funciona si ya en ROOM state (0x03) — para cambio de sala | ❌ | ❌ |
| 42 | 0x2A | `FUN_00420cb0` | **Room invite/observe** — payload `[targetId:2]`. Si target en lobby (0x02), envía 8-byte invite packet | ✅ 8 bytes | ❌ |
| 56 | 0x38 | `FUN_00423100` | **Join room (password)** — payload `[roomIdx:2][pw\0]`. Si room gameType==0: DB push sub=0x26. Si gameType!=0: direct join via `FUN_00406f40` + `FUN_0040b7b0` (state→ROOM) | ✅ `[0x38][0x05]` si no LOBBY | ✅ sub=0x26 |
| 57 | 0x39 | `FUN_00423300` | **Quick-join / auto-match** — itera rooms, match por race/class. Auto-join al primero | ✅ fallback | ❌ |
| 62 | 0x3E | `FUN_00423b70` | **Leave room** — no payload. Extracts room+channel via `FUN_0040b7d0`. Calls `FUN_004075a0` (state→LOBBY). Error 0x62 si no login, 99 si no ROOM state | ❌ | ❌ |
| 63 | 0x3F | `FUN_00423c00` | **Kick player from room** — chequea host flag (0x146c == 4). Vía `FUN_00405740` | ❌ | ❌ |
| 69 | 0x45 | `FUN_004242c0` | **Transfer room master** — vía `FUN_00407c70` | ❌ | ❌ |
| 72 | 0x48 | `FUN_00424640` | **Room invite** — vía `FUN_00408440` | ❌ | ❌ |
| 79 | 0x4F | `FUN_00424a20` | **NetworkMessageFieldQuickEnter** — lee channel idx (≤8) + room idx (≤19). Procesa entrada a field vía `FUN_004087d0`. Error si ya en estado incorrecto | ✅ error (0x8F-0x92) | ❌ |
| 83 | 0x53 | `FUN_00425010` | **NetworkMessageFieldCreate** — crea entrada en field. Valida estado, inicializa datos de personaje en el field | ❌ | ❌ |
| 71 | 0x47 | `FUN_004244f0` | **NetworkMessageFieldList** — copia nombre de field al slot. Envía opcode 0x47 al item del campo | ✅ opcode 0x47 | ❌ |
| 97 | 0x61 | `FUN_0041c270` | **NetworkMessageFieldReady** — setea valor en field array. Si valor == `this+0x51b4`, incrementa contador en `this+0x51bc` | ❌ | ❌ |

#### Room — State / Settings
| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 58 | 0x3A | `FUN_004234e0` | **Room state change** — vía `FUN_0040b7d0` + `FUN_004091e0` | ❌ | ❌ |
| 61 | 0x3D | `FUN_00423ad0` | **Room data/state update** — vía `FUN_00407520` | ❌ | ❌ |
| 64 | 0x40 | `FUN_00423cc0` | **Change slot/team** — valida host/master permission. Vía `FUN_004097c0` | ❌ | ❌ |
| 65 | 0x41 | `FUN_00423dd0` | **Change room settings/map** — valida map/game mode. Vía `FUN_004077c0` | ❌ | ❌ |
| 66 | 0x42 | `FUN_00424100` | **Toggle ready state** — valida slot index + action type (<0x14). Vía `FUN_00407910` | ❌ | ❌ |
| 67 | 0x43 | `FUN_00424210` | **Toggle unready** — vía `FUN_004079d0` | ❌ | ❌ |
| 70 | 0x46 | `FUN_00424350` | **Start game** — valida slot info. Vía `FUN_0041b860`. Pushea DB con equip data. Envía opcode 0x58 (game start) | ✅ opcode 0x58 | ✅ (vía 0x1b940) |

#### Room — Equip / Character
| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 74 | 0x4A | `FUN_004246e0` | **Select character in room** — vía `FUN_00405a90` | ❌ | ❌ |
| 75 | 0x4B | `FUN_004247b0` | **Equip item in room** — valida item count ≤200. Vía `FUN_00405c00` | ❌ | ❌ |
| 76 | 0x4C | `FUN_00424880` | **Change item/skill slot** — valida type <0x14, count ≤200. Vía `FUN_00405cc0` | ❌ | ❌ |
| 77 | 0x4D | `FUN_00424980` | **Change position/offset** — vía `FUN_00405d70` | ❌ | ❌ |

### FASE 6: In-Game (Room state 0x03)

| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 80 | 0x50 | `FUN_00424b60` | **NetworkMessageFieldExit** — salida de field con contabilidad de gold/points. Lee gold, points, action flag. Valida via `FUN_0041cf80`. Multiplica gold ×1.5 si bonus flag. Procesa items via `FUN_0040b940`. Pushea DB campo completo (0x40 bytes) | ✅ opcode 0x51 (5 bytes) | ✅ sub=? (0x40 bytes) |
| 86 | 0x56 | `FUN_00425620` | **Game chat/message** — valida mensaje ≤1000 chars vía `FUN_00405f30` | ❌ | ❌ |
| 87 | 0x57 | `FUN_004256d0` | **Game action (typed)** — valida type <0x14, count ≤1000. Vía `FUN_004060a0` | ❌ | ❌ |
| 89 | 0x59 | `FUN_004257b0` | **Game action (simple)** — valida type <0x14. Vía `FUN_004062c0` | ❌ | ❌ |
| 90 | 0x5A | `FUN_00425860` | **Forward game state to another player** — chequea target state (0x1440==0x03). Reenvía opcode 0x5a | ✅ opcode 0x5a al target | ❌ |
| 91 | 0x5B | `FUN_00425990` | **Surrender/forfeit** — chequea master flag (0x146c != 0x01). Vía `FUN_00409080` | ❌ | ❌ |
| 93 | 0x5D | `FUN_00425a70` | **Game result submit** — parsea datos de juego. Vía `FUN_0040a420` | ✅ error | ❌ |
| 94 | 0x5E | `FUN_00425bb0` | **Game result (simpler)** — vía `FUN_0040a420` con datos mínimos | ✅ error | ❌ |
| 96 | 0x60 | `FUN_00425cc0` | **Game vote** — chequea slot ownership (0x122/0x123). Vía `FUN_00405ef0` | ❌ | ❌ |
| 98 | 0x62 | `FUN_0041c2b0` | **Game action/event** — vía `FUN_00406930` | ❌ | ❌ |
| 110 | 0x6E | `FUN_00428c90` | **Game action/in-game request** — vía `FUN_0040e5f0` | ❌ | ❌ |
| 119 | 0x77 | `FUN_0041be60` | **Send full character data to client** — serializa 32 bytes desde field+0x04 a opcode 0x77. Sin state check | ✅ opcode 0x77 | ❌ |

### FINAL: Disconnect / Exit

| Opcode | Hex | Handler | Función | SEND | DB |
|--------|-----|---------|---------|------|----|
| 121 | 0x79 | `FUN_00422270` | **CWorld::NetworkMessageDisconnect** — envía notificación de desconexión (opcode 1) | ✅ opcode 1 | ❌ |

### Opcodes menores / misc
| Opcode | Hex | Handler | Función |
|--------|-----|---------|---------|
| 32 | 0x20 | `FUN_0041bc10` | — |
| 34 | 0x22 | `FUN_0041bca0` | — |
| 100 | 0x64 | `FUN_004283a0` | — |
| 101 | 0x65 | `FUN_00428430` | — |

### Opcodes sin handler (gaps)
Los siguientes opcodes NO tienen case en el switch (posiblemente deshabilitados o de otra build):
0x06, 0x07, 0x0D, 0x11, 0x1D, 0x1F, 0x21, 0x23-0x28, 0x2B, 0x30, 0x37, 0x3C, 0x44, 0x49, 0x4E, 0x51, 0x52, 0x54, 0x55, 0x58, 0x5C, 0x5F, 0x63, 0x64, 0x66-0x6A, 0x7A-0xFF

---

## DBWorker Dispatch (FUN_0041ae50, ~40 opcodes)

| DB Opcode | Handler | Función |
|-----------|---------|---------|
| 0x01 | `FUN_00410650` | **DBCommandAdminBan** — banea usuario por nombre |
| 0x02 | `FUN_004107d0` | **DBCommandLogin** (42 KB) — login: 8 queries, respuesta con chars + items + stage |
| 0x04 | `FUN_00412140` | LogUserConnect — update de disconnect |
| 0x05 | `FUN_004121e0` | LogUserConnect — update de RealIP |
| 0x07 | `FUN_00412280` | **DBCommandCharacterCreate** — crea personaje en DB |
| 0x08 | `FUN_00412530` | **DBCommandCharacterDelete** — borra personaje de DB |
| 0x0C | `FUN_004138b0` | Exp/CharacterInfo update |
| 0x0D | `FUN_00413980` | Buddy name query |
| 0x0E | `FUN_00413b00` | Tutorial update |
| 0x0F | `FUN_00413bd0` | LogDiePlayer — log de muerte en batalla |
| 0x10 | `FUN_00413cd0` | **DBCommandCharacterStateClear** — level up / power level |
| 0x29 | `FUN_0040f2f0` | **CDB::DBCommandBuyLotto / AskLotto / LottoResult** |
| 0x2A | `FUN_0040f2f0` | (misma que 0x29) |
| 0x2B | `FUN_0040f610` | **CDB::DBCommandAskClan** — lista de clanes/amigos |

### DB Inventory Handlers (opcode exacto pendiente)
| Handler | Nombre |
|---------|--------|
| `FUN_00414cc0` | **DBCommandInventoryEnter** |
| `FUN_00414e70` | **DBCommandInventoryBuyBag** |
| `FUN_00415590` | **DBCommandInventoryBuySlot** |
| `FUN_00415cb0` | **DBCommandInventoryBuyPowerUser** |
| `FUN_00417800` | **DBCommandInventoryBuyPotionSlot** |
| `FUN_004184a0` | **DBCommandInventoryBuyStageRankClear / StageLevelFree** |
| `FUN_00419a40` | **DBCommandInventoryBuy** |
| `FUN_0041a900` | **DBCommandInventorySell / DBCommandCharacterList** |
| `FUN_004144f0` | **DBCommandCharacterChangeCharName** |

---

## Nombres reales descubiertos vía strings

### CWorld methods
| Nombre | Dirección probable |
|--------|-------------------|
| `CWorld::NetworkMessageDisconnect` | `FUN_00422270` (opcode 0x79) |
| `CWorld::Idle` | `FUN_0042cee0` (68 KB, función más grande del binario) |
| `CWorld::GetRandomPresentIndex` | No mapeado |
| `CWorld::ProcessUserDisconnect` | No mapeado |
| `CWorld::DBCommandBuyLotto` | No mapeado (probablemente wrapper de CDB) |
| `CWorld::DBCommandAskLotto` | No mapeado |
| `CWorld::DBPS` | `FUN_00429030` (opcode 0x08) |
| `CWorld::DBCommandLogin1` | Probablemente un case del DB Response dispatch |
| `CWorld::DBCommandFieldCreateStage` | No mapeado |

### CDB / DBCommand methods
| Nombre | Handler |
|--------|---------|
| `CDB::DBCommandBuyLotto` | `FUN_0040f2f0` (también AskLotto + LottoResult) |
| `CDB::DBCommandAskLotto` | `FUN_0040f2f0` |
| `CDB::DBCommandLottoResult` | `FUN_0040f2f0` |
| `CDB::DBCommandAskClan` | `FUN_0040f610` |
| `CDB::DBCommandAdminBan` | `FUN_00410650` |

---

> **Referencias cruzadas:** Para más detalles de cada función, ver `01_functions_list.md`. Para flujo login, `login_flow.md`. Para Character Management, `character_management.md`. Para fase Lobby/Sala, `lobby_phase.md`. Para arquitectura general, `RAKION_RE_MASTER.md`.
