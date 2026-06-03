
uint __thiscall
FUN_0040c140(void *this,byte param_1,byte param_2,undefined4 *param_3,undefined4 *param_4,
            int *param_5)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(char *)((int)this + 0x144c) == '\0') {
    return 1;
  }
  if (*(char *)((int)this + 0x144c) != '\x02') {
    iVar3 = FUN_0042aad0();
    uVar4 = (uint)param_1;
    uVar1 = *(ushort *)((int)this + uVar4 * 2 + 0x1e2c);
    uVar5 = (uint)param_2;
    iVar3 = *(int *)(iVar3 + 0x10c);
    if (*(short *)(iVar3 + 0x12 + (uint)uVar1 * 0x20) !=
        *(short *)((uint)*(ushort *)((int)this + uVar5 * 2 + 0x1e2c) * 0x20 + 0x12 + iVar3)) {
      return CONCAT31((int3)((uint)iVar3 >> 8),3);
    }
    if ((11999 < uVar1) && (uVar1 < 13000)) {
      uVar1 = *(ushort *)((int)this + uVar5 * 2 + 0x1e2c);
      iVar3 = CONCAT22((short)((uint)iVar3 >> 0x10),uVar1);
      if ((11999 < uVar1) && (uVar1 < 13000)) {
        uVar2 = *(uint *)((int)this + uVar4 * 4 + 0x1f94);
        *param_3 = *(undefined4 *)((int)this + uVar4 * 4 + 0x1bc4);
        *param_4 = *(undefined4 *)((int)this + uVar5 * 4 + 0x1bc4);
        *param_5 = *(int *)((int)this + uVar5 * 4 + 0x1f94) + uVar2;
        return uVar2 & 0xffffff00;
      }
    }
    return CONCAT31((int3)((uint)iVar3 >> 8),4);
  }
  return 2;
}


