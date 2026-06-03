/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00416bf0(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint uVar8;
  CHAR *pCVar9;
  bool local_140d;
  undefined2 local_140c;
  long local_1408;
  CHAR local_1404 [1024];
  undefined2 uStack_1004;
  undefined2 uStack_1002;
  bool bStack_1000;
  long lStack_fff;
  uint uStack_ffb;
  undefined2 uStack_ff7;
  int local_4;
  
  local_4 = DAT_00454928;
  uVar8 = 0;
  local_1408 = 0;
  local_140c = 0;
  wsprintfA(local_1404,s_SELECT_id__present_id_FROM_pendi_0044a778,*param_4);
  uVar6 = *(undefined4 *)((int)this + 8);
  iVar1 = mysql_query(uVar6,local_1404);
  if ((iVar1 == 0) && (iVar1 = mysql_store_result(uVar6), iVar1 != 0)) {
    puVar2 = (undefined4 *)mysql_fetch_row(iVar1);
    local_140d = puVar2 == (undefined4 *)0x0;
    if (!local_140d) {
      local_1408 = _atol((char *)*puVar2);
      uVar8 = _atol((char *)puVar2[1]);
    }
    mysql_free_result(iVar1);
    if (((!local_140d) && (10999 < uVar8)) && (uVar8 < 12000)) {
      iVar1 = FUN_0042aad0();
      iVar1 = *(int *)(iVar1 + 0x110);
      iVar3 = FUN_0042aad0();
      iVar4 = 0;
      puVar7 = *(uint **)(iVar3 + 0x114);
      if (0 < iVar1) {
        do {
          if (*puVar7 == uVar8) {
            local_140c = (undefined2)(*(uint **)(iVar3 + 0x114))[iVar4 * 5 + 2];
            break;
          }
          iVar4 = iVar4 + 1;
          puVar7 = puVar7 + 5;
        } while (iVar4 < iVar1);
      }
    }
  }
  else {
    iVar1 = *(int *)((int)this + 8);
    pCVar9 = local_1404;
    iVar3 = -1;
    pvVar5 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar5,pCVar9,iVar3);
    if (iVar1 != 0) {
      iVar3 = -1;
      uVar6 = mysql_error(iVar1);
      pvVar5 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar5,uVar6,iVar3);
    }
    local_140d = true;
  }
  bStack_1000 = local_140d;
  lStack_fff = local_1408;
  uStack_1004 = param_2;
  uStack_1002 = 0x1e;
  uStack_ff7 = local_140c;
  uStack_ffb = uVar8;
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,0xf,(undefined4 *)&uStack_1004);
  FUN_00435e83(local_c);
  return;
}
