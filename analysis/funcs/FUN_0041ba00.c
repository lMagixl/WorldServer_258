/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041ba00(void *this,ushort param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  ushort local_180c [2];
  byte local_1808 [4];
  undefined4 local_1804 [256];
  undefined4 local_1404 [256];
  undefined4 local_1004;
  undefined4 local_1000;
  int local_ffc;
  int local_4;
  
  iVar8 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  uVar3 = FUN_0040daf0((void *)(*(int *)((int)this + 0xd4) + iVar8),(int)local_1804,local_1404,
                       '\x01');
  iVar7 = 0;
  if (uVar3 != 0) {
    local_1000 = CONCAT22(local_1000._2_2_,uVar3);
    local_1004._0_2_ = 0;
    local_1004._2_2_ = 0x22;
    uVar5 = 6;
    uVar4 = (uint)uVar3;
    do {
      uVar3 = uVar5 + 4;
      *(undefined4 *)((int)&local_1004 + (uint)uVar5) = *(undefined4 *)((int)local_1804 + iVar7);
      puVar1 = (undefined4 *)((int)local_1404 + iVar7);
      uVar5 = uVar5 + 8;
      iVar7 = iVar7 + 4;
      uVar4 = uVar4 - 1;
      *(undefined4 *)((int)&local_1004 + (uint)uVar3) = *puVar1;
    } while (uVar4 != 0);
    FUN_0041b940(this,DAT_00456030,uVar5,&local_1004);
  }
  pvVar6 = (void *)(*(int *)((int)this + 0xd4) + iVar8);
  if (*(int *)(*(int *)((int)this + 0xd4) + 0x14a4 + iVar8) != 0) {
    if (*(char *)((int)pvVar6 + 0x1440) == '\x02') {
      FUN_0040af90(pvVar6,(undefined1 *)local_180c,local_1808);
      FUN_00405240((void *)((uint)(byte)local_180c[0] * 0x358 + *(int *)((int)this + 0xdc)),
                   local_1808[0]);
    }
    else if (*(char *)((int)pvVar6 + 0x1440) == '\x03') {
      FUN_0040b7d0(pvVar6,local_180c,local_1808);
      if (param_2 != 0) {
        pvVar6 = (void *)((uint)local_180c[0] * 0x3c0 + *(int *)((int)this + 0xe4));
        iVar7 = FUN_0041b860(pvVar6,local_1808[0]);
        if (iVar7 != 0) {
          uVar2 = *(undefined4 *)(*(int *)((int)this + 0xd4) + 0x14a4 + iVar8);
          iVar7 = FUN_00405950(pvVar6,local_1808[0]);
          local_ffc = FUN_0040b900((void *)(*(int *)((int)this + 0xd4) + iVar8),(byte)iVar7);
          local_1004._0_2_ = *(undefined2 *)(*(int *)((int)this + 0xd4) + 0x1488 + iVar8);
          local_1004._2_2_ = 0xc;
          local_1000 = uVar2;
          FUN_0041b940(this,param_1,0xc,&local_1004);
        }
      }
      FUN_004091e0((void *)((uint)local_180c[0] * 0x3c0 + *(int *)((int)this + 0xe4)),local_1808[0])
      ;
    }
    FUN_0040d750((undefined4 *)(*(int *)((int)this + 0xd4) + iVar8));
  }
  FUN_00435e83(local_4);
  return;
}
