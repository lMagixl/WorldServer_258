/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00419a40(void *this,ushort param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  int iVar7;
  void *pvVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  uint uVar12;
  ushort uVar13;
  uint uVar14;
  ushort *puVar15;
  undefined4 **ppuVar16;
  byte *pbVar17;
  CHAR *pCVar18;
  byte *pbVar19;
  undefined4 *puVar20;
  undefined8 uVar21;
  char *pcVar22;
  int iVar23;
  byte bStack_177a;
  byte local_1779;
  uint local_1778;
  char cStack_1773;
  byte bStack_1772;
  byte *local_1770;
  uint uStack_176c;
  uint local_1764;
  int local_1760;
  undefined4 local_175c;
  long local_1758;
  uint local_1754;
  long local_1750;
  uint local_174c;
  undefined4 local_1740;
  undefined4 local_1738 [24];
  undefined4 auStack_16d8 [121];
  undefined4 *apuStack_14f4 [2];
  byte abStack_14ec [8];
  CHAR aCStack_14e4 [24];
  ushort auStack_14cc [8];
  CHAR aCStack_14bc [20];
  byte abStack_14a8 [32];
  CHAR local_1488 [1024];
  undefined4 auStack_1088 [30];
  undefined4 uStack_1010;
  char cStack_100c;
  long lStack_100b;
  long lStack_1007;
  byte bStack_1003;
  byte abStack_1002 [4086];
  int local_c;
  
  cVar1 = *(char *)(param_4 + 2);
  local_c = DAT_00454928;
  uVar9 = param_4[1];
  cVar2 = *(char *)((int)param_4 + 0xd);
  uVar6 = *param_4;
  local_1764 = *(uint *)((int)param_4 + 9);
  local_1760 = 0;
  local_1738[0] = 0;
  local_1738[1] = 0;
  local_1738[2] = 0;
  local_1738[3] = 0;
  local_175c = 0;
  local_1740 = 0;
  local_1770 = (byte *)0x0;
  uVar5 = 0;
  local_1778 = 0xe;
  if (cVar2 == '\x01') {
    local_175c = *(undefined4 *)((int)param_4 + 0xe);
    local_1740 = *(undefined4 *)((int)param_4 + 0x12);
    local_1770 = *(byte **)((int)param_4 + 0x16);
    uVar5 = *(undefined2 *)((int)param_4 + 0x1a);
    local_1764 = ((local_1764 - (int)local_1770) / 100) * 100;
    local_1778 = 0x1c;
  }
  local_174c = 0;
  local_1758 = 0;
  local_1754 = 0;
  local_1750 = 0;
  wsprintfA(local_1488,s_SELECT_name_gold_FROM_UserGameIn_0044af24,uVar6);
  apuStack_14f4[0] = *(undefined4 **)((int)this + 8);
  iVar7 = mysql_query(apuStack_14f4[0],local_1488);
  if ((iVar7 != 0) || (uStack_176c = mysql_store_result(apuStack_14f4[0]), uStack_176c == 0)) {
    iVar7 = *(int *)((int)this + 8);
    iVar23 = -1;
    pcVar22 = s_DBCommandInventoryBuy___mysql_st_0044b774;
    pvVar8 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar8,pcVar22,iVar23);
    if (iVar7 != 0) {
      iVar23 = -1;
      uVar9 = mysql_error(iVar7);
      pvVar8 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar8,uVar9,iVar23);
      FUN_00435e83(local_c);
      return;
    }
    goto LAB_00419e1b;
  }
  puVar10 = (undefined4 *)mysql_fetch_row(uStack_176c);
  apuStack_14f4[0] = puVar10;
  if (puVar10 != (undefined4 *)0x0) {
    lstrcpyA(aCStack_14bc,(LPCSTR)*puVar10);
    local_174c = _atol((char *)puVar10[1]);
  }
  mysql_free_result(uStack_176c);
  pCVar18 = local_1488;
  for (iVar7 = 0x100; iVar7 != 0; iVar7 = iVar7 + -1) {
    pCVar18[0] = '\0';
    pCVar18[1] = '\0';
    pCVar18[2] = '\0';
    pCVar18[3] = '\0';
    pCVar18 = pCVar18 + 4;
  }
  wsprintfA(local_1488,s_SELECT_cash_FROM_Cash_WHERE_id___0044a004,aCStack_14bc);
  uVar11 = *(undefined4 *)((int)this + 0xc);
  iVar7 = mysql_query(uVar11,local_1488);
  if ((iVar7 != 0) || (iVar7 = mysql_store_result(uVar11), iVar7 == 0)) {
    iVar7 = *(int *)((int)this + 0xc);
    iVar23 = -1;
    pcVar22 = s_DBCommandInventoryBuy___mysql_st_0044b774;
    pvVar8 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar8,pcVar22,iVar23);
    if (iVar7 != 0) {
      iVar23 = -1;
      uVar9 = mysql_error(iVar7);
      pvVar8 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar8,uVar9,iVar23);
      FUN_00435e83(local_c);
      return;
    }
    goto LAB_00419e1b;
  }
  puVar10 = (undefined4 *)mysql_fetch_row(iVar7);
  if (puVar10 != (undefined4 *)0x0) {
    local_1754 = _atol((char *)*puVar10);
  }
  mysql_free_result(iVar7);
  if (cVar1 == '\0') {
    if (local_1764 <= local_1754) {
      wsprintfA(local_1488,s_UPDATE_Cash_SET_cash_cash__u_WHE_0044b738,local_1764,aCStack_14bc,
                local_1764);
      iVar7 = mysql_query(*(undefined4 *)((int)this + 0xc),local_1488);
      if (iVar7 != 0) {
        FUN_0040ea30(*(int *)((int)this + 0xc),local_1488);
        FUN_00435e83(local_c);
        return;
      }
      goto LAB_00419ef9;
    }
LAB_00419ca5:
    cStack_1773 = '\x03';
  }
  else {
    if (local_174c < local_1764) goto LAB_00419ca5;
    wsprintfA(local_1488,s_UPDATE_UserGameInfo_SET_gold_gol_0044b6f8,local_1764,uVar6,local_1764);
    iVar7 = mysql_query(*(undefined4 *)((int)this + 8),local_1488);
    if (iVar7 != 0) {
LAB_00419ed1:
      FUN_0040ea30(*(int *)((int)this + 8),local_1488);
      FUN_00435e83(local_c);
      return;
    }
LAB_00419ef9:
    wsprintfA(local_1488,s_SELECT_gold_FROM_UserGameInfo_WH_00449f70,uVar6);
    iVar7 = FUN_0040eac0(*(undefined4 *)((int)this + 8),local_1488);
    if (iVar7 == 0) {
      FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandInventoryBuy___mysql_st_0044b774);
      FUN_00435e83(local_c);
      return;
    }
    puVar10 = (undefined4 *)mysql_fetch_row(iVar7);
    if (puVar10 != (undefined4 *)0x0) {
      local_1758 = _atol((char *)*puVar10);
    }
    mysql_free_result(iVar7);
    pCVar18 = local_1488;
    for (iVar7 = 0x100; iVar7 != 0; iVar7 = iVar7 + -1) {
      pCVar18[0] = '\0';
      pCVar18[1] = '\0';
      pCVar18[2] = '\0';
      pCVar18[3] = '\0';
      pCVar18 = pCVar18 + 4;
    }
    wsprintfA(local_1488,s_SELECT_cash_FROM_Cash_WHERE_id___0044a004,aCStack_14bc);
    iVar7 = FUN_0040eac0(*(undefined4 *)((int)this + 0xc),local_1488);
    if (iVar7 == 0) {
      FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuy___mysql_st_0044b774);
      FUN_00435e83(local_c);
      return;
    }
    puVar10 = (undefined4 *)mysql_fetch_row(iVar7);
    if (puVar10 != (undefined4 *)0x0) {
      local_1750 = _atol((char *)*puVar10);
    }
    mysql_free_result(iVar7);
    uVar21 = mysql_affected_rows(*(undefined4 *)((int)this + 8));
    uVar12 = (uint)uVar21 | (uint)((ulonglong)uVar21 >> 0x20);
    if (uVar12 == 0) goto LAB_00419ca5;
    bStack_177a = *(byte *)(local_1778 + (int)param_4);
    local_1778 = local_1778 + 1;
    cStack_1773 = '\0';
    if (bStack_177a != 0) {
      iVar7 = CONCAT22((short)(uVar12 >> 0x10),(ushort)bStack_177a);
      pbVar17 = (byte *)(local_1778 + (int)param_4);
      pbVar19 = abStack_14ec;
      for (uVar12 = (uint)(bStack_177a >> 2); uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 *)pbVar19 = *(undefined4 *)pbVar17;
        pbVar17 = pbVar17 + 4;
        pbVar19 = pbVar19 + 4;
      }
      for (uVar12 = (ushort)bStack_177a & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pbVar19 = *pbVar17;
        pbVar17 = pbVar17 + 1;
        pbVar19 = pbVar19 + 1;
      }
      local_1778 = local_1778 + iVar7;
      apuStack_14f4[0] = (undefined4 *)(iVar7 * 2);
      puVar10 = (undefined4 *)((local_1778 & 0xffff) + (int)param_4);
      puVar15 = auStack_14cc;
      for (uVar12 = ((uint)apuStack_14f4[0] & 0xffff) >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 *)puVar15 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar15 = puVar15 + 2;
      }
      for (uVar12 = (uint)apuStack_14f4[0] & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined1 *)puVar15 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar15 = (ushort *)((int)puVar15 + 1);
      }
      local_1778 = local_1778 + (int)apuStack_14f4[0];
      if (1 < bStack_177a) {
        uVar12 = local_1778 & 0xffff;
        local_1778 = local_1778 + 2;
        uStack_176c = (uint)*(ushort *)(uVar12 + (int)param_4);
      }
    }
    bVar3 = *(byte *)((local_1778 & 0xffff) + (int)param_4);
    local_1778 = local_1778 + 1;
    if (bVar3 != 0) {
      apuStack_14f4[0] = (undefined4 *)CONCAT22(apuStack_14f4[0]._2_2_,(ushort)bVar3);
      puVar10 = (undefined4 *)((local_1778 & 0xffff) + (int)param_4);
      puVar20 = local_1738 + 4;
      for (uVar12 = (uint)(ushort)bVar3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *puVar20 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar20 = puVar20 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined1 *)puVar20 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar20 = (undefined4 *)((int)puVar20 + 1);
      }
      local_1778 = local_1778 + (int)apuStack_14f4[0] * 4;
      pbVar17 = (byte *)((local_1778 & 0xffff) + (int)param_4);
      pbVar19 = abStack_14a8;
      for (uVar12 = ((uint)apuStack_14f4[0] & 0xffff) >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 *)pbVar19 = *(undefined4 *)pbVar17;
        pbVar17 = pbVar17 + 4;
        pbVar19 = pbVar19 + 4;
      }
      for (uVar12 = (uint)apuStack_14f4[0] & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pbVar19 = *pbVar17;
        pbVar17 = pbVar17 + 1;
        pbVar19 = pbVar19 + 1;
      }
      local_1778 = local_1778 + (int)apuStack_14f4[0];
    }
    bVar4 = *(byte *)((local_1778 & 0xffff) + (int)param_4);
    apuStack_14f4[0] = (undefined4 *)CONCAT31(apuStack_14f4[0]._1_3_,bVar4);
    if (bVar4 != 0) {
      puVar10 = (undefined4 *)((local_1778 + 1 & 0xffff) + (int)param_4);
      puVar20 = auStack_16d8;
      for (uVar12 = (uint)(ushort)bVar4; uVar12 != 0; uVar12 = uVar12 - 1) {
        *puVar20 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar20 = puVar20 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined1 *)puVar20 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar20 = (undefined4 *)((int)puVar20 + 1);
      }
      puVar10 = (undefined4 *)((local_1778 + 1 + (uint)(ushort)bVar4 * 4 & 0xffff) + (int)param_4);
      puVar20 = auStack_1088;
      for (uVar12 = (uint)apuStack_14f4[0] >> 2 & 0x3f; uVar12 != 0; uVar12 = uVar12 - 1) {
        *puVar20 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar20 = puVar20 + 1;
      }
      for (uVar12 = (uint)apuStack_14f4[0] & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined1 *)puVar20 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar20 = (undefined4 *)((int)puVar20 + 1);
      }
    }
    FUN_00416aa0(this,uVar9,bVar3,(int)(local_1738 + 4),(int)abStack_14a8,(byte)apuStack_14f4[0],
                 (int)auStack_16d8,(int)auStack_1088);
    wsprintfA(aCStack_14e4,(LPCSTR)&param_2_00449a10);
    if (cVar2 != '\0') {
      wsprintfA(local_1488,s_DELETE_FROM_useriteminfo_WHERE_i_004499e8,local_175c);
      iVar7 = mysql_query(*(undefined4 *)((int)this + 8),local_1488);
      if (iVar7 != 0) {
        FUN_0040ea30(*(int *)((int)this + 8),local_1488);
        FUN_00435e83(local_c);
        return;
      }
      if (bStack_177a < 2) {
        uVar12 = (uint)auStack_14cc[0];
      }
      else {
        uVar12 = uStack_176c & 0xffff;
      }
      wsprintfA(local_1488,s_INSERT_INTO_logcoupon__coupon_id_00449978,local_1740,uVar12,uVar6,
                (((int)local_1770 + 99U) / 100) * 100);
      iVar7 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1488);
      if (iVar7 != 0) {
        FUN_0040ea30(*(int *)((int)this + 0x20),local_1488);
        FUN_00435e83(local_c);
        return;
      }
      uVar11 = mysql_insert_id(*(undefined4 *)((int)this + 0x20));
      wsprintfA(aCStack_14e4,(LPCSTR)&param_2_00449974,uVar11);
    }
    local_1778 = 0;
    bStack_1772 = 0;
    if (bStack_177a != 0) {
      do {
        uVar12 = (uint)bStack_1772;
        uVar13 = auStack_14cc[uVar12];
        if ((uVar13 < 8000) || (8999 < uVar13)) {
          *(undefined1 *)((int)apuStack_14f4 + uVar12) = 0;
        }
        else {
          *(undefined1 *)((int)apuStack_14f4 + uVar12) = 1;
        }
        if ((uVar13 < 12000) || (12999 < uVar13)) {
          wsprintfA(local_1488,s_INSERT_INTO_UserItemInfo__userid_0044b658,uVar6,(uint)uVar13,
                    (uint)*(byte *)((int)apuStack_14f4 + uVar12),(uint)abStack_14ec[uVar12]);
          iVar7 = mysql_query(*(undefined4 *)((int)this + 8),local_1488);
          if (iVar7 != 0) goto LAB_00419ed1;
          local_1770 = abStack_14a8 + uVar12 * 4;
          uVar11 = mysql_insert_id(*(undefined4 *)((int)this + 8));
          *(undefined4 *)local_1770 = uVar11;
        }
        else {
          iVar7 = FUN_0042aad0();
          iVar23 = (uint)uVar13 * 0x20;
          wsprintfA(local_1488,s_INSERT_INTO_UserItemInfo__userid_0044b6a8,uVar6,(uint)uVar13,
                    (uint)*(byte *)((int)apuStack_14f4 + uVar12),(uint)abStack_14ec[uVar12],
                    (uint)*(ushort *)(*(int *)(iVar7 + 0x10c) + 0xe + iVar23));
          iVar7 = mysql_query(*(undefined4 *)((int)this + 8),local_1488);
          if (iVar7 != 0) {
            FUN_0040ea30(*(int *)((int)this + 8),local_1488);
          }
          local_1770 = abStack_14a8 + uVar12 * 4;
          uVar11 = mysql_insert_id(*(undefined4 *)((int)this + 8));
          *(undefined4 *)local_1770 = uVar11;
          iVar7 = FUN_0042aad0();
          uVar12 = (uint)*(ushort *)(*(int *)(iVar7 + 0x10c) + 0x10 + iVar23);
          if (uVar12 != 0) {
            wsprintfA(local_1488,s_UPDATE_usergameinfo_SET_gold_gol_00448838,uVar12,uVar6);
            iVar7 = mysql_query(*(undefined4 *)((int)this + 8),local_1488);
            if (iVar7 != 0) {
              FUN_0040ea30(*(int *)((int)this + 8),local_1488);
            }
          }
        }
        if (cVar1 == '\0') {
          if (bStack_177a < 2) {
            wsprintfA(local_1488,s_INSERT_INTO_LogBuyCashItem__user_0044b4a8,uVar6,(uint)uVar13,
                      local_1764,local_1754,local_1750,aCStack_14e4);
            iVar23 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1488);
            iVar7 = *(int *)((int)this + 0x20);
            if (iVar23 != 0) {
LAB_0041a733:
              FUN_0040ea30(iVar7,local_1488);
              FUN_00435e83(local_c);
              return;
            }
LAB_0041a62a:
            local_1778 = mysql_insert_id(iVar7);
          }
          else if (bStack_1772 == 0) {
            wsprintfA(local_1488,s_INSERT_INTO_LogBuyCashItem__user_0044b4a8,uVar6,
                      uStack_176c & 0xffff,local_1764,local_1754,local_1750,aCStack_14e4);
            iVar7 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1488);
            if (iVar7 != 0) {
              FUN_0040ea30(*(int *)((int)this + 0x20),local_1488);
              FUN_00435e83(local_c);
              return;
            }
            iVar7 = *(int *)((int)this + 0x20);
            goto LAB_0041a62a;
          }
          uVar11 = 2;
        }
        else if (bStack_177a < 2) {
          wsprintfA(local_1488,s_INSERT_INTO_LogUserItem__userid__0044b528,uVar6,uVar9,(uint)uVar13,
                    local_1764,0,local_174c,local_1758,aCStack_14e4);
          iVar7 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1488);
          if (iVar7 != 0) {
            FUN_0040ea30(*(int *)((int)this + 0x20),local_1488);
            FUN_00435e83(local_c);
            return;
          }
          local_1778 = mysql_insert_id(*(undefined4 *)((int)this + 0x20));
          uVar11 = 1;
        }
        else {
          if (bStack_1772 == 0) {
            wsprintfA(local_1488,s_INSERT_INTO_LogUserItem__userid__0044b5c0,uVar6,uVar9,
                      uStack_176c & 0xffff,local_1764,0,local_174c,local_1758,aCStack_14e4);
            iVar23 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1488);
            iVar7 = *(int *)((int)this + 0x20);
            if (iVar23 != 0) goto LAB_0041a733;
            local_1778 = mysql_insert_id(iVar7);
          }
          uVar11 = 1;
        }
        wsprintfA(local_1488,s_UPDATE_useriteminfo_SET_item_sn__0044b468,local_1778,uVar11,
                  *(undefined4 *)local_1770);
        iVar7 = mysql_query(*(undefined4 *)((int)this + 8),local_1488);
        if (iVar7 != 0) {
          FUN_0040ea30(*(int *)((int)this + 8),local_1488);
        }
        bStack_1772 = bStack_1772 + 1;
      } while (bStack_1772 < bStack_177a);
    }
    if ((cVar2 == '\0') && (cVar1 == '\0')) {
      pvVar8 = (void *)FUN_0042aad0();
      iVar7 = *(int *)((int)pvVar8 + 0xd4);
      iVar23 = FUN_0041d570(pvVar8,local_1764);
      if (iVar23 == 0) {
        local_1779 = *(byte *)((uint)param_1 * 0x23b4 + 0x1530 + iVar7);
        uVar12 = _rand();
        uVar12 = uVar12 & 0x80000003;
        if ((int)uVar12 < 0) {
          uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
        }
        iVar7 = uVar12 + 0x44e;
LAB_0041a818:
        local_1760 = 1;
        local_1738[0] = *(undefined4 *)((int)pvVar8 + (iVar7 * 5 + (uint)local_1779) * 4);
      }
      else {
        if (iVar23 == 1) {
          local_1779 = *(byte *)((uint)param_1 * 0x23b4 + 0x1530 + iVar7);
          uVar12 = _rand();
          uVar12 = uVar12 & 0x80000003;
          if ((int)uVar12 < 0) {
            uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
          }
          iVar7 = uVar12 + 0x44a;
          goto LAB_0041a818;
        }
        local_1760 = 0;
      }
      uStack_176c = 0;
      if (local_1760 != 0) {
        do {
          uVar9 = local_1738[uStack_176c];
          wsprintfA(local_1488,s_INSERT_INTO_pendingpresents__pre_00449868,uVar9,uVar6);
          iVar7 = mysql_query(*(undefined4 *)((int)this + 8),local_1488);
          if (iVar7 == 0) {
            uVar11 = mysql_insert_id(*(undefined4 *)((int)this + 8));
            wsprintfA(local_1488,s_INSERT_INTO_logpresent__pending__004497f8,uVar11,uVar9,uVar6);
            iVar7 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1488);
            if (iVar7 != 0) {
              FUN_0040ea30(*(int *)((int)this + 0x20),local_1488);
            }
          }
          else {
            FUN_0040ea30(*(int *)((int)this + 8),local_1488);
            local_1760 = 0;
          }
          uStack_176c = uStack_176c + 1;
        } while ((int)uStack_176c < local_1760);
      }
    }
  }
  uStack_1010._0_2_ = param_2;
  uStack_1010._2_2_ = 0x14;
  cStack_100c = cStack_1773;
  uVar13 = 5;
  if (cStack_1773 == '\0') {
    lStack_100b = local_1758;
    lStack_1007 = local_1750;
    bStack_1003 = bStack_177a;
    iVar7 = 0xe;
    if (bStack_177a != 0) {
      uVar13 = (ushort)bStack_177a;
      uStack_176c = (uint)uVar13;
      uVar14 = (uint)uVar13;
      pbVar17 = abStack_14a8;
      pbVar19 = abStack_1002;
      for (uVar12 = uVar14; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 *)pbVar19 = *(undefined4 *)pbVar17;
        pbVar17 = pbVar17 + 4;
        pbVar19 = pbVar19 + 4;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pbVar19 = *pbVar17;
        pbVar17 = pbVar17 + 1;
        pbVar19 = pbVar19 + 1;
      }
      pbVar17 = abStack_14ec;
      pbVar19 = abStack_1002 + uVar14 * 4;
      for (uVar12 = (uint)(bStack_177a >> 2); uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 *)pbVar19 = *(undefined4 *)pbVar17;
        pbVar17 = pbVar17 + 4;
        pbVar19 = pbVar19 + 4;
      }
      for (uVar12 = uVar13 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pbVar19 = *pbVar17;
        pbVar17 = pbVar17 + 1;
        pbVar19 = pbVar19 + 1;
      }
      iVar7 = uVar14 * 4 + 0xe + uStack_176c;
      puVar15 = auStack_14cc;
      pbVar17 = abStack_1002 + iVar7 + -0xe;
      for (uVar12 = (uint)(bStack_177a >> 1); uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 *)pbVar17 = *(undefined4 *)puVar15;
        puVar15 = puVar15 + 2;
        pbVar17 = pbVar17 + 4;
      }
      for (uVar12 = uStack_176c * 2 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pbVar17 = (byte)*puVar15;
        puVar15 = (ushort *)((int)puVar15 + 1);
        pbVar17 = pbVar17 + 1;
      }
      iVar7 = iVar7 + uStack_176c * 2;
      ppuVar16 = apuStack_14f4;
      pbVar17 = abStack_1002 + iVar7 + -0xe;
      for (uVar12 = (uint)(bStack_177a >> 2); uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 **)pbVar17 = *ppuVar16;
        ppuVar16 = ppuVar16 + 1;
        pbVar17 = pbVar17 + 4;
      }
      for (uVar12 = uVar13 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pbVar17 = *(byte *)ppuVar16;
        ppuVar16 = (undefined4 **)((int)ppuVar16 + 1);
        pbVar17 = pbVar17 + 1;
      }
      iVar7 = iVar7 + uStack_176c;
    }
    *(char *)((int)&uStack_1010 + iVar7) = cVar2;
    *(undefined2 *)((int)&uStack_1010 + iVar7 + 1) = uVar5;
    uVar12 = iVar7 + 4;
    uVar13 = (ushort)uVar12;
    iVar23 = 0;
    *(char *)((int)&uStack_1010 + iVar7 + 3) = (char)local_1760;
    if (local_1760 != 0) {
      do {
        puVar10 = local_1738 + iVar23;
        uVar14 = uVar12 & 0xffff;
        uVar12 = uVar12 + 4;
        uVar13 = (ushort)uVar12;
        iVar23 = iVar23 + 1;
        *(undefined4 *)((int)&uStack_1010 + uVar14) = *puVar10;
      } while (iVar23 < local_1760);
    }
  }
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar13,&uStack_1010);
LAB_00419e1b:
  FUN_00435e83(local_c);
  return;
}
