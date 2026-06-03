
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_004293f0(void *this,ushort param_1)

{
  int iVar1;
  ushort uVar2;
  undefined2 local_1004;
  undefined2 local_1002;
  int local_1000;
  int local_ffc;
  undefined4 local_ff8;
  undefined2 local_ff4;
  int local_4;
  
  local_4 = DAT_00454928;
  iVar1 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  local_1000 = *(int *)(iVar1 + 0x1460);
  if ((local_1000 == 0) || (local_ffc = *(int *)(iVar1 + 0x14a4), local_ffc == 0)) {
    uVar2 = 0xdb;
  }
  else {
    if (*(char *)(iVar1 + 0x1440) == '\x02') {
      local_1004 = *(undefined2 *)(iVar1 + 0x1488);
      local_ff8 = *(undefined4 *)(*(int *)((int)this + 0x10c) + 0x4e3c8);
      local_1002 = 0x24;
      local_ff4 = 0x271e;
      FUN_0041b940(this,param_1,0x12,(undefined4 *)&local_1004);
      FUN_00435e83(local_4);
      return;
    }
    uVar2 = 0xdc;
  }
  FUN_0041eb20(this,param_1,uVar2,'\x01',1);
  FUN_00435e83(local_4);
  return;
}


