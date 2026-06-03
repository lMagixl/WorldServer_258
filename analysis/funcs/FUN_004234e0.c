
void __thiscall FUN_004234e0(void *this,uint param_1)

{
  uint uVar1;
  void *this_00;
  void *local_4;
  
  uVar1 = param_1;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + (param_1 & 0xffff) * 0x23b4);
  local_4 = this;
  if ((*(int *)((int)this_00 + 0x1460) != 0) && (*(int *)((int)this_00 + 0x14a4) != 0)) {
    if (*(char *)((int)this_00 + 0x1440) != '\x03') {
      FUN_0041eb20(this,(ushort)param_1,0x51,'\x01',1);
      return;
    }
    FUN_0040b7d0(this_00,(undefined2 *)&param_1,(undefined1 *)&local_4);
    FUN_004091e0((void *)((param_1 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4)),(byte)local_4);
    FUN_0041b8b0(this,uVar1);
    return;
  }
  FUN_0041eb20(this,(ushort)param_1,0x50,'\x01',1);
  return;
}
