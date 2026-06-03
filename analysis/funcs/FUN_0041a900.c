/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_0041a900(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  void *pvVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  long lVar13;
  ushort uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  undefined4 *puVar18;
  CHAR *pCVar19;
  char *pcVar20;
  int iVar21;
  uint local_1714;
  long local_1704;
  long local_1700;
  long local_16f0;
  undefined4 local_16e0 [20];
  undefined4 local_1690 [120];
  CHAR local_14b0 [20];
  undefined4 local_149c [5];
  CHAR local_1488 [1024];
  undefined4 local_1088 [30];
  undefined2 uStack_1010;
  undefined2 uStack_100e;
  undefined1 uStack_100c;
  long lStack_100b;
  long lStack_1007;
  undefined1 uStack_1003;
  int local_c;
  
  local_c = DAT_00454928;
  local_16f0 = 0;
  local_1704 = 0;
  local_1700 = 0;
  uVar11 = param_4[1];
  uVar6 = *param_4;
  iVar21 = *(int *)((int)param_4 + 10);
  uVar5 = *(ushort *)(param_4 + 2);
  uVar7 = *(undefined4 *)((int)param_4 + 0xf);
  uVar1 = *(undefined1 *)((int)param_4 + 0xe);
  bVar2 = *(byte *)(param_4 + 5);
  bVar3 = *(byte *)((int)param_4 + 0x13);
  uVar8 = *(undefined4 *)((int)param_4 + 0x15);
  iVar17 = 0x19;
  if (bVar3 != 0) {
    uVar14 = (ushort)bVar3;
    local_1714 = (uint)uVar14;
    puVar12 = (undefined4 *)((int)param_4 + 0x19);
    puVar18 = local_16e0;
    for (uVar15 = (uint)uVar14; uVar15 != 0; uVar15 = uVar15 - 1) {
      *puVar18 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar18 = puVar18 + 1;
    }
    for (iVar17 = 0; iVar17 != 0; iVar17 = iVar17 + -1) {
      *(undefined1 *)puVar18 = *(undefined1 *)puVar12;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
      puVar18 = (undefined4 *)((int)puVar18 + 1);
    }
    iVar17 = local_1714 * 4 + 0x19;
    puVar12 = (undefined4 *)(iVar17 + (int)param_4);
    puVar18 = local_149c;
    for (uVar15 = (uint)(bVar3 >> 2); uVar15 != 0; uVar15 = uVar15 - 1) {
      *puVar18 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar18 = puVar18 + 1;
    }
    for (uVar15 = uVar14 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
      *(undefined1 *)puVar18 = *(undefined1 *)puVar12;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
      puVar18 = (undefined4 *)((int)puVar18 + 1);
    }
    iVar17 = iVar17 + local_1714;
  }
  bVar4 = *(byte *)(iVar17 + (int)param_4);
  if (bVar4 != 0) {
    puVar12 = (undefined4 *)(iVar17 + 1 + (int)param_4);
    puVar18 = local_1690;
    for (uVar15 = (uint)(ushort)bVar4; uVar15 != 0; uVar15 = uVar15 - 1) {
      *puVar18 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar18 = puVar18 + 1;
    }
    for (iVar16 = 0; iVar16 != 0; iVar16 = iVar16 + -1) {
      *(undefined1 *)puVar18 = *(undefined1 *)puVar12;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
      puVar18 = (undefined4 *)((int)puVar18 + 1);
    }
    puVar12 = (undefined4 *)(iVar17 + 1 + (uint)(ushort)bVar4 * 4 + (int)param_4);
    puVar18 = local_1088;
    for (uVar15 = (uint)(bVar4 >> 2); uVar15 != 0; uVar15 = uVar15 - 1) {
      *puVar18 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar18 = puVar18 + 1;
    }
    for (uVar15 = bVar4 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
      *(undefined1 *)puVar18 = *(undefined1 *)puVar12;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
      puVar18 = (undefined4 *)((int)puVar18 + 1);
    }
  }
  FUN_00416aa0(this,uVar11,bVar3,(int)local_16e0,(int)local_149c,bVar4,(int)local_1690,
               (int)local_1088);
  wsprintfA(local_1488,s_SELECT_count____FROM_UserItemInf_0044b8f8,uVar7);
  uVar9 = *(undefined4 *)((int)this + 8);
  iVar17 = mysql_query(uVar9,local_1488);
  if (iVar17 == 0) {
    iVar17 = mysql_store_result(uVar9);
    if (iVar17 != 0) {
      puVar12 = (undefined4 *)mysql_fetch_row(iVar17);
      if (puVar12 != (undefined4 *)0x0) {
        lVar13 = _atol((char *)*puVar12);
        if (lVar13 == 0) {
LAB_0041abe5:
          mysql_free_result(iVar17);
          FUN_00435e83(local_c);
          return;
        }
        mysql_free_result(iVar17);
        wsprintfA(local_1488,s_SELECT_name_gold_FROM_UserGameIn_0044af24,uVar6);
        uVar9 = *(undefined4 *)((int)this + 8);
        iVar17 = mysql_query(uVar9,local_1488);
        if (iVar17 != 0) {
LAB_0041ab4d:
          FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandInventorySell___mysql_s_0044b8c0);
          FUN_00435e83(local_c);
          return;
        }
        iVar17 = mysql_store_result(uVar9);
        if (iVar17 == 0) goto LAB_0041ab4d;
        puVar12 = (undefined4 *)mysql_fetch_row(iVar17);
        if (puVar12 != (undefined4 *)0x0) {
          lstrcpyA(local_14b0,(LPCSTR)*puVar12);
          local_16f0 = _atol((char *)puVar12[1]);
        }
        wsprintfA(local_1488,s_DELETE_FROM_UserItemInfo_WHERE_i_0044b898,uVar7);
        iVar16 = mysql_query(*(undefined4 *)((int)this + 8),local_1488);
        if (iVar16 != 0) {
          FUN_0040ea30(*(int *)((int)this + 8),local_1488);
          goto LAB_0041abe5;
        }
        mysql_free_result(iVar17);
        if (iVar21 != 0) {
          wsprintfA(local_1488,s_UPDATE_UserGameInfo_SET_gold_gol_0044b864,iVar21,uVar6);
          iVar17 = mysql_query(*(undefined4 *)((int)this + 8),local_1488);
          if (iVar17 != 0) {
            FUN_0040ea30(*(int *)((int)this + 8),local_1488);
            FUN_00435e83(local_c);
            return;
          }
        }
        wsprintfA(local_1488,s_SELECT_gold_FROM_UserGameInfo_WH_00449f70,uVar6);
        iVar17 = FUN_0040eac0(*(undefined4 *)((int)this + 8),local_1488);
        if (iVar17 == 0) {
          FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandInventorySell___mysql_s_0044b8c0);
          FUN_00435e83(local_c);
          return;
        }
        puVar12 = (undefined4 *)mysql_fetch_row(iVar17);
        if (puVar12 != (undefined4 *)0x0) {
          local_1704 = _atol((char *)*puVar12);
        }
        mysql_free_result(iVar17);
        wsprintfA(local_1488,s_INSERT_INTO_LogUserItem__userid__0044b7d0,uVar6,uVar11,(uint)uVar5,
                  iVar21,1,local_16f0,local_1704,(uint)bVar2,uVar8);
        iVar17 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1488);
        if (iVar17 != 0) {
          FUN_0040ea30(*(int *)((int)this + 0x20),local_1488);
          FUN_00435e83(local_c);
          return;
        }
      }
      pCVar19 = local_1488;
      for (iVar17 = 0x100; iVar17 != 0; iVar17 = iVar17 + -1) {
        pCVar19[0] = '\0';
        pCVar19[1] = '\0';
        pCVar19[2] = '\0';
        pCVar19[3] = '\0';
        pCVar19 = pCVar19 + 4;
      }
      wsprintfA(local_1488,s_SELECT_cash_FROM_Cash_WHERE_id___0044b7a8,local_14b0);
      uVar11 = *(undefined4 *)((int)this + 0xc);
      iVar17 = mysql_query(uVar11,local_1488);
      if (iVar17 != 0) {
LAB_0041ad9c:
        FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandCharacterList___mysql_s_004487d8);
        FUN_00435e83(local_c);
        return;
      }
      iVar17 = mysql_store_result(uVar11);
      if (iVar17 == 0) goto LAB_0041ad9c;
      puVar12 = (undefined4 *)mysql_fetch_row(iVar17);
      if (puVar12 != (undefined4 *)0x0) {
        local_1700 = _atol((char *)*puVar12);
      }
      mysql_free_result(iVar17);
      lStack_100b = local_1704;
      lStack_1007 = local_1700;
      uStack_1010 = param_2;
      uStack_100e = 0x15;
      uStack_100c = 0;
      uStack_1003 = uVar1;
      FUN_0042e720(*(void **)((int)this + 0x18),param_1,0xe,(undefined4 *)&uStack_1010);
      goto LAB_0041ae35;
    }
  }
  iVar17 = *(int *)((int)this + 8);
  iVar21 = -1;
  pcVar20 = s_DBCommandInventorySell___mysql_s_0044b8c0;
  pvVar10 = (void *)FUN_0042aad0();
  FUN_0041d380(pvVar10,pcVar20,iVar21);
  if (iVar17 != 0) {
    iVar21 = -1;
    uVar11 = mysql_error(iVar17);
    pvVar10 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar10,uVar11,iVar21);
    FUN_00435e83(local_c);
    return;
  }
LAB_0041ae35:
  FUN_00435e83(local_c);
  return;
}
