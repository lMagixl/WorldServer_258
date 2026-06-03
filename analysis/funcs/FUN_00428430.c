
void __thiscall FUN_00428430(void *this,ushort param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  byte local_28 [32];
  undefined1 local_8;
  int local_4;
  
  iVar5 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  cVar1 = *(char *)(*(int *)((int)this + 0xd4) + 0x237c + iVar5);
  if ((cVar1 != '\x04') && (cVar1 != '\x05')) {
    if (*(int *)(*(int *)((int)this + 0xd4) + iVar5 + 0x1460) == 0) {
      FUN_0041eb20(this,param_1,0xbb,'\x01',1);
    }
    pbVar3 = local_28;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined4 *)pbVar3 = *param_3;
      param_3 = param_3 + 1;
      pbVar3 = pbVar3 + 4;
    }
    local_8 = 0;
    pbVar3 = (byte *)((int)this + 0x14d);
    if (*(char *)(*(int *)((int)this + 0xd4) + 0x237c + iVar5) != '\x01') {
      pbVar3 = (byte *)((int)this + 300);
    }
    pbVar6 = local_28;
    do {
      bVar2 = *pbVar3;
      bVar7 = bVar2 < *pbVar6;
      if (bVar2 != *pbVar6) {
LAB_004284e8:
        iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_004284ed;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar7 = bVar2 < pbVar6[1];
      if (bVar2 != pbVar6[1]) goto LAB_004284e8;
      pbVar3 = pbVar3 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar2 != 0);
    iVar5 = 0;
LAB_004284ed:
    if (iVar5 != 0) {
      FUN_0041eb20(this,param_1,0xbc,'\x01',1);
    }
  }
  FUN_00435e83(local_4);
  return;
}
