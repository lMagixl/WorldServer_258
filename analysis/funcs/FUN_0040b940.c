
undefined4 __thiscall
FUN_0040b940(void *this,uint *param_1,int param_2,undefined1 *param_3,int param_4)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte local_d;
  undefined4 local_c;
  
  local_c = 0;
  iVar5 = FUN_0042aad0();
  iVar5 = *(int *)(iVar5 + 0x104);
  iVar6 = param_2 - (int)param_1;
  iVar7 = param_4 - (int)param_1;
  local_d = 10;
  param_2 = 3;
  do {
    if (*param_1 != 0) {
      uVar8 = (uint)local_d;
      uVar2 = *(ushort *)((int)this + uVar8 * 2 + 0x1da4);
      if (((uVar2 != 0) && (7999 < uVar2)) && (uVar2 < 9000)) {
        if (100 < *param_1) {
          *param_1 = 100;
        }
        uVar9 = *param_1 + *(int *)((int)this + uVar8 * 4 + 0x1de0);
        sVar3 = *(short *)((int)this + uVar8 * 2 + 0x1da4);
        *(uint *)((int)this + uVar8 * 4 + 0x1de0) = uVar9;
        if (*(char *)(uVar8 + 0x1dca + (int)this) == 'c') {
          uVar4 = *(uint *)(iVar5 + 0x18c);
          if (uVar4 < uVar9) {
            *(uint *)((int)this + uVar8 * 4 + 0x1de0) = uVar4;
          }
        }
        else {
          while ((uVar9 = *(uint *)((int)this + uVar8 * 4 + 0x1de0), uVar9 != 0 &&
                 (bVar1 = *(byte *)(uVar8 + 0x1dca + (int)this),
                 *(uint *)(iVar5 + ((uint)(ushort)(sVar3 + 0xe0c0) * 200 + (uint)bVar1) * 4) < uVar9
                 ))) {
            *(byte *)(uVar8 + 0x1dca + (int)this) = bVar1 + 1;
            local_c = 1;
          }
        }
        *(undefined4 *)(iVar6 + (int)param_1) = *(undefined4 *)((int)this + uVar8 * 4 + 0x1b78);
        *param_3 = *(undefined1 *)(uVar8 + 0x1dca + (int)this);
        *(undefined4 *)(iVar7 + (int)param_1) = *(undefined4 *)((int)this + uVar8 * 4 + 0x1de0);
        *(undefined4 *)((int)this + uVar8 * 4 + 0x157c) =
             *(undefined4 *)((int)this + uVar8 * 4 + 0x1b78);
        *(undefined1 *)(uVar8 + 0x17ce + (int)this) = *(undefined1 *)(uVar8 + 0x1dca + (int)this);
        *(undefined4 *)((int)this + uVar8 * 4 + 0x17e4) =
             *(undefined4 *)((int)this + uVar8 * 4 + 0x1de0);
      }
    }
    local_d = local_d + 1;
    param_3 = param_3 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  return local_c;
}


