
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00417800(void *this,ushort param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 uVar10;
  ushort uVar11;
  char *pcVar13;
  int iVar14;
  undefined1 local_144a;
  byte local_1449;
  int local_1448;
  int local_1444;
  uint local_1440;
  uint local_143c;
  undefined4 local_1428 [4];
  CHAR local_1418 [20];
  CHAR local_1404 [1024];
  undefined4 local_1004;
  undefined1 local_1000;
  uint local_fff;
  uint local_ffb;
  undefined1 local_ff7;
  int local_4;
  ushort uVar12;
  
  local_4 = DAT_00454928;
  uVar7 = param_4[1];
  uVar2 = *param_4;
  cVar1 = *(char *)(param_4 + 2);
  local_1444 = 0;
  local_1428[0] = 0;
  local_1428[1] = 0;
  local_1428[2] = 0;
  local_1428[3] = 0;
  uVar9 = *(uint *)((int)param_4 + 9);
  uVar12 = *(ushort *)((int)param_4 + 0xd);
  local_144a = 0;
  local_143c = 0;
  local_1440 = 0;
  wsprintfA(local_1404,s_SELECT_name_gold_FROM_UserGameIn_0044af24,uVar2);
  uVar10 = *(undefined4 *)((int)this + 8);
  iVar5 = mysql_query(uVar10,local_1404);
  if ((iVar5 == 0) && (iVar5 = mysql_store_result(uVar10), iVar5 != 0)) {
    puVar8 = (undefined4 *)mysql_fetch_row(iVar5);
    if (puVar8 != (undefined4 *)0x0) {
      lstrcpyA(local_1418,(LPCSTR)*puVar8);
      local_143c = _atol((char *)puVar8[1]);
    }
    uVar4 = local_143c;
    mysql_free_result(iVar5);
    wsprintfA(local_1404,s_SELECT_cash_FROM_Cash_WHERE_id___0044a004,local_1418);
    uVar10 = *(undefined4 *)((int)this + 0xc);
    iVar5 = mysql_query(uVar10,local_1404);
    if ((iVar5 == 0) && (iVar5 = mysql_store_result(uVar10), iVar5 != 0)) {
      puVar8 = (undefined4 *)mysql_fetch_row(iVar5);
      if (puVar8 != (undefined4 *)0x0) {
        local_1440 = _atol((char *)*puVar8);
      }
      uVar3 = local_1440;
      mysql_free_result(iVar5);
      if (cVar1 == '\0') {
        if (local_143c < uVar9) {
          local_144a = 4;
          goto LAB_00417d6b;
        }
      }
      else if (local_1440 < uVar9) {
        local_144a = 4;
        goto LAB_00417d6b;
      }
      wsprintfA(local_1404,s_UPDATE_characterinfo_SET_potions_0044ae88,uVar7);
      iVar5 = mysql_query(*(undefined4 *)((int)this + 8),local_1404);
      if (iVar5 != 0) {
        FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuyPotionSlot__0044ae58);
        local_144a = 2;
        goto LAB_00417d6b;
      }
      if (cVar1 == '\0') {
        wsprintfA(local_1404,s_UPDATE_usergameinfo_SET_gold___g_0044ada8,uVar9,uVar2,uVar9);
        iVar5 = mysql_query(*(undefined4 *)((int)this + 8),local_1404);
        if (iVar5 != 0) {
          FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuyPotionSlot__0044ad78);
          local_144a = 2;
          goto LAB_00417d6b;
        }
      }
      else {
        wsprintfA(local_1404,s_UPDATE_cash_SET_cash___cash____u_0044ae18,uVar9,local_1418,uVar9);
        iVar5 = mysql_query(*(undefined4 *)((int)this + 0xc),local_1404);
        if (iVar5 != 0) {
          FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuyPotionSlot__0044adec);
          local_144a = 2;
          goto LAB_00417d6b;
        }
      }
      wsprintfA(local_1404,s_SELECT_gold_FROM_UserGameInfo_WH_00449f70,uVar2);
      iVar5 = FUN_0040eac0(*(undefined4 *)((int)this + 8),local_1404);
      if (iVar5 == 0) {
        FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuyPotionSlot__0044ad4c);
        local_144a = 2;
        goto LAB_00417d6b;
      }
      puVar8 = (undefined4 *)mysql_fetch_row(iVar5);
      if (puVar8 != (undefined4 *)0x0) {
        local_143c = _atol((char *)*puVar8);
      }
      mysql_free_result(iVar5);
      wsprintfA(local_1404,s_SELECT_cash_FROM_Cash_WHERE_id___0044a004,local_1418);
      iVar5 = FUN_0040eac0(*(undefined4 *)((int)this + 0xc),local_1404);
      if (iVar5 == 0) {
        FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuyPotionSlot__0044ad20);
        local_144a = 2;
        goto LAB_00417d6b;
      }
      puVar8 = (undefined4 *)mysql_fetch_row(iVar5);
      if (puVar8 != (undefined4 *)0x0) {
        local_1440 = _atol((char *)*puVar8);
      }
      mysql_free_result(iVar5);
      if (cVar1 == '\0') {
        wsprintfA(local_1404,s_INSERT_INTO_LogUserItem__userid__0044ac10,uVar2,uVar7,(uint)uVar12,
                  uVar9,uVar4,local_143c);
        iVar5 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1404);
        if (iVar5 != 0) {
          FUN_0040ea30(*(int *)((int)this + 0x20),local_1404);
        }
        goto LAB_00417d6b;
      }
      wsprintfA(local_1404,s_INSERT_INTO_LogBuyCashItem__user_0044aca0,uVar2,(uint)uVar12,uVar9,
                uVar3,local_1440);
      iVar5 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1404);
      if (iVar5 != 0) {
        FUN_0040ea30(*(int *)((int)this + 0x20),local_1404);
        goto LAB_00417d6b;
      }
      pvVar6 = (void *)FUN_0042aad0();
      iVar5 = *(int *)((int)pvVar6 + 0xd4);
      iVar14 = FUN_0041d570(pvVar6,uVar9);
      if (iVar14 == 0) {
        local_1449 = *(byte *)((uint)param_1 * 0x23b4 + 0x1530 + iVar5);
        uVar9 = _rand();
        uVar9 = uVar9 & 0x80000003;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
        }
        iVar5 = uVar9 + 0x44e;
LAB_00417cb2:
        local_1444 = 1;
        local_1428[0] = *(undefined4 *)((int)pvVar6 + (iVar5 * 5 + (uint)local_1449) * 4);
      }
      else {
        if (iVar14 == 1) {
          local_1449 = *(byte *)((uint)param_1 * 0x23b4 + 0x1530 + iVar5);
          uVar9 = _rand();
          uVar9 = uVar9 & 0x80000003;
          if ((int)uVar9 < 0) {
            uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
          }
          iVar5 = uVar9 + 0x44a;
          goto LAB_00417cb2;
        }
        local_1444 = 0;
      }
      local_1448 = 0;
      if (local_1444 != 0) {
        do {
          uVar7 = local_1428[local_1448];
          wsprintfA(local_1404,s_INSERT_INTO_pendingpresents__pre_00449868,uVar7,uVar2);
          iVar5 = mysql_query(*(undefined4 *)((int)this + 8),local_1404);
          if (iVar5 == 0) {
            uVar10 = mysql_insert_id(*(int *)((int)this + 8));
            wsprintfA(local_1404,s_INSERT_INTO_logpresent__pending__004497f8,uVar10,uVar7,uVar2);
            iVar5 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1404);
            if (iVar5 != 0) {
              FUN_0040ea30(*(int *)((int)this + 0x20),local_1404);
            }
          }
          else {
            FUN_0040ea30(*(int *)((int)this + 8),local_1404);
            local_1444 = 0;
          }
          local_1448 = local_1448 + 1;
        } while (local_1448 < local_1444);
      }
      goto LAB_00417d6b;
    }
    iVar5 = *(int *)((int)this + 0xc);
    iVar14 = -1;
    pcVar13 = s_DBCommandInventoryBuyPotionSlot__0044aecc;
    pvVar6 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar6,pcVar13,iVar14);
    if (iVar5 != 0) {
      iVar14 = -1;
      uVar7 = mysql_error(iVar5);
      pvVar6 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar6,uVar7,iVar14);
      local_144a = 1;
      goto LAB_00417d6b;
    }
  }
  else {
    iVar5 = *(int *)((int)this + 0xc);
    iVar14 = -1;
    pcVar13 = s_DBCommandInventoryBuyPotionSlot__0044aef8;
    pvVar6 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar6,pcVar13,iVar14);
    if (iVar5 != 0) {
      iVar14 = -1;
      uVar7 = mysql_error(iVar5);
      pvVar6 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar6,uVar7,iVar14);
    }
  }
  local_144a = 1;
LAB_00417d6b:
  local_1004._0_2_ = param_2;
  local_1000 = local_144a;
  local_fff = local_143c;
  iVar5 = 0;
  local_ffb = local_1440;
  local_1004._2_2_ = 0x21;
  local_ff7 = (char)local_1444;
  uVar12 = 0xe;
  uVar11 = 0xe;
  if (local_1444 != 0) {
    do {
      puVar8 = local_1428 + iVar5;
      uVar11 = uVar12 + 4;
      iVar5 = iVar5 + 1;
      *(undefined4 *)((int)&local_1004 + (uint)uVar12) = *puVar8;
      uVar12 = uVar11;
    } while (iVar5 < local_1444);
  }
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar11,&local_1004);
  FUN_00435e83(local_4);
  return;
}


