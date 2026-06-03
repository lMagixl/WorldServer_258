// FUN_00413980 — DB opcode 0x0D, Buddy name query handler
// Address: 0x00413980

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00413980(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  char *pcVar6;
  int iVar7;
  CHAR aCStack_1428 [16];
  CHAR aCStack_1418 [20];
  CHAR local_1404 [1024];
  undefined4 uStack_1004;
  undefined1 uStack_1000;
  CHAR aCStack_fff [4091];
  int local_4;
  
  local_4 = DAT_00454928;
  wsprintfA(local_1404,s_SELECT_a_name_a_buddyname_FROM_U_004496d8,param_4);
  uVar3 = *(undefined4 *)((int)this + 8);
  iVar1 = mysql_query(uVar3,local_1404);
  if (iVar1 == 0) {
    iVar1 = mysql_store_result(uVar3);
    if (iVar1 != 0) {
      puVar4 = (undefined4 *)mysql_fetch_row(iVar1);
      if (puVar4 == (undefined4 *)0x0) {
        uVar5 = 2;
        aCStack_1418[0] = '\0';
        aCStack_1428[0] = '\0';
      }
      else {
        uVar5 = 0;
        lstrcpyA(aCStack_1418,(LPCSTR)*puVar4);
        lstrcpyA(aCStack_1428,(LPCSTR)puVar4[1]);
        FUN_0042f280(s__RW__szUserName____s_00449680);
        FUN_0042f280(s__RW__szBuddyName____s_00449668);
      }
      mysql_free_result(iVar1);
      goto LAB_00413a6a;
    }
  }
  iVar1 = *(int *)((int)this + 8);
  iVar7 = -1;
  pcVar6 = s_DBCommandCharacterGetUserName___m_00449698;
  pvVar2 = (void *)FUN_0042aad0();
  FUN_0041d380(pvVar2,pcVar6,iVar7);
  if (iVar1 != 0) {
    iVar7 = -1;
    uVar3 = mysql_error(iVar1);
    pvVar2 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar2,uVar3,iVar7);
  }
  uVar5 = 1;
LAB_00413a6a:
  uStack_1004._0_2_ = param_2;
  uStack_1004._2_2_ = 0xd;
  uStack_1000 = uVar5;
  lstrcpyA(aCStack_fff,aCStack_1418);
  iVar1 = lstrlenA(aCStack_1418);
  lstrcpyA((LPSTR)((int)&uStack_1004 + (iVar1 + 6U & 0xffff)),aCStack_1428);
  iVar7 = lstrlenA(aCStack_1428);
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,(short)iVar1 + 7 + (short)iVar7,&uStack_1004);
  FUN_00435e83(local_4);
  return;
}

// SQL strings found: SELECT
