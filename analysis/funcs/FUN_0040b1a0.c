
int __thiscall
FUN_0040b1a0(void *this,char param_1,ushort param_2,undefined4 *param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint3 uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  
  if (*(char *)((int)this + 0x144c) == '\0') {
    return 1;
  }
  if (*(char *)((int)this + 0x144c) == '\x02') {
    return 2;
  }
  iVar3 = FUN_0042aad0();
  uVar8 = *(uint *)(iVar3 + 0x110);
  iVar3 = FUN_0042aad0();
  puVar1 = *(uint **)(iVar3 + 0x114);
  uVar6 = 0;
  if (param_1 != '\x01') {
LAB_0040b249:
    uVar8 = (uVar6 * 12000) / 100;
    *param_5 = uVar8;
    if (5 < *(byte *)((int)this + 0x1541)) {
      return CONCAT31((int3)((ulonglong)(uVar6 * 12000) * 0x51eb851f >> 8),3);
    }
    uVar5 = (uint3)(*(uint *)((int)this + 0x153c) >> 8);
    if (((12000 - uVar8) / 100) * 100 <= *(uint *)((int)this + 0x153c)) {
      *(undefined1 *)((int)this + 0x144c) = 2;
      return (uint)uVar5 << 8;
    }
    return CONCAT31(uVar5,4);
  }
  *param_4 = (uint)*(ushort *)((int)this + (uint)param_2 * 2 + 0x1e2c);
  uVar2 = *(undefined4 *)((int)this + (uint)param_2 * 4 + 0x1bc4);
  *param_3 = uVar2;
  uVar6 = *param_4;
  if ((uVar6 < 11000) || (11999 < uVar6)) {
    return CONCAT31((int3)((uint)uVar2 >> 8),0x14);
  }
  uVar4 = 0;
  puVar7 = puVar1;
  if (uVar8 != 0) {
    do {
      if (*puVar7 == uVar6) {
        if (-1 < (int)uVar4) {
          if (puVar1[uVar4 * 5 + 4] == 0) {
            return CONCAT31((int3)((uint)(puVar1 + uVar4 * 5) >> 8),0x15);
          }
          uVar6 = (puVar1 + uVar4 * 5)[1];
          goto LAB_0040b249;
        }
        break;
      }
      uVar4 = uVar4 + 1;
      puVar7 = puVar7 + 5;
    } while (uVar4 < uVar8);
  }
  return CONCAT31((int3)(uVar4 >> 8),0x16);
}


