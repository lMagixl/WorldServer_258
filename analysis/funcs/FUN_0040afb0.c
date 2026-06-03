/* == COPY PLAYER INFO FOR CHANNEL PACKET ==
   Copies player name + class + master flag to output buffer.
   Used when building ChannelEnter/ChannelCharacterState packets. */

int __thiscall FUN_0040afb0(void *this,LPSTR param_1)

{
  int iVar1;
  
  lstrcpyA(param_1,(LPCSTR)((int)this + 0x14a8));
  iVar1 = lstrlenA((LPCSTR)((int)this + 0x14a8));
  param_1[iVar1 + 1U & 0xffff] = *(CHAR *)((int)this + 0x1531);
  param_1[iVar1 + 2U & 0xffff] = *(CHAR *)((int)this + 0x146c);
  *(undefined4 *)(param_1 + (iVar1 + 3U & 0xffff)) = *(undefined4 *)((int)this + 0x14d0);
  return iVar1 + 7;
}
