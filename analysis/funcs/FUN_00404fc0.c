/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00404fc0(void *this,LPCSTR param_1,ushort param_2,int param_3,byte *param_4)

{
  void *this_00;
  int iVar1;
  byte bVar2;
  void *this_01;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  ushort uVar7;
  ushort local_1004;
  char local_1002;
  byte local_1001;
  undefined2 local_1000;
  CHAR local_ffe [4090];
  int local_4;
  
  local_4 = DAT_00454928;
  this_01 = (void *)FUN_0042aad0();
  iVar1 = *(int *)((int)this_01 + 0xd4);
  local_1004 = 0x1f;
  if (*(char *)((int)this + 1) == '\0') {
    local_1002 = '\x01';
  }
  else if (*(byte *)((int)this + 0x35) < *(byte *)((int)this + 0x34)) {
    if ((*(char *)((int)this + 0x2b) == '\0') ||
       (iVar3 = lstrcmpA((LPCSTR)((int)this + 0x2b),param_1), iVar3 == 0)) {
      local_1002 = '\0';
    }
    else {
      local_1002 = '\x03';
    }
  }
  else {
    local_1002 = '\x02';
  }
  if (local_1002 != '\0') {
    if (param_3 == 0) {
      FUN_0041b8a0(this_01,param_2,3,(undefined4 *)&local_1004);
    }
    FUN_00435e83(local_4);
    return;
  }
  bVar2 = 0;
  do {
    if (*(int *)((int)this + (uint)bVar2 * 8 + 0x3c) == 0) {
      *(char *)((int)this + 0x35) = *(char *)((int)this + 0x35) + '\x01';
      *(ushort *)((int)this + (uint)bVar2 * 8 + 0x38) = param_2;
      *(undefined4 *)((int)this + (uint)bVar2 * 8 + 0x3c) = 1;
      *param_4 = bVar2;
      break;
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 < 100);
  local_1001 = *param_4;
  local_1000 = *(undefined2 *)((int)this + (uint)local_1001 * 8 + 0x38);
  this_00 = (void *)((uint)param_2 * 0x23b4 + iVar1);
  iVar3 = FUN_0040afb0(this_00,local_ffe);
  uVar7 = (short)iVar3 + 6;
  FUN_00404ef0(this,uVar7,(undefined4 *)&local_1004);
  FUN_0041b8a0(this_01,param_2,uVar7,(undefined4 *)&local_1004);
  local_1002 = *(char *)this;
  local_1001 = *(undefined1 *)((int)this + 0x35);
  local_1004 = 0x1e;
  local_1000 = CONCAT11(local_1000._1_1_,*(undefined1 *)((int)this + 0x36));
  lstrcpyA((LPSTR)((int)&local_1000 + 1),(LPCSTR)((int)this + 2));
  iVar3 = lstrlenA((LPCSTR)((int)this + 2));
  lstrcpyA((LPSTR)((int)&local_1004 + (iVar3 + 6U & 0xffff)),(LPCSTR)((int)this + 0x2b));
  iVar4 = lstrlenA((LPCSTR)((int)this + 0x2b));
  bVar2 = 0;
  uVar6 = iVar3 + 7 + iVar4;
  puVar5 = (ushort *)((int)this + 0x38);
  do {
    if (*(int *)(puVar5 + 2) != 0) {
      uVar7 = *puVar5;
      *(byte *)((int)&local_1004 + (uVar6 & 0xffff)) = bVar2;
      *(ushort *)((int)&local_1004 + (uVar6 + 1 & 0xffff)) = uVar7;
      iVar3 = FUN_0040afb0((void *)((uint)uVar7 * 0x23b4 + iVar1),
                           (LPSTR)((int)&local_1004 + (uVar6 + 3 & 0xffff)));
      uVar6 = uVar6 + 3 + iVar3;
    }
    bVar2 = bVar2 + 1;
    puVar5 = puVar5 + 4;
  } while (bVar2 < 100);
  FUN_0041b8a0(this_01,param_2,(ushort)uVar6,(undefined4 *)&local_1004);
  FUN_0040b670((int)this_00);
  FUN_00435e83(local_4);
  return;
}
