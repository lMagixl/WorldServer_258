
void __thiscall FUN_004247b0(void *this,uint param_1,undefined4 param_2,ushort *param_3)

{
  undefined2 extraout_var;
  void *this_00;
  ushort uVar1;
  void *local_4;
  
  this_00 = (void *)(*(int *)((int)this + 0xd4) + (param_1 & 0xffff) * 0x23b4);
  uVar1 = (ushort)param_1;
  local_4 = this;
  if ((*(int *)((int)this_00 + 0x1460) == 0) || (*(int *)((int)this_00 + 0x14a4) == 0)) {
    FUN_0041eb20(this,uVar1,0x86,'\x01',1);
    return;
  }
  if (*(char *)((int)this_00 + 0x1440) != '\x03') {
    FUN_0041eb20(this,uVar1,0x87,'\x01',1);
    return;
  }
  FUN_0040b7d0(this_00,(undefined2 *)&param_1,(undefined1 *)&local_4);
  if (200 < *param_3) {
    FUN_0041eb20(this,uVar1,0x88,'\x01',1);
    return;
  }
  FUN_00405c00((void *)((param_1 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4)),(byte)local_4,
               CONCAT22(extraout_var,*param_3),(undefined4 *)(param_3 + 1));
  return;
}
