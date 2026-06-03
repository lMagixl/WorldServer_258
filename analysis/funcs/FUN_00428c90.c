
void __thiscall FUN_00428c90(void *this,uint param_1,undefined4 param_2,byte *param_3)

{
  void *this_00;
  byte bVar1;
  short sVar2;
  int iVar3;
  ushort uVar4;
  
  iVar3 = (param_1 & 0xffff) * 0x23b4;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + iVar3);
  uVar4 = (ushort)param_1;
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    FUN_0041eb20(this,uVar4,0xd0,'\x01',1);
  }
  else {
    if (*(char *)((int)this_00 + 0x1440) != '\x03') {
      FUN_0041eb20(this,uVar4,0xd1,'\x01',1);
      return;
    }
    bVar1 = *param_3;
    sVar2 = *(short *)(param_3 + 1);
    FUN_0040b7d0(this_00,(undefined2 *)&param_3,(undefined1 *)&param_1);
    iVar3 = FUN_0040e5f0((void *)(*(int *)((int)this + 0xd4) + iVar3),bVar1,sVar2,
                         *(char *)(((uint)param_3 & 0xffff) * 0x3c0 + 0x119 +
                                  *(int *)((int)this + 0xe4)));
    if (iVar3 == 0) {
      FUN_0041eb20(this,uVar4,0xd2,'\x01',1);
      return;
    }
  }
  return;
}
