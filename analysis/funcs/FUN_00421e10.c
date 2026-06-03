/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00421e10(void *this,ushort param_1,undefined4 param_2,undefined1 *param_3)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  ushort uVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  byte local_1318;
  byte local_1317 [7];
  int local_1310;
  uint local_130c;
  uint local_1308;
  int local_1304;
  void *local_1300;
  void *local_12fc;
  undefined1 local_12f8;
  undefined3 uStack_12f7;
  float local_12f4;
  undefined4 local_12f0;
  undefined4 local_12ec;
  undefined4 local_12e8 [20];
  undefined4 local_1298 [121];
  undefined4 local_10b4;
  undefined4 local_10b0;
  undefined4 local_10ac;
  undefined4 local_10a8;
  undefined4 local_10a4;
  undefined2 local_10a0;
  undefined4 local_109c [5];
  undefined4 local_1088 [30];
  undefined4 local_1010;
  undefined4 local_100c;
  undefined1 local_1008;
  undefined1 local_1007 [4];
  undefined1 local_1003;
  undefined1 local_1002 [4];
  undefined1 local_ffe;
  undefined1 local_ffd;
  uint local_ffc;
  undefined1 local_ff8;
  undefined4 local_ff7;
  undefined1 local_ff3;
  undefined4 local_ff2;
  undefined1 local_fee;
  int local_fed;
  byte local_fe9;
  undefined4 local_fe8 [1015];
  int local_c;
  
  local_c = DAT_00454928;
  iVar11 = (uint)param_1 * 0x23b4;
  local_1300 = (void *)(*(int *)((int)this + 0xd4) + iVar11);
  local_12fc = this;
  if ((*(int *)((int)local_1300 + 0x1460) == 0) || (*(int *)((int)local_1300 + 0x14a4) == 0)) {
    uVar9 = 0xe2;
  }
  else if (*(char *)((int)local_1300 + 0x1440) == '\x02') {
    local_12f4 = (float)CONCAT31(local_12f4._1_3_,*param_3);
    _local_12f8 = CONCAT31(uStack_12f7,param_3[1]);
    bVar1 = param_3[2];
    local_1317[3] = 0;
    local_1317[4] = 0;
    local_1317[5] = 0;
    local_1310 = CONCAT31(local_1310._1_3_,bVar1);
    local_130c = 3;
    if (bVar1 < 4) {
      if (bVar1 != 0) {
        local_1308 = (uint)bVar1;
        pbVar7 = local_1317 + 3;
        do {
          *pbVar7 = param_3[local_130c & 0xffff];
          local_130c = local_130c + 1;
          pbVar7 = pbVar7 + 1;
          local_1308 = local_1308 - 1;
        } while (local_1308 != 0);
        local_1308 = 0;
      }
      local_1304 = *(int *)((int)local_1300 + 0x14a4);
      local_1318 = 0;
      local_1317[0] = 0;
      local_1317[2] = '\0';
      FUN_0040ca50(local_1300,&local_1318,(int)local_12e8,(int)local_109c,local_1317,(int)local_1298
                   ,(int)local_1088,(char *)(local_1317 + 2),(undefined2 *)&local_10b4);
      local_1317[1] = 0;
      uVar5 = FUN_0040c310((void *)(*(int *)((int)this + 0xd4) + iVar11),local_12f4,
                           (byte)_local_12f8,(byte)local_1310,local_1317 + 3,
                           (char *)(local_1317 + 1),&local_1300,&local_1308,&local_130c,&local_12ec,
                           &local_12f0);
      local_1317[1] = 0;
      if ((char)uVar5 == '\0') {
        iVar3 = *(int *)((int)this + 0xd4);
        iVar8 = iVar3 + iVar11;
        local_1010._0_2_ = *(undefined2 *)(iVar3 + 0x1488 + iVar11);
        local_100c = *(undefined4 *)(iVar3 + 0x1460 + iVar11);
        local_1007 = (undefined1  [4])local_1300;
        local_1008 = local_12f4._0_1_;
        local_1002 = (undefined1  [4])local_1308;
        local_1003 = local_12f8;
        local_ffd = local_1317[3];
        local_ffe = (undefined1)local_1310;
        local_ff8 = local_1317[4];
        local_ffc = local_130c;
        local_ff3 = local_1317[5];
        local_ff7 = local_12ec;
        local_fed = local_1304;
        local_ff2 = local_12f0;
        local_1010._2_2_ = 0x28;
        local_fee = 0;
        local_fe9 = local_1318;
        uVar5 = 0x28;
        if (local_1318 != 0) {
          uVar9 = (ushort)local_1318;
          local_1304 = CONCAT22(local_1304._2_2_,uVar9);
          uVar6 = (uint)uVar9;
          puVar10 = local_12e8;
          puVar12 = local_fe8;
          for (uVar5 = uVar6; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          for (iVar11 = 0; iVar11 != 0; iVar11 = iVar11 + -1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          puVar10 = local_109c;
          puVar12 = local_fe8 + uVar6;
          for (uVar5 = (uint)(local_1318 >> 2); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          for (uVar5 = uVar9 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          uVar5 = uVar6 * 4 + 0x28 + local_1304;
          this = local_12fc;
        }
        uVar6 = uVar5 + 1;
        *(byte *)((int)&local_1010 + (uVar5 & 0xffff)) = local_1317[0];
        if (local_1317[0] != 0) {
          uVar9 = (ushort)local_1317[0];
          local_1310 = CONCAT22(local_1310._2_2_,uVar9);
          puVar10 = local_1298;
          puVar12 = (undefined4 *)((int)&local_1010 + (uVar6 & 0xffff));
          for (uVar5 = (uint)uVar9; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          for (iVar11 = 0; iVar11 != 0; iVar11 = iVar11 + -1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          uVar6 = uVar6 + local_1310 * 4;
          puVar10 = local_1088;
          puVar12 = (undefined4 *)((int)&local_1010 + (uVar6 & 0xffff));
          for (uVar5 = (uint)(local_1317[0] >> 2); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          for (uVar5 = uVar9 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          uVar6 = uVar6 + local_1310;
          this = local_12fc;
        }
        uVar9 = (ushort)(uVar6 + 1);
        *(byte *)((int)&local_1010 + (uVar6 & 0xffff)) = local_1317[2];
        if (local_1317[2] != '\0') {
          uVar4 = *(undefined4 *)(iVar8 + 0x1460);
          uVar2 = *(undefined2 *)(iVar8 + 0x2370);
          *(undefined4 *)((int)&local_1010 + (uVar6 + 1 & 0xffff)) = *(undefined4 *)(iVar8 + 0x14a4)
          ;
          uVar5 = uVar6 + 5 & 0xffff;
          *(undefined4 *)((int)&local_1010 + uVar5) = local_10b4;
          *(undefined4 *)((int)&local_100c + uVar5) = local_10b0;
          *(undefined4 *)(&local_1008 + uVar5) = local_10ac;
          *(undefined4 *)(local_1007 + uVar5 + 3) = local_10a8;
          *(undefined4 *)(local_1002 + uVar5 + 2) = local_10a4;
          *(undefined2 *)((int)&local_ffc + uVar5) = local_10a0;
          *(undefined4 *)((int)&local_1010 + (uVar6 + 0x1b & 0xffff)) = uVar4;
          *(undefined2 *)((int)&local_1010 + (uVar6 + 0x1f & 0xffff)) = uVar2;
          uVar9 = (short)uVar6 + 0x21;
        }
        FUN_0041b940(this,param_1,uVar9,&local_1010);
        FUN_00435e83(local_c);
        return;
      }
      local_1010._0_2_ = 0x74;
      local_1010._2_2_ = CONCAT11(local_1010._3_1_,(char)uVar5);
      FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,&local_1010);
      FUN_00435e83(local_c);
      return;
    }
    uVar9 = 0xe4;
  }
  else {
    uVar9 = 0xe3;
  }
  FUN_0041eb20(this,param_1,uVar9,'\x01',1);
  FUN_00435e83(local_c);
  return;
}
