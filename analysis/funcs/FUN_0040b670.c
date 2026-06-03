/* == RESET LOBBY STATE ==
   Resets interaction timers and state after entering a channel. */

void __fastcall FUN_0040b670(int param_1)

{
  *(undefined1 *)(param_1 + 0x148e) = 0;
  *(undefined2 *)(param_1 + 0x1490) = 0;
  *(undefined1 *)(param_1 + 0x1492) = 0;
  *(undefined1 *)(param_1 + 0x1493) = 0;
  *(undefined1 *)(param_1 + 0x1494) = 0;
  *(undefined1 *)(param_1 + 0x1495) = 0;
  *(undefined1 *)(param_1 + 0x1496) = 0;
  *(undefined1 *)(param_1 + 0x1497) = 0;
  *(undefined1 *)(param_1 + 0x1498) = 0;
  *(undefined1 *)(param_1 + 0x1499) = 0;
  *(undefined4 *)(param_1 + 0x149c) = 0xffffffff;
  return;
}
