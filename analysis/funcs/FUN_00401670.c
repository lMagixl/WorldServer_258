
uint __cdecl FUN_00401670(uint *param_1,uint *param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_1c;
  
  if ((*(byte *)(param_3 + 0x208) & 1) == 0) {
    return param_3 + 8U & 0xffff0000;
  }
  uVar4 = *(uint *)(param_3 + 8U) ^ *param_1;
  local_1c = *(uint *)(param_3 + 0xc) ^ param_1[1];
  uVar5 = *(uint *)(param_3 + 0x10) ^ param_1[2];
  uVar3 = *(uint *)(param_3 + 0x14) ^ param_1[3];
  iVar1 = *(int *)(param_3 + 4);
  puVar2 = (uint *)(param_3 + 0x18);
  if (iVar1 != 10) {
    if (iVar1 != 0xc) {
      if (iVar1 != 0xe) goto LAB_00402761;
      uVar6 = *(uint *)(&DAT_00443148 + (uVar3 >> 0x18) * 4) ^
              *(uint *)(&DAT_00442d48 + (uVar5 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00442948 + (local_1c >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00442548 + (uVar4 & 0xff) * 4) ^ *puVar2;
      uVar7 = *(uint *)(&DAT_00442d48 + (uVar3 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00442948 + (uVar5 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00443148 + (uVar4 >> 0x18) * 4) ^
              *(uint *)(&DAT_00442548 + (local_1c & 0xff) * 4) ^ *(uint *)(param_3 + 0x1c);
      uVar8 = *(uint *)(&DAT_00442948 + (uVar3 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00443148 + (local_1c >> 0x18) * 4) ^
              *(uint *)(&DAT_00442d48 + (uVar4 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00442548 + (uVar5 & 0xff) * 4) ^ *(uint *)(param_3 + 0x20);
      uVar3 = *(uint *)(&DAT_00443148 + (uVar5 >> 0x18) * 4) ^
              *(uint *)(&DAT_00442d48 + (local_1c >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00442948 + (uVar4 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00442548 + (uVar3 & 0xff) * 4) ^ *(uint *)(param_3 + 0x24);
      uVar4 = *(uint *)(&DAT_00443148 + (uVar3 >> 0x18) * 4) ^
              *(uint *)(&DAT_00442d48 + (uVar8 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00442948 + (uVar7 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00442548 + (uVar6 & 0xff) * 4) ^ *(uint *)(param_3 + 0x28);
      local_1c = *(uint *)(&DAT_00442d48 + (uVar3 >> 0x10 & 0xff) * 4) ^
                 *(uint *)(&DAT_00442948 + (uVar8 >> 8 & 0xff) * 4) ^
                 *(uint *)(&DAT_00443148 + (uVar6 >> 0x18) * 4) ^
                 *(uint *)(&DAT_00442548 + (uVar7 & 0xff) * 4) ^ *(uint *)(param_3 + 0x2c);
      uVar5 = *(uint *)(&DAT_00442948 + (uVar3 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00443148 + (uVar7 >> 0x18) * 4) ^
              *(uint *)(&DAT_00442d48 + (uVar6 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00442548 + (uVar8 & 0xff) * 4) ^ *(uint *)(param_3 + 0x30);
      uVar3 = *(uint *)(&DAT_00443148 + (uVar8 >> 0x18) * 4) ^
              *(uint *)(&DAT_00442d48 + (uVar7 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00442948 + (uVar6 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00442548 + (uVar3 & 0xff) * 4) ^ *(uint *)(param_3 + 0x34);
      puVar2 = (uint *)(param_3 + 0x38);
    }
    uVar6 = *(uint *)(&DAT_00443148 + (uVar3 >> 0x18) * 4) ^
            *(uint *)(&DAT_00442d48 + (uVar5 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_00442948 + (local_1c >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_00442548 + (uVar4 & 0xff) * 4) ^ *puVar2;
    uVar7 = *(uint *)(&DAT_00442d48 + (uVar3 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_00442948 + (uVar5 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_00443148 + (uVar4 >> 0x18) * 4) ^
            *(uint *)(&DAT_00442548 + (local_1c & 0xff) * 4) ^ puVar2[1];
    uVar8 = *(uint *)(&DAT_00442948 + (uVar3 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_00443148 + (local_1c >> 0x18) * 4) ^
            *(uint *)(&DAT_00442d48 + (uVar4 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_00442548 + (uVar5 & 0xff) * 4) ^ puVar2[2];
    uVar3 = *(uint *)(&DAT_00443148 + (uVar5 >> 0x18) * 4) ^
            *(uint *)(&DAT_00442d48 + (local_1c >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_00442948 + (uVar4 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_00442548 + (uVar3 & 0xff) * 4) ^ puVar2[3];
    uVar4 = *(uint *)(&DAT_00443148 + (uVar3 >> 0x18) * 4) ^
            *(uint *)(&DAT_00442d48 + (uVar8 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_00442948 + (uVar7 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_00442548 + (uVar6 & 0xff) * 4) ^ puVar2[4];
    local_1c = *(uint *)(&DAT_00442d48 + (uVar3 >> 0x10 & 0xff) * 4) ^
               *(uint *)(&DAT_00442948 + (uVar8 >> 8 & 0xff) * 4) ^
               *(uint *)(&DAT_00443148 + (uVar6 >> 0x18) * 4) ^
               *(uint *)(&DAT_00442548 + (uVar7 & 0xff) * 4) ^ puVar2[5];
    uVar5 = puVar2[6] ^
            *(uint *)(&DAT_00442948 + (uVar3 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_00443148 + (uVar7 >> 0x18) * 4) ^
            *(uint *)(&DAT_00442d48 + (uVar6 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_00442548 + (uVar8 & 0xff) * 4);
    uVar3 = *(uint *)(&DAT_00443148 + (uVar8 >> 0x18) * 4) ^
            *(uint *)(&DAT_00442d48 + (uVar7 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_00442948 + (uVar6 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_00442548 + (uVar3 & 0xff) * 4) ^ puVar2[7];
    puVar2 = puVar2 + 8;
  }
  uVar6 = *(uint *)(&DAT_00443148 + (uVar3 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (local_1c >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar4 & 0xff) * 4) ^ *puVar2;
  uVar7 = *(uint *)(&DAT_00442d48 + (uVar3 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar4 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442548 + (local_1c & 0xff) * 4) ^ puVar2[1];
  uVar8 = *(uint *)(&DAT_00442948 + (uVar3 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (local_1c >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar5 & 0xff) * 4) ^ puVar2[2];
  uVar3 = *(uint *)(&DAT_00443148 + (uVar5 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (local_1c >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar3 & 0xff) * 4) ^ puVar2[3];
  uVar5 = *(uint *)(&DAT_00443148 + (uVar3 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar6 & 0xff) * 4) ^ puVar2[4];
  uVar9 = *(uint *)(&DAT_00442d48 + (uVar3 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar6 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar7 & 0xff) * 4) ^ puVar2[5];
  uVar10 = *(uint *)(&DAT_00442948 + (uVar3 >> 8 & 0xff) * 4) ^
           *(uint *)(&DAT_00443148 + (uVar7 >> 0x18) * 4) ^
           *(uint *)(&DAT_00442d48 + (uVar6 >> 0x10 & 0xff) * 4) ^
           *(uint *)(&DAT_00442548 + (uVar8 & 0xff) * 4) ^ puVar2[6];
  uVar6 = *(uint *)(&DAT_00443148 + (uVar8 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar3 & 0xff) * 4) ^ puVar2[7];
  uVar3 = *(uint *)(&DAT_00443148 + (uVar6 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar10 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar9 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar5 & 0xff) * 4) ^ puVar2[8];
  uVar4 = *(uint *)(&DAT_00442d48 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar10 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar5 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar9 & 0xff) * 4) ^ puVar2[9];
  uVar7 = *(uint *)(&DAT_00442948 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar9 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar10 & 0xff) * 4) ^ puVar2[10];
  uVar5 = *(uint *)(&DAT_00443148 + (uVar10 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar9 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar6 & 0xff) * 4) ^ puVar2[0xb];
  uVar6 = *(uint *)(&DAT_00443148 + (uVar5 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar3 & 0xff) * 4) ^ puVar2[0xc];
  uVar8 = *(uint *)(&DAT_00442d48 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar3 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar4 & 0xff) * 4) ^ puVar2[0xd];
  uVar9 = *(uint *)(&DAT_00442948 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar4 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar3 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar7 & 0xff) * 4) ^ puVar2[0xe];
  uVar5 = *(uint *)(&DAT_00443148 + (uVar7 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar3 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar5 & 0xff) * 4) ^ puVar2[0xf];
  uVar3 = *(uint *)(&DAT_00443148 + (uVar5 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar9 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar6 & 0xff) * 4) ^ puVar2[0x10];
  uVar4 = *(uint *)(&DAT_00442d48 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar9 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar6 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar8 & 0xff) * 4) ^ puVar2[0x11];
  uVar7 = *(uint *)(&DAT_00442948 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar8 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar9 & 0xff) * 4) ^ puVar2[0x12];
  uVar5 = *(uint *)(&DAT_00443148 + (uVar9 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar5 & 0xff) * 4) ^ puVar2[0x13];
  uVar6 = *(uint *)(&DAT_00443148 + (uVar5 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar3 & 0xff) * 4) ^ puVar2[0x14];
  uVar8 = *(uint *)(&DAT_00442d48 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar3 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar4 & 0xff) * 4) ^ puVar2[0x15];
  uVar9 = *(uint *)(&DAT_00442948 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar4 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar3 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar7 & 0xff) * 4) ^ puVar2[0x16];
  uVar5 = *(uint *)(&DAT_00443148 + (uVar7 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar3 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar5 & 0xff) * 4) ^ puVar2[0x17];
  uVar3 = *(uint *)(&DAT_00443148 + (uVar5 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar9 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar6 & 0xff) * 4) ^ puVar2[0x18];
  uVar4 = *(uint *)(&DAT_00442d48 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar9 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar6 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar8 & 0xff) * 4) ^ puVar2[0x19];
  uVar7 = *(uint *)(&DAT_00442948 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar8 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar9 & 0xff) * 4) ^ puVar2[0x1a];
  uVar5 = *(uint *)(&DAT_00443148 + (uVar9 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar5 & 0xff) * 4) ^ puVar2[0x1b];
  uVar8 = *(uint *)(&DAT_00443148 + (uVar5 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar3 & 0xff) * 4) ^ puVar2[0x1c];
  uVar9 = *(uint *)(&DAT_00442d48 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar3 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar4 & 0xff) * 4) ^ puVar2[0x1d];
  uVar10 = *(uint *)(&DAT_00442948 + (uVar5 >> 8 & 0xff) * 4) ^
           *(uint *)(&DAT_00443148 + (uVar4 >> 0x18) * 4) ^
           *(uint *)(&DAT_00442d48 + (uVar3 >> 0x10 & 0xff) * 4) ^
           *(uint *)(&DAT_00442548 + (uVar7 & 0xff) * 4) ^ puVar2[0x1e];
  uVar4 = *(uint *)(&DAT_00443148 + (uVar7 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar3 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar5 & 0xff) * 4) ^ puVar2[0x1f];
  uVar3 = *(uint *)(&DAT_00443148 + (uVar4 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar10 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar9 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar8 & 0xff) * 4) ^ puVar2[0x20];
  uVar6 = *(uint *)(&DAT_00442d48 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar10 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar8 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar9 & 0xff) * 4) ^ puVar2[0x21];
  uVar7 = *(uint *)(&DAT_00442948 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00443148 + (uVar9 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar10 & 0xff) * 4) ^ puVar2[0x22];
  uVar8 = *(uint *)(&DAT_00443148 + (uVar10 >> 0x18) * 4) ^
          *(uint *)(&DAT_00442d48 + (uVar9 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00442948 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00442548 + (uVar4 & 0xff) * 4) ^ puVar2[0x23];
  uVar4 = *(uint *)(&DAT_00445148 + (uVar8 >> 0x18) * 4) ^
          *(uint *)(&DAT_00444d48 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00444948 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00444548 + (uVar3 & 0xff) * 4) ^ puVar2[0x24];
  local_1c = *(uint *)(&DAT_00444d48 + (uVar8 >> 0x10 & 0xff) * 4) ^
             *(uint *)(&DAT_00444948 + (uVar7 >> 8 & 0xff) * 4) ^
             *(uint *)(&DAT_00445148 + (uVar3 >> 0x18) * 4) ^
             *(uint *)(&DAT_00444548 + (uVar6 & 0xff) * 4) ^ puVar2[0x25];
  uVar5 = *(uint *)(&DAT_00444948 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00445148 + (uVar6 >> 0x18) * 4) ^
          *(uint *)(&DAT_00444d48 + (uVar3 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00444548 + (uVar7 & 0xff) * 4) ^ puVar2[0x26];
  uVar3 = puVar2[0x27] ^
          *(uint *)(&DAT_00445148 + (uVar7 >> 0x18) * 4) ^
          *(uint *)(&DAT_00444d48 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_00444948 + (uVar3 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_00444548 + (uVar8 & 0xff) * 4);
LAB_00402761:
  param_2[1] = local_1c;
  param_2[2] = uVar5;
  *param_2 = uVar4;
  param_2[3] = uVar3;
  return CONCAT22((short)((uint)param_2 >> 0x10),1);
}



/* METADATA: sig=undefined4 __cdecl FUN_00401670(uint * param_1, uint * param_2, int param_3) xrefs=004010d3 callees= */
