
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00420410(void *this,ushort param_1)

{
  void *this_00;
  ushort uVar1;
  undefined1 local_100a;
  byte local_1009;
  undefined4 local_1008;
  undefined2 local_1004;
  undefined1 local_1002;
  undefined1 local_1001;
  undefined2 local_1000;
  int local_4;
  
  local_4 = DAT_00454928;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + (uint)param_1 * 0x23b4);
  if ((*(int *)((int)this_00 + 0x1460) != 0) && (*(int *)((int)this_00 + 0x14a4) != 0)) {
    local_1008 = 0;
    if (*(char *)((int)this_00 + 0x1440) == '\x02') {
      FUN_0040af90(this_00,&local_1009,&local_100a);
      local_1001 = 0;
      local_1008 = CONCAT22(local_1008._2_2_,(ushort)local_1009);
    }
    else {
      if (*(char *)((int)this_00 + 0x1440) != '\x03') {
        uVar1 = 0x25;
        goto LAB_004204f7;
      }
      FUN_0040b7d0(this_00,(undefined2 *)&local_1008,&local_100a);
      local_1001 = 1;
    }
    local_1002 = *(undefined1 *)((int)this + 0x54);
    local_1004 = 0x17;
    local_1000 = (undefined2)local_1008;
    FUN_004038e0(*(void **)((int)this + 0x118),param_1,6,(undefined4 *)&local_1004);
    FUN_00435e83(local_4);
    return;
  }
  uVar1 = 0x24;
LAB_004204f7:
  FUN_0041eb20(this,param_1,uVar1,'\x01',1);
  FUN_00435e83(local_4);
  return;
}
