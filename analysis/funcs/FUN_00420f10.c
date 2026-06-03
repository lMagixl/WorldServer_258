
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00420f10(void *this,ushort param_1)

{
  void *this_00;
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  char local_12f3;
  byte local_12f2;
  byte local_12f1;
  int local_12f0;
  void *local_12ec;
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
  byte local_1008;
  undefined1 local_1007 [7];
  undefined4 uStack_1000;
  undefined2 auStack_ffc [2040];
  int local_c;
  
  iVar7 = (uint)param_1 * 0x23b4;
  local_c = DAT_00454928;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + iVar7);
  local_12ec = this;
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    uVar6 = 0x34;
  }
  else {
    if (*(char *)((int)this_00 + 0x1440) == '\x02') {
      uVar3 = FUN_0040c960(this_00,&local_12f1,(int)local_12e8,(int)local_109c,&local_12f2,
                           (int)local_1298,(int)local_1088,&local_12f3,(undefined2 *)&local_10b4);
      if (((char)uVar3 == '\0') &&
         (((local_12f1 != 0 || (local_12f2 != 0)) || (local_12f3 != '\0')))) {
        iVar5 = *(int *)((int)this + 0xd4) + iVar7;
        local_100c = *(undefined4 *)(*(int *)((int)this + 0xd4) + 0x14a4 + iVar7);
        local_1010._0_2_ = *(undefined2 *)(iVar5 + 0x1488);
        local_1010._2_2_ = 0x13;
        local_1008 = local_12f1;
        uVar3 = 9;
        if (local_12f1 != 0) {
          uVar6 = (ushort)local_12f1;
          local_12f0 = CONCAT22(local_12f0._2_2_,uVar6);
          puVar8 = local_12e8;
          puVar9 = (undefined4 *)local_1007;
          for (uVar3 = (uint)uVar6; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
          iVar7 = (uint)uVar6 * 4;
          puVar8 = local_109c;
          puVar9 = (undefined4 *)(local_1007 + iVar7);
          for (uVar3 = (uint)(local_12f1 >> 2); uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          for (uVar3 = uVar6 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
          uVar3 = iVar7 + 9 + local_12f0;
          this = local_12ec;
        }
        uVar4 = uVar3 + 1;
        *(byte *)((int)&local_1010 + (uVar3 & 0xffff)) = local_12f2;
        if (local_12f2 != 0) {
          local_12f0 = CONCAT22(local_12f0._2_2_,(ushort)local_12f2);
          puVar8 = local_1298;
          puVar9 = (undefined4 *)((int)&local_1010 + (uVar4 & 0xffff));
          for (uVar3 = (uint)local_12f2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
          uVar4 = uVar4 + local_12f0 * 4;
          puVar8 = local_1088;
          puVar9 = (undefined4 *)((int)&local_1010 + (uVar4 & 0xffff));
          for (uVar3 = (uint)(local_12f2 >> 2); uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          for (uVar3 = (ushort)local_12f2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
          uVar4 = uVar4 + local_12f0;
          this = local_12ec;
        }
        uVar6 = (ushort)(uVar4 + 1);
        *(char *)((int)&local_1010 + (uVar4 & 0xffff)) = local_12f3;
        if (local_12f3 != '\0') {
          uVar2 = *(undefined4 *)(iVar5 + 0x1460);
          uVar1 = *(undefined2 *)(iVar5 + 0x2370);
          *(undefined4 *)((int)&local_1010 + (uVar4 + 1 & 0xffff)) = *(undefined4 *)(iVar5 + 0x14a4)
          ;
          uVar3 = uVar4 + 5 & 0xffff;
          *(undefined4 *)((int)&local_1010 + uVar3) = local_10b4;
          *(undefined4 *)((int)&local_100c + uVar3) = local_10b0;
          *(undefined4 *)(&local_1008 + uVar3) = local_10ac;
          *(undefined4 *)(local_1007 + uVar3 + 3) = local_10a8;
          *(undefined4 *)((int)&uStack_1000 + uVar3) = local_10a4;
          *(undefined2 *)((int)auStack_ffc + uVar3) = local_10a0;
          *(undefined4 *)((int)&local_1010 + (uVar4 + 0x1b & 0xffff)) = uVar2;
          *(undefined2 *)((int)&local_1010 + (uVar4 + 0x1f & 0xffff)) = uVar1;
          uVar6 = (short)uVar4 + 0x21;
        }
        FUN_0041b940(this,param_1,uVar6,&local_1010);
        FUN_00435e83(local_c);
        return;
      }
      local_1010._0_2_ = 0x2d;
      local_1010._2_2_ = CONCAT11(local_1010._3_1_,(char)uVar3);
      FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,&local_1010);
      FUN_00435e83(local_c);
      return;
    }
    uVar6 = 0x35;
  }
  FUN_0041eb20(this,param_1,uVar6,'\x01',1);
  FUN_00435e83(local_c);
  return;
}
