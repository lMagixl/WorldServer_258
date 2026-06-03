
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041bde0(void *this,ushort param_1)

{
  int iVar1;
  undefined2 local_1004;
  undefined2 local_1002;
  undefined4 local_1000;
  undefined4 local_ffc;
  int local_4;
  
  local_4 = DAT_00454928;
  iVar1 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  local_1000 = *(undefined4 *)(iVar1 + 0x1460);
  local_ffc = *(undefined4 *)(iVar1 + 0x14d0);
  local_1004 = *(undefined2 *)(iVar1 + 0x1488);
  local_1002 = 0x2c;
  FUN_0041b940(this,param_1,0xc,(undefined4 *)&local_1004);
  FUN_00435e83(local_4);
  return;
}


