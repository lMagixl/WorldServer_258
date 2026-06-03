
void __thiscall FUN_00424100(void *this,uint param_1,undefined4 param_2,byte *param_3)

{
  byte *pbVar1;
  byte bVar2;
  void *pvVar3;
  ushort uVar4;
  ushort local_8 [2];
  byte local_4;
  undefined3 uStack_3;
  
  pvVar3 = (void *)(*(int *)((int)this + 0xd4) + (param_1 & 0xffff) * 0x23b4);
  uVar4 = (ushort)param_1;
  if ((*(int *)((int)pvVar3 + 0x1460) == 0) || (*(int *)((int)pvVar3 + 0x14a4) == 0)) {
    FUN_0041eb20(this,uVar4,0x73,'\x01',1);
    return;
  }
  if (*(char *)((int)pvVar3 + 0x1440) != '\x03') {
    FUN_0041eb20(this,uVar4,0x74,'\x01',1);
    return;
  }
  FUN_0040b7d0(pvVar3,local_8,(undefined1 *)&param_1);
  pvVar3 = (void *)((uint)local_8[0] * 0x3c0 + *(int *)((int)this + 0xe4));
  if ((char)param_1 != *(char *)((int)pvVar3 + 0x121)) {
    FUN_0041eb20(this,uVar4,0x75,'\x01',1);
    return;
  }
  bVar2 = *param_3;
  _local_4 = CONCAT31(uStack_3,bVar2);
  if ((((bVar2 < 0x14) && (bVar2 != 8)) && (bVar2 != 9)) && ((bVar2 != 0x12 && (bVar2 != 0x13)))) {
    pbVar1 = param_3 + 1;
    param_3 = (byte *)CONCAT31(param_3._1_3_,*pbVar1);
    FUN_00407910(pvVar3,bVar2,*pbVar1);
    return;
  }
  FUN_0041eb20(this,uVar4,0x76,'\x01',1);
  return;
}
