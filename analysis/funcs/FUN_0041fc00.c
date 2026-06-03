
void __thiscall FUN_0041fc00(void *this,ushort param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  CHAR local_104 [256];
  int local_4;
  
  iVar2 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  iVar1 = FUN_0040a9c0((void *)(*(int *)((int)this + 0xd4) + iVar2),param_3);
  if (iVar1 != 0) {
    wsprintfA(local_104,s___04u__GMGD__u_0044bfb4,(uint)param_1,iVar1);
    FUN_0041d380(this,local_104,*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar2));
    FUN_0040aa00((void *)(*(int *)((int)this + 0xd4) + iVar2),&uStack_10c,&uStack_114,&uStack_11c,
                 &uStack_124,&uStack_108,&uStack_118,&uStack_110,&uStack_120);
    FUN_0041eb20(this,param_1,0x18,'\x01',1);
  }
  FUN_00435e83(local_4);
  return;
}


