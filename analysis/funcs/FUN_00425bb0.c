
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00425bb0(void *this,ushort param_1,undefined4 param_2,char *param_3)

{
  void *this_00;
  ushort uVar1;
  char local_100b [3];
  ushort local_1008 [2];
  undefined2 local_1004;
  char local_1002;
  int local_4;
  
  local_4 = DAT_00454928;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + (uint)param_1 * 0x23b4);
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    uVar1 = 0xaf;
  }
  else {
    if (*(char *)((int)this_00 + 0x1440) == '\x03') {
      local_100b[0] = *param_3;
      FUN_0040b7d0(this_00,local_1008,local_100b + 2);
      local_100b[1] = 0;
      local_1002 = FUN_0040a420((void *)((uint)local_1008[0] * 0x3c0 + *(int *)((int)this + 0xe4)),
                                local_100b,(byte *)(local_100b + 2),(byte *)(local_100b + 1),
                                (char *)0x0);
      if (local_1002 != '\0') {
        local_1004 = 0x5f;
        FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)&local_1004);
        FUN_00435e83(local_4);
        return;
      }
      goto LAB_00425ca9;
    }
    uVar1 = 0xb0;
  }
  FUN_0041eb20(this,param_1,uVar1,'\x01',1);
LAB_00425ca9:
  FUN_00435e83(local_4);
  return;
}
