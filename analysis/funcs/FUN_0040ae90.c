/* == FIELD OFFSET RESOLVER ==
   Returns pointer offsets into CUser field structure.
   Used by DB response handler to know where to write data blocks. */

void __thiscall
FUN_0040ae90(void *this,int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,
            int *param_6,int *param_7,int *param_8,int *param_9,int *param_10,int *param_11)

{
  *param_1 = (int)this + 0x14a8;
  *param_2 = (int)this + 0x157c;
  *param_3 = (int)this + 0x17a8;
  *param_4 = (int)this + 0x17ce;
  *param_5 = (int)this + 0x17e4;
  *param_6 = (int)this + 0x15c8;
  *param_7 = (int)this + 0x1830;
  *param_8 = (int)this + 0x1920;
  *param_9 = (int)this + 0x1998;
  *param_10 = (int)this + 0x2174;
  *param_11 = (int)this + 0x2304;
  return;
}
