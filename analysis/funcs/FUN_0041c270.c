
void __thiscall FUN_0041c270(void *this,ushort param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = *param_3;
  *(int *)((uint)param_1 * 0x23b4 + 0x2380 + *(int *)((int)this + 0xd4)) = iVar1;
  if (iVar1 == *(int *)((int)this + 0x51b4)) {
    *(int *)((int)this + 0x51bc) = *(int *)((int)this + 0x51bc) + 1;
  }
  return;
}
