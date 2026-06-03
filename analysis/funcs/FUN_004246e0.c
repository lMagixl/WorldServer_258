
void __thiscall FUN_004246e0(void *this,uint param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  void *pvVar2;
  ushort uVar3;
  void *local_4;
  
  pvVar2 = (void *)(*(int *)((int)this + 0xd4) + (param_1 & 0xffff) * 0x23b4);
  uVar3 = (ushort)param_1;
  local_4 = this;
  if ((*(int *)((int)pvVar2 + 0x1460) == 0) || (*(int *)((int)pvVar2 + 0x14a4) == 0)) {
    FUN_0041eb20(this,uVar3,0x83,'\x01',1);
    return;
  }
  if (*(char *)((int)pvVar2 + 0x1440) != '\x03') {
    FUN_0041eb20(this,uVar3,0x84,'\x01',1);
    return;
  }
  FUN_0040b7d0(pvVar2,(undefined2 *)&local_4,(undefined1 *)&param_1);
  pvVar2 = (void *)(((uint)local_4 & 0xffff) * 0x3c0 + *(int *)((int)this + 0xe4));
  if ((char)param_1 != *(char *)((int)pvVar2 + 0x121)) {
    FUN_0041eb20(this,uVar3,0x85,'\x01',1);
    return;
  }
  cVar1 = *param_3;
  param_3 = (char *)CONCAT31(param_3._1_3_,cVar1);
  FUN_00405a90(pvVar2,cVar1);
  return;
}
