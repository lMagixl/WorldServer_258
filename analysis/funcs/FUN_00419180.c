
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00419180(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  CHAR *pCVar10;
  char cVar11;
  undefined4 *puVar12;
  uint *puVar13;
  undefined4 *puVar14;
  int unaff_retaddr;
  char *pcVar15;
  int iVar16;
  char *param2;
  char cVar18;
  undefined1 *puVar17;
  undefined1 local_1af3;
  byte bStack_1af1;
  undefined1 uStack_1aea;
  undefined1 uStack_1ae9;
  undefined1 uStack_1ae7;
  undefined1 uStack_1ae6;
  undefined4 local_1ae8;
  uint local_1ad0 [20];
  undefined4 local_1a80 [120];
  uint local_18a0 [4];
  uint local_1890;
  char local_1888 [12];
  char acStack_187c [12];
  undefined1 auStack_1870 [1000];
  undefined4 local_1488 [30];
  CHAR local_1410 [1036];
  undefined2 uStack_1004;
  undefined2 uStack_1002;
  undefined1 uStack_1000;
  undefined1 uStack_fff;
  undefined1 uStack_ffe;
  byte bStack_ffc;
  undefined1 uStack_ffb;
  undefined1 uStack_ffa;
  char cStack_ff9;
  undefined4 local_c;
  
  local_c = DAT_00454928;
  param2 = *(char **)(param_4 + 10);
  cVar11 = *(char *)(param_4 + 0x19);
  local_1af3 = *(undefined1 *)(param_4 + 0x14);
  cVar18 = *(char *)(param_4 + 0x1e);
  bVar1 = *(byte *)(param_4 + 0x23);
  iVar8 = 0x24;
  if (bVar1 != 0) {
    uVar7 = (uint)(ushort)bVar1;
    puVar9 = (uint *)(param_4 + 0x24);
    puVar13 = local_1ad0;
    for (uVar6 = uVar7; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(char *)puVar13 = (char)*puVar9;
      puVar9 = (uint *)((int)puVar9 + 1);
      puVar13 = (uint *)((int)puVar13 + 1);
    }
    iVar8 = uVar7 * 4 + 0x24;
    puVar9 = (uint *)(iVar8 + param_4);
    puVar13 = local_18a0;
    for (uVar6 = (uint)(bVar1 >> 2); uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
    for (uVar6 = (ushort)bVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(char *)puVar13 = (char)*puVar9;
      puVar9 = (uint *)((int)puVar9 + 1);
      puVar13 = (uint *)((int)puVar13 + 1);
    }
    iVar8 = iVar8 + uVar7;
  }
  bVar2 = *(byte *)(iVar8 + param_4);
  uVar6 = iVar8 + 1;
  if (bVar2 != 0) {
    uVar3 = (ushort)bVar2;
    puVar12 = (undefined4 *)(uVar6 + param_4);
    puVar14 = local_1a80;
    for (uVar7 = (uint)uVar3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar14 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar14 = puVar14 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined1 *)puVar14 = *(undefined1 *)puVar12;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    }
    iVar8 = uVar6 + (uint)uVar3 * 4;
    puVar12 = (undefined4 *)(iVar8 + param_4);
    puVar14 = local_1488;
    for (uVar6 = (uint)(bVar2 >> 2); uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar14 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar14 = puVar14 + 1;
    }
    uVar6 = iVar8 + (uint)uVar3;
    for (uVar7 = uVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar14 = *(undefined1 *)puVar12;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    }
  }
  FUN_00416aa0(this,*(undefined4 *)(param_4 + 0x1f),bVar1,(int)local_1ad0,(int)local_18a0,bVar2,
               (int)local_1a80,(int)local_1488);
  if (*(char *)((uVar6 & 0xffff) + param_4) == '\0') {
LAB_00419465:
    _sprintf(local_1888,s_DELETE_FROM_useriteminfo_WHERE_i_004499e8,(uint)param2);
    iVar8 = mysql_query(*(undefined4 *)((int)this + 8),acStack_187c);
    if (iVar8 == 0) {
      if (bStack_1af1 != 0) {
        iVar8 = 0;
        do {
          _sprintf(acStack_187c,s_DELETE_FROM_useriteminfo_WHERE_i_004499e8,local_1ad0[iVar8]);
          iVar16 = mysql_query(*(undefined4 *)((int)this + 8),auStack_1870);
          if (iVar16 != 0) {
            iVar8 = *(int *)((int)this + 8);
            puVar17 = auStack_1870;
            iVar16 = -1;
            pvVar4 = (void *)FUN_0042aad0();
            FUN_0041d380(pvVar4,puVar17,iVar16);
            if (iVar8 != 0) {
              iVar16 = -1;
              uVar5 = mysql_error(iVar8);
              pvVar4 = (void *)FUN_0042aad0();
              FUN_0041d380(pvVar4,uVar5,iVar16);
            }
            goto LAB_00419689;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)(uint)bStack_1af1);
      }
      if (cVar11 == '\0') {
        _sprintf(acStack_187c,s_UPDATE_useriteminfo_SET_level___l_0044b3a8,(uint)param2);
        iVar8 = mysql_query(*(undefined4 *)((int)this + 8),auStack_1870);
        if (iVar8 == 0) goto LAB_0041968e;
        iVar8 = *(int *)((int)this + 8);
        puVar17 = auStack_1870;
        iVar16 = -1;
        pvVar4 = (void *)FUN_0042aad0();
        FUN_0041d380(pvVar4,puVar17,iVar16);
        if (iVar8 != 0) {
          iVar16 = -1;
          uVar5 = mysql_error(iVar8);
          pvVar4 = (void *)FUN_0042aad0();
          FUN_0041d380(pvVar4,uVar5,iVar16);
        }
      }
      else {
        if (cVar11 == '\x01') goto LAB_0041968e;
        if (cVar11 == '\x02') {
          pcVar15 = s_UPDATE_useriteminfo_SET_level___g_0044b360;
          _sprintf(acStack_187c,s_UPDATE_useriteminfo_SET_level___g_0044b360,(uint)param2);
          iVar8 = mysql_query(*(undefined4 *)((int)this + 8),auStack_1870);
          if (iVar8 == 0) goto LAB_0041968e;
        }
        else {
          if (cVar11 == '\x03') {
            pcVar15 = s_UPDATE_useriteminfo_SET_level___g_0044b318;
          }
          else if (cVar11 == '\x04') {
            pcVar15 = s_UPDATE_useriteminfo_SET_level___g_0044b2d0;
          }
          else {
            if (cVar11 != '\x05') goto LAB_00419689;
            pcVar15 = s_DELETE_FROM_useriteminfo_WHERE_i_004499e8;
          }
          _sprintf(acStack_187c,pcVar15,param2);
          iVar8 = mysql_query(*(undefined4 *)((int)this + 8),acStack_187c);
          if (iVar8 == 0) goto LAB_0041968e;
          pcVar15 = *(char **)((int)this + 8);
          param2 = acStack_187c;
        }
        FUN_0040ea30((int)pcVar15,param2);
      }
    }
    else {
      pCVar10 = acStack_187c;
LAB_0041949b:
      iVar8 = *(int *)((int)this + 8);
      iVar16 = -1;
      pvVar4 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar4,pCVar10,iVar16);
      if (iVar8 != 0) {
        iVar16 = -1;
        uVar5 = mysql_error(iVar8);
        pvVar4 = (void *)FUN_0042aad0();
        FUN_0041d380(pvVar4,uVar5,iVar16);
      }
    }
  }
  else {
    puVar9 = (uint *)((uVar6 + 5 & 0xffff) + param_4);
    local_18a0[0] = *puVar9;
    local_18a0[1] = puVar9[1];
    local_18a0[2] = puVar9[2];
    local_18a0[3] = puVar9[3];
    local_1890 = puVar9[4];
    uVar5 = *(undefined4 *)((uVar6 + 0x1b & 0xffff) + param_4);
    uVar3 = *(ushort *)((uVar6 + 0x1f & 0xffff) + param_4);
    wsprintfA(local_1410,s_UPDATE_CharacterInfo_SET_levelpo_0044aaf8,local_18a0[0] & 0xffff,
              local_18a0[0] >> 0x10,local_18a0[1] & 0xffff,local_18a0[1] >> 0x10,
              local_18a0[2] & 0xffff,local_18a0[2] >> 0x10,local_18a0[3] & 0xffff,
              local_18a0[3] >> 0x10,local_1890 & 0xffff,local_1890 >> 0x10,(uint)(ushort)puVar9[5],
              *(undefined4 *)((uVar6 + 1 & 0xffff) + param_4));
    iVar8 = mysql_query(*(undefined4 *)((int)this + 8),local_1410);
    if (iVar8 != 0) {
      pCVar10 = local_1410;
      goto LAB_0041949b;
    }
    wsprintfA(local_1410,s_UPDATE_usergameinfo_SET_powerlev_00449a44,(uint)uVar3,uVar5);
    iVar8 = mysql_query(*(undefined4 *)((int)this + 8),local_1410);
    if (iVar8 == 0) goto LAB_00419465;
    cVar11 = cVar18;
    FUN_0040ea30(*(int *)((int)this + 8),local_1410);
  }
LAB_00419689:
  local_1af3 = 10;
LAB_0041968e:
  uStack_1ae9 = (undefined1)((uint)this >> 0x18);
  uStack_1004 = param_2;
  uStack_1aea = (undefined1)((uint)this >> 0x10);
  uStack_fff = uStack_1ae9;
  uStack_ffe = uStack_1aea;
  uStack_1000 = local_1af3;
  uStack_ffb = uStack_1ae7;
  uStack_1002 = 0x28;
  uStack_ffa = uStack_1ae6;
  bStack_ffc = bVar2;
  cStack_ff9 = cVar11;
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,0xc,(undefined4 *)&uStack_1004);
  FUN_00435e83(unaff_retaddr);
  return;
}


