
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041f060(void *this,ushort param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  undefined2 local_1004;
  undefined1 local_1002;
  char local_1001;
  int local_4;
  
  local_4 = DAT_00454928;
  if (*(char *)((uint)param_1 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4)) != '\x05') {
    FUN_0041eb20(this,param_1,9,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  cVar1 = *param_3;
  local_1002 = 0;
  if (cVar1 == '\0') {
    if (*(int *)((int)this + 0x50) != 0) {
      FUN_0041d380(this,s_Server_Open_0044bf70,0);
      *(undefined4 *)((int)this + 0x50) = 0;
      goto LAB_0041f155;
    }
  }
  else if (*(int *)((int)this + 0x50) == 0) {
    FUN_0041d380(this,s_Server_Close_0044bf7c,0);
    *(undefined4 *)((int)this + 0x50) = 1;
    uVar3 = 0;
    if (DAT_00456030 != 0) {
      do {
        cVar2 = *(char *)((uint)uVar3 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4));
        if ((cVar2 != '\0') && (cVar2 != '\x05')) {
          FUN_0041eb20(this,uVar3,10,'\0',0);
        }
        uVar3 = uVar3 + 1;
        local_1002 = 0;
      } while (uVar3 < DAT_00456030);
    }
    goto LAB_0041f155;
  }
  local_1002 = 1;
LAB_0041f155:
  local_1004 = 3;
  local_1001 = cVar1;
  FUN_004038e0(*(void **)((int)this + 0x118),param_1,4,(undefined4 *)&local_1004);
  FUN_00435e83(local_4);
  return;
}
