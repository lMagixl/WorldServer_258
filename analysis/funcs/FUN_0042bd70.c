
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __fastcall FUN_0042bd70(uint *param_1)

{
  char cVar1;
  IPv4Address *pIVar2;
  undefined4 *puVar3;
  bool bVar4;
  ushort uVar5;
  DWORD DVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined3 extraout_var;
  ushort uVar11;
  int *piVar12;
  void *pvVar13;
  code *pcVar14;
  uint *puVar15;
  uint *puVar16;
  uint *in_stack_ffff9ce4;
  char *in_stack_ffff9ce8;
  char *pcVar17;
  uint uStack_62f4;
  int iStack_62f0;
  undefined4 *puStack_62ec;
  int iStack_62e8;
  undefined4 uStack_62e4;
  uint local_62e0;
  uint local_62dc;
  uint local_62d8;
  uint local_62d4;
  undefined1 *puStack_62d0;
  uint uStack_62cc;
  uint uStack_62c8;
  undefined4 uStack_62c4;
  int iStack_62c0;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_62bc [4];
  void *pvStack_62b8;
  undefined4 uStack_62a8;
  uint uStack_62a4;
  CHAR aCStack_6220 [128];
  CHAR aCStack_61a0 [128];
  char acStack_6120 [12];
  undefined1 auStack_6114 [244];
  ushort uStack_6020;
  char cStack_601e;
  char cStack_601d;
  undefined2 uStack_601c;
  undefined1 uStack_601a;
  undefined2 uStack_5020;
  undefined4 uStack_501e;
  undefined4 uStack_501a;
  undefined4 uStack_5016;
  undefined4 uStack_5012;
  undefined4 uStack_4020;
  ushort uStack_401c;
  undefined1 auStack_3020 [6];
  uint auStack_301a [7];
  uint auStack_2ffe [1015];
  undefined2 uStack_2020;
  undefined2 uStack_201e;
  undefined1 uStack_201c;
  undefined2 uStack_201b;
  undefined2 uStack_1020;
  undefined2 uStack_101e;
  int local_1c;
  uint *puStack_18;
  void *pvStack_14;
  undefined1 *puStack_10;
  uint uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_004412f9;
  pvStack_14 = ExceptionList;
  local_1c = DAT_00454928;
  ExceptionList = &pvStack_14;
  param_1[0x1673] = 1;
  local_62e0 = 0;
  local_62d8 = 0;
  local_62dc = 0;
  local_62d4 = 0;
  puStack_18 = param_1;
  DVar6 = GetTickCount();
  FUN_004364c8(DVar6 + 2);
  cVar1 = *(char *)((int)param_1 + 0x4e);
  do {
    if (cVar1 != '\x02') {
      *(undefined1 *)((int)param_1 + 0x4e) = 2;
      param_1[0x1673] = 0x2b;
      ExceptionList = pvStack_14;
      FUN_00435e83(local_1c);
      return;
    }
    param_1[0x1673] = 2;
    Sleep(1);
    param_1[0x1673] = 3;
    iVar7 = FUN_004038d0((void *)param_1[0x46],(undefined2 *)&uStack_62f4,(ushort *)&iStack_62f0,
                         (undefined4 *)&uStack_6020);
    while (iVar7 != 0) {
      param_1[0x1673] = 4;
      if (uStack_6020 == 0) {
        if (cStack_601e == '\0') {
          pvVar13 = (void *)(param_1[0x35] + (uStack_62f4 & 0xffff) * 0x23b4);
          if (*(char *)((int)pvVar13 + 0x1440) == '\0') {
            FUN_0040da80(pvVar13,CONCAT13(uStack_601a,CONCAT21(uStack_601c,cStack_601d)));
          }
          else {
            pcVar17 = s__0000__DUPC_0044c374;
LAB_0042c055:
            FUN_0041d380(param_1,pcVar17,0);
          }
        }
        else if (cStack_601e == '\x01') {
          if (*(char *)((uStack_62f4 & 0xffff) * 0x23b4 + 0x1440 + param_1[0x35]) != '\0') {
            FUN_0042f280(s__RW______CWorld__Idle___Disconne_0044c398);
            FUN_0041eb20(param_1,(ushort)uStack_62f4,1,'\0',1);
            if (cStack_601d != '\0') {
              in_stack_ffff9ce8 = (char *)0x42c013;
              wsprintfA(aCStack_61a0,s___04u__IOE1__02u__05u_0044c380);
              pcVar17 = aCStack_61a0;
              goto LAB_0042c055;
            }
          }
        }
        else {
          if (cStack_601e == '\x02') {
            in_stack_ffff9ce8 = (char *)0x42bf92;
            wsprintfA(aCStack_6220,s___04u__IOE2__02u__05u_0044c3c8);
            pcVar17 = aCStack_6220;
            goto LAB_0042c055;
          }
          FUN_0041d380(param_1,s__000__IOE3_00_0044c3e0,0);
          if (*(char *)((uStack_62f4 & 0xffff) * 0x23b4 + 0x1440 + param_1[0x35]) != '\0') {
            FUN_0041eb20(param_1,(ushort)uStack_62f4,3,'\x01',1);
          }
        }
      }
      else {
        iVar7 = (uStack_62f4 & 0xffff) * 0x23b4 + param_1[0x35];
        if (*(char *)(iVar7 + 0x1440) != '\0') {
          if (uStack_6020 == 0xf) {
            FUN_0042ab40(param_1,uStack_62f4,0xf,iStack_62f0 - 4,(uint *)&uStack_601c);
          }
          else if (uStack_6020 == 0xc) {
            *(undefined2 *)(iVar7 + 0x146e) = 0;
            FUN_0042ab40(param_1,uStack_62f4,0xc,iStack_62f0 - 4,(uint *)&uStack_601c);
          }
          else {
            uVar5 = *(short *)(iVar7 + 0x146e) + 1;
            if (65000 < uVar5) {
              uVar5 = 0;
            }
            if (CONCAT11(cStack_601d,cStack_601e) == uVar5) {
              *(ushort *)(iVar7 + 0x146e) = CONCAT11(cStack_601d,cStack_601e);
              FUN_0042ab40(param_1,uStack_62f4,uStack_6020,iStack_62f0 - 4,(uint *)&uStack_601c);
            }
            else {
              FUN_0041eb20(param_1,(ushort)uStack_62f4,2,'\x01',1);
            }
          }
        }
      }
      param_1[0x1673] = 5;
      iVar7 = FUN_004038d0((void *)param_1[0x46],(undefined2 *)&uStack_62f4,(ushort *)&iStack_62f0,
                           (undefined4 *)&uStack_6020);
    }
    iVar7 = FUN_00404000((void *)param_1[0x47],(ushort *)&iStack_62f0,(undefined4 *)&uStack_6020,
                         &iStack_62e8,(undefined2 *)&uStack_62e4);
    while (iVar7 != 0) {
      param_1[0x1673] = 6;
      FUN_00429530(param_1,iStack_62f0,&uStack_6020,iStack_62e8,(short)uStack_62e4);
      param_1[0x1673] = 7;
      iVar7 = FUN_00404000((void *)param_1[0x47],(ushort *)&iStack_62f0,(undefined4 *)&uStack_6020,
                           &iStack_62e8,(undefined2 *)&uStack_62e4);
    }
    iVar7 = FUN_00404000((void *)param_1[0x48],(ushort *)&iStack_62f0,(undefined4 *)&uStack_6020,
                         &iStack_62e8,(undefined2 *)&uStack_62e4);
    while (iVar7 != 0) {
      param_1[0x1673] = 8;
      FUN_00429530(param_1,iStack_62f0,&uStack_6020,iStack_62e8,(short)uStack_62e4);
      param_1[0x1673] = 9;
      iVar7 = FUN_00404000((void *)param_1[0x48],(ushort *)&iStack_62f0,(undefined4 *)&uStack_6020,
                           &iStack_62e8,(undefined2 *)&uStack_62e4);
    }
    iVar7 = FUN_0042e580((void *)param_1[0x3e],(undefined2 *)&uStack_62f4,(ushort *)&iStack_62f0,
                         (undefined4 *)&uStack_6020);
    pcVar14 = GetTickCount_exref;
    while (GetTickCount_exref = pcVar14, iVar7 != 0) {
      param_1[0x1676] = param_1[0x1676] + 1;
      param_1[0x1673] = 10;
      if ((DAT_00456030 <= (ushort)uStack_62f4) ||
         ((iVar7 = (uStack_62f4 & 0xffff) * 0x23b4 + param_1[0x35],
          *(char *)(iVar7 + 0x1440) != '\0' && (*(ushort *)(iVar7 + 0x148a) == uStack_6020)))) {
        FUN_004295c0(param_1,uStack_62f4,CONCAT11(cStack_601d,cStack_601e),iStack_62f0 + -2,
                     (int)&cStack_601e);
      }
      param_1[0x1673] = 0xb;
      iVar7 = FUN_0042e580((void *)param_1[0x3e],(undefined2 *)&uStack_62f4,(ushort *)&iStack_62f0,
                           (undefined4 *)&uStack_6020);
      pcVar14 = GetTickCount_exref;
    }
    param_1[0x1673] = 0xc;
    puVar8 = (undefined4 *)GetTickCount();
    puStack_62ec = puVar8;
    if (param_1[0x14d7] < (int)puVar8 - param_1[0x13a2]) {
      uStack_62cc = *(uint *)(param_1[0x3f] + 0x30);
      if (uStack_62cc < param_1[0x14d8]) {
        if ((uStack_62cc < param_1[0x14d9]) && (1 < param_1[0x13a0])) {
          piVar12 = (int *)((param_1[0x13a1] - 4) + param_1[0x13a0] * 4);
          if (*piVar12 != 0) {
            param_1[0x1673] = 0x10;
            FUN_0040e8a0(*piVar12);
            pIVar2 = *(IPv4Address **)((param_1[0x13a1] - 4) + param_1[0x13a0] * 4);
            if (*(int *)(pIVar2 + 0x30) == 10) {
              if (pIVar2 != (IPv4Address *)0x0) {
                PerfLib::IPv4Address::~IPv4Address(pIVar2);
                _free(pIVar2);
              }
            }
            else {
              iVar7 = 0;
              piVar12 = (int *)param_1[0x167c];
              do {
                if (*piVar12 == 0) {
                  ((int *)param_1[0x167c])[iVar7] = (int)pIVar2;
                  param_1[0x167b] = param_1[0x167b] + 1;
                  break;
                }
                iVar7 = iVar7 + 1;
                piVar12 = piVar12 + 1;
              } while (iVar7 < 0x20);
            }
            *(undefined4 *)((param_1[0x13a1] - 4) + param_1[0x13a0] * 4) = 0;
          }
          uVar10 = param_1[0x13a0] - 1;
          param_1[0x13a4] = (uint)puVar8;
LAB_0042c4fa:
          param_1[0x13a0] = uVar10;
        }
      }
      else if (param_1[0x13a0] < param_1[0x14d6]) {
        puStack_62d0 = operator_new(0x38);
        uStack_c = 0;
        if (puStack_62d0 == (undefined1 *)0x0) {
          uVar9 = 0;
        }
        else {
          uVar9 = FUN_0040e880((int)puStack_62d0);
        }
        *(undefined4 *)(param_1[0x13a1] + param_1[0x13a0] * 4) = uVar9;
        piVar12 = (int *)(param_1[0x13a1] + param_1[0x13a0] * 4);
        uStack_c = 0xffffffff;
        if (*piVar12 != 0) {
          in_stack_ffff9ce8 = (char *)param_1[0x145d];
          in_stack_ffff9ce4 = param_1 + 0x1439;
          param_1[0x1673] = 0xd;
          iVar7 = FUN_0041b520((void *)*piVar12,param_1[0x3d],param_1 + 0x13a6,param_1[0x13ca],
                               param_1 + 0x13b2,param_1 + 0x13be,param_1 + 0x13cb,param_1 + 0x13d7,
                               param_1[0x13fb],param_1 + 0x13e3,param_1 + 0x13ef,param_1 + 0x13fc,
                               param_1 + 0x1408,param_1[0x142c],param_1 + 0x1414,param_1 + 0x1420,
                               param_1 + 0x142d);
          if (iVar7 != 0) {
            param_1[0x1673] = 0xe;
            uVar10 = param_1[0x13a0] + 1;
            param_1[0x13a3] = (uint)puVar8;
            goto LAB_0042c4fa;
          }
          param_1[0x1673] = 0xf;
          FUN_0040e950(*(int *)(param_1[0x13a1] + param_1[0x13a0] * 4));
          pIVar2 = *(IPv4Address **)(param_1[0x13a1] + param_1[0x13a0] * 4);
          if (pIVar2 != (IPv4Address *)0x0) {
            PerfLib::IPv4Address::~IPv4Address(pIVar2);
            _free(pIVar2);
          }
          *(undefined4 *)(param_1[0x13a1] + param_1[0x13a0] * 4) = 0;
        }
      }
      iVar7 = 0;
      do {
        pIVar2 = *(IPv4Address **)(iVar7 + param_1[0x167c]);
        if ((pIVar2 != (IPv4Address *)0x0) && (*(int *)(pIVar2 + 0x30) == 10)) {
          PerfLib::IPv4Address::~IPv4Address(pIVar2);
          _free(pIVar2);
          *(undefined4 *)(iVar7 + param_1[0x167c]) = 0;
          param_1[0x167b] = param_1[0x167b] - 1;
        }
        pcVar14 = GetTickCount_exref;
        iVar7 = iVar7 + 4;
      } while (iVar7 < 0x80);
      param_1[0x13a2] = (uint)puStack_62ec;
      param_1[0x13a5] = uStack_62cc;
    }
    param_1[0x1673] = 0x12;
    uVar10 = (*pcVar14)();
    if (local_62e0 < uVar10) {
      uStack_62f4 = 0;
      if (DAT_00456030 != 0) {
        do {
          iVar7 = (uStack_62f4 & 0xffff) * 0x23b4;
          if (*(char *)(iVar7 + 0x1440 + param_1[0x35]) != '\0') {
            param_1[0x1673] = 0x13;
            uVar9 = FUN_0040bbe0(iVar7 + param_1[0x35]);
            if ((byte)uVar9 < 2) {
LAB_0042c60b:
              iVar7 = param_1[0x35] + (uStack_62f4 & 0xffff) * 0x23b4;
              param_1[0x1673] = 0x15;
              if ((*(char *)(iVar7 + 0x1440) == '\x02') &&
                 (bVar4 = FUN_0040b740(iVar7), CONCAT31(extraout_var,bVar4) != 0)) {
                FUN_0041bef0(param_1,(ushort)uStack_62f4);
                FUN_0040b770((uStack_62f4 & 0xffff) * 0x23b4 + param_1[0x35]);
              }
              pvVar13 = (void *)(param_1[0x35] + (uStack_62f4 & 0xffff) * 0x23b4);
              param_1[0x1673] = 0x19;
              if (*(int *)((int)pvVar13 + 0x1460) != 0) {
                puStack_62ec = (undefined4 *)0x0;
                iVar7 = FUN_0040a950(pvVar13,(int *)&puStack_62ec);
                if ((iVar7 == 0) && (puStack_62ec != (undefined4 *)0x0)) {
                  uStack_5020 = 0x10;
                  uStack_501e = *puStack_62ec;
                  uStack_501a = puStack_62ec[1];
                  uStack_5016 = puStack_62ec[2];
                  uStack_5012 = puStack_62ec[3];
                  FUN_004038e0((void *)param_1[0x46],(ushort)uStack_62f4,0x12,
                               (undefined4 *)&uStack_5020);
                }
              }
              param_1[0x1673] = 0x1a;
              pcVar14 = GetTickCount_exref;
            }
            else {
              cVar1 = *(char *)((uStack_62f4 & 0xffff) * 0x23b4 + 0x1440 + param_1[0x35]);
              if (cVar1 == '\x03') {
                FUN_0041eb20(param_1,(ushort)uStack_62f4,4,'\x01',1);
              }
              else {
                if (cVar1 != '\x02') goto LAB_0042c60b;
                FUN_0041eb20(param_1,(ushort)uStack_62f4,4,'\x01',1);
              }
            }
          }
          uStack_62f4 = uStack_62f4 + 1;
        } while ((ushort)uStack_62f4 < DAT_00456030);
      }
      iVar7 = (*pcVar14)();
      local_62e0 = iVar7 + 2000;
    }
    param_1[0x1673] = 0x1b;
    uVar10 = (*pcVar14)();
    if (local_62d8 < uVar10) {
      *(undefined2 *)(param_1 + 0x38) = 0;
      uStack_62f4 = 0;
      if (DAT_00455824 != 0) {
        do {
          pvVar13 = (void *)((uStack_62f4 & 0xffff) * 0x3c0 + param_1[0x39]);
          if (*(char *)((int)pvVar13 + 8) != '\0') {
            FUN_00409940(pvVar13);
            uVar10 = FUN_004069a0((void *)((uStack_62f4 & 0xffff) * 0x3c0 + param_1[0x39]),
                                  (int)param_1);
            if (uVar10 == 0) {
              *(short *)(param_1 + 0x38) = (short)param_1[0x38] + 1;
            }
            else {
              _sprintf(acStack_6120,s_GHOST_FIELD_DESTROYED___u_0044c358,uVar10);
              FUN_0041d380(param_1,auStack_6114,0);
            }
          }
          uStack_62f4 = uStack_62f4 + 1;
        } while ((ushort)uStack_62f4 < DAT_00455824);
      }
      iVar7 = (*pcVar14)();
      local_62d8 = iVar7 + 1000;
    }
    param_1[0x1673] = 0x1d;
    uVar10 = (*pcVar14)();
    if (local_62dc < uVar10) {
      FUN_0041ce60((int)param_1);
      iVar7 = (*pcVar14)();
      local_62dc = iVar7 + 20000;
    }
    param_1[0x1673] = 0x1f;
    uVar10 = (*pcVar14)();
    if (local_62d4 < uVar10) {
      uStack_201c = (undefined1)param_1[0x15];
      uStack_2020 = 0;
      uStack_201e = 0x19;
      if (param_1[0x14] == 0) {
        uStack_201b = (undefined2)param_1[0x1b];
      }
      else {
        uStack_201b = 0;
      }
      FUN_0041b940(param_1,DAT_00456030,7,(undefined4 *)&uStack_2020);
      iVar7 = (*pcVar14)();
      local_62d4 = iVar7 + 60000;
    }
    cVar1 = *(char *)((int)param_1 + 0x4e);
    param_1[0x1673] = 0x20;
    while (cVar1 == '\x02') {
      uVar10 = param_1[0x16c6];
      if (uVar10 == 1) {
        uStack_62a4 = 0xf;
        uStack_62a8 = 0;
        pvStack_62b8 = (void *)((uint)pvStack_62b8 & 0xffffff00);
        uStack_c = uVar10;
        uVar10 = PerfLib::AsyncWebRequest::GetResponse
                           ((AsyncWebRequest *)(param_1 + 0x1749),&uStack_62c8,abStack_62bc);
        if (uVar10 == 0x4e29) {
          uStack_c = 0xffffffff;
          if (0xf < uStack_62a4) {
            _free(pvStack_62b8);
          }
          uStack_62a4 = 0xf;
          uStack_62a8 = 0;
          pvStack_62b8 = (void *)((uint)pvStack_62b8 & 0xffffff00);
          break;
        }
        puStack_62d0 = &stack0xffff9ce4;
        in_stack_ffff9ce8 = (char *)((uint)in_stack_ffff9ce8 & 0xffffff00);
        FUN_0040d8a0(&stack0xffff9ce4,abStack_62bc,0,0xffffffff);
        FUN_00429b40(param_1,(ushort)uStack_62c8,in_stack_ffff9ce4,in_stack_ffff9ce8);
        uStack_c = 0xffffffff;
        if (0xf < uStack_62a4) {
          _free(pvStack_62b8);
        }
        uStack_62a4 = 0xf;
        uStack_62a8 = 0;
        pvStack_62b8 = (void *)((uint)pvStack_62b8 & 0xffffff00);
      }
      else {
        if ((uVar10 != 2) ||
           (uVar9 = FUN_00429dd0(param_1 + 0x17b6,&uStack_62c4), (char)uVar9 == '\0')) break;
        FUN_0041e2f0(param_1,(ushort)uStack_62c4,iStack_62c0);
      }
      cVar1 = *(char *)((int)param_1 + 0x4e);
    }
    puStack_62ec = (undefined4 *)0x0;
    if (DAT_00456030 != 0) {
      do {
        puVar8 = puStack_62ec;
        iVar7 = ((uint)puStack_62ec & 0xffff) * 0x23b4;
        if ((*(char *)(iVar7 + 0x1440 + param_1[0x35]) != '\0') &&
           (uVar5 = FUN_0040daf0((void *)(iVar7 + param_1[0x35]),0x456050,&DAT_00456450,'\0'),
           puVar3 = puStack_62ec, uVar5 != 0)) {
          uStack_4020._0_2_ = 0;
          uStack_4020._2_2_ = 0x22;
          uVar11 = 6;
          iVar7 = 0;
          uVar10 = (uint)uVar5;
          uStack_401c = uVar5;
          do {
            uVar5 = uVar11 + 4;
            *(undefined4 *)((int)&uStack_4020 + (uint)uVar11) =
                 *(undefined4 *)((int)&DAT_00456050 + iVar7);
            puVar8 = (undefined4 *)((int)&DAT_00456450 + iVar7);
            uVar11 = uVar11 + 8;
            iVar7 = iVar7 + 4;
            uVar10 = uVar10 - 1;
            *(undefined4 *)((int)&uStack_4020 + (uint)uVar5) = *puVar8;
          } while (uVar10 != 0);
          FUN_0041b940(param_1,DAT_00456030,uVar11,&uStack_4020);
          puVar8 = puVar3;
        }
        puStack_62ec = (undefined4 *)((int)puVar8 + 1);
      } while ((ushort)puStack_62ec < DAT_00456030);
    }
    DVar6 = GetTickCount();
    if (*param_1 < DVar6) {
      puStack_62ec = (undefined4 *)0x0;
      uVar5 = DAT_00456030;
      if (DAT_00456030 != 0) {
        do {
          cVar1 = *(char *)(((uint)puStack_62ec & 0xffff) * 0x23b4 + 0x1440 + param_1[0x35]);
          if ((cVar1 != '\0') && (cVar1 == '\x02')) {
            puVar8 = (undefined4 *)auStack_3020;
            for (iVar7 = 0x400; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar8 = 0;
              puVar8 = puVar8 + 1;
            }
            auStack_3020._2_4_ = param_1[1];
            auStack_3020._0_2_ = 0x77;
            puVar15 = param_1 + 2;
            puVar16 = auStack_301a;
            for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar16 = *puVar15;
              puVar15 = puVar15 + 1;
              puVar16 = puVar16 + 1;
            }
            puVar15 = param_1 + 9;
            puVar16 = auStack_2ffe;
            for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar16 = *puVar15;
              puVar15 = puVar15 + 1;
              puVar16 = puVar16 + 1;
            }
            pvVar13 = (void *)param_1[0x46];
            *(short *)puVar16 = (short)*puVar15;
            FUN_004038e0(pvVar13,(ushort)puStack_62ec,0x4c,(undefined4 *)auStack_3020);
            uVar5 = DAT_00456030;
          }
          puStack_62ec = (undefined4 *)((int)puStack_62ec + 1);
        } while ((ushort)puStack_62ec < uVar5);
      }
      uStack_1020 = 0;
      uStack_101e = 0x2b;
      FUN_0041b940(param_1,uVar5,4,(undefined4 *)&uStack_1020);
      DVar6 = GetTickCount();
      *param_1 = DVar6 + 60000;
    }
    param_1[0x1672] = param_1[0x1672] + 1;
    cVar1 = *(char *)((int)param_1 + 0x4e);
  } while( true );
}



/* METADATA: sig=undefined __fastcall FUN_0042bd70(uint * param_1) xrefs=0042cd14 callees=FUN_00429dd0 FUN_004069a0 FUN_00404000 FUN_0041eb20 FUN_0041ce60 FUN_00435e83 _sprintf GetTickCount FUN_0040b740 FUN_0040b770 GetResponse ~IPv4Address FUN_00409940 FUN_004038d0 FUN_0041e2f0 FUN_004364c8 FUN_0040e950 FUN_0040e880 FUN_0041b520 FUN_0041bef0 FUN_00429530 FUN_00429b40 FUN_004295c0 __chkstk FUN_0041b940 FUN_0040bbe0 operator_new _free FUN_0040a950 FUN_0040daf0 FUN_0040e8a0 FUN_0042f280 FUN_0042ab40 FUN_0041d380 Sleep FUN_004038e0 FUN_0040da80 FUN_0042e580 wsprintfA FUN_0040d8a0 */
