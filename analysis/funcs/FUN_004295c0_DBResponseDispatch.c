// DB Response Dispatch (FUN_004295c0)
// Procesa entradas de DbRecvQueue (this+0xF8)
// Diferente del game dispatcher (FUN_0042ab40) — NO es el mismo switch
// Signature: void __thiscall FUN_004295c0(void* this, uint fieldIdx, ushort subOpcode, int dataLen, int dataPtr)
// Switch en param_2 (subOpcode = s_w2 del response)

void __thiscall FUN_004295c0(void *this,uint param_1,ushort param_2,int param_3,int param_4)
{
  *(uint *)((int)this + 0x59d4) = (uint)param_2;
  uVar2 = (ushort)param_1;
  switch((uint)param_2) {
  case 1:  FUN_004261d0(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break; // auth dupe check
  case 2:  FUN_00426b30(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break; // login response
  case 3:  FUN_00426290(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break; // char data
  case 7:  FUN_0041c3d0(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 8:  FUN_00427570(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 9:  FUN_0041c4d0(this,param_1,param_3 + -2,(char *)(param_4 + 2)); break;
  case 10: FUN_0041cb20(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0xb: FUN_0041cb60(this,uVar2,param_3 + -2,(undefined1 *)(param_4 + 2)); break;
  case 0xd: FUN_0041cbe0(this,uVar2,param_3 + -2,(undefined1 *)(param_4 + 2)); break;
  case 0x10: FUN_00427760(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x11: FUN_004278d0(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x12: FUN_00427a80(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x13: FUN_0041cca0(this,uVar2); break;
  case 0x14: FUN_00427b10(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x15: FUN_0041cd20(this,uVar2,param_3 - 2,(char *)(param_4 + 2)); break;
  case 0x16: FUN_00427eb0(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x17: FUN_004281b0(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x18: FUN_00428030(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x1b: FUN_0041ce00(this,uVar2,param_3 + -2,(undefined4 *)(param_4 + 2)); break;
  case 0x1e: FUN_0041d4f0(this,uVar2,param_3 + -2,(undefined1 *)(param_4 + 2)); break;
  case 0x1f: FUN_00428ad0(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x20: FUN_00428c00(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x21: FUN_00428f00(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x23: FUN_0041d7e0(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x24: FUN_0041d920(this,uVar2,param_3 + -2,(undefined1 *)(param_4 + 2)); break;
  case 0x25: FUN_0041da40(uVar2,param_3 + -2,(byte *)(param_4 + 2)); break;
  case 0x26: FUN_0041dcb0(this,param_1,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x27: FUN_0041dd80(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x28: FUN_0041de40(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x29: FUN_0041dfb0(this,uVar2,param_3 + -2,(undefined4 *)(param_4 + 2)); break;
  case 0x2a: FUN_0041e0c0(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  case 0x2c: FUN_0041e1a0(this,uVar2,param_3 + -2,(char *)(param_4 + 2)); break;
  }
  // Incrementa packet sequence (field+0x148a) para todos menos subOpcode 2
  if (fieldIdx < maxFields && param_2 != 2) {
    *(short*)(fieldPtr + 0x148a) += 1;
  }
}
