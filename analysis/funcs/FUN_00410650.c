
// DB Opcode 0x01 — Admin Ban Handler
// Signature: void __thiscall FUN_00410650(void* this, ushort param_1, ushort param_2, undefined4 param_3, byte* param_4)
// Reads: byte = ban type, string = username
// Queries: SELECT userid FROM CharacterInfo WHERE name = '<name>'
// Then: UPDATE UserGameInfo SET BanDate = <now> WHERE id = <userid>
// Response: [fieldId:2][result:2][userId:4 if success]

void __thiscall FUN_00410650(void *this,undefined2 param_1,undefined2 param_2,undefined4 param_3,byte *param_4)
{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  long lStack_1418;
  CHAR local_1414 [16];
  CHAR aCStack_1404 [1024];
  undefined2 uStack_1004;
  undefined2 uStack_1002;
  char cStack_1000;
  long lStack_fff;
  int local_4;

  local_4 = DAT_00454928;
  bVar1 = *param_4;
  lstrcpyA(local_1414,(LPCSTR)(param_4 + 1));
  wsprintfA(aCStack_1404,s_SELECT_userid_FROM_CharacterInfo_00448538,local_1414);
  uVar5 = *(undefined4 *)((int)this + 8);
  iVar3 = mysql_query(uVar5,aCStack_1404);
  if (iVar3 == 0) {
    iVar3 = mysql_store_result(uVar5);
    if (iVar3 != 0) {
      puVar6 = (undefined4 *)mysql_fetch_row(iVar3);
      if (puVar6 == (undefined4 *)0x0) {
        cStack_1000 = '\x02';  // not found
        mysql_free_result(iVar3);
      } else {
        lStack_1418 = _atol((char *)*puVar6);
        mysql_free_result(iVar3);
        wsprintfA(aCStack_1404,s_UPDATE_UserGameInfo_SET_BanDate__004484b8,(uint)bVar1,lStack_1418);
        iVar3 = mysql_query(*(undefined4 *)((int)this + 8),aCStack_1404);
        if (iVar3 == 0) {
          cStack_1000 = '\0';  // success
        } else {
          FUN_0040ea30(*(int *)((int)this + 8),aCStack_1404);
          cStack_1000 = '\x01';  // fail
        }
      }
      goto LAB_0041075a;
    }
  }
  // Error path
  cStack_1000 = '\x01';
LAB_0041075a:
  uStack_1004 = param_2;
  uStack_1002 = 1;
  uVar2 = 5;
  if (cStack_1000 == '\0') {
    uVar2 = 9;
    lStack_fff = lStack_1418;
  }
  FUN_0042e720(*(void **)((int)this + 0x18),param_1,uVar2,(undefined4 *)&uStack_1004);
  FUN_00435e83(local_4);
  return;
}
