
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00425010(void *this,uint param_1,undefined4 param_2,byte *param_3)

{
  void *this_00;
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  byte bVar5;
  ushort uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  ushort *puVar12;
  void *pvVar13;
  undefined4 *puVar14;
  byte local_30f6;
  byte local_30f5;
  ushort local_30f4 [2];
  undefined1 local_30f0 [4];
  uint local_30ec;
  undefined1 local_30e5;
  undefined2 local_30e4 [2];
  void *local_30e0;
  uint local_30dc;
  byte local_30d8;
  undefined3 uStack_30d7;
  byte local_30d4;
  undefined3 uStack_30d3;
  undefined4 local_30d0;
  undefined4 local_30cc;
  undefined4 local_30c8;
  undefined4 local_30c4;
  undefined4 local_30c0;
  undefined4 local_30bc;
  undefined4 local_30b8;
  undefined4 local_30b4;
  uint local_30b0;
  uint local_30ac;
  uint local_30a8;
  undefined4 local_30a4;
  undefined4 local_30a0;
  undefined4 local_309c;
  ushort local_3098 [4];
  CHAR local_3090 [128];
  undefined1 local_3010 [2];
  undefined2 local_300e;
  undefined1 local_300c [4];
  undefined4 local_3008;
  undefined4 local_3004;
  byte local_3000;
  undefined4 local_2fff;
  undefined4 local_2ffb;
  undefined4 local_2ff7;
  undefined4 local_2ff3;
  undefined2 local_2fef;
  undefined4 local_2fed;
  undefined4 local_2fe9;
  undefined4 local_2fe5;
  undefined2 local_2fe1;
  undefined1 local_2fdf;
  undefined4 local_2fde;
  undefined4 local_2fda;
  undefined4 local_2fd6;
  byte local_2fd2;
  undefined4 local_2fd1 [1008];
  undefined2 local_2010;
  byte local_200e;
  undefined2 local_200d;
  byte local_200b;
  undefined4 local_200a [1022];
  undefined2 local_1010;
  undefined1 local_100e;
  byte local_100d;
  undefined2 local_100c;
  undefined1 local_100a;
  int local_c;
  
  uVar9 = param_1;
  pvVar13 = (void *)((param_1 & 0xffff) * 0x23b4);
  local_c = DAT_00454928;
  this_00 = (void *)((int)pvVar13 + *(int *)((int)this + 0xd4));
  local_30e0 = pvVar13;
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    uVar6 = 0x98;
  }
  else if (*(char *)((int)this_00 + 0x1440) == '\x03') {
    FUN_0040b7d0(this_00,local_30f4,&local_30e5);
    iVar8 = (uint)local_30f4[0] * 0x3c0 + *(int *)((int)this + 0xe4);
    if (*(char *)(iVar8 + 0x119) == '\0') {
      if ((*(char *)(iVar8 + 8) == '\x02') && (*(char *)(iVar8 + 0x2b4) == '\x02')) {
        bVar5 = *param_3;
        _local_30d4 = CONCAT31(uStack_30d3,bVar5);
        if (bVar5 < 100) {
          bVar1 = param_3[1];
          _local_30d8 = CONCAT31(uStack_30d7,bVar1);
          if (bVar1 < 6) {
            bVar2 = param_3[2];
            if (bVar2 < 5) {
              uVar11 = 3;
              bVar4 = 0;
              local_30ec = 3;
              if (bVar2 != 0) {
                do {
                  uVar6 = *(ushort *)(param_3 + (uVar11 & 0xffff));
                  uVar3 = *(ushort *)((int)this + 0x108);
                  local_3098[bVar4] = uVar6;
                  if (uVar3 <= uVar6) {
                    uVar6 = 0x9f;
                    uVar9 = param_1;
                    local_30ec = uVar11;
                    goto LAB_004255fb;
                  }
                  uVar11 = uVar11 + 2;
                  bVar4 = bVar4 + 1;
                  local_30ec = uVar11;
                } while (bVar4 < bVar2);
              }
              uVar9 = local_30ec;
              uVar7 = FUN_0040bae0((void *)(*(int *)((int)this + 0xd4) + (int)pvVar13),bVar5,bVar1,
                                   &local_30bc,&local_30f5);
              bVar5 = (byte)uVar7;
              if (1 < bVar5) goto LAB_00425602;
              local_2010 = 0x53;
              local_200e = bVar5;
              if (bVar5 != 0) {
                FUN_004038e0(*(void **)((int)this + 0x118),(ushort)param_1,3,
                             (undefined4 *)&local_2010);
                FUN_00435e83(local_c);
                return;
              }
              local_200d = CONCAT11(local_30d8,local_30d4);
              uVar6 = 6;
              if (bVar2 != 0) {
                puVar12 = local_3098;
                puVar14 = local_200a;
                for (uVar9 = (uint)(bVar2 >> 1); uVar9 != 0; uVar9 = uVar9 - 1) {
                  *puVar14 = *(undefined4 *)puVar12;
                  puVar12 = puVar12 + 2;
                  puVar14 = puVar14 + 1;
                }
                for (uVar9 = (uint)bVar2 * 2 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                  *(char *)puVar14 = (char)*puVar12;
                  puVar12 = (ushort *)((int)puVar12 + 1);
                  puVar14 = (undefined4 *)((int)puVar14 + 1);
                }
                uVar6 = (short)((uint)bVar2 * 2) + 6;
                uVar9 = local_30ec;
                pvVar13 = local_30e0;
              }
              local_200b = bVar2;
              FUN_004038e0(*(void **)((int)this + 0x118),(ushort)param_1,uVar6,
                           (undefined4 *)&local_2010);
              local_30ec = *(uint *)(param_3 + (uVar9 & 0xffff));
              local_30dc = *(uint *)(param_3 + (uVar9 + 4 & 0xffff));
              local_30e0 = (void *)((int)pvVar13 + *(int *)((int)this + 0xd4));
              if (*(int *)((int)local_30e0 + 0x236c) != 0) {
                local_30ec = local_30ec * 3 >> 1;
              }
              iVar8 = FUN_0041cf80(this,&param_1,local_30f4,&local_30f5,&local_30ec,&local_30dc);
              if (iVar8 == 0) {
                local_30e0 = (void *)FUN_0040d300(local_30e0,local_30ec,(int *)&local_30dc,
                                                  &local_30f6,&local_30c4,local_30e4);
                if (local_30e0 != (void *)0x0) {
                  local_200e = local_30f6;
                  local_200d = local_30e4[0];
                  local_2010 = 0x51;
                  FUN_004038e0(*(void **)((int)this + 0x118),(ushort)param_1,5,
                               (undefined4 *)&local_2010);
                }
                puVar10 = (uint *)(param_3 + (uVar9 + 8 & 0xffff));
                local_30b0 = *puVar10;
                local_30ac = puVar10[1];
                local_30a8 = puVar10[2];
                local_30d0 = 0;
                local_30cc = 0;
                local_30c8 = 0;
                local_30f0._0_3_ = 0;
                iVar8 = FUN_0040b940((void *)(*(int *)((int)this + 0xd4) + (int)pvVar13),&local_30b0
                                     ,(int)&local_30d0,local_30f0,(int)&local_30a4);
                if (iVar8 != 0 || local_30e0 != (void *)0x0) {
                  local_100e = local_30e5;
                  local_100a = local_30f0[2];
                  local_100d = local_30f6;
                  local_100c = local_30f0._0_2_;
                  local_1010 = 0x52;
                  FUN_004061f0((void *)((uint)local_30f4[0] * 0x3c0 + *(int *)((int)this + 0xe4)),7,
                               (undefined4 *)&local_1010);
                }
                FUN_0040bb60((void *)(*(int *)((int)this + 0xd4) + (int)pvVar13),'\x03',&local_30b4,
                             &local_30b8,&local_30c0);
                iVar8 = *(int *)((int)this + 0xd4);
                local_300c = (undefined1  [4])*(undefined4 *)(iVar8 + 0x1460 + (int)pvVar13);
                local_3010 = (undefined1  [2])*(undefined2 *)((int)pvVar13 + iVar8 + 0x1488);
                local_3008 = local_30dc;
                local_3004 = *(undefined4 *)(iVar8 + 0x14a4 + (int)pvVar13);
                local_2fff = local_30c4;
                local_2ffb = local_30b4;
                local_3000 = local_30f6;
                local_2ff3 = local_30c0;
                local_2fef = local_30e4[0];
                local_2ff7 = local_30b8;
                local_2fe9 = local_30cc;
                local_2fe5 = local_30c8;
                local_2fed = local_30d0;
                local_2fdf = local_30f0[2];
                local_2fde = local_30a4;
                local_2fe1 = local_30f0._0_2_;
                local_2fd6 = local_309c;
                local_300e = 10;
                local_2fda = local_30a0;
                local_2fd2 = bVar2;
                iVar8 = 0x3f;
                if (bVar2 != 0) {
                  puVar12 = local_3098;
                  puVar14 = local_2fd1;
                  for (uVar9 = (uint)(bVar2 >> 1); uVar9 != 0; uVar9 = uVar9 - 1) {
                    *puVar14 = *(undefined4 *)puVar12;
                    puVar12 = puVar12 + 2;
                    puVar14 = puVar14 + 1;
                  }
                  for (uVar9 = (uint)bVar2 * 2 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                    *(char *)puVar14 = (char)*puVar12;
                    puVar12 = (ushort *)((int)puVar12 + 1);
                    puVar14 = (undefined4 *)((int)puVar14 + 1);
                  }
                  iVar8 = (uint)bVar2 * 2 + 0x3f;
                }
                uVar6 = (short)iVar8 + 1;
                local_3010[iVar8] = local_30d8;
                if (local_30d8 != '\0') {
                  *(undefined4 *)(local_3010 + iVar8 + 1) =
                       *(undefined4 *)((uint)local_30f4[0] * 0x3c0 + 4 + *(int *)((int)this + 0xe4))
                  ;
                  local_300c[iVar8 + 1] = local_30d4;
                  *(undefined4 *)(local_300c + iVar8 + 2) = local_30bc;
                  *(byte *)((int)&local_3008 + iVar8 + 2) = local_30f5;
                  uVar6 = (short)iVar8 + 0xb;
                }
                FUN_0041b940(this,(ushort)param_1,uVar6,(undefined4 *)local_3010);
                FUN_00435e83(local_c);
                return;
              }
              wsprintfA(local_3090,s_Wrong_Game_Point__Exp____u__Gold_0044c104,local_30ec,local_30dc
                       );
              FUN_0041d380(this,local_3090,
                           *(int *)((int)pvVar13 + *(int *)((int)this + 0xd4) + 0x1460));
              uVar6 = 0xa0;
              uVar9 = param_1;
            }
            else {
              uVar6 = 0x9e;
            }
          }
          else {
            uVar6 = 0x9d;
          }
        }
        else {
          uVar6 = 0x9c;
        }
      }
      else {
        uVar6 = 0x9b;
      }
    }
    else {
      uVar6 = 0x9a;
    }
  }
  else {
    uVar6 = 0x99;
  }
LAB_004255fb:
  FUN_0041eb20(this,(ushort)uVar9,uVar6,'\x01',1);
LAB_00425602:
  FUN_00435e83(local_c);
  return;
}
