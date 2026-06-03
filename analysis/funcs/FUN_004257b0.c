
void __thiscall FUN_004257b0(void *this,uint param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  void *this_00;
  ushort uVar3;
  
  this_00 = (void *)(*(int *)((int)this + 0xd4) + (param_1 & 0xffff) * 0x23b4);
  uVar3 = (ushort)param_1;
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    FUN_0041eb20(this,uVar3,0xa6,'\x01',1);
  }
  else if (*(char *)((int)this_00 + 0x1440) == '\x03') {
    bVar1 = *param_3;
    if (0x13 < bVar1) {
      FUN_0041eb20(this,uVar3,0xa7,'\x01',1);
      return;
    }
    uVar2 = *(undefined4 *)(param_3 + 1);
    FUN_0040b7d0(this_00,(undefined2 *)&param_3,(undefined1 *)&param_1);
    FUN_004062c0((void *)(((uint)param_3 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4)),bVar1,uVar3
                 ,uVar2);
    return;
  }
  return;
}
