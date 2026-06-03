
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __fastcall FUN_00409940(void *param_1)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  DWORD DVar8;
  int iVar9;
  void *pvVar10;
  char *pcVar11;
  byte bVar12;
  int iVar13;
  ushort *puVar14;
  uint *puVar15;
  ushort uVar16;
  ushort uVar17;
  undefined4 *puVar18;
  byte bStack_100a;
  byte bStack_1009;
  undefined2 uStack_1004;
  undefined1 uStack_1002;
  undefined2 uStack_1001;
  undefined1 uStack_fff;
  undefined1 uStack_ffe;
  undefined1 uStack_ffd;
  undefined1 uStack_ffc;
  int local_4;
  
  local_4 = DAT_00454928;
  if (*(char *)((int)param_1 + 8) != '\x02') {
LAB_0040a3f3:
    FUN_00435e83(local_4);
    return;
  }
  if (((*(byte *)((int)param_1 + 0x121) != 0x14) &&
      (uVar5 = (uint)*(byte *)((int)param_1 + 0x121),
      *(char *)((int)param_1 + uVar5 * 0x14 + 0x126) != '\x03')) &&
     (*(char *)((int)param_1 + uVar5 * 0x14 + 0x127) != '\x01')) {
    uVar16 = *(ushort *)((int)param_1 + uVar5 * 0x14 + 0x124);
    iVar6 = FUN_0042aad0();
    iVar6 = *(int *)(iVar6 + 0xd4);
    uVar7 = FUN_0040bbe0((uint)uVar16 * 0x23b4 + iVar6);
    if ((char)uVar7 != '\0') {
      bVar12 = 0;
      do {
        if ((*(char *)((int)param_1 + (uint)bVar12 * 0x14 + 0x126) == '\x04') &&
           (uVar7 = FUN_0040bbe0((uint)*(ushort *)((int)param_1 + (uint)bVar12 * 0x14 + 0x124) *
                                 0x23b4 + iVar6), (char)uVar7 == '\0')) {
          FUN_00406350(param_1,bVar12);
          break;
        }
        bVar12 = bVar12 + 1;
      } while (bVar12 < 0x14);
    }
  }
  FUN_00409810(param_1);
  puVar15 = (uint *)((int)param_1 + 0x35c);
  iVar6 = 10;
  do {
    bVar3 = false;
    if ((*puVar15 != 0) && (DVar8 = GetTickCount(), *puVar15 < DVar8)) {
      puVar15[-1] = 0;
      *puVar15 = 0;
    }
    puVar15 = puVar15 + 2;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  cVar1 = *(char *)((int)param_1 + 0x2b4);
  if (cVar1 == '\0') {
    DVar8 = GetTickCount();
    if (*(uint *)((int)param_1 + 0x2b8) <= DVar8) {
      if ((*(char *)((int)param_1 + (uint)*(byte *)((int)param_1 + 0x121) * 0x14 + 0x126) == '\x03')
         && (*(char *)((int)param_1 + (uint)*(byte *)((int)param_1 + 0x121) * 0x14 + 0x127) !=
             '\x01')) {
        bVar12 = 0;
        do {
          if (*(char *)((int)param_1 + (uint)bVar12 * 0x14 + 0x126) == '\x04') {
            FUN_00406350(param_1,bVar12);
            break;
          }
          bVar12 = bVar12 + 1;
        } while (bVar12 < 0x14);
      }
      else {
        bVar12 = 0x14;
      }
      if (*(char *)((int)param_1 + 0x119) == '\0') {
        bVar12 = 0;
        pcVar11 = (char *)((int)param_1 + 0x126);
        do {
          if (*pcVar11 == '\x04') {
            bVar3 = true;
          }
          else if (*pcVar11 == '\x03') {
            FUN_00407e00(param_1,bVar12);
          }
          bVar12 = bVar12 + 1;
          pcVar11 = pcVar11 + 0x14;
        } while (bVar12 < 0x14);
        if (!bVar3) {
          FUN_00407be0(param_1,1);
          FUN_00435e83(local_4);
          return;
        }
        *(undefined1 *)((int)param_1 + 0x2b4) = 1;
        DVar8 = GetTickCount();
        *(DWORD *)((int)param_1 + 0x2b8) = DVar8 + (*(ushort *)((int)param_1 + 0x11c) + 3) * 1000;
        *(undefined2 *)((int)param_1 + 0x2c4) = 1;
        *(undefined2 *)((int)param_1 + 0x2c6) = 1;
        *(undefined2 *)((int)param_1 + 0x2c8) = 1;
        *(undefined2 *)((int)param_1 + 0x2ca) = 1;
        *(undefined1 *)((int)param_1 + 700) = 1;
        *(undefined1 *)((int)param_1 + 0x2be) = 0;
        *(undefined1 *)((int)param_1 + 0x2bf) = 0;
        *(undefined1 *)((int)param_1 + 0x2c0) = 0;
        *(undefined1 *)((int)param_1 + 0x2c1) = 0;
        *(undefined1 *)((int)param_1 + 0x11f) = 0;
        *(undefined1 *)((int)param_1 + 0x120) = 0;
        FUN_004059d0(param_1,(ushort *)((int)param_1 + (uint)bVar12 * 0x14 + 0x124));
        DVar8 = GetTickCount();
        uStack_fff = *(undefined1 *)((int)param_1 + 0x2c0);
        uStack_1002 = *(undefined1 *)((int)param_1 + 700);
        uStack_ffd = *(undefined1 *)((int)param_1 + 0x122);
        uStack_1001 = (undefined2)((*(int *)((int)param_1 + 0x2b8) - DVar8) / 1000);
        uStack_ffe = *(undefined1 *)((int)param_1 + 0x2c1);
        uStack_ffc = *(undefined1 *)((int)param_1 + 0x123);
        uStack_1004 = 0x48;
        puVar14 = (ushort *)((int)param_1 + 0x124);
        iVar6 = 0x14;
        do {
          if ((char)puVar14[1] == '\x04') {
            iVar13 = FUN_0042aad0();
            iVar13 = (uint)*puVar14 * 0x23b4 + *(int *)(iVar13 + 0xd4);
            *(undefined4 *)(iVar13 + 0x2395) = 0;
            *(undefined2 *)(iVar13 + 0x2399) = 0;
            uVar16 = *puVar14;
            puVar18 = (undefined4 *)&uStack_1004;
            uVar17 = 9;
            pvVar10 = (void *)FUN_0042aad0();
            FUN_0041b8a0(pvVar10,uVar16,uVar17,puVar18);
            *(undefined1 *)(puVar14 + 4) = 0;
            puVar14[2] = 0;
            puVar14[3] = 0;
          }
          puVar14 = puVar14 + 10;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        FUN_00435e83(local_4);
        return;
      }
      if (0x13 < bVar12) {
        bVar12 = 0;
        while (*(char *)((int)param_1 + (uint)bVar12 * 0x14 + 0x126) != '\x04') {
          bVar12 = bVar12 + 1;
          if (0x13 < bVar12) {
            FUN_00435e83(local_4);
            return;
          }
        }
        if (0x13 < bVar12) goto LAB_0040a3f3;
      }
      *(undefined1 *)((int)param_1 + 0x2b4) = 1;
      DVar8 = GetTickCount();
      *(DWORD *)((int)param_1 + 0x2b8) = DVar8 + (*(ushort *)((int)param_1 + 0x11c) + 3) * 1000;
      *(undefined2 *)((int)param_1 + 0x2c4) = 1;
      *(undefined2 *)((int)param_1 + 0x2c6) = 1;
      *(undefined2 *)((int)param_1 + 0x2c8) = 1;
      *(undefined2 *)((int)param_1 + 0x2ca) = 1;
      *(undefined1 *)((int)param_1 + 700) = 1;
      *(undefined1 *)((int)param_1 + 0x2be) = 0;
      *(undefined1 *)((int)param_1 + 0x2bf) = 0;
      *(undefined1 *)((int)param_1 + 0x2c0) = 0;
      *(undefined1 *)((int)param_1 + 0x2c1) = 0;
      *(undefined1 *)((int)param_1 + 0x11f) = 0;
      *(undefined1 *)((int)param_1 + 0x120) = 0;
      FUN_004059d0(param_1,(ushort *)((int)param_1 + (uint)bVar12 * 0x14 + 0x124));
      DVar8 = GetTickCount();
      uStack_1002 = *(undefined1 *)((int)param_1 + 700);
      uStack_fff = *(undefined1 *)((int)param_1 + 0x2c0);
      uStack_ffd = *(undefined1 *)((int)param_1 + 0x122);
      uStack_1001 = (undefined2)((*(int *)((int)param_1 + 0x2b8) - DVar8) / 1000);
      uStack_ffe = *(undefined1 *)((int)param_1 + 0x2c1);
      uStack_ffc = *(undefined1 *)((int)param_1 + 0x123);
      uStack_1004 = 0x48;
      puVar14 = (ushort *)((int)param_1 + 0x124);
      iVar6 = 0x14;
      do {
        if ((char)puVar14[1] == '\x04') {
          iVar13 = FUN_0042aad0();
          iVar13 = (uint)*puVar14 * 0x23b4 + *(int *)(iVar13 + 0xd4);
          *(undefined4 *)(iVar13 + 0x2395) = 0;
          *(undefined2 *)(iVar13 + 0x2399) = 0;
          uVar16 = *puVar14;
          puVar18 = (undefined4 *)&uStack_1004;
          uVar17 = 9;
          pvVar10 = (void *)FUN_0042aad0();
          FUN_0041b8a0(pvVar10,uVar16,uVar17,puVar18);
          *(undefined1 *)(puVar14 + 4) = 0;
          puVar14[2] = 0;
          puVar14[3] = 0;
        }
        puVar14 = puVar14 + 10;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    goto LAB_0040a3f3;
  }
  if (cVar1 != '\x01') {
    if ((cVar1 == '\x02') && (DVar8 = GetTickCount(), *(uint *)((int)param_1 + 0x2b8) <= DVar8)) {
      bVar12 = *(char *)((int)param_1 + 700) + 1;
      *(byte *)((int)param_1 + 700) = bVar12;
      *(undefined4 *)((int)param_1 + 0x3ac) = 0;
      *(undefined4 *)((int)param_1 + 0x3b0) = 0;
      *(undefined4 *)((int)param_1 + 0x3b4) = 0;
      *(undefined4 *)((int)param_1 + 0x3b8) = 0;
      *(undefined1 *)((int)param_1 + 0x3bc) = 0;
      *(undefined1 *)((int)param_1 + 0x3be) = 0;
      *(undefined1 *)((int)param_1 + 0x3bf) = 0x14;
      if (*(byte *)((int)param_1 + 0x11a) < bVar12) {
        FUN_00407be0(param_1,2);
        FUN_00435e83(local_4);
        return;
      }
      uVar5 = 0;
      bStack_100a = 0;
      bStack_1009 = 0;
      bVar12 = 0;
      pcVar11 = (char *)((int)param_1 + 0x126);
      do {
        if ((*pcVar11 == '\x04') || (*pcVar11 == '\x03')) {
          uVar5 = (uint)bVar12;
          if (bVar12 < 10) {
            bStack_100a = bStack_100a + 1;
          }
          else {
            bStack_1009 = bStack_1009 + 1;
          }
        }
        bVar12 = bVar12 + 1;
        pcVar11 = pcVar11 + 0x14;
      } while (bVar12 < 0x12);
      cVar1 = *(char *)((int)param_1 + 0x119);
      switch(cVar1) {
      case '\x01':
      case '\x03':
      case '\x04':
        if ((bStack_100a == 0) || (bStack_1009 == 0)) {
          FUN_00407be0(param_1,5);
          FUN_00435e83(local_4);
          return;
        }
        break;
      case '\x02':
        if ((uint)bStack_1009 + (uint)bStack_100a < 2) {
          FUN_00407be0(param_1,6);
          FUN_00435e83(local_4);
          return;
        }
      }
      if ((((cVar1 == '\x01') || (cVar1 == '\x03')) || (cVar1 == '\x04')) &&
         (*(byte *)((int)param_1 + 0x2bf) < 2)) {
        FUN_004082e0(param_1,(char *)((int)param_1 + 0x2bf));
      }
      *(undefined1 *)((int)param_1 + 0x2b4) = 1;
      DVar8 = GetTickCount();
      *(DWORD *)((int)param_1 + 0x2b8) = DVar8 + (*(ushort *)((int)param_1 + 0x11c) + 3) * 1000;
      *(undefined2 *)((int)param_1 + 0x2c4) = 1;
      *(undefined2 *)((int)param_1 + 0x2c6) = 1;
      *(undefined2 *)((int)param_1 + 0x2c8) = 1;
      *(undefined2 *)((int)param_1 + 0x2ca) = 1;
      *(undefined1 *)((int)param_1 + 0x2be) = 0;
      *(undefined1 *)((int)param_1 + 0x11f) = 0;
      *(undefined1 *)((int)param_1 + 0x120) = 0;
      FUN_004059d0(param_1,(ushort *)((int)param_1 + uVar5 * 0x14 + 0x124));
      bVar12 = 0;
      bStack_100a = 0;
      if (*(char *)((int)param_1 + 0x119) == '\x04') {
        iVar6 = FUN_0042aad0();
        iVar6 = *(int *)(iVar6 + 0xd4);
        bVar4 = 0;
        puVar14 = (ushort *)((int)param_1 + 0x124);
        do {
          if ((char)puVar14[1] == '\x04') {
            if (bVar4 < 10) {
              bVar2 = *(byte *)((uint)*puVar14 * 0x23b4 + 0x1531 + iVar6);
              if (bStack_100a < bVar2) {
                *(byte *)((int)param_1 + 0x122) = bVar4;
                bStack_100a = bVar2;
              }
            }
            else {
              bVar2 = *(byte *)((uint)*puVar14 * 0x23b4 + 0x1531 + iVar6);
              if (bVar12 < bVar2) {
                *(byte *)((int)param_1 + 0x123) = bVar4;
                bVar12 = bVar2;
              }
            }
          }
          bVar4 = bVar4 + 1;
          puVar14 = puVar14 + 10;
        } while (bVar4 < 0x14);
      }
      uStack_1002 = *(undefined1 *)((int)param_1 + 700);
      uStack_1001 = *(undefined2 *)((int)param_1 + 0x122);
      uStack_1004 = 0x49;
      iVar6 = FUN_0042aad0();
      iVar6 = *(int *)(iVar6 + 0xd4);
      puVar14 = (ushort *)((int)param_1 + 0x124);
      iVar13 = 0x14;
      do {
        if ((char)puVar14[1] == '\x04') {
          iVar9 = (uint)*puVar14 * 0x23b4 + iVar6;
          *(undefined4 *)(iVar9 + 0x2395) = 0;
          *(undefined2 *)(iVar9 + 0x2399) = 0;
          uVar16 = *puVar14;
          puVar18 = (undefined4 *)&uStack_1004;
          uVar17 = 5;
          pvVar10 = (void *)FUN_0042aad0();
          FUN_0041b8a0(pvVar10,uVar16,uVar17,puVar18);
          *(undefined1 *)(puVar14 + 4) = 0;
          puVar14[2] = 0;
          puVar14[3] = 0;
        }
        puVar14 = puVar14 + 10;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      FUN_00435e83(local_4);
      return;
    }
    goto LAB_0040a3f3;
  }
  DVar8 = GetTickCount();
  if (DVar8 < *(uint *)((int)param_1 + 0x2b8)) {
    DVar8 = GetTickCount();
    if ((*(uint *)((int)param_1 + 0x2b8) < DVar8 + 30000) &&
       (*(char *)((int)param_1 + 0x2be) == '\0')) {
      *(undefined1 *)((int)param_1 + 0x2be) = 1;
      FUN_00435e83(local_4);
      return;
    }
    goto LAB_0040a3f3;
  }
  cVar1 = *(char *)((int)param_1 + 0x119);
  if (cVar1 == '\x01') {
    if (*(ushort *)((int)param_1 + 0x2c6) < *(ushort *)((int)param_1 + 0x2c4)) {
      *(char *)((int)param_1 + 0x2c0) = *(char *)((int)param_1 + 0x2c0) + '\x01';
      *(undefined1 *)((int)param_1 + 0x2bf) = 1;
      pcVar11 = (char *)((int)param_1 + 0x12d);
      iVar6 = 10;
      do {
        if (pcVar11[-7] == '\x04') {
          *pcVar11 = *pcVar11 + '\x01';
        }
        pcVar11 = pcVar11 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      pcVar11 = (char *)((int)param_1 + 0x1f6);
      iVar6 = 10;
      do {
        if (pcVar11[-8] == '\x04') {
          *pcVar11 = *pcVar11 + '\x01';
        }
        pcVar11 = pcVar11 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      goto LAB_00409fa7;
    }
    if (*(ushort *)((int)param_1 + 0x2c4) < *(ushort *)((int)param_1 + 0x2c6)) {
      *(char *)((int)param_1 + 0x2c1) = *(char *)((int)param_1 + 0x2c1) + '\x01';
      *(undefined1 *)((int)param_1 + 0x2bf) = 0;
      pcVar11 = (char *)((int)param_1 + 0x12e);
      iVar6 = 10;
      do {
        if (pcVar11[-8] == '\x04') {
          *pcVar11 = *pcVar11 + '\x01';
        }
        pcVar11 = pcVar11 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      pcVar11 = (char *)((int)param_1 + 0x1f5);
      iVar6 = 10;
      do {
        if (pcVar11[-7] == '\x04') {
          *pcVar11 = *pcVar11 + '\x01';
        }
        pcVar11 = pcVar11 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      goto LAB_00409fa7;
    }
  }
  else if (cVar1 == '\x03') {
    if (*(byte *)((int)param_1 + 0x120) < *(byte *)((int)param_1 + 0x11f)) {
      *(char *)((int)param_1 + 0x2c0) = *(char *)((int)param_1 + 0x2c0) + '\x01';
      *(undefined1 *)((int)param_1 + 0x2bf) = 1;
      pcVar11 = (char *)((int)param_1 + 0x12d);
      iVar6 = 10;
      do {
        if (pcVar11[-7] == '\x04') {
          *pcVar11 = *pcVar11 + '\x01';
        }
        pcVar11 = pcVar11 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      pcVar11 = (char *)((int)param_1 + 0x1f6);
      iVar6 = 10;
      do {
        if (pcVar11[-8] == '\x04') {
          *pcVar11 = *pcVar11 + '\x01';
        }
        pcVar11 = pcVar11 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      goto LAB_00409fa7;
    }
    if (*(byte *)((int)param_1 + 0x11f) < *(byte *)((int)param_1 + 0x120)) {
      *(char *)((int)param_1 + 0x2c1) = *(char *)((int)param_1 + 0x2c1) + '\x01';
      *(undefined1 *)((int)param_1 + 0x2bf) = 0;
      pcVar11 = (char *)((int)param_1 + 0x12e);
      iVar6 = 10;
      do {
        if (pcVar11[-8] == '\x04') {
          *pcVar11 = *pcVar11 + '\x01';
        }
        pcVar11 = pcVar11 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      pcVar11 = (char *)((int)param_1 + 0x1f5);
      iVar6 = 10;
      do {
        if (pcVar11[-7] == '\x04') {
          *pcVar11 = *pcVar11 + '\x01';
        }
        pcVar11 = pcVar11 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      goto LAB_00409fa7;
    }
  }
  else {
    if (cVar1 != '\x04') goto LAB_00409fa7;
    if (*(ushort *)((int)param_1 + 0x2ca) < *(ushort *)((int)param_1 + 0x2c8)) {
      *(char *)((int)param_1 + 0x2c0) = *(char *)((int)param_1 + 0x2c0) + '\x01';
      *(undefined1 *)((int)param_1 + 0x2bf) = 1;
      pcVar11 = (char *)((int)param_1 + 0x12d);
      iVar6 = 10;
      do {
        if (pcVar11[-7] == '\x04') {
          *pcVar11 = *pcVar11 + '\x01';
        }
        pcVar11 = pcVar11 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      pcVar11 = (char *)((int)param_1 + 0x1f6);
      iVar6 = 10;
      do {
        if (pcVar11[-8] == '\x04') {
          *pcVar11 = *pcVar11 + '\x01';
        }
        pcVar11 = pcVar11 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      goto LAB_00409fa7;
    }
    if (*(ushort *)((int)param_1 + 0x2c8) < *(ushort *)((int)param_1 + 0x2ca)) {
      *(char *)((int)param_1 + 0x2c1) = *(char *)((int)param_1 + 0x2c1) + '\x01';
      *(undefined1 *)((int)param_1 + 0x2bf) = 0;
      pcVar11 = (char *)((int)param_1 + 0x12e);
      iVar6 = 10;
      do {
        if (pcVar11[-8] == '\x04') {
          *pcVar11 = *pcVar11 + '\x01';
        }
        pcVar11 = pcVar11 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      pcVar11 = (char *)((int)param_1 + 0x1f5);
      iVar6 = 10;
      do {
        if (pcVar11[-7] == '\x04') {
          *pcVar11 = *pcVar11 + '\x01';
        }
        pcVar11 = pcVar11 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      goto LAB_00409fa7;
    }
  }
  *(undefined1 *)((int)param_1 + 0x2bf) = 2;
LAB_00409fa7:
  *(undefined1 *)((int)param_1 + 0x2bd) = 0;
  *(undefined1 *)((int)param_1 + 0x2b4) = 2;
  DVar8 = GetTickCount();
  uStack_1002 = *(undefined1 *)((int)param_1 + 0x2bd);
  *(DWORD *)((int)param_1 + 0x2b8) = DVar8 + 15000;
  uStack_fff = *(undefined1 *)((int)param_1 + 0x2c1);
  uStack_1004 = 0x4a;
  uStack_1001 = CONCAT11(*(undefined1 *)((int)param_1 + 0x2c0),*(undefined1 *)((int)param_1 + 0x2bf)
                        );
  puVar14 = (ushort *)((int)param_1 + 0x124);
  iVar6 = 0x14;
  do {
    if ((char)puVar14[1] == '\x04') {
      uVar16 = *puVar14;
      puVar18 = (undefined4 *)&uStack_1004;
      uVar17 = 6;
      pvVar10 = (void *)FUN_0042aad0();
      FUN_0041b8a0(pvVar10,uVar16,uVar17,puVar18);
    }
    puVar14 = puVar14 + 10;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_00435e83(local_4);
  return;
}



/* METADATA: sig=undefined __fastcall FUN_00409940(void * param_1) xrefs=0042c7c9 callees=FUN_00407be0 FUN_00406350 GetTickCount FUN_004059d0 FUN_0040bbe0 FUN_004082e0 FUN_0041b8a0 FUN_0042aad0 FUN_00409810 FUN_00407e00 FUN_00435e83 __chkstk */
