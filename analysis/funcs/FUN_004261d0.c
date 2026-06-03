// FUN_004261d0 — DB Response case 1, Auth duplicate check
// Address: 0x004261d0

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_004261d0(void *this,ushort param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  undefined2 local_1004;
  char local_1002;
  int local_4;
  
  local_4 = DAT_00454928;
  cVar1 = *param_3;
  if (cVar1 == '\0') {
    uVar2 = 0;
    if (DAT_00456030 != 0) {
      do {
        iVar3 = (uint)uVar2 * 0x23b4 + *(int *)((int)this + 0xd4);
        if ((*(char *)(iVar3 + 0x1440) != '\0') &&
           (*(int *)(iVar3 + 0x1460) == *(int *)(param_3 + 1))) {
          FUN_0041eb20(this,uVar2,0xb4,'\x01',1);
          break;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < DAT_00456030);
    }
  }
  local_1004 = 4;
  local_1002 = cVar1;
  FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)&local_1004);
  FUN_00435e83(local_4);
  return;
}

// SQL strings found: (none — in-memory auth duplicate check)
