
void __thiscall FUN_00420c20(void *this,ushort param_1,undefined4 param_2,ushort *param_3)

{
  int iVar1;
  void *this_00;
  
  iVar1 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  if ((*(int *)(iVar1 + 0x1460) == 0) || (*(int *)(iVar1 + 0x14a4) == 0)) {
    FUN_0041eb20(this,param_1,0x2e,'\x01',1);
  }
  else if (*(char *)(iVar1 + 0x1440) == '\x03') {
    if (DAT_00455824 <= *param_3) {
      FUN_0041eb20(this,param_1,0x2f,'\x01',1);
      return;
    }
    this_00 = (void *)(*(int *)((int)this + 0xe4) + (uint)*param_3 * 0x3c0);
    if (*(char *)((int)this_00 + 8) != '\0') {
      FUN_00406240(this_00,param_1,*(undefined4 *)(param_3 + 1));
      return;
    }
  }
  return;
}
