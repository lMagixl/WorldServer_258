
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_004222a0(void *this,ushort param_1,uint param_2,undefined4 *param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  ushort uVar6;
  char local_2045;
  int local_2044;
  IPv4Address local_2040 [8];
  int local_2038;
  IPv4Address local_2034 [8];
  undefined4 local_202c;
  char local_2028 [4];
  undefined1 local_2024;
  undefined1 local_2020 [7];
  undefined4 local_2019;
  undefined2 local_1020;
  undefined2 local_101e;
  undefined4 local_101c;
  undefined4 local_1018 [1023];
  int local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00441216;
  local_14 = ExceptionList;
  iVar4 = (uint)param_1 * 0x23b4;
  local_1c = DAT_00454928;
  iVar2 = *(int *)((int)this + 0xd4) + iVar4;
  pvStack_18 = this;
  if ((*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar4) == 0) ||
     (*(int *)(iVar2 + 0x14a4) == 0)) {
    uVar6 = 0xe5;
  }
  else {
    if (*(char *)(iVar2 + 0x1440) == '\x02') {
      ExceptionList = &local_14;
      FUN_0042fe20(local_2040,local_2020);
      local_c = 0;
      FUN_0042fe60(local_2040,0x75);
      FUN_0042fe20(local_2034,param_3);
      local_c = CONCAT31(local_c._1_3_,1);
      FUN_0042fe40(local_2034,&local_2045);
      if (local_2045 == '\0') {
        if (*(uint *)(iVar4 + 0x1538 + *(int *)((int)this + 0xd4)) < 1000) goto LAB_0042241b;
LAB_004223a2:
        local_2028[2] = *(undefined1 *)((int)param_3 + 3);
        local_2028[1] = *(undefined1 *)((int)param_3 + 2);
        local_2028[0] = *(char *)((int)param_3 + 1);
        local_2028[3] = *(char *)(param_3 + 1);
        local_2024 = *(undefined1 *)((int)param_3 + 5);
        FUN_0042f280(s__RW____NetworkMessageBuyLotto_____0044c0c4);
        local_202c = (int)&local_202c + 3;
        bVar1 = false;
        local_2044 = 1;
        local_2038 = 4;
        do {
          if (local_2044 < 5) {
            iVar2 = local_2044;
            do {
              if (*(char *)(local_202c + local_2044) == local_2028[iVar2]) {
                FUN_0042f280(s__RW____NetworkMessageBuyLotto_____0044c044);
                bVar1 = true;
                break;
              }
              iVar2 = iVar2 + 1;
            } while (iVar2 < 5);
          }
          local_2044 = local_2044 + 1;
          local_2038 = local_2038 + -1;
        } while (local_2038 != 0);
        if (bVar1) {
          FUN_0042f280(s__RW____NetworkMessageBuyLotto_____0044c00c);
          iVar4 = *(int *)((int)this + 0xd4) + iVar4;
          local_2020[2] = 2;
          local_2020._3_4_ = *(undefined4 *)(iVar4 + 0x1538);
          local_2019 = *(undefined4 *)(iVar4 + 0x153c);
          FUN_004038e0(*(void **)((int)this + 0x118),param_1,0xb,(undefined4 *)local_2020);
        }
        else {
          local_1020 = *(undefined2 *)(*(int *)((int)this + 0xd4) + 0x1488 + iVar4);
          local_101c = *(undefined4 *)(*(int *)((int)this + 0xd4) + iVar4 + 0x1460);
          local_101e = 0x29;
          puVar5 = local_1018;
          for (uVar3 = (param_2 & 0xffff) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar5 = *param_3;
            param_3 = param_3 + 1;
            puVar5 = puVar5 + 1;
          }
          for (uVar3 = param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar5 = *(undefined1 *)param_3;
            param_3 = (undefined4 *)((int)param_3 + 1);
            puVar5 = (undefined4 *)((int)puVar5 + 1);
          }
          FUN_0041b940(this,param_1,(short)param_2 + 8,(undefined4 *)&local_1020);
        }
      }
      else if (local_2045 == '\x01') {
        if (99 < *(uint *)(iVar4 + 0x153c + *(int *)((int)this + 0xd4))) goto LAB_004223a2;
LAB_0042241b:
        FUN_0042f280(s__RW____NetworkMessageBuyLotto_____0044c080);
        iVar4 = iVar4 + *(int *)((int)this + 0xd4);
        local_2020[2] = 1;
        local_2020._3_4_ = *(undefined4 *)(iVar4 + 0x1538);
        local_2019 = *(undefined4 *)(iVar4 + 0x153c);
        FUN_004038e0(*(void **)((int)this + 0x118),param_1,0xb,(undefined4 *)local_2020);
      }
      else {
        FUN_0041eb20(this,param_1,0xe7,'\x01',1);
      }
      local_c = local_c & 0xffffff00;
      PerfLib::IPv4Address::~IPv4Address(local_2034);
      local_c = 0xffffffff;
      PerfLib::IPv4Address::~IPv4Address(local_2040);
      goto LAB_004225ab;
    }
    uVar6 = 0xe6;
  }
  ExceptionList = &local_14;
  FUN_0041eb20(this,param_1,uVar6,'\x01',1);
LAB_004225ab:
  ExceptionList = local_14;
  FUN_00435e83(local_1c);
  return;
}


