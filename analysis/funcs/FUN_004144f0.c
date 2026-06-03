/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* DB opcode 0x11 - Character Change Name */

void __thiscall
FUN_004144f0(void *this,ushort param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  long lVar9;
  byte *pbVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  uint uVar15;
  bool bVar16;
  char *pcVar17;
  int iVar18;
  char local_1497;
  byte bStack_1496;
  int local_1494;
  int local_1490;
  undefined4 uStack_148c;
  long local_1488;
  int iStack_1484;
  int local_1480;
  uint local_147c;
  undefined4 uStack_1478;
  byte bStack_1470;
  undefined4 uStack_146f;
  undefined4 uStack_146b;
  undefined4 uStack_1467;
  undefined4 local_1460 [4];
  CHAR CStack_1450;
  undefined4 uStack_144f;
  undefined4 uStack_144b;
  undefined4 uStack_1447;
  undefined4 uStack_1443;
  byte bStack_143c;
  undefined4 uStack_143b;
  undefined4 uStack_1437;
  undefined4 uStack_1433;
  CHAR local_142c [16];
  CHAR aCStack_141c [24];
  CHAR aCStack_1404 [1024];
  undefined4 uStack_1004;
  char cStack_1000;
  int iStack_fff;
  CHAR aCStack_ffb [4087];
  int local_4;
  
  local_4 = DAT_00454928;
  uVar7 = *param_4;
  local_1497 = '\0';
  local_1488 = 0;
  local_147c = 0;
  local_1480 = 0;
  local_1494 = 0;
  local_1460[0] = 0;
  local_1460[1] = 0;
  local_1460[2] = 0;
  local_1460[3] = 0;
  lstrcpyA(local_142c,(LPCSTR)(param_4 + 1));
  iVar5 = lstrlenA((LPCSTR)(param_4 + 1));
  cVar1 = *(char *)((iVar5 + 5U & 0xffff) + (int)param_4);
  uStack_1478 = 0;
  uStack_148c = 0;
  iStack_1484 = 0;
  uVar3 = 0;
  if (cVar1 == '\x01') {
    uStack_1478 = *(undefined4 *)((iVar5 + 6U & 0xffff) + (int)param_4);
    uStack_148c = *(undefined4 *)((iVar5 + 10U & 0xffff) + (int)param_4);
    iStack_1484 = *(int *)((iVar5 + 0xeU & 0xffff) + (int)param_4);
    uVar3 = *(undefined2 *)((iVar5 + 0x12U & 0xffff) + (int)param_4);
  }
  wsprintfA(aCStack_1404,s_SELECT_count____FROM_Characterin_00449df8,local_142c);
  // Check name not taken
  uVar11 = *(undefined4 *)((int)this + 8);
  iVar5 = mysql_query(uVar11,aCStack_1404);
  if ((iVar5 == 0) && (iVar5 = mysql_store_result(uVar11), iVar5 != 0)) {
    puVar8 = (undefined4 *)mysql_fetch_row(iVar5);
    while (puVar8 != (undefined4 *)0x0) {
      lVar9 = _atol((char *)*puVar8);
      if (0 < lVar9) {
        mysql_free_result(iVar5);
        local_1497 = '\x01';  // Name already taken
        goto LAB_00414bda;
      }
      puVar8 = (undefined4 *)mysql_fetch_row(iVar5);
    }
    mysql_free_result(iVar5);
    // Get old name and user info
    wsprintfA(aCStack_1404,s_SELECT_a_name_b_name_a_userid_b__00449d48,uVar7);
    // ... gets old char info, checks cash, costs, etc ...
    // UPDATE CharacterInfo SET name='<newName>' WHERE id=<charId>
    // UPDATE Cash SET cash=cash-<cost>
    // INSERT INTO LogChangeCharName
    // Handle presents/items if coupon used
  }
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar4,&uStack_1004);
LAB_00414c9f:
  FUN_00435e83(local_4);
  return;
}
