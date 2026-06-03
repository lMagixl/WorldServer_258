
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall
FUN_004129f0(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  undefined4 uVar1;
  undefined4 uVar2;
  ushort uVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  long lVar8;
  uint uVar9;
  char cVar10;
  long *plVar11;
  CHAR *pCVar12;
  long *plVar13;
  undefined4 *puVar14;
  char *pcVar15;
  int iVar16;
  undefined1 uStack_1ebd;
  undefined1 uStack_1ebc;
  undefined1 uStack_1ebb;
  undefined1 uStack_1eba;
  undefined1 uStack_1eb9;
  long lStack_1eb0;
  long lStack_1eac;
  undefined2 uStack_1ea8;
  long lStack_1ea4;
  long lStack_1ea0;
  undefined2 uStack_1e9c;
  undefined2 uStack_1e98;
  long lStack_1e94;
  long lStack_1e90;
  undefined2 uStack_1e8c;
  long lStack_1e88;
  undefined2 uStack_1e84;
  undefined2 uStack_1e80;
  undefined2 uStack_1e7c;
  long lStack_1e78;
  undefined2 uStack_1e74;
  undefined2 uStack_1e70;
  undefined2 uStack_1e6c;
  undefined2 uStack_1e68;
  undefined2 uStack_1e64;
  long alStack_1e60 [20];
  long alStack_1e10 [20];
  long alStack_1dc0 [20];
  long alStack_1d70 [100];
  long alStack_1be0 [120];
  long alStack_1a00 [120];
  long alStack_1820 [120];
  uint uStack_1640;
  undefined4 uStack_163c;
  undefined4 uStack_1638;
  undefined4 uStack_1634;
  undefined1 uStack_1630;
  undefined1 uStack_162f;
  undefined1 uStack_162e;
  undefined1 auStack_162c [2];
  undefined4 uStack_162a;
  undefined4 uStack_1626;
  undefined4 uStack_1622;
  undefined4 uStack_161e;
  undefined4 uStack_161a;
  undefined4 uStack_1616;
  undefined4 uStack_1612;
  undefined4 uStack_160e;
  undefined4 uStack_160a;
  CHAR aCStack_1604 [16];
  CHAR aCStack_15f4 [20];
  undefined1 auStack_15e0 [3];
  undefined1 auStack_15dd [101];
  undefined1 auStack_1578 [3];
  undefined1 auStack_1575 [117];
  undefined1 auStack_1500 [2];
  undefined4 auStack_14fe [59];
  CHAR local_1410 [1024];
  undefined4 uStack_1010;
  char cStack_100c;
  undefined1 auStack_100b [4];
  undefined1 auStack_1007 [4];
  undefined1 auStack_1003 [4];
  undefined1 uStack_fff;
  long lStack_ffe;
  long lStack_ffa;
  long lStack_ff6;
  undefined2 uStack_ff2;
  CHAR aCStack_ff0 [4068];
  int local_c;
  
  local_c = DAT_00454928;
  uVar6 = *param_4;
  uVar1 = param_4[1];
  wsprintfA(local_1410,s_SELECT_name_gold_bag_slot_FROM_U_00449414,uVar6);
  uVar2 = *(undefined4 *)((int)this + 8);
  iVar4 = mysql_query(uVar2,local_1410);
  if ((iVar4 == 0) && (iVar4 = mysql_store_result(uVar2), iVar4 != 0)) {
    lStack_1eb0 = 0;
    lStack_1eac = 0;
    puVar7 = (undefined4 *)mysql_fetch_row(iVar4);
    if (puVar7 == (undefined4 *)0x0) {
      cVar10 = '\x02';
      mysql_free_result(iVar4);
    }
    else {
      lstrcpyA(aCStack_15f4,(LPCSTR)*puVar7);
      lStack_1eb0 = _atol((char *)puVar7[1]);
      lVar8 = _atol((char *)puVar7[2]);
      uStack_1ebb = (undefined1)lVar8;
      _atol((char *)puVar7[3]);
      mysql_free_result(iVar4);
      pCVar12 = local_1410;
      for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
        pCVar12[0] = '\0';
        pCVar12[1] = '\0';
        pCVar12[2] = '\0';
        pCVar12[3] = '\0';
        pCVar12 = pCVar12 + 4;
      }
      wsprintfA(local_1410,s_SELECT_cash_FROM_Cash_WHERE_id____004493ec,aCStack_15f4);
      uVar2 = *(undefined4 *)((int)this + 0xc);
      iVar4 = mysql_query(uVar2,local_1410);
      if ((iVar4 == 0) && (iVar4 = mysql_store_result(uVar2), iVar4 != 0)) {
        puVar7 = (undefined4 *)mysql_fetch_row(iVar4);
        if (puVar7 != (undefined4 *)0x0) {
          lStack_1eac = _atol((char *)*puVar7);
        }
        mysql_free_result(iVar4);
        uStack_1e80 = 0;
        wsprintfA(local_1410,s_SELECT_name_auth_class_level_win_00449330,uVar1,uVar6);
        uVar2 = *(undefined4 *)((int)this + 8);
        iVar4 = mysql_query(uVar2,local_1410);
        if ((iVar4 == 0) && (iVar4 = mysql_store_result(uVar2), iVar4 != 0)) {
          puVar7 = (undefined4 *)mysql_fetch_row(iVar4);
          if (puVar7 == (undefined4 *)0x0) {
            cVar10 = '\x02';
            mysql_free_result(iVar4);
          }
          else {
            lstrcpyA(aCStack_1604,(LPCSTR)*puVar7);
            lVar8 = _atol((char *)puVar7[1]);
            uStack_1ebc = (undefined1)lVar8;
            lVar8 = _atol((char *)puVar7[2]);
            uStack_1eb9 = (undefined1)lVar8;
            lVar8 = _atol((char *)puVar7[3]);
            uStack_1eba = (undefined1)lVar8;
            lStack_1e78 = _atol((char *)puVar7[4]);
            lStack_1ea0 = _atol((char *)puVar7[5]);
            lStack_1e88 = _atol((char *)puVar7[6]);
            lStack_1e94 = _atol((char *)puVar7[7]);
            lVar8 = _atol((char *)puVar7[8]);
            uStack_1e70 = (undefined2)lVar8;
            lVar8 = _atol((char *)puVar7[9]);
            uStack_1e8c = (undefined2)lVar8;
            lVar8 = _atol((char *)puVar7[10]);
            uStack_1e64 = (undefined2)lVar8;
            lVar8 = _atol((char *)puVar7[0xb]);
            uStack_1e84 = (undefined2)lVar8;
            lVar8 = _atol((char *)puVar7[0xc]);
            uStack_1e6c = (undefined2)lVar8;
            lVar8 = _atol((char *)puVar7[0xd]);
            uStack_1e7c = (undefined2)lVar8;
            lVar8 = _atol((char *)puVar7[0xe]);
            uStack_1ea8 = (undefined2)lVar8;
            lVar8 = _atol((char *)puVar7[0xf]);
            uStack_1e68 = (undefined2)lVar8;
            lVar8 = _atol((char *)puVar7[0x10]);
            uStack_1e74 = (undefined2)lVar8;
            lVar8 = _atol((char *)puVar7[0x11]);
            uStack_1e9c = (undefined2)lVar8;
            lVar8 = _atol((char *)puVar7[0x12]);
            uStack_1e98 = (undefined2)lVar8;
            lVar8 = _atol((char *)puVar7[0x13]);
            uStack_1ebd = (undefined1)lVar8;
            lStack_1e90 = _atol((char *)puVar7[0x14]);
            lStack_1ea4 = _atol((char *)puVar7[0x15]);
            mysql_free_result(iVar4);
            wsprintfA(local_1410,s_SELECT_slot_characterid_id_itemi_00449278,uVar6,uVar1);
            iVar4 = FUN_0040eac0(*(undefined4 *)((int)this + 8),local_1410);
            if (iVar4 == 0) {
              FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandCharacterSelect___mysql_0044856c);
              cVar10 = '\x01';
            }
            else {
              plVar11 = alStack_1e10;
              alStack_1e10[0] = 0;
              for (iVar16 = 0x12; plVar11 = plVar11 + 1, iVar16 != 0; iVar16 = iVar16 + -1) {
                *plVar11 = 0;
              }
              alStack_1820[0] = 0;
              plVar11 = alStack_1820;
              for (iVar16 = 0x77; plVar11 = plVar11 + 1, iVar16 != 0; iVar16 = iVar16 + -1) {
                *plVar11 = 0;
              }
              uStack_162a = 0;
              uStack_1640 = 0;
              uStack_1626 = 0;
              uStack_163c = 0;
              uStack_1622 = 0;
              uStack_1638 = 0;
              uStack_161e = 0;
              uStack_1634 = 0;
              uStack_1630 = 0;
              uStack_161a = 0;
              uStack_162f = 0;
              uStack_162e = 0;
              uStack_1616 = 0;
              uStack_1612 = 0;
              uStack_160e = 0;
              alStack_1dc0[0] = 0;
              plVar11 = alStack_1dc0;
              for (iVar16 = 0x12; plVar11 = plVar11 + 1, iVar16 != 0; iVar16 = iVar16 + -1) {
                *plVar11 = 0;
              }
              uStack_160a = 0;
              alStack_1e60[0] = 0;
              plVar11 = alStack_1e60;
              for (iVar16 = 0x12; plVar11 = plVar11 + 1, iVar16 != 0; iVar16 = iVar16 + -1) {
                *plVar11 = 0;
              }
              auStack_1500 = (undefined1  [2])0x0;
              puVar7 = (undefined4 *)(auStack_1500 + 2);
              for (iVar16 = 0x3b; iVar16 != 0; iVar16 = iVar16 + -1) {
                *puVar7 = 0;
                puVar7 = puVar7 + 1;
              }
              *(undefined2 *)puVar7 = 0;
              auStack_1578[0] = 0;
              puVar7 = (undefined4 *)(auStack_1578 + 1);
              for (iVar16 = 0x1d; iVar16 != 0; iVar16 = iVar16 + -1) {
                *puVar7 = 0;
                puVar7 = puVar7 + 1;
              }
              *(undefined2 *)puVar7 = 0;
              *(undefined1 *)((int)puVar7 + 2) = 0;
              alStack_1be0[0] = 0;
              plVar11 = alStack_1be0;
              for (iVar16 = 0x77; plVar11 = plVar11 + 1, iVar16 != 0; iVar16 = iVar16 + -1) {
                *plVar11 = 0;
              }
              alStack_1a00[0] = 0;
              plVar11 = alStack_1a00;
              auStack_162c = (undefined1  [2])0x0;
              uStack_1640 = uStack_1640 & 0xffffff00;
              for (iVar16 = 0x77; plVar11 = plVar11 + 1, iVar16 != 0; iVar16 = iVar16 + -1) {
                *plVar11 = 0;
              }
              puVar7 = (undefined4 *)mysql_fetch_row(iVar4);
              while (puVar7 != (undefined4 *)0x0) {
                uVar9 = _atol((char *)*puVar7);
                lVar8 = _atol((char *)puVar7[1]);
                if (lVar8 == 0) {
                  uVar9 = uVar9 & 0xff;
                  lVar8 = _atol((char *)puVar7[2]);
                  pcVar15 = (char *)puVar7[3];
                  alStack_1820[uVar9] = lVar8;
                  lVar8 = _atol(pcVar15);
                  pcVar15 = (char *)puVar7[4];
                  *(short *)(auStack_1500 + uVar9 * 2) = (short)lVar8;
                  lVar8 = _atol(pcVar15);
                  pcVar15 = (char *)puVar7[5];
                  auStack_1578[uVar9] = (char)lVar8;
                  lVar8 = _atol(pcVar15);
                  pcVar15 = (char *)puVar7[6];
                  alStack_1be0[uVar9] = lVar8;
                  lVar8 = _atol(pcVar15);
                  alStack_1a00[uVar9] = lVar8;
                }
                else {
                  uVar9 = uVar9 & 0xff;
                  lVar8 = _atol((char *)puVar7[2]);
                  pcVar15 = (char *)puVar7[3];
                  alStack_1e10[uVar9] = lVar8;
                  lVar8 = _atol(pcVar15);
                  pcVar15 = (char *)puVar7[4];
                  *(short *)(auStack_162c + uVar9 * 2) = (short)lVar8;
                  lVar8 = _atol(pcVar15);
                  pcVar15 = (char *)puVar7[5];
                  *(char *)((int)&uStack_1640 + uVar9) = (char)lVar8;
                  lVar8 = _atol(pcVar15);
                  pcVar15 = (char *)puVar7[6];
                  alStack_1dc0[uVar9] = lVar8;
                  lVar8 = _atol(pcVar15);
                  alStack_1e60[uVar9] = lVar8;
                }
                puVar7 = (undefined4 *)mysql_fetch_row(iVar4);
              }
              mysql_free_result(iVar4);
              wsprintfA(local_1410,s_SELECT_stage_id_rank_FROM_UserSt_004485a4,uVar1);
              iVar4 = FUN_0040eac0(*(undefined4 *)((int)this + 8),local_1410);
              if (iVar4 == 0) {
                FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandCharacterSelect___mysql_0044856c);
                cVar10 = '\x01';
              }
              else {
                plVar11 = alStack_1d70;
                alStack_1d70[0] = 0;
                for (iVar16 = 99; plVar11 = plVar11 + 1, iVar16 != 0; iVar16 = iVar16 + -1) {
                  *plVar11 = 0;
                }
                auStack_15e0[0] = 0;
                puVar7 = (undefined4 *)(auStack_15e0 + 1);
                for (iVar16 = 0x18; iVar16 != 0; iVar16 = iVar16 + -1) {
                  *puVar7 = 0;
                  puVar7 = puVar7 + 1;
                }
                *(undefined2 *)puVar7 = 0;
                *(undefined1 *)((int)puVar7 + 2) = 0;
                puVar7 = (undefined4 *)mysql_fetch_row(iVar4);
                while (puVar7 != (undefined4 *)0x0) {
                  uVar9 = _atol((char *)*puVar7);
                  lVar8 = _atol((char *)puVar7[1]);
                  alStack_1d70[uVar9 & 0xff] = lVar8;
                  lVar8 = _atol((char *)puVar7[2]);
                  auStack_15e0[uVar9 & 0xff] = (char)lVar8;
                  puVar7 = (undefined4 *)mysql_fetch_row(iVar4);
                }
                mysql_free_result(iVar4);
                cVar10 = '\0';
              }
            }
          }
        }
        else {
          FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandCharacterSelect__mysql__004492f8);
          cVar10 = '\x01';
        }
      }
      else {
        FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandCharacterSelect___mysql_0044856c);
        cVar10 = '\x01';
      }
    }
  }
  else {
    iVar4 = *(int *)((int)this + 8);
    iVar16 = -1;
    pcVar15 = s_DBCommandCharacterSelect___mysql_0044856c;
    pvVar5 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar5,pcVar15,iVar16);
    if (iVar4 != 0) {
      iVar16 = -1;
      uVar6 = mysql_error(iVar4);
      pvVar5 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar5,uVar6,iVar16);
    }
    cVar10 = '\x01';
  }
  uStack_1010._0_2_ = param_2;
  uStack_1010._2_2_ = 9;
  uVar3 = 5;
  cStack_100c = cVar10;
  if (cVar10 == '\0') {
    auStack_1003 = (undefined1  [4])lStack_1eac;
    uStack_fff = uStack_1ebb;
    auStack_1007 = (undefined1  [4])lStack_1eb0;
    lStack_ffa = lStack_1ea0;
    lStack_ff6 = lStack_1e88;
    lStack_ffe = lStack_1e78;
    uStack_ff2 = uStack_1e80;
    auStack_100b = (undefined1  [4])uVar1;
    lstrcpyA(aCStack_ff0,aCStack_1604);
    iVar4 = lstrlenA(aCStack_1604);
    *(undefined1 *)((int)&uStack_1010 + (iVar4 + 0x21U & 0xffff)) = uStack_1ebc;
    *(undefined1 *)((int)&uStack_1010 + (iVar4 + 0x22U & 0xffff)) = uStack_1eb9;
    *(undefined1 *)((int)&uStack_1010 + (iVar4 + 0x23U & 0xffff)) = uStack_1eba;
    *(long *)((int)&uStack_1010 + (iVar4 + 0x24U & 0xffff)) = lStack_1e94;
    *(undefined2 *)((int)&uStack_1010 + (iVar4 + 0x28U & 0xffff)) = uStack_1e70;
    *(undefined2 *)((int)&uStack_1010 + (iVar4 + 0x2aU & 0xffff)) = uStack_1e8c;
    *(undefined2 *)((int)&uStack_1010 + (iVar4 + 0x2cU & 0xffff)) = uStack_1e64;
    *(undefined2 *)((int)&uStack_1010 + (iVar4 + 0x2eU & 0xffff)) = uStack_1e84;
    *(undefined2 *)((int)&uStack_1010 + (iVar4 + 0x30U & 0xffff)) = uStack_1e6c;
    *(undefined2 *)((int)&uStack_1010 + (iVar4 + 0x32U & 0xffff)) = uStack_1e7c;
    *(undefined2 *)((int)&uStack_1010 + (iVar4 + 0x34U & 0xffff)) = uStack_1ea8;
    *(undefined2 *)((int)&uStack_1010 + (iVar4 + 0x36U & 0xffff)) = uStack_1e68;
    *(undefined2 *)((int)&uStack_1010 + (iVar4 + 0x38U & 0xffff)) = uStack_1e74;
    *(undefined2 *)((int)&uStack_1010 + (iVar4 + 0x3aU & 0xffff)) = uStack_1e9c;
    *(undefined2 *)((int)&uStack_1010 + (iVar4 + 0x3cU & 0xffff)) = uStack_1e98;
    *(undefined1 *)((int)&uStack_1010 + (iVar4 + 0x3eU & 0xffff)) = uStack_1ebd;
    *(long *)((int)&uStack_1010 + (iVar4 + 0x3fU & 0xffff)) = lStack_1e90;
    *(long *)((int)&uStack_1010 + (iVar4 + 0x43U & 0xffff)) = lStack_1ea4;
    plVar11 = alStack_1e10;
    plVar13 = (long *)((int)&uStack_1010 + (iVar4 + 0x47U & 0xffff));
    for (iVar16 = 0x13; iVar16 != 0; iVar16 = iVar16 + -1) {
      *plVar13 = *plVar11;
      plVar11 = plVar11 + 1;
      plVar13 = plVar13 + 1;
    }
    puVar7 = (undefined4 *)auStack_162c;
    puVar14 = (undefined4 *)((int)&uStack_1010 + (iVar4 + 0x93U & 0xffff));
    for (iVar16 = 9; iVar16 != 0; iVar16 = iVar16 + -1) {
      *puVar14 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar14 = puVar14 + 1;
    }
    *(undefined2 *)puVar14 = *(undefined2 *)puVar7;
    uVar9 = iVar4 + 0xb9U & 0xffff;
    *(uint *)((int)&uStack_1010 + uVar9) = uStack_1640;
    *(undefined4 *)(&cStack_100c + uVar9) = uStack_163c;
    *(undefined4 *)(auStack_100b + uVar9 + 3) = uStack_1638;
    *(undefined4 *)(auStack_1007 + uVar9 + 3) = uStack_1634;
    *(ushort *)(auStack_1003 + uVar9 + 3) = CONCAT11(uStack_162f,uStack_1630);
    *(undefined1 *)((int)&lStack_ffe + uVar9) = uStack_162e;
    plVar11 = alStack_1dc0;
    plVar13 = (long *)((int)&uStack_1010 + (iVar4 + 0xccU & 0xffff));
    for (iVar16 = 0x13; iVar16 != 0; iVar16 = iVar16 + -1) {
      *plVar13 = *plVar11;
      plVar11 = plVar11 + 1;
      plVar13 = plVar13 + 1;
    }
    plVar11 = alStack_1e60;
    plVar13 = (long *)((int)&uStack_1010 + (iVar4 + 0x118U & 0xffff));
    for (iVar16 = 0x13; iVar16 != 0; iVar16 = iVar16 + -1) {
      *plVar13 = *plVar11;
      plVar11 = plVar11 + 1;
      plVar13 = plVar13 + 1;
    }
    plVar11 = alStack_1820;
    plVar13 = (long *)((int)&uStack_1010 + (iVar4 + 0x164U & 0xffff));
    for (iVar16 = 0x78; iVar16 != 0; iVar16 = iVar16 + -1) {
      *plVar13 = *plVar11;
      plVar11 = plVar11 + 1;
      plVar13 = plVar13 + 1;
    }
    puVar7 = (undefined4 *)auStack_1500;
    puVar14 = (undefined4 *)((int)&uStack_1010 + (iVar4 + 0x344U & 0xffff));
    for (iVar16 = 0x3c; iVar16 != 0; iVar16 = iVar16 + -1) {
      *puVar14 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar14 = puVar14 + 1;
    }
    puVar7 = (undefined4 *)auStack_1578;
    puVar14 = (undefined4 *)((int)&uStack_1010 + (iVar4 + 0x434U & 0xffff));
    for (iVar16 = 0x1e; iVar16 != 0; iVar16 = iVar16 + -1) {
      *puVar14 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar14 = puVar14 + 1;
    }
    plVar11 = alStack_1be0;
    plVar13 = (long *)((int)&uStack_1010 + (iVar4 + 0x4acU & 0xffff));
    for (iVar16 = 0x78; iVar16 != 0; iVar16 = iVar16 + -1) {
      *plVar13 = *plVar11;
      plVar11 = plVar11 + 1;
      plVar13 = plVar13 + 1;
    }
    plVar11 = alStack_1a00;
    plVar13 = (long *)((int)&uStack_1010 + (iVar4 + 0x68cU & 0xffff));
    for (iVar16 = 0x78; iVar16 != 0; iVar16 = iVar16 + -1) {
      *plVar13 = *plVar11;
      plVar11 = plVar11 + 1;
      plVar13 = plVar13 + 1;
    }
    plVar11 = alStack_1d70;
    plVar13 = (long *)((int)&uStack_1010 + (iVar4 + 0x86cU & 0xffff));
    for (iVar16 = 100; iVar16 != 0; iVar16 = iVar16 + -1) {
      *plVar13 = *plVar11;
      plVar11 = plVar11 + 1;
      plVar13 = plVar13 + 1;
    }
    puVar7 = (undefined4 *)auStack_15e0;
    puVar14 = (undefined4 *)((int)&uStack_1010 + (iVar4 + 0x9fcU & 0xffff));
    for (iVar16 = 0x19; iVar16 != 0; iVar16 = iVar16 + -1) {
      *puVar14 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar14 = puVar14 + 1;
    }
    uVar3 = (short)iVar4 + 0xa60;
  }
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar3,&uStack_1010);
  FUN_00435e83(local_c);
  return;
}



/* METADATA: sig=undefined __thiscall FUN_004129f0(void * this, undefined2 param_1, undefined2 param_2, undefined4 param_3, undefined4 * param_4) xrefs=0041af3e callees=lstrlenA mysql_free_result mysql_query _atol mysql_fetch_row FUN_00435e83 __chkstk mysql_error FUN_0040ea30 mysql_store_result FUN_0041d380 lstrcpyA FUN_0040eac0 FUN_0042e720 wsprintfA FUN_0042aad0 */
