
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_004225d0(void *this,ushort param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  ushort uVar2;
  ushort local_1008;
  undefined2 local_1004;
  undefined2 local_1002;
  int local_1000;
  ushort local_ffc;
  int local_4;
  
  local_4 = DAT_00454928;
  iVar1 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  local_1000 = *(int *)(iVar1 + 0x1460);
  if ((local_1000 == 0) || (*(int *)(iVar1 + 0x14a4) == 0)) {
    uVar2 = 0xe8;
  }
  else {
    if (*(char *)(iVar1 + 0x1440) == '\x02') {
      local_1004 = *(undefined2 *)(iVar1 + 0x1488);
      local_1008 = (ushort)*param_3;
      local_1002 = 0x2a;
      local_ffc = local_1008;
      FUN_0041b940(this,param_1,10,(undefined4 *)&local_1004);
      FUN_00435e83(local_4);
      return;
    }
    uVar2 = 0xe9;
  }
  FUN_0041eb20(this,param_1,uVar2,'\x01',1);
  FUN_00435e83(local_4);
  return;
}


