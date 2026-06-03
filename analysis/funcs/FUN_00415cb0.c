/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00415cb0(void *this,ushort param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 **ppuVar1;
  byte bVar2;
  char cVar3;
  undefined2 uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 uVar13;
  CHAR *pCVar14;
  longlong lVar15;
  char *pcVar16;
  char local_1887;
  byte local_1886;
  int local_1880;
  int local_187c;
  uint local_1874;
  uint local_1870;
  long local_186c;
  int local_1868;
  undefined4 local_1860;
  long local_185c;
  undefined4 local_1858;
  undefined4 *local_1854 [5];
  uint uStack_1840;
  CHAR local_183c [20];
  CHAR aCStack_1828 [24];
  CHAR local_1810 [1024];
  CHAR aCStack_1410 [1024];
  undefined4 local_1010;
  char local_100c;
  long local_100b;
  long local_1007;
  uint local_1003;
  undefined2 local_fff;
  char local_ffd;
  undefined2 local_ffc;
  undefined1 local_ffa;
  int local_c;
  
  local_c = DAT_00454928;
  bVar2 = *(byte *)(param_4 + 1);
  local_1880 = 0;
  local_1854[0] = (undefined4 *)0x0;
  local_1854[1] = (undefined4 *)0x0;
  local_1854[2] = (undefined4 *)0x0;
  local_1854[3] = (undefined4 *)0x0;
  local_1858 = 0;
  local_1860 = 0;
  local_1868 = 0;
  uVar4 = 0;
  cVar3 = *(char *)((int)param_4 + 7);
  uVar10 = *param_4;
  local_1874 = CONCAT22(local_1874._2_2_,*(undefined2 *)((int)param_4 + 5));
  if (cVar3 == '\x01') {
    local_1858 = param_4[2];
    local_1860 = param_4[3];
    local_1868 = param_4[4];
    uVar4 = *(undefined2 *)(param_4 + 5);
  }
  iVar7 = ((((-(uint)(bVar2 != 0) & 0xfffff830) + 9000) - local_1868) / 100) * 100;
  wsprintfA(local_1810,s_SELECT_name_FROM_UserGameInfo_WH_0044a064,uVar10);
  uVar13 = *(undefined4 *)((int)this + 8);
  iVar8 = mysql_query(uVar13,local_1810);
  if ((iVar8 != 0) || (iVar8 = mysql_store_result(uVar13), iVar8 == 0)) {
    iVar7 = *(int *)((int)this + 8);
    iVar8 = -1;
    pcVar16 = s_DBCommandInventoryBuyPowerUser___0044a3dc;
    pvVar9 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar9,pcVar16,iVar8);
    if (iVar7 != 0) {
      iVar8 = -1;
      uVar10 = mysql_error(iVar7);
      pvVar9 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar9,uVar10,iVar8);
    }
    local_1887 = '\x01';
    goto LAB_00416461;
  }
  puVar11 = (undefined4 *)mysql_fetch_row(iVar8);
  if (puVar11 == (undefined4 *)0x0) {
LAB_00416456:
    local_1887 = '\x02';
    mysql_free_result(iVar8);
    goto LAB_00416461;
  }
  lstrcpyA(local_183c,(LPCSTR)*puVar11);
  mysql_free_result(iVar8);
  wsprintfA(local_1810,s_SELECT_powertime_FROM_UserGameIn_0044a3ac,uVar10);
  uVar13 = *(undefined4 *)((int)this + 8);
  iVar8 = mysql_query(uVar13,local_1810);
  if ((iVar8 != 0) || (iVar8 = mysql_store_result(uVar13), iVar8 == 0)) {
    FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandInventoryBuyPowerUser___0044a3dc);
    local_1887 = '\x01';
    goto LAB_00416461;
  }
  puVar11 = (undefined4 *)mysql_fetch_row(iVar8);
  if (puVar11 == (undefined4 *)0x0) goto LAB_00416456;
  uVar12 = _atol((char *)*puVar11);
  uStack_1840 = local_1874;
  mysql_free_result(iVar8);
  wsprintfA(local_1810,s_SELECT__to_days_now____24_hour_n_004489ec);
  iVar8 = FUN_0040eac0(*(undefined4 *)((int)this + 8),local_1810);
  if (iVar8 == 0) {
    FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandInventoryBuyPowerUser___0044a3dc);
    local_1887 = '\x01';
    goto LAB_00416461;
  }
  puVar11 = (undefined4 *)mysql_fetch_row(iVar8);
  if (puVar11 == (undefined4 *)0x0) {
    iVar7 = *(int *)((int)this + 8);
    goto LAB_0041644f;
  }
  local_186c = _atol((char *)*puVar11);
  mysql_free_result(iVar8);
  if (local_186c + 0x5cb27800U < uVar12) {
LAB_00415eef:
    local_1887 = '\x04';
    goto LAB_00416461;
  }
  local_186c = 0;
  wsprintfA(local_1810,s_UPDATE_Cash_SET_cash_cash__u_WHE_00449fc8,iVar7,local_183c,iVar7);
  iVar8 = mysql_query(*(undefined4 *)((int)this + 0xc),local_1810);
  if (iVar8 != 0) {
    FUN_0040ea30(*(int *)((int)this + 0xc),local_1810);
    local_1887 = '\x01';
    goto LAB_00416461;
  }
  lVar15 = mysql_affected_rows(*(undefined4 *)((int)this + 0xc));
  if (lVar15 == 0) goto LAB_00415eef;
  local_1874 = local_1874 + 10;
  local_1887 = '\0';
  if (bVar2 == 0) {
    pcVar16 = s_UPDATE_UserGameInfo_SET_powertim_0044a2d0;
  }
  else {
    pcVar16 = s_UPDATE_UserGameInfo_SET_powertim_0044a350;
  }
  wsprintfA(local_1810,pcVar16,local_1874 & 0xffff,uVar10);
  iVar8 = mysql_query(*(undefined4 *)((int)this + 8),local_1810);
  if (iVar8 != 0) {
LAB_00415fc1:
    FUN_0040ea30(*(int *)((int)this + 8),local_1810);
    local_1887 = '\x01';
    goto LAB_00416461;
  }
  pCVar14 = local_1810;
  for (iVar8 = 0x100; iVar8 != 0; iVar8 = iVar8 + -1) {
    pCVar14[0] = '\0';
    pCVar14[1] = '\0';
    pCVar14[2] = '\0';
    pCVar14[3] = '\0';
    pCVar14 = pCVar14 + 4;
  }
  wsprintfA(local_1810,s_SELECT_cash_FROM_Cash_WHERE_id___0044a2a4,local_183c);
  iVar8 = FUN_0040eac0(*(undefined4 *)((int)this + 0xc),local_1810);
  if (iVar8 == 0) {
    FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuyPowerUser___0044a3dc);
    local_1887 = '\x01';
    goto LAB_00416461;
  }
  puVar11 = (undefined4 *)mysql_fetch_row(iVar8);
  if (puVar11 == (undefined4 *)0x0) {
    iVar7 = *(int *)((int)this + 0xc);
LAB_0041644f:
    FUN_0040ea30(iVar7,s_DBCommandInventoryBuyPowerUser___0044a130);
    goto LAB_00416456;
  }
  local_186c = _atol((char *)*puVar11);
  mysql_free_result(iVar8);
  wsprintfA(local_1810,s_SELECT_gold_powertime_FROM_UserG_0044a270,uVar10);
  iVar8 = FUN_0040eac0(*(undefined4 *)((int)this + 8),local_1810);
  if (iVar8 == 0) {
    FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandInventoryBuyPowerUser___0044a3dc);
    local_1887 = '\x01';
    goto LAB_00416461;
  }
  local_185c = 0;
  local_1870 = 0;
  local_1854[4] = (undefined4 *)mysql_fetch_row(iVar8);
  if (local_1854[4] == (undefined4 *)0x0) {
    iVar7 = *(int *)((int)this + 8);
    goto LAB_0041644f;
  }
  local_185c = _atol((char *)*local_1854[4]);
  local_1870 = _atol((char *)local_1854[4][1]);
  mysql_free_result(iVar8);
  wsprintfA(aCStack_1828,(LPCSTR)&param_2_00449a10);
  if (cVar3 != '\0') {
    wsprintfA(local_1810,s_DELETE_FROM_useriteminfo_WHERE_i_004499e8,local_1858);
    iVar8 = mysql_query(*(undefined4 *)((int)this + 8),local_1810);
    if (iVar8 != 0) {
      FUN_0040ea30(*(int *)((int)this + 8),local_1810);
      FUN_00435e83(local_c);
      return;
    }
    uVar13 = 10000;
    if (bVar2 != 0) {
      uVar13 = 0x2711;
    }
    wsprintfA(local_1810,s_INSERT_INTO_logcoupon__coupon_id_00449978,local_1860,uVar13,uVar10,
              ((local_1868 + 99U) / 100) * 100);
    iVar8 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1810);
    if (iVar8 != 0) {
      FUN_0040ea30(*(int *)((int)this + 0x20),local_1810);
      FUN_00435e83(local_c);
      return;
    }
    uVar13 = mysql_insert_id(*(undefined4 *)((int)this + 0x20));
    wsprintfA(aCStack_1828,(LPCSTR)&param_2_00449974,uVar13);
  }
  FUN_0040ea70(local_1870,aCStack_1410);
  wsprintfA(local_1810,s_INSERT_INTO_logbuypoweruser__use_0044a1a8,uVar10,(uint)bVar2,iVar7,uVar12,
            local_1870,aCStack_1410,uStack_1840 & 0xffff,local_1874 & 0xffff,aCStack_1828);
  iVar8 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1810);
  if (iVar8 != 0) {
    FUN_0040ea30(*(int *)((int)this + 0x20),local_1810);
    local_1887 = '\x01';
    goto LAB_00416461;
  }
  wsprintfA(local_1810,s_UPDATE_UserGameInfo_SET_powertim_0044a16c,aCStack_1410,uVar10);
  iVar8 = mysql_query(*(undefined4 *)((int)this + 8),local_1810);
  if (iVar8 != 0) goto LAB_00415fc1;
  if (cVar3 != '\0') goto LAB_00416461;
  pvVar9 = (void *)FUN_0042aad0();
  iVar8 = *(int *)((int)pvVar9 + 0xd4);
  iVar7 = FUN_0041d570(pvVar9,iVar7);
  if (iVar7 == 0) {
    local_1886 = *(byte *)((uint)param_1 * 0x23b4 + 0x1530 + iVar8);
    uVar12 = _rand();
    uVar12 = uVar12 & 0x80000003;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
    }
    iVar7 = uVar12 + 0x44e;
LAB_00416355:
    local_1880 = 1;
    local_1854[0] = *(undefined4 **)((int)pvVar9 + (iVar7 * 5 + (uint)local_1886) * 4);
  }
  else {
    if (iVar7 == 1) {
      local_1886 = *(byte *)((uint)param_1 * 0x23b4 + 0x1530 + iVar8);
      uVar12 = _rand();
      uVar12 = uVar12 & 0x80000003;
      if ((int)uVar12 < 0) {
        uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
      }
      iVar7 = uVar12 + 0x44a;
      goto LAB_00416355;
    }
    local_1880 = 0;
  }
  local_187c = 0;
  if (local_1880 != 0) {
    do {
      puVar11 = local_1854[local_187c];
      wsprintfA(local_1810,s_INSERT_INTO_pendingpresents__pre_00449e98,puVar11,uVar10);
      iVar7 = mysql_query(*(undefined4 *)((int)this + 8),local_1810);
      if (iVar7 == 0) {
        uVar13 = mysql_insert_id(*(int *)((int)this + 8));
        wsprintfA(local_1810,s_INSERT_INTO_logpresent__pending__004497f8,uVar13,puVar11,uVar10);
        iVar7 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1810);
        if (iVar7 != 0) {
          FUN_0040ea30(*(int *)((int)this + 0x20),local_1810);
        }
      }
      else {
        FUN_0040ea30(*(int *)((int)this + 8),local_1810);
        local_1880 = 0;
      }
      local_187c = local_187c + 1;
    } while (local_187c < local_1880);
  }
LAB_00416461:
  local_1010._0_2_ = param_2;
  local_1010._2_2_ = 0x17;
  local_100c = local_1887;
  uVar5 = 5;
  if (local_1887 == '\0') {
    local_1007 = local_186c;
    local_100b = local_185c;
    local_1003 = local_1870;
    local_ffd = cVar3;
    local_fff = (undefined2)local_1874;
    iVar7 = 0;
    local_ffc = uVar4;
    local_ffa = (char)local_1880;
    uVar6 = 0x17;
    uVar5 = 0x17;
    if (local_1880 != 0) {
      do {
        ppuVar1 = local_1854 + iVar7;
        uVar5 = uVar6 + 4;
        iVar7 = iVar7 + 1;
        *(undefined4 **)((int)&local_1010 + (uint)uVar6) = *ppuVar1;
        uVar6 = uVar5;
      } while (iVar7 < local_1880);
    }
  }
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar5,&local_1010);
  FUN_00435e83(local_c);
  return;
}
