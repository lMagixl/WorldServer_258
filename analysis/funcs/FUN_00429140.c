
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00429140(void *this,ushort param_1,undefined4 param_2,ushort *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  undefined4 local_1004;
  int local_4;
  
  local_4 = DAT_00454928;
  if (*(char *)((uint)param_1 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4)) != '\x05') {
    FUN_0041eb20(this,param_1,200,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  local_1004._2_2_ = *param_3;
  uVar3 = 2;
  local_1004._0_2_ = 10;
  uVar5 = 4;
  for (uVar1 = (uint)local_1004._2_2_; uVar1 != 0; uVar1 = uVar1 - 1) {
    uVar4 = *(uint *)((uVar3 & 0xffff) + (int)param_3);
    uVar3 = uVar3 + 4;
    if (uVar4 < 0x200) {
      uVar2 = *(undefined4 *)((int)this + uVar4 * 4 + 0x51c8);
    }
    else {
      uVar2 = 0;
    }
    uVar4 = (uint)uVar5;
    uVar5 = uVar5 + 4;
    *(undefined4 *)((int)&local_1004 + uVar4) = uVar2;
  }
  FUN_004038e0(*(void **)((int)this + 0x118),param_1,uVar5,&local_1004);
  FUN_00435e83(local_4);
  return;
}
