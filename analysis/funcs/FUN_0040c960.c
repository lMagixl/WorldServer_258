
uint __thiscall
FUN_0040c960(void *this,byte *param_1,int param_2,int param_3,byte *param_4,int param_5,int param_6,
            char *param_7,undefined2 *param_8)

{
  undefined2 *puVar1;
  
  if (*(char *)((int)this + 0x144c) == '\0') {
    return 1;
  }
  if (*(char *)((int)this + 0x144c) != '\x02') {
    FUN_0040bcb0(this,param_1,param_2,param_3,param_4,param_5,param_6,'\x01');
    puVar1 = (undefined2 *)FUN_0040bc50((int)this);
    *param_7 = (char)puVar1;
    if ((char)puVar1 != '\0') {
      *param_8 = *(undefined2 *)((int)this + 0x1550);
      param_8[1] = *(undefined2 *)((int)this + 0x1552);
      param_8[2] = *(undefined2 *)((int)this + 0x1554);
      param_8[3] = *(undefined2 *)((int)this + 0x1556);
      param_8[4] = *(undefined2 *)((int)this + 0x1558);
      param_8[5] = *(undefined2 *)((int)this + 0x155a);
      param_8[6] = *(undefined2 *)((int)this + 0x155c);
      param_8[7] = *(undefined2 *)((int)this + 0x155e);
      param_8[8] = *(undefined2 *)((int)this + 0x1560);
      param_8[9] = *(undefined2 *)((int)this + 0x1562);
      param_8[10] = *(undefined2 *)((int)this + 0x1564);
      puVar1 = param_8;
    }
    *(undefined1 *)((int)this + 0x144c) = 0;
    return (uint)puVar1 & 0xffffff00;
  }
  return 2;
}


