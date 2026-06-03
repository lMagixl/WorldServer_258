
void __fastcall FUN_00429a70(int param_1)

{
  void *_Memory;
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  while (iVar1 != 0) {
    if ((*(int *)(param_1 + 0x10) != 0) &&
       (iVar1 = *(int *)(param_1 + 0x10) + -1, *(int *)(param_1 + 0x10) = iVar1, iVar1 == 0)) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    iVar1 = *(int *)(param_1 + 0x10);
  }
  iVar1 = *(int *)(param_1 + 8);
  while (iVar1 != 0) {
    _Memory = *(void **)(*(int *)(param_1 + 4) + -4 + iVar1 * 4);
    iVar1 = iVar1 + -1;
    if (_Memory != (void *)0x0) {
      _free(_Memory);
    }
  }
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    _free(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



/* === METADATA ===
SIGNATURE: undefined __fastcall FUN_00429a70(int param_1)
XREFS: 00433be7 00433c0a 00433c2b 0042a7d7 0042a7f0 004346bb 0043485b 004346ea 0043488a 00433a23
CALLEES: _free
CALLERS: FUN_0042a780 ~AsyncWebRequest Catch@004346b8 Catch@00434858 FUN_004346d0 FUN_00434870 ~Queue<class_PerfLib::MemoryPool<32>::Block*>
SIZE: 783 chars */
