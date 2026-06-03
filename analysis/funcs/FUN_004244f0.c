
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_004244f0(void *this,ushort param_1,undefined4 param_2,LPCSTR param_3)

{
  int iVar1;
  int iVar2;
  undefined1 uStack_1009;
  ushort auStack_1008 [2];
  undefined2 uStack_1004;
  undefined1 uStack_1002;
  CHAR aCStack_1001 [4093];
  int local_4;
  
  iVar2 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  iVar1 = *(int *)((int)this + 0xd4) + iVar2;
  if ((*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar2) != 0) &&
     (*(int *)(iVar1 + 0x14a4) != 0)) {
    if (*(char *)(iVar1 + 0x1440) != '\x03') {
      FUN_0041eb20(this,param_1,0x7f,'\x01',1);
      FUN_00435e83(local_4);
      return;
    }
    iVar1 = lstrlenA(param_3);
    if (iVar1 < 0x81) {
      FUN_0040b7d0((void *)(*(int *)((int)this + 0xd4) + iVar2),auStack_1008,&uStack_1009);
      uStack_1004 = 0x47;
      uStack_1002 = uStack_1009;
      lstrcpyA(aCStack_1001,param_3);
      iVar1 = lstrlenA(aCStack_1001);
      FUN_004061f0((void *)((uint)auStack_1008[0] * 0x3c0 + *(int *)((int)this + 0xe4)),
                   (short)iVar1 + 4,(undefined4 *)&uStack_1004);
    }
    else {
      FUN_0041eb20(this,param_1,0x80,'\x01',1);
    }
    FUN_00435e83(local_4);
    return;
  }
  FUN_0041eb20(this,param_1,0x7e,'\x01',1);
  FUN_00435e83(local_4);
  return;
}
