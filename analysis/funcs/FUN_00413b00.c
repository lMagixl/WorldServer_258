
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00413b00(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  CHAR *pCVar4;
  int iVar5;
  CHAR local_1404 [1024];
  undefined2 uStack_1004;
  undefined2 uStack_1002;
  int local_4;
  
  pCVar4 = local_1404;
  local_4 = DAT_00454928;
  wsprintfA(local_1404,s_UPDATE_UserGameInfo_SET_tutorial_0044973c,*param_4);
  iVar1 = mysql_query(*(undefined4 *)((int)this + 8),local_1404);
  if (iVar1 != 0) {
    iVar1 = *(int *)((int)this + 8);
    iVar5 = -1;
    pvVar2 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar2,pCVar4,iVar5);
    if (iVar1 != 0) {
      iVar5 = -1;
      uVar3 = mysql_error(iVar1);
      pvVar2 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar2,uVar3,iVar5);
    }
  }
  uStack_1004 = param_2;
  uStack_1002 = 0xe;
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,4,(undefined4 *)&uStack_1004);
  FUN_00435e83(local_4);
  return;
}


