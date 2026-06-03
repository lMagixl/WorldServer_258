
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_004226b0(void *this,ushort param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  void *this_00;
  ushort uVar4;
  int iVar5;
  uint local_1014;
  undefined4 local_1010;
  uint local_100c;
  char local_1008;
  undefined3 uStack_1007;
  undefined2 local_1004;
  undefined2 local_1002;
  undefined4 local_1000;
  undefined1 local_ffc;
  char local_ffb;
  undefined4 local_ffa;
  uint local_ff6;
  uint local_ff2;
  ushort local_fee;
  int local_4;
  
  local_4 = DAT_00454928;
  iVar5 = (uint)param_1 * 0x23b4;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + iVar5);
  uVar4 = 0;
  if ((*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar5) != 0) &&
     (*(int *)((int)this_00 + 0x14a4) != 0)) {
    if (*(char *)((int)this_00 + 0x1440) != '\x02') {
      FUN_0041eb20(this,param_1,0x40,'\x01',1);
      FUN_00435e83(local_4);
      return;
    }
    cVar1 = *param_3;
    local_100c = 0;
    local_1010 = 0;
    local_1014 = 0;
    _local_1008 = CONCAT31(uStack_1007,cVar1);
    if (cVar1 != '\0') {
      uVar4 = *(ushort *)(param_3 + 1);
    }
    iVar3 = FUN_0040b080(this_00,cVar1,uVar4,&local_1010,&local_100c,&local_1014);
    if ((char)iVar3 == '\0') {
      iVar3 = *(int *)((int)this + 0xd4);
      local_ffc = *(undefined1 *)(iVar3 + 0x1540 + iVar5);
      local_1004 = *(undefined2 *)(iVar3 + 0x1488 + iVar5);
      local_1000 = *(undefined4 *)(iVar3 + iVar5 + 0x1460);
      local_1002 = 0x16;
      uVar2 = 10;
      if (cVar1 == '\x01') {
        local_ffa = local_1010;
        local_ff6 = local_100c;
        local_ff2 = local_1014;
        uVar2 = 0x18;
        local_fee = uVar4;
      }
      local_ffb = cVar1;
      FUN_0041b940(this,param_1,uVar2,(undefined4 *)&local_1004);
    }
    else {
      local_1004 = 0x32;
      local_1002 = CONCAT11(local_1002._1_1_,(char)iVar3);
      FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)&local_1004);
    }
    FUN_00435e83(local_4);
    return;
  }
  FUN_0041eb20(this,param_1,0x3f,'\x01',1);
  FUN_00435e83(local_4);
  return;
}
