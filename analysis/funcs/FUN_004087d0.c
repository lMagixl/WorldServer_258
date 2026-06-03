
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_004087d0(void *this,byte param_1,char param_2,byte param_3)

{
  uint uVar1;
  void *pvVar2;
  char *pcVar3;
  DWORD DVar4;
  char cVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  ushort *puVar9;
  ushort uVar10;
  ushort uVar11;
  undefined4 *puVar12;
  int local_2008;
  undefined2 local_2004;
  byte local_2002;
  char local_2001;
  byte local_2000;
  byte local_1fff;
  byte local_1ffe;
  undefined2 uStack_1004;
  undefined1 uStack_1002;
  undefined1 uStack_1001;
  undefined1 uStack_1000;
  undefined1 uStack_fff;
  int local_4;
  
  local_4 = DAT_00454928;
  if ((*(char *)((int)this + 8) == '\x02') && (*(char *)((int)this + 0x2b4) == '\x01')) {
    uVar8 = (uint)param_1;
    if ((*(char *)((int)this + uVar8 * 0x14 + 0x126) == '\x04') &&
       (*(int *)((int)this + uVar8 * 0x14 + 0x128) != 1)) {
      local_2002 = param_1;
      local_2004 = 0x4f;
      local_2001 = param_2;
      local_2000 = param_3;
      FUN_0042f280(s__RW____CField__GameDiePlayer___m_00447640);
      FUN_0042f280(s__RW____CField__GameDiePlayer___b_00447614);
      switch(*(undefined1 *)((int)this + 0x119)) {
      case 0:
      case 1:
        local_1fff = param_3;
        local_1ffe = param_3;
        *(undefined4 *)((int)this + uVar8 * 0x14 + 0x128) = 1;
        puVar7 = (ushort *)((int)this + 0x124);
        iVar6 = 0x14;
        do {
          if ((char)puVar7[1] == '\x04') {
            uVar10 = *puVar7;
            puVar12 = (undefined4 *)&local_2004;
            uVar11 = 7;
            pvVar2 = (void *)FUN_0042aad0();
            FUN_0041b8a0(pvVar2,uVar10,uVar11,puVar12);
          }
          puVar7 = puVar7 + 10;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        FUN_004063a0((int)this);
        break;
      case 2:
        uVar1 = (uint)param_3;
        if (*(char *)((int)this + uVar1 * 0x14 + 0x126) == '\x04') {
          if (param_2 == '\x01') {
            iVar6 = uVar8 * 5 + 0x4b;
            cVar5 = *(char *)((int)this + iVar6 * 4);
            if (cVar5 != '\0') {
              *(char *)((int)this + iVar6 * 4) = cVar5 + -1;
            }
          }
          else {
            if (param_2 == '\b') {
              iVar6 = uVar1 * 5 + 0x4b;
              pcVar3 = (char *)((int)this + iVar6 * 4);
              cVar5 = *(char *)((int)this + iVar6 * 4) + '\x02';
            }
            else {
              pcVar3 = (char *)((int)this + (uVar1 * 5 + 0x4b) * 4);
              cVar5 = *pcVar3 + '\x01';
            }
            *pcVar3 = cVar5;
          }
          local_1fff = *(byte *)((int)this + (uVar8 * 5 + 0x4b) * 4);
          iVar6 = uVar1 * 5 + 0x4b;
          local_1ffe = *(byte *)((int)this + iVar6 * 4);
          puVar7 = (ushort *)((int)this + 0x124);
          local_2008 = 0x14;
          puVar9 = puVar7;
          do {
            if ((char)puVar9[1] == '\x04') {
              uVar10 = *puVar9;
              puVar12 = (undefined4 *)&local_2004;
              uVar11 = 7;
              pvVar2 = (void *)FUN_0042aad0();
              FUN_0041b8a0(pvVar2,uVar10,uVar11,puVar12);
            }
            puVar9 = puVar9 + 10;
            local_2008 = local_2008 + -1;
          } while (local_2008 != 0);
          if (*(byte *)((int)this + 0x11e) <= *(byte *)((int)this + iVar6 * 4)) {
            *(undefined1 *)((int)this + 0x2bd) = 1;
            *(undefined1 *)((int)this + 0x2b4) = 2;
            DVar4 = GetTickCount();
            uStack_1002 = *(undefined1 *)((int)this + 0x2bd);
            uStack_1000 = *(undefined1 *)((int)this + 0x2c0);
            *(DWORD *)((int)this + 0x2b8) = DVar4 + 15000;
            uStack_1001 = *(undefined1 *)((int)this + 0x2bf);
            uStack_fff = *(undefined1 *)((int)this + 0x2c1);
            uStack_1004 = 0x4a;
            iVar6 = 0x14;
            do {
              if ((char)puVar7[1] == '\x04') {
                uVar10 = *puVar7;
                puVar12 = (undefined4 *)&uStack_1004;
                uVar11 = 6;
                pvVar2 = (void *)FUN_0042aad0();
                FUN_0041b8a0(pvVar2,uVar10,uVar11,puVar12);
              }
              puVar7 = puVar7 + 10;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
        }
        break;
      case 3:
        FUN_0042aad0();
        puVar7 = (ushort *)((int)this + 0x124);
        if (param_2 == '\x01') {
          iVar6 = 0x14;
          if (param_1 < 10) {
            local_1fff = *(byte *)((int)this + 0x11f);
            local_1ffe = *(char *)((int)this + 0x120) + 1;
            *(byte *)((int)this + 0x120) = local_1ffe;
            puVar9 = puVar7;
            do {
              if ((char)puVar9[1] == '\x04') {
                uVar10 = *puVar9;
                puVar12 = (undefined4 *)&local_2004;
                uVar11 = 7;
                pvVar2 = (void *)FUN_0042aad0();
                FUN_0041b8a0(pvVar2,uVar10,uVar11,puVar12);
              }
              puVar9 = puVar9 + 10;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            if (*(byte *)((int)this + 0x120) < *(byte *)((int)this + 0x11e)) break;
            *(char *)((int)this + 0x2c1) = *(char *)((int)this + 0x2c1) + '\x01';
            *(undefined1 *)((int)this + 0x2bf) = 0;
            pcVar3 = (char *)((int)this + 0x12e);
            iVar6 = 10;
            do {
              if (pcVar3[-8] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            pcVar3 = (char *)((int)this + 0x1f5);
            iVar6 = 10;
            do {
              if (pcVar3[-7] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          else {
            local_1fff = *(char *)((int)this + 0x11f) + 1;
            *(byte *)((int)this + 0x11f) = local_1fff;
            local_1ffe = *(byte *)((int)this + 0x120);
            puVar9 = puVar7;
            do {
              if ((char)puVar9[1] == '\x04') {
                uVar10 = *puVar9;
                puVar12 = (undefined4 *)&local_2004;
                uVar11 = 7;
                pvVar2 = (void *)FUN_0042aad0();
                FUN_0041b8a0(pvVar2,uVar10,uVar11,puVar12);
              }
              puVar9 = puVar9 + 10;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            if (*(byte *)((int)this + 0x11f) < *(byte *)((int)this + 0x11e)) break;
            *(char *)((int)this + 0x2c0) = *(char *)((int)this + 0x2c0) + '\x01';
            *(undefined1 *)((int)this + 0x2bf) = 1;
            pcVar3 = (char *)((int)this + 0x12d);
            iVar6 = 10;
            do {
              if (pcVar3[-7] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            pcVar3 = (char *)((int)this + 0x1f6);
            iVar6 = 10;
            do {
              if (pcVar3[-8] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
        }
        else if (param_2 == '\b') {
          iVar6 = 0x14;
          if (param_1 < 10) {
            local_1fff = *(byte *)((int)this + 0x11f);
            local_1ffe = *(char *)((int)this + 0x120) + 2;
            *(byte *)((int)this + 0x120) = local_1ffe;
            iVar6 = 0x14;
            puVar9 = puVar7;
            do {
              if ((char)puVar9[1] == '\x04') {
                uVar10 = *puVar9;
                puVar12 = (undefined4 *)&local_2004;
                uVar11 = 7;
                pvVar2 = (void *)FUN_0042aad0();
                FUN_0041b8a0(pvVar2,uVar10,uVar11,puVar12);
              }
              puVar9 = puVar9 + 10;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            if (*(byte *)((int)this + 0x120) < *(byte *)((int)this + 0x11e)) break;
            *(char *)((int)this + 0x2c1) = *(char *)((int)this + 0x2c1) + '\x01';
            *(undefined1 *)((int)this + 0x2bf) = 0;
            pcVar3 = (char *)((int)this + 0x12e);
            iVar6 = 10;
            do {
              if (pcVar3[-8] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            pcVar3 = (char *)((int)this + 0x1f5);
            iVar6 = 10;
            do {
              if (pcVar3[-7] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          else {
            local_1ffe = *(byte *)((int)this + 0x120);
            local_1fff = *(char *)((int)this + 0x11f) + 2;
            *(byte *)((int)this + 0x11f) = local_1fff;
            puVar9 = puVar7;
            do {
              if ((char)puVar9[1] == '\x04') {
                uVar10 = *puVar9;
                puVar12 = (undefined4 *)&local_2004;
                uVar11 = 7;
                pvVar2 = (void *)FUN_0042aad0();
                FUN_0041b8a0(pvVar2,uVar10,uVar11,puVar12);
              }
              puVar9 = puVar9 + 10;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            if (*(byte *)((int)this + 0x11f) < *(byte *)((int)this + 0x11e)) break;
            *(char *)((int)this + 0x2c0) = *(char *)((int)this + 0x2c0) + '\x01';
            *(undefined1 *)((int)this + 0x2bf) = 1;
            pcVar3 = (char *)((int)this + 0x12d);
            iVar6 = 10;
            do {
              if (pcVar3[-7] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            pcVar3 = (char *)((int)this + 0x1f6);
            iVar6 = 10;
            do {
              if (pcVar3[-8] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
        }
        else {
          iVar6 = 0x14;
          if (param_3 < 10) {
            local_1fff = *(char *)((int)this + 0x11f) + 1;
            *(byte *)((int)this + 0x11f) = local_1fff;
            local_1ffe = *(byte *)((int)this + 0x120);
            puVar9 = puVar7;
            do {
              if ((char)puVar9[1] == '\x04') {
                uVar10 = *puVar9;
                puVar12 = (undefined4 *)&local_2004;
                uVar11 = 7;
                pvVar2 = (void *)FUN_0042aad0();
                FUN_0041b8a0(pvVar2,uVar10,uVar11,puVar12);
              }
              puVar9 = puVar9 + 10;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            if (*(byte *)((int)this + 0x11f) < *(byte *)((int)this + 0x11e)) break;
            *(char *)((int)this + 0x2c0) = *(char *)((int)this + 0x2c0) + '\x01';
            *(undefined1 *)((int)this + 0x2bf) = 1;
            pcVar3 = (char *)((int)this + 0x12d);
            iVar6 = 10;
            do {
              if (pcVar3[-7] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            pcVar3 = (char *)((int)this + 0x1f6);
            iVar6 = 10;
            do {
              if (pcVar3[-8] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          else {
            local_1fff = *(byte *)((int)this + 0x11f);
            local_1ffe = *(char *)((int)this + 0x120) + 1;
            *(byte *)((int)this + 0x120) = local_1ffe;
            puVar9 = puVar7;
            do {
              if ((char)puVar9[1] == '\x04') {
                uVar10 = *puVar9;
                puVar12 = (undefined4 *)&local_2004;
                uVar11 = 7;
                pvVar2 = (void *)FUN_0042aad0();
                FUN_0041b8a0(pvVar2,uVar10,uVar11,puVar12);
              }
              puVar9 = puVar9 + 10;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            if (*(byte *)((int)this + 0x120) < *(byte *)((int)this + 0x11e)) break;
            *(char *)((int)this + 0x2c1) = *(char *)((int)this + 0x2c1) + '\x01';
            *(undefined1 *)((int)this + 0x2bf) = 0;
            pcVar3 = (char *)((int)this + 0x12e);
            iVar6 = 10;
            do {
              if (pcVar3[-8] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            pcVar3 = (char *)((int)this + 0x1f5);
            iVar6 = 10;
            do {
              if (pcVar3[-7] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
        }
        *(undefined1 *)((int)this + 0x2bd) = 1;
        *(undefined1 *)((int)this + 0x2b4) = 2;
        DVar4 = GetTickCount();
        uStack_1002 = *(undefined1 *)((int)this + 0x2bd);
        uStack_1000 = *(undefined1 *)((int)this + 0x2c0);
        *(DWORD *)((int)this + 0x2b8) = DVar4 + 15000;
        uStack_1001 = *(undefined1 *)((int)this + 0x2bf);
        uStack_fff = *(undefined1 *)((int)this + 0x2c1);
        uStack_1004 = 0x4a;
        iVar6 = 0x14;
        do {
          if ((char)puVar7[1] == '\x04') {
            uVar10 = *puVar7;
            puVar12 = (undefined4 *)&uStack_1004;
            uVar11 = 6;
            pvVar2 = (void *)FUN_0042aad0();
            FUN_0041b8a0(pvVar2,uVar10,uVar11,puVar12);
          }
          puVar7 = puVar7 + 10;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        break;
      case 4:
        local_1fff = *(byte *)((int)this + (uVar8 * 5 + 0x4b) * 4);
        local_1ffe = *(byte *)((int)this + (param_3 + 0xf) * 0x14);
        puVar7 = (ushort *)((int)this + 0x124);
        iVar6 = 0x14;
        puVar9 = puVar7;
        do {
          if ((char)puVar9[1] == '\x04') {
            uVar10 = *puVar9;
            puVar12 = (undefined4 *)&local_2004;
            uVar11 = 7;
            pvVar2 = (void *)FUN_0042aad0();
            FUN_0041b8a0(pvVar2,uVar10,uVar11,puVar12);
          }
          puVar9 = puVar9 + 10;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        iVar6 = FUN_00405400(this,param_1);
        if (iVar6 != 0) {
          iVar6 = 10;
          if (param_1 < 10) {
            *(char *)((int)this + 0x2c1) = *(char *)((int)this + 0x2c1) + '\x01';
            *(undefined1 *)((int)this + 0x2bf) = 0;
            pcVar3 = (char *)((int)this + 0x12e);
            do {
              if (pcVar3[-8] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            pcVar3 = (char *)((int)this + 0x1f5);
            iVar6 = 10;
            do {
              if (pcVar3[-7] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          else {
            *(char *)((int)this + 0x2c0) = *(char *)((int)this + 0x2c0) + '\x01';
            *(undefined1 *)((int)this + 0x2bf) = 1;
            pcVar3 = (char *)((int)this + 0x12d);
            do {
              if (pcVar3[-7] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            pcVar3 = (char *)((int)this + 0x1f6);
            iVar6 = 10;
            do {
              if (pcVar3[-8] == '\x04') {
                *pcVar3 = *pcVar3 + '\x01';
              }
              pcVar3 = pcVar3 + 0x14;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          *(undefined1 *)((int)this + 0x2bd) = 1;
          *(undefined1 *)((int)this + 0x2b4) = 2;
          DVar4 = GetTickCount();
          uStack_1002 = *(undefined1 *)((int)this + 0x2bd);
          uStack_1000 = *(undefined1 *)((int)this + 0x2c0);
          *(DWORD *)((int)this + 0x2b8) = DVar4 + 15000;
          uStack_1001 = *(undefined1 *)((int)this + 0x2bf);
          uStack_fff = *(undefined1 *)((int)this + 0x2c1);
          uStack_1004 = 0x4a;
          iVar6 = 0x14;
          do {
            if ((char)puVar7[1] == '\x04') {
              uVar10 = *puVar7;
              puVar12 = (undefined4 *)&uStack_1004;
              uVar11 = 6;
              pvVar2 = (void *)FUN_0042aad0();
              FUN_0041b8a0(pvVar2,uVar10,uVar11,puVar12);
            }
            puVar7 = puVar7 + 10;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
    }
  }
  FUN_00435e83(local_4);
  return;
}



/* METADATA: sig=undefined __thiscall FUN_004087d0(void * this, byte param_1, char param_2, byte param_3) xrefs=00424b31 callees=FUN_0042f280 FUN_00405400 FUN_00435e83 __chkstk FUN_004063a0 GetTickCount FUN_0041b8a0 FUN_0042aad0 */
