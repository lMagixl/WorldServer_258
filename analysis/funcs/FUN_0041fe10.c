
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041fe10(void *this,ushort param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined2 local_1004;
  undefined2 local_1002;
  int local_1000;
  undefined4 local_ffc;
  CHAR local_ff8 [4084];
  int local_4;
  
  local_4 = DAT_00454928;
  iVar1 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  local_1000 = *(int *)(iVar1 + 0x1460);
  if ((local_1000 != 0) && (*(int *)(iVar1 + 0x14a4) == 0)) {
    local_1004 = *(undefined2 *)(iVar1 + 0x1488);
    local_ffc = *param_3;
    local_1002 = 8;
    lstrcpynA(local_ff8,(LPCSTR)(param_3 + 1),0xb);
    lstrlenA(local_ff8);
    iVar1 = lstrlenA(local_ff8);
    FUN_0041b940(this,param_1,(short)iVar1 + 0xd,(undefined4 *)&local_1004);
    FUN_00435e83(local_4);
    return;
  }
  FUN_0041eb20(this,param_1,0x1c,'\x01',1);
  FUN_00435e83(local_4);
  return;
}


