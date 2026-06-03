
void __thiscall FUN_00423c00(void *this,uint param_1)

{
  void *this_00;
  int iVar1;
  ushort uVar2;
  void *local_4;
  
  iVar1 = (param_1 & 0xffff) * 0x23b4;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + iVar1);
  uVar2 = (ushort)param_1;
  local_4 = this;
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    FUN_0041eb20(this,uVar2,100,'\x01',1);
    return;
  }
  if (*(char *)((int)this_00 + 0x1440) != '\x03') {
    FUN_0041eb20(this,uVar2,0x65,'\x01',1);
    return;
  }
  FUN_0040b7d0(this_00,(undefined2 *)&local_4,(undefined1 *)&param_1);
  if (*(char *)(*(int *)((int)this + 0xd4) + 0x146c + iVar1) != '4') {
    FUN_0041eb20(this,uVar2,0x66,'\x01',1);
    return;
  }
  FUN_00405740(((uint)local_4 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4));
  return;
}
