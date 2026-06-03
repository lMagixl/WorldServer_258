/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041eb20(void *this,ushort param_1,ushort param_2,char param_3,byte param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  CHAR local_1510;
  undefined4 local_150f;
  char local_1410 [1024];
  undefined2 local_1010;
  undefined2 local_100e;
  undefined4 local_100c;
  ushort local_1008;
  int local_1006;
  int local_c;
  
  local_c = DAT_00454928;
  uVar3 = (uint)param_2;
  FUN_0042f280(s__RW______CWorld__ProcessUserDisc_0044bf28);
  switch(uVar3) {
  case 0x47:
    bVar2 = *(byte *)((uint)param_1 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4));
    pcVar7 = s__71__NetworkMessageFieldList___N_0044be28;
    break;
  default:
    goto switchD_0041eb72_caseD_48;
  case 0x4f:
    bVar2 = *(byte *)((uint)param_1 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4));
    pcVar7 = s__79__NetworkMessageFieldQuickEnt_0044bee0;
    break;
  case 0x51:
    bVar2 = *(byte *)((uint)param_1 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4));
    pcVar7 = s__81__NetworkMessageFieldExit___N_0044be64;
    goto LAB_0041ec72;
  case 0x53:
    bVar2 = *(byte *)((uint)param_1 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4));
    pcVar7 = s__83__NetworkMessageFieldCreate___0044bde8;
    goto LAB_0041ec38;
  case 0x61:
    bVar2 = *(byte *)((uint)param_1 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4));
    pcVar7 = s__97__NetworkMessageFieldReady___N_0044bda8;
LAB_0041ec72:
    _sprintf(local_1410,pcVar7,(uint)bVar2);
    goto LAB_0041ec8b;
  case 0x7f:
    bVar2 = *(byte *)((uint)param_1 * 0x23b4 + 0x1440 + *(int *)((int)this + 0xd4));
    pcVar7 = s__127__NetworkMessageFieldChat___N_0044bea0;
LAB_0041ec38:
    _sprintf(local_1410,pcVar7,(uint)bVar2);
    goto LAB_0041ec8b;
  }
  _sprintf(local_1410,pcVar7,(uint)bVar2);
LAB_0041ec8b:
  FUN_0041d380(this,local_1410,(uint)param_1);
switchD_0041eb72_caseD_48:
  iVar5 = (uint)param_1 * 0x23b4;
  iVar4 = *(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar5);
  if (iVar4 != 0) {
    FUN_0041ba00(this,param_1,(uint)param_4);
    if (param_3 == '\0') {
      param_2 = 0;
    }
    iVar1 = *(int *)((int)this + 0xd4) + iVar5;
    local_100c = *(undefined4 *)(iVar1 + 0x1468);
    local_1010 = *(undefined2 *)(iVar1 + 0x1488);
    local_100e = 4;
    local_1008 = param_2;
    local_1006 = iVar4;
    FUN_0041b940(this,param_1,0xe,(undefined4 *)&local_1010);
  }
  if (param_3 == '\x01') {
    local_1510 = '\0';
    puVar6 = &local_150f;
    for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    *(undefined2 *)puVar6 = 0;
    *(undefined1 *)((int)puVar6 + 2) = 0;
    wsprintfA(&local_1510,s___04u__DISC__03u_0044bd94,param_1,uVar3);
    FUN_0041d380(this,&local_1510,*(int *)(*(int *)((int)this + 0xd4) + 0x1460 + iVar5));
  }
  FUN_004038b0(*(void **)((int)this + 0x118),param_1);
  FUN_0040a8e0(*(int *)((int)this + 0xd4) + iVar5);
  FUN_00435e83(local_c);
  return;
}
