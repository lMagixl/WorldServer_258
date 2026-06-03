/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041c4d0(void *this,uint param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  void *this_00;
  int iVar13;
  int iVar14;
  char *pcVar15;
  int iVar16;
  uint uVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  LPSTR pCStack_108c;
  undefined4 *puStack_1088;
  undefined4 *puStack_1084;
  uint uStack_1080;
  undefined4 *puStack_107c;
  undefined4 *puStack_1078;
  undefined4 *puStack_1074;
  undefined4 *puStack_1070;
  undefined4 *puStack_106c;
  undefined4 *puStack_1068;
  byte abStack_1064 [4];
  undefined4 *puStack_1060;
  void *local_105c;
  uint uStack_1058;
  undefined4 uStack_1054;
  uint uStack_1050;
  undefined4 uStack_104c;
  uint uStack_1048;
  undefined4 uStack_1044;
  uint uStack_1040;
  char cStack_103c;
  undefined3 uStack_103b;
  uint uStack_1038;
  undefined4 uStack_1034;
  uint uStack_1030;
  undefined4 uStack_102c;
  uint uStack_1028;
  char cStack_1024;
  undefined3 uStack_1023;
  uint uStack_1020;
  char cStack_101c;
  undefined3 uStack_101b;
  uint uStack_1018;
  undefined4 uStack_1014;
  uint uStack_1010;
  int iStack_100c;
  undefined4 *puStack_1008;
  undefined1 local_1004 [4];
  undefined4 uStack_1000;
  undefined4 auStack_ffc [2];
  undefined4 uStack_ff4;
  undefined2 uStack_ff0;
  CHAR aCStack_fee [4074];
  int local_4;
  
  local_1004[2] = *param_3;
  local_4 = DAT_00454928;
  local_1004._0_2_ = 0x14;
  local_105c = this;
  if (local_1004[2] != '\0') {
    FUN_004038e0(*(void **)((int)this + 0x118),(ushort)param_1,3,(undefined4 *)local_1004);
    FUN_00435e83(local_4);
    return;
  }
  iVar16 = (param_1 & 0xffff) * 0x23b4;
  pCStack_108c = (LPSTR)0x0;
  puStack_1060 = (undefined4 *)0x0;
  puStack_1070 = (undefined4 *)0x0;
  puStack_1084 = (undefined4 *)0x0;
  puStack_1088 = (undefined4 *)0x0;
  iStack_100c = iVar16;
  FUN_0040ae90((void *)(*(int *)((int)this + 0xd4) + iVar16),(int *)&pCStack_108c,
               (int *)&puStack_1070,(int *)&puStack_1088,(int *)&puStack_1068,(int *)&puStack_107c,
               (int *)&puStack_1060,(int *)&puStack_1084,(int *)&puStack_1078,(int *)&puStack_1074,
               (int *)&puStack_1008,(int *)&puStack_106c);
  uStack_1014 = *(undefined4 *)(param_3 + 1);
  uStack_102c = *(undefined4 *)(param_3 + 5);
  uStack_1034 = *(undefined4 *)(param_3 + 9);
  uStack_1000._3_1_ = param_3[0xd];
  _cStack_103c = CONCAT31(uStack_103b,uStack_1000._3_1_);
  uStack_1044 = *(undefined4 *)(param_3 + 0xe);
  uStack_104c = *(undefined4 *)(param_3 + 0x12);
  uStack_1054 = *(undefined4 *)(param_3 + 0x16);
  uStack_ff0 = *(undefined2 *)(param_3 + 0x1a);
  unique0x10000777 = uStack_1014;
  auStack_ffc[0] = uStack_1044;
  auStack_ffc[1] = uStack_104c;
  uStack_ff4 = uStack_1054;
  lstrcpyA(pCStack_108c,param_3 + 0x1c);
  lstrcpyA(aCStack_fee,pCStack_108c);
  iVar13 = lstrlenA(pCStack_108c);
  iVar14 = lstrlenA(param_3 + 0x1c);
  _cStack_101c = CONCAT31(uStack_101b,param_3[iVar14 + 0x1dU & 0xffff]);
  local_1004[iVar13 + 0x17U & 0xffff] = param_3[iVar14 + 0x1dU & 0xffff];
  cVar1 = param_3[iVar14 + 0x1eU & 0xffff];
  local_1004[iVar13 + 0x18U & 0xffff] = cVar1;
  _cStack_1024 = CONCAT31(uStack_1023,cVar1);
  cVar1 = param_3[iVar14 + 0x1fU & 0xffff];
  local_1004[iVar13 + 0x19U & 0xffff] = cVar1;
  abStack_1064[0] = cVar1;
  uStack_1080 = *(uint *)(param_3 + (iVar14 + 0x20U & 0xffff));
  FUN_0040d3f0((void *)(*(int *)((int)local_105c + 0xd4) + iVar16),abStack_1064,&uStack_1080);
  this_00 = local_105c;
  *(uint *)(local_1004 + (iVar13 + 0x1aU & 0xffff)) = uStack_1080;
  uVar2 = *(undefined2 *)(param_3 + (iVar14 + 0x24U & 0xffff));
  *(undefined2 *)(local_1004 + (iVar13 + 0x1eU & 0xffff)) = uVar2;
  uVar3 = *(ushort *)(param_3 + (iVar14 + 0x26U & 0xffff));
  uStack_1018 = (uint)uVar3;
  *(ushort *)(local_1004 + (iVar13 + 0x20U & 0xffff)) = uVar3;
  uVar4 = *(ushort *)(param_3 + (iVar14 + 0x28U & 0xffff));
  uStack_1030 = (uint)uVar4;
  *(ushort *)(local_1004 + (iVar13 + 0x22U & 0xffff)) = uVar4;
  uVar5 = *(ushort *)(param_3 + (iVar14 + 0x2aU & 0xffff));
  uStack_1010 = (uint)uVar5;
  *(ushort *)(local_1004 + (iVar13 + 0x24U & 0xffff)) = uVar5;
  uVar6 = *(ushort *)(param_3 + (iVar14 + 0x2cU & 0xffff));
  uStack_1038 = (uint)uVar6;
  *(ushort *)(local_1004 + (iVar13 + 0x26U & 0xffff)) = uVar6;
  uVar7 = *(ushort *)(param_3 + (iVar14 + 0x2eU & 0xffff));
  uStack_1020 = (uint)uVar7;
  *(ushort *)(local_1004 + (iVar13 + 0x28U & 0xffff)) = uVar7;
  uVar8 = *(ushort *)(param_3 + (iVar14 + 0x30U & 0xffff));
  uStack_1040 = (uint)uVar8;
  *(ushort *)(local_1004 + (iVar13 + 0x2aU & 0xffff)) = uVar8;
  uVar9 = *(ushort *)(param_3 + (iVar14 + 0x32U & 0xffff));
  uStack_1058 = (uint)uVar9;
  *(ushort *)(local_1004 + (iVar13 + 0x2cU & 0xffff)) = uVar9;
  uVar10 = *(ushort *)(param_3 + (iVar14 + 0x34U & 0xffff));
  uStack_1048 = (uint)uVar10;
  *(ushort *)(local_1004 + (iVar13 + 0x2eU & 0xffff)) = uVar10;
  uVar11 = *(ushort *)(param_3 + (iVar14 + 0x36U & 0xffff));
  uStack_1028 = (uint)uVar11;
  *(ushort *)(local_1004 + (iVar13 + 0x30U & 0xffff)) = uVar11;
  uVar12 = *(ushort *)(param_3 + (iVar14 + 0x38U & 0xffff));
  uStack_1050 = (uint)uVar12;
  *(ushort *)(local_1004 + (iVar13 + 0x32U & 0xffff)) = uVar12;
  local_1004[iVar13 + 0x34U & 0xffff] = param_3[iVar14 + 0x3aU & 0xffff];
  *(undefined4 *)(local_1004 + (iVar13 + 0x35U & 0xffff)) =
       *(undefined4 *)(param_3 + (iVar14 + 0x3bU & 0xffff));
  *(undefined4 *)(local_1004 + (iVar13 + 0x39U & 0xffff)) =
       *(undefined4 *)(param_3 + (iVar14 + 0x3fU & 0xffff));
  pcVar15 = param_3 + (iVar14 + 0x43U & 0xffff);
  puVar18 = puStack_1070;
  for (iVar16 = 0x13; iVar16 != 0; iVar16 = iVar16 + -1) {
    *puVar18 = *(undefined4 *)pcVar15;
    pcVar15 = pcVar15 + 4;
    puVar18 = puVar18 + 1;
  }
  // ... continues with multiple 4-byte copy loops for various arrays ...
  // 19 items, 9 skills, 100 items, 25 entries, etc.
  FUN_0040ac30((void *)(*(int *)((int)local_105c + 0xd4) + iStack_100c),uStack_1014,
               (char)_cStack_101c,(char)_cStack_1024,abStack_1064[0],uStack_1080,uStack_102c,
               uStack_1034,(char)_cStack_103c,uStack_1044,uStack_104c,uStack_1054,uVar2,uVar3,uVar4,
               uVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12);
  FUN_004038e0(*(void **)((int)this_00 + 0x118),(ushort)param_1,(short)iVar13 + 0x69a,
               (undefined4 *)local_1004);
  FUN_0041b8b0(this_00,param_1);
  FUN_00435e83(local_4);
  return;
}
