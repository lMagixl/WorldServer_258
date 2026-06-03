
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00425860(void *this,ushort param_1,undefined4 param_2,ushort *param_3)

{
  char cVar1;
  ushort uVar2;
  void *this_00;
  undefined2 local_100a;
  undefined2 local_1008 [2];
  undefined2 local_1004;
  undefined2 local_1002;
  undefined4 local_1000;
  int local_4;
  
  local_4 = DAT_00454928;
  this_00 = (void *)((uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4));
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    FUN_0041eb20(this,param_1,0xa8,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(char *)((int)this_00 + 0x1440) == '\x03') {
    uVar2 = *param_3;
    if (uVar2 < DAT_00456030) {
      FUN_0040b7d0(this_00,local_1008,(undefined1 *)&local_100a);
      local_1002 = local_100a;
      local_1000 = *(undefined4 *)(param_3 + 1);
      local_1004 = 0x5a;
      cVar1 = *(char *)((uint)uVar2 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4));
      if ((cVar1 != '\0') && (cVar1 == '\x03')) {
        FUN_004038e0(*(void **)((int)this + 0x118),uVar2,8,(undefined4 *)&local_1004);
        FUN_00435e83(local_4);
        return;
      }
    }
    else {
      FUN_0041eb20(this,param_1,0xa9,'\x01',1);
    }
  }
  FUN_00435e83(local_4);
  return;
}
