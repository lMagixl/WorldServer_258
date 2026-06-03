
void __thiscall FUN_00425990(void *this,uint param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  void *pvVar2;
  ushort uVar3;
  void *local_4;
  
  pvVar2 = (void *)((param_1 & 0xffff) * 0x23b4 + *(int *)((int)this + 0xd4));
  uVar3 = (ushort)param_1;
  local_4 = this;
  if ((*(int *)((int)pvVar2 + 0x1460) == 0) || (*(int *)((int)pvVar2 + 0x14a4) == 0)) {
    FUN_0041eb20(this,uVar3,0xaa,'\x01',1);
  }
  else {
    if (*(char *)((int)pvVar2 + 0x1440) != '\x03') {
      FUN_0041eb20(this,uVar3,0xab,'\x01',1);
      return;
    }
    if (*(char *)((int)pvVar2 + 0x146c) != '\x01') {
      FUN_0041eb20(this,uVar3,0xac,'\x01',1);
      return;
    }
    FUN_0040b7d0(pvVar2,(undefined2 *)&local_4,(undefined1 *)&param_1);
    pvVar2 = (void *)(*(int *)((int)this + 0xe4) + ((uint)local_4 & 0xffff) * 0x3c0);
    if (((*(char *)((int)pvVar2 + 8) != '\x02') && ((char)param_1 == *(char *)((int)pvVar2 + 0x121))
        ) && (bVar1 = *param_3, param_3 = (byte *)CONCAT31(param_3._1_3_,bVar1), bVar1 < 0x12)) {
      FUN_00409080(pvVar2,bVar1);
      return;
    }
  }
  return;
}
