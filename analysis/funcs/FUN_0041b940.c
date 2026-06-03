/* == DB SEND QUEUE PUSH ==
   Pushes data to the DB send queue.
   Wakes DBWorker thread via SetEvent.
   Increments session transaction counter. */

void __thiscall FUN_0041b940(void *this,ushort param_1,ushort param_2,undefined4 *param_3)

{
  short *psVar1;
  int iVar2;
  
  if (*(int *)((int)this + 0x5368) == 1) {
    iVar2 = FUN_0042e630(*(void **)((int)this + 0xfc),param_1,param_2,param_3);
    while (iVar2 == 0) {
      InterlockedIncrement((LONG *)((int)this + 0x51dc));
      *(undefined4 *)((int)this + 0x59cc) = 0x23;
      Sleep(10);
      *(undefined4 *)((int)this + 0x59cc) = 0x24;
      iVar2 = FUN_0042e630(*(void **)((int)this + 0xfc),param_1,param_2,param_3);
    }
  }
  else {
    FUN_0042e720(*(void **)((int)this + 0xfc),param_1,param_2,param_3);
  }
  SetEvent(*(HANDLE *)((int)this + 0xf4));
  if (param_1 < DAT_00456030) {
    psVar1 = (short *)((uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4) + 0x1488);
    *psVar1 = *psVar1 + 1;
  }
  return;
}
