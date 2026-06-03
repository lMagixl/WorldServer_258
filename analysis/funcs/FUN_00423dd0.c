
void __thiscall FUN_00423dd0(void *this,ushort param_1,undefined4 param_2,LPCSTR param_3)

{
  LPCSTR pCVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  void *this_00;
  ushort uVar7;
  char local_11d;
  LPCSTR pCStack_11c;
  ushort local_118 [2];
  byte bStack_114;
  undefined3 uStack_113;
  byte bStack_110;
  undefined3 uStack_10f;
  CHAR CStack_10c;
  undefined3 uStack_10b;
  CHAR aCStack_108 [12];
  CHAR local_fc [44];
  CHAR aCStack_d0 [204];
  int local_4;
  
  local_4 = DAT_00454928;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + (uint)param_1 * 0x23b4);
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    FUN_0041eb20(this,param_1,0x6a,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(char *)((int)this_00 + 0x1440) != '\x03') {
    FUN_0041eb20(this,param_1,0x6b,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  FUN_0040b7d0(this_00,local_118,&local_11d);
  iVar5 = (uint)local_118[0] * 0x3c0 + *(int *)((int)this + 0xe4);
  if (*(char *)(iVar5 + 8) == '\x02') {
    FUN_0041eb20(this,param_1,0x6c,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(char *)(iVar5 + 0x119) == '\0') {
    FUN_0041eb20(this,param_1,0x6d,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (local_11d != *(char *)(iVar5 + 0x121)) {
    FUN_0041eb20(this,param_1,0x6e,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  iVar5 = lstrlenA(param_3);
  if (iVar5 < 0x29) {
    lstrcpyA(local_fc,param_3);
    iVar5 = lstrlenA(param_3);
    pCStack_11c = param_3 + (iVar5 + 1U & 0xffff);
    iVar6 = lstrlenA(pCStack_11c);
    if (iVar6 < 9) {
      lstrcpyA(aCStack_108,pCStack_11c);
      iVar6 = lstrlenA(pCStack_11c);
      pCStack_11c = (LPCSTR)(iVar5 + 2 + iVar6);
      pCVar1 = param_3 + ((uint)pCStack_11c & 0xffff);
      iVar5 = lstrlenA(pCVar1);
      if (iVar5 < 0xc9) {
        lstrcpyA(aCStack_d0,pCVar1);
        iVar5 = lstrlenA(pCVar1);
        pCVar1 = pCStack_11c + iVar5 + 1;
        bVar2 = param_3[(uint)(pCVar1 + 1) & 0xffff];
        _CStack_10c = CONCAT31(uStack_10b,param_3[(uint)pCVar1 & 0xffff]);
        uVar7 = *(ushort *)(param_3 + ((uint)(pCVar1 + 2) & 0xffff));
        bVar3 = param_3[(uint)(pCVar1 + 4) & 0xffff];
        bVar4 = param_3[(uint)(pCVar1 + 5) & 0xffff];
        _bStack_114 = CONCAT31(uStack_113,bVar2);
        _bStack_110 = CONCAT31(uStack_10f,bVar3);
        pCStack_11c = (LPCSTR)CONCAT31(pCStack_11c._1_3_,bVar4);
        if (bVar2 < 0x16) {
          if ((uVar7 < 0x122) || (0x4ba < uVar7)) {
            uVar7 = 0xce;
          }
          else if (bVar4 == 2) {
            if ((0xc < bVar3) && (bVar3 < 0x1f)) goto LAB_0042406b;
            uVar7 = 0xcf;
          }
          else if (bVar4 == 3) {
            if ((0x13 < bVar3) && (bVar3 < 0x33)) {
LAB_0042406b:
              FUN_004077c0((void *)((uint)local_118[0] * 0x3c0 + *(int *)((int)this + 0xe4)),
                           local_fc,aCStack_108,aCStack_d0,param_3[(uint)pCVar1 & 0xffff],bVar2,
                           uVar7,bVar3,bVar4);
              goto LAB_00423f8d;
            }
            uVar7 = 0xcf;
          }
          else {
            if ((bVar4 != 0) && (bVar4 < 5)) goto LAB_0042406b;
            uVar7 = 0x72;
          }
        }
        else {
          uVar7 = 0xcd;
        }
      }
      else {
        uVar7 = 0x71;
      }
    }
    else {
      uVar7 = 0x70;
    }
  }
  else {
    uVar7 = 0x6f;
  }
  FUN_0041eb20(this,param_1,uVar7,'\x01',1);
LAB_00423f8d:
  FUN_00435e83(local_4);
  return;
}
