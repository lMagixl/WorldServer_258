
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00420de0(void *this,ushort param_1)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  undefined2 local_1004;
  char local_1002;
  int iStack_1001;
  undefined1 uStack_ffd;
  undefined4 local_ffc;
  int local_4;
  
  iVar2 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  iVar1 = *(int *)((int)this + 0xd4) + iVar2;
  if ((*(int *)(iVar1 + 0x1460) == 0) || (*(int *)(iVar1 + 0x14a4) == 0)) {
    uVar3 = 0x32;
  }
  else {
    if (*(char *)(iVar1 + 0x1440) == '\x02') {
      local_1002 = FUN_0040b000(iVar1);
      if (local_1002 != '\0') {
        local_1004 = 0x2c;
        iStack_1001 = 0;
        FUN_004038e0(*(void **)((int)this + 0x118),param_1,7,(undefined4 *)&local_1004);
        FUN_00435e83(local_4);
        return;
      }
      iStack_1001 = *(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar2);
      iVar2 = *(int *)((int)this + 0xd4) + iVar2;
      local_ffc = *(undefined4 *)(iVar2 + 0x14a4);
      local_1004 = *(undefined2 *)(iVar2 + 0x1488);
      uStack_ffd = (undefined1)((uint)iStack_1001 >> 0x18);
      local_1002 = 0x12;
      iStack_1001 = iStack_1001 << 8;
      FUN_0041b940(this,param_1,0xc,(undefined4 *)&local_1004);
      FUN_00435e83(local_4);
      return;
    }
    uVar3 = 0x33;
  }
  FUN_0041eb20(this,param_1,uVar3,'\x01',1);
  FUN_00435e83(local_4);
  return;
}
