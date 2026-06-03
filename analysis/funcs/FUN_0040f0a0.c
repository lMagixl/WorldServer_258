
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall
FUN_0040f0a0(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 uVar5;
  long lVar6;
  char cVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  ushort uVar10;
  ushort uVar11;
  char *pcVar12;
  int iVar13;
  uint uStack_1468;
  long alStack_1460 [10];
  undefined1 uStack_1438;
  undefined4 auStack_1437 [12];
  CHAR local_1404 [1024];
  undefined4 uStack_1004;
  char cStack_1000;
  uint uStack_fff;
  int local_4;
  
  local_4 = DAT_00454928;
  bVar1 = *(byte *)(param_4 + 1);
  uVar5 = *param_4;
  pcVar12 = s__RW____CDB___wPageNo____u_00447df0;
  cVar7 = '\x02';
  uVar3 = (uint)bVar1;
  FUN_0042f280(s__RW____CDB___wPageNo____u_00447df0);
  wsprintfA(local_1404,s_SELECT_no__no1__no2__no3__no4__n_00447d90,uVar5,(uint)bVar1 * 10,10,pcVar12
            ,uVar3);
  uVar5 = *(undefined4 *)((int)this + 8);
  iVar2 = mysql_query(uVar5,local_1404);
  if ((iVar2 == 0) && (uVar3 = mysql_store_result(uVar5), uStack_1468 = uVar3, uVar3 != 0)) {
    alStack_1460[1] = 0;
    alStack_1460[2] = 0;
    alStack_1460[3] = 0;
    alStack_1460[4] = 0;
    alStack_1460[5] = 0;
    alStack_1460[6] = 0;
    alStack_1460[7] = 0;
    alStack_1460[8] = 0;
    uStack_1438 = 0;
    alStack_1460[9] = 0;
    puVar8 = auStack_1437;
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    *(undefined1 *)puVar8 = 0;
    alStack_1460[0] = 0;
    uStack_1468 = 0;
    puVar8 = (undefined4 *)mysql_fetch_row(uVar3);
    if (puVar8 != (undefined4 *)0x0) {
      puVar9 = &uStack_1438;
      do {
        if ((char *)*puVar8 != (char *)0x0) {
          lVar6 = _atol((char *)*puVar8);
          alStack_1460[uStack_1468] = lVar6;
          FUN_0042f280(s__RW____CDB___dwNow__u_____u_00447d2c);
          iVar2 = 0;
          do {
            puVar8 = puVar8 + 1;
            lVar6 = _atol((char *)*puVar8);
            puVar9[iVar2] = (char)lVar6;
            FUN_0042f280(s__RW____CDB___byLottoNum__u___d____00447d04);
            iVar2 = iVar2 + 1;
          } while (iVar2 < 5);
          uStack_1468 = uStack_1468 + 1;
          puVar9 = puVar9 + 5;
        }
        puVar8 = (undefined4 *)mysql_fetch_row(uVar3);
      } while (puVar8 != (undefined4 *)0x0);
    }
    mysql_free_result(uVar3);
    cVar7 = '\x01' - (uStack_1468 != 0);
    FUN_0042f280(s__RW____CDB__DBCommandAskLotto_____00447cd0);
  }
  else {
    iVar2 = *(int *)((int)this + 8);
    iVar13 = -1;
    pcVar12 = s_DBCommandAskLotto___failed__0_00447d6c;
    pvVar4 = (void *)FUN_0042aad0();
    FUN_0041d380(pvVar4,pcVar12,iVar13);
    if (iVar2 != 0) {
      iVar13 = -1;
      uVar5 = mysql_error(iVar2);
      pvVar4 = (void *)FUN_0042aad0();
      FUN_0041d380(pvVar4,uVar5,iVar13);
    }
  }
  uStack_1004._0_2_ = param_2;
  uStack_1004._2_2_ = 0x2a;
  cStack_1000 = cVar7;
  uVar10 = 5;
  if ((cVar7 == '\0') || (cVar7 == '\x01')) {
    uVar3 = 0;
    uStack_fff = uStack_1468;
    uVar10 = 9;
    if (uStack_1468 != 0) {
      puVar8 = (undefined4 *)&uStack_1438;
      uVar10 = 9;
      do {
        *(long *)((int)&uStack_1004 + (uint)uVar10) = alStack_1460[uVar3];
        uVar11 = uVar10 + 4;
        FUN_0042f280(s__RW____SendWorld___CDB___dwNo_____00447d48);
        cVar7 = *(char *)(puVar8 + 1);
        uVar10 = uVar10 + 9;
        uVar3 = uVar3 + 1;
        *(undefined4 *)((int)&uStack_1004 + (uint)uVar11) = *puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 5);
        (&cStack_1000)[uVar11] = cVar7;
      } while (uVar3 < uStack_1468);
    }
  }
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar10,&uStack_1004);
  FUN_00435e83(local_4);
  return;
}


