
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00424350(void *this,ushort param_1,undefined4 param_2,byte *param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  ushort local_2010 [2];
  byte local_200c [4];
  undefined4 local_2008;
  undefined2 local_2004;
  undefined2 local_2002;
  undefined4 local_2000;
  int local_1ffc;
  undefined2 local_1004;
  int local_1002;
  int local_4;
  
  iVar3 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  pvVar1 = (void *)(*(int *)((int)this + 0xd4) + iVar3);
  if ((*(int *)((int)pvVar1 + 0x1460) == 0) || (*(int *)((int)pvVar1 + 0x14a4) == 0)) {
    uVar4 = 0x7c;
  }
  else {
    if (*(char *)((int)pvVar1 + 0x1440) == '\x03') {
      FUN_0040b7d0(pvVar1,local_2010,local_200c);
      if (*param_3 < 2) {
        pvVar1 = (void *)((uint)local_2010[0] * 0x3c0 + *(int *)((int)this + 0xe4));
        iVar2 = FUN_0041b860(pvVar1,local_200c[0]);
        if (iVar2 != 0) {
          local_2008 = *(undefined4 *)(*(int *)((int)this + 0xd4) + 0x14a4 + iVar3);
          iVar2 = FUN_00405950(pvVar1,local_200c[0]);
          iVar2 = FUN_0040b900((void *)(*(int *)((int)this + 0xd4) + iVar3),(byte)iVar2);
          local_2004 = *(undefined2 *)(*(int *)((int)this + 0xd4) + 0x1488 + iVar3);
          local_2000 = local_2008;
          local_2002 = 0xc;
          local_1ffc = iVar2;
          FUN_0041b940(this,param_1,0xc,(undefined4 *)&local_2004);
          local_1004 = 0x58;
          local_1002 = iVar2;
          FUN_004038e0(*(void **)((int)this + 0x118),param_1,6,(undefined4 *)&local_1004);
        }
      }
      FUN_00407e00((void *)((uint)local_2010[0] * 0x3c0 + *(int *)((int)this + 0xe4)),local_200c[0])
      ;
      FUN_00435e83(local_4);
      return;
    }
    uVar4 = 0x7d;
  }
  FUN_0041eb20(this,param_1,uVar4,'\x01',1);
  FUN_00435e83(local_4);
  return;
}
