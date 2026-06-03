
void __thiscall FUN_00423ad0(void *this,uint param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  void *this_00;
  void *local_4;
  
  this_00 = (void *)((param_1 & 0xffff) * 0x23b4 + *(int *)((int)this + 0xd4));
  local_4 = this;
  if ((*(int *)((int)this_00 + 0x1460) != 0) && (*(int *)((int)this_00 + 0x14a4) != 0)) {
    if (*(char *)((int)this_00 + 0x1440) != '\x03') {
      FUN_0041eb20(this,(ushort)param_1,0x61,'\x01',1);
      return;
    }
    FUN_0040b7d0(this_00,(undefined2 *)&param_1,(undefined1 *)&local_4);
    cVar1 = *param_3;
    param_3 = (char *)CONCAT31(param_3._1_3_,cVar1);
    FUN_00407520((void *)((param_1 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4)),(byte)local_4,
                 cVar1);
    return;
  }
  FUN_0041eb20(this,(ushort)param_1,0x60,'\x01',1);
  return;
}
