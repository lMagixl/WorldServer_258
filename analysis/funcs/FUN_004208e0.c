/* ============================================================
 * FUN_004208e0 — Game Opcode 0x1B Handler
 * Address: 004208e0
 * Signature: void __thiscall FUN_004208e0(void *this, ushort param_1, undefined4 param_2, char *param_3)
 * Called from: FUN_0042ab40 (main opcode dispatcher)
 * ============================================================
 * PURPOSE:
 *   Item buyback / repurchase handler (opcode 0x1B). Allows a player
 *   to repurchase a recently sold-back item. Looks up the item via
 *   FUN_0040bd80 (inventory/item lookup), then sends a DB command
 *   to restore it to the player's inventory.
 *
 * OPCODE: 0x1B (27)
 * PACKET STRUCTURE (in):
 *   param_1: client slot index (ushort)
 *   param_2: unknown (undefined4)
 *   param_3: packed data:
 *     [0]:    cVar1 — item type/sub-op (char)
 *     [1-2]:  uVar4 — item index/ID (ushort)
 *
 * PACKET STRUCTURE (out):
 *   On success via FUN_0041b940:
 *     Header (4 bytes):
 *       [0-1]: local_1004 = session/sequence ID (from this+0xd4+0x1488)
 *       [2-3]: sub-opcode (0x10 = 16 for basic, 0x17 = 23 for item with extra data)
 *     Body:
 *       local_1000 = local_1008 (item context/inventory slot id from player struct)
 *       local_ffc = cVar1 (item type)
 *       If cVar1 == 0x01 (type 1 / equipment):
 *         local_ffb = local_1010 (item data field 1)
 *         local_ff7 = local_1014 (item data field 2)
 *         local_ff3 = local_1018 (item data field 3)
 *         local_fef = uVar4 (item original index)
 *
 *   On failure via FUN_004038e0:
 *     [0-1]: 0x001b (error sub-opcode)
 *     [2]:   error code from FUN_0040bd80 return value
 *
 *   On session inactive:
 *     FUN_0041eb20(this, param_1, 0x2b, 0x01, 1)
 *
 * KEY FUNCTIONS CALLED:
 *   - FUN_0040bd80: item lookup/resolve (returns 0 on success, non-zero on error)
 *   - FUN_0041b940: sends DB command to execute buyback
 *   - FUN_004038e0: sends error packet back to client (3 bytes)
 *   - FUN_0041eb20: sends generic error/disconnect
 *   - FUN_00435e83: mutex unlock / cleanup
 * ============================================================ */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_004208e0(void *this,ushort param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  void *this_00;
  ushort uVar4;
  int iVar5;
  uint local_1018;
  uint local_1014;
  undefined4 local_1010;
  char local_100c;
  undefined3 uStack_100b;
  undefined4 local_1008;
  undefined2 local_1004;
  undefined2 local_1002;
  undefined4 local_1000;
  char local_ffc;
  undefined4 local_ffb;
  uint local_ff7;
  uint local_ff3;
  ushort local_fef;
  int local_4;
  
  local_4 = DAT_00454928;
  iVar5 = (uint)param_1 * 0x23b4;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + iVar5);
  uVar4 = 0;
  if (*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar5) == 0) {
    FUN_0041eb20(this,param_1,0x2b,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  cVar1 = *param_3;
  local_1014 = 0;
  local_1010 = 0;
  local_1018 = 0;
  _local_100c = CONCAT31(uStack_100b,cVar1);
  if (cVar1 != '\0') {
    uVar4 = *(ushort *)(param_3 + 1);
  }
  local_1008 = *(undefined4 *)((int)this_00 + 0x14a4);
  uVar3 = FUN_0040bd80(this_00,cVar1,uVar4,&local_1010,&local_1014,&local_1018);
  if ((char)uVar3 == '\0') {
    local_1004 = *(undefined2 *)(*(int *)((int)this + 0xd4) + 0x1488 + iVar5);
    local_1002 = 0x10;
    local_1000 = local_1008;
    uVar2 = 9;
    if (cVar1 == '\x01') {
      local_ff7 = local_1014;
      local_ffb = local_1010;
      local_ff3 = local_1018;
      uVar2 = 0x17;
      local_fef = uVar4;
    }
    local_ffc = cVar1;
    FUN_0041b940(this,param_1,uVar2,(undefined4 *)&local_1004);
  }
  else {
    local_1002 = CONCAT11(local_1002._1_1_,(char)uVar3);
    local_1004 = 0x1b;
    FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)&local_1004);
  }
  FUN_00435e83(local_4);
  return;
}
