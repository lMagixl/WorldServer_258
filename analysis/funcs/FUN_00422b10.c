
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00422b10(void *this,ushort param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  uint local_1018;
  uint local_1014;
  undefined4 local_1010;
  char local_100c;
  undefined3 uStack_100b;
  char local_1008;
  undefined3 uStack_1007;
  undefined2 local_1004;
  undefined2 local_1002;
  undefined4 local_1000;
  undefined1 local_ffc;
  undefined2 local_ffb;
  char local_ff9;
  undefined4 local_ff8;
  uint local_ff4;
  uint local_ff0;
  ushort local_fec;
  int local_4;
  
  local_4 = DAT_00454928;
  cVar1 = param_3[1];
  cVar2 = *param_3;
  uVar5 = 0;
  _local_100c = CONCAT31(uStack_100b,cVar2);
  _local_1008 = CONCAT31(uStack_1007,cVar1);
  if (cVar1 != '\0') {
    uVar5 = *(ushort *)(param_3 + 2);
  }
  if ((cVar2 != '\0') && (cVar2 != '\x01')) {
    FUN_0041eb20(this,param_1,0x45,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  local_1010 = 0;
  iVar6 = (uint)param_1 * 0x23b4;
  local_1018 = 0;
  local_1014 = 0;
  uVar4 = FUN_0040b2c0((void *)(*(int *)((int)this + 0xd4) + iVar6),cVar2,cVar1,uVar5,&local_1010,
                       &local_1018,&local_1014);
  if ((char)uVar4 == '\0') {
    local_1000 = *(undefined4 *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar6);
    iVar6 = *(int *)((int)this + 0xd4) + iVar6;
    local_ffb = *(undefined2 *)(iVar6 + 0x2370);
    local_1004 = *(undefined2 *)(iVar6 + 0x1488);
    local_1002 = 0x17;
    local_ffc = local_100c;
    uVar3 = 0xc;
    if (cVar1 == '\x01') {
      local_ff4 = local_1018;
      local_ff8 = local_1010;
      local_ff0 = local_1014;
      uVar3 = 0x1a;
      local_fec = uVar5;
    }
    local_ff9 = cVar1;
    FUN_0041b940(this,param_1,uVar3,(undefined4 *)&local_1004);
  }
  else {
    local_1002 = CONCAT11(local_1002._1_1_,(char)uVar4);
    local_1004 = 0x34;
    FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)&local_1004);
  }
  FUN_00435e83(local_4);
  return;
}
