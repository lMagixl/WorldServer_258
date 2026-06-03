/* ============================================================
 * FUN_00420a40 — Game Opcode 0x1C Handler
 * Address: 00420a40
 * Signature: void __thiscall FUN_00420a40(void *this, ushort param_1, undefined4 param_2, LPCSTR param_3)
 * Called from: FUN_0042ab40 (main opcode dispatcher)
 * ============================================================
 * PURPOSE:
 *   Item buy (purchase from NPC shop) handler (opcode 0x1C). Processes
 *   a purchase request: validates session, parses the item name from
 *   the packet, resolves the item via FUN_0040bd80, then sends a DB
 *   command to add the item to the player's inventory.
 *
 * OPCODE: 0x1C (28)
 * PACKET STRUCTURE (in):
 *   param_1: client slot index (ushort)
 *   param_2: unknown (undefined4)
 *   param_3: item name string + extra data:
 *     [0..N-1]:     item name (null-terminated string)
 *     [N+1]:        cVar1 — item type/sub-op (char)
 *     [N+2..N+3]:   uVar2 — item index (ushort, if cVar1 != 0)
 *
 * PACKET STRUCTURE (out):
 *   On success via FUN_0041b940:
 *     Header:
 *       [0-1]: uStack_1004._0_2_ = session/sequence ID
 *       [2-3]: 0x0011 (sub-opcode = 17)
 *     Body:
 *       [4-7]: uStack_1000 = local_1018 (inventory slot ID)
 *       [8..]: item name string (copied via lstrcpyA)
 *       After string: cVar1 (item type)
 *       If cVar1 == 0x01:
 *         next 4 bytes: uStack_1020 (item data field 1)
 *         next 4 bytes: uStack_1024 (item data field 2)
 *         next 4 bytes: uStack_1028 (item data field 3)
 *         next 2 bytes: uVar2 (item original index)
 *     Total size: strlen(item_name) + 10 (basic) or + 24 (with extra data)
 *
 *   On failure via FUN_004038e0:
 *     [0-1]: 0x001c (error sub-opcode)
 *     [2]:   error code from FUN_0040bd80
 *
 *   On session inactive:
 *     FUN_0041eb20(this, param_1, 0x2c, 0x01, 1)
 *
 * KEY FUNCTIONS CALLED:
 *   - lstrcpyA / lstrlenA: string copy/length
 *   - FUN_0040bd80: item lookup/resolve by name + type (returns 0 on success)
 *   - FUN_0041b940: sends DB command to insert item into inventory
 *   - FUN_004038e0: sends error packet back to client
 *   - FUN_0041eb20: sends generic error/disconnect
 *   - FUN_00435e83: mutex unlock / cleanup
 *
 * INTERESTING STRINGS:
 *   - param_3 contains the item name (LPCSTR) — shop item names
 *     are passed directly from the client packet
 * ============================================================ */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00420a40(void *this,ushort param_1,undefined4 param_2,LPCSTR param_3)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uStack_1028;
  uint uStack_1024;
  undefined4 uStack_1020;
  char cStack_101c;
  undefined3 uStack_101b;
  undefined4 local_1018;
  CHAR local_1014 [16];
  undefined4 uStack_1004;
  undefined4 uStack_1000;
  CHAR aCStack_ffc [4088];
  int local_4;
  
  iVar6 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  if (*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar6) == 0) {
    FUN_0041eb20(this,param_1,0x2c,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  local_1018 = *(undefined4 *)(*(int *)((int)this + 0xd4) + iVar6 + 0x14a4);
  lstrcpyA(local_1014,param_3);
  iVar4 = lstrlenA(param_3);
  uVar2 = 0;
  uStack_1024 = 0;
  uStack_1020 = 0;
  uStack_1028 = 0;
  cVar1 = param_3[iVar4 + 1U & 0xffff];
  _cStack_101c = CONCAT31(uStack_101b,cVar1);
  if (cVar1 != '\0') {
    uVar2 = *(ushort *)(param_3 + (iVar4 + 2U & 0xffff));
  }
  uVar5 = FUN_0040bd80((void *)(*(int *)((int)this + 0xd4) + iVar6),cVar1,uVar2,&uStack_1020,
                       &uStack_1024,&uStack_1028);
  if ((char)uVar5 != '\0') {
    uStack_1004._2_2_ = CONCAT11(uStack_1004._3_1_,(char)uVar5);
    uStack_1004._0_2_ = 0x1c;
    FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,&uStack_1004);
    FUN_00435e83(local_4);
    return;
  }
  uStack_1004._0_2_ = *(undefined2 *)(*(int *)((int)this + 0xd4) + 0x1488 + iVar6);
  uStack_1004._2_2_ = 0x11;
  uStack_1000 = local_1018;
  lstrcpyA(aCStack_ffc,local_1014);
  iVar6 = lstrlenA(local_1014);
  uVar3 = (ushort)(iVar6 + 10U);
  *(char *)((int)&uStack_1004 + (iVar6 + 9U & 0xffff)) = cVar1;
  if (cVar1 == '\x01') {
    *(undefined4 *)((int)&uStack_1004 + (iVar6 + 10U & 0xffff)) = uStack_1020;
    *(uint *)((int)&uStack_1004 + (iVar6 + 0xeU & 0xffff)) = uStack_1024;
    *(uint *)((int)&uStack_1004 + (iVar6 + 0x12U & 0xffff)) = uStack_1028;
    *(ushort *)((int)&uStack_1004 + (iVar6 + 0x16U & 0xffff)) = uVar2;
    uVar3 = (short)iVar6 + 0x18;
  }
  FUN_0041b940(this,param_1,uVar3,&uStack_1004);
  FUN_00435e83(local_4);
  return;
}
