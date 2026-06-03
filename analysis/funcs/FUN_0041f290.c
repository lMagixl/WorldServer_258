
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041f290(void *this,ushort param_1,undefined4 param_2,LPCSTR param_3)

{
  char cVar1;
  int iVar2;
  CHAR CVar3;
  ushort uVar4;
  LPCSTR lpString;
  ushort uVar5;
  char local_1014 [16];
  undefined2 local_1004;
  CHAR aCStack_1002 [4094];
  int local_4;
  
  local_4 = DAT_00454928;
  iVar2 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  if (((*(char *)(iVar2 + 0x1440) != '\x05') && (cVar1 = *(char *)(iVar2 + 0x146c), cVar1 != '\x01')
      ) && (cVar1 != '4')) {
    FUN_0041eb20(this,param_1,0xd,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  local_1004 = 99;
  iVar2 = lstrlenA(param_3);
  if (iVar2 < 0xd) {
    cVar1 = *param_3;
    lstrcpyA(local_1014,param_3 + 1);
    iVar2 = lstrlenA(param_3 + 1);
    lpString = param_3 + (iVar2 + 2U & 0xffff);
    iVar2 = lstrlenA(lpString);
    if (iVar2 < 0x81) {
      lstrcpyA(aCStack_1002,lpString);
      iVar2 = lstrlenA(lpString);
      uVar5 = (short)iVar2 + 3;
      uVar4 = 0;
      if (local_1014[0] == '\0') {
        if (DAT_00456030 != 0) {
          do {
            iVar2 = FUN_0040c870((void *)((uint)uVar4 * 0x23b4 + *(int *)((int)this + 0xd4)),cVar1,
                                 local_1014);
            if (iVar2 != 0) {
              FUN_004038e0(*(void **)((int)this + 0x118),uVar4,uVar5,(undefined4 *)&local_1004);
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < DAT_00456030);
        }
      }
      else {
        CVar3 = '\x01';
        if (DAT_00456030 != 0) {
          do {
            iVar2 = FUN_0040c870((void *)((uint)uVar4 * 0x23b4 + *(int *)((int)this + 0xd4)),cVar1,
                                 local_1014);
            if (iVar2 != 0) {
              FUN_004038e0(*(void **)((int)this + 0x118),uVar4,uVar5,(undefined4 *)&local_1004);
              CVar3 = '\0';
              break;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < DAT_00456030);
        }
        local_1004 = 5;
        aCStack_1002[0] = CVar3;
        FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)&local_1004);
      }
    }
    else {
      FUN_0041eb20(this,param_1,0xf,'\x01',1);
    }
  }
  else {
    FUN_0041eb20(this,param_1,0xe,'\x01',1);
  }
  FUN_00435e83(local_4);
  return;
}
