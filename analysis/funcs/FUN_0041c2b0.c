
void __thiscall FUN_0041c2b0(void *this,ushort param_1,undefined4 param_2,undefined1 *param_3)

{
  void *this_00;
  void *local_4;
  
  this_00 = (void *)(*(int *)((int)this + 0xd4) + (uint)param_1 * 0x23b4);
  if (((*(int *)((int)this_00 + 0x1460) != 0) && (*(int *)((int)this_00 + 0x14a4) != 0)) &&
     (*(char *)((int)this_00 + 0x1440) == '\x03')) {
    param_1 = CONCAT11(param_1._1_1_,*param_3);
    local_4 = this;
    FUN_0040b7d0(this_00,(undefined2 *)&local_4,(undefined1 *)&param_3);
    FUN_00406930((void *)(((uint)local_4 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4)),
                 (undefined1 *)&param_3,(byte *)&param_1);
  }
  return;
}
