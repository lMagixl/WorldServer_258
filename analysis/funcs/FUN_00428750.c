
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00428750(void *this,ushort param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  void *this_00;
  ushort uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  byte local_12f3;
  byte local_12f2;
  char local_12f1;
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
  undefined4 local_100c [2];
  undefined2 local_1004;
  undefined1 local_1002 [4];
  byte local_ffe;
  undefined4 local_ffd;
  int local_c;
  
  local_c = DAT_00454928;
  iVar7 = (uint)param_1 * 0x23b4;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + iVar7);
  local_12ec = this;
  if ((*(int *)((int)this_00 + 0x1460) != 0) &&
     (local_12f0 = *(int *)((int)this_00 + 0x14a4), local_12f0 != 0)) {
    uVar3 = *param_3;
    uVar2 = *(undefined2 *)(param_3 + 1);
    local_12f2 = 0;
    local_12f3 = 0;
    local_12f1 = '\0';
    FUN_0040ca50(this_00,&local_12f2,(int)local_12e8,(int)local_109c,&local_12f3,(int)local_1298,
                 (int)local_1088,&local_12f1,(undefined2 *)&local_10b4);
    iVar1 = *(int *)((int)local_12ec + 0xd4) + iVar7;
    local_100c[0] = *(undefined4 *)(iVar1 + 0x1460);
    local_1010._0_2_ = *(undefined2 *)(*(int *)((int)local_12ec + 0xd4) + 0x1488 + iVar7);
    local_1002 = (undefined1  [4])local_12f0;
    local_1010._2_2_ = 0x1f;
    local_100c[1] = uVar3;
    local_1004 = uVar2;
    local_ffe = local_12f2;
    uVar4 = 0x13;
    if (local_12f2 != 0) {
      uVar6 = (ushort)local_12f2;
      local_12f0 = CONCAT22(local_12f0._2_2_,uVar6);
      uVar5 = (uint)uVar6;
      puVar8 = local_12e8;
      puVar9 = &local_ffd;
      for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      puVar8 = local_109c;
      puVar9 = &local_ffd + uVar5;
      for (uVar4 = (uint)(local_12f2 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar4 = uVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      uVar4 = uVar5 * 4 + 0x13 + local_12f0;
    }
    uVar5 = uVar4 + 1;
    *(byte *)((int)&local_1010 + (uVar4 & 0xffff)) = local_12f3;
    if (local_12f3 != 0) {
      uVar6 = (ushort)local_12f3;
      local_12f0 = CONCAT22(local_12f0._2_2_,uVar6);
      puVar8 = local_1298;
      puVar9 = (undefined4 *)((int)&local_1010 + (uVar5 & 0xffff));
      for (uVar4 = (uint)uVar6; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      uVar5 = uVar5 + local_12f0 * 4;
      puVar8 = local_1088;
      puVar9 = (undefined4 *)((int)&local_1010 + (uVar5 & 0xffff));
      for (uVar4 = (uint)(local_12f3 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar4 = uVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      uVar5 = uVar5 + local_12f0;
    }
    uVar6 = (ushort)(uVar5 + 1);
    *(char *)((int)&local_1010 + (uVar5 & 0xffff)) = local_12f1;
    if (local_12f1 != '\0') {
      uVar3 = *(undefined4 *)(iVar1 + 0x1460);
      uVar2 = *(undefined2 *)(iVar1 + 0x2370);
      *(undefined4 *)((int)&local_1010 + (uVar5 + 1 & 0xffff)) = *(undefined4 *)(iVar1 + 0x14a4);
      uVar4 = uVar5 + 5 & 0xffff;
      *(undefined4 *)((int)&local_1010 + uVar4) = local_10b4;
      *(undefined4 *)((int)local_100c + uVar4) = local_10b0;
      *(undefined4 *)((int)local_100c + uVar4 + 4) = local_10ac;
      *(undefined4 *)((int)&local_1004 + uVar4) = local_10a8;
      *(undefined4 *)(local_1002 + uVar4 + 2) = local_10a4;
      *(undefined2 *)((int)&local_ffd + uVar4 + 1) = local_10a0;
      *(undefined4 *)((int)&local_1010 + (uVar5 + 0x1b & 0xffff)) = uVar3;
      *(undefined2 *)((int)&local_1010 + (uVar5 + 0x1f & 0xffff)) = uVar2;
      uVar6 = (short)uVar5 + 0x21;
    }
    FUN_0041b940(local_12ec,param_1,uVar6,&local_1010);
    FUN_00435e83(local_c);
    return;
  }
  FUN_0041eb20(this,param_1,0xc3,'\x01',1);
  FUN_00435e83(local_c);
  return;
}
