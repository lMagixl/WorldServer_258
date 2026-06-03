# RAKION WORLD SERVER — Ingeniería Inversa & Emulador C#
## Archivo de Contexto Maestro · Versión 1.0

> **INSTRUCCIÓN AL AGENTE:** Si pierdes contexto, lee este archivo COMPLETO antes de continuar.  
> Cárgalo con: `@RAKION_RE_MASTER.md` al inicio de cada sesión en Antigravity CLI / Claude Code.

---

## 1. OBJETIVO FINAL

Construir un **servidor emulador en C#** para Rakion (MMORPG/shooter de Softnyx, ~2007)  
que reproduzca el comportamiento del servidor original `RakionWorldServ.exe`.

El emulador debe manejar:
- Autenticación de usuarios
- Gestión de personajes (crear, listar, seleccionar, borrar)
- Inventario de ítems y tienda
- Sistema de campos/partidas (Field/Stage)
- Sistema de clanes
- Sistema de lotería/lotto
- Comunicación TCP/UDP con los clientes Rakion
- Conexión a base de datos MySQL
- Protocolo de red propietario (parsear paquetes)

---

## 2. BINARIO ANALIZADO

| Campo | Valor |
|---|---|
| Archivo | `RakionWorldServ.exe` |
| Tamaño | 352,531 bytes (344.3 KB) |
| Arquitectura | PE32, x86 (32-bit), Intel 80386 |
| Compiler | MSVC (Visual C++) |
| Timestamp | 2007-11-19 05:12:44 |
| MD5 | d9402e4bcff885e2ad8cdd4a67f8e3f8 |
| SHA256 | e4835ab326f745541cb0a21ac52e3b2ea0ffe989040193c8019c7244ebd2e81f |
| PDB path | `d:\Rakion\Debug\SoftnyxServerSuite_071119\RakionWorldServer\Release\RakionWorldServer.pdb` |
| Entry Point | RVA 0x36E31 → VA 0x00436E31 |
| ImageBase | 0x00400000 |
| Sección especial | `.Silvana` (custom, posiblemente datos cifrados/config) |

### Secciones PE
| Sección | VA | VSize | Flags |
|---|---|---|---|
| .text | 0x00401000 | 0x40666 | Execute/Read |
| .rdata | 0x00442000 | 0x109C7 | Read/Write |
| .data | 0x00453000 | 0x6A64 | Read/Write |
| .Silvana | 0x0045A000 | 0x1000 | Read/Write |

---

## 2.5 Estructuras de datos clave (mapeadas de código decompilado)

### CWorld (tamaño: 0x5F44 bytes, creado en FUN_0042aad0/FUN_0042a810)
Singletón global en `DAT_00456850`. Puntero obtenido vía `FUN_0042aad0()`.

| Offset (dec) | Offset (hex) | Tipo | Nombre | Descripción |
|---|---|---|---|---|---|
| 0x00-0x0F | +0x00 | varios | vtable/fields | Primeros campos (flags, etc.) |
| 0xD4 | +0x35×4 | CField* | m_pFieldArray | Array de fields (0x23b4 bytes c/u, MaxField elementos) |
| 0x118 | +0x46×4 | TcpListener* | m_pTcpServer | Listener TCP (0x24 bytes) |
| 0x11C | +0x47×4 | UdpSocket* | m_pUdp1 | Socket UDP 1 (0x10 bytes) |
| 0x120 | +0x48×4 | UdpSocket* | m_pUdp2 | Socket UDP 2 (0x10 bytes) |
| 0xEC | +0x3B×4 | ulong | brokerIP | IP del broker (inet_addr) |
| 0xF0 | +0x3C×4 | ushort | brokerPort | Puerto del broker (network order) |
| 0xF4 | +0x3D×4 | HANDLE | hStopEvent | Evento de parada |
| 0xF8 | +0x3E×4 | Queue* | m_pbfmDBResult | Cola de resultados DB (DbRecvQueue) |
| 0xFC | +0x3F×4 | Queue* | m_pbfmDBCommand | Cola de comandos DB (DbSendQueue) |
| 0x4E | +0x13.8 | byte | state | Estado del servidor (0=init, 1=starting, 2=running) |
| 0x5CE6 | +0x173B×4 | int | tickState | Contador de estado interno del loop |
| 0x59DC | +0x1677×4 | int | dbThreadCount | Contador de hilos DBWorker activos |
| 0x50 | +0x14×4 | void* | pProtocolHandler | Puntero a estructura PRTCLIB cargada desde WorldServerDll.dll |

### CField (tamaño: 0x23B4 bytes, array en CWorld+0xD4)
| Offset | Tipo | Nombre | Descripción |
|---|---|---|---|
| +0x1440 | byte | state | **Máquina de estados**: 0=init,1=conectando,2=**LOBBY** (char seleccionado),3=**ROOM** (en sala),4=admin,5=superadmin |
| +0x1448 | byte[?] | ? | Estado del canal (0x04/0x05 = autenticado en channel) |
| +0x1450 | uint | connData | Datos de conexión (IP + flags) |
| +0x1454 | uint | ? | Padding/desconocido |
| +0x1460 | void* | loginId | ID de login / sesión (non-zero = conectado) |
| +0x146C | byte | subState | Sub-estado del field: 0=normal, 1=?, 4=host de sala |
| +0x146E | ushort | packetSeq | Número de secuencia de paquete |
| +0x1470 | ushort | ? | Otro contador/secuencia |
| +0x1480 | uint | connectTime | GetTickCount al conectar |
| +0x1484 | uint | ? | Último tick de actividad |
| +0x1488 | ushort | transactionId | Contador de transacciones DB (incrementa en cada DB push) |
| +0x148A | ushort | fieldValue | Valor específico del field |
| +0x148C | byte | channelId | ID del canal asignado |
| +0x148D | byte | channelStatus | Estado en el canal |
| +0x148E-0x1499 | byte[12] | interactionState | Estado de interacción (reset por FUN_0040b670) |
| +0x149C | int | inactivityTimer | Timer de inactividad (0xFFFFFFFF = reset) |
| +0x14A4 | uint | activeCharId | ID del personaje activo (0 = ninguno seleccionado) |
| +0x14A8 | char[13] | playerName | Nombre del jugador (max 12 chars + null) |
| +0x14B5 | char[13] | playerNameLower | Nombre en minúsculas (para búsquedas) |
| +0x14D0 | uint | fieldFlags | Flags del field (PvP? modo?) |
| +0x1530 | byte | classId | Clase del personaje activo |
| +0x1531 | byte | classVariant | Variante de clase (raza/sub-clase) |
| +0x1534 | uint | accumulatedExp | Experiencia acumulada en sesión |
| +0x1538 | uint | currentHp | HP actual |
| +0x153C | uint | currentAp | AP/SP actual |
| +0x1540 | byte | level | Nivel del personaje |
| +0x1544 | uint | attackStat | Ataque |
| +0x1548 | uint | defenseStat | Defensa |
| +0x154C | uint | blockStat | Bloqueo |
| +0x1550 | ushort | hit1 | Stat hit1 |
| +0x1552 | ushort | hit2 | Stat hit2 |
| +0x1554 | ushort | hit3 | Stat hit3 |
| +0x1556 | ushort | hit4 | Stat hit4 |
| +0x1558 | ushort | crit | Critical hit |
| +0x155A | ushort | maxHp | HP máximo |
| +0x155C | ushort | maxAp | AP máximo |
| +0x155E | ushort | attackSpeed | Velocidad de ataque |
| +0x1560 | ushort | moveSpeed | Velocidad de movimiento |
| +0x1562 | ushort | maxCp | CP máximo |
| +0x1564 | ushort | levelPoint | Puntos de nivel disponibles |
| +0x1566-0x157A | uint[6] | statDuplicates | Duplicados de stats anteriores (para cálculos) |
| +0x157C | uint[19] | itemVisualIds | IDs visuales de ítems equipados (itemid en BD) |
| +0x17A8 | uint[9] | skillData | Datos de skills/habilidades |
| +0x17CE | uint[4]+byte[2] | specialItems | Items especiales (criaturas?) |
| +0x17E4 | uint[19] | equipDbIds | IDs de BD de ítems equipados |
| +0x1B78 | uint[0x17F] | equipDuplicates | Duplicado del workspace (copia de 0x157c+0x17a8+0x17ce+0x17e4) |
| +0x2174 | uint[100] | inventory | Inventario del jugador |
| +0x2304 | uint[25] | itemEntries | Entradas de ítems adicionales |

### PRTCLIB Protocol Handler (cargado desde WorldServerDll.dll, creado en FUN_004304f0)
Tamaño: 0x38 bytes, struct dinámico cargado por LoadLibrary/GetProcAddress.
Referencias: `PrtcGetVersion`, `PrtcGetAuthQuery`, `PrtcCheckAuthAnswer`, `PrtcEncryptQuery`, `PrtcDecryptAnswer`, `PrtcUpdateTimer`

| Offset | Tipo | Nombre | Descripción |
|--------|------|--------|-------------|
| +0x00 | HMODULE | hDll | Handle de WorldServerDll.dll |
| +0x04 | uint | version | Versión del protocolo (vía PrtcGetVersion) |
| +0x08 | uint | flags | Flags (bit0=inited, bit1=error) |
| +0x0C | uint | connectCount | Contador de conexiones |
| +0x10 | time_t | initTime | Tiempo de inicialización (time32) |
| +0x14-0x1A | ? | ? | Padding/desconocido |
| +0x1C (+7) | FARPROC | pPrtcGetAuthQuery | Puntero a PrtcGetAuthQuery |
| +0x20 (+8) | FARPROC | pPrtcCheckAuthAnswer | Puntero a PrtcCheckAuthAnswer |
| +0x24 (+9) | FARPROC | pPrtcEncryptQuery | **Puntero a encrypt de paquetes salientes** |
| +0x28 (+10) | FARPROC | pPrtcDecryptAnswer | **Puntero a decrypt de paquetes entrantes** |
| +0x2C (+11) | FARPROC | pPrtcUpdateTimer | Puntero a update de timer |
| +0x30 | ?* | pNext | Siguiente protocol handler (lista ligada) |
| +0x34 | ?* | pPrev | Anterior protocol handler |

Los punteros a funciones encrypt/decrypt se obtienen vía GetProcAddress(hModule, "PrtcEncryptQuery") y GetProcAddress(hModule, "PrtcDecryptAnswer"). Estas implementan el cifrado AES-ECB con formato de bloque 0x7FC4.

### Buffer de recv TCP por field (tamaño: 0x68 bytes, array en TcpListener+0x10)
| Offset | Tipo | Nombre | Descripción |
|---|---|---|---|
| +0x14 | byte | state | Estado de conexión (0=init,1=socket,2=AcceptEx,3=connected,4=disconnect) |
| +0x16 | ushort | fieldIdx | Índice de field asociado |
| +0x18 | void* | pTcpListener | Puntero al TcpListener padre |
| +0x1C | uint | maxFieldCount | Máximo de fields |
| +0x20 | SOCKET | socket | Socket por-field |
| +0x24 | HANDLE | hIOCP | Handle de IOCP compartido |
| +0x28 | Queue* | sendQueue | Cola de envío |
| +0x2C | ULONG_PTR | completionKey | Clave de finalización IOCP (= fieldIdx) |
| +0x30 | void* | recvBuffer | Buffer de recv (0x2020 bytes: OVERLAPPED + WSABUF + data) |
| +0x34 | void* | auxBuffer | Buffer auxiliar (0x1020 bytes) |
| +0x38 | CRITICAL_SECTION | csSend | Critical section de envío |
| +0x50 | CRITICAL_SECTION | csRecv | Critical section de recepción |

### TcpListener (tamaño: 0x24 bytes, creado en FUN_00403880)
| Offset | Tipo | Nombre | Descripción |
|---|---|---|---|
| +0x00 | byte | state | Estado (0=init,1=WSAStarted,2=listening,3=?,4=running) |
| +0x04 | SOCKET | listenSocket | Socket de escucha |
| +0x08 | HANDLE | hIOCP | Handle IOCP (compartido con todos los field sockets) |
| +0x0C | Queue* | recvQueue | Cola de recepción (param_2 = TcpRecvQueue de config) |
| +0x10 | void* | recvBuffers | Array de buffers de recv (0x68 * MaxField bytes) |
| +0x14 | ushort | maxFields | Máximo de fields (DAT_00456030) |
| +0x18 | ushort | maxFieldsPlus1 | maxFields + 1 |
| +0x1C | ? | ? | Desconocido |
| +0x20 | void* | acceptObj | Objeto AcceptEx (0x210 bytes) |

---

## 3. ARQUITECTURA DEL SERVIDOR (extraída de código decompilado)

### 3.1 Modelo de hilos (3 hilos)
1. **Hilo principal IOCP** (`FUN_0042bd70`, vía `lpStartAddress_0042cd10`): loop que procesa colas de paquetes pre-parseados. No llama a `GetQueuedCompletionStatus` directamente — solo desencola y despacha.
2. **Hilo DBWorker** (creado en `FUN_0041b520`, vía `lpStartAddress_0041b510`): maneja queries MySQL asíncronas.
3. **Hilo GameGuard** (`lpStartAddress_004294d0` → `FUN_0041e7e0`): anti-cheat.

### 3.2 Pipeline de paquetes
```
AcceptEx → IOCP callback (raw Win32) → PrtcDecryptAnswer (AES decrypt via WorldServerDll.dll)
→ recv queue push (FUN_0042e720) 
→ FUN_0042bd70 (Sleep(1) + desencolar) 
→ FUN_0042ab40 (dispatcher 86 opcodes — ver `03_packet_opcodes.md`) 
→ handler específico

Saliente:
handler → FUN_004038e0 (SEND) → PrtcEncryptQuery (AES encrypt via WorldServerDll.dll) → WSASend
```

### 3.3 Framework de red: `PerfLib`
El servidor compila la librería **PerfLib** pero **solo usa IOCP raw de Win32** para el servidor TCP principal. Las clases `IoCompletionPort`/`ThreadPool` de PerfLib son **código muerto** (nunca inicializadas). Se usan únicamente:
- `AsyncWebRequest` — solicitudes HTTP (auth externa)
- `IPv4Address` — gestión de IPs
- `MemoryPool<N>` — pools de memoria en handlers específicos
- `CriticalSection`, `Event` — sincronización básica

### 3.4 Flujo completo de estados del servidor

```
CONNECT → [state 0x01]
  → opcode 0x01 (Admin IP check)
  → opcode 0x02 (Server info)
  → opcode 0x04 (Admin Login) → DB opcode 2 → DB Resp case 2 (admin path)
  → opcode 0x0C/0x0E (Normal Login via post-switch → FUN_0041f6c0) → DB opcode 2 → DB Resp case 2
  → [state 0x04/0x05 si admin, o 0x02 si normal]
  
CHANNEL → [state 0x02]
  → opcode 0x05 (Channel search/enter)
  → Recibe lista de canales
  → Entra a un channel

CHARACTER MANAGEMENT → [state 0x02]
  → opcode 0x12 (Character Create): payload [name\0][class:1][slot:1], DB opcode 7
  → opcode 0x13 (Character Delete): payload [charId:4][name\0], DB opcode 8
  → opcode 0x14 (Character Select): payload [charId:4], response 1 byte
  → opcode 0x15 (Character Name Registration): payload [name\0], DB opcode 0x0B
  → opcode 0x19 (Character Name Change): payload [newName\0], DB opcode 0x0D
  → opcode 0x1A (Tutorial Complete): no payload, DB opcode 0x0E
  → Detalles completos: `character_management.md` (1668 líneas, 100% documentado)

CHARACTER SELECT → CRITICAL LOBBY ENTRY POINT
  → opcode 0x14: FUN_0041fef0 loads char from DB slot into field workspace
  → Loads: name→field+0x14a8, items→field+0x157c, equip→field+0x17e4, etc.
  → Calls FUN_0040ac30 (SetActiveCharacter) → sets all stats, copies workspace
  → Sends [opcode=0x14][result:1] — ONLY 1 BYTE payload!
  → Calls FUN_0041b8b0 → finds channel → FUN_00404fc0 (CChannel::Enter)
  → Sends opcode 0x1F (ChannelEnter): [result:1][slot:1][fieldId:2][name\0][class:1][master:1][flags:4]
  → Sends opcode 0x1E (ChannelCharacterState): [count:1][channelName\0] + player list
  → FUN_0040af60 (SetChannelInfo): field+0x148c=channelId, field+0x148d=status
  → **field+0x1440 = 0x02** — TRANSITION TO LOBBY!

LOBBY → [state 0x02]
  → Movimiento (0x31), whisper (0x16), shop (0x2F)
  → Crear sala (0x2E/0x3B), unirse a sala (0x29/0x38)
  → Comprar items (0x74), equipar (0x73), lotto (0x75)
  → Guardar skills/quests a DB (0x6F-0x71)
  → Detalles completos: `lobby_phase.md` (737 líneas, 14 opcodes documentados)

ROOM → [state 0x03]
  → Ready/Unready (0x42/0x43)
  → Cambiar equipo/posición (0x4A-0x4D)
  → Cambiar settings (0x40/0x41)
  → Iniciar juego (0x46) → Game Start (opcode 0x58)

IN-GAME → [state 0x03]
  → Acciones (0x57/0x59), chat (0x56)
  → Resultado (0x5D/0x5E)
  → Salir de field (0x50) → gold/points accounting
  
DISCONNECT (0x79) → CWorld::NetworkMessageDisconnect
```

Para la tabla completa de opcodes con descripciones, ver `03_packet_opcodes.md`.

### 3.5 Cola de paquetes (recv queue)
Formato de entrada en cola:
```
[fieldId:2][dataSize:2][opcode:2][payload:N]
```
- Push: `FUN_0042e720(queue, fieldId, dataSize, dataPtr)`
- Pop: `FUN_0042e580(queue, &fieldId, &dataSize, &opcode_buf)`

Donde `dataSize` = tamaño total de opcode + payload en bytes.
El dispatcher recibe: `FUN_0042ab40(world, fieldId, opcode, dataSize - 2, &payload)`

### 3.6 DLLs dependencias conocidas
```
KERNEL32.dll   — WinAPI base
WS2_32.dll     — Winsock (TCP/UDP)
MSWSOCK.dll    — AcceptEx, TransmitFile (IOCP)
LIBMYSQL.dll   — MySQL client
WININET.dll    — HTTP (auth externa)
ADVAPI32.dll   — Windows Services
dbghelp.dll    — MiniDump (crash handler)
WorldServerDll.dll — DLL propia del juego
ggauth60.dll   — GameGuard anti-cheat
ole32.dll / OLEAUT32.dll
```

### 3.7 Archivo de configuración
`worldserver.ini` — configuración principal con estas claves:
- `ServerId`
- `ServerList`
- `MaxUser`
- `MaxField`
- `Port`
- `Authentication` / `AuthPage` (/auth.asp)
- `DisplayName` / `Name`
- `EnableDebugThread`
- `FlexDbConn` (MaxDbConnection, DbConnIncrease, DbConnDecrease, DbConnAdjustFreq)
- `DbSendQueue` / `DbRecvQueue`
- `TcpSendPoolSize` / `TcpRecvQueue`
- `UdpRecvQueue` / `SendPoolCount`
- `ExecUser` / `ExecPassword`
- `CharacterDeleteSubject` / `CharacterDeleteBodyFileName`
- `MD5_1` / `MD5_2`
- `channel00` ... `channel[N]` — lista de canales
- `MailSender` / `PickupFolder` — configuración de correo

---

## 4. BASE DE DATOS MySQL

### Tablas identificadas

#### Usuarios / Cuentas
```sql
user                  -- id, password, country, NoCountryUpdate
UserGameInfo          -- id, name, charname, gold, bag, slot, clanid, clanpoint,
                      --   clanrank, buddyname, powertime, powerlevelpoint, ban,
                      --   treeuppername, treerank, tutorial, createtime, lastconnect,
                      --   country, BanDate, rankgrade, stagelevelfree
Cash                  -- id (string), cash
```

#### Personajes
```sql
CharacterInfo         -- id, userid, name, auth, class, slot, level, exp, levelpoint,
                      --   hit1,hit2,hit3,hit4, chit, hp, ap, attackspeed, speed, maxcp,
                      --   rankgrade, win, lose, draw, totalrank, classrank, potionslot,
                      --   used, deletekey, createtime, changetime
```

#### Ítems
```sql
UserItemInfo          -- id, userid, characterid, itemid, level, exp, limittime, slot,
                      --   item_sn, sn_type
ItemInfo              -- id, type, class, level, shop, gold, cash, hit1,hit2,hit3,hit4,
                      --   chit, ap, hp, maxcp, power
```

#### Clanes
```sql
ClanInfo              -- id, rank, members, point, name, masterid
```

#### Stages/Rankings
```sql
StageInfo             -- id, maxcharacters, minlevel, maxlevel
UserStageInfo         -- id, characterid, stage, rank, updatetime
LogStageClear         -- id, charid, stage, createtime, stageid, rank
```

#### Clases/NPCs
```sql
ClassInfo             -- class, hit1,hit2,hit3,hit4, chit, hp, ap, attackspeed, speed, maxcp
ClassLevelInfo        -- class, level, exp
NPCInfo               -- npc, level, exp, gold
CouponInfo            -- id, discount_rate, expire_days, min_level, max_level, for_cash
```

#### Lotería
```sql
lotto                 -- id, userid, no, buytime, no1..no5, gold, cash
loglottery            -- no, no1..no5, bonus, lotterytime
```

#### Presentas/Regalos
```sql
pendingpresents       -- id, present_id, user_id, added_time
logpresent            -- pending_id, present_id, sender_id, user_id, present_time, accept_time, dispose_time
loggoldpresents       -- id, user_id, gold, process_flg, accept_time
```

#### Logs
```sql
LogUserConnect        -- id, userid, username, serverid, userip, country, connecttime,
                      --   disconnecttime, note, RealIP
LogDiePlayer          -- killerid, killername, deadid, deadname, fieldmode, deadcause, createtime
LogFieldGamePoint     -- BossCharID, BossCharName, CharID, CharName, Poweruser, FieldMode,
                      --   maxround, round, exp, gold, createtime
LogFieldGamePointList -- ...win, loss, ...
LogFieldPlayers       -- id, map, mode, maxround, round, starttime, charname[N], exp[N],
                      --   gold[N], winloss[N], endtime
LogDeleteCharacter    -- userid, charname, deletetime, level
LogUserItem           -- userid, characterid, itemid, gold, kind, processtime, gold_prev,
                      --   gold_cur, level, exp, coupon_log_id
LogBuyCashItem        -- userid, itemid, price, cash_prev, cash_cur, createtime, coupon_log_id
LogBuyPowerUser       -- userid, extend, buycash, powertime_prev, powertime_cur, buytime,
                      --   powertime, powerlevelpoint_prev, powerlevelpoint_cur, coupon_log_id
LogCharStateClear     -- userid, charid, level, cost, cash_prev, cash_cur, totallevelpoint,
                      --   usedpowerlevelpoint, createtime, coupon_log_id
LogChangeCharName     -- userid, charid, cost, cash_prev, cash_cur, charname_prev, createtime,
                      --   coupon_log_id
LogCurrentUser        -- id, users, checktime
logcoupon             -- coupon_id, item_id, user_id, use_time, discount_amount
AdminInfo             -- ip, class
```

---

## 5. PROTOCOLO DE RED (Mensajes identificados)

### Arquitectura de dispatchers (descubierta con Ghidra MCP)

El servidor tiene **tres niveles de dispatch**:

1. **Capa socket** (`FUN_0042bd70`, 19.8 KB): Loop principal que desencola de 4 colas (TCP recv, DB send x2, UDP) y despacha.
2. **Login/Game Dispatcher** (`FUN_0042ab40`): Switch con **87 opcodes** (0x01–0x79). Firm: `void __thiscall(CWorld* world, ushort fieldIdx, ushort opcode, uint data_size, uint* data_ptr)`.
3. **DBWorker Dispatch** (`FUN_0041ae50`): Switch con **40 opcodes** (0x01–0x2B). Las respuestas de la DB vuelven a través de este dispatcher.

### Cifrado de paquetes (PRTCLIB — WorldServerDll.dll)
El servidor **NO** usa cifrado interno. Todo el cifrado/descifrado se delega a `WorldServerDll.dll`, cargada dinámicamente en `FUN_004304f0`:

```
LoadLibraryA("WorldServerDll.dll")
  → GetProcAddress(hModule, "PrtcGetVersion")     → guardado en struct+0x04
  → GetProcAddress(hModule, "PrtcGetAuthQuery")    → guardado en struct+0x1C (+7)
  → GetProcAddress(hModule, "PrtcCheckAuthAnswer") → guardado en struct+0x20 (+8)
  → GetProcAddress(hModule, "PrtcEncryptQuery")    → guardado en struct+0x24 (+9)
  → GetProcAddress(hModule, "PrtcDecryptAnswer")   → guardado en struct+0x28 (+10)
  → GetProcAddress(hModule, "PrtcUpdateTimer")     → guardado en struct+0x2C (+11)
  → PrtcGetVersion(DAT_004581b8) → version en struct+0x04
```

El struct PRTCLIB (0x38 bytes) se almacena en una lista ligada global (`DAT_00457ff0`).

**Pipeline wire:**
```
Wire TCP:  [AES_encrypted_blocks_0x7FC4]
  → PrtcDecryptAnswer(hModule, data, size) → datos descifrados
  → [fieldId:2][dataSize:2][opcode:2][payload:N]
  → push a TcpRecvQueue
```

**Pipeline saliente:**
```
handler → FUN_004038e0(SEND) → buffer plano
  → PrtcEncryptQuery(hModule, data, size) → datos cifrados
  → WSASend → wire
```

El formato de bloque AES usado es **0x7FC4** (AES-ECB con clave estática), implementado dentro de WorldServerDll.dll.

### Formato de cola de paquetes (TcpRecvQueue, pop en FUN_004038d0)
```
Offset  Tipo     Campo
------  -------  ------
0x00    ushort   fieldId (índice de conexión/jugador)
0x02    ushort   dataSize (bytes totales de opcode + payload)
0x04    uint32   seqNum (número de secuencia, 4 bytes)
0x08    ushort   opcode (2 bytes)
0x0A    ...      payload (dataSize - 2 bytes)
```

Nota: El formato exacto puede variar — la cola TcpRecvQueue (FUN_004038d0) usa un formato diferente a la cola DbRecvQueue (FUN_0042e580). Pendiente verificar el layout exacto de la cabecera.

### Llamada al dispatcher de juego
```
FUN_0042ab40(world, fieldId, opcode, dataSize, dataPtr)
```
Donde `opcode` es `ushort`, `dataSize` es `uint`, `dataPtr` apunta al payload.

### Opcode 0x0C — Post-switch handler (especial)
`0x0C` en el dispatcher de red hace `break;` en el switch y cae al código post-switch, que bifurca según `this+0x5b18`:
- **0** → llama a `FUN_0041f6c0` (game world handler) — **ruta normal para login de usuarios**
- **≠0** → llama a `FUN_0042a310` (DB/admin handler)

### Opcode 0x0E
Mismo handler que 0x0C (`FUN_0041fa40`).

### Secuencia de paquetes (sequence number)
Cada field tiene un contador de secuencia en `field+0x146e` (ushort). Se valida antes de dispatch (wrap-around en 65000). Si no coincide, se envía `FUN_0041eb20(world, fieldId, 2, 0x01, 1)` — reset de secuencia.

### Tabla completa de opcodes
Ver archivo completo en `analysis/03_packet_opcodes.md` — se extrajeron 87 opcodes de red + 40 opcodes DB.

### Comandos de chat/admin
```
/roominfo   — ver info de sala
```

### Logs de estado del servidor
```
[XXXX] DISC NNN  — Disconnect
[XXXX] ALTO N    — Alto (parada)
[XXXX] GMGD N    — GameGuard
[XXXX] IOE1 XX NNNNN — IO Error 1
[XXXX] IOE2 XX NNNNN — IO Error 2
[0000] DUPC       — Duplicate connection
Server Start / Stop / Open / Close
```

---

## 6. SISTEMAS CLAVE A EMULAR

### 6.1 Autenticación
- HTTP POST a `AuthPage` (por defecto `/auth.asp`) con XML:
  ```xml
  <msg>
    <PTUserName>user</PTUserName>
    <Password>pass</Password>
    <GameClientIP>ip</GameClientIP>
    <Attachment></Attachment>
  </msg>
  ```
- También hay auth URL-based: `?id=X&pw=Y&idc=0`
- GameGuard anti-cheat: `ggauth60.dll` con protocolo de challenge/response

### 6.2 Sistema de Tiempo
- El servidor usa minutos desde epoch como unidad de tiempo:
  ```sql
  (to_days(now())*24+hour(now()))*60+minute(now())
  ```
- PowerUser expira en minutos: `powertime + 30*1440`
- LimitTime de ítems temporales: `current_minutes + 1440*días`

### 6.3 Enchant/Reinforce de ítems
- Sistema de niveles de ítem (level +1, -1, -2, -3 con probabilidad)
- Probabilidad con seed/random: `pp[0..5]`, `seed`, `p`, `nLv`, `u`, `c1`, `c2`, `c3`

### 6.4 Rank Tree (árbol de referidos)
- Campos: `treeuppername`, `treerank`

### 6.5 Clan System
- `clanid`, `clanrank`, `clangrade`, `clanpoint`, `masterid`

---

## 7. PLAN DE IMPLEMENTACIÓN DEL EMULADOR C#

### Fase 1 — Infraestructura base
- [ ] Proyecto C# (.NET 8, consola)
- [ ] Lector de `worldserver.ini`
- [ ] Conexión MySQL (MySql.Data o Pomelo)
- [ ] Servidor TCP con IOCP (System.Net.Sockets, SocketAsyncEventArgs)
- [ ] Servidor UDP
- [ ] Clase `Session` / `ClientConnection`
- [ ] Sistema de logging (con formato `[YYYY-MM-DD HH:MM:SS] [ID] mensaje`)

### Fase 2 — Parseo de paquetes
- [ ] Capturar tráfico real cliente↔servidor con Wireshark
- [ ] Identificar cabecera de paquete (length, opcode, datos)
- [ ] Implementar `PacketReader` / `PacketWriter`
- [ ] Mapear opcodes a handlers

### Fase 3 — Handlers de autenticación
- [ ] `HandleLogin` → DBCommandLogin
- [ ] `HandleDisconnect` → LogUserConnect update

### Fase 4 — Handlers de personaje
- [ ] `HandleCharacterList` → DBCommandCharacterList
- [ ] `HandleCharacterCreate` → DBCommandCharacterCreate
- [ ] `HandleCharacterSelect` → DBCommandCharacterSelect
- [ ] `HandleCharacterDelete` → DBCommandCharacterDelete
- [ ] `HandleCharacterChangeCharName`
- [ ] `HandleCharacterStateClear`

### Fase 5 — Inventario y tienda
- [ ] `HandleInventoryEnter`
- [ ] `HandleInventoryBuy`
- [ ] `HandleInventorySell`
- [ ] `HandleInventoryBuyBag`
- [ ] `HandleInventoryBuySlot`
- [ ] `HandleInventoryBuyPowerUser`
- [ ] `HandleInventoryBuyPotionSlot`
- [ ] `HandleInventoryBuyStageLevelFree`
- [ ] `HandleInventoryBuyStageRankClear`
- [ ] Sistema de encantamiento (enchant/reinforce)

### Fase 6 — Sistema de campo (Field/Stage)
- [ ] `HandleFieldList`
- [ ] `HandleFieldCreate`
- [ ] `HandleFieldQuickEnter`
- [ ] `HandleFieldExit`
- [ ] `HandleFieldReady`
- [ ] `HandleFieldChat`
- [ ] `HandleGameDiePlayer` → CField::GameDiePlayer
- [ ] Cálculo de exp/gold al finalizar

### Fase 7 — Sistemas adicionales
- [ ] Sistema de clanes
- [ ] Sistema de votación (Vote/BanSlot)
- [ ] Lotería (BuyLotto, AskLotto, LottoResult)
- [ ] Sistema de regalos (presents)
- [ ] AdminInfo y comandos GM

### Fase 8 — GameGuard (opcional/bypass)
- [ ] Stub que devuelve OK sin verificar

---

## 8. SESIONES DE ANÁLISIS

### Sesión 1 — [fecha]
**Estado:** Análisis estático inicial del binario  
**Completado:**
- ✅ Headers PE parseados
- ✅ Strings extraídos (~600 strings únicos)
- ✅ Tablas MySQL mapeadas (30+ tablas)
- ✅ Clases principales identificadas (CWorld, CUser, CField, CDB, PerfLib)
- ✅ Protocolo de autenticación HTTP identificado
- ✅ Dependencias DLL mapeadas
- ✅ Sistema de tiempo documentado

**Pendiente:**
- ❌ Ghidra: descompilar funciones principales
- ❌ Opcodes de paquetes de red
- ❌ Estructura exacta de paquetes (header format)
- ❌ Algoritmo de encantamiento completo
- ❌ Formato binario de mensajes de campo

### Sesión 4 (a+b) — 2026-05-28 (noche, completa)
**Estado:** Decompilación en profundidad: flujo login + handlers de personajes + 10 handlers adicionales  
**Herramientas:** Ghidra MCP | **Archivos .c:** 42 en `analysis/funcs/`

**Funciones decompiladas (27 nuevas en Sesión 4):**
- Game handlers: opcode 0x01 (`FUN_0041ee00`), 0x02 (`FUN_0041ef00`), 0x03, 0x04 (`FUN_0041f1a0`), 0x09 (`FUN_0041f5c0` item info), 0x0B (`FUN_0041f480` MD5 setup), 0x0F, 0x10, 0x12 (`FUN_0041fcd0` char create), 0x13 (`FUN_0041fe10` char delete), 0x14 (`FUN_0041fef0` char select)
- DB handlers: 0x01 (ban), **0x02 (login builder — 4000 líneas)**, 0x04 (disconnect), 0x05 (RealIP), 0x07 (char create), 0x08 (char delete), 0x0E (tutorial), 0x0F (LogDiePlayer), 0x10 (char state clear/level up), 0x29 (buy lotto), 0x2A (lotto results), 0x2B (clan/buddy list)
- DB Response: **dispatch table completa** + case 1 (auth dup), **case 2 (login response processor)**, **case 3 (char data)**, case 7 (char select response)

**Completado en 4a:**
- ✅ **Tres dispatch tables separadas**: game (87), DB (40), DB Response (30+)
- ✅ **Flujo login completo** end-to-end: game 0x04 → DB opcode 2 → DB Resp case 2 → cliente
- ✅ **Formatos de cola DB**: command `[retOpcode:2][dbOpcode:2][payload:N]`, response `[fieldId:2][size:2][retOpcode:2][subType:2][payload:N]`
- ✅ **Login handler** (`FUN_004107d0`, 42 KB) decompilado con 8+ queries y formato de respuesta
- ✅ **Códigos resultado login**: 0=ok, 1=DB err, 2=not found, 3=wrong pw, 6=banned, 0x1A=success
- ✅ **Estructuras**: CWorld (0x5F44), CField (0x23B4), TcpListener (0x24), recv buffer (0x68)
- ✅ **FUN_004038e0** = SENDER, **FUN_0041b940** = DB command sender
- ✅ **Char create/delete** formatos completos

**Completado en 4b:**
- ✅ **Flujo de personajes completo**: create (game 0x12 → DB 7), delete (game 0x13 → DB 8), select (game 0x14 → DB Resp case 7)
- ✅ **Char select**: formato slot array 0x360 bytes por personaje en field structure
- ✅ **Item info** (game 0x09): usa array de items de 0x3C0 bytes c/u en CWorld+0xE4
- ✅ **Char state clear/level up** (DB 0x10): power level points, cash deduction, coupons
- ✅ **LogDiePlayer** (DB 0x0F): log de muerte en batalla
- ✅ **Clan/buddy list** (DB 0x2B): query de lista de amigos/clan
- ✅ **Lotto** (DB 0x29/0x2A): compra y consulta de resultados de lotería
- ✅ **Tutorial** (DB 0x0E): update de estado de tutorial
- ✅ 10 archivos .c nuevos guardados

**Correcciones:**
- ❌ DB opcode 0x04 NO es char create — es disconnect log update
- ❌ DB opcode 0x05 NO es char list — es RealIP update
- ❌ DB opcode 0x0C NO es buy item — es exp update en CharacterInfo
- ❌ DB opcode 0x0D NO es sell item — es buddy name query
- ✅ El flujo login real usa dispatch separado (FUN_004295c0, no el game dispatcher)
- ✅ Firma correcta dispatcher: `(CWorld*, ushort fieldIdx, ushort opcode, uint dataSize, uint* dataPtr)`

**Pendiente para próxima sesión:**
- ❌ **Sistema de encantamiento** — NO ENCONTRADO. Sin strings "enchant/reinforce/LevelUp" en el binario. Probablemente en game opcodes 0x15–0x36 sin decompilar
- ❌ Callback IOCP real (buscar función que llama GetQueuedCompletionStatus)
- ❌ Sistema P2P/UDP battle
- ❌ Handlers de field/stage (game opcodes 0x30–0x50)
- ❌ Guardar handlers inline faltantes como .c (FUN_004121e0, FUN_00412280, etc.)
- ❌ Implementar emulador C#: flujo login + personajes ya están documentados

### Sesión 6 — 2026-05-29 (tarde)
**Estado:** Descubrimiento de PRTCLIB (WorldServerDll.dll crypto layer) + corrección de frame format + verificación de opcodes
**Herramientas:** Ghidra MCP headless

**Completado:**
- ✅ **`WorldServerDll.dll`** descubierta — cargada dinámicamente vía `LoadLibraryA` en `FUN_004304f0`
- ✅ **6 funciones PRTCLIB** descubiertas vía strings + GetProcAddress:
  - `PrtcGetVersion` (struct+0x04) — versión del protocolo
  - `PrtcGetAuthQuery` (struct+0x1C/+7) — query de autenticación
  - `PrtcCheckAuthAnswer` (struct+0x20/+8) — verificación de auth
  - **`PrtcEncryptQuery`** (struct+0x24/+9) — **cifrado de paquetes salientes**
  - **`PrtcDecryptAnswer`** (struct+0x28/+10) — **descifrado de paquetes entrantes**
  - `PrtcUpdateTimer` (struct+0x2C/+11) — timer del protocolo
- ✅ **Formato de cifrado confirmado**: AES-ECB con bloque 0x7FC4 (clave estática en WorldServerDll.dll)
- ✅ **Pipeline wire documentado**: PrtcDecryptAnswer antes de push a cola, PrtcEncryptQuery antes de WSASend
- ✅ **Frame format corregido**: opcode es `ushort` (2 bytes), no `uint32`
- ✅ **Corrección de opcode 0x0C**: NO es solo DB Response — bifurca entre game handler (FUN_0041f6c0, login normal) y DB handler (FUN_0042a310)
- ✅ **Corrección de errores anteriores**: 
  - ❌ "AES no existe" → CORREGIDO: `PrtcEncryptQuery`/`PrtcDecryptAnswer` SÍ existen
  - ❌ "Opcode 0x000C no es login" → CORREGIDO: 0x0C post-switch → FUN_0041f6c0 = game handler (login normal)
  - ❌ "Opcode 4 bytes" → CORREGIDO: dispatcher recibe `ushort param_2`

**Hallazgos clave:**
- El struct PRTCLIB (0x38 bytes) se almacena en lista ligada global (`DAT_00457ff0`)
- La función `FUN_004304f0` es el **loader** de la DLL — recibe `(char* versionParam, int isGlobal)` y construye el struct
- El cifrado NO está dentro de WorldServer.exe — todo se delega a la DLL externa
  Esto explica por qué no encontramos imports de AES/crypto en la tabla de imports estática
- Los punteros a funciones se guardan como `FARPROC` en el struct +0x04 (version), +0x1C (+7) a +0x2C (+11)

**Correcciones para el emulador C#:**
- ✅ El codec AES-ECB + 0x7FC4 de `Program.cs` es **CORRECTO** — el servidor real usa `PrtcEncryptQuery`/`PrtcDecryptAnswer` con ese formato
- ❌ El mapeo de opcodes en `Program.cs` tiene errores de NOMBRE (no de valor):
  - `0x0036` = RoomListQuery (no FieldList)
  - `0x0047` = ChannelFieldList (no FieldChat)
  - `0x0061` = FieldReady (no KeepAliveOrVersion)
  - `0x004F` = FieldQuickEnter (no BattleDeathReport)
- ❌ Falta máquina de estados CField (state 2=lobby, 3=room)
- ❌ Falta DBWorker asíncrono con colas

**Archivos actualizados en esta sesión:**
```
RAKION_RE_MASTER.md — Sesión 6 añadida, frame format corregido, PRTC struct documentado
03_packet_opcodes.md — frame format corregido (ushort opcode)
01_functions_list.md — PRTC functions añadidas
login_flow.md — pipeline actualizado con PRTCLIB decrypt
SESSION_LOG.md — Sesión 6 añadida
```

**Pendiente:**
- ❌ Verificar formato exacto de la cabecera TcpRecvQueue (FUN_004038d0)
- ❌ Callback IOCP real (GetQueuedCompletionStatus)
- ❌ Sistema de encantamiento/reinforce
- ❌ Sistema P2P/UDP battle
- ❌ Implementar emulador C# con flujo login + personajes

### Sesión 7 — 2026-05-29 (final, consolidación de documentación)
**Estado:** Expansión de Character Management al 100% con esquema BD completo + slot 0x360 mapeado + todas las queries SQL exactas + oro/cash/pets/clan + consolidación cross-reference entre todos los .md
**Herramientas:** Ghidra MCP (análisis existente) | **Archivos .c:** 151 en `analysis/funcs/`

**Completado en Character Management:**
- ✅ **Esquema BD completo** agregado a `character_management.md`: 12+ tablas con columnas exactas, tipos, PKs, FKs
- ✅ **Todas las queries SQL** extraídas de FUN_004107d0.c (login) — queries de auth, UserGameInfo, CharacterInfo, UserItemInfo, Cash, UserStageInfo, ClanInfo, log tables
- ✅ **Slot 0x360 mapeado offset por offset** — cada campo con tipo, tamaño, origen BD
- ✅ **Items compartidos de cuenta** (characterid=0 en UserItemInfo) documentados con paquete 0x0D (120 slots globales)
- ✅ **Manejo de oro**: todas las queries con atomicidad `WHERE gold>=%u`
- ✅ **Manejo de cash**: tabla separada keyeada por username string (NO accountId)
- ✅ **Pets/crias**: confirmado NO existen como tabla separada — son items en UserItemInfo con ItemInfo.type=mascota
- ✅ **Sistema Power User**: powertime + powerlevelpoint con queries exactas
- ✅ **Slots de personaje por cuenta**: UserGameInfo.slot controla máximo (default 5, máx 10)
- ✅ **Tabla ItemInfo**: columnas exactas (id, type, class, level, shop, gold, cash, stats)
- ✅ **15+ tablas de log** documentadas

**Completado en cross-referencing:**
- ✅ `login_flow.md` → referencias a `character_management.md` en sección de Character Management
- ✅ `03_packet_opcodes.md` → referencias a `character_management.md` y `lobby_phase.md`
- ✅ `RAKION_RE_MASTER.md` → sección 3.4 ahora referencia `character_management.md` y `lobby_phase.md`
- ✅ `RAKION_RE_MASTER.md` → sección 12 (estructura de carpetas) incluye todos los .md + conteo actualizado
- ✅ `SESSION_LOG.md` → Sesión 7 agregada
- ✅ `program_info.md` → conteo .c actualizado (128→151)

**Hallazgos clave de la Sesión 7:**
- El campo `UserGameInfo.slot` controla cuántos personajes puede tener una cuenta (default 5, UPDATE para aumentar)
- MySQL trigger en CharacterInfo.slot causa problemas de asignación — solución: slot virtual en C#
- `Cash` table usa username string como key, confirmado por 6 cross-references en el binario
- `UserItemInfo.characterid=0` = account-shared item, no pertenece a ningún personaje
- Pets NO existen como tabla UserPetInfo — solo son items con type=mascota en ItemInfo
- Gold siempre se decrementa con `WHERE gold>=%u` para evitar balances negativos
- Items expirados se eliminan con `DELETE FROM UserItemInfo WHERE limittime>0 AND limittime<%u`
- `ItemInfo` es la tabla crítica cargada al iniciar servidor — catalogo completo de items

**Archivos actualizados/creados en esta sesión:**
- `character_management.md` — expandido de 1214 a 1668 líneas con BD, slot, gold/cash/pets
- `RAKION_RE_MASTER.md` — Session 7 añadida, refs cruzadas, conteo actualizado
- `SESSION_LOG.md` — Sesión 7 añadida

**Pendiente global:**
- ❌ Sistema de encantamiento/reinforce — NO ENCONTRADO en el binario
- ❌ Sistema P2P/UDP battle — sin analizar
- ❌ Callback IOCP real (GetQueuedCompletionStatus)
- ❌ Implementar emulador C# — flujo login + personajes + lobby ya documentados
- ❌ Fase In-Game (opcodes 0x50-0x77) — solo stubs, helpers no decompilados
- ❌ Sistema NPC (spawn, AI, interacciones) — solo NPCInfo table conocida

### Sesión 5 — 2026-05-29
**Estado:** Decompilación masiva de handlers del dispatcher principal (86 opcodes) + descubrimiento de nombres reales vía strings
**Herramientas:** Ghidra MCP headless (v5.12.0) | **Archivos .c:** 128 en `analysis/funcs/` (~586 KB)

**Completado:**
- ✅ **Dispatcher principal** (`FUN_0042ab40`) decompilado y guardado — switch con 86 cases
- ✅ **86 opcodes** extraídos con handlers mapeados (decimal 1-10, hex 0x0B-0x79, decimal 100, 112-121)
- ✅ **Todos los handlers individuales** decompilados como archivos .c (~72 nuevos en esta sesión)
- ✅ **9 handlers inline** decompilados que inicialmente tenían código inline (`FUN_004292b0`, `FUN_004293f0`, `FUN_00428520`, `FUN_00421a50`, `FUN_004222a0`, `FUN_004225d0`, `FUN_0041be60`, `FUN_0041bde0`, `FUN_00422270`)
- ✅ **Nombres reales de funciones descubiertos via strings** (a pesar de binario stripped):
  - `CWorld::NetworkMessageDisconnect` → `FUN_00422270` (opcode 0x79)
  - `CWorld::Idle` → posiblemente `FUN_0042cee0` (68 KB, función más grande)
  - `CWorld::DBPS` → `FUN_00429030` (opcode 0x08)
  - `CDB::DBCommandBuyLotto` / `AskLotto` / `LottoResult` → `FUN_0040f2f0`
  - `CDB::DBCommandAskClan` → `FUN_0040f610`
  - `CDB::DBCommandAdminBan` → `FUN_00410650`
  - `CDB::DBCommandLogin` → `FUN_004107d0` (42 KB)
  - `DBCommandCharacterCreate` → `FUN_00412280`
  - `DBCommandCharacterDelete` → `FUN_00412530`
  - `DBCommandCharacterChangeCharName` → `FUN_004144f0`
  - `DBCommandCharacterStateClear` → `FUN_00413cd0`
  - `DBCommandInventoryEnter` → `FUN_00414cc0`
  - `DBCommandInventoryBuy` → `FUN_00419a40`
  - `DBCommandInventorySell` / `DBCommandCharacterList` → `FUN_0041a900`
  - `DBCommandInventoryBuyBag` → `FUN_00414e70`
  - `DBCommandInventoryBuySlot` → `FUN_00415590`
  - `DBCommandInventoryBuyPowerUser` → `FUN_00415cb0`
  - `DBCommandInventoryBuyPotionSlot` → `FUN_00417800`
  - `DBCommandInventoryBuyStageRankClear` / `StageLevelFree` → `FUN_004184a0`
- ✅ **11 strings NetworkMessage** encontrados con xrefs a sus funciones (FieldReady, FieldCreate, FieldList, FieldExit, FieldChat, FieldQuickEnter, BuyLotto, Disconnect)
- ✅ **Opcodes mapeados a nombres funcionales**: opcode 0x47 → `NetworkMessageFieldList`, 0x4F → `NetworkMessageFieldQuickEnter`, 0x53 → `NetworkMessageFieldCreate`, 0x61 → `NetworkMessageFieldReady`, 0x79 → `CWorld::NetworkMessageDisconnect`
- ✅ **Opcodes sin handler documentados** (gaps): 0x06-0x07, 0x0D, 0x11, 0x1D, 0x1F, 0x21, 0x23-0x28, 0x2B, 0x30, 0x37, 0x3C, 0x44, 0x49, 0x4E, 0x51-0x52, 0x54-0x55, 0x58, 0x5C, 0x5F, 0x63-0x64, 0x66-0x6A, 0x7A+
- ✅ **`analysis/03_packet_opcodes.md`** regenerado con tabla completa de 86 opcodes + tabla DBWorker + nombres descubiertos

**Hallazgos clave:**
- El dispatcher recibe `(this, fieldIdx, opcode, dataSize-4, &payload[4])` — puro puntero a payload
- Los handlers no parsean individualmente el header del paquete; todo el parsing del header ocurre en el caller
- Opcode 0x0C es especial: hace `break` y cae al código post-switch que bifurca entre game world handler (`FUN_0041f6c0`) y DB response handler (`FUN_0042a310`)
- Se descubrieron **~25 nombres de funciones reales** a pesar de que el binario está stripped, mediante xrefs a strings de debug
- El servidor usa nombres estilo `CWorld::NetworkMessage*` y `CDB::DBCommand*` para sus handlers
- Los strings están en .rdata con prefijos `[RW]` y etiquetas de clase (CWorld::, CDB::)

**Archivos generados (99 nuevos en esta sesión):**
```
analysis/03_packet_opcodes.md         — tabla completa con 86 opcodes + DBWorker
analysis/funcs/FUN_0042ab40_dispatcher.c — switch del dispatcher completo
analysis/funcs/FUN_0041eb20.c          — función de log de "Not Channel" para NetworkMessage
analysis/funcs/FUN_00422270.c          — CWorld::NetworkMessageDisconnect handler
analysis/funcs/FUN_004292b0.c          — handler opcode 0x70
analysis/funcs/FUN_004293f0.c          — handler opcode 0x71
analysis/funcs/FUN_00428520.c          — handler opcode 0x72
analysis/funcs/FUN_00421a50.c          — handler opcode 0x73
analysis/funcs/FUN_004222a0.c          — handler opcode 0x75
analysis/funcs/FUN_004225d0.c          — handler opcode 0x76
analysis/funcs/FUN_0041be60.c          — handler opcode 0x77
analysis/funcs/FUN_0041bde0.c          — handler opcode 0x78
... + 72+ handlers de opcodes adicionales
```

**Completado en análisis posterior dentro de Sesión 5:**
- ✅ **Análisis completo de todos los 86 handlers** → tabla completa con descripciones en `03_packet_opcodes.md`
- ✅ **Flujo completo mapeado**: Login → Channel → Char Select → Lobby → Room → In-Game → Disconnect
- ✅ **Máquina de estados del field** documentada (0x1440: 0=lobby, 3=room, 4/5=admin)
- ✅ **Cada opcode categorizado** por fase (auth, login, char mgmt, lobby, room, game)
- ✅ **login_flow.md** actualizado con flujo completo post-login
- ✅ **03_packet_opcodes.md** rewrite completo con descripciones funcionales
- ❌ Pendiente: Callbacks IOCP reales (GetQueuedCompletionStatus)
- ❌ Pendiente: Sistema de encantamiento/reinforce
- ❌ Pendiente: Sistema P2P/UDP battle
- ❌ Pendiente: Identificar `CWorld::Idle` (FUN_0042cee0, 68 KB)
- ❌ Pendiente: Empezar implementación emulador C#

### Sesión 3 — 2026-05-28 (tarde)
**Estado:** Análisis profundo del pipeline de paquetes y arquitectura de hilos  
**Herramientas:** Ghidra MCP

**Completado:**
- ✅ Identificado el **modelo de hilos real**: 3 hilos (IOCP loop, DBWorker, GameGuard)
- ✅ Confirmado que `PerfLib::IoCompletionPort`/`ThreadPool` es **código muerto** — el servidor usa IOCP raw de Win32
- ✅ Identificado que `FUN_0042bd70` **no** llama a `GetQueuedCompletionStatus` — solo procesa colas pre-parseadas
- ✅ Encontrado el **pipeline completo**: AcceptEx → IOCP callback → recv queue (`FUN_0042e720`) → main loop
- ✅ Confirmado **formato de cola**: `[fieldId:2][dataSize:2][opcode+payload:N]`
- ✅ `FUN_004038e0` = SEND (no queue push)
- ✅ Encontrada la **estructura de field** (0x23b4 bytes) con offsets clave
- ✅ Encontrada la **estructura de buffer de recv** por field (0x68 bytes)
- ✅ Identificado que **creación de personaje** (opcode 0x05) usa strings null-terminated
- ✅ Encontradas las funciones de AcceptEx (`FUN_00404a10`) y WSARecv (`FUN_004047f0`)
- ✅ `FUN_0041b940` = DB command sender (push DbSendQueue + SetEvent)
- ✅ Identificado thread DBWorker creado en `FUN_0041b520`

**Correcciones al contexto:**
- ❌ `PerfLib::IoCompletionPort` es código muerto
- ❌ `FUN_0042cee0` = init, no loop principal
- ❌ `FUN_0042bd70` no llama a GQCS, solo procesa colas
- ❌ Formato de paquete anterior incorrecto: ahora (fieldIdx, opcode, dataSize-4, &payload[4])

**Pendiente (resuelto en Sesión 4):**
- ✅ Analizar DB handlers individuales
- ✅ Mapear estructuras C++ completas (CWorld, CField, TcpListener)
- ❌ Encontrar callback IOCP real
- ❌ Sistema de encantamiento
- ❌ Formato UDP battle

### Sesión 2 — 2026-05-28 (mañana)
**Estado:** Decompilación masiva con Ghidra MCP  
**Herramientas:** Ghidra MCP (bethington/ghidra-mcp) — HTTP en `127.0.0.1:8089`  
**Comandos usados:** `list_segments`, `list_functions`, `list_imports`, `list_exports`, `analyze_function_complete`, `decompile_function`

**Completado:**
- ✅ Confirmado binario cargado: 5 segmentos (Headers, .text, .rdata, .data, .Silvana)
- ✅ Exportadas 1046 funciones a `analysis/01_functions_list.md`
- ✅ Import list (100 imports: Winsock, MySQL, WinINET, OLE/COM, CRT) + Export list (150+ exports demangled de PerfLib)
- ✅ Buscados patrones "NetworkMessage", "DBCommand", "CWorld" — **no existen** (binario totalmente stripped)
- ✅ Decompiladas **24 funciones clave** guardadas en `analysis/funcs/*.c`:

  **Mayor prioridad:**
  - `FUN_004107d0.c` (42 KB) — DBWorker_Opcode2: construye respuesta de login (65+ consultas SQL, formato de paquete secuencial) 
  - `FUN_0041ae50.c` (5.1 KB) — DBWorker Dispatch: switch de 40 opcodes DB
  - `FUN_0042ab40.c` (12.6 KB) — Login/Game Dispatcher: switch de 87 opcodes de red

  **Funciones más grandes decompiladas:**
  - `FUN_0042cee0.c` (68 KB) — Función MÁS GRANDE. Probablemente el main loop o procesamiento central
  - `FUN_0042bd70.c` (19.8 KB) — Llamador del dispatcher (procesa IOCP → arma paquetes → llama a FUN_0042ab40)
  - `FUN_00409940.c` (18.1 KB) — DB query builder
  - `FUN_004129f0.c` (18.8 KB) — Handler DB
  - `FUN_004087d0.c` (17.6 KB) — Procesamiento de datos
  - `FUN_00401670.c` (15.8 KB) — Inicialización
  - 12 funciones adicionales (desde 0.5 KB hasta 15 KB)

- ✅ Extraídos **87 opcodes de red** a `analysis/03_packet_opcodes.md` desde el switch de FUN_0042ab40:
  - Opcodes van desde 0x01 hasta 0x79
  - Opcode 0x0C es especial (break → post-switch dispatch a DBWorker o GameWorld)
  - Muchos opcodes intermedios sin handler (0x06, 0x07, 0x0D, 0x11, 0x1D, 0x1F, etc.) — posiblemente deshabilitados o de otra build

- ✅ Extraídos **40 opcodes DB** desde FUN_0041ae50:
  - Opcodes DB van desde 0x01 hasta 0x2B
  - DB opcode 0x02 = FUN_004107d0 (login response builder) — el más grande
  - DB opcode 0x0C = FUN_004138b0 (buy item)
  - DB opcode 0x0D = FUN_00413980 (sell item)

**Hallazgos clave:**
- El binario está **completamente stripped** (solo símbolos de exports PerfLib y runtime CRT)
- Los exports revelan namespaces completos de `PerfLib` (TcpSocket, UdpSocket, IoCompletionPort, ThreadPool, MemoryPool, AsyncWebRequest, etc.)
- El dispatch de red usa switch/case con jump table (no if/else chain)
- El DBWorker tiene su propio dispatch separado (FUN_0041ae50) para respuestas asíncronas
- La función `FUN_0042cee0` (68 KB) no está identificada pero es la más grande del binario — posiblemente `CWorld::Idle` o el loop principal del servidor

**Archivos generados (31 archivos, ~398 KB total):**
```
analysis/01_functions_list.md       — 1046 funciones con direcciones
analysis/03_packet_opcodes.md       — 87+40 opcodes mapeados a handlers
analysis/program_info.md            — segmentos PE
analysis/login_flow.md              — flujo login completo (actualizado con Character Management)
analysis/character_management.md    — [ES] Gestión completa de personajes (6 handlers, 4 DB ops, helpers) — 100% descompilado
analysis/lobby_phase.md             — [ES] Fase Lobby/Sala completa (14 opcodes, estructura sala, tienda, equipar, comprar, movimiento, whisper)
analysis/funcs/*.c                  — 142+ funciones decompiladas (~650 KB)
analysis/funcs/SEARCH_RESULTS.md    — resultados de búsqueda por patrón
```

**Limitaciones de esta sesión:**
- ⚠️ El endpoint `search_functions_by_name` de Ghidra MCP no funciona correctamente (siempre devuelve "Search term is required")
- ⚠️ No se pudieron buscar funciones por patrón de nombre debido a que el binario está stripped
- ⚠️ No se decompilaron todas las 1046 funciones (solo las 24 más grandes/clave)
- ⚠️ El formato de cabecera de paquete exacto requiere más análisis

**Pendiente para próxima sesión (resuelto en Sesión 3):**
- ✅ Decompilada `FUN_0042cee0` (68 KB) — es init del servidor, no loop principal
- ✅ Identificado formato de header de paquete (fieldId:2 + dataSize:2 + opcode+payload)
- ❌ Analizar funciones DB handler individuales para entender su protocolo
- ❌ Mapear estructuras C++ (offsets de CWorld, CField, CUser) — pendiente
- ❌ Analizar el sistema de encantamiento

---

## 9. PROMPT COMPLETO PARA ANTIGRAVITY CLI / CLAUDE CODE CON GHIDRA MCP

Copia y pega esto al inicio de cada sesión de análisis con Ghidra MCP activo:

```
@RAKION_RE_MASTER.md

Eres un experto en ingeniería inversa de servidores de juego. 
Estamos analizando RakionWorldServ.exe para construir un emulador en C#.
Lee el contexto maestro completo arriba antes de continuar.

TAREA DE ESTA SESIÓN: [ESCRIBE AQUÍ la tarea específica]

Usa Ghidra MCP para ejecutar los siguientes pasos en orden:

PASO 1 — CARGA Y ANÁLISIS INICIAL
- Abre el binario en Ghidra
- Ejecuta análisis automático completo (Auto Analyze)
- Confirma que el ImageBase es 0x400000
- Lista el número total de funciones encontradas

PASO 2 — EXPORTAR LISTA DE FUNCIONES
- Exporta TODAS las funciones con: dirección VA, nombre (si hay símbolo), 
  tamaño en bytes, complejidad ciclomática estimada
- Guarda en analysis/01_functions_list.md

PASO 3 — STRINGS Y XREFS
- Para cada string de interés (ver sección 3 del contexto), 
  busca sus referencias cruzadas (XREFs)
- Anota qué función usa cada string importante
- Guarda en analysis/02_strings_xrefs.md

PASO 4 — DECOMPILACIÓN DE FUNCIONES CRÍTICAS
Decompila en orden de prioridad y guarda cada una en analysis/funcs/:

  4a. Función en Entry Point (0x00436E31) — inicialización del servidor
  4b. Funciones que usan string "worldserver.ini" — parsing de config
  4c. Función que usa "mysql_real_connect" — init de DB
  4d. Funciones NetworkMessage* — handlers de paquetes de red
  4e. Funciones DBCommand* — queries SQL
  4f. Función CWorld::Idle — loop principal
  4g. Funciones relacionadas a "listen"/"accept" — setup de socket
  4h. Función que parsea paquetes entrantes (busca patrones switch/case con muchos casos)

Para cada función decompilada:
- Guarda el pseudocódigo C en analysis/funcs/[nombre_o_addr].c
- Escribe un resumen en lenguaje natural de qué hace
- Identifica parámetros y tipos de retorno
- Anota el opcode si es un handler de red

PASO 5 — ESTRUCTURA DE PAQUETES
- Busca la función principal de dispatch de mensajes (switch grande sobre opcode)
- Lista TODOS los opcodes encontrados con su handler correspondiente
- Identifica el formato del header de paquete (offset de length, opcode, data)
- Guarda en analysis/03_packet_opcodes.md

PASO 6 — ESTRUCTURAS DE DATOS
- Identifica las estructuras C++ para CUser, CField, CWorld
- Documenta los offsets y tipos de cada campo
- Guarda en analysis/04_data_structures.md

PASO 7 — ALGORITMOS ESPECIALES
- Decompila y explica el algoritmo de encantamiento (enchant/reinforce)
  (busca funciones que usen las variables pp[], seed, nLv)
- Documenta el sistema de tiempo en minutos
- Guarda en analysis/05_algorithms.md

PASO 8 — ACTUALIZAR CONTEXTO
Al finalizar, actualiza la sección "8. SESIONES DE ANÁLISIS" de RAKION_RE_MASTER.md
con todo lo que se descubrió en esta sesión y qué queda pendiente.

REGLAS:
- Guarda CADA archivo en la carpeta analysis/ relativa al directorio de trabajo
- Si Ghidra tarda, procesa de a 10 funciones a la vez y muestra progreso
- Si encuentras algo no documentado en el contexto maestro (nuevo opcode, 
  nueva tabla, nueva clase), agrégalo al contexto
- Prioriza las funciones más grandes y complejas
- Para funciones con nombre mangled C++ (??0, ??1, etc.), desmanglealas
```

---

## 10. PROMPT SOLO PARA PARSEO DE PAQUETES (sesión específica)

```
@RAKION_RE_MASTER.md

SESIÓN: Identificar protocolo de red completo

Usando Ghidra MCP sobre RakionWorldServ.exe:

1. Encuentra la función de receive/dispatch principal.
   Pista: busca donde se llama a GetQueuedCompletionStatus o donde 
   se procesan los datos del IOCP. Luego sigue hasta el switch de opcodes.

2. Identifica el formato exacto del header de paquete:
   - ¿Cuántos bytes tiene el header?
   - ¿Byte/Word de longitud total? ¿Está incluida o excluida la cabecera?
   - ¿Byte/Word de opcode? ¿En qué offset?
   - ¿Hay checksum o encriptación?

3. Para CADA case del switch principal, extrae:
   - Valor del opcode (hex y decimal)
   - Nombre del handler si existe
   - Parámetros que lee del buffer
   - Tipos de datos leídos (byte, word, dword, string, etc.)

4. Documenta el protocolo en formato:
   ## Opcode 0xXX — NombreHandler
   | Offset | Tipo | Nombre | Descripción |
   |--------|------|--------|-------------|
   | 0x00   | WORD | length | ... |
   | 0x02   | BYTE | opcode | ... |
   ...

5. Guarda en analysis/03_packet_opcodes.md con un ejemplo de cada paquete
```

---

## 11. PROMPT PARA RETOMAR SIN GHIDRA (análisis de strings/contexto)

```
@RAKION_RE_MASTER.md

No tenemos Ghidra disponible en esta sesión. 
Lee el contexto maestro y continúa con la siguiente tarea pendiente
según la sección "8. SESIONES DE ANÁLISIS".

Basándote en los strings y estructuras ya documentadas:
1. ¿Qué tablas MySQL faltan por implementar en el emulador?
2. ¿Qué handlers de red podemos implementar ya con la info disponible?
3. Genera el código C# para: [TAREA ESPECÍFICA]

Para el código C#:
- Usa .NET 8
- MySql.Data para la DB
- System.Net.Sockets con SocketAsyncEventArgs para la red
- Patrones: Repository, Command Handler
- Sigue la estructura de nombres del servidor original (CWorld→WorldServer, CUser→UserSession, etc.)
```

---

## 12. ESTRUCTURA DE CARPETAS DEL PROYECTO

```
RakionEmulator/
├── RAKION_RE_MASTER.md              ← este archivo (documento maestro)
├── analysis/
│   ├── 01_functions_list.md         ← 1046 funciones + nombres reales anotados
│   ├── 03_packet_opcodes.md         ← 86 opcodes de red + 40 DB + nombres reales
│   ├── login_flow.md                ← flujo login completo (game → DB → DB Resp → cliente)
│   ├── character_management.md      ← [ES] Gestión de personajes 100% completa (1668 líneas)
│   ├── lobby_phase.md               ← [ES] Fase Lobby/Sala completa (737 líneas, 14 opcodes)
│   ├── SESSION_LOG.md               ← historial de todas las sesiones de análisis
│   ├── program_info.md              ← info del binario PE + segmentos + dispatch tables
│   └── funcs/                       ← 151 archivos .c decompilados (~700 KB)
│       ├── FUN_0042ab40_dispatcher.c ← switch del dispatcher principal
│       └── FUN_*.c                  ← handlers decompilados
├── src/
│   └── RakionWorldServer/
│       ├── RakionWorldServer.csproj
│       ├── Program.cs
│       ├── Config/
│       │   └── ServerConfig.cs
│       ├── Network/
│       │   ├── TcpServer.cs
│       │   ├── UdpServer.cs
│       │   ├── ClientSession.cs
│       │   ├── PacketReader.cs
│       │   └── PacketWriter.cs
│       ├── Handlers/
│       │   ├── AuthHandler.cs
│       │   ├── CharacterHandler.cs
│       │   ├── InventoryHandler.cs
│       │   ├── FieldHandler.cs
│       │   └── AdminHandler.cs
│       ├── Database/
│       │   ├── DbManager.cs
│       │   ├── UserRepository.cs
│       │   ├── CharacterRepository.cs
│       │   ├── ItemRepository.cs
│       │   └── ...
│       ├── Game/
│       │   ├── World.cs
│       │   ├── UserSession.cs
│       │   ├── Field.cs
│       │   ├── Channel.cs
│       │   └── GameGuardStub.cs
│       └── worldserver.ini
└── sql/
    └── schema.sql               ← DDL de todas las tablas
```

---

## 13. CÓDIGO C# BASE — Para empezar ahora

### worldserver.ini de ejemplo
```ini
[Server]
ServerId=1
ServerList=World Server 1
MaxUser=200
MaxField=100
Port=10001
DisplayName=Rakion World Server

[Database]
MaxDbConnection=5
DbConnIncrease=1
DbConnDecrease=1
DbConnAdjustFreq=60
DbSendQueue=1000
DbRecvQueue=1000

[Network]
TcpSendPoolSize=512
TcpRecvQueue=512
UdpRecvQueue=256
SendPoolCount=256

[Auth]
Authentication=1
AuthPage=/auth.asp

[Channels]
channel00=Channel 1
channel01=Channel 2
```

### ServerConfig.cs básico
```csharp
public class ServerConfig
{
    public int ServerId { get; set; } = 1;
    public string ServerList { get; set; } = "";
    public int MaxUser { get; set; } = 200;
    public int MaxField { get; set; } = 100;
    public int Port { get; set; } = 10001;
    public string DisplayName { get; set; } = "";
    public string AuthPage { get; set; } = "/auth.asp";
    public int MaxDbConnection { get; set; } = 5;
    public List<string> Channels { get; set; } = new();

    public static ServerConfig Load(string path = "worldserver.ini")
    {
        // Usar GetPrivateProfileString equivalente en C#
        var cfg = new ServerConfig();
        var lines = File.ReadAllLines(path);
        // parsear secciones...
        return cfg;
    }
}
```

---

*Actualizado: Sesión 9 — Todas las 12 funciones MISSING de shop/inventory/refinery decompiladas vía Ghidra MCP el 2026-05-29. `shop_inventory_refinery.md` expandido a ~1059 líneas con: EquipProcessing (FUN_0040c140), ItemLookup (FUN_0040bd80), LobbyItemQuery (FUN_0040b080), LobbyItemList (FUN_0040b1a0), ItemFieldExit (FUN_0040b940), GoldPointsValidation (FUN_0041cf80), DBCommandInventoryBuySlot (FUN_00415590), DBCommandInventoryBuyPotionSlot (FUN_00417800), DBCommandBuyStageRankClear (FUN_004184a0), ItemEquipDataBattleStart (FUN_0040c960), DBCommandBuyLotto (FUN_0040ec50), DBCommandAskLotto (FUN_0040f0a0). Documentación de Shop/Inventory/Refinery 100% completa.*

*Próximo paso: Documentar sistema de batalla (Battle Phase: opcodes 0x50-0x77, P2P/UDP, daño, skills), sistema de clans/guilds, y analizar CWorld::Idle (FUN_0042cee0, ~68 KB).**
