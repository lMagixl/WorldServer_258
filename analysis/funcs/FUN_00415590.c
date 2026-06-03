
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00415590(void *this,ushort param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  char cVar2;
  undefined2 uVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  ushort uVar10;
  ushort uVar11;
  int iVar12;
  CHAR *pCVar13;
  longlong lVar14;
  char *pcVar15;
  int iVar16;
  char local_1478;
  byte bStack_1476;
  int local_1474;
  uint local_1470;
  undefined4 local_1468;
  long local_1464;
  int local_1460;
  undefined4 local_145c;
  long local_1458;
  undefined4 local_144c [4];
  CHAR local_143c [20];
  CHAR aCStack_1428 [24];
  CHAR local_1410;
  CHAR local_140f [2];
  CHAR aCStack_140d [1021];
  undefined4 local_1010;
  char local_100c;
  long local_100b;
  long local_1007;
  byte local_1003;
  char local_1002;
  undefined2 local_1001;
  undefined1 local_fff;
  int local_c;
  
  local_c = DAT_00454928;
  local_143c[1] = '\0';
  local_143c[2] = '\0';
  local_143c[3] = '\0';
  local_143c[4] = '\0';
  local_143c[5] = '\0';
  local_143c[6] = '\0';
  local_143c[7] = '\0';
  local_143c[8] = '\0';
  local_143c[9] = '\0';
  local_143c[10] = '\0';
  local_143c[0xb] = '\0';
  local_143c[0xc] = '\0';
  local_143c[0xd] = '\0';
  local_143c[0xe] = '\0';
  local_143c[0xf] = '\0';
  local_143c[0x10] = '\0';
  local_1410 = '\0';
  pCVar13 = local_140f;
  for (iVar12 = 0xff; iVar12 != 0; iVar12 = iVar12 + -1) {
    pCVar13[0] = '\0';
    pCVar13[1] = '\0';
    pCVar13[2] = '\0';
    pCVar13[3] = '\0';
    pCVar13 = pCVar13 + 4;
  }
  pCVar13[0] = '\0';
  pCVar13[1] = '\0';
  pCVar13[2] = '\0';
  cVar1 = *(char *)(param_4 + 1);
  uVar5 = *param_4;
  cVar2 = *(char *)((int)param_4 + 5);
  local_143c[0] = '\0';
  local_1474 = 0;
  local_144c[0] = 0;
  local_144c[1] = 0;
  local_144c[2] = 0;
  local_144c[3] = 0;
  local_1470 = 0;
  local_1464 = 0;
  local_1458 = 0;
  local_145c = 0;
  local_1468 = 0;
  local_1460 = 0;
  uVar3 = 0;
  if (cVar2 == '\x01') {
    local_145c = *(undefined4 *)((int)param_4 + 6);
    local_1468 = *(undefined4 *)((int)param_4 + 10);
    local_1460 = *(int *)((int)param_4 + 0xe);
    uVar3 = *(undefined2 *)((int)param_4 + 0x12);
  }
  wsprintfA(&local_1410,s_SELECT_name_FROM_UserGameInfo_WH_0044a064,uVar5);
  uVar8 = *(undefined4 *)((int)this + 8);
  iVar12 = mysql_query(uVar8,&local_1410);
  if ((iVar12 != 0) || (iVar12 = mysql_store_result(uVar8), iVar12 == 0)) {
    iVar12 = *(int *)((int)this + 8);
    iVar16 = -1;
    pcVar15 = s_DBCommandInventoryBuySlot___mysq_0044a0f8;
    pvVar4 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar4,pcVar15,iVar16);
    if (iVar12 != 0) {
      iVar16 = -1;
      uVar5 = mysql_error(iVar12);
      pvVar4 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar4,uVar5,iVar16);
    }
    local_1478 = '\x01';
    goto LAB_00415bec;
  }
  puVar6 = (undefined4 *)mysql_fetch_row(iVar12);
  if (puVar6 == (undefined4 *)0x0) {
LAB_00415be1:
    mysql_free_result(iVar12);
    local_1478 = '\x02';
    goto LAB_00415bec;
  }
  lstrcpyA(local_143c,(LPCSTR)*puVar6);
  mysql_free_result(iVar12);
  pCVar13 = &local_1410;
  for (iVar12 = 0x100; iVar12 != 0; iVar12 = iVar12 + -1) {
    pCVar13[0] = '\0';
    pCVar13[1] = '\0';
    pCVar13[2] = '\0';
    pCVar13[3] = '\0';
    pCVar13 = pCVar13 + 4;
  }
  wsprintfA(&local_1410,s_SELECT_cash_FROM_Cash_WHERE_id___0044a004,local_143c);
  uVar8 = *(undefined4 *)((int)this + 0xc);
  iVar12 = mysql_query(uVar8,&local_1410);
  if ((iVar12 != 0) || (iVar12 = mysql_store_result(uVar8), iVar12 == 0)) {
    FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuySlot___mysq_0044a0f8);
    local_1478 = '\x01';
    goto LAB_00415bec;
  }
  puVar6 = (undefined4 *)mysql_fetch_row(iVar12);
  if (puVar6 != (undefined4 *)0x0) {
    local_1470 = _atol((char *)*puVar6);
  }
  mysql_free_result(iVar12);
  uVar7 = ((6000U - local_1460) / 100) * 100;
  if (local_1470 < uVar7) {
    local_1478 = '\x03';
    goto LAB_00415bec;
  }
  wsprintfA(&local_1410,s_UPDATE_Cash_SET_cash_cash__u_WHE_00449fc8,uVar7,local_143c,uVar7);
  iVar12 = mysql_query(*(undefined4 *)((int)this + 0xc),&local_1410);
  if (iVar12 != 0) {
    FUN_0040ea30(*(int *)((int)this + 0xc),&local_1410);
    local_1478 = '\x01';
    goto LAB_00415bec;
  }
  lVar14 = mysql_affected_rows(*(undefined4 *)((int)this + 0xc));
  if (lVar14 == 0) {
    local_1478 = '\x04';
    goto LAB_00415bec;
  }
  local_1478 = '\0';
  wsprintfA(&local_1410,s_UPDATE_UserGameInfo_SET_slot__u_W_0044a0c8,(uint)(byte)(cVar1 + 1U),uVar5)
  ;
  iVar12 = mysql_query(*(undefined4 *)((int)this + 8),&local_1410);
  if (iVar12 != 0) {
    FUN_0040ea30(*(int *)((int)this + 8),&local_1410);
    local_1478 = '\x01';
    goto LAB_00415bec;
  }
  wsprintfA(&local_1410,s_SELECT_gold_FROM_UserGameInfo_WH_00449f70,uVar5);
  iVar12 = FUN_0040eac0(*(undefined4 *)((int)this + 8),&local_1410);
  if (iVar12 == 0) {
    FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandInventoryBuySlot___mysq_0044a0f8);
    local_1478 = '\x01';
    goto LAB_00415bec;
  }
  puVar6 = (undefined4 *)mysql_fetch_row(iVar12);
  if (puVar6 == (undefined4 *)0x0) {
    FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandInventoryBuySlot___mysq_0044a090);
    goto LAB_00415be1;
  }
  local_1458 = _atol((char *)*puVar6);
  mysql_free_result(iVar12);
  pCVar13 = &local_1410;
  for (iVar12 = 0x100; iVar12 != 0; iVar12 = iVar12 + -1) {
    pCVar13[0] = '\0';
    pCVar13[1] = '\0';
    pCVar13[2] = '\0';
    pCVar13[3] = '\0';
    pCVar13 = pCVar13 + 4;
  }
  wsprintfA(&local_1410,s_SELECT_cash_FROM_Cash_WHERE_id____004493ec,local_143c);
  iVar12 = FUN_0040eac0(*(undefined4 *)((int)this + 0xc),&local_1410);
  if (iVar12 == 0) {
    FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandInventoryBuySlot___mysq_0044a0f8);
    local_1478 = '\x01';
    goto LAB_00415bec;
  }
  puVar6 = (undefined4 *)mysql_fetch_row(iVar12);
  if (puVar6 == (undefined4 *)0x0) {
    local_1478 = '\x02';
    mysql_free_result(iVar12);
    goto LAB_00415bec;
  }
  local_1464 = _atol((char *)*puVar6);
  mysql_free_result(iVar12);
  wsprintfA(aCStack_1428,(LPCSTR)&param_2_00449a10);
  if (cVar2 != '\0') {
    wsprintfA(&local_1410,s_DELETE_FROM_useriteminfo_WHERE_i_004499e8,local_145c);
    iVar12 = mysql_query(*(undefined4 *)((int)this + 8),&local_1410);
    if (iVar12 != 0) {
      FUN_0040ea30(*(int *)((int)this + 8),&local_1410);
      FUN_00435e83(local_c);
      return;
    }
    wsprintfA(&local_1410,s_INSERT_INTO_logcoupon__coupon_id_00449978,local_1468,0x2717,uVar5,
              ((local_1460 + 99U) / 100) * 100);
    iVar12 = mysql_query(*(undefined4 *)((int)this + 0x20),&local_1410);
    if (iVar12 != 0) {
      FUN_0040ea30(*(int *)((int)this + 0x20),&local_1410);
      FUN_00435e83(local_c);
      return;
    }
    uVar8 = mysql_insert_id(*(undefined4 *)((int)this + 0x20));
    wsprintfA(aCStack_1428,(LPCSTR)&param_2_00449974,uVar8);
  }
  wsprintfA(&local_1410,s_INSERT_INTO_LogBuyCashItem__user_00449ef0,uVar5,0x2717,uVar7,local_1470,
            local_1464,aCStack_1428);
  iVar12 = mysql_query(*(undefined4 *)((int)this + 0x20),&local_1410);
  if (iVar12 != 0) {
    FUN_0040ea30(*(int *)((int)this + 0x20),&local_1410);
    local_1478 = '\x01';
    goto LAB_00415bec;
  }
  if (cVar2 != '\0') goto LAB_00415bec;
  pvVar4 = (void *)FUN_0042aad0();
  iVar12 = *(int *)((int)pvVar4 + 0xd4);
  iVar16 = FUN_0041d570(pvVar4,uVar7);
  if (iVar16 == 0) {
    bStack_1476 = *(byte *)((uint)param_1 * 0x23b4 + 0x1530 + iVar12);
    uVar7 = _rand();
    uVar7 = uVar7 & 0x80000003;
    if ((int)uVar7 < 0) {
      uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
    }
    iVar12 = uVar7 + 0x44e;
LAB_00415af0:
    local_1474 = 1;
    local_144c[0] = *(undefined4 *)((int)pvVar4 + (iVar12 * 5 + (uint)bStack_1476) * 4);
  }
  else {
    if (iVar16 == 1) {
      bStack_1476 = *(byte *)((uint)param_1 * 0x23b4 + 0x1530 + iVar12);
      uVar7 = _rand();
      uVar7 = uVar7 & 0x80000003;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
      }
      iVar12 = uVar7 + 0x44a;
      goto LAB_00415af0;
    }
    local_1474 = 0;
  }
  local_1470 = 0;
  if (local_1474 != 0) {
    do {
      uVar8 = local_144c[local_1470];
      wsprintfA(&local_1410,s_INSERT_INTO_pendingpresents__pre_00449868,uVar8,uVar5);
      iVar12 = mysql_query(*(undefined4 *)((int)this + 8),&local_1410);
      if (iVar12 == 0) {
        uVar9 = mysql_insert_id(*(int *)((int)this + 8));
        wsprintfA(&local_1410,s_INSERT_INTO_logpresent__pending__004497f8,uVar9,uVar8,uVar5);
        iVar12 = mysql_query(*(undefined4 *)((int)this + 0x20),&local_1410);
        if (iVar12 != 0) {
          FUN_0040ea30(*(int *)((int)this + 0x20),&local_1410);
        }
      }
      else {
        FUN_0040ea30(*(int *)((int)this + 8),&local_1410);
        local_1474 = 0;
      }
      local_1470 = local_1470 + 1;
    } while ((int)local_1470 < local_1474);
  }
LAB_00415bec:
  local_1010._0_2_ = param_2;
  local_1010._2_2_ = 0x18;
  local_100c = local_1478;
  uVar10 = 5;
  if (local_1478 == '\0') {
    local_100b = local_1458;
    local_1007 = local_1464;
    local_1002 = cVar2;
    local_1001 = uVar3;
    iVar12 = 0;
    local_1003 = cVar1 + 1U;
    local_fff = (char)local_1474;
    uVar10 = 0x12;
    uVar11 = 0x12;
    if (local_1474 != 0) {
      do {
        puVar6 = local_144c + iVar12;
        uVar10 = uVar11 + 4;
        iVar12 = iVar12 + 1;
        *(undefined4 *)((int)&local_1010 + (uint)uVar11) = *puVar6;
        uVar11 = uVar10;
      } while (iVar12 < local_1474);
    }
  }
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar10,&local_1010);
  FUN_00435e83(local_c);
  return;
}


