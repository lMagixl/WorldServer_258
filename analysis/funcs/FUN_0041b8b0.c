/* == POST-SELECT CHANNEL FINDER ==
   Called after character select to find and enter a channel.
   Iterates CChannel array to find an available channel slot. */

void __thiscall FUN_0041b8b0(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  
  uVar1 = param_1;
  bVar3 = 0;
  if (*(char *)((int)this + 0xd8) != '\0') {
    bVar3 = 0;
    do {
      iVar2 = FUN_00404fc0((void *)((uint)bVar3 * 0x358 + *(int *)((int)this + 0xdc)),(LPCSTR)0x0,
                           (ushort)uVar1,1,(byte *)&param_1);
      if (iVar2 != 0) break;
      bVar3 = bVar3 + 1;
    } while (bVar3 < *(byte *)((int)this + 0xd8));
  }
  if (bVar3 < *(byte *)((int)this + 0xd8)) {
    FUN_0040af60((void *)((uVar1 & 0xffff) * 0x23b4 + *(int *)((int)this + 0xd4)),bVar3,
                 (char)param_1);
  }
  return;
}
