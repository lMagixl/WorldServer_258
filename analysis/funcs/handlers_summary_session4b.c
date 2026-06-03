// Game opcode 0x12 — Character Create / Inventory Enter?
// Signature: void __thiscall FUN_0041fcd0(void* this, ushort fieldIdx, uint data_size, LPCSTR data)
// Pushes DB opcode 7 (char create) with: [counter:2][7:2][userId:4][username\0][class:1][slot:1]
// Validates field+0x1460 (loginId) non-zero and field+0x14a4 == 0

// Game opcode 0x13 — Character Delete
// Signature: void __thiscall FUN_0041fe10(void* this, ushort fieldIdx, uint data_size, uint* data)
// Pushes DB opcode 8 (char delete) with: [counter:2][8:2][charId:4][name\0]

// Game opcode 0x14 — Character Select
// Signature: void __thiscall FUN_0041fef0(void* this, uint fieldIdx, uint data_size, int* data)
// Selects character from field slot array (0xD8 entries * 0x360 bytes per slot)
// Calls: FUN_0040be30 (load char), FUN_0040d3f0 (access check), FUN_0040ac30 (notification)
// Input: param_3[0] = charId

// Game opcode 0x09 — Item Info Display
// Signature: void __thiscall FUN_0041f5c0(void* this, ushort fieldIdx, uint data_size, ushort* data)
// Uses item array at this+0xE4 (items of 0x3C0 bytes each)
// Reads: param_3[0] = item index
// Checks if index < maxItems, validates item state
// Sends: [opcode=9:2][state:1][itemData:N]

// Game opcode 0x0B — MD5 Config Setup
// Signature: void __thiscall FUN_0041f480(void* this, ushort fieldIdx, uint data_size, LPCSTR data)
// Sets MD5_1 and MD5_2 in CWorld (this+300 and this+0x14D)
// Input: [string1\0][string2\0]
// Output: [opcode=0x0B:2][result:1][MD5_1\0][MD5_2\0]

// DB opcode 0x10 — Character State Clear / Level Up  
// Signature: void __thiscall FUN_00413cd0(void* this, ushort fieldIdx, ushort retOpcode, uint dataSize, uint* data)
// Input: [userId:4][cmdType:1][... cmd-specific data]
// Queries: SELECT level, powerlevelpoint, ... FROM usergameinfo WHERE id=<userId>
// Handles power level point distribution and cash deduction
// Supports coupon usage (logcoupon table)
// If cmdType == 0x01: reads additional fields for item coupon

// DB opcode 0x2A — Lotto Results Query
// Input: [lottoId:4][pageNo:1]
// Queries: SELECT no, no1..no5, ... FROM loglottery

// DB opcode 0x29 — Buy Lotto Ticket
// Input: [userId:4][?]
// Checks gold/cash, INSERT INTO lotto

// DB opcode 0x2B — Clan/Buddy List
// Input: [userId:4][charId:4]
// Queries: SELECT name, buddyname FROM usergameinfo WHERE ...
// Returns: clan/buddy name list
