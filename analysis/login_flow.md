
# Flujo Completo: Login → Channel → Personajes → Lobby → Sala → Juego
## Reconstruido desde decompilación de RakionWorldServ.exe

> **Archivos relacionados:**
> - `03_packet_opcodes.md` — tabla completa de 86 opcodes de red con handlers
> - `01_functions_list.md` — lista de funciones con nombres reales anotados
> - `character_management.md` — análisis completo de Character Management (6 handlers, 4 DB ops, helpers)
> - `lobby_phase.md` — fase Lobby/Sala (14 opcodes: room list, shop, equip, buy, movement, whisper)
> - `RAKION_RE_MASTER.md` — documento maestro (arquitectura, estructuras, DB, sesiones)
> - `program_info.md` — info del binario PE + dispatch tables

## Pipeline General
```
Cliente → AES wire (bloques 0x7FC4) → WSARecv → IOCP callback → 
  PrtcDecryptAnswer (WorldServerDll.dll, AES decrypt) → recv_queue_push(FUN_0042e720) → 
  FUN_0042bd70 (main loop, Sleep(1) + polling) → 
   FUN_0042ab40 (game dispatcher, 86 opcodes — ver `03_packet_opcodes.md`) → handler → 
  FUN_004038e0 (SEND buffer) → PrtcEncryptQuery (WorldServerDll.dll, AES encrypt) → WSASend → wire
```

## Pipeline DB
```
handler → FUN_0041b940(push to DbSendQueue, SetEvent DBWorker) →
  DBWorker thread (FUN_0041b510) → 
  FUN_0041ae50 (DB dispatcher, 40 opcodes) → DB handler →
  FUN_0042e720(push to DbRecvQueue this+0x18) →
  FUN_0042bd70 (main loop, pop from DbRecvQueue) → 
  FUN_004295c0 (DB response dispatch, ~32 sub-opcodes) → handler →
  FUN_004038e0 (enviar respuesta al cliente)
```

## DB Dispatcher (FUN_0041ae50)
Entrada de cola (DbSendQueue): `[retOpcode:2][dbOpcode:2][payload:N]`
- `data[0:2]` = UVar2 = retOpcode (se usa como opcode de retorno)
- `data[2:2]` = UVar1 = dbOpcode (switch opcode del DB)
- `data[4:N]` = payload (param_3 + 2 en handlers)
- `param_1` = fieldId, `param_2` = dataLen

## DB Response Dispatch (FUN_004295c0)
Entrada de cola (DbRecvQueue): `[fieldId:2][size:2][retOpcode:2][subType:2][payload:N]`
- `param_1` = fieldId
- `param_2` = subType (ushort, switch opcode del DB response)
- `param_3` = dataLen - 2 (size del payload)
- `param_4` = payload + 2 (salta el subType)

### Sub-opcodes conocidos del DB response:
| Sub-opcode | Handler | Propósito |
|-----------|---------|-----------|
| 1 | FUN_004261d0 | Auth: busca field por loginId, disconnect duplicado, envía [3][result] |
| 2 | FUN_00426b30 | Login response: procesa resultado login, setup field, envía al cliente |
| 3 | FUN_00426290 | Character data: datos de personaje para selector (chunks si >4 chars) |
| 7 | FUN_0041c3d0 | **Character CREATE response**: DB opcode 7 result, carga char en slot field (0x360 bytes a 0), envía [0x12][result][charId] |
| 8 | FUN_00427570 | — |
| 0x0B | FUN_0041cb60 | — |
| 0x10 | FUN_00427760 | — |
| 0x11 | FUN_004278d0 | — |
| 0x12 | FUN_00427a80 | — |
| 0x13 | FUN_0041cca0 | — |
| +20 more | ... | |

## Login Flow Completo

**Nota importante:** Hay DOS caminos de login:
1. **Admin (0x04)** — `FUN_0041f1a0`: requiere field state 5 o subState 1/4
2. **Normal (0x0C post-switch)** — `FUN_0041f6c0`: para usuarios normales, pasa por el post-switch del dispatcher (`break` → bifurca según flag)

### Paso 1: Client → Server (admin: opcode 0x04, normal: opcode 0x0C post-switch)

#### Admin path (0x04) — FUN_0041f1a0:
- Valida field state (debe ser 5 o subState 1/4)
- Lee field+0x1488 (counter)
- Formato entrada: `[flag:1][username:null-term]`
- Pushea a DbSendQueue via FUN_0041b940:
  `[retOpcode=1:2][dbOpcode=2:2][counter:2][flag:1][username:null]`

#### Normal path (0x0C → FUN_0041f6c0):
- El dispatcher hace `break` en case 0x0C
- Post-switch chequea `this+0x5b18`:
  - `0` → game handler `FUN_0041f6c0` (procesa login normal)
  - `≠0` → DB handler `FUN_0042a310`
- Verifica `field+0x50` (loginId) y `field+0x1460` (estado)
- Lee sub-comando del primer byte de payload
- Procesa username/password
  
### Paso 2: DBWorker → DB opcode 2 → FUN_004107d0 (login response builder)
**Handler más grande del binario (~4000 líneas decompiladas)**

#### Parámetros de entrada:
- `param_4` (LPCSTR) = payload del DB command
- Formato: `[counter:2][flag:1][username\0][password\0][IP:4]`

#### Queries SQL:
1. **Auth query** (MySQL conn `this+0xC`):
   `SELECT password, country, NoCountry FROM <auth_table> WHERE id='<username>'`
   - Si flag!=0: validate password, get country
   - Result codes: 0=success, 2=user not found, 3=wrong password

2. **UserGameInfo query** (MySQL conn `this+0x8`):
   `SELECT id, bandate>now(), clanid, ..., ... FROM usergameinfo WHERE name='<username>'`
   
3. **Create user** if not found:
   `INSERT INTO UserGameInfo (name, ...) VALUES ('<username>', <counter&0xffff>)`

4. **Char list query:**
   `SELECT slot, id, name, auth, class, level, ..., ... FROM CharacterInfo WHERE userid=<userId> LIMIT 10`
   
5. **Item query:**
   `SELECT id, characterid, itemid, level, ... FROM UserItemInfo WHERE userid=<userId>`

6. **Cash query:**
   `SELECT cash FROM Cash WHERE id='<username>'`

7. **Stage info query:**
   `SELECT stage_id, rank FROM UserStageInfo WHERE characterid=<charId>`

8. **Pending gold:**
   `SELECT gold FROM loggoldpresents WHERE userid=<userId> AND processed=0`

#### Códigos de resultado (local_3309):
| Código | Significado |
|--------|-------------|
| 0 | Éxito — construye respuesta completa |
| 1 | Error DB |
| 2 | Usuario no encontrado en tabla auth |
| 3 | Contraseña incorrecta |
| 6 | Cuenta baneada |
| 0x1A (26) | Éxito (variante) |

#### Formato response push a DbRecvQueue (result=0):
```
[retOpcode:2][2:2][result:1][logId:4][timeVal:4][userId:4][clanId:4]
[clanName:str\0][clanRank:4][clanMembers:2][clanPoints:4]
[flags1:4][flags2:4][guildName:str\0][pendingItems:str\0]
[accountName:str\0][lastChar:str\0][authFlag:1][charCount:1]
  para cada char: [name:str\0][charName:str\0][level:4][exp:4][hp:4]
                   [face:1][class:1][str:1][dex:1][agi:1]
                   [equip items:10x2][inventory items:38x4(?)]
                   [stage data:0x1C×N]
  [totalSize=0x711+charData]
(se divide en chunks si >4 chars: s_w2=3 para chunks intermedios)
```

### Paso 3: Main Loop → FUN_004295c0 case 2 → FUN_00426b30 (login processor)
- Lee `param_3[0]` = result code
- Si success: extrae loginId (bytes 1-4), busca duplicados
- Envía UDP broadcast a otros servidores world
- Lee datos completos: clan, char list, equip
- Envía al cliente via FUN_004038e0

### Paso 4: DB Response case 3 → FUN_00426290 (char data processor)
- Procesa datos de personaje en chunks
- Almacena en field structure offsets
- Envía paquetes al cliente con datos de personajes

## Nombres Reales de Funciones (descubiertos vía strings)

A pesar de que el binario está completamente stripped, se descubrieron ~25 nombres reales mediante xrefs a strings de debug:

### CWorld
| Nombre | Función | Notas |
|--------|---------|-------|
| `CWorld::NetworkMessageDisconnect` | `FUN_00422270` | Game opcode 0x79 |
| `CWorld::DBPS` | `FUN_00429030` | Game opcode 0x08 |
| `CWorld::GetRandomPresentIndex` | ? | No mapeado aún |
| `CWorld::ProcessUserDisconnect` | ? | No mapeado aún |
| `CWorld::Idle` | `FUN_0042cee0`? | 68 KB — la función más grande |
| `CWorld::DBCommandBuyLotto` | ? | Probablemente wrapper CDB |
| `CWorld::DBCommandLogin1` | ? | Probablemente case del DB Resp |

### CDB (DBWorker handlers)
| Nombre | Función |
|--------|---------|
| `CDB::DBCommandBuyLotto` | `FUN_0040f2f0` (también AskLotto + LottoResult) |
| `CDB::DBCommandAskClan` | `FUN_0040f610` |
| `CDB::DBCommandAdminBan` | `FUN_00410650` |
| `CDB::DBCommandLogin` | `FUN_004107d0` |

### NetworkMessage handlers (game opcodes)
| Nombre | Opcode | Función |
|--------|--------|---------|
| `NetworkMessageFieldReady` | 0x61 | `FUN_0041c270` |
| `NetworkMessageFieldCreate` | 0x53 | `FUN_00425010` |
| `NetworkMessageFieldList` | 0x47 | `FUN_004244f0` |
| `NetworkMessageFieldExit` | 0x51 | `FUN_00424b60` |
| `NetworkMessageFieldChat` | 0x7F | No en dispatcher — posiblemente otro canal |
| `NetworkMessageFieldQuickEnter` | 0x4F | `FUN_00424a20` |

Ver `03_packet_opcodes.md` y `01_functions_list.md` para la lista completa.

## Formato Paquete de Autenticación al Cliente
Handler: FUN_00426b30 → FUN_004038e0
- Header: [opcode?][result:1]
- Según resultado, incluye datos de cuenta, clan, personajes

## DB Command Formats

### Character Create (DB opcode 7, FUN_00412280)
Input: `[userId:4][CharInfoId:4][name:str\0][class:1][slot:1]`
Proceso:
1. Verifica slot < 6
2. Verifica slot no ocupado: `SELECT slot FROM CharacterInfo WHERE name='<name>'`
3. Verifica < 6 chars existentes
4. Verifica nombre no existe: `SELECT id FROM CharacterInfo WHERE name='<name>'`
5. INSERT INTO CharacterInfo (name, userid, auth, class, ...)
6. UPDATE Usergameinfo SET charname = '<name>' WHERE id=<userId>
Output: `[retOpcode:2][7:2][result:1][charId:4][slot:1][class:1][name:str\0]`
- Result: 0=success, 1=DB err, 2=slot occupied, 3=too many chars, 4=name taken

### Character Delete (DB opcode 8, FUN_00412530)
Input: `[userId:4][charId:4][name:str\0]`
- Complex validation: level, deletion date, email verification
- DELETE FROM CharacterInfo, UserItemInfo, UserStageInfo WHERE charid=<charId>

### Admin Ban (DB opcode 1, FUN_00410650)
Input: `[banType:1][username:str\0]`
- SELECT userid FROM CharacterInfo WHERE name='<username>'
- UPDATE UserGameInfo SET BanDate=NOW() WHERE id=<userid>
Output: `[retOpcode:2][1:2][result:1][userId:4 if success]`

## Flujo de Personajes

### Character Create (game opcode 0x12 → DB opcode 7)
Game handler: `FUN_0041fcd0`
1. Valida field+0x1460 (loginId) non-zero, field+0x14a4 == 0
2. Lee campo de entrada: `[username\0][class:1][slot:1]` (class<5, slot<6)
3. Pushea a DbSendQueue: `[counter:2][7:2][loginId:4][username\0][class:1][slot:1]`
DB handler: `FUN_00412280` (ver arriba para formato detallado)
DB Response: → case ? (sin determinar, probablemente re-carga char list)

### Character Delete (game opcode 0x13 → DB opcode 8)
Game handler: `FUN_0041fe10`
1. Valida field+0x1460 non-zero, field+0x14a4 == 0
2. Lee campo de entrada: `[charId:4][name:max11\0]`
3. Pushea a DbSendQueue: `[counter:2][8:2][charId:4][name\0]`
DB handler: `FUN_00412530` (ver arriba para formato detallado)
DB Response: → case ? (sin determinar)

### Character Select (game opcode 0x14 → DB Response case 7)
Game handler: `FUN_0041fef0`
1. Valida field+0x1460 y field+0x14a4
2. `param_3[0]` = charId a seleccionar
3. Itera slot array en field (0xD8 entries × 0x360 bytes c/u = slots de personaje)
4. Si encuentra el charId:
   - `FUN_0040be30(field, name, ...)` — load char data from field
   - `FUN_0040d3f0(field, &result)` — access check
   - `FUN_0040ac30(field, charId, class, face, ...)` — set active char + notify
5. Pushea a DbSendQueue con datos del personaje seleccionado
DB Response case 7: `FUN_0041c3d0`
1. Lee `param_3[0]` = result; si 0: `param_3[1]`=slot, `param_3[2:5]`=charId, `param_3[6]`=class, `param_3[7+]`=name
2. Limpia slot del field (0xD8 * 4 = 0x360 bytes a 0)
3. Copia name, class, charId al slot field
4. Setea flag `[slot+0x356] = 1` (activo), `[slot+0xD2*4] = 0x1A`
5. Envía al cliente: `[opcode=0x12:2][result:1][charId:4]` via FUN_004038e0

### Character State Clear / Level Up (DB opcode 0x10)
Handler: `FUN_00413cd0`
Input: `[userId:4][cmdType:1][cmd-specific data]`
- Si cmdType=0x01: también lee `[couponItemId:4][couponId:4][charId:4][?]`
Queries:
1. `SELECT level, powerlevelpoint, ..., ..., ... FROM usergameinfo WHERE id=<userId>` (14+ campos)
2. Si level>0: `SELECT cash FROM Cash WHERE id='<username>'`
3. Verifica cash suficiente para power level up
4. UPDATE characterinfo SET levelpoint = ...
5. UPDATE usergameinfo SET powerlevelpoint = ...
6. UPDATE Cash SET cash = cash - <cost>
7. Si cmdType!=0: DELETE FROM useriteminfo WHERE id=<couponItem>, INSERT INTO logcoupon
Output: `[retOpcode:2][0x10:2][result:1][data...]`

## DB Command Formats Adicionales

### Tutorial Update (DB opcode 0x0E, FUN_00413b00)
Input: `[userId:4]`
- UPDATE UserGameInfo SET tutorial = ... WHERE id=<userId>
Output: `[retOpcode:2][0x0E:2]`

### LogDiePlayer (DB opcode 0x0F, FUN_00413bd0)
Input: `[killerId:4][killerName\0][deadId:4][deadName\0][fieldMode:1][deadCause:1]`
- INSERT INTO LogDiePlayer (killerid, killername, deadid, deadname, fieldmode, deadcause)

### Item Info Display (game opcode 0x09, FUN_0041f5c0)
Input: `[itemIndex:2]`
- Usa item array en CWorld+0xE4 (items de 0x3C0 bytes c/u)
- Verifica index < DAT_00455824
- Retorna info del item al cliente

---

## Flujo Post-Login: Channel → Character Select → Lobby → Sala → Juego

### Estados del field (offset field+0x1440)
| Valor | Estado | Descripción |
|-------|--------|-------------|
| 0x00 | Init | Vacío |
| 0x01 | Conectando | Handshake inicial |
| 0x02 | **LOBBY** | Personaje seleccionado, en el hub del juego |
| 0x03 | **ROOM** | Dentro de una sala de juego (pre-battle) |
| 0x04 | Admin | Admin autenticado |
| 0x05 | SuperAdmin | Superadmin |

### Fase 1: Channel Entry (0x05)
```
Cliente → opcode 0x05 (FUN_0041f290)
  → Lee channel name (≤12 chars, null-terminated) + password opcional (≤128 chars)
  → Si name vacío: broadcast a todos los fields
  → Si name dado: busca match via FUN_0040c870
  → Envía opcode 0x63 (99) al field del canal encontrado
  → DB Response case 2/3: carga datos de personajes
```

### Fase 2: Character Management (0x12-0x1A) y Transición a Lobby

**Archivo detallado:** `character_management.md` — contiene análisis completo de TODAS las funciones, formatos de paquete, DB queries, y códigos de error.

#### Opcodes de Character Management:
| Opcode | Hex | Handler | DB Opcode | Payload del Cliente | Payload del Servidor |
|--------|-----|---------|-----------|-------|--------|
| 18 | 0x12 | FUN_0041fcd0 | 7 (CREATE) | `[name\0][class:1][slot:1]` | `[result:1][charId:4][slot:1][class:1][0x07:1]` = 8 bytes |
| 19 | 0x13 | FUN_0041fe10 | 8 (DELETE) | `[charId:4][name:max11\0]` | `[result:1][charId:4]` = 5 bytes |
| 20 | 0x14 | FUN_0041fef0 | — (in-memory) | `[charId:4]` | **`[result:1]`** = SOLO 1 BYTE! |
| 21 | 0x15 | FUN_00420120 | 0x0B | `[name:13\0]` | 27 bytes (name echo × 2) |
| 25 | 0x19 | FUN_00420760 | 0x0D | `[newName:13\0]` | DB response |
| 26 | 0x1A | FUN_00420840 | 0x0E | (empty) | DB response |

#### Character Create (0x12):
```
Network: FUN_0041fcd0
1. Valida field+0x1460 (loginId) non-zero AND field+0x14a4 == 0 (ningún char seleccionado)
   Si inválido: error 0x19 (disconnect)
2. Lee payload: lstrlenA(param_3) < 13
   - Si falla: error 0x1A (name too long)
3. Lee class en param_3[nameLen+1] — must be < 5
   - Si falla: error 0x1B (invalid class)
4. Lee slot en param_3[nameLen+2] — must be < 6
   - Si falla: error 0xEA (invalid slot)
5. Copia name a buffer local
6. DB push via FUN_0041b940: [counter:2][7:2][loginId:4][name\0][class:1][slot:1]

DB Handler: FUN_00412280
- Validation:
  - slot >= 6 → result=1
  - `SELECT slot FROM CharacterInfo WHERE id=<loginId>` — same slot? → result=2
  - row count > 5? → result=3
  - `SELECT id FROM CharacterInfo WHERE name='<name>'` — exists? → result=4
- INSERT INTO CharacterInfo (name,userid,class,slot,createtime,changetime) VALUES (...)
- UPDATE UserGameInfo SET charname='<name>' WHERE id=<loginId>
- Result codes: 0=success, 1=DB error, 2=slot occupied, 3=too many chars, 4=name taken

DB Response case 7: FUN_0041c3d0
- If result==0: clears 0x360 bytes, writes [charId:4][name:str][class:1], sets active flag
- Sends to client: [opcode=0x12:2][result:1][charId:4]
```

#### Character Delete (0x13):
```
Network: FUN_0041fe10
1. Valida field+0x1460 non-zero AND field+0x14a4 == 0
   Si inválido: error 0x1C (disconnect)
2. Lee payload: [charId:4][name:max11\0]
3. DB push: [counter:2][8:2][charId:4][name\0]

DB Handler: FUN_00412530 (~500 líneas decompiladas)
- Queries character info from CharacterInfo
- Complex validation based on level:
  - Level < 15: simple DELETE FROM CharacterInfo, UserItemInfo, UserStageInfo
  - Level >= 15: soft delete (auth=10, used=0) + email verification
- Result codes: 0=success, 1=DB err, 2=not found, 3=used/restricted, 4=userid mismatch, 5=delete key mismatch, 6=email not found, 7=email sent, 9=name mismatch
```

#### Character Select (0x14) — ENTRADA CRÍTICA AL LOBBY:
```
Network: FUN_0041fef0
1. Valida field+0x1460 non-zero AND field+0x14a4 == 0
   Si inválido: error 0x1D (disconnect)
2. Lee param_3[0] = charId
3. Itera 6 slots (0xD8 * 4 = 0x360 stride each) en field+0x14a4 area
4. Cuando encuentra el slot:
   a. FUN_0040be30(field, name, items, skills, equip, inventory, entries)
      → Copia name→field+0x14a8, 19 items→field+0x157c, equip→field+0x17e4, etc.
   b. FUN_0040d3f0(field, &class, &potionSlot) — valida potion slot contra server item table
   c. FUN_0040ac30(field, charId, masterFlag, class, variant, ...) — SET ACTIVE CHAR
      → field+0x146c = masterFlag, field+0x14a4 = charId
      → field+0x1530 = class, field+0x1531 = variant, field+0x1540 = level
      → Writes 11 stat ushorts, copies 0x17F dwords from +0x157c to +0x1b78
      → Copies name to lowercase at field+0x14b5
   d. field+0x2368 = slotClass (track active class)
5. Sends: [opcode=0x14:2][result:1] — SOLO 1 BYTE DE PAYLOAD! (no 3 bytes)
6. FUN_0041b8b0(this, fieldId) — busqueda de canal para entrar:

a. Itera CChannel array (0x358 bytes/cada, this+0xdc, count this+0xd8)
b. Para cada canal: FUN_00404fc0(channel, null, fieldId, 1, &param_1)
   - Valida channel abierto (byte+1 != 0)
   - Valida capacidad (count < max)
   - Valida password si existe
   - Busca slot libre (100 slots × 8 bytes en channel+0x38)
   - Asigna: slot.fieldId = fieldId, slot.active = 1
   - Builds packet 0x1F (ChannelEnter): [0x1F:2][result:1][channelSlot:1][fieldId:2]
     Después, via FUN_0040afb0 añade: [playerName\0][class:1][masterFlag:1][flags:4]
   - Builds packet 0x1E (ChannelCharacterState): [0x1E:2][channelName\0]
     + lista de TODOS los players conectados al canal
   - FUN_0040b670(field): reset interacción (field+0x148e..0x1499 a 0, +0x149c a -1)

c. FUN_0040af60(field, channelIndex, fieldId):
   → field+0x148c = channelIndex
   → field+0x148d = fieldId (status)
   → **field+0x1440 = 0x02** — TRANSICIÓN OFICIAL A LOBBY!
   → Log: "RW......CUser::SetChannelInfo..."

Resultado final: cliente recibe:
1. [0x00] (1 byte) — confirmación de selección de personaje
2. Paquete 0x1F (ChannelEnter) — entrada al canal
3. Paquete 0x1E (ChannelCharacterState) — lista de jugadores en canal
```

#### Character Name Registration (0x15):
```
Network: FUN_00420120
1. Valida field+0x1460 non-zero
2. Lee name de payload (max 12 chars)
3. DB push: [counter:2][0x0B:2][name\0]
```

#### Character Name Change (0x19):
```
Network: FUN_00420760
1. Valida field+0x1460 non-zero
2. Lee newName de payload (max 12 chars)
3. DB push: [counter:2][0x0D:2][newName\0]

DB Handler: FUN_004144f0 (DB opcode 0x11)
- Validates name not already taken
- Gets old character info + cash
- Validates cost (2000 cash base, discount if coupon used)
- UPDATE CharacterInfo SET name='<newName>' WHERE id=<charId>
- UPDATE Cash SET cash=cash-cost WHERE id='<username>'
- Handles coupon items (DELETE + INSERT INTO logcoupon)
- Handles free present items on name change
- Result codes: 0=success, 1=name exists, 2=insufficient cash
```

#### Tutorial Complete (0x1A):
```
Network: FUN_00420840
1. Lee field+0x1488 (session counter)
2. DB push: [counter:2][0x0E:2][sessionId:4] — solo 8 bytes total
3. NO envía respuesta al cliente — solo actualiza DB

DB Handler: FUN_00413b00 (DB opcode 0x0E)
- UPDATE UserGameInfo SET tutorial=1 WHERE id=<userId>
- Output: [retOpcode:2][0x0E:2] — 4 bytes, no payload

Nota: El cliente envía opcode 0x1A después de completar el tutorial.
En el original, esto se enviaba como sub-opcode 0x0E al DB.
```

### Fase 3: Lobby (state 0x02)

En el lobby el jugador puede moverse, equipar items, crear salas, comprar, etc.

```
MOVEMENT (0x31):
  → FUN_00421870: Lee coordenadas (x,y,z,w), reenvía a otros players en lobby

WHISPER (0x16):
  → Lee [targetName\0][message\0], busca target, reenvía mensaje

SHOP (0x2F):
  → Lee [category:1], carga items de shop via FUN_0040cd70
  → Pushea DB sub=0x15 para confirmar

BUY (0x1C / 0x74):
  → Lee [itemName\0][type:1][index?], procesa compra via FUN_0040c310
  → Pushea DB con datos de inventario

EQUIP (0x73):
  → Lee índices de item/equip slot, serializa equip+inventory+stats a DB

LOTTO (0x75):
  → Lee tipo de money (gold/cash), chequea colisiones, compra ticket

ROOM LIST (0x36):
  → Escanea slots de canal (0x3c0 entries), aplica filtros (class, race, level)
  → Devuelve lista de salas disponibles

CREATE ROOM (0x2E / 0x3B):
  → Lee [roomIdx:1][type:1] / [name\0][pw\0][mapId:1][mode:1][lvlRange...]
  → Inicializa sala, pushea DB
```

### Fase 4: Room (state 0x03)

Dentro de una sala, antes de empezar la batalla:

```
JOIN (0x29):
  → Lee [roomIndex:1], verifica sala activa, procesa via FUN_00406240

INVITE (0x2A):
  → Lee [targetSlot:1], envía invite de 8 bytes al target

LEAVE (0x3E): Sale de la sala via FUN_004075a0
KICK (0x3F): Host kickea player via FUN_00405740

READY/UNREADY (0x42/0x43):
  → Toggle ready state del jugador en la sala

CHANGE SLOT (0x40):
  → Cambia de equipo/posición en la sala

CHANGE MAP/MODE (0x41):
  → Host cambia mapa o modo de juego

EQUIP IN ROOM (0x4B):
  → Cambia equipamiento (item count ≤200) via FUN_00405c00

START GAME (0x46):
  → Host inicia la partida
  → Pushea DB con equip data
  → Envía opcode 0x58 al cliente (game start)
```

### Fase 5: In-Game

Durante la batalla:

```
CHAT (0x56): Mensaje ≤1000 chars via FUN_00405f30
ACTION (0x57): Acción con tipo <0x14 + count ≤1000 via FUN_004060a0
ACTION SIMPLE (0x59): Acción simple con tipo <0x14
FORWARD STATE (0x5A): Reenvía estado de juego a otro player
SURRENDER (0x5B): Rendición (solo no-host)
RESULT (0x5D/0x5E): Submit de resultado de partida via FUN_0040a420
VOTE (0x60): Votación en juego

FIELD EXIT (0x50):
  → FUN_00424b60: Salida del field con contabilidad
  → Lee [gold:4][points:4][actionFlag:4][...]
  → Valida gold/points via FUN_0041cf80
  → Procesa items via FUN_0040b940
  → Pushea DB con estado completo (0x40 bytes)
  → Envía [opcode=0x51:2][data...]

DISCONNECT (0x79):
  → CWorld::NetworkMessageDisconnect via FUN_00422270
  → Envía notificación de desconexión
```

---

> **Ver también:** `03_packet_opcodes.md` para la tabla detallada de los 86 opcodes con descripciones completas, `01_functions_list.md` para la leyenda de funciones, `character_management.md` para el análisis completo de Character Management, `lobby_phase.md` para la fase Lobby/Sala, `program_info.md` para info del binario, y `RAKION_RE_MASTER.md` para la arquitectura general del servidor.
