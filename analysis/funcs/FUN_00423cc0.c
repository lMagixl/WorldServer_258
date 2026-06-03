
void __thiscall FUN_00423cc0(void *this,uint param_1,undefined4 param_2,byte *param_3)

{
  void *this_00;
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  ushort uVar5;
  ushort local_8 [2];
  undefined4 local_4;
  
  iVar4 = (param_1 & 0xffff) * 0x23b4;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + iVar4);
  uVar5 = (ushort)param_1;
  if ((*(int *)((int)this_00 + 0x1460) != 0) && (*(int *)((int)this_00 + 0x14a4) != 0)) {
    if (*(char *)((int)this_00 + 0x1440) != '\x03') {
      FUN_0041eb20(this,uVar5,0x68,'\x01',1);
      return;
    }
    FUN_0040b7d0(this_00,local_8,(undefined1 *)&param_1);
    cVar1 = *(char *)(*(int *)((int)this + 0xd4) + 0x146c + iVar4);
    uVar3 = CONCAT22((short)((uint)*(int *)((int)this + 0xd4) >> 0x10),local_8[0]);
    if ((cVar1 != '4') && (cVar1 != '\x01')) {
      local_4 = uVar3;
      if ((char)param_1 != *(char *)((uint)local_8[0] * 0x3c0 + 0x121 + *(int *)((int)this + 0xe4)))
      {
        FUN_0041eb20(this,uVar5,0x69,'\x01',1);
        return;
      }
    }
    bVar2 = *param_3;
    param_3 = (byte *)CONCAT31(param_3._1_3_,bVar2);
    FUN_004097c0((void *)((uint)local_8[0] * 0x3c0 + *(int *)((int)this + 0xe4)),bVar2);
    return;
  }
  FUN_0041eb20(this,uVar5,0x67,'\x01',1);
  return;
}
