
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00424b60(void *this,uint param_1,undefined4 param_2,uint *param_3)

{
  void *this_00;
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  byte local_20d9;
  undefined1 local_20d8 [4];
  uint local_20d4;
  undefined1 local_20d0;
  undefined3 uStack_20cf;
  undefined2 local_20cc [2];
  uint local_20c8;
  byte local_20c4 [4];
  uint local_20c0;
  uint local_20bc;
  undefined4 local_20b8;
  undefined4 local_20b4;
  undefined4 local_20b0;
  undefined4 local_20ac;
  undefined4 local_20a8;
  undefined4 local_20a4;
  undefined4 local_20a0;
  uint local_209c;
  undefined4 local_2098;
  undefined4 local_2094;
  undefined4 local_2090;
  undefined4 local_208c;
  undefined4 local_2088;
  CHAR local_2084 [128];
  undefined2 local_2004;
  undefined2 local_2002;
  undefined4 local_2000;
  uint local_1ffc;
  undefined4 local_1ff8;
  byte local_1ff4;
  undefined4 local_1ff3;
  undefined4 local_1fef;
  undefined4 local_1feb;
  undefined4 local_1fe7;
  undefined2 local_1fe3;
  undefined4 local_1fe1;
  undefined4 local_1fdd;
  undefined4 local_1fd9;
  undefined2 local_1fd5;
  undefined1 local_1fd3;
  undefined4 local_1fd2;
  undefined4 local_1fce;
  undefined4 local_1fca;
  undefined1 local_1fc6;
  undefined1 local_1fc5;
  undefined2 local_1004;
  byte local_1002;
  undefined1 local_1001 [3];
  undefined1 local_ffe;
  int local_4;
  
  iVar4 = (param_1 & 0xffff) * 0x23b4;
  local_4 = DAT_00454928;
  this_00 = (void *)(*(int *)((int)this + 0xd4) + iVar4);
  uVar6 = (ushort)param_1;
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    FUN_0041eb20(this,uVar6,0x93,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(char *)((int)this_00 + 0x1440) != '\x03') {
    FUN_0041eb20(this,uVar6,0x94,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  FUN_0040b7d0(this_00,(undefined2 *)&local_20d4,local_20c4);
  iVar2 = *(int *)((int)this + 0xe4) + (local_20d4 & 0xffff) * 0x3c0;
  if (*(char *)(iVar2 + 0x119) != '\0') {
    if ((*(char *)(iVar2 + 8) == '\x02') && (*(char *)(iVar2 + 0x2b4) == '\x02')) {
      local_20c8 = param_3[1];
      uVar5 = *param_3;
      _local_20d0 = CONCAT31(uStack_20cf,(char)param_3[2]);
      uVar1 = local_20c0 >> 8;
      local_20c0 = local_20c0 & 0xffffff00;
      if (*(int *)(*(int *)((int)this + 0xd4) + 0x236c + iVar4) != 0) {
        uVar5 = uVar5 * 3 >> 1;
        local_20c0 = CONCAT31((int3)uVar1,1);
      }
      local_20bc = uVar5;
      FUN_0041d0d0(this,uVar6,(ushort)local_20d4,(char)local_20c0,uVar5,local_20c8,(char)param_3[2])
      ;
      iVar2 = FUN_0041cf80(this,&param_1,(ushort *)&local_20d4,&local_20c0,&local_20bc,&local_20c8);
      if (iVar2 == 1) {
        wsprintfA(local_2084,s_Wrong_Game_Point__Exp____u__Gold_0044c104,uVar5,local_20c8);
        FUN_0041d380(this,local_2084,*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar4));
        FUN_0041eb20(this,uVar6,0x97,'\x01',1);
      }
      else {
        FUN_0041d290(this,uVar6,(ushort)local_20d4,local_20c4[0],uVar5,local_20c8,(char)_local_20d0)
        ;
        FUN_004061c0((void *)((local_20d4 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4)),
                     local_20c4[0],uVar5);
        iVar2 = FUN_0040d300((void *)(*(int *)((int)this + 0xd4) + iVar4),uVar5,(int *)&local_20c8,
                             &local_20d9,&local_20ac,local_20cc);
        if (iVar2 != 0) {
          local_1001._0_2_ = local_20cc[0];
          local_1004 = 0x51;
          local_1002 = local_20d9;
          FUN_004038e0(*(void **)((int)this + 0x118),uVar6,5,(undefined4 *)&local_1004);
        }
        local_209c = *(uint *)((int)param_3 + 9);
        local_2098 = *(undefined4 *)((int)param_3 + 0xd);
        local_2094 = *(undefined4 *)((int)param_3 + 0x11);
        local_20b4 = 0;
        local_20b8 = 0;
        local_20b0 = 0;
        local_20d8._0_3_ = 0;
        iVar3 = FUN_0040b940((void *)(*(int *)((int)this + 0xd4) + iVar4),&local_209c,
                             (int)&local_20b8,local_20d8,(int)&local_2090);
        if (iVar3 != 0 || iVar2 != 0) {
          local_1002 = local_20c4[0];
          local_ffe = local_20d8[2];
          local_1004 = 0x52;
          local_1001._1_2_ = local_20d8._0_2_;
          local_1001[0] = local_20d9;
          FUN_004061f0((void *)((local_20d4 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4)),7,
                       (undefined4 *)&local_1004);
        }
        if (*(short *)((int)param_3 + 0x15) == 0) {
          _local_20d0 = CONCAT31(uStack_20cf,3);
        }
        else {
          uVar5 = FUN_00405980((void *)((local_20d4 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4)),
                               local_20c4[0]);
          _local_20d0 = CONCAT31(uStack_20cf,(char)uVar5);
        }
        FUN_0040bb60((void *)(*(int *)((int)this + 0xd4) + iVar4),(char)_local_20d0,&local_20a0,
                     &local_20a4,&local_20a8);
        local_2000 = *(undefined4 *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar4);
        iVar4 = *(int *)((int)this + 0xd4) + iVar4;
        local_1ff8 = *(undefined4 *)(iVar4 + 0x14a4);
        local_2004 = *(undefined2 *)(iVar4 + 0x1488);
        local_1ffc = local_20c8;
        local_1fef = local_20a0;
        local_1fe3 = local_20cc[0];
        local_1ff4 = local_20d9;
        local_1ff3 = local_20ac;
        local_1fd9 = local_20b0;
        local_1feb = local_20a4;
        local_1fe7 = local_20a8;
        local_1fd2 = local_2090;
        local_1fe1 = local_20b8;
        local_1fdd = local_20b4;
        local_1fd5 = local_20d8._0_2_;
        local_1fd3 = local_20d8[2];
        local_2002 = 10;
        local_1fce = local_208c;
        local_1fca = local_2088;
        local_1fc6 = 0;
        local_1fc5 = 0;
        FUN_0041b940(this,uVar6,0x40,(undefined4 *)&local_2004);
      }
    }
    FUN_00435e83(local_4);
    return;
  }
  FUN_0041eb20(this,uVar6,0x95,'\x01',1);
  FUN_00435e83(local_4);
  return;
}
