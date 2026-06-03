
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_004229f0(void *this,ushort param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  uint uVar2;
  ushort uVar3;
  void *this_00;
  undefined2 local_1010 [2];
  short local_100c [2];
  undefined2 local_1008 [2];
  undefined2 local_1004;
  char local_1002;
  undefined2 local_1001;
  undefined2 local_fff;
  undefined1 local_ffd;
  short local_ffc;
  int local_4;
  
  local_4 = DAT_00454928;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + (uint)param_1 * 0x23b4);
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    uVar3 = 0x43;
  }
  else {
    if (*(char *)((int)this_00 + 0x1440) == '\x02') {
      uVar1 = *param_3;
      local_100c[0]._0_1_ = uVar1;
      uVar2 = FUN_0040b3d0(this_00,uVar1,local_1008,local_1010,local_100c);
      local_1002 = (char)uVar2;
      local_1004 = 0x33;
      uVar3 = 3;
      if (local_1002 == '\0') {
        local_fff = local_1010[0];
        local_1001 = local_1008[0];
        local_ffc = local_100c[0];
        uVar3 = 10;
        local_ffd = uVar1;
      }
      FUN_004038e0(*(void **)((int)this + 0x118),param_1,uVar3,(undefined4 *)&local_1004);
      FUN_00435e83(local_4);
      return;
    }
    uVar3 = 0x44;
  }
  FUN_0041eb20(this,param_1,uVar3,'\x01',1);
  FUN_00435e83(local_4);
  return;
}
