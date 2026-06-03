
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00423580(void *this,ushort param_1,undefined4 param_2,LPCSTR param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  void *pvVar9;
  ushort uVar10;
  undefined1 uVar11;
  byte bStack_212d;
  uint local_212c;
  ushort uStack_2128;
  undefined2 uStack_2126;
  byte bStack_2124;
  undefined3 uStack_2123;
  byte bStack_2120;
  undefined3 uStack_211f;
  int local_211c;
  CHAR CStack_2118;
  undefined3 uStack_2117;
  byte bStack_2114;
  undefined3 uStack_2113;
  byte abStack_2110 [4];
  byte bStack_210c;
  undefined3 uStack_210b;
  CHAR local_2108 [12];
  CHAR local_20fc [44];
  CHAR local_20d0 [204];
  undefined4 uStack_2004;
  undefined4 uStack_2000;
  CHAR aCStack_1ffc [4088];
  undefined2 uStack_1004;
  undefined1 uStack_1002;
  ushort uStack_1001;
  int local_4;
  
  local_4 = DAT_00454928;
  local_211c = (uint)param_1 * 0x23b4;
  iVar6 = local_211c + *(int *)((int)this + 0xd4);
  if ((*(int *)(iVar6 + 0x1460) == 0) || (*(int *)(iVar6 + 0x14a4) == 0)) {
    FUN_0041eb20(this,param_1,0x52,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(char *)(iVar6 + 0x1440) != '\x02') {
    FUN_0041eb20(this,param_1,0x53,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  iVar6 = lstrlenA(param_3);
  if (iVar6 < 0x29) {
    lstrcpyA(local_20fc,param_3);
    iVar6 = lstrlenA(local_20fc);
    local_212c = iVar6 + 1;
    uVar8 = local_212c & 0xffff;
    iVar6 = lstrlenA(param_3 + uVar8);
    if (iVar6 < 9) {
      lstrcpyA(local_2108,param_3 + uVar8);
      iVar6 = lstrlenA(local_2108);
      local_212c = local_212c + 1 + iVar6;
      uVar8 = local_212c & 0xffff;
      iVar6 = lstrlenA(param_3 + uVar8);
      if (iVar6 < 0xc9) {
        lstrcpynA(local_20d0,param_3 + uVar8,0xc9);
        iVar6 = lstrlenA(local_20d0);
        uVar8 = local_212c + 1 + iVar6;
        bVar1 = param_3[uVar8 & 0xffff];
        _bStack_2124 = CONCAT31(uStack_2123,bVar1);
        bVar2 = param_3[uVar8 + 1 & 0xffff];
        _bStack_2120 = CONCAT31(uStack_211f,param_3[uVar8 + 2 & 0xffff]);
        uVar10 = *(ushort *)(param_3 + (uVar8 + 3 & 0xffff));
        _uStack_2128 = CONCAT22(uStack_2126,uVar10);
        bVar3 = param_3[uVar8 + 5 & 0xffff];
        bVar4 = param_3[uVar8 + 6 & 0xffff];
        local_212c = CONCAT31(local_212c._1_3_,bVar4);
        bVar5 = param_3[uVar8 + 7 & 0xffff];
        _bStack_210c = CONCAT31(uStack_210b,bVar2);
        _bStack_2114 = CONCAT31(uStack_2113,bVar5);
        _CStack_2118 = CONCAT31(uStack_2117,param_3[uVar8 + 8 & 0xffff]);
        if (bVar2 == 0) {
          if (bVar1 < 100) {
            if (*(char *)((uint)bVar1 * 3 + *(int *)((int)this + 0xe8)) != '\0') {
              uStack_2004._0_2_ = *(undefined2 *)(*(int *)((int)this + 0xd4) + 0x1488 + local_211c);
              uStack_2000 = *(undefined4 *)(*(int *)((int)this + 0xd4) + local_211c + 0x1460);
              uStack_2004._2_2_ = 0x25;
              lstrcpyA(aCStack_1ffc,local_20fc);
              iVar6 = lstrlenA(local_20fc);
              lstrcpyA((LPSTR)((int)&uStack_2004 + (iVar6 + 9U & 0xffff)),local_2108);
              iVar7 = lstrlenA(local_2108);
              uVar8 = iVar6 + 10 + iVar7;
              lstrcpyA((LPSTR)((int)&uStack_2004 + (uVar8 & 0xffff)),local_20d0);
              iVar6 = lstrlenA(local_20d0);
              uVar8 = uVar8 + 1 + iVar6;
              *(byte *)((int)&uStack_2004 + (uVar8 & 0xffff)) = bStack_2124;
              *(byte *)((int)&uStack_2004 + (uVar8 + 1 & 0xffff)) = bStack_2120;
              *(ushort *)((int)&uStack_2004 + (uVar8 + 2 & 0xffff)) = uStack_2128;
              *(byte *)((int)&uStack_2004 + (uVar8 + 4 & 0xffff)) = bVar3;
              *(undefined1 *)((int)&uStack_2004 + (uVar8 + 5 & 0xffff)) = (undefined1)local_212c;
              *(byte *)((int)&uStack_2004 + (uVar8 + 6 & 0xffff)) = bStack_2114;
              *(CHAR *)((int)&uStack_2004 + (uVar8 + 7 & 0xffff)) = CStack_2118;
              FUN_0041b940(this,param_1,(short)uVar8 + 8,&uStack_2004);
              goto LAB_00423661;
            }
            uVar10 = 0x58;
          }
          else {
            uVar10 = 0x57;
          }
        }
        else if (bVar2 < 5) {
          if ((byte)param_3[uVar8 + 2 & 0xffff] < 0x16) {
            if ((uVar10 < 0x122) || (0x4ba < uVar10)) {
              uVar10 = 0xcb;
            }
            else if (bVar2 == 2) {
              if ((bVar3 < 0xd) || (0x1e < bVar3)) {
                uVar10 = 0xcc;
              }
              else {
LAB_004237ce:
                if ((bVar4 == 0) || (99 < bVar5)) {
                  uVar10 = 0x59;
                }
                else {
                  pvVar9 = (void *)(*(int *)((int)this + 0xd4) + local_211c);
                  bVar1 = *(byte *)((int)pvVar9 + 0x1531);
                  if ((bVar4 <= bVar1) && (bVar1 <= bVar5)) {
                    uStack_1002 = 1;
                    uStack_1001 = 0;
                    if (DAT_00455824 != 0) {
                      uVar10 = 0;
                      do {
                        if (*(char *)((uint)uVar10 * 0x3c0 + 8 + *(int *)((int)this + 0xe4)) == '\0'
                           ) {
                          FUN_0040af90(pvVar9,&bStack_212d,abStack_2110);
                          FUN_00405240((void *)((uint)bStack_212d * 0x358 + *(int *)((int)this + 0xdc)),abStack_2110[0]);
                          FUN_00405440((void *)((uint)uVar10 * 0x3c0 + *(int *)((int)this + 0xe4)),
                                       local_20fc,local_2108,local_20d0,(byte)_bStack_2124,
                                       (byte)_bStack_210c,(char)_bStack_2120,(short)_uStack_2128,
                                       bVar3,(char)local_212c,(char)_bStack_2114,param_1,
                                       (char)_CStack_2118);
                          pvVar9 = (void *)(local_211c + *(int *)((int)this + 0xd4));
                          if (*(char *)((int)pvVar9 + 0x146c) == '\x01') {
                            uVar11 = 0x13;
                          }
                          else {
                            uVar11 = 0;
                          }
                          FUN_0040b7b0(pvVar9,uVar10,uVar11);
                          uStack_1002 = 0;
                          uStack_1001 = uVar10;
                          break;
                        }
                        uStack_1001 = uVar10 + 1;
                        uVar10 = uStack_1001;
                      } while (uStack_1001 < DAT_00455824);
                    }
                    uStack_1004 = 0x3b;
                    FUN_004038e0(*(void **)((int)this + 0x118),param_1,5,(undefined4 *)&uStack_1004)
                    ;
                    goto LAB_00423661;
                  }
                  uVar10 = 0x5a;
                }
              }
            }
            else {
              if ((bVar2 != 3) || ((0x13 < bVar3 && (bVar3 < 0x33)))) goto LAB_004237ce;
              uVar10 = 0xcc;
            }
          }
          else {
            uVar10 = 0xca;
          }
        }
        else {
          uVar10 = 0x5b;
        }
      }
      else {
        uVar10 = 0x56;
      }
    }
    else {
      uVar10 = 0x55;
    }
  }
  else {
    uVar10 = 0x54;
  }
  FUN_0041eb20(this,param_1,uVar10,'\x01',1);
LAB_00423661:
  FUN_00435e83(local_4);
  return;
}
