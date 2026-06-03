// FUN_0042a310 — Post-switch handler, admin/GM HTTP auth
// Address: 0x0042a310

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0042a310(void *this,ushort param_1,undefined4 param_2,char *param_3)

{
  LPCSTR pCVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  char *pcVar7;
  void *this_00;
  int iVar8;
  byte *pbVar9;
  bool bVar10;
  ushort uVar11;
  uint uVar12;
  _union_1226 local_1470 [2];
  byte local_1468 [5];
  undefined4 local_1463;
  undefined4 local_145f;
  undefined4 local_145b;
  undefined4 local_1457;
  undefined4 local_1453;
  undefined4 local_144f;
  undefined4 local_144b;
  undefined2 local_1444 [4];
  CHAR aCStack_143c [24];
  CHAR aCStack_1424 [32];
  char acStack_1404 [20];
  char acStack_13f0 [1004];
  undefined2 local_1004;
  undefined1 local_1002;
  int local_4;
  
  local_4 = DAT_00454928;
  if (*(int *)((int)this + 0x50) != 0) {
    FUN_0041eb20(this,param_1,0x12,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  uVar12 = (uint)param_1;
  iVar8 = uVar12 * 0x23b4;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + iVar8);
  if ((*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar8) != 0) ||
     (*(int *)((int)this_00 + 0x14a4) != 0)) {
    FUN_0041eb20(this,param_1,0x13,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(uint *)((int)this + 0x536c) <= *(uint *)(*(int *)((int)this + 0xfc) + 0x30)) {
    local_1004 = 0xc;
    local_1002 = 10;
    FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)&local_1004);
    FUN_00435e83(local_4);
    return;
  }
  FUN_0040abe0(this_00,local_1470,local_1444);
  cVar2 = *param_3;
  *(char *)(*(int *)((int)this + 0xd4) + 0x237c + iVar8) = cVar2;
  local_1468[1] = 0;
  local_1468[2] = 0;
  local_1468[3] = 0;
  local_1468[4] = 0;
  local_1463 = 0;
  local_145f = 0;
  local_145b = 0;
  local_1457 = 0;
  local_1453 = 0;
  local_144f = 0;
  local_1468[0] = 0;
  local_144b = 0;
  lstrcpynA((LPSTR)local_1468,param_3 + 1,0x21);
  iVar4 = lstrlenA(param_3 + 1);
  if (cVar2 != '\x04') {
    pbVar5 = local_1468;
    if (cVar2 == '\x01') {
      pbVar9 = (byte *)((int)this + 0x14d);
      do {
        bVar3 = *pbVar5;
        bVar10 = bVar3 < *pbVar9;
        if (bVar3 != *pbVar9) goto LAB_0042a4b8;
        if (bVar3 == 0) break;
        bVar3 = pbVar5[1];
        bVar10 = bVar3 < pbVar9[1];
        if (bVar3 != pbVar9[1]) goto LAB_0042a4b8;
        pbVar5 = pbVar5 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar3 != 0);
      iVar6 = 0;
    }
    else {
      pbVar9 = (byte *)((int)this + 300);
      do {
        bVar3 = *pbVar5;
        bVar10 = bVar3 < *pbVar9;
        if (bVar3 != *pbVar9) goto LAB_0042a4b8;
        if (bVar3 == 0) break;
        bVar3 = pbVar5[1];
        bVar10 = bVar3 < pbVar9[1];
        if (bVar3 != pbVar9[1]) goto LAB_0042a4b8;
        pbVar5 = pbVar5 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar3 != 0);
      iVar6 = 0;
    }
    goto LAB_0042a4bd;
  }
LAB_0042a4f2:
  pCVar1 = param_3 + (iVar4 + 2U & 0xffff);
  iVar6 = lstrlenA(pCVar1);
  if (iVar6 < 0x11) {
    lstrcpynA(aCStack_1424,pCVar1,0x11);
    iVar6 = lstrlenA(pCVar1);
    FUN_0041b810((void *)(*(int *)((int)this + 0xd4) + iVar8),aCStack_1424);
    pCVar1 = param_3 + (iVar6 + 1 + iVar4 + 2U & 0xffff);
    iVar8 = lstrlenA(pCVar1);
    if (iVar8 < 0x15) {
      lstrcpynA(aCStack_143c,pCVar1,0x15);
      lstrlenA(pCVar1);
      if (*(int *)((int)this + 0x5b18) == 1) {
        _sprintf(acStack_1404,s__s_id__s_pw__s_idc_0_0044c2dc,(char *)((int)this + 0x5c20),
                 aCStack_1424,aCStack_143c);
        if (*(int *)((int)this + 0x5d20) == 0) {
          PerfLib::AsyncWebRequest::SendRequest
                    ((AsyncWebRequest *)((int)this + 0x5d24),
                     CONCAT31((undefined3)local_1463,local_1468[4]),acStack_13f0,false);
        }
        else {
          PerfLib::AsyncWebRequest::SendRequest
                    ((AsyncWebRequest *)((int)this + 0x5d24),
                     CONCAT31((undefined3)local_1463,local_1468[4]),acStack_13f0,true);
        }
      }
      else if (*(int *)((int)this + 0x5b18) == 2) {
        pcVar7 = inet_ntoa((in_addr)local_1470[0]);
        FUN_00429eb0((void *)((int)this + 0x5e5c),uVar12,aCStack_1424,aCStack_143c,pcVar7);
      }
      goto LAB_0042a522;
    }
    uVar11 = 0x15;
  }
  else {
    uVar11 = 0x14;
  }
  FUN_0041eb20(this,param_1,uVar11,'\x01',1);
LAB_0042a522:
  FUN_00435e83(local_4);
  return;
LAB_0042a4b8:
  iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
LAB_0042a4bd:
  if (iVar6 != 0) {
    local_1004 = 0xc;
    local_1002 = 8;
    FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)&local_1004);
    goto LAB_0042a522;
  }
  goto LAB_0042a4f2;
}

// SQL strings found: (none — admin/GM HTTP auth handler, uses AsyncWebRequest)
