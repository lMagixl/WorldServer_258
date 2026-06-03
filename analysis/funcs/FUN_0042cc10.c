
void __thiscall FUN_0042cc10(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  
  if (((*(int *)((int)this + 0xc) + *(int *)((int)this + 0x10) & 1U) == 0) &&
     (*(uint *)((int)this + 8) <= *(int *)((int)this + 0x10) + 2U >> 1)) {
    FUN_0042ba80(this,1);
  }
  uVar4 = *(int *)((int)this + 0xc) + *(int *)((int)this + 0x10);
  uVar3 = uVar4 >> 1;
  if (*(uint *)((int)this + 8) <= uVar3) {
    uVar3 = uVar3 - *(uint *)((int)this + 8);
  }
  if (*(int *)(*(int *)((int)this + 4) + uVar3 * 4) == 0) {
    pvVar2 = operator_new(0x10);
    *(void **)(*(int *)((int)this + 4) + uVar3 * 4) = pvVar2;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)((int)this + 4) + uVar3 * 4) + (uVar4 & 1) * 8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
  }
  *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
  return;
}



/* === METADATA ===
SIGNATURE: undefined __thiscall FUN_0042cc10(void * this, undefined4 * param_1)
XREFS: 0042cd35
CALLEES: FUN_0042ba80 operator_new
CALLERS: FUN_0042cd20
SIZE: 949 chars */
