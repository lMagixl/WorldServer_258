
// Opcode 0x04 — DB Command Sender (username query)
// Signature: void __thiscall FUN_0041f1a0(void* this, ushort fieldIdx, uint param_3, undefined1* param_4)
// Reads field+0x1488 counter, first byte = flag, then username string.
// Calls FUN_0041b940 to push to DbSendQueue (this + 0xfc).

void __thiscall FUN_0041f1a0(void *this,ushort param_1,undefined4 param_2,undefined1 *param_3)
{
  int iVar1;
  undefined2 local_1004;
  undefined2 local_1002;
  undefined1 local_1000;
  CHAR local_fff [4091];
  int local_4;

  local_4 = DAT_00454928;
  iVar1 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  if (((*(char *)(iVar1 + 0x1440) != '\x05') && (*(char *)(iVar1 + 0x146c) != '\x01')) &&
     (*(char *)(iVar1 + 0x146c) != '4')) {
    FUN_0041eb20(this,param_1,0xb,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  local_1004 = *(undefined2 *)(iVar1 + 0x1488);
  local_1000 = *param_3;
  local_1002 = 1;
  iVar1 = lstrlenA(param_3 + 1);
  if (iVar1 < 0xd) {
    lstrcpyA(local_fff,param_3 + 1);
    iVar1 = lstrlenA(local_fff);
    FUN_0041b940(this,param_1,(short)iVar1 + 6,(undefined4 *)&local_1004);
  }
  else {
    FUN_0041eb20(this,param_1,0xc,'\x01',1);
  }
  FUN_00435e83(local_4);
  return;
}
