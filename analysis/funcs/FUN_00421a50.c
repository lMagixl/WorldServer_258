
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00421a50(void *this,ushort param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  void *this_00;
  ushort uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  char local_1307;
  byte local_1306;
  byte local_1305;
  int local_1304;
  int local_1300;
  void *local_12fc;
  undefined4 local_12f8;
  int local_12f4;
  undefined4 local_12f0;
  byte local_12ec;
  undefined3 uStack_12eb;
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
  byte local_1008 [2];
  undefined1 local_1006 [4];
  undefined1 local_1002 [4];
  undefined4 local_ffe;
  int local_ffa;
  byte local_ff6;
  undefined4 local_ff5 [1018];
  int local_c;
  
  local_c = DAT_00454928;
  iVar9 = (uint)param_1 * 0x23b4;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + iVar9);
  local_12fc = this;
  if ((*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar9) == 0) ||
     (local_1300 = *(int *)((int)this_00 + 0x14a4), local_1300 == 0)) {
    uVar7 = 0xde;
  }
  else if (*(char *)((int)this_00 + 0x1440) == '\x02') {
    bVar2 = *param_3;
    _local_12ec = CONCAT31(uStack_12eb,bVar2);
    local_1304 = CONCAT31(local_1304._1_3_,param_3[1]);
    if (bVar2 < 0x78) {
      if (param_3[1] < 0x78) {
        local_1305 = 0;
        local_1306 = 0;
        local_1307 = '\0';
        FUN_0040ca50(this_00,&local_1305,(int)local_12e8,(int)local_109c,&local_1306,(int)local_1298
                     ,(int)local_1088,&local_1307,(undefined2 *)&local_10b4);
        local_12f0 = 0;
        local_12f8 = 0;
        local_12f4 = 0;
        uVar5 = FUN_0040c140((void *)(*(int *)((int)this + 0xd4) + iVar9),(byte)_local_12ec,
                             (byte)local_1304,&local_12f0,&local_12f8,&local_12f4);
        if ((char)uVar5 != '\0') {
          local_1010._0_2_ = 0x73;
          local_1010._2_2_ = CONCAT11(local_1010._3_1_,(char)uVar5);
          FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,&local_1010);
          FUN_00435e83(local_c);
          return;
        }
        iVar1 = iVar9 + *(int *)((int)this + 0xd4);
        local_100c = *(undefined4 *)(iVar1 + 0x1460);
        local_1010._0_2_ = *(undefined2 *)(iVar9 + 0x1488 + *(int *)((int)this + 0xd4));
        local_1008[1] = (undefined1)local_1304;
        local_1006 = (undefined1  [4])local_12f0;
        local_1002 = (undefined1  [4])local_12f8;
        local_ffe = local_12f4;
        local_ffa = local_1300;
        local_1010._2_2_ = 0x27;
        local_1008[0] = bVar2;
        local_ff6 = local_1305;
        uVar5 = 0x1b;
        if (local_1305 != 0) {
          uVar7 = (ushort)local_1305;
          local_1300 = CONCAT22(local_1300._2_2_,uVar7);
          uVar6 = (uint)uVar7;
          puVar8 = local_12e8;
          puVar10 = local_ff5;
          for (uVar5 = uVar6; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          puVar8 = local_109c;
          puVar10 = local_ff5 + uVar6;
          for (uVar5 = (uint)(local_1305 >> 2); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar5 = uVar7 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          uVar5 = uVar6 * 4 + 0x1b + local_1300;
          this = local_12fc;
        }
        uVar6 = uVar5 + 1;
        *(byte *)((int)&local_1010 + (uVar5 & 0xffff)) = local_1306;
        if (local_1306 != 0) {
          uVar7 = (ushort)local_1306;
          local_1304 = CONCAT22(local_1304._2_2_,uVar7);
          puVar8 = local_1298;
          puVar10 = (undefined4 *)((int)&local_1010 + (uVar6 & 0xffff));
          for (uVar5 = (uint)uVar7; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          uVar6 = uVar6 + local_1304 * 4;
          puVar8 = local_1088;
          puVar10 = (undefined4 *)((int)&local_1010 + (uVar6 & 0xffff));
          for (uVar5 = (uint)(local_1306 >> 2); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar5 = uVar7 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          uVar6 = uVar6 + local_1304;
          this = local_12fc;
        }
        uVar7 = (ushort)(uVar6 + 1);
        *(char *)((int)&local_1010 + (uVar6 & 0xffff)) = local_1307;
        if (local_1307 != '\0') {
          uVar4 = *(undefined4 *)(iVar1 + 0x1460);
          uVar3 = *(undefined2 *)(iVar1 + 0x2370);
          *(undefined4 *)((int)&local_1010 + (uVar6 + 1 & 0xffff)) = *(undefined4 *)(iVar1 + 0x14a4)
          ;
          uVar5 = uVar6 + 5 & 0xffff;
          *(undefined4 *)((int)&local_1010 + uVar5) = local_10b4;
          *(undefined4 *)((int)&local_100c + uVar5) = local_10b0;
          *(undefined4 *)(local_1008 + uVar5) = local_10ac;
          *(undefined4 *)(local_1006 + uVar5 + 2) = local_10a8;
          *(undefined4 *)(local_1002 + uVar5 + 2) = local_10a4;
          *(undefined2 *)((int)&local_ffe + uVar5 + 2) = local_10a0;
          *(undefined4 *)((int)&local_1010 + (uVar6 + 0x1b & 0xffff)) = uVar4;
          *(undefined2 *)((int)&local_1010 + (uVar6 + 0x1f & 0xffff)) = uVar3;
          uVar7 = (short)uVar6 + 0x21;
        }
        FUN_0041b940(this,param_1,uVar7,&local_1010);
        FUN_00435e83(local_c);
        return;
      }
      uVar7 = 0xe1;
    }
    else {
      uVar7 = 0xe0;
    }
  }
  else {
    uVar7 = 0xdf;
  }
  FUN_0041eb20(this,param_1,uVar7,'\x01',1);
  FUN_00435e83(local_c);
  return;
}


