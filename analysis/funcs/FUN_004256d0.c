
void __thiscall FUN_004256d0(void *this,uint param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  void *this_00;
  undefined2 extraout_var;
  ushort uVar4;
  void *local_4;
  
  this_00 = (void *)(*(int *)((int)this + 0xd4) + (param_1 & 0xffff) * 0x23b4);
  uVar4 = (ushort)param_1;
  local_4 = this;
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    FUN_0041eb20(this,uVar4,0xa3,'\x01',1);
  }
  else if (*(char *)((int)this_00 + 0x1440) == '\x03') {
    FUN_0040b7d0(this_00,(undefined2 *)&param_1,(undefined1 *)&local_4);
    pbVar3 = param_3;
    bVar1 = *param_3;
    param_3 = (byte *)CONCAT31(param_3._1_3_,bVar1);
    if (0x13 < bVar1) {
      FUN_0041eb20(this,uVar4,0xa4,'\x01',1);
      return;
    }
    uVar2 = *(ushort *)(pbVar3 + 1);
    if (1000 < uVar2) {
      FUN_0041eb20(this,uVar4,0xa5,'\x01',1);
      return;
    }
    FUN_004060a0((void *)((param_1 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4)),(byte)local_4,
                 bVar1,CONCAT22(extraout_var,uVar2),(undefined4 *)(pbVar3 + 3));
    return;
  }
  return;
}
