
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_004215a0(void *this,ushort param_1,undefined4 param_2,byte *param_3)

{
  void *this_00;
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  byte local_12ea;
  byte local_12e9;
  int local_12e8;
  byte local_12e1;
  ushort local_12e0 [2];
  undefined4 local_12dc;
  undefined4 local_12d8;
  undefined4 local_12d4;
  undefined4 local_12d0 [20];
  undefined4 local_1280 [121];
  undefined4 local_109c [5];
  undefined4 local_1088 [30];
  undefined4 local_1010;
  undefined4 local_100c;
  undefined4 local_1008;
  ushort local_1004;
  undefined4 local_1002;
  undefined1 local_ffe;
  undefined4 local_ffd;
  byte local_ff9;
  byte local_ff8;
  undefined4 local_ff7;
  undefined4 local_ff3 [1017];
  int local_c;
  
  iVar6 = (uint)param_1 * 0x23b4;
  local_c = DAT_00454928;
  this_00 = (void *)(iVar6 + *(int *)((int)this + 0xd4));
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    uVar5 = 0x39;
  }
  else if (*(char *)((int)this_00 + 0x1440) == '\x02') {
    bVar2 = *param_3;
    local_12e8 = CONCAT31(local_12e8._1_3_,bVar2);
    if (bVar2 < 0x78) {
      local_12ea = 0;
      local_12dc = 0;
      uVar3 = FUN_0040cd70(this_00,bVar2,local_12e0,&local_12d8,&local_12ea,&local_12dc,&local_12d4,
                           &local_12e1,(int)local_12d0,(int)local_109c,&local_12e9,(int)local_1280,
                           (int)local_1088);
      if ((char)uVar3 != '\0') {
        local_1010._2_2_ = CONCAT11(local_1010._3_1_,(char)uVar3);
        local_1010._0_2_ = 0x2f;
        FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,&local_1010);
        FUN_00435e83(local_c);
        return;
      }
      iVar1 = iVar6 + *(int *)((int)this + 0xd4);
      local_100c = *(undefined4 *)(iVar1 + 0x1460);
      local_1010._0_2_ = *(undefined2 *)(iVar1 + 0x1488);
      local_1004 = local_12e0[0];
      local_1008 = *(undefined4 *)(iVar6 + 0x14a4 + *(int *)((int)this + 0xd4));
      local_ffe = (undefined1)local_12e8;
      local_ffd = local_12d4;
      local_1002 = local_12d8;
      local_ff7 = local_12dc;
      local_1010._2_2_ = 0x15;
      local_ff9 = local_12e1;
      local_ff8 = local_12ea;
      uVar3 = 0x1d;
      if (local_12e1 != 0) {
        uVar5 = (ushort)local_12e1;
        local_12e8 = CONCAT22(local_12e8._2_2_,uVar5);
        uVar4 = (uint)uVar5;
        puVar7 = local_12d0;
        puVar8 = local_ff3;
        for (uVar3 = uVar4; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        puVar7 = local_109c;
        puVar8 = local_ff3 + uVar4;
        for (uVar3 = (uint)(local_12e1 >> 2); uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        for (uVar3 = uVar5 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        uVar3 = uVar4 * 4 + 0x1d + local_12e8;
      }
      uVar4 = uVar3 + 1;
      uVar5 = (ushort)uVar4;
      *(byte *)((int)&local_1010 + (uVar3 & 0xffff)) = local_12e9;
      if (local_12e9 != 0) {
        uVar5 = (ushort)local_12e9;
        local_12e8 = CONCAT22(local_12e8._2_2_,uVar5);
        puVar7 = local_1280;
        puVar8 = (undefined4 *)((int)&local_1010 + (uVar4 & 0xffff));
        for (uVar3 = (uint)uVar5; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        uVar4 = uVar4 + local_12e8 * 4;
        puVar7 = local_1088;
        puVar8 = (undefined4 *)((int)&local_1010 + (uVar4 & 0xffff));
        for (uVar3 = (uint)(local_12e9 >> 2); uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        for (uVar3 = uVar5 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        uVar5 = (short)uVar4 + uVar5;
      }
      FUN_0041b940(this,param_1,uVar5,&local_1010);
      FUN_00435e83(local_c);
      return;
    }
    uVar5 = 0x3b;
  }
  else {
    uVar5 = 0x3a;
  }
  FUN_0041eb20(this,param_1,uVar5,'\x01',1);
  FUN_00435e83(local_c);
  return;
}
