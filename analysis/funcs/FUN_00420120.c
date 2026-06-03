/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00420120(void *this,ushort param_1,undefined4 param_2,LPCSTR param_3)

{
  int iVar1;
  undefined2 local_1004;
  undefined2 local_1002;
  int local_1000;
  CHAR local_ffc [4088];
  int local_4;
  
  local_4 = DAT_00454928;
  iVar1 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  local_1000 = *(int *)(iVar1 + 0x1460);
  if (local_1000 == 0) {
    FUN_0041eb20(this,param_1,0x1f,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  local_1004 = *(undefined2 *)(iVar1 + 0x1488);
  local_1002 = 0xb;
  iVar1 = lstrlenA(param_3);
  if (iVar1 < 0xd) {
    lstrcpyA(local_ffc,param_3);
    iVar1 = lstrlenA(local_ffc);
    FUN_0041b940(this,param_1,(short)iVar1 + 9,(undefined4 *)&local_1004);
  }
  else {
    FUN_0041eb20(this,param_1,0x20,'\x01',1);
  }
  FUN_00435e83(local_4);
  return;
}
