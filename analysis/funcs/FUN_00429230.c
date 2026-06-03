
void __thiscall FUN_00429230(void *this,uint param_1)

{
  void *this_00;
  ushort uVar1;
  undefined4 uStack_4;
  
  this_00 = (void *)(*(int *)((int)this + 0xd4) + (param_1 & 0xffff) * 0x23b4);
  uVar1 = (ushort)param_1;
  uStack_4 = this;
  if ((*(int *)((int)this_00 + 0x1460) != 0) && (*(int *)((int)this_00 + 0x14a4) != 0)) {
    FUN_0040af90(this_00,(undefined1 *)&param_1,(undefined1 *)((int)&uStack_4 + 3));
    FUN_00404da0((void *)((param_1 & 0xff) * 0x358 + *(int *)((int)this + 0xdc)),uVar1);
    return;
  }
  FUN_0041eb20(this,uVar1,0xdd,'\x01',1);
  return;
}
