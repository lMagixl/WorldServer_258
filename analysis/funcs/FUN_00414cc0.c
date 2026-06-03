/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00414cc0(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  int iVar1;
  undefined4 *puVar2;
  long lVar3;
  void *pvVar4;
  undefined4 uVar5;
  char cVar6;
  char *pcVar7;
  int iVar8;
  undefined1 local_1409;
  long local_1408;
  CHAR local_1404 [1024];
  undefined2 local_1004;
  undefined2 local_1002;
  undefined1 local_1000;
  long local_fff;
  int local_4;
  
  local_4 = DAT_00454928;
  local_1408 = 0;
  local_1409 = 0;
  cVar6 = '\0';
  wsprintfA(local_1404,s_SELECT_userid__u_FROM_characteri_00449e64,*param_4,param_4[1]);
  uVar5 = *(undefined4 *)((int)this + 8);
  iVar1 = mysql_query(uVar5,local_1404);
  if (iVar1 == 0) {
    iVar1 = mysql_store_result(uVar5);
    if (iVar1 == 0) goto LAB_00414da4;
    puVar2 = (undefined4 *)mysql_fetch_row(iVar1);
    if (puVar2 != (undefined4 *)0x0) {
      lVar3 = _atol((char *)*puVar2);
      cVar6 = (char)lVar3;
    }
    mysql_free_result(iVar1);
    if (cVar6 == '\0') goto LAB_00414d51;
  }
  else {
LAB_00414da4:
    iVar1 = *(int *)((int)this + 8);
    iVar8 = -1;
    pcVar7 = s_DBCommandInventoryEnter___mysql__00449e2c;
    pvVar4 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar4,pcVar7,iVar8);
    if (iVar1 != 0) {
      iVar8 = -1;
      uVar5 = mysql_error(iVar1);
      pvVar4 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar4,uVar5,iVar8);
    }
LAB_00414d51:
    local_1409 = 0x34;
  }
  wsprintfA(local_1404,s_SELECT__to_days_now____24_hour_n_004489ec);
  uVar5 = *(undefined4 *)((int)this + 8);
  iVar1 = mysql_query(uVar5,local_1404);
  if (iVar1 == 0) {
    iVar1 = mysql_store_result(uVar5);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)mysql_fetch_row(iVar1);
      if (puVar2 != (undefined4 *)0x0) {
        local_1408 = _atol((char *)*puVar2);
      }
      mysql_free_result(iVar1);
      goto LAB_00414e0c;
    }
  }
  iVar1 = *(int *)((int)this + 8);
  iVar8 = -1;
  pcVar7 = s_DBCommandInventoryEnter___mysql__00449e2c;
  pvVar4 = (void *)FUN_0042aad0();
  FUN_0041d380(pvVar4,pcVar7,iVar8);
  if (iVar1 != 0) {
    iVar8 = -1;
    uVar5 = mysql_error(iVar1);
    pvVar4 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar4,uVar5,iVar8);
  }
  local_1409 = 1;
LAB_00414e0c:
  local_1004 = param_2;
  local_1000 = local_1409;
  local_1002 = 0x12;
  local_fff = local_1408;
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,9,(undefined4 *)&local_1004);
  FUN_00435e83(local_4);
  return;
}
