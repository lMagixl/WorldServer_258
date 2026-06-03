
void __thiscall FUN_00424210(void *this,uint param_1)

{
  void *pvVar1;
  ushort uVar2;
  void *local_4;
  
  pvVar1 = (void *)(*(int *)((int)this + 0xd4) + (param_1 & 0xffff) * 0x23b4);
  uVar2 = (ushort)param_1;
  local_4 = this;
  if ((*(int *)((int)pvVar1 + 0x1460) == 0) || (*(int *)((int)pvVar1 + 0x14a4) == 0)) {
    FUN_0041eb20(this,uVar2,0x77,'\x01',1);
    return;
  }
  if (*(char *)((int)pvVar1 + 0x1440) != '\x03') {
    FUN_0041eb20(this,uVar2,0x78,'\x01',1);
    return;
  }
  FUN_0040b7d0(pvVar1,(undefined2 *)&local_4,(undefined1 *)&param_1);
  pvVar1 = (void *)(((uint)local_4 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4));
  if ((char)param_1 != *(char *)((int)pvVar1 + 0x121)) {
    FUN_0041eb20(this,uVar2,0x79,'\x01',1);
    return;
  }
  FUN_004079d0(pvVar1);
  return;
}
