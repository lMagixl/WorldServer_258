
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_0040f610(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  ushort uVar6;
  CHAR *lpString2;
  CHAR *lpString2_00;
  undefined2 in_stack_00000006;
  char *pcVar7;
  int iVar8;
  char cStack_1fcd;
  uint uStack_1fcc;
  ushort uStack_1fc8;
  void *pvStack_1fc4;
  CHAR CStack_1fc0;
  undefined4 uStack_1fbf;
  CHAR CStack_1aa8;
  undefined4 uStack_1aa7;
  char local_1410 [16];
  undefined1 auStack_1400 [1024];
  undefined4 uStack_1000;
  char cStack_ffc;
  ushort uStack_ffb;
  undefined4 local_c;
  
  local_c = DAT_00454928;
  _sprintf(local_1410,s_SELECT_name__buddyname_FROM_user_00448000,param_4[1],*param_4);
  uVar3 = *(undefined4 *)((int)this + 8);
  iVar1 = mysql_query(uVar3,auStack_1400);
  if ((iVar1 == 0) && (iVar1 = mysql_store_result(uVar3), iVar1 != 0)) {
    CStack_1aa8 = '\0';
    puVar4 = &uStack_1aa7;
    for (iVar8 = 0x1a8; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    *(undefined2 *)puVar4 = 0;
    *(undefined1 *)((int)puVar4 + 2) = 0;
    CStack_1fc0 = '\0';
    puVar4 = &uStack_1fbf;
    for (iVar8 = 0x144; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    *(undefined2 *)puVar4 = 0;
    uVar6 = 0;
    *(undefined1 *)((int)puVar4 + 2) = 0;
    puVar4 = (undefined4 *)mysql_fetch_row(iVar1);
    while (puVar4 != (undefined4 *)0x0) {
      if ((LPCSTR)*puVar4 != (LPCSTR)0x0) {
        lstrcpyA(&CStack_1aa8 + (uint)uVar6 * 0x11,(LPCSTR)*puVar4);
        if ((LPCSTR)puVar4[1] != (LPCSTR)0x0) {
          lstrcpyA(&CStack_1fc0 + (uint)uVar6 * 0xd,(LPCSTR)puVar4[1]);
        }
      }
      uVar6 = uVar6 + 1;
      puVar4 = (undefined4 *)mysql_fetch_row(iVar1);
    }
    mysql_free_result(iVar1);
    cStack_1fcd = uVar6 == 0;
    this = pvStack_1fc4;
    uStack_ffb = uVar6;
  }
  else {
    iVar1 = *(int *)((int)this + 8);
    iVar8 = -1;
    pcVar7 = s_DBCommandAskClan___failed__0_00447fe0;
    pvVar2 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar2,pcVar7,iVar8);
    uStack_ffb = uStack_1fc8;
    if (iVar1 != 0) {
      iVar8 = -1;
      uVar3 = mysql_error(iVar1);
      pvVar2 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar2,uVar3,iVar8);
    }
  }
  uStack_1000._0_2_ = param_2;
  uStack_1000._2_2_ = 0x2c;
  cStack_ffc = cStack_1fcd;
  uVar5 = 7;
  uVar6 = 7;
  if (((cStack_1fcd == '\0') || (cStack_1fcd == '\x01')) && (uStack_ffb != 0)) {
    uStack_1fcc = (uint)uStack_ffb;
    lpString2_00 = &CStack_1fc0;
    lpString2 = &CStack_1aa8;
    do {
      lstrcpyA((LPSTR)((int)&uStack_1000 + (uVar5 & 0xffff)),lpString2);
      iVar1 = lstrlenA(lpString2);
      uVar5 = uVar5 + 1 + iVar1;
      lstrcpyA((LPSTR)((int)&uStack_1000 + (uVar5 & 0xffff)),lpString2_00);
      iVar1 = lstrlenA(lpString2_00);
      uVar5 = uVar5 + 1 + iVar1;
      uVar6 = (ushort)uVar5;
      FUN_0042f280(s__RW____CDB___szAccountName____s_00447fbc);
      FUN_0042f280(s__RW____CDB___szNickName____s_00447f9c);
      lpString2 = lpString2 + 0x11;
      lpString2_00 = lpString2_00 + 0xd;
      uStack_1fcc = uStack_1fcc - 1;
      this = pvStack_1fc4;
    } while (uStack_1fcc != 0);
  }
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar6,&uStack_1000);
  FUN_00435e83(_param_1);
  return;
}


