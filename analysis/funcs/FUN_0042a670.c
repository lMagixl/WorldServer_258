
void FUN_0042a670(void)

{
  code *pcVar1;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00441248;
  pvStack_c = ExceptionList;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  ExceptionList = &pvStack_c;
  FUN_0040d990(local_50,(undefined4 *)s_deque<T>_too_long_0044c2f4,0x11);
  local_4 = 0;
  FUN_0040dc20(local_34,local_50);
  local_34[0] = &PTR_FUN_0044df98;
  __CxxThrowException_8(local_34,&DAT_0044f704);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* === METADATA ===
SIGNATURE: undefined __stdcall FUN_0042a670(void)
XREFS: 0042ba9b 0042bbfb
CALLEES: FUN_0040d990 __CxxThrowException@8 FUN_0040dc20
CALLERS: FUN_0042ba80 FUN_0042bbe0
SIZE: 694 chars */
