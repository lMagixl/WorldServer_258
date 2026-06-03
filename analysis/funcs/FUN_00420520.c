
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00420520(void *this,ushort param_1,undefined4 param_2,LPCSTR param_3)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined2 extraout_var_00;
  void *pvVar4;
  undefined1 uVar5;
  byte bStack_101a;
  undefined1 uStack_1019;
  undefined4 uStack_1018;
  CHAR aCStack_1014 [16];
  undefined4 uStack_1004;
  int local_4;
  
  local_4 = DAT_00454928;
  iVar3 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  if ((*(int *)(iVar3 + 0x1460) == 0) || (*(int *)(iVar3 + 0x14a4) == 0)) {
    FUN_0041eb20(this,param_1,0x26,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  iVar3 = lstrlenA(param_3);
  if (0xc < iVar3) {
    FUN_0041eb20(this,param_1,0x27,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  lstrcpyA(aCStack_1014,param_3);
  uVar2 = 0;
  if (DAT_00456030 != 0) {
    do {
      pvVar4 = (void *)(*(int *)((int)this + 0xd4) + (uint)uVar2 * 0x23b4);
      if ((((*(char *)((int)pvVar4 + 0x1440) != '\0') && (*(int *)((int)pvVar4 + 0x1460) != 0)) &&
          (*(int *)((int)pvVar4 + 0x14a4) != 0)) &&
         ((bVar1 = FUN_0040af20(pvVar4,aCStack_1014), CONCAT31(extraout_var,bVar1) != 0 &&
          (*(char *)(*(int *)((int)this + 0xd4) + 0x146c + (uint)uVar2 * 0x23b4) != '\x01')))) {
        pvVar4 = (void *)((uint)uVar2 * 0x23b4 + *(int *)((int)this + 0xd4));
        uStack_1018 = 0;
        if (*(char *)((int)pvVar4 + 0x1440) == '\x02') {
          FUN_0040af90(pvVar4,&bStack_101a,&uStack_1019);
          uStack_1018 = CONCAT22(extraout_var_00,(ushort)bStack_101a);
          uVar5 = 0;
        }
        else {
          if (*(char *)((int)pvVar4 + 0x1440) != '\x03') break;
          FUN_0040b7d0(pvVar4,(undefined2 *)&uStack_1018,&uStack_1019);
          uVar5 = 1;
        }
        uStack_1004._0_2_ = 0x18;
        uStack_1004._2_1_ = 0;
        lstrcpyA((LPSTR)((int)&uStack_1004 + 3),aCStack_1014);
        iVar3 = lstrlenA(aCStack_1014);
        *(undefined1 *)((int)&uStack_1004 + (iVar3 + 4U & 0xffff)) = uVar5;
        *(undefined2 *)((int)&uStack_1004 + (iVar3 + 5U & 0xffff)) = (undefined2)uStack_1018;
        uVar2 = (short)iVar3 + 7;
        goto LAB_0042065c;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_00456030);
  }
  uStack_1004._0_2_ = 0x18;
  uStack_1004._2_1_ = 1;
  lstrcpyA((LPSTR)((int)&uStack_1004 + 3),aCStack_1014);
  iVar3 = lstrlenA(aCStack_1014);
  uVar2 = (short)iVar3 + 4;
LAB_0042065c:
  FUN_004038e0(*(void **)((int)this + 0x118),param_1,uVar2,&uStack_1004);
  FUN_00435e83(local_4);
  return;
}
