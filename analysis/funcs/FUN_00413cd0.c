
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00413cd0(void *this,ushort param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined2 uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  void *pvVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  long lVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  char *pcVar19;
  char local_149f;
  byte local_149e;
  undefined4 uStack_149c;
  uint local_1498;
  int local_1494;
  long lStack_1490;
  int local_148c;
  int local_1488;
  undefined2 local_1484;
  uint local_1480;
  int local_147c;
  undefined4 local_1478;
  int local_1474;
  int local_146c;
  int local_1468;
  int local_1464;
  ushort local_1460;
  int local_145c;
  undefined4 local_1454;
  int local_1450;
  int local_144c;
  int local_1448;
  int local_1444;
  undefined4 local_1440 [4];
  CHAR aCStack_1430 [20];
  CHAR aCStack_141c [24];
  CHAR local_1404 [1024];
  undefined4 uStack_1004;
  char cStack_1000;
  int iStack_fff;
  ushort uStack_ffb;
  undefined2 uStack_ff9;
  char cStack_ff7;
  undefined2 uStack_ff6;
  undefined1 uStack_ff4;
  int local_4;
  
  iVar17 = 0;
  local_4 = DAT_00454928;
  uVar9 = *param_4;
  cVar1 = *(char *)(param_4 + 1);
  iVar16 = 0;
  local_149f = '\0';
  local_149e = 0;
  local_144c = 0;
  local_1488 = 0;
  local_1464 = 0;
  local_147c = 0;
  local_146c = 0;
  local_1444 = 0;
  local_1474 = 0;
  local_145c = 0;
  local_1450 = 0;
  local_1448 = 0;
  local_1494 = 0;
  local_1440[0] = 0;
  local_1440[1] = 0;
  local_1440[2] = 0;
  local_1440[3] = 0;
  local_1480 = 0;
  local_1484 = 0;
  uVar4 = local_1484;
  local_1484 = 0;
  local_1460 = 0;
  uVar5 = local_1460;
  local_1460 = 0;
  local_1498 = 0;
  local_1468 = 0;
  local_1454 = 0;
  local_1478 = 0;
  local_148c = 0;
  uVar2 = 0;
  if (cVar1 == '\x01') {
    local_1454 = *(undefined4 *)((int)param_4 + 5);
    local_1478 = *(undefined4 *)((int)param_4 + 9);
    local_148c = *(int *)((int)param_4 + 0xd);
    uVar2 = *(undefined2 *)((int)param_4 + 0x11);
  }
  wsprintfA(local_1404,s_SELECT_a_level_b_powerlevelpoint_00449b68,uVar9);
  uVar12 = *(undefined4 *)((int)this + 8);
  iVar7 = mysql_query(uVar12,local_1404);
  if ((iVar7 == 0) && (iVar7 = mysql_store_result(uVar12), iVar7 != 0)) {
    puVar10 = (undefined4 *)mysql_fetch_row(iVar7);
    while (puVar10 != (undefined4 *)0x0) {
      lVar11 = _atol((char *)*puVar10);
      local_149e = (byte)lVar11;
      local_144c = _atol((char *)puVar10[1]);
      local_1488 = _atol((char *)puVar10[2]);
      iVar17 = _atol((char *)puVar10[3]);
      iVar16 = _atol((char *)puVar10[4]);
      local_1464 = _atol((char *)puVar10[5]);
      local_147c = _atol((char *)puVar10[6]);
      local_146c = _atol((char *)puVar10[7]);
      local_1444 = _atol((char *)puVar10[8]);
      local_1474 = _atol((char *)puVar10[9]);
      local_145c = _atol((char *)puVar10[10]);
      local_1450 = _atol((char *)puVar10[0xb]);
      local_1448 = _atol((char *)puVar10[0xc]);
      lStack_1490 = _atol((char *)puVar10[0xd]);
      lstrcpyA(aCStack_1430,(LPCSTR)puVar10[0xe]);
      puVar10 = (undefined4 *)mysql_fetch_row(iVar7);
    }
    mysql_free_result(iVar7);
    iVar17 = local_1448 + local_1450 + local_145c + local_1474 + local_1444 + local_146c +
             local_147c + local_1464 + iVar16 + iVar17;
    local_1460 = uVar5;
    local_1484 = uVar4;
    if ((short)iVar17 == 0) {
      local_149f = '\x02';
    }
    else {
      wsprintfA(local_1404,s_SELECT_cash_FROM_Cash_WHERE_id___00449b00,aCStack_1430);
      uVar12 = *(undefined4 *)((int)this + 0xc);
      iVar16 = mysql_query(uVar12,local_1404);
      if ((iVar16 == 0) && (iVar16 = mysql_store_result(uVar12), iVar16 != 0)) {
        puVar10 = (undefined4 *)mysql_fetch_row(iVar16);
        while (puVar10 != (undefined4 *)0x0) {
          local_1498 = _atol((char *)*puVar10);
          puVar10 = (undefined4 *)mysql_fetch_row(iVar16);
        }
        mysql_free_result(iVar16);
        if (local_149e < 0x29) {
          if (local_149e < 0x10) {
            uStack_149c = 0x2712;
          }
          else {
            uStack_149c = 0x2713;
          }
        }
        else {
          uStack_149c = 0x2714;
        }
        uVar14 = (uint)(local_148c * 0x1324) / 100;
        uVar15 = (0x1324 - uVar14) / 100;
        uVar18 = uVar15 * 100;
        if (local_1498 < uVar18) {
          local_149f = '\x01';
        }
        else {
          uVar13 = local_1488 + iVar17;
          uVar3 = (local_149e - 1) * 3;
          local_1460 = (ushort)uVar3;
          if (local_1460 < (ushort)uVar13) {
            local_1480 = uVar13 + (local_149e - 1) * -3;
          }
          local_1484 = (undefined2)(local_1480 + local_144c);
          local_1468 = local_1498 + uVar15 * -100;
          wsprintfA(local_1404,s_UPDATE_characterinfo_SET_levelpo_00449a80,uVar3 & 0xffff,uVar9);
          iVar17 = mysql_query(*(undefined4 *)((int)this + 8),local_1404);
          if (iVar17 == 0) {
            wsprintfA(local_1404,s_UPDATE_usergameinfo_SET_powerlev_00449a44,
                      local_1480 + local_144c & 0xffff,lStack_1490);
            iVar17 = mysql_query(*(undefined4 *)((int)this + 8),local_1404);
            if (iVar17 == 0) {
              wsprintfA(local_1404,s_UPDATE_Cash_SET_cash_cash__u_WHE_00449a18,uVar18,aCStack_1430);
              iVar17 = mysql_query(*(undefined4 *)((int)this + 0xc),local_1404);
              if (iVar17 == 0) {
                wsprintfA(aCStack_141c,(LPCSTR)&param_2_00449a10);
                if (cVar1 != '\0') {
                  wsprintfA(local_1404,s_DELETE_FROM_useriteminfo_WHERE_i_004499e8,local_1454);
                  iVar17 = mysql_query(*(undefined4 *)((int)this + 8),local_1404);
                  if (iVar17 != 0) {
                    FUN_0040ea30(*(int *)((int)this + 8),local_1404);
                    goto LAB_004144cf;
                  }
                  wsprintfA(local_1404,s_INSERT_INTO_logcoupon__coupon_id_00449978,local_1478,
                            uStack_149c,lStack_1490,((uVar14 + 99) / 100) * 100);
                  iVar17 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1404);
                  if (iVar17 != 0) {
                    FUN_0040ea30(*(int *)((int)this + 0x20),local_1404);
                    goto LAB_004144cf;
                  }
                  uVar12 = mysql_insert_id(*(undefined4 *)((int)this + 0x20));
                  wsprintfA(aCStack_141c,(LPCSTR)&param_2_00449974,uVar12);
                }
                wsprintfA(local_1404,s_INSERT_INTO_LogCharStateClear_us_004498c0,lStack_1490,uVar9,
                          (uint)local_149e,uVar18,local_1498,local_1468,uVar13 & 0xffff,
                          local_1480 & 0xffff,aCStack_141c);
                iVar17 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1404);
                if (iVar17 == 0) {
                  if (cVar1 == '\0') {
                    pvVar8 = (void *)FUN_0042aad0();
                    iVar17 = FUN_0041d570(pvVar8,uVar18);
                    if (iVar17 == 0) {
                      local_149e = *(byte *)((uint)param_1 * 0x23b4 + 0x1530 +
                                            *(int *)((int)pvVar8 + 0xd4));
                      uVar14 = _rand();
                      uVar14 = uVar14 & 0x80000003;
                      if ((int)uVar14 < 0) {
                        uVar14 = (uVar14 - 1 | 0xfffffffc) + 1;
                      }
                      iVar17 = uVar14 + 0x44e;
LAB_00414354:
                      local_1494 = 1;
                      local_1440[0] =
                           *(undefined4 *)((int)pvVar8 + (iVar17 * 5 + (uint)local_149e) * 4);
                    }
                    else {
                      if (iVar17 == 1) {
                        local_149e = *(byte *)((uint)param_1 * 0x23b4 + 0x1530 +
                                              *(int *)((int)pvVar8 + 0xd4));
                        uVar14 = _rand();
                        uVar14 = uVar14 & 0x80000003;
                        if ((int)uVar14 < 0) {
                          uVar14 = (uVar14 - 1 | 0xfffffffc) + 1;
                        }
                        iVar17 = uVar14 + 0x44a;
                        goto LAB_00414354;
                      }
                      local_1494 = 0;
                    }
                    local_1498 = 0;
                    if (local_1494 != 0) {
                      do {
                        uVar9 = local_1440[local_1498];
                        wsprintfA(local_1404,s_INSERT_INTO_pendingpresents__pre_00449868,uVar9,
                                  lStack_1490);
                        iVar17 = mysql_query(*(undefined4 *)((int)this + 8),local_1404);
                        if (iVar17 == 0) {
                          uVar12 = mysql_insert_id(*(int *)((int)this + 8));
                          wsprintfA(local_1404,s_INSERT_INTO_logpresent__pending__004497f8,uVar12,
                                    uVar9,lStack_1490);
                          iVar17 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1404);
                          if (iVar17 != 0) {
                            FUN_0040ea30(*(int *)((int)this + 0x20),local_1404);
                          }
                        }
                        else {
                          FUN_0040ea30(*(int *)((int)this + 8),local_1404);
                          local_1494 = 0;
                        }
                        local_1498 = local_1498 + 1;
                      } while ((int)local_1498 < local_1494);
                    }
                  }
                }
                else {
                  FUN_0040ea30(*(int *)((int)this + 0x20),local_1404);
                  local_149f = '\x11';
                }
              }
              else {
                FUN_0040ea30(*(int *)((int)this + 0xc),local_1404);
                local_149f = '\x10';
              }
            }
            else {
              FUN_0040ea30(*(int *)((int)this + 8),local_1404);
              local_149f = '\x0f';
            }
          }
          else {
            FUN_0040ea30(*(int *)((int)this + 8),local_1404);
            local_149f = '\x0e';
          }
        }
      }
      else {
        FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandCharacterStateClear___m_00449b28);
        local_149f = '\v';
      }
    }
  }
  else {
    iVar17 = *(int *)((int)this + 8);
    iVar16 = -1;
    pcVar19 = s_DBCommandCharacterStateClear___m_00449b28;
    pvVar8 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar8,pcVar19,iVar16);
    if (iVar17 != 0) {
      iVar16 = -1;
      uVar9 = mysql_error(iVar17);
      pvVar8 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar8,uVar9,iVar16);
    }
    local_149f = '\v';
  }
  iVar17 = 0;
  uStack_1004._0_2_ = param_2;
  uStack_1004._2_2_ = 0x10;
  cStack_1000 = local_149f;
  uVar5 = 5;
  if (local_149f == '\0') {
    iStack_fff = local_1468;
    cStack_ff7 = cVar1;
    uStack_ffb = local_1460;
    uStack_ff9 = local_1484;
    uStack_ff6 = uVar2;
    uStack_ff4 = (char)local_1494;
    uVar6 = 0x11;
    uVar5 = 0x11;
    if (local_1494 != 0) {
      do {
        puVar10 = local_1440 + iVar17;
        uVar5 = uVar6 + 4;
        iVar17 = iVar17 + 1;
        *(undefined4 *)((int)&uStack_1004 + (uint)uVar6) = *puVar10;
        uVar6 = uVar5;
      } while (iVar17 < local_1494);
    }
  }
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar5,&uStack_1004);
LAB_004144cf:
  FUN_00435e83(local_4);
  return;
}



/* METADATA: sig=undefined __thiscall FUN_00413cd0(void * this, ushort param_1, undefined2 param_2, undefined4 param_3, undefined4 * param_4) xrefs=0041b009 callees=mysql_free_result FUN_0042e720 mysql_store_result FUN_0040ea30 FUN_0042aad0 _rand mysql_error _atol FUN_0041d380 FUN_0041d570 wsprintfA mysql_query lstrcpyA mysql_fetch_row FUN_00435e83 __chkstk mysql_insert_id */
