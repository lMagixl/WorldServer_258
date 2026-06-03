
void __thiscall FUN_00424980(void *this,uint param_1,undefined4 param_2,short *param_3)

{
  void *this_00;
  void *local_4;
  
  this_00 = (void *)((param_1 & 0xffff) * 0x23b4 + *(int *)((int)this + 0xd4));
  local_4 = this;
  if ((*(int *)((int)this_00 + 0x1460) != 0) && (*(int *)((int)this_00 + 0x14a4) != 0)) {
    if (*(char *)((int)this_00 + 0x1440) != '\x03') {
      FUN_0041eb20(this,(ushort)param_1,0x8e,'\x01',1);
      return;
    }
    FUN_0040b7d0(this_00,(undefined2 *)&local_4,(undefined1 *)&param_1);
    FUN_00405d70((void *)(((uint)local_4 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4)),*param_3,
                 param_3[1]);
    return;
  }
  FUN_0041eb20(this,(ushort)param_1,0x8d,'\x01',1);
  return;
}
