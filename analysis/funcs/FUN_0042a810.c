
undefined4 * __fastcall FUN_0042a810(undefined4 *param_1)

{
  DWORD DVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0044128a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00405380(param_1 + 0x85e);
  local_4 = 0;
  PerfLib::AsyncWebRequest::AsyncWebRequest((AsyncWebRequest *)(param_1 + 0x1749));
  FUN_0042a6e0((undefined1 *)(param_1 + 0x1797));
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  puVar4 = param_1 + 9;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  param_1[0x1677] = 0;
  param_1[0x1678] = 0;
  param_1[0x1679] = 0;
  param_1[0x167a] = 0;
  *(undefined1 *)((int)param_1 + 0x4e) = 0;
  param_1[0x14] = 0;
  *(undefined1 *)(param_1 + 0x15) = 0;
  *(undefined1 *)((int)param_1 + 0x55) = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  *(undefined1 *)(param_1 + 0x18) = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  *(undefined2 *)(param_1 + 0x1b) = 0;
  puVar4 = (undefined4 *)((int)param_1 + 0x6e);
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)((int)param_1 + 0xd2) = 0;
  param_1[0x35] = 0;
  *(undefined1 *)(param_1 + 0x36) = 0;
  param_1[0x37] = 0;
  *(undefined2 *)(param_1 + 0x38) = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  *(undefined2 *)(param_1 + 0x3c) = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  *(undefined2 *)(param_1 + 0x42) = 0;
  param_1[0x43] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  *(undefined1 *)(param_1 + 0x53) = 0;
  *(undefined4 *)((int)param_1 + 0x14d) = 0;
  *(undefined4 *)((int)param_1 + 0x151) = 0;
  *(undefined4 *)((int)param_1 + 0x155) = 0;
  *(undefined4 *)((int)param_1 + 0x159) = 0;
  *(undefined4 *)((int)param_1 + 0x15d) = 0;
  *(undefined4 *)((int)param_1 + 0x161) = 0;
  *(undefined4 *)((int)param_1 + 0x165) = 0;
  *(undefined4 *)((int)param_1 + 0x169) = 0;
  *(undefined1 *)((int)param_1 + 0x16d) = 0;
  puVar4 = param_1 + 0x99f;
  for (iVar3 = 0x100; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = param_1 + 0xa9f;
  for (iVar3 = 0x100; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  param_1[0x5c] = 0;
  *(undefined2 *)(param_1 + 0x5d) = 0;
  param_1[0x13a1] = 0;
  param_1[0x13a0] = 0;
  param_1[0x13a2] = 0;
  param_1[0x13a3] = 0;
  param_1[0x13a4] = 0;
  param_1[0x13a5] = 0;
  *(undefined1 *)(param_1 + 0x139f) = 0;
  param_1[0x146d] = 0;
  DVar1 = GetTickCount();
  param_1[0x146e] = DVar1;
  param_1[0x146f] = 0;
  param_1[0x1470] = 0;
  param_1[0x1672] = 0;
  param_1[0x1676] = 0;
  param_1[0x167b] = 0;
  pvVar2 = operator_new(0x80);
  param_1[0x167c] = pvVar2;
  iVar3 = 0;
  do {
    *(undefined4 *)(iVar3 + param_1[0x167c]) = 0;
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x80);
  param_1[0x1471] = 0;
  FUN_0041e470((int)param_1);
  ExceptionList = pvStack_c;
  return param_1;
}



/* === METADATA ===
SIGNATURE: undefined4 * __fastcall FUN_0042a810(undefined4 * param_1)
XREFS: 0042ab0d
CALLEES: AsyncWebRequest FUN_0041e470 FUN_00405380 FUN_0042a6e0 operator_new GetTickCount
CALLERS: FUN_0042aad0
SIZE: 3668 chars */
