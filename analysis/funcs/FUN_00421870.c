
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00421870(void *this,ushort param_1,undefined4 param_2,char *param_3)

{
  void *this_00;
  byte bVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined1 local_1026;
  undefined1 local_1025;
  byte local_1024;
  undefined3 uStack_1023;
  char local_1020;
  undefined3 uStack_101f;
  undefined4 local_101c;
  undefined4 local_1018;
  undefined4 local_1014;
  byte local_1010;
  undefined3 uStack_100f;
  undefined4 local_100c;
  char local_1008;
  undefined3 uStack_1007;
  undefined2 local_1004;
  undefined1 local_1002;
  char local_1001;
  undefined1 local_1000;
  undefined2 local_fff;
  undefined1 local_ffd;
  undefined4 local_ffc;
  undefined1 local_ff8;
  undefined1 local_ff7;
  undefined2 local_ff6;
  undefined1 local_ff4;
  undefined4 local_ff3;
  int local_4;
  
  local_4 = DAT_00454928;
  this_00 = (void *)((uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4));
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    FUN_0041eb20(this,param_1,0x3c,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(char *)((int)this_00 + 0x1440) != '\x02') {
    FUN_0041eb20(this,param_1,0x3d,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  bVar1 = param_3[1];
  cVar2 = *param_3;
  _local_1024 = CONCAT31(uStack_1023,bVar1);
  cVar3 = param_3[2];
  bVar4 = param_3[3];
  _local_1008 = CONCAT31(uStack_1007,cVar2);
  _local_1020 = CONCAT31(uStack_101f,cVar3);
  _local_1010 = CONCAT31(uStack_100f,bVar4);
  if (cVar2 == '\0') {
    if (bVar1 < 0x78) goto LAB_00421926;
  }
  else if (bVar1 < 0x13) {
LAB_00421926:
    if (cVar3 == '\0') {
      bVar6 = bVar4 < 0x78;
    }
    else {
      bVar6 = bVar4 < 0x13;
    }
    if (bVar6) {
      local_1025 = 0;
      local_1026 = 0;
      local_100c = 0;
      local_101c = 0;
      local_1018 = 0;
      local_1014 = 0;
      uVar5 = FUN_0040cf10(this_00,cVar2,bVar1,cVar3,bVar4,(undefined2 *)&local_100c,&local_1025,
                           &local_1018,(undefined2 *)&local_101c,&local_1026,&local_1014);
      local_1002 = (undefined1)uVar5;
      local_1000 = local_1024;
      local_ffc = local_1018;
      local_fff = (undefined2)local_100c;
      local_ff6 = (undefined2)local_101c;
      local_ffd = local_1025;
      local_ff8 = local_1020;
      local_ff7 = local_1010;
      local_ff4 = local_1026;
      local_1004 = 0x31;
      local_ff3 = local_1014;
      local_1001 = cVar2;
      FUN_004038e0(*(void **)((int)this + 0x118),param_1,0x15,(undefined4 *)&local_1004);
      goto LAB_0042193c;
    }
  }
  FUN_0041eb20(this,param_1,0x3e,'\x01',1);
LAB_0042193c:
  FUN_00435e83(local_4);
  return;
}
