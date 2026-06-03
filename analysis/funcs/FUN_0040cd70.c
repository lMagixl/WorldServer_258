
uint __thiscall
FUN_0040cd70(void *this,byte param_1,ushort *param_2,undefined4 *param_3,byte *param_4,
            undefined4 *param_5,undefined4 *param_6,byte *param_7,int param_8,int param_9,
            byte *param_10,int param_11,int param_12)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  if (*(byte *)((int)this + 0x144c) == 0) {
    return 1;
  }
  iVar2 = *(byte *)((int)this + 0x144c) - 2;
  if (iVar2 != 0) {
    uVar3 = (uint)param_1;
    uVar1 = *(ushort *)((int)this + uVar3 * 2 + 0x1e2c);
    if (uVar1 == 0) {
      return CONCAT31((int3)(CONCAT22((short)((uint)iVar2 >> 0x10),uVar1) >> 8),3);
    }
    *param_2 = uVar1;
    if ((uVar1 < 1000) || (7999 < uVar1)) {
      if ((uVar1 < 8000) || (8999 < uVar1)) {
        if ((uVar1 < 12000) || (12999 < uVar1)) {
          uVar4 = FUN_0042aad0();
          uVar5 = FUN_0040a810((uint)*param_2 * 0x20 + *(int *)((int)uVar4 + 0x10c),
                               (uint)((ulonglong)uVar4 >> 0x20));
          *param_3 = (int)uVar5;
        }
        else {
          *param_3 = 0;
        }
        *param_4 = 0;
        *param_5 = 0;
      }
      else {
        iVar2 = FUN_0042aad0();
        iVar2 = *(int *)(iVar2 + 0x104);
        *param_4 = *(byte *)(uVar3 + 0x1f1c + (int)this);
        *param_5 = *(undefined4 *)((int)this + uVar3 * 4 + 0x1f94);
        *param_3 = *(undefined4 *)(iVar2 + -0x61a670 + ((uint)*param_2 * 200 + (uint)*param_4) * 4);
      }
    }
    else {
      *param_4 = *(byte *)(uVar3 + 0x1f1c + (int)this);
      *param_5 = *(undefined4 *)((int)this + uVar3 * 4 + 0x1f94);
      uVar4 = FUN_0042aad0();
      uVar5 = FUN_0040a810((uint)*param_2 * 0x20 + *(int *)((int)uVar4 + 0x10c),
                           (uint)((ulonglong)uVar4 >> 0x20));
      *param_3 = (int)uVar5;
      FUN_0042f280(s__RW__CUser__byItemLevel____d_00447840);
      FUN_0042f280(s__RW__CUser__ulItemExp____d_00447824);
      FUN_0042f280(s_8_RW__CUser__ulSellGold____d_00447807 + 1);
    }
    *param_6 = *(undefined4 *)((int)this + uVar3 * 4 + 0x1bc4);
    uVar3 = FUN_0040bcb0(this,param_7,param_8,param_9,param_10,param_11,param_12,'\x01');
    *(undefined1 *)((int)this + 0x144c) = 2;
    return uVar3 & 0xffffff00;
  }
  return 2;
}


