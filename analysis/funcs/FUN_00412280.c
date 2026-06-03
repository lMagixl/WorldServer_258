// FUN_00412280 — DB opcode 0x07, Character create DB handler
// Address: 0x00412280

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00412280(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  long lVar9;
  char cVar10;
  char *pcVar11;
  int iVar12;
  byte bStack_141a;
  undefined4 uStack_1418;
  CHAR local_1414 [16];
  CHAR aCStack_1404 [1024];
  undefined2 uStack_1004;
  undefined2 uStack_1002;
  char cStack_1000;
  byte bStack_fff;
  undefined4 uStack_ffe;
  byte bStack_ffa;
  CHAR aCStack_ff9 [4085];
  int local_4;
  
  uVar7 = *param_4;
  local_4 = DAT_00454928;
  lstrcpyA(local_1414,(LPCSTR)(param_4 + 1));
  iVar5 = lstrlenA((LPCSTR)(param_4 + 1));
  bVar1 = *(byte *)((iVar5 + 5U & 0xffff) + (int)param_4);
  bVar2 = *(byte *)((iVar5 + 6U & 0xffff) + (int)param_4);
  if (5 < bVar2) {
    cVar10 = '\x01';
    goto LAB_00412488;
  }
  wsprintfA(aCStack_1404,s_SELECT_slot_FROM_CharacterInfo_W_00448f10,10,uVar7);
  uVar3 = *(undefined4 *)((int)this + 8);
  iVar5 = mysql_query(uVar3,aCStack_1404);
  if ((iVar5 == 0) && (iVar5 = mysql_store_result(uVar3), iVar5 != 0)) {
    bStack_141a = 0;
    puVar8 = (undefined4 *)mysql_fetch_row(iVar5);
    while (puVar8 != (undefined4 *)0x0) {
      lVar9 = _atol((char *)*puVar8);
      if ((byte)lVar9 == bVar2) {
        cVar10 = '\x02';
        mysql_free_result(iVar5);
        goto LAB_00412488;
      }
      bStack_141a = bStack_141a + 1;
      puVar8 = (undefined4 *)mysql_fetch_row(iVar5);
    }
    mysql_free_result(iVar5);
    if (5 < bStack_141a) {
      cVar10 = '\x03';
      goto LAB_00412488;
    }
    wsprintfA(aCStack_1404,s_SELECT_id_FROM_CharacterInfo_WHE_00448ea4,local_1414);
    uVar3 = *(undefined4 *)((int)this + 8);
    iVar5 = mysql_query(uVar3,aCStack_1404);
    if ((iVar5 == 0) && (iVar5 = mysql_store_result(uVar3), iVar5 != 0)) {
      iVar12 = mysql_fetch_row(iVar5);
      if (iVar12 == 0) {
        mysql_free_result(iVar5);
        wsprintfA(aCStack_1404,s_INSERT_INTO_CharacterInfo_name_u_00448e38,local_1414,uVar7,
                  (uint)bVar1,(uint)bVar2);
        iVar5 = mysql_query(*(undefined4 *)((int)this + 8),aCStack_1404);
        if (iVar5 == 0) {
          uStack_1418 = mysql_insert_id(*(undefined4 *)((int)this + 8));
          wsprintfA(aCStack_1404,s_UPDATE_Usergameinfo_SET_charname_00448df0,local_1414,uVar7);
          iVar5 = mysql_query(*(undefined4 *)((int)this + 8),aCStack_1404);
          if (iVar5 == 0) {
            cVar10 = '\0';
          }
          else {
            FUN_0040ea30(*(int *)((int)this + 8),aCStack_1404);
            cVar10 = '\x01';
          }
        }
        else {
          FUN_0040ea30(*(int *)((int)this + 8),aCStack_1404);
          cVar10 = '\x01';
        }
      }
      else {
        cVar10 = '\x04';
        mysql_free_result(iVar5);
      }
      goto LAB_00412488;
    }
  }
  iVar5 = *(int *)((int)this + 8);
  iVar12 = -1;
  pcVar11 = s_DBCommandCharacterCreate___mysql_00448ed4;
  pvVar6 = (void *)FUN_0042aad0();
  FUN_0041d380(pvVar6,pcVar11,iVar12);
  if (iVar5 != 0) {
    iVar12 = -1;
    uVar7 = mysql_error(iVar5);
    pvVar6 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar6,uVar7,iVar12);
  }
  cVar10 = '\x01';
LAB_00412488:
  uStack_1004 = param_2;
  uStack_1002 = 7;
  uVar4 = 5;
  cStack_1000 = cVar10;
  if (cVar10 == '\0') {
    uStack_ffe = uStack_1418;
    bStack_fff = bVar2;
    bStack_ffa = bVar1;
    lstrcpyA(aCStack_ff9,local_1414);
    iVar5 = lstrlenA(local_1414);
    uVar4 = (short)iVar5 + 0xc;
  }
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar4,(undefined4 *)&uStack_1004);
  FUN_00435e83(local_4);
  return;
}

// SQL strings found: SELECT, INSERT, UPDATE
