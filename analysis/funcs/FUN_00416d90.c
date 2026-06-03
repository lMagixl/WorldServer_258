
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00416d90(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  long lVar8;
  undefined4 uVar9;
  ushort uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  uint *puVar15;
  undefined4 *puVar16;
  uint uVar17;
  CHAR *pCVar18;
  char *pcVar19;
  int iVar20;
  int iVar21;
  char local_1af2;
  byte local_1af1;
  uint local_1af0;
  undefined4 local_1aec;
  uint local_1ae4;
  int local_1ae0;
  undefined1 local_1ad4;
  undefined4 local_1ad0 [20];
  undefined4 local_1a80 [120];
  uint local_18a0 [4];
  uint local_1890;
  CHAR local_1888 [1024];
  undefined4 local_1488 [30];
  CHAR local_1410 [1024];
  undefined4 local_1010;
  char local_100c;
  undefined4 local_100b;
  undefined1 local_1007;
  undefined2 local_1006;
  byte local_1004;
  int local_c;
  
  local_c = DAT_00454928;
  iVar20 = param_4[1];
  uVar6 = *param_4;
  uVar3 = *(ushort *)(param_4 + 2);
  bVar1 = *(byte *)((int)param_4 + 0xe);
  uVar9 = *(undefined4 *)((int)param_4 + 10);
  iVar14 = 0xf;
  if (bVar1 != 0) {
    local_1ae4 = (uint)(ushort)bVar1;
    puVar7 = (undefined4 *)((int)param_4 + 0xf);
    puVar16 = local_1ad0;
    for (uVar11 = (uint)bVar1; uVar11 != 0; uVar11 = uVar11 - 1) {
      *puVar16 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar16 = puVar16 + 1;
    }
    for (iVar14 = 0; iVar14 != 0; iVar14 = iVar14 + -1) {
      *(undefined1 *)puVar16 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar16 = (undefined4 *)((int)puVar16 + 1);
    }
    iVar14 = (uint)bVar1 * 4 + 0xf;
    puVar13 = (uint *)(iVar14 + (int)param_4);
    puVar15 = local_18a0;
    for (uVar11 = (uint)(bVar1 >> 2); uVar11 != 0; uVar11 = uVar11 - 1) {
      *puVar15 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar15 = puVar15 + 1;
    }
    for (uVar11 = (ushort)bVar1 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(char *)puVar15 = (char)*puVar13;
      puVar13 = (uint *)((int)puVar13 + 1);
      puVar15 = (uint *)((int)puVar15 + 1);
    }
    iVar14 = iVar14 + local_1ae4;
  }
  bVar2 = *(byte *)(iVar14 + (int)param_4);
  iVar14 = iVar14 + 1;
  if (bVar2 != 0) {
    uVar10 = (ushort)bVar2;
    local_1ae4 = (uint)uVar10;
    puVar7 = (undefined4 *)(iVar14 + (int)param_4);
    puVar16 = local_1a80;
    for (uVar11 = (uint)uVar10; uVar11 != 0; uVar11 = uVar11 - 1) {
      *puVar16 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar16 = puVar16 + 1;
    }
    for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
      *(undefined1 *)puVar16 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar16 = (undefined4 *)((int)puVar16 + 1);
    }
    iVar14 = iVar14 + local_1ae4 * 4;
    puVar7 = (undefined4 *)(iVar14 + (int)param_4);
    puVar16 = local_1488;
    for (uVar11 = (uint)(bVar2 >> 2); uVar11 != 0; uVar11 = uVar11 - 1) {
      *puVar16 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar16 = puVar16 + 1;
    }
    for (uVar11 = uVar10 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined1 *)puVar16 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar16 = (undefined4 *)((int)puVar16 + 1);
    }
    iVar14 = iVar14 + local_1ae4;
  }
  FUN_00416aa0(this,uVar9,bVar1,(int)local_1ad0,(int)local_18a0,bVar2,(int)local_1a80,
               (int)local_1488);
  if (*(char *)(iVar14 + (int)param_4) != '\0') {
    puVar13 = (uint *)(iVar14 + 5 + (int)param_4);
    local_18a0[0] = *puVar13;
    local_18a0[1] = puVar13[1];
    local_18a0[2] = puVar13[2];
    local_18a0[3] = puVar13[3];
    local_1890 = puVar13[4];
    uVar9 = *(undefined4 *)(iVar14 + 0x1b + (int)param_4);
    uVar4 = *(undefined2 *)(iVar14 + 0x1f + (int)param_4);
    wsprintfA(local_1410,s_UPDATE_CharacterInfo_SET_levelpo_0044aaf8,local_18a0[0] & 0xffff,
              local_18a0[0] >> 0x10,local_18a0[1] & 0xffff,local_18a0[1] >> 0x10,
              local_18a0[2] & 0xffff,local_18a0[2] >> 0x10,local_18a0[3] & 0xffff,
              local_18a0[3] >> 0x10,local_1890 & 0xffff,local_1890 >> 0x10,(uint)(ushort)puVar13[5],
              *(undefined4 *)(iVar14 + 1 + (int)param_4));
    iVar14 = mysql_query(*(undefined4 *)((int)this + 8),local_1410);
    if (iVar14 != 0) {
      iVar14 = *(int *)((int)this + 8);
      pCVar18 = local_1410;
      iVar20 = -1;
      pvVar5 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar5,pCVar18,iVar20);
      if (iVar14 != 0) {
        iVar20 = -1;
        uVar6 = mysql_error(iVar14);
        pvVar5 = (void *)FUN_0042aad0();
        FUN_0041d380(pvVar5,uVar6,iVar20);
        FUN_00435e83(local_c);
        return;
      }
      goto LAB_004174aa;
    }
    wsprintfA(local_1410,s_UPDATE_usergameinfo_SET_powerlev_0044aabc,uVar4,uVar9);
    iVar14 = mysql_query(*(undefined4 *)((int)this + 8),local_1410);
    if (iVar14 != 0) {
      FUN_0040ea30(*(int *)((int)this + 8),local_1410);
      FUN_00435e83(local_c);
      return;
    }
  }
  local_1af2 = '\0';
  local_1af0 = 0;
  wsprintfA(local_1888,s_SELECT_id__present_id_FROM_pendi_0044a778,uVar6);
  uVar9 = *(undefined4 *)((int)this + 8);
  iVar14 = mysql_query(uVar9,local_1888);
  if ((iVar14 == 0) && (iVar14 = mysql_store_result(uVar9), iVar14 != 0)) {
    puVar7 = (undefined4 *)mysql_fetch_row(iVar14);
    if (puVar7 == (undefined4 *)0x0) {
      iVar12 = *(int *)((int)this + 8);
      iVar21 = -1;
      pcVar19 = s_DBCommandPresentAccept___mysql_f_0044aa88;
      pvVar5 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar5,pcVar19,iVar21);
      if (iVar12 != 0) {
        iVar21 = -1;
        uVar9 = mysql_error(iVar12);
        pvVar5 = (void *)FUN_0042aad0();
        FUN_0041d380(pvVar5,uVar9,iVar21);
      }
      local_1af2 = '\x02';
      mysql_free_result(iVar14);
    }
    else {
      lVar8 = _atol((char *)*puVar7);
      if (lVar8 == iVar20) {
        local_1af0 = _atol((char *)puVar7[1]);
        mysql_free_result(iVar14);
      }
      else {
        local_1af2 = '\x01';
        mysql_free_result(iVar14);
      }
    }
  }
  else {
    iVar14 = *(int *)((int)this + 8);
    iVar12 = -1;
    pcVar19 = s_DBCommandPresentAccept___mysql_s_0044aa50;
    pvVar5 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar5,pcVar19,iVar12);
    if (iVar14 != 0) {
      iVar12 = -1;
      uVar9 = mysql_error(iVar14);
      pvVar5 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar5,uVar9,iVar12);
    }
    local_1af2 = '\x04';
  }
  local_1aec = 0;
  local_1af1 = 0;
  if (local_1af2 == '\0') {
    wsprintfA(local_1888,s_SELECT_slot_FROM_useriteminfo_WH_0044aa10,uVar6);
    uVar9 = *(undefined4 *)((int)this + 8);
    iVar14 = mysql_query(uVar9,local_1888);
    if ((iVar14 == 0) && (iVar14 = mysql_store_result(uVar9), iVar14 != 0)) {
      puVar7 = (undefined4 *)mysql_fetch_row(iVar14);
      if (puVar7 == (undefined4 *)0x0) {
LAB_0041721b:
        mysql_free_result(iVar14);
      }
      else {
        do {
          uVar11 = _atol((char *)*puVar7);
          if (uVar11 == uVar3) {
            local_1af2 = '\x03';
            goto LAB_0041721b;
          }
          puVar7 = (undefined4 *)mysql_fetch_row(iVar14);
        } while (puVar7 != (undefined4 *)0x0);
        mysql_free_result(iVar14);
      }
    }
    else {
      iVar14 = *(int *)((int)this + 8);
      iVar12 = -1;
      pcVar19 = s_DBCommandPresentAccept___mysql_s_0044aa50;
      pvVar5 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar5,pcVar19,iVar12);
      if (iVar14 != 0) {
        iVar12 = -1;
        uVar9 = mysql_error(iVar14);
        pvVar5 = (void *)FUN_0042aad0();
        FUN_0041d380(pvVar5,uVar9,iVar12);
      }
      local_1af2 = '\x04';
    }
  }
  local_1ae4 = 0;
  if (local_1af2 == '\0') {
    if ((local_1af0 < 11000) || (11999 < local_1af0)) {
      if ((7999 < local_1af0) && (local_1af0 < 9000)) {
        local_1af1 = 1;
      }
      if ((local_1af0 < 12000) || (12999 < local_1af0)) {
        wsprintfA(local_1888,s_INSERT_INTO_useriteminfo__userid_0044a808,uVar6,local_1af0,
                  (uint)uVar3,(uint)local_1af1);
      }
      else {
        iVar14 = FUN_0042aad0();
        wsprintfA(local_1888,s_INSERT_INTO_useriteminfo__userid_0044a858,uVar6,local_1af0,
                  (uint)uVar3,(uint)local_1af1,
                  (uint)*(ushort *)(*(int *)(iVar14 + 0x10c) + 0xe + local_1af0 * 0x20));
      }
      iVar14 = mysql_query(*(undefined4 *)((int)this + 8),local_1888);
      if (iVar14 == 0) {
        local_1aec = mysql_insert_id(*(undefined4 *)((int)this + 8));
        wsprintfA(local_1888,s_UPDATE_logpresent_SET_accept_tim_0044a944,iVar20);
        iVar14 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1888);
        if (iVar14 == 0) {
          wsprintfA(local_1888,s_UPDATE_useriteminfo_SET_item_sn__0044a7c8,iVar20,local_1aec);
          mysql_query(*(undefined4 *)((int)this + 8),local_1888);
LAB_004173fa:
          wsprintfA(local_1888,s_DELETE_FROM_pendingpresents_WHER_0044a8b0,iVar20);
          iVar14 = mysql_query(*(undefined4 *)((int)this + 8),local_1888);
          if (iVar14 == 0) goto LAB_00417427;
        }
      }
    }
    else {
      iVar14 = FUN_0042aad0();
      uVar11 = *(uint *)(iVar14 + 0x110);
      uVar17 = 0;
      if (uVar11 != 0) {
        local_1ae0 = 0;
        do {
          iVar14 = FUN_0042aad0();
          if (*(uint *)(local_1ae0 + *(int *)(iVar14 + 0x114)) == local_1af0) {
            iVar14 = FUN_0042aad0();
            wsprintfA(local_1888,s_INSERT_INTO_useriteminfo__userid_0044a980,uVar6,local_1af0,
                      (uint)uVar3,*(undefined4 *)(*(int *)(iVar14 + 0x114) + 8 + uVar17 * 0x14));
            iVar14 = mysql_query(*(undefined4 *)((int)this + 8),local_1888);
            if (iVar14 == 0) {
              local_1aec = mysql_insert_id(*(undefined4 *)((int)this + 8));
              wsprintfA(local_1888,s_UPDATE_logpresent_SET_accept_tim_0044a944,iVar20);
              iVar14 = mysql_query(*(undefined4 *)((int)this + 0x20),local_1888);
              if (iVar14 == 0) {
                wsprintfA(local_1888,s_UPDATE_useriteminfo_SET_item_sn__0044a908,iVar20,local_1aec);
                mysql_query(*(undefined4 *)((int)this + 8),local_1888);
              }
              else {
                local_1af2 = '\x04';
              }
            }
            else {
              local_1af2 = '\x04';
            }
            wsprintfA(local_1888,s_SELECT_limittime_FROM_useritemin_0044a8d8,local_1aec);
            uVar6 = *(undefined4 *)((int)this + 8);
            iVar14 = mysql_query(uVar6,local_1888);
            if ((iVar14 == 0) && (iVar14 = mysql_store_result(uVar6), iVar14 != 0)) {
              puVar7 = (undefined4 *)mysql_fetch_row(iVar14);
              if (puVar7 != (undefined4 *)0x0) {
                local_1ae4 = _atol((char *)*puVar7);
              }
              mysql_free_result(iVar14);
              if (local_1af2 == '\0') goto LAB_004173fa;
              goto LAB_00417427;
            }
            FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandPresentAccept___mysql_s_0044aa50);
            break;
          }
          uVar17 = uVar17 + 1;
          local_1ae0 = local_1ae0 + 0x14;
        } while (uVar17 < uVar11);
      }
    }
    local_1af2 = '\x04';
  }
LAB_00417427:
  local_1010._0_2_ = param_2;
  local_1010._2_2_ = 0x1f;
  local_100c = local_1af2;
  iVar14 = 5;
  if (local_1af2 == '\0') {
    local_1ad4 = (undefined1)uVar3;
    local_100b = local_1aec;
    local_1004 = local_1af1;
    local_1007 = local_1ad4;
    local_1006 = (undefined2)local_1af0;
    iVar14 = 0xd;
  }
  *(uint *)((int)&local_1010 + iVar14) = local_1ae4;
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,(short)iVar14 + 4,&local_1010);
LAB_004174aa:
  FUN_00435e83(local_c);
  return;
}



/* METADATA: sig=undefined __thiscall FUN_00416d90(void * this, undefined2 param_1, undefined2 param_2, undefined4 param_3, undefined4 * param_4) xrefs=0041b19f callees=mysql_free_result mysql_insert_id mysql_query _atol mysql_fetch_row FUN_00435e83 __chkstk mysql_error FUN_0040ea30 mysql_store_result FUN_0041d380 FUN_00416aa0 FUN_0042e720 wsprintfA FUN_0042aad0 */
