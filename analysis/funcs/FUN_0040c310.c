
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall
FUN_0040c310(void *this,float param_1,byte param_2,byte param_3,byte *param_4,char *param_5,
            undefined4 *param_6,undefined4 *param_7,undefined4 *param_8,undefined4 *param_9,
            undefined4 *param_10)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  ushort uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  uint uVar14;
  int iVar15;
  byte bVar16;
  uint uVar17;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  float local_10 [3];
  
  local_20 = 0;
  local_2c = 0;
  local_24 = 0;
  uVar6 = *(ushort *)((int)this + (uint)param_2 * 2 + 0x1e2c);
  uVar14 = (uint)param_1 & 0xff;
  if (*(ushort *)((int)this + uVar14 * 2 + 0x1e2c) < 8000) {
    if ((((uVar6 != 0x32c9) && (uVar6 != 0x32ca)) && (uVar6 != 0x32cb)) &&
       ((uVar6 != 0x32cc && (uVar6 != 0x32cd)))) {
LAB_0040c3e3:
      return CONCAT31((int3)(uVar14 >> 8),7);
    }
    uVar17 = 0;
    if (param_3 != 0) {
      do {
        uVar7 = *(ushort *)((int)this + (uint)param_4[uVar17] * 2 + 0x1e2c);
        uVar14 = (uint)uVar7;
        if (uVar7 == 0x36b1) {
          local_20 = local_20 + 1;
        }
        else if (uVar7 == 0x36b2) {
          local_2c = local_2c + 1;
        }
        else {
          if (uVar7 != 0x36b3) goto LAB_0040c3e3;
          local_24 = local_24 + 1;
        }
        bVar16 = (char)uVar17 + 1;
        uVar17 = (uint)bVar16;
      } while (bVar16 < param_3);
    }
    bVar16 = *(byte *)(((uint)param_1 & 0xff) + 0x1f1c + (int)this);
    uVar14 = (uint)bVar16;
    if (uVar6 == 0x32c9) {
      if (4 < bVar16) {
        return 8;
      }
    }
    else if ((uVar6 == 0x32cc) && (9 < bVar16)) {
      return 8;
    }
    if (uVar14 < 0xf) {
      iVar15 = _rand();
      fVar8 = (float)iVar15 * _DAT_00447804;
      iVar15 = FUN_0042aad0();
      local_28 = 1;
      fVar9 = (float)*(int *)(iVar15 + -0x7810 + (uint)uVar6 * 4) * _DAT_00447800;
      fVar10 = (float)local_24 * _DAT_004477fc;
      fVar11 = _DAT_004477f8 - fVar10;
      local_10[0] = fVar11 * (float)*(int *)(iVar15 + -0x7844 + (uint)uVar6 * 4) * _DAT_00447800 +
                    fVar10;
      if (7 < uVar14) {
        local_1c = 3;
        do {
          fVar13 = (float)local_28;
          iVar15 = local_1c + -1;
          iVar1 = local_1c + 1;
          local_28 = local_28 + 8;
          fVar12 = (float)local_1c;
          iVar2 = local_1c + 2;
          iVar3 = local_1c + 3;
          iVar4 = local_1c + 4;
          iVar5 = local_1c + 5;
          local_1c = local_1c + 8;
          local_10[0] = (_DAT_004477f8 - (float)iVar5 * fVar9) *
                        ((_DAT_004477f8 - (float)iVar4 * fVar9) *
                         ((_DAT_004477f8 - (float)iVar3 * fVar9) *
                          ((_DAT_004477f8 - (float)iVar2 * fVar9) *
                           ((_DAT_004477f8 - (float)iVar1 * fVar9) *
                            ((_DAT_004477f8 - fVar12 * fVar9) *
                             ((_DAT_004477f8 - (float)iVar15 * fVar9) *
                              ((_DAT_004477f8 - fVar13 * fVar9) * fVar11 * local_10[0] + fVar10) *
                              fVar11 + fVar10) * fVar11 + fVar10) * fVar11 + fVar10) * fVar11 +
                          fVar10) * fVar11 + fVar10) * fVar11 + fVar10) * fVar11 + fVar10;
        } while (local_28 <= (int)(uVar14 - 7));
      }
      for (; local_28 <= (int)uVar14; local_28 = local_28 + 1) {
        local_10[0] = (_DAT_004477f8 - (float)local_28 * fVar9) * fVar11 * local_10[0] + fVar10;
      }
      fVar9 = _DAT_004477f8 - local_10[0];
      local_10[1] = fVar9 * ((float)local_2c * (float)_DAT_004477e8 +
                            (float)local_20 * _DAT_004477f4 + _DAT_004477f0) * (float)_DAT_004477e0;
      local_10[2] = (_DAT_004477d8 * (float)local_2c + _DAT_004477d4) * fVar9 * _DAT_004477d0;
      param_1 = (_DAT_004477f8 - (float)local_20 * _DAT_004477f4) * fVar9 * _DAT_004477d0;
      if (local_10[0] < (float)lpSrcStr_004477c0) {
        local_10[0] = 0.0;
      }
      if (local_10[1] < (float)lpSrcStr_004477c0) {
        local_10[1] = 0.0;
      }
      if (local_10[2] < (float)lpSrcStr_004477c0) {
        local_10[2] = 0.0;
      }
      if (param_1 < (float)lpSrcStr_004477c0) {
        param_1 = 0.0;
      }
      FUN_0042f280(s__RW__c1__u__c2__u__c3__u_004477a4);
      FUN_0042f280(s__RW__seed__f__p__f__nLv__d__u__f_00447780);
      FUN_0042f280(s__RW__pp_0___f__pp_1___f__pp_2____00447740);
      *param_5 = '\x06';
      iVar15 = 0;
      do {
        if (fVar8 < local_10[iVar15] != (fVar8 == local_10[iVar15])) {
          *param_5 = (char)iVar15;
          break;
        }
        fVar8 = fVar8 - local_10[iVar15];
        iVar15 = iVar15 + 1;
      } while (iVar15 < 6);
      if (uVar14 < 4) {
        if (*param_5 == '\x05') {
          FUN_0042f280(s__RW____CUser__CheckEnchantReinfo_004476f8);
          *param_5 = '\x04';
        }
      }
      else if (*param_5 == '\x05') {
        FUN_0042f280(s__RW____CUser__CheckEnchantReinfo_004476c4);
        *param_5 = '\x01';
      }
      *param_6 = *(undefined4 *)((int)this + ((uint)param_1 & 0xff) * 4 + 0x1bc4);
      *param_7 = *(undefined4 *)((int)this + (uint)param_2 * 4 + 0x1bc4);
      if (param_3 != 0) {
        *param_8 = *(undefined4 *)((int)this + (uint)*param_4 * 4 + 0x1bc4);
      }
      if (1 < param_3) {
        *param_9 = *(undefined4 *)((int)this + (uint)param_4[1] * 4 + 0x1bc4);
      }
      if (2 < param_3) {
        param_4 = (byte *)(uint)param_4[2];
        *param_10 = *(undefined4 *)((int)this + (int)param_4 * 4 + 0x1bc4);
      }
      return (uint)param_4 & 0xffffff00;
    }
  }
  return 6;
}


