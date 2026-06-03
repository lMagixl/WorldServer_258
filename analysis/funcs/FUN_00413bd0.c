
void __thiscall FUN_00413bd0(void *this)

{
  LPCSTR lpString2;
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 *in_stack_00000010;
  CHAR *pCVar7;
  CHAR aCStack_424 [16];
  CHAR local_414 [16];
  CHAR aCStack_404 [1024];
  int local_4;
  
  local_4 = DAT_00454928;
  uVar6 = *in_stack_00000010;
  lstrcpyA(local_414,(LPCSTR)(in_stack_00000010 + 1));
  iVar3 = lstrlenA((LPCSTR)(in_stack_00000010 + 1));
  uVar2 = *(undefined4 *)((iVar3 + 5U & 0xffff) + (int)in_stack_00000010);
  lpString2 = (LPCSTR)((iVar3 + 9U & 0xffff) + (int)in_stack_00000010);
  lstrcpyA(aCStack_424,lpString2);
  iVar4 = lstrlenA(lpString2);
  uVar1 = iVar3 + 10 + iVar4;
  wsprintfA(aCStack_404,s_INSERT_INTO_LogDiePlayer__killer_00449770,uVar6,local_414,uVar2,
            aCStack_424,(uint)*(byte *)((uVar1 & 0xffff) + (int)in_stack_00000010),
            (uint)*(byte *)((uVar1 + 1 & 0xffff) + (int)in_stack_00000010));
  iVar3 = mysql_query(*(undefined4 *)((int)this + 0x20),aCStack_404);
  if (iVar3 != 0) {
    iVar3 = *(int *)((int)this + 0x20);
    pCVar7 = aCStack_404;
    iVar4 = -1;
    pvVar5 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar5,pCVar7,iVar4);
    if (iVar3 != 0) {
      iVar4 = -1;
      uVar6 = mysql_error(iVar3);
      pvVar5 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar5,uVar6,iVar4);
    }
  }
  FUN_00435e83(local_4);
  return;
}


