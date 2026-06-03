
void __thiscall FUN_00412140(void *this)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_stack_00000010;
  CHAR *pCVar4;
  int iVar5;
  CHAR local_404 [1024];
  int local_4;
  
  local_4 = DAT_00454928;
  wsprintfA(local_404,s_UPDATE_LogUserConnect_SET_discon_00448d70,
            (uint)*(ushort *)(in_stack_00000010 + 1),*in_stack_00000010);
  iVar1 = mysql_query(*(undefined4 *)((int)this + 0x20),local_404);
  if (iVar1 != 0) {
    iVar1 = *(int *)((int)this + 0x20);
    pCVar4 = local_404;
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
  FUN_00435e83(local_4);
  return;
}



/* === METADATA ===
SIGNATURE: undefined __thiscall FUN_00412140(void * this)
XREFS: 0041aeca
CALLEES: FUN_0041d380 FUN_00435e83 mysql_error wsprintfA mysql_query FUN_0042aad0
CALLERS: FUN_0041ae50
SIZE: 845 chars */
