// FUN_004121e0 — DB opcode 0x05, RealIP update handler
// Address: 0x004121e0

void __thiscall FUN_004121e0(void *this)

{
  char *pcVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  _union_1226 *in_stack_00000010;
  CHAR *pCVar5;
  ULONG UVar6;
  int iVar7;
  CHAR aCStack_404 [1024];
  int local_4;
  
  local_4 = DAT_00454928;
  UVar6 = in_stack_00000010[1].S_addr;
  pcVar1 = inet_ntoa((in_addr)in_stack_00000010->S_un_b);
  wsprintfA(aCStack_404,s_UPDATE_LogUserConnect_SET_RealIP_00448db8,pcVar1,UVar6);
  iVar2 = mysql_query(*(undefined4 *)((int)this + 0x20),aCStack_404);
  if (iVar2 != 0) {
    iVar2 = *(int *)((int)this + 0x20);
    pCVar5 = aCStack_404;
    iVar7 = -1;
    pvVar3 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar3,pCVar5,iVar7);
    if (iVar2 != 0) {
      iVar7 = -1;
      uVar4 = mysql_error(iVar2);
      pvVar3 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar3,uVar4,iVar7);
    }
  }
  FUN_00435e83(local_4);
  return;
}

// SQL strings found: UPDATE
