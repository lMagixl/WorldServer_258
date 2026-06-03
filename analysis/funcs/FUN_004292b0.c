
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_004292b0(void *this,ushort param_1)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  undefined2 local_1004;
  undefined2 local_1002;
  int local_1000;
  int local_ffc;
  undefined4 local_ff8;
  undefined2 local_ff4;
  int local_4;
  
  local_4 = DAT_00454928;
  iVar2 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  local_1000 = *(int *)(iVar2 + 0x1460);
  if ((local_1000 == 0) || (local_ffc = *(int *)(iVar2 + 0x14a4), local_ffc == 0)) {
    uVar3 = 0xd9;
  }
  else {
    if (*(char *)(iVar2 + 0x1440) == '\x02') {
      bVar1 = *(byte *)(iVar2 + 0x1531);
      local_ff8 = 0;
      local_ff4 = 0;
      if ((bVar1 < 10) || (0x14 < bVar1)) {
        if ((bVar1 < 0x15) || (0x28 < bVar1)) {
          if (0x28 < bVar1) {
            local_ff8 = *(undefined4 *)(*(int *)((int)this + 0x10c) + 0x4e3a8);
            local_ff4 = 0x271d;
          }
        }
        else {
          local_ff8 = *(undefined4 *)(*(int *)((int)this + 0x10c) + 0x4e388);
          local_ff4 = 0x271c;
        }
      }
      else {
        local_ff8 = *(undefined4 *)(*(int *)((int)this + 0x10c) + 0x4e368);
        local_ff4 = 0x271b;
      }
      local_1004 = *(undefined2 *)(iVar2 + 0x1488);
      local_1002 = 0x23;
      FUN_0041b940(this,param_1,0x12,(undefined4 *)&local_1004);
      FUN_00435e83(local_4);
      return;
    }
    uVar3 = 0xda;
  }
  FUN_0041eb20(this,param_1,uVar3,'\x01',1);
  FUN_00435e83(local_4);
  return;
}


