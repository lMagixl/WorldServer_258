
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00426b30(void *this,ushort param_1,undefined4 param_2,char *param_3)

{
  LPCSTR lpString2;
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
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  char *pcVar24;
  undefined4 *puVar25;
  uint uVar26;
  byte bVar27;
  ushort uVar28;
  uint uVar29;
  uint uVar30;
  undefined4 *puVar31;
  byte *pbVar32;
  uint uStack_1500;
  uint local_14f0;
  char local_14d8 [16];
  CHAR local_14c8 [20];
  byte local_14b4 [3];
  undefined1 auStack_14b1 [4];
  undefined1 auStack_14ad [2];
  undefined1 auStack_14ab [4];
  undefined1 auStack_14a7 [4];
  undefined4 uStack_14a3;
  CHAR aCStack_149f [4075];
  char local_4b4 [7];
  int local_4ad;
  int local_4;
  
  local_4 = DAT_00454928;
  local_14b4[2] = *param_3;
  local_14b4[0] = 0xc;
  local_14b4[1] = 0;
  uVar28 = 3;
  if (local_14b4[2] == '\0') {
    local_14c8[1] = '\0';
    local_14c8[2] = '\0';
    local_14c8[3] = '\0';
    local_14c8[4] = '\0';
    local_14d8[1] = '\0';
    local_14d8[2] = '\0';
    local_14d8[3] = '\0';
    local_14d8[4] = '\0';
    local_14c8[5] = '\0';
    local_14c8[6] = '\0';
    local_14c8[7] = '\0';
    local_14c8[8] = '\0';
    iVar23 = *(int *)(param_3 + 1);
    local_14d8[5] = '\0';
    local_14d8[6] = '\0';
    local_14d8[7] = '\0';
    local_14d8[8] = '\0';
    local_14c8[9] = '\0';
    local_14c8[10] = '\0';
    local_14c8[0xb] = '\0';
    local_14c8[0xc] = '\0';
    uVar28 = 0;
    local_14d8[9] = '\0';
    local_14d8[10] = '\0';
    local_14d8[0xb] = '\0';
    local_14d8[0xc] = '\0';
    local_14c8[0] = '\0';
    local_14c8[0xd] = '\0';
    local_14c8[0xe] = '\0';
    local_14c8[0xf] = '\0';
    local_14c8[0x10] = '\0';
    local_14d8[0] = local_14b4[2];
    if (DAT_00456030 != 0) {
      do {
        iVar21 = (uint)uVar28 * 0x23b4 + *(int *)((int)this + 0xd4);
        if ((*(char *)(iVar21 + 0x1440) != '\0') && (*(int *)(iVar21 + 0x1460) == iVar23)) {
          FUN_0042f280(s__RW______CWorld__DBCommandLogin1_0044c1cc);
          FUN_0041eb20(this,uVar28,0xb6,'\x01',1);
          break;
        }
        uVar28 = uVar28 + 1;
      } while (uVar28 < DAT_00456030);
    }
    bVar27 = 0;
    if (*(char *)((int)this + 0x55) != '\0') {
      do {
        if (bVar27 != *(byte *)((int)this + 0x54)) {
          local_4b4[0] = '\x01';
          local_4b4[1] = '\x04';
          local_4b4[2] = '\0';
          local_4b4[3] = '\0';
          local_4b4[4] = '\0';
          local_4b4[5] = '\0';
          local_4b4[6] = bVar27;
          local_4ad = iVar23;
          FUN_00404010(*(void **)((int)this + 0x11c),0xb,local_4b4,
                       *(undefined4 *)(*(int *)((int)this + 0x58) + (uint)bVar27 * 4),
                       *(undefined2 *)(*(int *)((int)this + 0x5c) + (uint)bVar27 * 2));
        }
        bVar27 = bVar27 + 1;
      } while (bVar27 < *(byte *)((int)this + 0x55));
    }
    uVar14 = *(undefined4 *)(param_3 + 5);
    uVar15 = *(undefined4 *)(param_3 + 9);
    uVar16 = *(undefined4 *)(param_3 + 0xd);
    lstrcpyA(local_14d8,param_3 + 0x11);
    iVar21 = lstrlenA(param_3 + 0x11);
    uVar17 = *(undefined4 *)(param_3 + (iVar21 + 0x12U & 0xffff));
    uVar3 = *(undefined2 *)(param_3 + (iVar21 + 0x16U & 0xffff));
    uVar18 = *(undefined4 *)(param_3 + (iVar21 + 0x18U & 0xffff));
    uVar19 = *(undefined4 *)(param_3 + (iVar21 + 0x1cU & 0xffff));
    uVar20 = *(undefined4 *)(param_3 + (iVar21 + 0x20U & 0xffff));
    lstrcpyA(local_14c8,param_3 + (iVar21 + 0x24U & 0xffff));
    iVar22 = lstrlenA(param_3 + (iVar21 + 0x24U & 0xffff));
    uVar26 = iVar21 + 0x25 + iVar22;
    iVar21 = _rand();
    iVar22 = (uint)param_1 * 0x23b4;
    FUN_0040c8f0((void *)(*(int *)((int)this + 0xd4) + iVar22),iVar23,iVar21,uVar14,0,uVar15,uVar16,
                 0,local_14d8,uVar17,uVar3,uVar18,uVar19,uVar20,local_14c8);
    FUN_0040a920(*(int *)((int)this + 0xd4) + iVar22);
    auStack_14ad = (undefined1  [2])param_1;
    auStack_14b1 = (undefined1  [4])iVar23;
    auStack_14ab = (undefined1  [4])iVar21;
    auStack_14a7 = (undefined1  [4])uVar15;
    uStack_14a3 = uVar16;
    lstrcpyA(aCStack_149f,local_14d8);
    iVar23 = lstrlenA(local_14d8);
    *(undefined4 *)(local_14b4 + (iVar23 + 0x16U & 0xffff)) = uVar17;
    *(undefined2 *)(local_14b4 + (iVar23 + 0x1aU & 0xffff)) = uVar3;
    *(undefined4 *)(local_14b4 + (iVar23 + 0x1cU & 0xffff)) = uVar18;
    *(undefined4 *)(local_14b4 + (iVar23 + 0x20U & 0xffff)) = uVar19;
    *(undefined4 *)(local_14b4 + (iVar23 + 0x24U & 0xffff)) = uVar20;
    lstrcpyA((LPSTR)(local_14b4 + (iVar23 + 0x28U & 0xffff)),local_14c8);
    iVar21 = lstrlenA(local_14c8);
    uVar29 = iVar23 + 0x29 + iVar21;
    lstrcpyA((LPSTR)(local_14b4 + (uVar29 & 0xffff)),param_3 + (uVar26 & 0xffff));
    iVar23 = lstrlenA(param_3 + (uVar26 & 0xffff));
    uVar26 = uVar26 + 1 + iVar23;
    iVar23 = lstrlenA((LPCSTR)(local_14b4 + (uVar29 & 0xffff)));
    uVar29 = uVar29 + 1 + iVar23;
    uVar14 = *(undefined4 *)(param_3 + (uVar26 & 0xffff));
    uVar3 = *(undefined2 *)(param_3 + (uVar26 + 4 & 0xffff));
    uVar4 = *(undefined2 *)(param_3 + (uVar26 + 6 & 0xffff));
    *(undefined4 *)(*(int *)((int)this + 0xd4) + 0x236c + iVar22) = uVar14;
    *(undefined2 *)(*(int *)((int)this + 0xd4) + 0x2370 + iVar22) = uVar3;
    *(undefined2 *)(*(int *)((int)this + 0xd4) + 0x2374 + iVar22) = uVar4;
    *(undefined4 *)(local_14b4 + (uVar29 & 0xffff)) = uVar14;
    *(undefined2 *)(local_14b4 + (uVar29 + 4 & 0xffff)) = uVar3;
    lstrcpyA((LPSTR)(local_14b4 + (uVar29 + 6 & 0xffff)),param_3 + (uVar26 + 8 & 0xffff));
    iVar23 = lstrlenA(param_3 + (uVar26 + 8 & 0xffff));
    uVar30 = uVar26 + 9 + iVar23;
    iVar23 = lstrlenA((LPCSTR)(local_14b4 + (uVar29 + 6 & 0xffff)));
    uVar26 = uVar29 + 7 + iVar23;
    lstrcpyA((LPSTR)(local_14b4 + (uVar26 & 0xffff)),param_3 + (uVar30 & 0xffff));
    iVar23 = lstrlenA(param_3 + (uVar30 & 0xffff));
    uVar30 = iVar23 + 1 + uVar30;
    iVar23 = lstrlenA((LPCSTR)(local_14b4 + (uVar26 & 0xffff)));
    uVar26 = uVar26 + 1 + iVar23;
    local_14b4[uVar26 & 0xffff] = param_3[uVar30 & 0xffff];
    bVar27 = param_3[uVar30 + 1 & 0xffff];
    uVar30 = uVar30 + 2;
    uVar29 = uVar26 + 2;
    local_14b4[uVar26 + 1 & 0xffff] = bVar27;
    if (bVar27 != 0) {
      uStack_1500 = (uint)bVar27;
      do {
        lstrcpyA((LPSTR)(local_14b4 + (uVar29 & 0xffff)),param_3 + (uVar30 & 0xffff));
        iVar23 = lstrlenA(param_3 + (uVar30 & 0xffff));
        uVar30 = iVar23 + 1 + uVar30;
        iVar23 = lstrlenA((LPCSTR)(local_14b4 + (uVar29 & 0xffff)));
        uVar26 = uVar29 + 1 + iVar23;
        lstrcpyA((LPSTR)(local_14b4 + (uVar26 & 0xffff)),param_3 + (uVar30 & 0xffff));
        iVar23 = lstrlenA(param_3 + (uVar30 & 0xffff));
        uVar30 = iVar23 + 1 + uVar30;
        iVar23 = lstrlenA((LPCSTR)(local_14b4 + (uVar26 & 0xffff)));
        uVar29 = uVar26 + 1 + iVar23;
        uStack_1500 = uStack_1500 - 1;
      } while (uStack_1500 != 0);
    }
    *(undefined2 *)(local_14b4 + (uVar29 & 0xffff)) = *(undefined2 *)(param_3 + (uVar30 & 0xffff));
    uVar14 = *(undefined4 *)(param_3 + (uVar30 + 2 & 0xffff));
    iVar23 = *(int *)((int)this + 0xd4) + iVar22;
    uVar15 = *(undefined4 *)(param_3 + (uVar30 + 6 & 0xffff));
    *(undefined4 *)(iVar23 + 0x153c) = uVar15;
    *(undefined4 *)(iVar23 + 0x1538) = uVar14;
    *(undefined4 *)(local_14b4 + (uVar29 + 2 & 0xffff)) = uVar14;
    *(undefined4 *)(local_14b4 + (uVar29 + 6 & 0xffff)) = uVar15;
    bVar27 = param_3[uVar30 + 10 & 0xffff];
    *(byte *)(*(int *)((int)this + 0xd4) + 0x1541 + iVar22) = bVar27;
    local_14b4[uVar29 + 10 & 0xffff] = bVar27;
    local_14b4[uVar29 + 0xb & 0xffff] = param_3[uVar30 + 0xb & 0xffff];
    puVar25 = (undefined4 *)(*(int *)((int)this + 0xd4) + iVar22);
    puVar31 = puVar25;
    for (iVar23 = 0x510; iVar23 != 0; iVar23 = iVar23 + -1) {
      *puVar31 = 0;
      puVar31 = puVar31 + 1;
    }
    uVar30 = uVar30 + 0xc;
    uVar28 = (ushort)(uVar29 + 0xc);
    bVar27 = (3 < bVar27) + 3;
    if (bVar27 != 0) {
      local_14f0 = (uint)bVar27;
      puVar25 = puVar25 + 5;
      uVar26 = uVar29 + 0xc;
      do {
        iVar23 = *(int *)(param_3 + (uVar30 & 0xffff));
        uVar30 = uVar30 + 4;
        uVar29 = uVar26 + 4;
        *(int *)(local_14b4 + (uVar26 & 0xffff)) = iVar23;
        puVar25[-5] = iVar23;
        if (iVar23 != 0) {
          lpString2 = param_3 + (uVar30 & 0xffff);
          lstrcpyA((LPSTR)(puVar25 + -4),lpString2);
          lstrcpyA((LPSTR)(local_14b4 + (uVar29 & 0xffff)),lpString2);
          iVar23 = lstrlenA(lpString2);
          uVar30 = iVar23 + 1 + uVar30;
          iVar23 = lstrlenA((LPCSTR)(local_14b4 + (uVar29 & 0xffff)));
          uVar29 = uVar26 + 5 + iVar23;
          uVar14 = *(undefined4 *)(param_3 + (uVar30 & 0xffff));
          uVar15 = *(undefined4 *)(param_3 + (uVar30 + 4 & 0xffff));
          uVar16 = *(undefined4 *)(param_3 + (uVar30 + 8 & 0xffff));
          puVar25[2] = uVar16;
          *puVar25 = uVar14;
          puVar25[1] = uVar15;
          *(undefined4 *)(local_14b4 + (uVar29 & 0xffff)) = uVar14;
          *(undefined4 *)(local_14b4 + (uVar29 + 4 & 0xffff)) = uVar15;
          *(undefined4 *)(local_14b4 + (uVar29 + 8 & 0xffff)) = uVar16;
          bVar27 = param_3[uVar30 + 0xc & 0xffff];
          uVar14 = *(undefined4 *)(param_3 + (uVar30 + 0xd & 0xffff));
          uVar15 = *(undefined4 *)(param_3 + (uVar30 + 0x11 & 0xffff));
          puVar25[0xce] = uVar15;
          *(byte *)(puVar25 + 0xcd) = bVar27;
          puVar25[0xcf] = uVar14;
          local_14b4[uVar29 + 0xc & 0xffff] = bVar27;
          *(undefined4 *)(local_14b4 + (uVar29 + 0xd & 0xffff)) = uVar14;
          *(undefined4 *)(local_14b4 + (uVar29 + 0x11 & 0xffff)) = uVar15;
          bVar27 = param_3[uVar30 + 0x15 & 0xffff];
          bVar1 = param_3[uVar30 + 0x16 & 0xffff];
          bVar2 = param_3[uVar30 + 0x17 & 0xffff];
          uVar14 = *(undefined4 *)(param_3 + (uVar30 + 0x18 & 0xffff));
          *(byte *)((int)puVar25 + 0x342) = bVar2;
          puVar25[0xd1] = uVar14;
          *(byte *)((int)puVar25 + 0x341) = bVar1;
          *(byte *)(puVar25 + 0xd0) = bVar27;
          local_14b4[uVar29 + 0x15 & 0xffff] = bVar27;
          local_14b4[uVar29 + 0x16 & 0xffff] = bVar1;
          local_14b4[uVar29 + 0x17 & 0xffff] = bVar2;
          *(undefined4 *)(local_14b4 + (uVar29 + 0x18 & 0xffff)) = uVar14;
          uVar3 = *(undefined2 *)(param_3 + (uVar30 + 0x1c & 0xffff));
          uVar4 = *(undefined2 *)(param_3 + (uVar30 + 0x20 & 0xffff));
          uVar5 = *(undefined2 *)(param_3 + (uVar30 + 0x22 & 0xffff));
          uVar6 = *(undefined2 *)(param_3 + (uVar30 + 0x24 & 0xffff));
          uVar7 = *(undefined2 *)(param_3 + (uVar30 + 0x26 & 0xffff));
          uVar8 = *(undefined2 *)(param_3 + (uVar30 + 0x1e & 0xffff));
          uVar9 = *(undefined2 *)(param_3 + (uVar30 + 0x28 & 0xffff));
          uVar10 = *(undefined2 *)(param_3 + (uVar30 + 0x2a & 0xffff));
          uVar11 = *(undefined2 *)(param_3 + (uVar30 + 0x2c & 0xffff));
          uVar12 = *(undefined2 *)(param_3 + (uVar30 + 0x2e & 0xffff));
          uVar13 = *(undefined2 *)(param_3 + (uVar30 + 0x30 & 0xffff));
          *(undefined2 *)(puVar25 + 0x81) = uVar4;
          *(undefined2 *)((int)puVar25 + 0x206) = uVar5;
          *(undefined2 *)(puVar25 + 0x82) = uVar6;
          *(undefined2 *)((int)puVar25 + 0x20a) = uVar7;
          *(undefined2 *)(puVar25 + 0x83) = uVar9;
          *(undefined2 *)((int)puVar25 + 0x20e) = uVar10;
          *(undefined2 *)(puVar25 + 0x84) = uVar11;
          *(undefined2 *)(puVar25 + 0x80) = uVar3;
          *(undefined2 *)((int)puVar25 + 0x202) = uVar8;
          *(undefined2 *)((int)puVar25 + 0x212) = uVar12;
          *(undefined2 *)(puVar25 + 0x85) = uVar13;
          *(undefined2 *)(local_14b4 + (uVar29 + 0x1c & 0xffff)) = uVar3;
          *(undefined2 *)(local_14b4 + (uVar29 + 0x1e & 0xffff)) = uVar8;
          *(undefined2 *)(local_14b4 + (uVar29 + 0x20 & 0xffff)) = uVar4;
          *(undefined2 *)(local_14b4 + (uVar29 + 0x22 & 0xffff)) = uVar5;
          *(undefined2 *)(local_14b4 + (uVar29 + 0x24 & 0xffff)) = uVar6;
          *(undefined2 *)(local_14b4 + (uVar29 + 0x26 & 0xffff)) = uVar7;
          *(undefined2 *)(local_14b4 + (uVar29 + 0x28 & 0xffff)) = uVar9;
          *(undefined2 *)(local_14b4 + (uVar29 + 0x2a & 0xffff)) = uVar10;
          *(undefined2 *)(local_14b4 + (uVar29 + 0x2c & 0xffff)) = uVar11;
          *(undefined2 *)(local_14b4 + (uVar29 + 0x2e & 0xffff)) = uVar12;
          *(undefined2 *)(local_14b4 + (uVar29 + 0x30 & 0xffff)) = uVar13;
          pcVar24 = param_3 + (uVar30 + 0x32 & 0xffff);
          puVar31 = (undefined4 *)((int)puVar25 + 0x216);
          for (iVar23 = 9; iVar23 != 0; iVar23 = iVar23 + -1) {
            *puVar31 = *(undefined4 *)pcVar24;
            pcVar24 = pcVar24 + 4;
            puVar31 = puVar31 + 1;
          }
          *(undefined2 *)puVar31 = *(undefined2 *)pcVar24;
          puVar31 = (undefined4 *)((int)puVar25 + 0x216);
          pbVar32 = local_14b4 + (uVar29 + 0x32 & 0xffff);
          for (iVar23 = 9; iVar23 != 0; iVar23 = iVar23 + -1) {
            *(undefined4 *)pbVar32 = *puVar31;
            puVar31 = puVar31 + 1;
            pbVar32 = pbVar32 + 4;
          }
          *(undefined2 *)pbVar32 = *(undefined2 *)puVar31;
          pcVar24 = param_3 + (uVar30 + 0x58 & 0xffff);
          puVar25[0xa2] = *(undefined4 *)pcVar24;
          puVar25[0xa3] = *(undefined4 *)(pcVar24 + 4);
          puVar25[0xa4] = *(undefined4 *)(pcVar24 + 8);
          puVar25[0xa5] = *(undefined4 *)(pcVar24 + 0xc);
          *(undefined2 *)(puVar25 + 0xa6) = *(undefined2 *)(pcVar24 + 0x10);
          *(char *)((int)puVar25 + 0x29a) = pcVar24[0x12];
          uVar26 = uVar29 + 0x58 & 0xffff;
          *(undefined4 *)(local_14b4 + uVar26) = puVar25[0xa2];
          *(undefined4 *)(auStack_14b1 + uVar26 + 1) = puVar25[0xa3];
          *(undefined4 *)(auStack_14ad + uVar26 + 1) = puVar25[0xa4];
          *(undefined4 *)(auStack_14ab + uVar26 + 3) = puVar25[0xa5];
          *(undefined2 *)(auStack_14a7 + uVar26 + 3) = *(undefined2 *)(puVar25 + 0xa6);
          aCStack_149f[uVar26 - 3] = *(CHAR *)((int)puVar25 + 0x29a);
          pcVar24 = param_3 + (uVar30 + 0x6b & 0xffff);
          puVar31 = puVar25 + 0xa7;
          for (iVar23 = 0x13; iVar23 != 0; iVar23 = iVar23 + -1) {
            *puVar31 = *(undefined4 *)pcVar24;
            pcVar24 = pcVar24 + 4;
            puVar31 = puVar31 + 1;
          }
          puVar31 = puVar25 + 0xa7;
          pbVar32 = local_14b4 + (uVar29 + 0x6b & 0xffff);
          for (iVar23 = 0x13; iVar23 != 0; iVar23 = iVar23 + -1) {
            *(undefined4 *)pbVar32 = *puVar31;
            puVar31 = puVar31 + 1;
            pbVar32 = pbVar32 + 4;
          }
          pcVar24 = param_3 + (uVar30 + 0xb7 & 0xffff);
          puVar31 = puVar25 + 0xba;
          for (iVar23 = 0x13; iVar23 != 0; iVar23 = iVar23 + -1) {
            *puVar31 = *(undefined4 *)pcVar24;
            pcVar24 = pcVar24 + 4;
            puVar31 = puVar31 + 1;
          }
          puVar31 = puVar25 + 0xba;
          pbVar32 = local_14b4 + (uVar29 + 0xb7 & 0xffff);
          for (iVar23 = 0x13; iVar23 != 0; iVar23 = iVar23 + -1) {
            *(undefined4 *)pbVar32 = *puVar31;
            puVar31 = puVar31 + 1;
            pbVar32 = pbVar32 + 4;
          }
          pcVar24 = param_3 + (uVar30 + 0x103 & 0xffff);
          puVar31 = puVar25 + 0x8f;
          for (iVar23 = 0x13; iVar23 != 0; iVar23 = iVar23 + -1) {
            *puVar31 = *(undefined4 *)pcVar24;
            pcVar24 = pcVar24 + 4;
            puVar31 = puVar31 + 1;
          }
          pcVar24 = param_3 + (uVar30 + 0x14f & 0xffff);
          puVar31 = puVar25 + 0x67;
          for (iVar23 = 0x19; iVar23 != 0; iVar23 = iVar23 + -1) {
            *puVar31 = *(undefined4 *)pcVar24;
            pcVar24 = pcVar24 + 4;
            puVar31 = puVar31 + 1;
          }
          puVar31 = puVar25 + 0x67;
          pbVar32 = local_14b4 + (uVar29 + 0x103 & 0xffff);
          for (iVar23 = 0x19; iVar23 != 0; iVar23 = iVar23 + -1) {
            *(undefined4 *)pbVar32 = *puVar31;
            puVar31 = puVar31 + 1;
            pbVar32 = pbVar32 + 4;
          }
          pcVar24 = param_3 + (uVar30 + 0x1b3 & 0xffff);
          puVar31 = puVar25 + 3;
          for (iVar23 = 100; iVar23 != 0; iVar23 = iVar23 + -1) {
            *puVar31 = *(undefined4 *)pcVar24;
            pcVar24 = pcVar24 + 4;
            puVar31 = puVar31 + 1;
          }
          bVar27 = param_3[uVar30 + 0x343 & 0xffff];
          *(byte *)(puVar25 + 0xd2) = bVar27;
          uVar30 = uVar30 + 0x344;
          local_14b4[uVar29 + 0x167 & 0xffff] = bVar27;
          uVar29 = uVar29 + 0x168;
        }
        uVar28 = (ushort)uVar29;
        puVar25 = puVar25 + 0xd8;
        local_14f0 = local_14f0 - 1;
        uVar26 = uVar29;
      } while (local_14f0 != 0);
    }
  }
  FUN_004038e0(*(void **)((int)this + 0x118),param_1,uVar28,(undefined4 *)local_14b4);
  FUN_00435e83(local_4);
  return;
}



/* METADATA: sig=undefined __thiscall FUN_00426b30(void * this, ushort param_1, undefined4 param_2, char * param_3) xrefs=00429618 callees=lstrlenA FUN_0042f280 FUN_00404010 _rand FUN_0041eb20 FUN_0040c8f0 FUN_004038e0 lstrcpyA FUN_00435e83 __chkstk FUN_0040a920 */
