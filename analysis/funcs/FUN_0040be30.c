/* == LOAD CHARACTER EQUIPMENT DATA ==
   Copies character data from DB slot to field workspace.
   Called during character select at FUN_0041fef0 line ~35. */

void __thiscall
FUN_0040be30(void *this,LPCSTR param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6,undefined4 *param_7)

{
  int iVar1;
  undefined4 *puVar2;
  
  lstrcpyA((LPSTR)((int)this + 0x14a8),param_1);
  puVar2 = (undefined4 *)((int)this + 0x157c);
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x17a8);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_3;
    param_3 = param_3 + 1;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = *(undefined2 *)param_3;
  *(undefined4 *)((int)this + 0x17ce) = *param_4;
  *(undefined4 *)((int)this + 0x17d2) = param_4[1];
  *(undefined4 *)((int)this + 0x17d6) = param_4[2];
  *(undefined4 *)((int)this + 0x17da) = param_4[3];
  *(undefined2 *)((int)this + 0x17de) = *(undefined2 *)(param_4 + 4);
  *(undefined1 *)((int)this + 0x17e0) = *(undefined1 *)((int)param_4 + 0x12);
  puVar2 = (undefined4 *)((int)this + 0x17e4);
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_5;
    param_5 = param_5 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x2174);
  for (iVar1 = 100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_6;
    param_6 = param_6 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x2304);
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_7;
    param_7 = param_7 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}
