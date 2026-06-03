
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041c3d0(void *this,ushort param_1,undefined4 param_2,char *param_3)

{
  undefined4 *puVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  ushort uVar5;
  int iVar6;
  undefined4 *puVar7;
  CHAR local_1014 [16];
  undefined2 local_1004;
  char local_1002;
  undefined4 uStack_1001;
  int local_4;
  
  local_4 = DAT_00454928;
  local_1002 = *param_3;
  local_1004 = 0x12;
  uVar5 = 3;
  if (local_1002 == '\0') {
    cVar2 = param_3[6];
    bVar3 = param_3[1];
    uVar4 = *(undefined4 *)(param_3 + 2);
    lstrcpyA(local_1014,param_3 + 7);
    lstrlenA(param_3 + 7);
    puVar1 = (undefined4 *)
             ((uint)bVar3 * 0x360 + (uint)param_1 * 0x23b4 + *(int *)((int)this + 0xd4));
    puVar7 = puVar1;
    for (iVar6 = 0xd8; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    lstrcpyA((LPSTR)(puVar1 + 1),local_1014);
    *(char *)((int)puVar1 + 0x355) = cVar2;
    *puVar1 = uVar4;
    *(undefined1 *)((int)puVar1 + 0x356) = 1;
    *(undefined1 *)(puVar1 + 0xd2) = 0x1a;
    uVar5 = 7;
    uStack_1001 = uVar4;
  }
  FUN_004038e0(*(void **)((int)this + 0x118),param_1,uVar5,(undefined4 *)&local_1004);
  FUN_00435e83(local_4);
  return;
}


