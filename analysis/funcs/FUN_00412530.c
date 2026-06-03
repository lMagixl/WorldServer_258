// FUN_00412530 — DB opcode 0x08, Character delete DB handler
// Address: 0x00412530

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00412530(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,int *param_4)

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  ushort uVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  int iVar16;
  char cVar17;
  byte *pbVar18;
  bool bVar19;
  char *pcVar20;
  long lStack_148c;
  byte abStack_1488 [12];
  byte local_147c [12];
  CHAR aCStack_1470 [16];
  CHAR aCStack_1460 [20];
  CHAR aCStack_144c [72];
  CHAR aCStack_1404 [1024];
  undefined2 uStack_1004;
  undefined2 uStack_1002;
  char cStack_1000;
  long lStack_fff;
  int iStack_ffb;
  int local_4;
  
  local_4 = DAT_00454928;
  iVar2 = param_4[1];
  iVar16 = *param_4;
  lstrcpyA((LPSTR)local_147c,(LPCSTR)(param_4 + 2));
  lstrlenA((LPCSTR)(param_4 + 2));
  wsprintfA(aCStack_1404,s_SELECT_a_name_a_level_a_used_TO__00449178,iVar2);
  uVar7 = *(undefined4 *)((int)this + 8);
  iVar5 = mysql_query(uVar7,aCStack_1404);
  if ((iVar5 != 0) || (iVar5 = mysql_store_result(uVar7), iVar5 == 0)) {
    iVar16 = *(int *)((int)this + 8);
    iVar5 = -1;
    pcVar20 = s_DBCommandCharacterDelete___mysql_0044913c;
    pvVar6 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar6,pcVar20,iVar5);
    if (iVar16 != 0) {
      iVar5 = -1;
      uVar7 = mysql_error(iVar16);
      pvVar6 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar6,uVar7,iVar5);
    }
    cVar17 = '\x01';
    goto LAB_0041296c;
  }
  puVar8 = (undefined4 *)mysql_fetch_row(iVar5);
  if (puVar8 == (undefined4 *)0x0) {
    cVar17 = '\x02';
    mysql_free_result(iVar5);
    goto LAB_0041296c;
  }
  pbVar9 = (byte *)*puVar8;
  pbVar18 = (byte *)puVar8[5];
  do {
    bVar1 = *pbVar9;
    bVar19 = bVar1 < *pbVar18;
    if (bVar1 != *pbVar18) {
LAB_0041262d:
      iVar10 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
      goto LAB_00412632;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar9[1];
    bVar19 = bVar1 < pbVar18[1];
    if (bVar1 != pbVar18[1]) goto LAB_0041262d;
    pbVar9 = pbVar9 + 2;
    pbVar18 = pbVar18 + 2;
  } while (bVar1 != 0);
  iVar10 = 0;
LAB_00412632:
  if (iVar10 == 0) {
    cVar17 = '\t';
    mysql_free_result(iVar5);
    goto LAB_0041296c;
  }
  lstrcpyA(aCStack_1470,(LPCSTR)*puVar8);
  uVar11 = _atol((char *)puVar8[1]);
  lVar12 = _atol((char *)puVar8[2]);
  lVar13 = _atol((char *)puVar8[3]);
  lstrcpyA(aCStack_1460,(LPCSTR)puVar8[6]);
  lstrcpyA((LPSTR)abStack_1488,(LPCSTR)puVar8[7]);
  lVar14 = _atol((char *)puVar8[8]);
  lStack_148c = _atol((char *)puVar8[9]);
  lVar15 = _atol((char *)puVar8[10]);
  mysql_free_result(iVar5);
  pcVar3 = wsprintfA_exref;
  if (iVar16 != lVar15) {
    cVar17 = '4';
    goto LAB_0041296c;
  }
  if (((char)lVar12 != '\0') && (lVar13 < 7)) {
    cVar17 = '\x03';
    goto LAB_0041296c;
  }
  if ((byte)uVar11 < 0xf) {
    wsprintfA(aCStack_1404,s_DELETE_FROM_CharacterInfo_WHERE_i_00449058,iVar2);
    iVar5 = mysql_query(*(undefined4 *)((int)this + 8),aCStack_1404);
    if (iVar5 == 0) {
      wsprintfA(aCStack_1404,s_DELETE_FROM_UserItemInfo_WHERE_c_00449028,iVar2);
      iVar5 = mysql_query(*(undefined4 *)((int)this + 8),aCStack_1404);
      if (iVar5 != 0) {
        FUN_0040ea30(*(int *)((int)this + 8),aCStack_1404);
        cVar17 = '\x01';
        goto LAB_0041296c;
      }
      wsprintfA(aCStack_1404,s_DELETE_FROM_UserStageInfo_WHERE_c_00448ff8,iVar2);
      iVar5 = mysql_query(*(undefined4 *)((int)this + 8),aCStack_1404);
      goto joined_r0x004128d9;
    }
  }
  else if (((char)lVar14 == '\0') || (abStack_1488[0] == 0)) {
    pvVar6 = (void *)FUN_0042aad0();
    wsprintfA(aCStack_1404,s_SELECT_e_mail_FROM_user_WHERE_id_004490fc,aCStack_1460);
    iVar16 = FUN_0040eac0(*(undefined4 *)((int)this + 0xc),aCStack_1404);
    if (iVar16 == 0) {
      FUN_0040ea30(*(int *)((int)this + 0xc),s_DBCommandCharacterDelete___mysql_0044913c);
      cVar17 = '\x01';
      goto LAB_0041296c;
    }
    puVar8 = (undefined4 *)mysql_fetch_row(iVar16);
    if (puVar8 == (undefined4 *)0x0) {
      cVar17 = '\x06';
      FUN_0040ea30(*(int *)((int)this + 8),s_DBCommandCharacterDelete___mysql_004490c8);
      mysql_free_result(iVar16);
      goto LAB_0041296c;
    }
    lstrcpyA(aCStack_144c,(LPCSTR)*puVar8);
    mysql_free_result(iVar16);
    FUN_0041d050((int)abStack_1488,0xb);
    wsprintfA(aCStack_1404,s_UPDATE_characterinfo_SET_deleteK_00449080,abStack_1488,iVar2);
    iVar16 = mysql_query(*(undefined4 *)((int)this + 8),aCStack_1404);
    if (iVar16 == 0) {
      FUN_00428350(pvVar6,aCStack_144c,abStack_1488);
      cVar17 = '\a';
      goto LAB_0041296c;
    }
  }
  else {
    pbVar9 = abStack_1488;
    pbVar18 = local_147c;
    do {
      bVar1 = *pbVar18;
      bVar19 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_0041272d:
        iVar5 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
        goto LAB_00412732;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar18[1];
      bVar19 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_0041272d;
      pbVar18 = pbVar18 + 2;
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_00412732:
    if (iVar5 != 0) {
      cVar17 = '\x05';
      goto LAB_0041296c;
    }
    wsprintfA(aCStack_1404,s_UPDATE_CharacterInfo_SET_auth__u_00448fb8,10,iVar2);
    iVar5 = mysql_query(*(undefined4 *)((int)this + 8),aCStack_1404);
    pcVar3 = wsprintfA_exref;
joined_r0x004128d9:
    if (iVar5 == 0) {
      (*pcVar3)(aCStack_1404,s_INSERT_INTO_LogDeleteCharacter___00448f58,iVar16,aCStack_1470,
                uVar11 & 0xff);
      iVar16 = mysql_query(*(undefined4 *)((int)this + 0x20),aCStack_1404);
      if (iVar16 == 0) {
        cVar17 = '\0';
      }
      else {
        FUN_0040ea30(*(int *)((int)this + 0x20),aCStack_1404);
        cVar17 = '\x01';
      }
      goto LAB_0041296c;
    }
  }
  FUN_0040ea30(*(int *)((int)this + 8),aCStack_1404);
  cVar17 = '\x01';
LAB_0041296c:
  uStack_1004 = param_2;
  uStack_1002 = 8;
  uVar4 = 5;
  if (cVar17 == '\0') {
    lStack_fff = lStack_148c;
    uVar4 = 0xd;
    iStack_ffb = iVar2;
  }
  cStack_1000 = cVar17;
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar4,(undefined4 *)&uStack_1004);
  FUN_00435e83(local_4);
  return;
}

// SQL strings found: SELECT, DELETE, UPDATE, INSERT
