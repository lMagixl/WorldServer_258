
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00422c90(void *this,ushort param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  ushort uVar9;
  bool bVar10;
  byte bVar11;
  short sVar12;
  undefined3 extraout_var;
  int iVar13;
  ushort uVar14;
  int iVar15;
  void *pvVar16;
  int iVar17;
  ushort uVar18;
  byte local_102d;
  ushort local_1004;
  byte local_1002;
  int local_4;
  
  iVar15 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  pvVar16 = (void *)(iVar15 + *(int *)((int)this + 0xd4));
  if ((*(int *)((int)pvVar16 + 0x1460) == 0) || (*(int *)((int)pvVar16 + 0x14a4) == 0)) {
    FUN_0041eb20(this,param_1,0x46,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(char *)((int)pvVar16 + 0x1440) != '\x02') {
    FUN_0041eb20(this,param_1,0x47,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  bVar1 = *param_3;
  if (10 < bVar1) {
    FUN_0041eb20(this,param_1,0x48,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  uVar14 = *(ushort *)(param_3 + 1);
  if (DAT_00455824 <= uVar14) {
    FUN_0041eb20(this,param_1,0x49,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  bVar2 = param_3[5];
  bVar3 = param_3[4];
  bVar11 = param_3[3];
  bVar4 = param_3[6];
  bVar5 = param_3[7];
  bVar6 = param_3[8];
  bVar7 = param_3[9];
  FUN_0040b6c0(pvVar16,bVar1,uVar14,bVar11,bVar3,bVar2,bVar4,bVar5,bVar6,bVar7);
  if (bVar11 == 0) {
    if (uVar14 != 0) {
      uVar14 = uVar14 - 1;
    }
    local_102d = 0;
    for (; uVar14 != 0; uVar14 = uVar14 - 1) {
      iVar17 = (uint)uVar14 * 0x3c0;
      cVar8 = *(char *)(iVar17 + 8 + *(int *)((int)this + 0xe4));
      pvVar16 = (void *)(iVar17 + *(int *)((int)this + 0xe4));
      if (cVar8 != '\0') {
        if (bVar7 == 0) {
          bVar10 = FUN_0041b830((int)pvVar16);
          if ((CONCAT31(extraout_var,bVar10) == 0) &&
             (iVar13 = FUN_00405920(pvVar16,*(byte *)(iVar15 + 0x1531 + *(int *)((int)this + 0xd4)))
             , iVar13 != 0)) {
            iVar17 = iVar17 + *(int *)((int)this + 0xe4);
            switch(*(undefined1 *)(iVar17 + 0x119)) {
            case 0:
              if (bVar3 != 0) {
                bVar10 = *(char *)(iVar17 + 8) == '\x02';
                goto LAB_00422eee;
              }
              break;
            case 1:
              goto switchD_00422ea2_caseD_1;
            case 2:
              goto switchD_00422ea2_caseD_2;
            case 3:
              goto switchD_00422ea2_caseD_3;
            case 4:
              goto switchD_00422ea2_caseD_4;
            }
            goto switchD_00422ea2_default;
          }
          goto LAB_00422efe;
        }
        switch(*(undefined1 *)((int)pvVar16 + 0x119)) {
        case 0:
          if (bVar3 == 0) goto switchD_00422ea2_default;
          bVar10 = cVar8 == '\x02';
          goto LAB_00422eee;
        case 1:
switchD_00422ea2_caseD_1:
          bVar11 = bVar2;
          break;
        case 2:
switchD_00422ea2_caseD_2:
          bVar11 = bVar4;
          break;
        case 3:
switchD_00422ea2_caseD_3:
          bVar11 = bVar5;
          break;
        case 4:
switchD_00422ea2_caseD_4:
          bVar11 = bVar6;
          break;
        default:
          goto switchD_00422ea2_default;
        }
        bVar10 = bVar11 == 0;
LAB_00422eee:
        if (!bVar10) {
          local_102d = local_102d + 1;
        }
switchD_00422ea2_default:
        if (bVar1 <= local_102d) break;
      }
LAB_00422efe:
    }
  }
  else if ((uVar14 != 0) && ((int)(uint)uVar14 < (int)(DAT_00455824 - 1))) {
    uVar14 = uVar14 + 1;
  }
  local_1004 = 0x36;
  uVar18 = 3;
  local_102d = 0;
  uVar9 = 3;
  if (uVar14 < DAT_00455824) {
    do {
      uVar18 = uVar9;
      iVar17 = (uint)uVar14 * 0x3c0;
      pvVar16 = (void *)(iVar17 + *(int *)((int)this + 0xe4));
      if (*(char *)((int)pvVar16 + 8) != '\0') {
        if (bVar7 == 0) {
          if (((uint)*(byte *)((int)pvVar16 + 0x117) + (uint)*(byte *)((int)pvVar16 + 0x116) <
               (uint)*(byte *)((int)pvVar16 + 0x115) + (uint)*(byte *)((int)pvVar16 + 0x114)) &&
             (iVar13 = FUN_00405920(pvVar16,*(byte *)(iVar15 + 0x1531 + *(int *)((int)this + 0xd4)))
             , iVar13 != 0)) {
            pvVar16 = (void *)(*(int *)((int)this + 0xe4) + iVar17);
            switch(*(undefined1 *)(*(int *)((int)this + 0xe4) + 0x119 + iVar17)) {
            case 0:
              if (bVar3 != 0) {
                bVar10 = *(char *)((int)pvVar16 + 8) == '\x02';
                goto LAB_0042300f;
              }
              break;
            case 1:
              goto switchD_00422fc9_caseD_1;
            case 2:
              goto switchD_00422fc9_caseD_2;
            case 3:
              goto switchD_00422fc9_caseD_3;
            case 4:
              goto switchD_00422fc9_caseD_4;
            }
          }
        }
        else {
          switch(*(undefined1 *)((int)pvVar16 + 0x119)) {
          case 0:
            bVar11 = bVar3;
            break;
          case 1:
switchD_00422fc9_caseD_1:
            bVar11 = bVar2;
            break;
          case 2:
switchD_00422fc9_caseD_2:
            bVar11 = bVar4;
            break;
          case 3:
switchD_00422fc9_caseD_3:
            bVar11 = bVar5;
            break;
          case 4:
switchD_00422fc9_caseD_4:
            bVar11 = bVar6;
            break;
          default:
            goto switchD_00422fc9_default;
          }
          bVar10 = bVar11 == 0;
LAB_0042300f:
          if (!bVar10) {
            *(ushort *)((int)&local_1004 + (uint)uVar18) = uVar14;
            local_102d = local_102d + 1;
            sVar12 = FUN_00405790(pvVar16,(int)&local_1004 + (uint)(ushort)(uVar18 + 2));
            uVar18 = uVar18 + 2 + sVar12;
            if (bVar1 <= local_102d) break;
          }
        }
      }
switchD_00422fc9_default:
      uVar14 = uVar14 + 1;
      uVar9 = uVar18;
    } while (uVar14 < DAT_00455824);
  }
  local_1002 = local_102d;
  FUN_004038e0(*(void **)((int)this + 0x118),param_1,uVar18,(undefined4 *)&local_1004);
  FUN_00435e83(local_4);
  return;
}
