
void __thiscall FUN_0041fb30(void *this,ushort param_1)

{
  uint uVar1;
  int iVar2;
  CHAR local_84 [128];
  int local_4;
  
  local_4 = DAT_00454928;
  iVar2 = (uint)param_1 * 0x23b4;
  if (*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar2) == 0) {
    FUN_0041eb20(this,param_1,0x1a,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  uVar1 = FUN_0040bbb0(*(int *)((int)this + 0xd4) + iVar2);
  if (90000 < uVar1) {
    wsprintfA(local_84,s___04u__ALTO__u_0044bfa4,(uint)param_1,uVar1 / 1000);
    FUN_0041d380(this,local_84,*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar2));
  }
  FUN_00435e83(local_4);
  return;
}


