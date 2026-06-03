/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_00419730(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  byte bVar1;
  byte bVar2;
  void *pvVar3;
  undefined4 uVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  undefined4 *puVar10;
  uint *puVar11;
  undefined4 *puVar12;
  CHAR *pCVar13;
  uint local_16e0;
  undefined4 local_16d0 [20];
  undefined4 local_1680 [120];
  uint local_14a0 [4];
  uint local_1490;
  undefined4 local_1488 [30];
  CHAR local_1410 [1024];
  undefined2 local_1010;
  undefined2 local_100e;
  int local_c;
  
  local_c = DAT_00454928;
  uVar4 = *param_4;
  bVar1 = *(byte *)(param_4 + 1);
  iVar9 = 5;
  if (bVar1 != 0) {
    local_16e0 = (uint)(ushort)bVar1;
    puVar10 = (undefined4 *)((int)param_4 + 5);
    puVar12 = local_16d0;
    for (uVar6 = (uint)bVar1; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar12 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar12 = puVar12 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    iVar9 = (uint)bVar1 * 4 + 5;
    puVar8 = (uint *)(iVar9 + (int)param_4);
    puVar11 = local_14a0;
    for (uVar6 = (uint)(bVar1 >> 2); uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar11 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar11 = puVar11 + 1;
    }
    for (uVar6 = (ushort)bVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(char *)puVar11 = (char)*puVar8;
      puVar8 = (uint *)((int)puVar8 + 1);
      puVar11 = (uint *)((int)puVar11 + 1);
    }
    iVar9 = iVar9 + local_16e0;
  }
  bVar2 = *(byte *)(iVar9 + (int)param_4);
  iVar9 = iVar9 + 1;
  if (bVar2 != 0) {
    uVar5 = (ushort)bVar2;
    local_16e0 = (uint)uVar5;
    puVar10 = (undefined4 *)(iVar9 + (int)param_4);
    puVar12 = local_1680;
    for (uVar6 = (uint)uVar5; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar12 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar12 = puVar12 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    iVar9 = iVar9 + local_16e0 * 4;
    puVar10 = (undefined4 *)(iVar9 + (int)param_4);
    puVar12 = local_1488;
    for (uVar6 = (uint)(bVar2 >> 2); uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar12 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar12 = puVar12 + 1;
    }
    for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    iVar9 = iVar9 + local_16e0;
  }
  FUN_00416aa0(this,uVar4,bVar1,(int)local_16d0,(int)local_14a0,bVar2,(int)local_1680,
               (int)local_1488);
  if (*(char *)(iVar9 + (int)param_4) != '\0') {
    puVar8 = (uint *)(iVar9 + 5 + (int)param_4);
    local_14a0[0] = *puVar8;
    local_14a0[1] = puVar8[1];
    local_14a0[2] = puVar8[2];
    local_14a0[3] = puVar8[3];
    local_1490 = puVar8[4];
    uVar4 = *(undefined4 *)(iVar9 + 0x1b + (int)param_4);
    uVar5 = *(ushort *)(iVar9 + 0x1f + (int)param_4);
    wsprintfA(local_1410,s_UPDATE_CharacterInfo_SET_levelpo_0044b3e0,local_14a0[0] & 0xffff,
              local_14a0[0] >> 0x10,local_14a0[1] & 0xffff,local_14a0[1] >> 0x10,
              local_14a0[2] & 0xffff,local_14a0[2] >> 0x10,local_14a0[3] & 0xffff,
              local_14a0[3] >> 0x10,local_1490 & 0xffff,local_1490 >> 0x10,(uint)(ushort)puVar8[5],
              *(undefined4 *)(iVar9 + 1 + (int)param_4));
    iVar9 = mysql_query(*(undefined4 *)((int)this + 8),local_1410);
    if (iVar9 != 0) {
      iVar9 = *(int *)((int)this + 8);
      pCVar13 = local_1410;
      iVar7 = -1;
      pvVar3 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar3,pCVar13,iVar7);
      if (iVar9 != 0) {
        iVar7 = -1;
        uVar4 = mysql_error(iVar9);
        pvVar3 = (void *)FUN_0042aad0();
        FUN_0041d380(pvVar3,uVar4,iVar7);
        FUN_00435e83(local_c);
        return;
      }
      goto LAB_00419a1f;
    }
    wsprintfA(local_1410,s_UPDATE_usergameinfo_SET_powerlev_00449a44,(uint)uVar5,uVar4);
    iVar9 = mysql_query(*(undefined4 *)((int)this + 8),local_1410);
    if (iVar9 != 0) {
      FUN_0040ea30(*(int *)((int)this + 8),local_1410);
      FUN_00435e83(local_c);
      return;
    }
  }
  local_1010 = param_2;
  local_100e = 0x13;
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,4,(undefined4 *)&local_1010);
LAB_00419a1f:
  FUN_00435e83(local_c);
  return;
}
