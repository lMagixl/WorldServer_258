/* == SET ACTIVE CHARACTER ==
   Initializes a player field entry with full character data.
   Called during character select and after DB response case 7. */

void __thiscall
FUN_0040ac30(void *this,undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined1 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined2 param_12,
            undefined2 param_13,undefined2 param_14,undefined2 param_15,undefined2 param_16,
            undefined2 param_17,undefined2 param_18,undefined2 param_19,undefined2 param_20,
            undefined2 param_21,undefined2 param_22)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *(undefined1 *)((int)this + 0x146c) = param_2;
  *(undefined4 *)((int)this + 0x14a4) = param_1;
  *(undefined4 *)((int)this + 0x1534) = param_5;
  *(undefined1 *)((int)this + 0x1530) = param_3;
  *(undefined1 *)((int)this + 0x1531) = param_4;
  *(undefined1 *)((int)this + 0x1540) = param_8;
  *(undefined4 *)((int)this + 0x1538) = param_6;
  *(undefined4 *)((int)this + 0x153c) = param_7;
  *(undefined4 *)((int)this + 0x154c) = param_11;
  *(undefined2 *)((int)this + 0x1554) = param_14;
  *(undefined4 *)((int)this + 0x1544) = param_9;
  *(undefined4 *)((int)this + 0x1548) = param_10;
  *(undefined2 *)((int)this + 0x1550) = param_12;
  *(undefined2 *)((int)this + 0x1552) = param_13;
  *(undefined2 *)((int)this + 0x155a) = param_17;
  *(undefined2 *)((int)this + 0x1556) = param_15;
  *(undefined2 *)((int)this + 0x1558) = param_16;
  *(undefined2 *)((int)this + 0x1560) = param_20;
  *(undefined2 *)((int)this + 0x155c) = param_18;
  *(undefined2 *)((int)this + 0x155e) = param_19;
  *(undefined2 *)((int)this + 0x1562) = param_21;
  *(undefined2 *)((int)this + 0x1564) = param_22;
  *(undefined4 *)((int)this + 0x1566) = *(undefined4 *)((int)this + 0x1550);
  *(undefined4 *)((int)this + 0x156a) = *(undefined4 *)((int)this + 0x1554);
  *(undefined4 *)((int)this + 0x156e) = *(undefined4 *)((int)this + 0x1558);
  *(undefined4 *)((int)this + 0x1572) = *(undefined4 *)((int)this + 0x155c);
  *(undefined4 *)((int)this + 0x1576) = *(undefined4 *)((int)this + 0x1560);
  *(undefined2 *)((int)this + 0x157a) = *(undefined2 *)((int)this + 0x1564);
  puVar4 = (undefined4 *)((int)this + 0x157c);
  puVar5 = (undefined4 *)((int)this + 0x1b78);
  for (iVar1 = 0x17f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar1 = lstrlenA((LPCSTR)((int)this + 0x14a8));
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      cVar3 = ((LPCSTR)((int)this + 0x14a8))[iVar2];
      if ((cVar3 < 'A') || ('Z' < cVar3)) {
        if (cVar3 < '\0') {
          *(char *)((int)this + iVar2 + 0x14b5) = cVar3;
          cVar3 = *(char *)((int)this + iVar2 + 0x14a9);
          iVar2 = iVar2 + 1;
        }
      }
      else {
        cVar3 = cVar3 + ' ';
      }
      *(char *)((int)this + iVar2 + 0x14b5) = cVar3;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return;
}
