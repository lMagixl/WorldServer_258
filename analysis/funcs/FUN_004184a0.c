
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_004184a0(void *this,ushort param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  ushort uVar8;
  uint uVar9;
  char *pcVar10;
  int iVar11;
  undefined1 local_1446;
  byte bStack_1445;
  int local_1444;
  int iStack_1440;
  uint local_143c;
  int local_1438;
  undefined4 *local_1434;
  long local_1430;
  undefined4 local_1428 [4];
  CHAR local_1418 [20];
  CHAR local_1404 [1024];
  undefined4 local_1004;
  undefined1 local_1000;
  long local_fff;
  uint local_ffb;
  undefined4 *local_ff7;
  undefined1 local_ff3;
  int local_4;
  
  local_4 = DAT_00454928;
  local_1430 = 0;
  local_1438 = 0;
  local_1428[0] = 0;
  local_1428[1] = 0;
  local_1428[2] = 0;
  local_1428[3] = 0;
  uVar5 = *param_4;
  uVar8 = *(ushort *)(param_4 + 3);
  uVar9 = param_4[2];
  local_1446 = 0;
  wsprintfA(local_1404,s_SELECT_name_gold_FROM_UserGameIn_0044af24,uVar5);
  uVar1 = *(undefined4 *)((int)this + 8);
  iVar3 = mysql_query(uVar1,local_1404);
  if ((iVar3 == 0) && (iVar3 = mysql_store_result(uVar1), iVar3 != 0)) {
    local_1434 = (undefined4 *)mysql_fetch_row(iVar3);
    if (local_1434 != (undefined4 *)0x0) {
      lstrcpyA(local_1418,(LPCSTR)*local_1434);
      local_1430 = _atol((char *)local_1434[1]);
    }
    mysql_free_result(iVar3);
    local_143c = 0;
    wsprintfA(local_1404,s_SELECT_cash_FROM_Cash_WHERE_id___0044a004,local_1418);
    uVar1 = *(undefined4 *)((int)this + 0xc);
    iVar3 = mysql_query(uVar1,local_1404);
    if ((iVar3 == 0) && (iVar3 = mysql_store_result(uVar1), iVar3 != 0)) {
      puVar6 = (undefined4 *)mysql_fetch_row(iVar3);
      if (puVar6 != (undefined4 *)0x0) {
        local_143c = _atol((char *)*puVar6);
      }
      uVar2 = local_143c;
      mysql_free_result(iVar3);
      if (local_143c < uVar9) {
        local_1446 = 2;
        goto LAB_00418a51;
      }
      iStack_1440 = 0;
      wsprintfA(local_1404,s_SELECT_stagelevelfree_FROM_UserG_0044b238,uVar5);
      uVar1 = *(undefined4 *)((int)this + 8);
      iVar3 = mysql_query(uVar1,local_1404);
      if ((iVar3 != 0) || (iVar3 = mysql_store_result(uVar1), iVar3 == 0)) {
        FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuyStageLevelF_0044b208);
        local_1446 = 1;
        goto LAB_00418a51;
      }
      puVar6 = (undefined4 *)mysql_fetch_row(iVar3);
      if (puVar6 != (undefined4 *)0x0) {
        iStack_1440 = _atol((char *)*puVar6);
      }
      mysql_free_result(iVar3);
      wsprintfA(local_1404,s_SELECT__to_days_now____24_hour_n_004489ec);
      iVar3 = FUN_0040eac0(*(undefined4 *)((int)this + 8),local_1404);
      if (iVar3 == 0) {
        FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandInventoryBuyStageLevelF_0044b1d8);
        local_1446 = 1;
        goto LAB_00418a51;
      }
      puVar6 = (undefined4 *)mysql_fetch_row(iVar3);
      if (puVar6 == (undefined4 *)0x0) {
        FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandInventoryBuyStageLevelF_0044b174);
        local_1446 = 1;
        mysql_free_result(iVar3);
        goto LAB_00418a51;
      }
      local_1434 = (undefined4 *)_atol((char *)*puVar6);
      mysql_free_result(iVar3);
      if (local_1434 <= (undefined4 *)(iStack_1440 + 0x5a0)) {
        local_1446 = 3;
        goto LAB_00418a51;
      }
      wsprintfA(local_1404,s_UPDATE_usergameinfo_SET_stagelev_0044b1a0,local_1434,uVar5);
      iVar3 = mysql_query(*(undefined4 *)((int)this + 8),local_1404);
      if (iVar3 != 0) {
        FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandInventoryBuyStageRankCl_0044b084);
        local_1446 = 1;
        goto LAB_00418a51;
      }
      wsprintfA(local_1404,s_UPDATE_cash_SET_cash___cash____u_0044ae18,uVar9,local_1418,uVar9);
      iVar3 = mysql_query(*(undefined4 *)((int)this + 0xc),local_1404);
      if (iVar3 != 0) {
        FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuyStageRankCl_0044b0b4);
        local_1446 = 1;
        goto LAB_00418a51;
      }
      wsprintfA(local_1404,s_SELECT_gold_FROM_UserGameInfo_WH_00449f70,uVar5);
      iVar3 = FUN_0040eac0(*(undefined4 *)((int)this + 8),local_1404);
      if (iVar3 == 0) {
        FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuyStageRankCl_0044b084);
        local_1446 = 1;
        goto LAB_00418a51;
      }
      puVar6 = (undefined4 *)mysql_fetch_row(iVar3);
      if (puVar6 != (undefined4 *)0x0) {
        local_1430 = _atol((char *)*puVar6);
      }
      mysql_free_result(iVar3);
      wsprintfA(local_1404,s_SELECT_cash_FROM_Cash_WHERE_id___0044a004,local_1418);
      iVar3 = FUN_0040eac0(*(undefined4 *)((int)this + 0xc),local_1404);
      if (iVar3 == 0) {
        FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuyStageRankCl_0044b054);
        local_1446 = 1;
        goto LAB_00418a51;
      }
      puVar6 = (undefined4 *)mysql_fetch_row(iVar3);
      if (puVar6 != (undefined4 *)0x0) {
        local_143c = _atol((char *)*puVar6);
      }
      mysql_free_result(iVar3);
      wsprintfA(local_1404,s_INSERT_INTO_LogBuyCashItem__user_0044aca0,uVar5,(uint)uVar8,uVar9,uVar2
                ,local_143c);
      iVar3 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1404);
      if (iVar3 != 0) {
        FUN_0040ea30(*(int *)((int)this + 0x20),local_1404);
        goto LAB_00418a51;
      }
      local_1446 = 0;
      pvVar4 = (void *)FUN_0042aad0();
      iVar3 = *(int *)((int)pvVar4 + 0xd4);
      iVar11 = FUN_0041d570(pvVar4,uVar9);
      if (iVar11 == 0) {
        bStack_1445 = *(byte *)((uint)param_1 * 0x23b4 + 0x1530 + iVar3);
        uVar9 = _rand();
        uVar9 = uVar9 & 0x80000003;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
        }
        iVar3 = uVar9 + 0x44e;
LAB_0041897a:
        local_1438 = 1;
        local_1428[0] = *(undefined4 *)((int)pvVar4 + (iVar3 * 5 + (uint)bStack_1445) * 4);
      }
      else {
        if (iVar11 == 1) {
          bStack_1445 = *(byte *)((uint)param_1 * 0x23b4 + 0x1530 + iVar3);
          uVar9 = _rand();
          uVar9 = uVar9 & 0x80000003;
          if ((int)uVar9 < 0) {
            uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
          }
          iVar3 = uVar9 + 0x44a;
          goto LAB_0041897a;
        }
        local_1438 = 0;
      }
      local_1444 = 0;
      if (local_1438 != 0) {
        do {
          uVar1 = local_1428[local_1444];
          wsprintfA(local_1404,s_INSERT_INTO_pendingpresents__pre_00449868,uVar1,uVar5);
          iVar3 = mysql_query(*(undefined4 *)((int)this + 8),local_1404);
          if (iVar3 == 0) {
            uVar7 = mysql_insert_id(*(int *)((int)this + 8));
            wsprintfA(local_1404,s_INSERT_INTO_logpresent__pending__004497f8,uVar7,uVar1,uVar5);
            iVar3 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1404);
            if (iVar3 != 0) {
              FUN_0040ea30(*(int *)((int)this + 0x20),local_1404);
            }
          }
          else {
            FUN_0040ea30(*(int *)((int)this + 8),local_1404);
            local_1438 = 0;
          }
          local_1444 = local_1444 + 1;
        } while (local_1444 < local_1438);
      }
      goto LAB_00418a51;
    }
    iVar3 = *(int *)((int)this + 0xc);
    iVar11 = -1;
    pcVar10 = s_DBCommandInventoryBuyStageLevelF_0044b26c;
    pvVar4 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar4,pcVar10,iVar11);
    if (iVar3 != 0) {
      iVar11 = -1;
      uVar5 = mysql_error(iVar3);
      pvVar4 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar4,uVar5,iVar11);
      local_1446 = 1;
      goto LAB_00418a51;
    }
  }
  else {
    iVar3 = *(int *)((int)this + 0xc);
    iVar11 = -1;
    pcVar10 = s_DBCommandInventoryBuyStageLevelF_0044b29c;
    pvVar4 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar4,pcVar10,iVar11);
    if (iVar3 != 0) {
      iVar11 = -1;
      uVar5 = mysql_error(iVar3);
      pvVar4 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar4,uVar5,iVar11);
    }
  }
  local_143c = 0;
  local_1446 = 1;
LAB_00418a51:
  local_1000 = local_1446;
  local_1004._0_2_ = param_2;
  local_ff7 = local_1434;
  local_fff = local_1430;
  iVar3 = 0;
  local_ffb = local_143c;
  local_1004._2_2_ = 0x24;
  local_ff3 = (char)local_1438;
  uVar8 = 0x12;
  if (local_1438 != 0) {
    uVar8 = 0x12;
    do {
      puVar6 = local_1428 + iVar3;
      uVar9 = (uint)uVar8;
      uVar8 = uVar8 + 4;
      iVar3 = iVar3 + 1;
      *(undefined4 *)((int)&local_1004 + uVar9) = *puVar6;
    } while (iVar3 < local_1438);
  }
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar8,&local_1004);
  FUN_00435e83(local_4);
  return;
}


