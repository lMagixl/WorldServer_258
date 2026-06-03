
// Opcode 0x01 — Admin IP check
// Signature: void __thiscall FUN_0041ee00(void* this, ushort fieldIdx)
// Called from: FUN_0042ab40 (game dispatcher)
// Verifica que la IP del cliente esté en la lista de admin.
// Si no es admin → envía error (opcode 7, result=1)
// Si es admin → setea estado del field (4=admin normal, 5=superadmin),
//   envía respuesta (opcode=3, data=\x01\x00)

void __thiscall FUN_0041ee00(void *this,ushort param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int local_1014 [2];
  undefined2 local_100c [4];
  undefined2 local_1004;
  undefined1 local_1002;
  int local_4;

  local_4 = DAT_00454928;
  iVar4 = (uint)param_1 * 0x23b4;
  FUN_0040abe0((void *)(*(int *)((int)this + 0xd4) + iVar4),local_1014,local_100c);
  bVar1 = *(byte *)((int)this + 0x60);
  uVar3 = 0;
  bVar2 = 0;
  if (bVar1 != 0) {
    do {
      bVar2 = (byte)uVar3;
      if (*(int *)(*(int *)((int)this + 100) + uVar3 * 4) == local_1014[0]) break;
      bVar2 = bVar2 + 1;
      uVar3 = (uint)bVar2;
    } while (bVar2 < bVar1);
  }
  if (bVar1 <= bVar2) {
    FUN_0041eb20(this,param_1,7,'\x01',1);
    FUN_00435e83(local_4);
    return;
  }
  if (*(char *)((uint)bVar2 + *(int *)((int)this + 0x68)) == '\0') {
    *(undefined1 *)(*(int *)((int)this + 0xd4) + 0x1440 + iVar4) = 4;
  }
  else {
    *(undefined1 *)(*(int *)((int)this + 0xd4) + 0x1440 + iVar4) = 5;
  }
  local_1004 = 1;
  local_1002 = 0;
  FUN_004038e0(*(void **)((int)this + 0x118),param_1,3,(undefined4 *)&local_1004);
  FUN_00435e83(local_4);
  return;
}
