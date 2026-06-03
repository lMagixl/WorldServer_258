
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041bca0(void *this,ushort param_1,undefined4 param_2,LPCSTR param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  byte local_1006;
  undefined1 local_1005;
  undefined2 local_1004;
  undefined1 local_1002;
  CHAR local_1001 [4093];
  int local_4;
  
  local_4 = DAT_00454928;
  if (*(char *)(*(int *)((int)this + 0xd4) + 0x1440 + (uint)param_1 * 0x23b4) == '\x02') {
    iVar3 = 0;
    do {
      if (param_3[iVar3] == ':') {
        if ((-1 < iVar3) &&
           (iVar1 = _strncmp(param_3 + iVar3 + 2,s__roominfo_0044b9e8,9), iVar1 == 0)) {
          lVar2 = _atol(param_3 + iVar3 + 0xc);
          if ((-1 < lVar2) && (lVar2 < (int)(uint)DAT_00455824)) {
            FUN_00406b10((void *)(lVar2 * 0x3c0 + *(int *)((int)this + 0xe4)),param_1);
          }
          goto LAB_0041bd66;
        }
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x1000);
    FUN_0040af90((void *)(*(int *)((int)this + 0xd4) + (uint)param_1 * 0x23b4),&local_1006,
                 &local_1005);
    local_1004 = 0x22;
    local_1002 = local_1005;
    lstrcpynA(local_1001,param_3,0x81);
    iVar3 = lstrlenA(local_1001);
    FUN_00404ef0((void *)((uint)local_1006 * 0x358 + *(int *)((int)this + 0xdc)),(short)iVar3 + 4,
                 (undefined4 *)&local_1004);
  }
LAB_0041bd66:
  FUN_00435e83(local_4);
  return;
}
