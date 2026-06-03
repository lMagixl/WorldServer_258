
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00428520(void *this,ushort param_1,undefined4 param_2,ushort *param_3)

{
  void *this_00;
  LPCSTR lpString2;
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort local_100c [3];
  undefined1 local_1005;
  ushort local_1004 [2];
  CHAR local_1000 [4092];
  int local_4;
  
  iVar3 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  iVar2 = *(int *)((int)this + 0xd4);
  this_00 = (void *)(iVar2 + iVar3);
  if ((*(int *)(iVar2 + 0x1460 + iVar3) != 0) && (*(int *)((int)this_00 + 0x14a4) != 0)) {
    if (*(char *)((int)this_00 + 0x1440) != '\x03') {
      FUN_0041eb20(this,param_1,0xd7,'\x01',1);
      FUN_00435e83(local_4);
      return;
    }
    uVar1 = *param_3;
    if (*(int *)((uint)uVar1 * 0x23b4 + 0x1460 + iVar2) == 0) {
      FUN_0041eb20(this,param_1,0xd8,'\x01',1);
    }
    else {
      FUN_0040b7d0(this_00,local_100c,&local_1005);
      lpString2 = (LPCSTR)(*(int *)((int)this + 0xd4) + 0x14a8 + iVar3);
      local_1004[0] = 0x72;
      local_1004[1] = param_1;
      lstrcpyA(local_1000,lpString2);
      iVar2 = lstrlenA(lpString2);
      *(ushort *)((int)local_1004 + (iVar2 + 5U & 0xffff)) = local_100c[0];
      iVar3 = FUN_00406a80((void *)((uint)local_100c[0] * 0x3c0 + *(int *)((int)this + 0xe4)),
                           (undefined1 *)((int)local_1004 + (iVar2 + 7U & 0xffff)));
      FUN_004038e0(*(void **)((int)this + 0x118),uVar1,(short)(iVar2 + 7U) + (short)iVar3,
                   (undefined4 *)local_1004);
    }
    FUN_00435e83(local_4);
    return;
  }
  FUN_0041eb20(this,param_1,0xd6,'\x01',1);
  FUN_00435e83(local_4);
  return;
}


