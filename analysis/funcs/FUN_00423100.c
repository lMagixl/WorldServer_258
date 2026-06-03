
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00423100(void *this,ushort param_1,undefined4 param_2,ushort *param_3)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  byte bStack_1019;
  ushort *local_1018;
  byte abStack_1014 [4];
  CHAR aCStack_1010 [12];
  undefined2 local_1004;
  undefined2 local_1002;
  undefined4 uStack_1000;
  ushort uStack_ffc;
  CHAR aCStack_ffa [4086];
  int local_4;
  
  iVar2 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  iVar1 = *(int *)((int)this + 0xd4) + iVar2;
  if ((*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar2) == 0) ||
     (*(int *)(iVar1 + 0x14a4) == 0)) {
    FUN_0041eb20(this,param_1,0x4a,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(char *)(iVar1 + 0x1440) != '\x02') {
    local_1004 = 0x38;
    local_1002 = CONCAT11(local_1002._1_1_,5);
    FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)&local_1004);
    FUN_00435e83(local_4);
    return;
  }
  uVar3 = *param_3;
  if (DAT_00455824 < uVar3) {
    uVar3 = 0x4c;
  }
  else {
    local_1018 = param_3 + 1;
    iVar1 = lstrlenA((LPCSTR)local_1018);
    if (iVar1 < 9) {
      lstrcpyA(aCStack_1010,(LPCSTR)local_1018);
      if (*(char *)((uint)uVar3 * 0x3c0 + 0x119 + *(int *)((int)this + 0xe4)) == '\0') {
        uStack_1000 = *(undefined4 *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar2);
        local_1004 = *(undefined2 *)(*(int *)((int)this + 0xd4) + 0x1488 + iVar2);
        local_1002 = 0x26;
        uStack_ffc = uVar3;
        lstrcpyA(aCStack_ffa,aCStack_1010);
        iVar1 = lstrlenA(aCStack_1010);
        FUN_0041b940(this,param_1,(short)iVar1 + 0xb,(undefined4 *)&local_1004);
      }
      else {
        iVar1 = FUN_00406f40((void *)((uint)uVar3 * 0x3c0 + *(int *)((int)this + 0xe4)),0,
                             aCStack_1010,param_1,abStack_1014,0);
        if (iVar1 != 0) {
          FUN_0040af90((void *)(*(int *)((int)this + 0xd4) + iVar2),&bStack_1019,
                       (undefined1 *)&local_1018);
          FUN_00405240((void *)((uint)bStack_1019 * 0x358 + *(int *)((int)this + 0xdc)),
                       (byte)local_1018);
          FUN_0040b7b0((void *)(*(int *)((int)this + 0xd4) + iVar2),uVar3,abStack_1014[0]);
        }
      }
      goto LAB_004231b2;
    }
    uVar3 = 0x4d;
  }
  FUN_0041eb20(this,param_1,uVar3,'\x01',1);
LAB_004231b2:
  FUN_00435e83(local_4);
  return;
}
