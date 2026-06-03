
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041f5c0(void *this,ushort param_1,undefined4 param_2,ushort *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined2 local_1004;
  byte local_1002;
  ushort local_1001;
  CHAR local_fff [4091];
  int local_4;
  
  local_4 = DAT_00454928;
  if (*(char *)((uint)param_1 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4)) != '\x05') {
    FUN_0041eb20(this,param_1,0x11,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  local_1001 = *param_3;
  if (local_1001 < DAT_00455824) {
    local_1002 = (*(char *)((uint)local_1001 * 0x3c0 + 8 + *(int *)((int)this + 0xe4)) != '\0') - 1U
                 & 2;
  }
  else {
    local_1002 = 1;
  }
  local_1004 = 9;
  uVar1 = 5;
  if (local_1002 == 0) {
    iVar2 = FUN_004058e0((void *)((uint)local_1001 * 0x3c0 + *(int *)((int)this + 0xe4)),local_fff);
    uVar1 = (short)iVar2 + 5;
  }
  FUN_004038e0(*(void **)((int)this + 0x118),param_1,uVar1,(undefined4 *)&local_1004);
  FUN_00435e83(local_4);
  return;
}


