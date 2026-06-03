
void __thiscall FUN_00425cc0(void *this,uint param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  void *pvVar2;
  void *local_4;
  
  pvVar2 = (void *)((param_1 & 0xffff) * 0x23b4 + *(int *)((int)this + 0xd4));
  local_4 = this;
  if ((*(int *)((int)pvVar2 + 0x1460) == 0) || (*(int *)((int)pvVar2 + 0x14a4) == 0)) {
    FUN_0041eb20(this,(ushort)param_1,0xb1,'\x01',1);
  }
  else {
    if (*(char *)((int)pvVar2 + 0x1440) != '\x03') {
      FUN_0041eb20(this,(ushort)param_1,0xb2,'\x01',1);
      return;
    }
    FUN_0040b7d0(pvVar2,(undefined2 *)&param_1,(undefined1 *)&local_4);
    iVar1 = (param_1 & 0xffff) * 0x3c0;
    pvVar2 = (void *)(*(int *)((int)this + 0xe4) + iVar1);
    if (((char)local_4 == *(char *)(*(int *)((int)this + 0xe4) + 0x122 + iVar1)) ||
       ((char)local_4 == *(char *)((int)pvVar2 + 0x123))) {
      local_4 = (void *)CONCAT31(local_4._1_3_,*param_3);
      FUN_00405ef0(pvVar2,*param_3,*(undefined2 *)(param_3 + 1));
      return;
    }
  }
  return;
}
