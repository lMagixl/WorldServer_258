
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041fcd0(void *this,ushort param_1,undefined4 param_2,LPCSTR param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  ushort uVar4;
  undefined4 local_1004;
  int local_1000;
  CHAR local_ffc [4088];
  int local_4;
  
  local_4 = DAT_00454928;
  iVar3 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  local_1000 = *(int *)(iVar3 + 0x1460);
  if ((local_1000 == 0) || (*(int *)(iVar3 + 0x14a4) != 0)) {
    FUN_0041eb20(this,param_1,0x19,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  local_1004._0_2_ = *(undefined2 *)(iVar3 + 0x1488);
  local_1004._2_2_ = 7;
  iVar3 = lstrlenA(param_3);
  if (iVar3 < 0xd) {
    lstrcpyA(local_ffc,param_3);
    iVar3 = lstrlenA(param_3);
    bVar1 = param_3[iVar3 + 1U & 0xffff];
    if (bVar1 < 5) {
      bVar2 = param_3[iVar3 + 2U & 0xffff];
      if (bVar2 < 6) {
        iVar3 = lstrlenA(local_ffc);
        *(byte *)((int)&local_1004 + (iVar3 + 9U & 0xffff)) = bVar1;
        *(byte *)((int)&local_1004 + (iVar3 + 10U & 0xffff)) = bVar2;
        FUN_0041b940(this,param_1,(short)iVar3 + 0xb,&local_1004);
        goto LAB_0041fd5a;
      }
      uVar4 = 0xea;
    }
    else {
      uVar4 = 0x1b;
    }
  }
  else {
    uVar4 = 0x1a;
  }
  FUN_0041eb20(this,param_1,uVar4,'\x01',1);
LAB_0041fd5a:
  FUN_00435e83(local_4);
  return;
}


