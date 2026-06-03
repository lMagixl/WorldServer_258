
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00429030(void *this,ushort param_1,undefined4 param_2,ushort *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char local_1009;
  undefined2 local_1004;
  char local_1002;
  int local_4;
  
  local_4 = DAT_00454928;
  if (*(char *)((uint)param_1 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4)) != '\x05') {
    FUN_0041eb20(this,param_1,199,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  local_1009 = '\0';
  uVar3 = 2;
  for (uVar2 = (uint)*param_3; uVar2 != 0; uVar2 = uVar2 - 1) {
    uVar1 = *(uint *)((uVar3 & 0xffff) + (int)param_3);
    uVar4 = uVar3 + 4;
    uVar3 = uVar3 + 8;
    if (uVar1 < 0x200) {
      InterlockedExchange((LONG *)((int)this + uVar1 * 4 + 0x51c8),
                          *(LONG *)((uVar4 & 0xffff) + (int)param_3));
    }
    else {
      local_1009 = local_1009 + '\x01';
    }
  }
  local_1004 = 8;
  local_1002 = local_1009;
  FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)&local_1004);
  FUN_00435e83(local_4);
  return;
}
