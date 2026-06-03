
// Opcode 0x02 — Server Info Response
// Signature: void __thiscall FUN_0041ef00(void* this, ushort fieldIdx)
// Builds server info packet with: state flags, server name, auth URL, etc.
// Checks field state >= 4 before responding.

void __thiscall FUN_0041ef00(void *this,ushort param_1)
{
  uint uVar1;
  CHAR *pCVar2;
  void *this_00;
  int iVar3;
  int iVar4;
  CHAR local_1004 [3];
  undefined2 local_1001;
  undefined2 local_fff;
  undefined2 local_ffd;
  undefined4 local_ffb;
  undefined4 local_ff7;
  CHAR local_ff3 [4079];
  int local_4;

  local_4 = DAT_00454928;
  iVar4 = (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4);
  if (*(byte *)(iVar4 + 0x1440) < 4) {
    FUN_0041eb20(this,param_1,8,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  FUN_0040bbb0(iVar4);
  local_ffd = *(undefined2 *)((int)this + 0xd2);
  local_1004[2] = *(int *)((int)this + 0x50) != 0;
  local_fff = *(undefined2 *)((int)this + 0xe0);
  local_1001 = *(undefined2 *)((int)this + 0x6c);
  local_ffb = *(undefined4 *)((int)this + 0x124);
  local_ff7 = *(undefined4 *)((int)this + 0x128);
  local_1004[0] = '\x02';
  local_1004[1] = '\0';
  lstrcpyA(local_ff3,(LPCSTR)((int)this + 300));
  iVar4 = lstrlenA((LPCSTR)((int)this + 300));
  lstrcpyA(local_1004 + (iVar4 + 0x12U & 0xffff),(LPCSTR)((int)this + 0x14d));
  iVar3 = lstrlenA((LPCSTR)((int)this + 0x14d));
  uVar1 = iVar4 + 0x13 + iVar3;
  pCVar2 = local_1004 + (uVar1 & 0xffff);
  pCVar2[0] = '\0'; pCVar2[1] = '\0'; pCVar2[2] = '\0'; pCVar2[3] = '\0';
  pCVar2 = local_1004 + (uVar1 + 4 & 0xffff);
  pCVar2[0] = '\0'; pCVar2[1] = '\0'; pCVar2[2] = '\0'; pCVar2[3] = '\0';
  pCVar2 = local_1004 + (uVar1 + 8 & 0xffff);
  pCVar2[0] = '\0'; pCVar2[1] = '\0'; pCVar2[2] = '\0'; pCVar2[3] = '\0';
  pCVar2 = local_1004 + (uVar1 + 0xc & 0xffff);
  pCVar2[0] = '\0'; pCVar2[1] = '\0'; pCVar2[2] = '\0'; pCVar2[3] = '\0';
  this_00 = *(void **)((int)this + 0x118);
  pCVar2 = local_1004 + (uVar1 + 0x10 & 0xffff);
  pCVar2[0] = '\0'; pCVar2[1] = '\0'; pCVar2[2] = '\0'; pCVar2[3] = '\0';
  FUN_004038e0(this_00,param_1,(short)uVar1 + 0x14,(undefined4 *)local_1004);
  FUN_00435e83(local_4);
  return;
}
