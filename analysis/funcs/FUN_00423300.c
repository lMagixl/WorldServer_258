
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_00423300(void *this,ushort param_1)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  ushort uVar5;
  byte local_1014;
  byte local_1013;
  byte local_1012;
  byte local_1011;
  undefined1 local_1010;
  undefined1 local_100f;
  undefined1 local_100e;
  undefined1 local_100d;
  byte local_100c [4];
  byte local_1008 [4];
  undefined2 local_1004 [2048];
  int local_4;
  
  iVar4 = (uint)param_1 * 0x23b4;
  local_4 = DAT_00454928;
  pvVar3 = (void *)(*(int *)((int)this + 0xd4) + iVar4);
  if ((*(int *)((int)pvVar3 + 0x1460) == 0) || (*(int *)((int)pvVar3 + 0x14a4) == 0)) {
    FUN_0041eb20(this,param_1,0x4e,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(char *)((int)pvVar3 + 0x1440) != '\x02') {
    FUN_0041eb20(this,param_1,0x4f,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  FUN_0041b790(pvVar3,&local_100f,(undefined2 *)local_100c,&local_100e,&local_1010,&local_1011,
               &local_1013,&local_1012,&local_1014,&local_100d);
  uVar5 = 0;
  if (DAT_00455824 != 0) {
    do {
      pvVar3 = (void *)(*(int *)((int)this + 0xe4) + (uint)uVar5 * 0x3c0);
      if (*(char *)((int)pvVar3 + 8) != '\0') {
        switch(*(undefined1 *)((int)pvVar3 + 0x119)) {
        case 1:
          bVar1 = local_1011;
          break;
        case 2:
          bVar1 = local_1013;
          break;
        case 3:
          bVar1 = local_1012;
          break;
        case 4:
          bVar1 = local_1014;
          break;
        default:
          goto switchD_004233e5_default;
        }
        if (bVar1 != 0) {
          iVar2 = FUN_00406f40(pvVar3,1,&DAT_0044c102,param_1,local_1008,0);
          if (iVar2 != 0) {
            FUN_0040af90((void *)(*(int *)((int)this + 0xd4) + iVar4),&local_1014,local_100c);
            FUN_00405240((void *)((uint)local_1014 * 0x358 + *(int *)((int)this + 0xdc)),
                         local_100c[0]);
            FUN_0040b7b0((void *)(*(int *)((int)this + 0xd4) + iVar4),uVar5,local_1008[0]);
            goto LAB_00423442;
          }
        }
      }
switchD_004233e5_default:
      uVar5 = uVar5 + 1;
    } while (uVar5 < DAT_00455824);
  }
  local_1004[0] = 0x39;
  FUN_004038e0(*(void **)((int)this + 0x118),param_1,2,(undefined4 *)local_1004);
LAB_00423442:
  FUN_00435e83(local_4);
  return;
}
