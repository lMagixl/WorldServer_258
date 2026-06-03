/* == POTION SLOT VALIDATION ==
   Validates and clamps potion slot index against server item table.
   Called during character select. */

void __thiscall FUN_0040d3f0(void *this,byte *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_0042aad0();
  iVar3 = (uint)*(byte *)((int)this + 0x1530) * 0x69;
  uVar1 = *(uint *)(*(int *)(iVar2 + 0x100) + 0x14 + ((uint)*param_1 + iVar3) * 4);
  if (uVar1 < *param_2) {
    *param_2 = uVar1;
    return;
  }
  uVar1 = *(uint *)(*(int *)(iVar2 + 0x100) + 0x14 + ((uint)(byte)(*param_1 - 1) + iVar3) * 4);
  if (*param_2 <= uVar1) {
    *param_2 = uVar1 + 1;
  }
  return;
}
