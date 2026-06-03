
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00421210(void *this,ushort param_1,undefined4 param_2,ushort *param_3)

{
  void *this_00;
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  int iVar7;
  byte *pbVar8;
  ushort *puVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  byte local_12f7;
  byte local_12f6;
  byte local_12f5;
  int local_12f4;
  uint local_12f0;
  void *local_12ec;
  char local_12e8;
  undefined3 uStack_12e7;
  uint local_12e4;
  undefined4 local_12e0;
  uint local_12dc;
  uint local_12d8;
  byte local_12d4 [8];
  ushort local_12cc [8];
  undefined4 local_12bc [5];
  undefined4 local_12a8 [19];
  undefined4 local_125c [30];
  undefined1 local_11e4 [2];
  undefined2 local_11e2;
  undefined4 local_11e0;
  undefined4 local_11dc;
  undefined1 local_11d8;
  int local_11d7;
  char local_11d3;
  undefined4 local_11d2;
  uint local_11ce;
  uint local_11ca;
  undefined2 local_11c6;
  undefined4 local_1e4 [120];
  int local_4;
  
  iVar7 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  this_00 = (void *)(iVar7 + *(int *)((int)this + 0xd4));
  local_12ec = this;
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    FUN_0041eb20(this,param_1,0x36,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(char *)((int)this_00 + 0x1440) == '\x02') {
    local_12f0 = 0;
    local_12e0 = 0;
    local_12dc = 0;
    local_12e4 = 0;
    uVar6 = *param_3;
    local_12d8 = (uint)uVar6;
    if (uVar6 < *(ushort *)((int)this + 0x108)) {
      cVar1 = *(char *)((int)param_3 + 3);
      _local_12e8 = CONCAT31(uStack_12e7,(char)param_3[1]);
      local_12f4 = CONCAT31(local_12f4._1_3_,cVar1);
      if (cVar1 == '\x01') {
        local_12f0 = (uint)param_3[2];
      }
      uVar2 = FUN_0040cb10(this_00,uVar6,(char)param_3[1],&local_12f4,&local_12f6,local_12d4,
                           local_12cc,&local_12f5,(int)local_12a8,(int)local_12bc,&local_12f7,
                           (int)local_1e4,(int)local_125c,cVar1,(ushort)local_12f0,&local_12e0,
                           &local_12e4,&local_12dc);
      if ((char)uVar2 == '\0') {
        iVar3 = *(int *)((int)this + 0xd4);
        local_11e0 = *(undefined4 *)(iVar3 + 0x1460 + iVar7);
        local_11dc = *(undefined4 *)(iVar3 + 0x14a4 + iVar7);
        local_11e4 = (undefined1  [2])*(undefined2 *)(iVar3 + iVar7 + 0x1488);
        local_11e2 = 0x14;
        local_11d8 = local_12e8;
        local_11d7 = local_12f4;
        local_11d3 = cVar1;
        iVar7 = 0x12;
        if (cVar1 == '\x01') {
          local_11d2 = local_12e0;
          local_11c6 = (undefined2)local_12f0;
          local_11ce = local_12e4;
          local_11ca = local_12dc;
          iVar7 = 0x20;
        }
        iVar3 = iVar7 + 1;
        local_11e4[iVar7] = local_12f6;
        if (local_12f6 != 0) {
          uVar6 = (ushort)local_12f6;
          pbVar8 = local_12d4;
          pbVar11 = local_11e4 + iVar7 + 1;
          for (uVar4 = (uint)(local_12f6 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined4 *)pbVar11 = *(undefined4 *)pbVar8;
            pbVar8 = pbVar8 + 4;
            pbVar11 = pbVar11 + 4;
          }
          for (uVar4 = uVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *pbVar11 = *pbVar8;
            pbVar8 = pbVar8 + 1;
            pbVar11 = pbVar11 + 1;
          }
          iVar3 = iVar3 + (uint)uVar6;
          uVar4 = (uint)uVar6 * 2;
          puVar9 = local_12cc;
          puVar10 = (undefined4 *)(local_11e4 + iVar3);
          for (uVar5 = (uint)(local_12f6 >> 1); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar10 = *(undefined4 *)puVar9;
            puVar9 = puVar9 + 2;
            puVar10 = puVar10 + 1;
          }
          iVar3 = iVar3 + uVar4;
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(char *)puVar10 = (char)*puVar9;
            puVar9 = (ushort *)((int)puVar9 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          this = local_12ec;
          if (1 < local_12f6) {
            *(undefined2 *)(local_11e4 + iVar3) = (undefined2)local_12d8;
            iVar3 = iVar3 + 2;
          }
        }
        iVar7 = iVar3 + 1;
        local_11e4[iVar3] = local_12f5;
        if (local_12f5 != 0) {
          uVar5 = (uint)local_12f5;
          puVar10 = local_12a8;
          puVar12 = (undefined4 *)(local_11e4 + iVar3 + 1);
          for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          iVar7 = iVar7 + uVar5 * 4;
          puVar10 = local_12bc;
          puVar12 = (undefined4 *)(local_11e4 + iVar7);
          for (uVar4 = (uint)(local_12f5 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          iVar7 = iVar7 + uVar5;
        }
        uVar6 = (ushort)(iVar7 + 1);
        local_11e4[iVar7] = local_12f7;
        if (local_12f7 != 0) {
          uVar5 = (uint)local_12f7;
          puVar10 = local_1e4;
          puVar12 = (undefined4 *)(local_11e4 + iVar7 + 1);
          for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          iVar7 = iVar7 + 1 + uVar5 * 4;
          puVar10 = local_125c;
          puVar12 = (undefined4 *)(local_11e4 + iVar7);
          for (uVar4 = (uint)(local_12f7 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          uVar6 = (short)iVar7 + (ushort)local_12f7;
        }
        FUN_0041b940(this,param_1,uVar6,(undefined4 *)local_11e4);
      }
      else {
        local_11e4 = (undefined1  [2])0x2e;
        local_11e2 = CONCAT11(local_11e2._1_1_,(char)uVar2);
        FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)local_11e4);
      }
      goto LAB_0042127c;
    }
  }
  FUN_0041eb20(this,param_1,0x37,'\x01',1);
LAB_0042127c:
  FUN_00435e83(local_4);
  return;
}
