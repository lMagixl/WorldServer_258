
void __thiscall FUN_0041bc10(void *this,ushort param_1)

{
  void *this_00;
  int iVar1;
  void *local_4;
  
  iVar1 = (uint)param_1 * 0x23b4;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + iVar1);
  if (*(int *)((int)this_00 + 0x14a4) != 0) {
    local_4 = this;
    if (*(char *)((int)this_00 + 0x1440) == '\x02') {
      FUN_0040af90(this_00,(undefined1 *)&param_1,(undefined1 *)&local_4);
      FUN_00405240((void *)((uint)(byte)param_1 * 0x358 + *(int *)((int)this + 0xdc)),(byte)local_4)
      ;
      *(undefined1 *)(*(int *)((int)this + 0xd4) + 0x1440 + iVar1) = 1;
    }
    FUN_0040bf30((void *)(*(int *)((int)this + 0xd4) + iVar1),
                 *(int *)(*(int *)((int)this + 0xd4) + 0x14a4 + iVar1));
    FUN_0040af40(*(int *)((int)this + 0xd4) + iVar1);
  }
  return;
}
