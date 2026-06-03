
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00425a70(void *this,ushort param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  char local_108f;
  byte bStack_108e;
  byte local_108d;
  ushort auStack_108c [2];
  CHAR local_1088 [132];
  undefined2 uStack_1004;
  char cStack_1002;
  int local_4;
  
  iVar2 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  iVar1 = *(int *)((int)this + 0xd4) + iVar2;
  if ((*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar2) == 0) ||
     (*(int *)(iVar1 + 0x14a4) == 0)) {
    uVar3 = 0xad;
  }
  else {
    if (*(char *)(iVar1 + 0x1440) == '\x03') {
      local_108d = *param_3;
      local_108f = '\0';
      lstrcpyA(local_1088,(LPCSTR)(param_3 + 1));
      lstrlenA((LPCSTR)(param_3 + 1));
      FUN_0040b7d0((void *)(*(int *)((int)this + 0xd4) + iVar2),auStack_108c,&bStack_108e);
      cStack_1002 = FUN_0040a420((void *)((uint)auStack_108c[0] * 0x3c0 + *(int *)((int)this + 0xe4)
                                         ),&local_108f,&bStack_108e,&local_108d,local_1088);
      if (cStack_1002 != '\0') {
        uStack_1004 = 0x5f;
        FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)&uStack_1004);
        FUN_00435e83(local_4);
        return;
      }
      goto LAB_00425b96;
    }
    uVar3 = 0xae;
  }
  FUN_0041eb20(this,param_1,uVar3,'\x01',1);
LAB_00425b96:
  FUN_00435e83(local_4);
  return;
}
