/* == SET CHANNEL INFO ==
   Simple setter function for a CUser object.
   Sets the player's channel ID and status when joining a channel. */

void __thiscall FUN_0040af60(void *this,undefined1 param_1,undefined1 param_2)

{
  *(undefined1 *)((int)this + 0x148c) = param_1;
  *(undefined1 *)((int)this + 0x148d) = param_2;
  *(undefined1 *)((int)this + 0x1440) = 2;
  FUN_0042f280(s__RW______CUser__SetChannelInfo___00447688);
  return;
}
