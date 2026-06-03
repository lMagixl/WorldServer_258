
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* == DB COMMAND: BUY LOTTO ==
   Handles the player's request to buy a lotto ticket.
   1. Fetches user gold/cash from DB.
   2. Checks if the player has enough currency.
   3. Inserts a new lotto ticket into the DB.
   4. Subtracts the cost from the player's currency. */

void __thiscall
FUN_0040ec50(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  void *pvVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  char *pcVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  undefined1 local_1431;
  int local_1430;
  uint local_142c;
  CHAR local_1418 [20];
  CHAR local_1404 [1024];
  undefined2 local_1004;
  undefined2 local_1002;
  int local_1000;
  char local_ffc;
  undefined1 local_ffb;
  int local_4;
  
  cVar1 = *(char *)(param_4 + 1);
  local_4 = DAT_00454928;
  uVar9 = *param_4;
  local_1431 = 3;
  local_1430 = 0;
  local_142c = 0;
  wsprintfA(local_1404,s_SELECT_name__gold_FROM_UserGameI_00447c9c,uVar9);
  uVar12 = *(undefined4 *)((int)this + 8);
  iVar7 = mysql_query(uVar12,local_1404);
  if (iVar7 == 0) {
    iVar7 = mysql_store_result(uVar12);
    if (iVar7 != 0) {
      puVar10 = (undefined4 *)mysql_fetch_row(iVar7);
      if (puVar10 != (undefined4 *)0x0) {
        lstrcpyA(local_1418,(LPCSTR)*puVar10);
        local_142c = _atol((char *)puVar10[1]);
      }
      mysql_free_result(iVar7);
      wsprintfA(local_1404,s_SELECT_cash_FROM_Cash_WHERE_id___00447c54,local_1418);
      uVar12 = *(undefined4 *)((int)this + 0xc);
      iVar7 = mysql_query(uVar12,local_1404);
      if (iVar7 == 0) {
        iVar7 = mysql_store_result(uVar12);
        if (iVar7 != 0) {
          puVar10 = (undefined4 *)mysql_fetch_row(iVar7);
          if (puVar10 == (undefined4 *)0x0) {
            uVar11 = 0;
          }
          else {
            uVar11 = _atol((char *)*puVar10);
          }
          mysql_free_result(iVar7);
          if (cVar1 == '\0') {
            if (local_142c < 1000) {
LAB_0040ee9e:
              FUN_0042f280(s__RW____CDB__DBCommandBuyLotto_____00447b68);
              local_1431 = 1;
              goto LAB_0040f01b;
            }
          }
          else if ((cVar1 == '\x01') && (uVar11 < 100)) goto LAB_0040ee9e;
          bVar2 = *(byte *)(param_4 + 2);
          bVar3 = *(byte *)((int)param_4 + 5);
          bVar4 = *(byte *)((int)param_4 + 6);
          bVar5 = *(byte *)((int)param_4 + 7);
          bVar6 = *(byte *)((int)param_4 + 9);
          pcVar15 = s__RW____CDB__DBCommandBuyLotto_____00447bf0;
          uVar11 = (uint)bVar3;
          uVar13 = (uint)bVar4;
          uVar14 = (uint)bVar5;
          uVar16 = (uint)bVar2;
          uVar18 = (uint)bVar6;
          FUN_0042f280(s__RW____CDB__DBCommandBuyLotto_____00447bf0);
          _sprintf(local_1404,s_SELECT_MAX_no__FROM_loglottery_00447bd0,pcVar15,uVar11,uVar13,uVar14
                   ,uVar16,uVar18);
          uVar12 = *(undefined4 *)((int)this + 0x20);
          iVar7 = mysql_query(uVar12,local_1404);
          if (iVar7 == 0) {
            iVar7 = mysql_store_result(uVar12);
            if (iVar7 != 0) {
              puVar10 = (undefined4 *)mysql_fetch_row(iVar7);
              if (puVar10 != (undefined4 *)0x0) {
                local_1430 = _atol((char *)*puVar10);
              }
              mysql_free_result(iVar7);
              local_1430 = local_1430 + 1;
              FUN_0042f280(s__RW____CDB__dwNo____u_00447b4c);
              uVar12 = 0;
              if (cVar1 == '\x01') {
                uVar12 = 100;
              }
              wsprintfA(local_1404,s_INSERT_INTO_lotto__userid__no__b_00447ac8,uVar9,local_1430,
                        (uint)bVar3,(uint)bVar4,(uint)bVar5,(uint)bVar2,(uint)bVar6,1000,uVar12);
              iVar7 = mysql_query(*(undefined4 *)((int)this + 8),local_1404);
              if (iVar7 != 0) {
                iVar7 = *(int *)((int)this + 8);
                iVar17 = -1;
                pcVar15 = s_DBCommandBuyLotto___failed__3_00447aa8;
                pvVar8 = (void *)FUN_0042aad0();
                FUN_0041d380(pvVar8,pcVar15,iVar17);
                if (iVar7 != 0) {
                  iVar17 = -1;
                  uVar9 = mysql_error(iVar7);
                  pvVar8 = (void *)FUN_0042aad0();
                  FUN_0041d380(pvVar8,uVar9,iVar17);
                }
                goto LAB_0040f01b;
              }
              if (cVar1 == '\0') {
                wsprintfA(local_1404,s_UPDATE_UserGameInfo_SET_gold___g_00447a60,1000,uVar9,1000);
                iVar7 = mysql_query(*(undefined4 *)((int)this + 8),local_1404);
                if (iVar7 != 0) {
                  FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandBuyLotto___failed__4_00447a40);
                  goto LAB_0040f01b;
                }
              }
              else {
                if (cVar1 != '\x01') {
                  FUN_0042f280(s__RW____CDB__DBCommandBuyLotto_____0044799c);
                  goto LAB_0040f01b;
                }
                wsprintfA(local_1404,s_UPDATE_Cash_SET_cash___cash____u_00447a00,100,local_1418,100)
                ;
                iVar7 = mysql_query(*(undefined4 *)((int)this + 0xc),local_1404);
                if (iVar7 != 0) {
                  FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandBuyLotto___failed__5_004479dc);
                  goto LAB_0040f01b;
                }
              }
              local_1431 = 0;
              goto LAB_0040f01b;
            }
          }
          iVar7 = *(int *)((int)this + 8);
          iVar17 = -1;
          pcVar15 = s_DBCommandBuyLotto___failed__2_00447bb0;
          pvVar8 = (void *)FUN_0042aad0();
          FUN_0041d380(pvVar8,pcVar15,iVar17);
          if (iVar7 != 0) {
            iVar17 = -1;
            uVar9 = mysql_error(iVar7);
            pvVar8 = (void *)FUN_0042aad0();
            FUN_0041d380(pvVar8,uVar9,iVar17);
          }
          goto LAB_0040f01b;
        }
      }
      iVar7 = *(int *)((int)this + 0xc);
      iVar17 = -1;
      pcVar15 = s_DBCommandBuyLotto___failed__1_00447c34;
      pvVar8 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar8,pcVar15,iVar17);
      if (iVar7 != 0) {
        iVar17 = -1;
        uVar9 = mysql_error(iVar7);
        pvVar8 = (void *)FUN_0042aad0();
        FUN_0041d380(pvVar8,uVar9,iVar17);
      }
      goto LAB_0040f01b;
    }
  }
  iVar7 = *(int *)((int)this + 8);
  iVar17 = -1;
  pcVar15 = s_DBCommandBuyLotto___failed__0_00447c7c;
  pvVar8 = (void *)FUN_0042aad0();
  FUN_0041d380(pvVar8,pcVar15,iVar17);
  if (iVar7 != 0) {
    iVar17 = -1;
    uVar9 = mysql_error(iVar7);
    pvVar8 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar8,uVar9,iVar17);
  }
LAB_0040f01b:
  FUN_0042f280(s__RW____CDB__DBCommandBuyLotto_____00447960);
  local_1004 = param_2;
  local_1000 = local_1430;
  local_1002 = 0x29;
  local_ffb = local_1431;
  local_ffc = cVar1;
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,10,(undefined4 *)&local_1004);
  FUN_00435e83(local_4);
  return;
}


