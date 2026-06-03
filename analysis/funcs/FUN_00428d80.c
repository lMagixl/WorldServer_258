
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00428d80(void *this,ushort param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_1009;
  undefined4 local_1008;
  undefined2 local_1004;
  undefined2 local_1002;
  undefined4 local_1000;
  undefined4 local_ffc;
  undefined1 local_ff8;
  undefined4 local_ff7;
  undefined2 local_ff3;
  int local_4;
  
  iVar4 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  iVar3 = *(int *)((int)this + 0xd4) + iVar4;
  if ((*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar4) == 0) ||
     (*(int *)(iVar3 + 0x14a4) == 0)) {
    FUN_0041eb20(this,param_1,0xd3,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(char *)(iVar3 + 0x1440) != '\x02') {
    FUN_0041eb20(this,param_1,0xd4,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  cVar1 = *(char *)(iVar3 + 0x2368);
  if (cVar1 == '\x03') {
    iVar3 = 0x2718;
  }
  else if (cVar1 == '\x04') {
    iVar3 = 0x2719;
  }
  else {
    if (cVar1 != '\x05') {
      FUN_0041eb20(this,param_1,0xd5,'\x01',1);
      goto LAB_00428e9e;
    }
    iVar3 = 0x271a;
  }
  FUN_0040a860((void *)(iVar3 * 0x20 + *(int *)((int)this + 0x10c)),&local_1009,&local_1008);
  iVar2 = *(int *)((int)this + 0xd4);
  local_ffc = *(undefined4 *)(iVar2 + 0x14a4 + iVar4);
  local_1000 = *(undefined4 *)(iVar2 + 0x1460 + iVar4);
  local_1004 = *(undefined2 *)(iVar2 + iVar4 + 0x1488);
  local_ff8 = local_1009;
  local_1002 = 0x21;
  local_ff7 = local_1008;
  local_ff3 = (undefined2)iVar3;
  FUN_0041b940(this,param_1,0x13,(undefined4 *)&local_1004);
LAB_00428e9e:
  FUN_00435e83(local_4);
  return;
}
