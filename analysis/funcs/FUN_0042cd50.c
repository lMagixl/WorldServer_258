
void __thiscall FUN_0042cd50(void *this,undefined4 *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x14));
  FUN_0042cc90(this,param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x14));
  return;
}



/* === METADATA ===
SIGNATURE: undefined __thiscall FUN_0042cd50(void * this, undefined4 * param_1)
XREFS: 0042cdf9 0042ce3c
CALLEES: EnterCriticalSection LeaveCriticalSection FUN_0042cc90
CALLERS: FUN_0042cd80
SIZE: 246 chars */
