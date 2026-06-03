
void __thiscall FUN_0041ae50(void *this,ushort param_1,int param_2,USHORT *param_3)

{
  USHORT UVar1;
  USHORT UVar2;
  void *this_00;
  char *pcVar3;
  int iVar4;
  
  GetTickCount();
  UVar1 = param_3[1];
  UVar2 = *param_3;
  *(USHORT *)((int)this + 4) = UVar1;
  switch(UVar1) {
  case 1:
    FUN_00410650(this,param_1,UVar2,param_2 + -4,(byte *)(param_3 + 2));
    return;
  case 2:
    FUN_004107d0(this,param_1,UVar2,param_2 + -4,(LPCSTR)(param_3 + 2));
    return;
  default:
    iVar4 = -1;
    pcVar3 = s_Invalid_Db_Command_Number_0044b928;
    this_00 = (void *)FUN_0042aad0();
    FUN_0041d380(this_00,pcVar3,iVar4);
switchD_0041ae75_caseD_1d:
    return;
  case 4:
    FUN_00412140(this);
    return;
  case 5:
    FUN_004121e0(this);
    return;
  case 7:
    FUN_00412280(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 8:
    FUN_00412530(this,param_1,UVar2,param_2 + -4,(int *)(param_3 + 2));
    return;
  case 9:
    FUN_004129f0(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 10:
    FUN_00413440(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0xb:
    FUN_004137a0(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0xc:
    FUN_004138b0(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0xd:
    FUN_00413980(this,param_1,UVar2,param_2 + -4,param_3 + 2);
    return;
  case 0xe:
    FUN_00413b00(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0xf:
    FUN_00413bd0(this);
    return;
  case 0x10:
    FUN_00413cd0(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x11:
    FUN_004144f0(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x12:
    FUN_00414cc0(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x13:
    FUN_00419730(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x14:
    FUN_00419a40(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x15:
    FUN_0041a900(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x16:
    FUN_00414e70(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x17:
    FUN_00415cb0(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x18:
    FUN_00415590(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x19:
    FUN_00416530(this);
    return;
  case 0x1a:
    FUN_004165d0(this);
    return;
  case 0x1b:
    FUN_00416810(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x1c:
    FUN_00416950(this);
    return;
  case 0x1d:
    goto switchD_0041ae75_caseD_1d;
  case 0x1e:
    FUN_00416bf0(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x1f:
    FUN_00416d90(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x20:
    FUN_004175e0(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x21:
    FUN_00417800(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x22:
    FUN_00417e10(this);
    return;
  case 0x23:
    FUN_00417f10(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x24:
    FUN_004184a0(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x25:
    FUN_00418b00(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x26:
    FUN_0040eaf0(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x27:
    FUN_00418da0(this,param_1,UVar2,param_2 + -4,(int)(param_3 + 2));
    return;
  case 0x28:
    FUN_00419180(this,param_1,UVar2,param_2 + -4,(int)(param_3 + 2));
    return;
  case 0x29:
    FUN_0040ec50(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x2a:
    FUN_0040f0a0(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  case 0x2b:
    FUN_0040f2f0((int)this);
    return;
  case 0x2c:
    FUN_0040f610(this,param_1,UVar2,param_2 + -4,(undefined4 *)(param_3 + 2));
    return;
  }
}



/* === METADATA ===
SIGNATURE: undefined __thiscall FUN_0041ae50(void * this, ushort param_1, int param_2, USHORT * param_3)
XREFS: 0041b4a2
CALLEES: FUN_0041d380 FUN_00419a40 FUN_00416950 FUN_0040f2f0 FUN_00416d90 FUN_004121e0 FUN_004184a0 FUN_00417800 FUN_0040f610 FUN_004137a0 FUN_0040f0a0 FUN_00414cc0 FUN_00419730 FUN_00413cd0 GetTickCount FUN_00413440 FUN_00416530 FUN_00417f10 FUN_00413b00 FUN_00413980 FUN_0042aad0 FUN_00413bd0 FUN_00418b00 FUN_00416810 FUN_00418da0 FUN_0040ec50 FUN_00419180 FUN_00415cb0 FUN_00414e70 FUN_00412530 FUN_004129f0 FUN_004165d0 FUN_0040eaf0 FUN_00417e10 FUN_00416bf0 FUN_004144f0 FUN_0041a900 FUN_00412140 FUN_004138b0 FUN_00415590 FUN_00410650 FUN_004107d0 FUN_00412280 FUN_004175e0
CALLERS: FUN_0041b3f0
SIZE: 4434 chars */
