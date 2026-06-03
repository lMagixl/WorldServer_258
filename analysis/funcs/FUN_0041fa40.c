
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041fa40(void *this,ushort param_1)

{
  void *this_00;
  undefined4 local_1014;
  undefined4 local_1010;
  undefined2 local_100c;
  undefined2 local_100a;
  undefined2 local_1004;
  undefined1 local_1002;
  undefined4 local_1001;
  undefined2 local_ffd;
  undefined4 local_ffb;
  undefined2 local_ff7;
  int local_4;
  
  local_4 = DAT_00454928;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + (uint)param_1 * 0x23b4);
  if ((*(int *)((int)this_00 + 0x1460) != 0) && (*(int *)((int)this_00 + 0x14a4) == 0)) {
    FUN_0040abe0(this_00,&local_1014,&local_100c);
    *(undefined1 *)(*(int *)((int)this + 0xd4) + 0x1478 + (uint)param_1 * 0x23b4) = 0;
    local_ffd = local_100c;
    local_1001 = local_1014;
    local_ffb = local_1010;
    local_1004 = 0xe;
    local_1002 = 0;
    local_ff7 = local_100a;
    FUN_004038e0(*(void **)((int)this + 0x118),param_1,0xf,(undefined4 *)&local_1004);
    FUN_00435e83(local_4);
    return;
  }
  FUN_0041eb20(this,param_1,0x16,'\x01',1);
  FUN_00435e83(local_4);
  return;
}
