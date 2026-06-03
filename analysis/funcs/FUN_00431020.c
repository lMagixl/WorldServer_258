
undefined4 __cdecl FUN_00431020(int param_1)

{
  ulong param3;
  __time32_t param6;
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint *puVar7;
  longlong lVar8;
  int iVar9;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000000c;
  int in_stack_00000014;
  char *pcVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int local_4;
  
  iVar6 = param_1;
  uVar4 = 0;
  if (param_1 == 0) {
    if ((DAT_004581bc & 2) == 0) {
      return 0;
    }
    pcVar10 = s__C___S_lib__UpdateProtocol_____I_00454278;
    uVar2 = 0;
  }
  else {
    uVar2 = *(uint *)(param_1 + 4);
    if ((0x1004f < uVar2) && (uVar2 < 0x20001)) {
      if ((DAT_00457ff0 == 0) || (uVar2 < *(uint *)(DAT_00457ff0 + 4))) {
        if ((DAT_004581bc & 2) != 0) {
          _sprintf(&DAT_00457de8,s__C___S_lib__UpdateProtocol___err_00453ca4,uVar2);
          FUN_0042b9f0(2,&DAT_00457de8);
        }
        return 0xc;
      }
      if ((*(uint *)(DAT_00457ff0 + 4) < uVar2) && (DAT_004581a4 == '\0')) {
        DAT_004581a4 = '\x01';
        DAT_004581b4 = FID_conflict___time32((__time32_t *)0x0);
        if ((DAT_004581bc & 1) != 0) {
          _sprintf(&DAT_00457de8,s__C___S_lib__UpdateProtocol_____N_0045422c,*(ulong *)(iVar6 + 4),
                   DAT_004581b4);
          FUN_0042b9f0(1,&DAT_00457de8);
        }
      }
      param6 = FID_conflict___time32((__time32_t *)0x0);
      iVar6 = 0;
      piVar5 = &DAT_00458154;
LAB_004310e2:
      if ((*piVar5 != *(int *)(in_stack_00000014 + 4)) || (*piVar5 == 0)) goto LAB_0043110f;
      FUN_00437382(piVar5[2],param6);
      lVar8 = __ftol();
      uVar2 = (int)(uint)lVar8 >> 0x1f;
      if (0xe0f < (int)(((uint)lVar8 ^ uVar2) - uVar2)) goto LAB_0043110f;
      (&DAT_00458158)[iVar6 * 4] = (&DAT_00458158)[iVar6 * 4] + 1;
      (&DAT_0045815c)[iVar6 * 4] = param6;
      if ((((uint)(&DAT_00458158)[iVar6 * 4] < DAT_00457fec) ||
          ((uint)(param6 - DAT_004581b4) <= (uint)(DAT_004581ac * 0x3c))) ||
         ((uint)(&DAT_00458154)[iVar6 * 4] <= *(uint *)(DAT_00457ff0 + 4))) {
        if ((DAT_004581bc & 1) != 0) {
          _sprintf(&DAT_00457de8,s__C___S_lib__UpdateProtocol_____P_00453f8c,
                   *(ulong *)(in_stack_00000014 + 4),iVar6,(&DAT_00458154)[iVar6 * 4],
                   (&DAT_00458158)[iVar6 * 4],param6,(&DAT_00458160)[iVar6 * 4]);
          FUN_0042b9f0(1,&DAT_00457de8);
        }
        goto LAB_004316de;
      }
      piVar5 = &DAT_00458158;
      do {
        iVar6 = *piVar5;
        piVar5 = piVar5 + 4;
        uVar4 = uVar4 + iVar6;
      } while ((int)piVar5 < 0x4581a8);
      iVar9 = 0;
      local_4 = -1;
      puVar7 = &DAT_00458154;
      iVar6 = DAT_004581a8;
      do {
        if ((*(uint *)(DAT_00457ff0 + 4) < *puVar7) &&
           (uVar2 = puVar7[1], (iVar6 * uVar4) / 100 < uVar2)) {
          if ((DAT_004581bc & 1) != 0) {
            _sprintf(&DAT_00457de8,s__C___S_lib__UpdateProtocol_____N_004541bc,*puVar7,uVar2,uVar4,
                     (uVar2 * 100) / uVar4,iVar6);
            FUN_0042b9f0(1,&DAT_00457de8);
            iVar6 = DAT_004581a8;
          }
          if (((local_4 != -1) || (local_4 = iVar9, puVar7 != &DAT_00458144)) &&
             ((uint)(&DAT_00458154)[local_4 * 4] < *puVar7)) {
            local_4 = iVar9;
          }
        }
        puVar7 = puVar7 + 4;
        iVar9 = iVar9 + 1;
      } while ((int)puVar7 < 0x4581a4);
      if (local_4 == -1) {
        if ((DAT_004581bc & 1) != 0) {
          _sprintf(&DAT_00457de8,s__C___S_lib__UpdateProtocol_____N_00453ff8);
          FUN_0042b9f0(1,&DAT_00457de8);
        }
      }
      else {
        if ((DAT_004581bc & 2) != 0) {
          _sprintf(&DAT_00457de8,s__C___S_lib__UpdateProtocol_______00454180);
          FUN_0042b9f0(2,&DAT_00457de8);
        }
        iVar6 = 0;
        piVar5 = &DAT_00458158;
        do {
          if ((DAT_004581bc & 2) != 0) {
            _sprintf(&DAT_00457de8,s__C___S_lib____ld____lx___ld___ld_00454150,iVar6,piVar5[-1],
                     *piVar5,piVar5[1],piVar5[2],(uint)(*piVar5 * 100) / uVar4);
            FUN_0042b9f0(2,&DAT_00457de8);
          }
          piVar5 = piVar5 + 4;
          iVar6 = iVar6 + 1;
        } while ((int)piVar5 < 0x4581a8);
        if ((DAT_004581bc & 2) != 0) {
          _sprintf(&DAT_00457de8,s__C___S_lib__CURRENT_PRTC____lx_00454130,
                   *(ulong *)(DAT_00457ff0 + 4));
          FUN_0042b9f0(2,&DAT_00457de8);
          if ((DAT_004581bc & 2) != 0) {
            _sprintf(&DAT_00457de8,s__C___S_lib__UpdateProtocol_______004540f4);
            FUN_0042b9f0(2,&DAT_00457de8);
          }
        }
        param3 = (&DAT_00458154)[local_4 * 4];
        iVar6 = in_stack_00000014;
        iVar9 = DAT_00457ff0;
        if (param3 != *(ulong *)(in_stack_00000014 + 4)) {
          do {
            iVar6 = iVar9;
            if (iVar6 == 0) {
LAB_0043138d:
              if ((DAT_004581bc & 2) != 0) {
                _sprintf(&DAT_00457de8,s__C___S_lib__UpdateProtocol___err_004540c0,local_4,param3);
                FUN_0042b9f0(2,&DAT_00457de8);
              }
              return 0xc;
            }
            if (*(ulong *)(iVar6 + 4) == param3) {
              if (iVar6 == 0) goto LAB_0043138d;
              break;
            }
            iVar9 = *(int *)(iVar6 + 0x30);
          } while( true );
        }
        param_1 = *(int *)(DAT_00457ff0 + 4);
        if (*(int *)(iVar6 + 0x30) == 0) {
          *(undefined4 *)(*(int *)(iVar6 + 0x34) + 0x30) = 0;
        }
        else {
          *(int *)(*(int *)(iVar6 + 0x34) + 0x30) = *(int *)(iVar6 + 0x30);
          *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x34) = *(undefined4 *)(iVar6 + 0x34);
        }
        *(int *)(DAT_00457ff0 + 0x34) = iVar6;
        *(undefined4 *)(DAT_00457ff0 + 0x18) = 1;
        *(int *)(iVar6 + 0x30) = DAT_00457ff0;
        *(undefined4 *)(iVar6 + 0x34) = 0;
        in_stack_00000008 = *(undefined4 *)(iVar6 + 4);
        in_stack_0000000c = 2;
        DAT_00457ff0 = iVar6;
        FUN_0042ba10(&param_1);
        if ((DAT_004581bc & 1) != 0) {
          _sprintf(&DAT_00457de8,s__C___S_lib__UpdateProtocol_____N_00454070,*(ulong *)(iVar6 + 4),
                   *(long *)(iVar6 + 8),*(long *)(iVar6 + 0x10));
          FUN_0042b9f0(1,&DAT_00457de8);
        }
      }
      puVar1 = &DAT_00458158;
      do {
        puVar1[-1] = 0;
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1 = puVar1 + 4;
      } while ((int)puVar1 < 0x4581a8);
      DAT_004581a4 = '\0';
      goto LAB_004316de;
    }
    if ((DAT_004581bc & 2) == 0) {
      return 0;
    }
    pcVar10 = s__C___S_lib__UpdateProtocol_____I_00453c64;
  }
  _sprintf(&DAT_00457de8,pcVar10,uVar2);
  FUN_0042b9f0(2,&DAT_00457de8);
  return 0;
LAB_0043110f:
  piVar5 = piVar5 + 4;
  iVar6 = iVar6 + 1;
  if (0x4581a3 < (int)piVar5) goto code_r0x0043111b;
  goto LAB_004310e2;
code_r0x0043111b:
  uVar4 = 0;
  piVar5 = &DAT_00458154;
  do {
    if (*piVar5 == 0) {
      (&DAT_00458154)[uVar4 * 4] = *(undefined4 *)(in_stack_00000014 + 4);
      (&DAT_00458158)[uVar4 * 4] = 1;
      (&DAT_0045815c)[uVar4 * 4] = param6;
      (&DAT_00458160)[uVar4 * 4] = param6;
      break;
    }
    piVar5 = piVar5 + 4;
    uVar4 = uVar4 + 1;
  } while ((int)piVar5 < 0x4581a4);
  if (uVar4 == 5) {
    uVar4 = 0xffffffff;
    uVar2 = 0;
    puVar7 = &DAT_00458158;
    do {
      FUN_00437382(puVar7[1],param6);
      lVar8 = __ftol();
      uVar3 = (int)(uint)lVar8 >> 0x1f;
      if ((0xe10 < (int)(((uint)lVar8 ^ uVar3) - uVar3)) &&
         (*puVar7 < (uint)(&DAT_00458158)[(-(uint)(uVar4 != 0xffffffff) & uVar4) * 4])) {
        uVar4 = uVar2;
      }
      puVar7 = puVar7 + 4;
      uVar2 = uVar2 + 1;
    } while ((int)puVar7 < 0x4581a8);
    if (uVar4 == 0xffffffff) {
      uVar2 = 0;
      puVar7 = &DAT_0045815c;
      do {
        if (*puVar7 < (uint)(&DAT_0045815c)[(-(uint)(uVar4 != 0xffffffff) & uVar4) * 4]) {
          uVar4 = uVar2;
        }
        puVar7 = puVar7 + 4;
        uVar2 = uVar2 + 1;
      } while ((int)puVar7 < 0x4581ac);
      if (uVar4 == 0xffffffff) {
        uVar4 = 0;
      }
      if ((DAT_004581bc & 1) != 0) {
        uVar15 = (&DAT_00458160)[uVar4 * 4];
        uVar14 = (&DAT_0045815c)[uVar4 * 4];
        uVar13 = (&DAT_00458158)[uVar4 * 4];
        uVar12 = (&DAT_00458154)[uVar4 * 4];
        uVar11 = *(undefined4 *)(in_stack_00000014 + 4);
        pcVar10 = s__C___S_lib__UpdateProtocol_____a_00453f00;
LAB_0043162d:
        _sprintf(&DAT_00457de8,pcVar10,uVar11,uVar4,uVar12,uVar13,uVar14,uVar15);
        FUN_0042b9f0(1,&DAT_00457de8);
      }
    }
    else if ((DAT_004581bc & 1) != 0) {
      uVar15 = (&DAT_00458160)[uVar4 * 4];
      uVar14 = (&DAT_0045815c)[uVar4 * 4];
      uVar13 = (&DAT_00458158)[uVar4 * 4];
      uVar12 = (&DAT_00458154)[uVar4 * 4];
      uVar11 = *(undefined4 *)(in_stack_00000014 + 4);
      pcVar10 = s__C___S_lib__UpdateProtocol_____a_00453e64;
      goto LAB_0043162d;
    }
    (&DAT_00458154)[uVar4 * 4] = *(undefined4 *)(in_stack_00000014 + 4);
    (&DAT_00458158)[uVar4 * 4] = 1;
    (&DAT_0045815c)[uVar4 * 4] = param6;
    (&DAT_00458160)[uVar4 * 4] = param6;
    if ((DAT_004581bc & 1) != 0) {
      uVar15 = (&DAT_0045815c)[uVar4 * 4];
      uVar14 = (&DAT_00458158)[uVar4 * 4];
      uVar13 = (&DAT_00458154)[uVar4 * 4];
      pcVar10 = s__C___S_lib___>___ld____lx___ld___00453e20;
      goto LAB_004316c5;
    }
  }
  else {
    if ((DAT_004581bc & 1) == 0) goto LAB_00431705;
    param6 = (&DAT_00458160)[uVar4 * 4];
    uVar15 = (&DAT_0045815c)[uVar4 * 4];
    uVar14 = (&DAT_00458158)[uVar4 * 4];
    uVar13 = (&DAT_00458154)[uVar4 * 4];
    pcVar10 = s__C___S_lib__UpdateProtocol_____i_00453da8;
LAB_004316c5:
    _sprintf(&DAT_00457de8,pcVar10,uVar4,uVar13,uVar14,uVar15,param6);
    FUN_0042b9f0(1,&DAT_00457de8);
  }
LAB_004316de:
  if ((DAT_004581bc & 1) != 0) {
    _sprintf(&DAT_00457de8,s__C___S_lib__UpdateProtocol_______00453d64);
    FUN_0042b9f0(1,&DAT_00457de8);
  }
LAB_00431705:
  iVar6 = 0;
  piVar5 = &DAT_00458158;
  do {
    if ((*piVar5 != 0) && ((DAT_004581bc & 1) != 0)) {
      _sprintf(&DAT_00457de8,s__C___S_lib____ld____lx___ld___ld_00453d38,iVar6,piVar5[-1],*piVar5,
               piVar5[1],piVar5[2]);
      FUN_0042b9f0(1,&DAT_00457de8);
    }
    piVar5 = piVar5 + 4;
    iVar6 = iVar6 + 1;
  } while ((int)piVar5 < 0x4581a8);
  if ((DAT_004581bc & 1) != 0) {
    _sprintf(&DAT_00457de8,s__C___S_lib__CURRENT_VER____lx_00453d18,*(ulong *)(DAT_00457ff0 + 4));
    FUN_0042b9f0(1,&DAT_00457de8);
    if ((DAT_004581bc & 1) != 0) {
      _sprintf(&DAT_00457de8,s__C___S_lib__UpdateProtocol_______00453cd4);
      FUN_0042b9f0(1,&DAT_00457de8);
      return 0;
    }
  }
  return 0;
}



/* METADATA: sig=undefined4 __cdecl FUN_00431020(int param_1) xrefs=00431f61 callees=__ftol FUN_0042ba10 FUN_00437382 _sprintf FID_conflict:__time32 FUN_0042b9f0 */
