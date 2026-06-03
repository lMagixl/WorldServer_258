
void __thiscall FUN_004283a0(void *this,ushort param_1)

{
  int *piVar1;
  void *this_00;
  ushort uVar2;
  int local_14 [2];
  undefined2 local_c [4];
  int local_4;
  
  local_4 = DAT_00454928;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + (uint)param_1 * 0x23b4);
  if (*(char *)((int)this_00 + 0x146c) == '4') {
    FUN_0040abe0(this_00,local_14,local_c);
    piVar1 = &DAT_00456034;
    do {
      if (local_14[0] == *piVar1) goto LAB_00428410;
      piVar1 = piVar1 + 1;
    } while ((int)piVar1 < 0x456044);
    uVar2 = 0xba;
  }
  else {
    uVar2 = 0xb9;
  }
  FUN_0041eb20(this,param_1,uVar2,'\x01',1);
LAB_00428410:
  FUN_00435e83(local_4);
  return;
}
