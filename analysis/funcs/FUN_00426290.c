
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_00426290(void *this,ushort param_1,undefined4 param_2,char *param_3)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  LPCSTR lpString2;
  int iVar17;
  byte bVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  int *piVar25;
  int *piVar26;
  byte *pbVar27;
  undefined4 *puVar28;
  char *pcVar29;
  int *piVar30;
  byte *pbVar31;
  uint local_1754;
  byte local_174b;
  undefined4 auStack_1718 [120];
  undefined4 auStack_1538 [120];
  undefined4 auStack_1358 [120];
  undefined1 auStack_1178 [3];
  undefined1 auStack_1175 [117];
  undefined1 auStack_1100 [2];
  undefined4 auStack_10fe [59];
  byte local_1010 [4];
  int aiStack_100c [3];
  undefined2 uStack_1000;
  undefined1 auStack_ffe [4082];
  int local_c;
  
  local_c = DAT_00454928;
  uVar23 = 1;
  if (*param_3 == '\0') {
    iVar22 = (uint)param_1 * 0x23b4;
    iVar19 = *(int *)((int)this + 0xd4) + iVar22;
    local_1010[0] = 0xd;
    local_1010[1] = 0;
    local_1754 = 2;
    if (*(int *)(iVar19 + 0x1460) == 0) {
      FUN_0041eb20(this,param_1,0xb5,'\x01',1);
    }
    uVar20 = 4;
    local_174b = 4;
    uVar24 = uVar23;
    if (4 < *(byte *)(iVar22 + 0x1541 + *(int *)((int)this + 0xd4))) {
      do {
        iVar17 = *(int *)(param_3 + (uVar23 & 0xffff));
        *(int *)(local_1010 + (local_1754 & 0xffff)) = iVar17;
        piVar25 = (int *)(iVar19 + uVar20 * 0x360);
        uVar24 = uVar23 + 4;
        *piVar25 = iVar17;
        bVar18 = (byte)uVar20;
        uVar20 = local_1754 + 4;
        if (iVar17 != 0) {
          lpString2 = param_3 + (uVar24 & 0xffff);
          lstrcpyA((LPSTR)(piVar25 + 1),lpString2);
          lstrcpyA((LPSTR)(local_1010 + (local_1754 + 4 & 0xffff)),lpString2);
          iVar17 = lstrlenA(lpString2);
          uVar24 = uVar23 + 5 + iVar17;
          iVar17 = lstrlenA((LPCSTR)(local_1010 + (local_1754 + 4 & 0xffff)));
          uVar23 = local_1754 + 5 + iVar17;
          iVar17 = *(int *)(param_3 + (uVar24 & 0xffff));
          iVar14 = *(int *)(param_3 + (uVar24 + 4 & 0xffff));
          iVar15 = *(int *)(param_3 + (uVar24 + 8 & 0xffff));
          piVar25[6] = iVar14;
          piVar25[7] = iVar15;
          piVar25[5] = iVar17;
          *(int *)(local_1010 + (uVar23 & 0xffff)) = iVar17;
          *(int *)(local_1010 + (uVar23 + 4 & 0xffff)) = iVar14;
          *(int *)(local_1010 + (uVar23 + 8 & 0xffff)) = iVar15;
          bVar18 = param_3[uVar24 + 0xc & 0xffff];
          iVar17 = *(int *)(param_3 + (uVar24 + 0xd & 0xffff));
          iVar14 = *(int *)(param_3 + (uVar24 + 0x11 & 0xffff));
          piVar25[0xd4] = iVar17;
          piVar25[0xd3] = iVar14;
          *(byte *)(piVar25 + 0xd2) = bVar18;
          local_1010[uVar23 + 0xc & 0xffff] = bVar18;
          *(int *)(local_1010 + (uVar23 + 0xd & 0xffff)) = iVar17;
          *(int *)(local_1010 + (uVar23 + 0x11 & 0xffff)) = iVar14;
          bVar18 = param_3[uVar24 + 0x15 & 0xffff];
          bVar1 = param_3[uVar24 + 0x16 & 0xffff];
          bVar2 = param_3[uVar24 + 0x17 & 0xffff];
          iVar17 = *(int *)(param_3 + (uVar24 + 0x18 & 0xffff));
          *(byte *)((int)piVar25 + 0x355) = bVar1;
          *(byte *)((int)piVar25 + 0x356) = bVar2;
          piVar25[0xd6] = iVar17;
          *(byte *)(piVar25 + 0xd5) = bVar18;
          local_1010[uVar23 + 0x15 & 0xffff] = bVar18;
          local_1010[uVar23 + 0x16 & 0xffff] = bVar1;
          local_1010[uVar23 + 0x17 & 0xffff] = bVar2;
          *(int *)(local_1010 + (uVar23 + 0x18 & 0xffff)) = iVar17;
          uVar3 = *(undefined2 *)(param_3 + (uVar24 + 0x1e & 0xffff));
          uVar4 = *(undefined2 *)(param_3 + (uVar24 + 0x20 & 0xffff));
          uVar5 = *(undefined2 *)(param_3 + (uVar24 + 0x22 & 0xffff));
          uVar6 = *(undefined2 *)(param_3 + (uVar24 + 0x24 & 0xffff));
          uVar7 = *(undefined2 *)(param_3 + (uVar24 + 0x26 & 0xffff));
          uVar8 = *(undefined2 *)(param_3 + (uVar24 + 0x28 & 0xffff));
          uVar9 = *(undefined2 *)(param_3 + (uVar24 + 0x1c & 0xffff));
          uVar10 = *(undefined2 *)(param_3 + (uVar24 + 0x2a & 0xffff));
          uVar11 = *(undefined2 *)(param_3 + (uVar24 + 0x2c & 0xffff));
          uVar12 = *(undefined2 *)(param_3 + (uVar24 + 0x2e & 0xffff));
          uVar13 = *(undefined2 *)(param_3 + (uVar24 + 0x30 & 0xffff));
          *(undefined2 *)((int)piVar25 + 0x216) = uVar3;
          *(undefined2 *)(piVar25 + 0x85) = uVar9;
          *(undefined2 *)(piVar25 + 0x86) = uVar4;
          *(undefined2 *)((int)piVar25 + 0x21a) = uVar5;
          *(undefined2 *)(piVar25 + 0x87) = uVar6;
          *(undefined2 *)((int)piVar25 + 0x21e) = uVar7;
          *(undefined2 *)(piVar25 + 0x88) = uVar8;
          *(undefined2 *)((int)piVar25 + 0x222) = uVar10;
          *(undefined2 *)(piVar25 + 0x89) = uVar11;
          *(undefined2 *)((int)piVar25 + 0x226) = uVar12;
          *(undefined2 *)(piVar25 + 0x8a) = uVar13;
          *(undefined2 *)(local_1010 + (uVar23 + 0x1c & 0xffff)) = uVar9;
          *(undefined2 *)(local_1010 + (uVar23 + 0x1e & 0xffff)) = uVar3;
          *(undefined2 *)(local_1010 + (uVar23 + 0x20 & 0xffff)) = uVar4;
          *(undefined2 *)(local_1010 + (uVar23 + 0x22 & 0xffff)) = uVar5;
          *(undefined2 *)(local_1010 + (uVar23 + 0x24 & 0xffff)) = uVar6;
          *(undefined2 *)(local_1010 + (uVar23 + 0x26 & 0xffff)) = uVar7;
          *(undefined2 *)(local_1010 + (uVar23 + 0x28 & 0xffff)) = uVar8;
          *(undefined2 *)(local_1010 + (uVar23 + 0x2a & 0xffff)) = uVar10;
          *(undefined2 *)(local_1010 + (uVar23 + 0x2c & 0xffff)) = uVar11;
          *(undefined2 *)(local_1010 + (uVar23 + 0x2e & 0xffff)) = uVar12;
          *(undefined2 *)(local_1010 + (uVar23 + 0x30 & 0xffff)) = uVar13;
          pcVar29 = param_3 + (uVar24 + 0x32 & 0xffff);
          puVar28 = (undefined4 *)((int)piVar25 + 0x22a);
          for (iVar17 = 9; iVar17 != 0; iVar17 = iVar17 + -1) {
            *puVar28 = *(undefined4 *)pcVar29;
            pcVar29 = pcVar29 + 4;
            puVar28 = puVar28 + 1;
          }
          *(undefined2 *)puVar28 = *(undefined2 *)pcVar29;
          puVar28 = (undefined4 *)((int)piVar25 + 0x22a);
          pbVar27 = local_1010 + (uVar23 + 0x32 & 0xffff);
          for (iVar17 = 9; iVar17 != 0; iVar17 = iVar17 + -1) {
            *(undefined4 *)pbVar27 = *puVar28;
            puVar28 = puVar28 + 1;
            pbVar27 = pbVar27 + 4;
          }
          *(undefined2 *)pbVar27 = *(undefined2 *)puVar28;
          piVar26 = (int *)(param_3 + (uVar24 + 0x58 & 0xffff));
          piVar25[0xa7] = *piVar26;
          piVar25[0xa8] = piVar26[1];
          piVar25[0xa9] = piVar26[2];
          piVar25[0xaa] = piVar26[3];
          *(short *)(piVar25 + 0xab) = (short)piVar26[4];
          *(undefined1 *)((int)piVar25 + 0x2ae) = *(undefined1 *)((int)piVar26 + 0x12);
          uVar20 = uVar23 + 0x58 & 0xffff;
          *(int *)(local_1010 + uVar20) = piVar25[0xa7];
          *(int *)((int)aiStack_100c + uVar20) = piVar25[0xa8];
          *(int *)((int)aiStack_100c + uVar20 + 4) = piVar25[0xa9];
          *(int *)((int)aiStack_100c + uVar20 + 8) = piVar25[0xaa];
          *(short *)((int)&uStack_1000 + uVar20) = (short)piVar25[0xab];
          auStack_ffe[uVar20] = *(undefined1 *)((int)piVar25 + 0x2ae);
          piVar26 = (int *)(param_3 + (uVar24 + 0x6b & 0xffff));
          piVar30 = piVar25 + 0xac;
          for (iVar17 = 0x13; iVar17 != 0; iVar17 = iVar17 + -1) {
            *piVar30 = *piVar26;
            piVar26 = piVar26 + 1;
            piVar30 = piVar30 + 1;
          }
          piVar26 = piVar25 + 0xac;
          pbVar27 = local_1010 + (uVar23 + 0x6b & 0xffff);
          for (iVar17 = 0x13; iVar17 != 0; iVar17 = iVar17 + -1) {
            *(int *)pbVar27 = *piVar26;
            piVar26 = piVar26 + 1;
            pbVar27 = pbVar27 + 4;
          }
          piVar26 = (int *)(param_3 + (uVar24 + 0xb7 & 0xffff));
          piVar30 = piVar25 + 0xbf;
          for (iVar17 = 0x13; iVar17 != 0; iVar17 = iVar17 + -1) {
            *piVar30 = *piVar26;
            piVar26 = piVar26 + 1;
            piVar30 = piVar30 + 1;
          }
          piVar26 = piVar25 + 0xbf;
          pbVar27 = local_1010 + (uVar23 + 0xb7 & 0xffff);
          for (iVar17 = 0x13; iVar17 != 0; iVar17 = iVar17 + -1) {
            *(int *)pbVar27 = *piVar26;
            piVar26 = piVar26 + 1;
            pbVar27 = pbVar27 + 4;
          }
          piVar26 = (int *)(param_3 + (uVar24 + 0x103 & 0xffff));
          piVar30 = piVar25 + 0x94;
          for (iVar17 = 0x13; iVar17 != 0; iVar17 = iVar17 + -1) {
            *piVar30 = *piVar26;
            piVar26 = piVar26 + 1;
            piVar30 = piVar30 + 1;
          }
          piVar26 = (int *)(param_3 + (uVar24 + 0x14f & 0xffff));
          piVar30 = piVar25 + 0x6c;
          for (iVar17 = 0x19; iVar17 != 0; iVar17 = iVar17 + -1) {
            *piVar30 = *piVar26;
            piVar26 = piVar26 + 1;
            piVar30 = piVar30 + 1;
          }
          piVar26 = piVar25 + 0x6c;
          pbVar27 = local_1010 + (uVar23 + 0x103 & 0xffff);
          for (iVar17 = 0x19; iVar17 != 0; iVar17 = iVar17 + -1) {
            *(int *)pbVar27 = *piVar26;
            piVar26 = piVar26 + 1;
            pbVar27 = pbVar27 + 4;
          }
          piVar26 = (int *)(param_3 + (uVar24 + 0x1b3 & 0xffff));
          piVar30 = piVar25 + 8;
          for (iVar17 = 100; iVar17 != 0; iVar17 = iVar17 + -1) {
            *piVar30 = *piVar26;
            piVar26 = piVar26 + 1;
            piVar30 = piVar30 + 1;
          }
          bVar18 = param_3[uVar24 + 0x343 & 0xffff];
          *(byte *)(piVar25 + 0xd7) = bVar18;
          uVar24 = uVar24 + 0x344;
          local_1010[uVar23 + 0x167 & 0xffff] = bVar18;
          bVar18 = local_174b;
          uVar20 = uVar23 + 0x168;
        }
        local_1754 = uVar20;
        local_174b = bVar18 + 1;
        uVar20 = (uint)local_174b;
        uVar23 = uVar24;
      } while (local_174b < *(byte *)(iVar22 + 0x1541 + *(int *)((int)this + 0xd4)));
    }
    bVar18 = param_3[uVar24 & 0xffff];
    uVar24 = uVar24 + 1;
    uVar23 = local_1754 + 1;
    local_1010[local_1754 & 0xffff] = bVar18;
    if (bVar18 != 0) {
      uVar20 = (uint)bVar18 * 2;
      pbVar27 = (byte *)(param_3 + (uVar24 & 0xffff));
      pbVar31 = local_1010 + (uVar23 & 0xffff);
      for (uVar21 = (uint)(bVar18 >> 1); uVar21 != 0; uVar21 = uVar21 - 1) {
        *(undefined4 *)pbVar31 = *(undefined4 *)pbVar27;
        pbVar27 = pbVar27 + 4;
        pbVar31 = pbVar31 + 4;
      }
      for (uVar21 = uVar20 & 3; uVar21 != 0; uVar21 = uVar21 - 1) {
        *pbVar31 = *pbVar27;
        pbVar27 = pbVar27 + 1;
        pbVar31 = pbVar31 + 1;
      }
      uVar24 = uVar24 + uVar20;
      uVar23 = uVar23 + uVar20;
    }
    bVar18 = param_3[uVar24 & 0xffff];
    local_1010[uVar23 & 0xffff] = bVar18;
    *(byte *)(iVar22 + 0x1540 + *(int *)((int)this + 0xd4)) = bVar18;
    auStack_1538[0] = 0;
    auStack_1100 = (undefined1  [2])0x0;
    puVar28 = auStack_1538;
    for (iVar19 = 0x77; puVar28 = puVar28 + 1, iVar19 != 0; iVar19 = iVar19 + -1) {
      *puVar28 = 0;
    }
    puVar28 = (undefined4 *)(auStack_1100 + 2);
    for (iVar19 = 0x3b; iVar19 != 0; iVar19 = iVar19 + -1) {
      *puVar28 = 0;
      puVar28 = puVar28 + 1;
    }
    *(undefined2 *)puVar28 = 0;
    auStack_1178[0] = 0;
    puVar28 = (undefined4 *)((int)auStack_1178 + 1);
    for (iVar19 = 0x1d; iVar19 != 0; iVar19 = iVar19 + -1) {
      *puVar28 = 0;
      puVar28 = puVar28 + 1;
    }
    *(undefined2 *)puVar28 = 0;
    *(undefined1 *)((int)puVar28 + 2) = 0;
    auStack_1718[0] = 0;
    puVar28 = auStack_1718;
    for (iVar19 = 0x77; puVar28 = puVar28 + 1, iVar19 != 0; iVar19 = iVar19 + -1) {
      *puVar28 = 0;
    }
    pcVar29 = param_3 + (uVar24 + 1 & 0xffff);
    puVar28 = (undefined4 *)auStack_1100;
    for (iVar19 = 0x3c; iVar19 != 0; iVar19 = iVar19 + -1) {
      *puVar28 = *(undefined4 *)pcVar29;
      pcVar29 = pcVar29 + 4;
      puVar28 = puVar28 + 1;
    }
    puVar28 = (undefined4 *)auStack_1100;
    pbVar27 = local_1010 + (uVar23 + 1 & 0xffff);
    for (iVar19 = 0x3c; iVar19 != 0; iVar19 = iVar19 + -1) {
      *(undefined4 *)pbVar27 = *puVar28;
      puVar28 = puVar28 + 1;
      pbVar27 = pbVar27 + 4;
    }
    pcVar29 = param_3 + (uVar24 + 0xf1 & 0xffff);
    puVar28 = (undefined4 *)auStack_1178;
    for (iVar19 = 0x1e; iVar19 != 0; iVar19 = iVar19 + -1) {
      *puVar28 = *(undefined4 *)pcVar29;
      pcVar29 = pcVar29 + 4;
      puVar28 = puVar28 + 1;
    }
    puVar28 = (undefined4 *)auStack_1178;
    pbVar27 = local_1010 + (uVar23 + 0xf1 & 0xffff);
    for (iVar19 = 0x1e; iVar19 != 0; iVar19 = iVar19 + -1) {
      *(undefined4 *)pbVar27 = *puVar28;
      puVar28 = puVar28 + 1;
      pbVar27 = pbVar27 + 4;
    }
    pcVar29 = param_3 + (uVar24 + 0x169 & 0xffff);
    puVar28 = auStack_1718;
    for (iVar19 = 0x78; iVar19 != 0; iVar19 = iVar19 + -1) {
      *puVar28 = *(undefined4 *)pcVar29;
      pcVar29 = pcVar29 + 4;
      puVar28 = puVar28 + 1;
    }
    puVar28 = auStack_1718;
    pbVar27 = local_1010 + (uVar23 + 0x169 & 0xffff);
    for (iVar19 = 0x78; iVar19 != 0; iVar19 = iVar19 + -1) {
      *(undefined4 *)pbVar27 = *puVar28;
      puVar28 = puVar28 + 1;
      pbVar27 = pbVar27 + 4;
    }
    pcVar29 = param_3 + (uVar24 + 0x349 & 0xffff);
    puVar28 = auStack_1358;
    for (iVar19 = 0x78; iVar19 != 0; iVar19 = iVar19 + -1) {
      *puVar28 = *(undefined4 *)pcVar29;
      pcVar29 = pcVar29 + 4;
      puVar28 = puVar28 + 1;
    }
    puVar28 = auStack_1358;
    pbVar27 = local_1010 + (uVar23 + 0x349 & 0xffff);
    for (iVar19 = 0x78; iVar19 != 0; iVar19 = iVar19 + -1) {
      *(undefined4 *)pbVar27 = *puVar28;
      puVar28 = puVar28 + 1;
      pbVar27 = pbVar27 + 4;
    }
    pcVar29 = param_3 + (uVar24 + 0x529 & 0xffff);
    puVar28 = auStack_1538;
    for (iVar19 = 0x78; iVar19 != 0; iVar19 = iVar19 + -1) {
      *puVar28 = *(undefined4 *)pcVar29;
      pcVar29 = pcVar29 + 4;
      puVar28 = puVar28 + 1;
    }
    FUN_0040bee0((void *)(*(int *)((int)this + 0xd4) + iVar22),auStack_1538,
                 (undefined4 *)auStack_1100,(undefined4 *)auStack_1178,auStack_1718);
    *(undefined4 *)(local_1010 + (uVar23 + 0x529 & 0xffff)) =
         *(undefined4 *)(param_3 + (uVar24 + 0x709 & 0xffff));
    uVar16 = *(undefined4 *)(param_3 + (uVar24 + 0x70d & 0xffff));
    *(undefined4 *)(iVar22 + 0x2378 + *(int *)((int)this + 0xd4)) = uVar16;
    *(undefined4 *)(local_1010 + (uVar23 + 0x52d & 0xffff)) = uVar16;
    FUN_004038e0(*(void **)((int)this + 0x118),param_1,(short)uVar23 + 0x531,
                 (undefined4 *)local_1010);
  }
  FUN_00435e83(local_c);
  return;
}



/* METADATA: sig=undefined __thiscall FUN_00426290(void * this, ushort param_1, undefined4 param_2, char * param_3) xrefs=00429635 callees=lstrlenA FUN_0041eb20 FUN_004038e0 lstrcpyA FUN_00435e83 __chkstk FUN_0040bee0 */
