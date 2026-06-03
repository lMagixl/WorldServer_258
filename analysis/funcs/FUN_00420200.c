
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00420200(void *this,ushort param_1,undefined4 param_2,LPCSTR param_3)

{
  LPCSTR lpString;
  void *this_00;
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  CHAR aCStack_1014 [16];
  CHAR aCStack_1004 [4096];
  int local_4;
  
  iVar3 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  if ((*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar3) == 0) ||
     (*(int *)(*(int *)((int)this + 0xd4) + iVar3 + 0x14a4) == 0)) {
    FUN_0041eb20(this,param_1,0x21,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  iVar2 = lstrlenA(param_3);
  if (iVar2 < 0xd) {
    lstrcpyA(aCStack_1014,param_3);
    iVar2 = lstrlenA(param_3);
    lpString = param_3 + (iVar2 + 1U & 0xffff);
    iVar2 = lstrlenA(lpString);
    if (iVar2 < 0x81) {
      if (DAT_00456030 != 0) {
        uVar4 = 0;
        do {
          this_00 = (void *)(*(int *)((int)this + 0xd4) + (uint)uVar4 * 0x23b4);
          if ((((*(char *)((int)this_00 + 0x1440) != '\0') && (*(int *)((int)this_00 + 0x1460) != 0)
               ) && (*(int *)((int)this_00 + 0x14a4) != 0)) &&
             ((bVar1 = FUN_0040af20(this_00,aCStack_1014), CONCAT31(extraout_var,bVar1) != 0 &&
              (*(char *)(*(int *)((int)this + 0xd4) + 0x146c + (uint)uVar4 * 0x23b4) != '\x01')))) {
            aCStack_1004[0] = '\x16';
            aCStack_1004[1] = '\0';
            aCStack_1004[2] = 0;
            lstrcpyA(aCStack_1004 + 3,(LPCSTR)(*(int *)((int)this + 0xd4) + 0x14a8 + iVar3));
            iVar3 = lstrlenA((LPCSTR)(*(int *)((int)this + 0xd4) + 0x14a8 + iVar3));
            lstrcpyA(aCStack_1004 + (iVar3 + 4U & 0xffff),lpString);
            iVar2 = lstrlenA(lpString);
            uVar5 = (short)iVar3 + 5 + (short)iVar2;
            FUN_004038e0(*(void **)((int)this + 0x118),uVar4,uVar5,(undefined4 *)aCStack_1004);
            FUN_004038e0(*(void **)((int)this + 0x118),param_1,uVar5,(undefined4 *)aCStack_1004);
            goto LAB_00420272;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < DAT_00456030);
      }
      aCStack_1004[0] = '\x16';
      aCStack_1004[1] = '\0';
      aCStack_1004[2] = 1;
      FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)aCStack_1004);
      goto LAB_00420272;
    }
    uVar4 = 0x23;
  }
  else {
    uVar4 = 0x22;
  }
  FUN_0041eb20(this,param_1,uVar4,'\x01',1);
LAB_00420272:
  FUN_00435e83(local_4);
  return;
}
