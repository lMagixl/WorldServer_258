
void __thiscall FUN_0041b700(void *this,char *param_1,int param_2,uint param_3)

{
  IPv4Address *pIVar1;
  IPv4Address local_38 [16];
  char local_28 [12];
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_28[8] = '\0';
  local_28[9] = '\0';
  local_28[10] = '\0';
  local_28[0xb] = '\0';
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_1c = param_3;
  local_28[0] = '(';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  local_28[4] = -0x43;
  local_28[5] = '\v';
  local_28[6] = '\0';
  local_28[7] = '\0';
  pIVar1 = (IPv4Address *)PerfLib::IPv4Address::IPv4Address(local_38,param_1,param_2);
  PerfLib::UdpSocket::SendTo
            ((UdpSocket *)((int)this + 0x14),pIVar1,local_28,0x28,&param_3,(_OVERLAPPED *)0x0);
  PerfLib::IPv4Address::~IPv4Address(local_38);
  return;
}



/* === METADATA ===
SIGNATURE: undefined __thiscall FUN_0041b700(void * this, char * param_1, int param_2, uint param_3)
XREFS: 0041cf65
CALLEES: SendTo ~IPv4Address IPv4Address
CALLERS: FUN_0041ce60
SIZE: 1009 chars */
