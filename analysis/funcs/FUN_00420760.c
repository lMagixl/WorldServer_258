/* ============================================================
 * FUN_00420760 — Game Opcode 0x19 Handler
 * Address: 00420760
 * Signature: void __thiscall FUN_00420760(void *this, ushort param_1, undefined4 param_2, LPCSTR param_3)
 * Called from: FUN_0042ab40 (main opcode dispatcher)
 * ============================================================
 * PURPOSE:
 *   Character name change handler. Validates that the player session
 *   is active, checks the new name length (< 13 chars), sends a DB
 *   command to update the name, and either rejects or accepts.
 *
 * OPCODE: 0x19 (25)
 * PACKET STRUCTURE (in):
 *   param_1: client slot index (ushort)
 *   param_2: unknown (undefined4)
 *   param_3: new character name string (LPCSTR)
 *
 * PACKET STRUCTURE (out via FUN_0041b940):
 *   On success:
 *     - 2 bytes: uStack_1004 (session/sequence ID from this+0xd4 + 0x1488)
 *     - 2 bytes: 0x0d (sub-opcode length = 13)
 *     - N bytes: new name string (char[])
 *     Total header size: (strlen(param_3) + 5)
 *   On validation failure:
 *     - FUN_0041eb20(this, param_1, 0x29, 0x01, 1) — sends error 0x29
 *   On session inactive:
 *     - FUN_0041eb20(this, param_1, 0x28, 0x01, 1) — sends error 0x28
 * ============================================================ */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00420760(void *this,ushort param_1,undefined4 param_2,LPCSTR param_3)

{
  int iVar1;
  undefined2 uStack_1004;
  undefined2 uStack_1002;
  CHAR aCStack_1000 [4092];
  int local_4;
  
  local_4 = DAT_00454928;
  if (*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + (uint)param_1 * 0x23b4) == 0) {
    FUN_0041eb20(this,param_1,0x28,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  iVar1 = lstrlenA(param_3);
  if (iVar1 < 0xd) {
    uStack_1004 = *(undefined2 *)(*(int *)((int)this + 0xd4) + 0x1488 + (uint)param_1 * 0x23b4);
    uStack_1002 = 0xd;
    lstrcpyA(aCStack_1000,param_3);
    iVar1 = lstrlenA(param_3);
    FUN_0041b940(this,param_1,(short)iVar1 + 5,(undefined4 *)&uStack_1004);
  }
  else {
    FUN_0041eb20(this,param_1,0x29,'\x01',1);
  }
  FUN_00435e83(local_4);
  return;
}
