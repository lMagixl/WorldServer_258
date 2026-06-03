
undefined4 __thiscall
FUN_0041cf80(void *this,undefined4 param_1,ushort *param_2,undefined4 param_3,uint *param_4,
            uint *param_5)

{
  char cVar1;
  int iVar2;
  ushort *puVar3;
  
  iVar2 = (uint)*param_2 * 0x3c0;
  cVar1 = *(char *)(iVar2 + 0x119 + *(int *)((int)this + 0xe4));
  if (cVar1 == '\0') {
    param_2 = (ushort *)(uint)*(ushort *)((int)this + 0x52b8);
    puVar3 = (ushort *)(uint)*(ushort *)((int)this + 0x52bc);
  }
  else if ((cVar1 == '\x02') || (cVar1 == '\x04')) {
    param_2 = (ushort *)(uint)*(ushort *)((int)this + 0x52c0);
    puVar3 = (ushort *)(uint)*(ushort *)((int)this + 0x52c4);
  }
  else if (cVar1 == '\x03') {
    param_2 = (ushort *)(uint)*(ushort *)((int)this + 0x52c8);
    puVar3 = (ushort *)(uint)*(ushort *)((int)this + 0x52cc);
  }
  else {
    puVar3 = param_2;
    if (cVar1 == '\x01') {
      if (*(char *)(iVar2 + *(int *)((int)this + 0xe4) + 700) ==
          *(char *)(iVar2 + 0x11a + *(int *)((int)this + 0xe4))) {
        param_2 = (ushort *)(uint)*(ushort *)((int)this + 0x52d0);
        puVar3 = (ushort *)(uint)*(ushort *)((int)this + 0x52d4);
      }
      else {
        param_2 = (ushort *)(uint)*(ushort *)((int)this + 0x52d8);
        puVar3 = (ushort *)(uint)*(ushort *)((int)this + 0x52dc);
      }
    }
  }
  if ((*param_4 <= ((uint)param_2 & 0xffff)) && (*param_5 <= ((uint)puVar3 & 0xffff))) {
    return 0;
  }
  return 1;
}


