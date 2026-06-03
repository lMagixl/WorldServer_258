
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041f480(void *this,ushort param_1,undefined4 param_2,LPCSTR param_3)

{
  LPSTR lpString1;
  LPSTR lpString1_00;
  int iVar1;
  int iVar2;
  CHAR aCStack_1004 [4096];
  int local_4;
  
  local_4 = DAT_00454928;
  if (*(char *)((uint)param_1 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4)) != '\x05') {
    FUN_0041eb20(this,param_1,0x10,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  lpString1 = (LPSTR)((int)this + 300);
  lstrcpynA(lpString1,param_3,0x21);
  iVar1 = lstrlenA(param_3);
  lpString1_00 = (LPSTR)((int)this + 0x14d);
  lstrcpynA(lpString1_00,param_3 + (iVar1 + 1U & 0xffff),0x21);
  lstrlenA(param_3 + (iVar1 + 1U & 0xffff));
  FUN_0042fe00(DAT_00456d84,s_Client_0044bf94,s_MD5_1_0044bf9c,lpString1);
  FUN_0042fe00(DAT_00456d84,s_Client_0044bf94,s_MD5_2_0044bf8c,lpString1_00);
  aCStack_1004[0] = '\v';
  aCStack_1004[1] = '\0';
  aCStack_1004[2] = 0;
  lstrcpyA(aCStack_1004 + 3,lpString1);
  iVar1 = lstrlenA(lpString1);
  lstrcpyA(aCStack_1004 + (iVar1 + 4U & 0xffff),lpString1_00);
  iVar2 = lstrlenA(lpString1_00);
  FUN_004038e0(*(void **)((int)this + 0x118),param_1,(short)iVar1 + 5 + (short)iVar2,
               (undefined4 *)aCStack_1004);
  FUN_00435e83(local_4);
  return;
}


