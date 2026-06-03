
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_004286a0(void *this,ushort param_1)

{
  int iVar1;
  undefined2 local_1004;
  undefined2 local_1002;
  int local_1000;
  int local_4;
  
  local_4 = DAT_00454928;
  iVar1 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  local_1000 = *(int *)(iVar1 + 0x1460);
  if ((local_1000 != 0) && (*(int *)(iVar1 + 0x14a4) != 0)) {
    local_1004 = *(undefined2 *)(iVar1 + 0x1488);
    local_1002 = 0x1e;
    FUN_0041b940(this,param_1,8,(undefined4 *)&local_1004);
    FUN_00435e83(local_4);
    return;
  }
  FUN_0041eb20(this,param_1,0xc2,'\x01',1);
  FUN_00435e83(local_4);
  return;
}
