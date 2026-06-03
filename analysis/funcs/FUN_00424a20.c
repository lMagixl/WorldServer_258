
void __thiscall FUN_00424a20(void *this,uint param_1,undefined4 param_2,byte *param_3)

{
  void *this_00;
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  ushort uVar5;
  byte local_4 [4];
  
  iVar4 = (param_1 & 0xffff) * 0x23b4;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + iVar4);
  uVar5 = (ushort)param_1;
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    FUN_0041eb20(this,uVar5,0x8f,'\x01',1);
    return;
  }
  if (*(char *)((int)this_00 + 0x1440) != '\x03') {
    FUN_0041eb20(this,uVar5,0x90,'\x01',1);
    return;
  }
  FUN_0040b7d0(this_00,(undefined2 *)&param_1,local_4);
  bVar1 = *param_3;
  if (8 < bVar1) {
    FUN_0041eb20(this,uVar5,0x91,'\x01',1);
    return;
  }
  bVar2 = param_3[1];
  param_3 = (byte *)CONCAT31(param_3._1_3_,bVar2);
  if (0x13 < bVar2) {
    FUN_0041eb20(this,uVar5,0x92,'\x01',1);
    return;
  }
  cVar3 = *(char *)((param_1 & 0xffff) * 0x3c0 + 0x119 + *(int *)((int)this + 0xe4));
  if ((cVar3 == '\x02') || (cVar3 == '\x03')) {
    iVar4 = *(int *)((int)this + 0xd4) + iVar4;
    *(undefined4 *)(iVar4 + 0x2395) = 0;
    *(undefined2 *)(iVar4 + 0x2399) = 0;
  }
  FUN_004087d0((void *)((param_1 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4)),local_4[0],bVar1,
               bVar2);
  return;
}
