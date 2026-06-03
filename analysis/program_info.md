# RakionWorldServ.exe — Program Info

| Campo | Valor |
|-------|-------|
| Archivo | `RakionWorldServ.exe` |
| Tamaño | 352,531 bytes (344.3 KB) |
| Arquitectura | PE32, x86 (32-bit), Intel 80386 |
| Compiler | MSVC (Visual C++) |
| Timestamp | 2007-11-19 05:12:44 |
| MD5 | d9402e4bcff885e2ad8cdd4a67f8e3f8 |
| SHA256 | e4835ab326f745541cb0a21ac52e3b2ea0ffe989040193c8019c7244ebd2e81f |
| PDB path | `d:\Rakion\Debug\SoftnyxServerSuite_071119\RakionWorldServer\Release\RakionWorldServer.pdb` |
| ImageBase | 0x00400000 |
| Entry Point | 0x00436E31 |
| Funciones totales | 1,046 (1,208 con thunks/thunks) |
| Función más grande | FUN_0042cee0 (68 KB) — probablemente `CWorld::Idle` |

## Segmentos PE

| Sección | VA Start | VA End | Tamaño | Flags |
|---------|----------|--------|--------|-------|
| Headers | 0x00400000 | 0x00400fff | 4 KB | — |
| .text | 0x00401000 | 0x00441fff | ~262 KB | Execute/Read |
| .rdata | 0x00442000 | 0x00452fff | ~68 KB | Read/Data |
| .data | 0x00453000 | 0x00459a63 | ~27 KB | Read/Write |
| .Silvana | 0x0045a000 | 0x0045afff | 4 KB | Read/Write (custom — posiblemente config cifrada) |
| tdb | 0xffdff000 | 0xffdfffff | 4 KB | Debug data |

## PRTCLIB Crypto Layer (WorldServerDll.dll)

| Función | Dirección | Propósito |
|---------|-----------|-----------|
| `FUN_004304f0` | 0x004304f0 | LoadLibrary("WorldServerDll.dll") + GetProcAddress |
| `PrtcGetVersion` | (external) | Versión del protocolo |
| `PrtcEncryptQuery` | (external, struct+0x24) | **AES-ECB 0x7FC4 encrypt saliente** |
| `PrtcDecryptAnswer` | (external, struct+0x28) | **AES-ECB 0x7FC4 decrypt entrante** |
| `PrtcGetAuthQuery` | (external, struct+0x1C) | Auth query |
| `PrtcCheckAuthAnswer` | (external, struct+0x20) | Auth response check |
| `PrtcUpdateTimer` | (external, struct+0x2C) | Protocol timer |

## Dispatch Tables

| Tabla | Función | # Opcodes | Archivo |
|-------|---------|-----------|---------|
| Game Dispatcher | `FUN_0042ab40` | 86 | `03_packet_opcodes.md` |
| DBWorker | `FUN_0041ae50` | 40 | `01_functions_list.md` |
| DB Response | `FUN_004295c0` | 30+ | `01_functions_list.md` |
| PRTCLIB Loader | `FUN_004304f0` | 6 funciones Prtc* | `RAKION_RE_MASTER.md` |

## Archivos Relacionados
- `01_functions_list.md` — lista completa de 1,046 funciones con nombres reales anotados
- `03_packet_opcodes.md` — tabla de 86 opcodes de red con handlers y nombres
- `login_flow.md` — flujo completo de login (game → DB → DB Response → cliente)
- `SESSION_LOG.md` — historial de sesiones de análisis (Sesión 6: PRTCLIB crypto)
- `RAKION_RE_MASTER.md` — documento maestro de RE (arquitectura, estructuras, DB, PRTCLIB)
- `funcs/*.c` — 151 archivos de funciones decompiladas (~700 KB)
- `character_management.md` — [ES] análisis COMPLETO de Character Management (1668 líneas, BD, slots, gold/cash/pets)
- `lobby_phase.md` — [ES] fase Lobby/Sala completa (737 líneas, 14 opcodes)

## Actualizado en Sesión 7
- `character_management.md` — expandido 1214→1668 líneas con BD completa, slot 0x360, gold/cash/pets
- `RAKION_RE_MASTER.md` — Sesión 7 añadida, refs cruzadas, conteo actualizado
- `SESSION_LOG.md` — Sesión 7 añadida
- `program_info.md` — conteo .c (128→151), refs a character_management.md y lobby_phase.md

### Actualizado en Sesión 6
- `RAKION_RE_MASTER.md` — Sesión 6, PRTCLIB struct, pipeline con decrypt/encrypt, correcciones
- `03_packet_opcodes.md` — frame format corregido (ushort opcode), correcciones en descripciones
- `01_functions_list.md` — PRTCLIB functions añadidas
- `login_flow.md` — pipeline actualizado con PRTCLIB decrypt/encrypt, dual path login (admin vs normal)
- `SESSION_LOG.md` — Sesión 6 añadida
