
uint __thiscall
FUN_0040bd80(void *this,char param_1,ushort param_2,undefined4 *param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  
  iVar5 = FUN_0042aad0();
  uVar1 = *(uint *)(iVar5 + 0x110);
  puVar6 = (uint *)FUN_0042aad0();
  puVar2 = (uint *)puVar6[0x45];
  *param_5 = 0;
  if (param_1 != '\x01') {
LAB_0040be1e:
    return (uint)puVar6 & 0xffffff00;
  }
  *param_4 = (uint)*(ushort *)((int)this + (uint)param_2 * 2 + 0x1e2c);
  uVar3 = *(undefined4 *)((int)this + (uint)param_2 * 4 + 0x1bc4);
  *param_3 = uVar3;
  uVar4 = *param_4;
  if ((uVar4 < 11000) || (11999 < uVar4)) {
    return CONCAT31((int3)((uint)uVar3 >> 8),0x14);
  }
  uVar7 = 0;
  puVar6 = puVar2;
  if (uVar1 != 0) {
    do {
      if (*puVar6 == uVar4) {
        if (-1 < (int)uVar7) {
          puVar6 = puVar2 + uVar7 * 5;
          if (puVar2[uVar7 * 5 + 4] == 0) {
            return CONCAT31((int3)((uint)puVar6 >> 8),0x15);
          }
          *param_5 = puVar6[1];
          goto LAB_0040be1e;
        }
        break;
      }
      uVar7 = uVar7 + 1;
      puVar6 = puVar6 + 5;
    } while (uVar7 < uVar1);
  }
  return CONCAT31((int3)(uVar7 >> 8),0x16);
}


