
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_0041fef0(void *this,uint param_1,undefined4 param_2,int *param_3)

{
  int *this_00;
  int *piVar1;
  void *this_01;
  int iVar2;
  int iVar3;
  ushort uVar4;
  char cVar5;
  undefined1 local_100a;
  byte local_1009;
  uint local_1008;
  undefined2 local_1004;
  undefined1 local_1002;
  int local_4;
  
  iVar3 = (param_1 & 0xffff) * 0x23b4;
  local_4 = DAT_00454928;
  this_00 = (int *)(*(int *)((int)this + 0xd4) + iVar3);
  iVar2 = 0;
  if ((this_00[0x518] == 0) || (this_00[0x529] != 0)) {
    cVar5 = '\0';
    uVar4 = 0x1d;
  }
  else {
    if (*param_3 != 0) {
      local_100a = 0;
      piVar1 = this_00;
      do {
        if (*piVar1 == *param_3) {
          piVar1 = this_00 + iVar2 * 0xd8;
          FUN_0040be30(this_00,(LPCSTR)(piVar1 + 1),piVar1 + 0x94,
                       (undefined4 *)((int)piVar1 + 0x22a),piVar1 + 0xa7,piVar1 + 0xac,piVar1 + 8,
                       piVar1 + 0x6c);
          local_1009 = *(byte *)((int)piVar1 + 0x356);
          local_1008 = piVar1[0xd6];
          FUN_0040d3f0((void *)(*(int *)((int)this + 0xd4) + iVar3),&local_1009,&local_1008);
          piVar1[0xd6] = local_1008;
          this_01 = (void *)(*(int *)((int)this + 0xd4) + iVar3);
          FUN_0040ac30(this_01,*piVar1,(char)piVar1[0xd5],*(undefined1 *)((int)piVar1 + 0x355),
                       *(undefined1 *)((int)piVar1 + 0x356),local_1008,
                       *(undefined4 *)((int)this_01 + 0x1538),*(undefined4 *)((int)this_01 + 0x153c)
                       ,*(undefined1 *)((int)this_01 + 0x1540),piVar1[5],piVar1[6],piVar1[7],
                       (short)piVar1[0x85],*(undefined2 *)((int)piVar1 + 0x216),(short)piVar1[0x86],
                       *(undefined2 *)((int)piVar1 + 0x21a),(short)piVar1[0x87],
                       *(undefined2 *)((int)piVar1 + 0x21e),(short)piVar1[0x88],
                       *(undefined2 *)((int)piVar1 + 0x222),(short)piVar1[0x89],
                       *(undefined2 *)((int)piVar1 + 0x226),(short)piVar1[0x8a]);
          *(char *)(*(int *)((int)this + 0xd4) + 0x2368 + iVar3) = (char)piVar1[0xd7];
          break;
        }
        iVar2 = iVar2 + 1;
        piVar1 = piVar1 + 0xd8;
      } while (iVar2 < 6);
      if (iVar2 == 6) {
        local_100a = 2;
      }
      local_1004 = 0x14;
      local_1002 = local_100a;
      FUN_004038e0(*(void **)((int)this + 0x118),(ushort)param_1,3,(undefined4 *)&local_1004);
      FUN_0041b8b0(this,param_1);
      goto LAB_004200fe;
    }
    cVar5 = '\x01';
    uVar4 = 0x1e;
  }
  FUN_0041eb20(this,(ushort)param_1,uVar4,cVar5,1);
LAB_004200fe:
  FUN_00435e83(local_4);
  return;
}


