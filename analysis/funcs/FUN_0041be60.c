
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041be60(void *this,ushort param_1)

{
  void *this_00;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_1010 [6];
  undefined4 local_100a [7];
  undefined4 local_fee [1016];
  int local_c;
  
  local_c = DAT_00454928;
  puVar2 = (undefined4 *)local_1010;
  for (iVar1 = 0x400; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_1010._2_4_ = *(undefined4 *)((int)this + 4);
  local_1010._0_2_ = 0x77;
  puVar2 = (undefined4 *)((int)this + 8);
  puVar3 = local_100a;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x24);
  puVar3 = local_fee;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  this_00 = *(void **)((int)this + 0x118);
  *(undefined2 *)puVar3 = *(undefined2 *)puVar2;
  FUN_004038e0(this_00,param_1,0x4c,(undefined4 *)local_1010);
  FUN_00435e83(local_c);
  return;
}


