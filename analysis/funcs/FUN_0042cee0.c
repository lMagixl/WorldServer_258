
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* == SERVER INITIALIZATION CORE ==
   Main function that initializes all server components.
   Reads config, sets up database, network (IOCP), worker threads, and begins listening for
   connections. */

void __fastcall FUN_0042cee0(void *param_1)

{
  char *lpReturnedString;
  char cVar1;
  DWORD DVar2;
  undefined4 uVar3;
  DWORD DVar4;
  bool bVar5;
  u_short uVar6;
  DWORD DVar7;
  UINT UVar8;
  uint uVar9;
  undefined4 uVar10;
  LPSTR pCVar11;
  HANDLE pvVar12;
  BOOL BVar13;
  void *pvVar14;
  ulong uVar15;
  uint *puVar16;
  UINT UVar17;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  byte bVar18;
  int unaff_EBP;
  char *unaff_ESI;
  ushort uVar19;
  int iVar20;
  uint param2;
  void *unaff_retaddr;
  UINT in_stack_fffffdf8;
  char acStack_200 [4];
  uint uStack_1fc;
  uint *puStack_1f8;
  undefined1 *puStack_1f4;
  DWORD aDStack_1f0 [2];
  char acStack_1e8 [4];
  CHAR aCStack_1e4 [32];
  CHAR aCStack_1c4 [20];
  CHAR aCStack_1b0 [44];
  CHAR aCStack_184 [128];
  CHAR aCStack_104 [128];
  char acStack_84 [12];
  undefined1 auStack_78 [104];
  int local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &LAB_004413c3;
  pvStack_c = ExceptionList;
  local_10 = DAT_00454928;
  ExceptionList = &pvStack_c;
  DVar7 = GetTickCount();
  FUN_004364c8(DVar7);
  *(undefined4 *)((int)param_1 + 0x5afc) = 0;
  *(undefined4 *)((int)param_1 + 0x5b04) = 0;
  *(undefined4 *)((int)param_1 + 0x5b00) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x5b08) = 0;
  *(undefined4 *)((int)param_1 + 0x5b0c) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x5b10) = 0;
  *(undefined4 *)((int)param_1 + 0x5b14) = 0;
  DVar7 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)&lpFilename_00455c30,0x400);
  DVar4 = DVar7;
  if (DVar7 == 0) goto LAB_0042d378;
  do {
    DVar2 = DVar4;
    if ((int)(DVar2 - 1) < 0) goto LAB_0042cf87;
    DVar4 = DVar2 - 1;
  } while ((&DAT_00455c2f)[DVar2] != '\\');
  *(undefined1 *)((int)&lpFilename_00455c30 + DVar2) = 0;
  DVar7 = DVar2;
LAB_0042cf87:
  __mbsnbcpy((uchar *)&lpFileName_00455830,(uchar *)&lpFilename_00455c30,DVar7);
  uVar10 = s_worldserver_ini_0044cc10._4_4_;
  *(undefined4 *)((int)&lpFileName_00455830 + DVar7) = s_worldserver_ini_0044cc10._0_4_;
  uVar3 = s_worldserver_ini_0044cc10._8_4_;
  *(undefined4 *)(&DAT_00455834 + DVar7) = uVar10;
  uVar10 = s_worldserver_ini_0044cc10._12_4_;
  *(undefined4 *)(&DAT_00455838 + DVar7) = uVar3;
  *(undefined4 *)(&DAT_0045583c + DVar7) = uVar10;
  *(undefined4 *)((int)param_1 + 0x51ac) = 0;
  *(undefined4 *)((int)param_1 + 0x51b0) = 0;
  bVar5 = FUN_0042fd90(DAT_00456d84,s_FlexDbConn_0044cbf4,s_MaxDbConnection_0044cc00,
                       (UINT *)&stack0xfffffdf8);
  if (bVar5) {
    *(UINT *)((int)param_1 + 0x5358) = in_stack_fffffdf8;
    bVar5 = FUN_0042fd90(DAT_00456d84,s_FlexDbConn_0044cbf4,s_DbConnAdjustFreq_0044cbbc,
                         (UINT *)&stack0xfffffdf8);
    if (bVar5) {
      *(UINT *)((int)param_1 + 0x535c) = in_stack_fffffdf8;
      bVar5 = FUN_0042fd90(DAT_00456d84,s_FlexDbConn_0044cbf4,s_DbConnIncrease_0044cb84,
                           (UINT *)&stack0xfffffdf8);
      if (bVar5) {
        *(UINT *)((int)param_1 + 0x5360) = in_stack_fffffdf8;
        bVar5 = FUN_0042fd90(DAT_00456d84,s_FlexDbConn_0044cbf4,s_DbConnDecrease_0044cb50,
                             (UINT *)&stack0xfffffdf8);
        if (bVar5) {
          *(UINT *)((int)param_1 + 0x5364) = in_stack_fffffdf8;
          bVar5 = FUN_0042fd90(DAT_00456d84,s_Server_0044cb18,s_ServerId_0044cb20,
                               (UINT *)&stack0xfffffdf8);
          if (bVar5) {
            *(char *)((int)param_1 + 0x54) = (char)in_stack_fffffdf8;
            UVar8 = GetPrivateProfileIntA
                              (s_Authentication_0044caf0,(LPCSTR)&lpKeyName_0044cb00,0,
                               (LPCSTR)&lpFileName_00455830);
            lpReturnedString = (char *)((int)param_1 + 0x5b1c);
            *(UINT *)((int)param_1 + 0x5b18) = UVar8;
            GetPrivateProfileStringA
                      (s_Authentication_0044caf0,(LPCSTR)&lpKeyName_0044cadc,s_127_0_0_1_0044cae4,
                       lpReturnedString,0x100,(LPCSTR)&lpFileName_00455830);
            UVar8 = GetPrivateProfileIntA
                              (s_Authentication_0044caf0,(LPCSTR)&lpKeyName_0044cad4,0,
                               (LPCSTR)&lpFileName_00455830);
            *(UINT *)((int)param_1 + 0x5c1c) = UVar8;
            GetPrivateProfileStringA
                      (s_Authentication_0044caf0,s_AuthPage_0044cabc,s__auth_asp_0044cac8,
                       (LPSTR)((int)param_1 + 0x5c20),0x100,(LPCSTR)&lpFileName_00455830);
            UVar8 = GetPrivateProfileIntA
                              (s_Authentication_0044caf0,s_Secured_0044cab4,0,
                               (LPCSTR)&lpFileName_00455830);
            *(UINT *)((int)param_1 + 0x5d20) = UVar8;
            if (*(int *)((int)param_1 + 0x5b18) == 1) {
              _sprintf((char *)&puStack_1f4,s_RGS__u_0044ca7c,(uint)*(byte *)((int)param_1 + 0x54));
              puStack_1f4 = &stack0xfffffdd8;
              FUN_0040dbe0(&stack0xfffffdd8,acStack_1e8);
              puStack_1f8 = (uint *)&stack0xfffffdac;
              FUN_0040dbe0(&stack0xfffffdac,lpReturnedString);
              uVar9 = PerfLib::AsyncWebRequest::Initialize
                                ((AsyncWebRequest *)((int)param_1 + 0x5d24));
              if (uVar9 == 0) goto LAB_0042d219;
              unaff_EBP = 0;
              unaff_ESI = s_Authentication_initialize_failed_0044ca84;
            }
            else if ((*(int *)((int)param_1 + 0x5b18) != 2) ||
                    (uVar9 = FUN_0042ce50((void *)((int)param_1 + 0x5e5c),lpReturnedString,
                                          *(int *)((int)param_1 + 0x5c1c)), uVar9 == 0)) {
LAB_0042d219:
              uVar9 = FUN_0042fdc0(DAT_00456d84,s_Client_0044bf94,s_MD5_1_0044bf9c,
                                   (LPSTR)((int)param_1 + 300),0x21);
              if ((char)uVar9 == '\0') {
                unaff_EBP = 0;
                unaff_ESI = s_Error_MD5_1_0044ca70;
              }
              else {
                uVar9 = FUN_0042fdc0(DAT_00456d84,s_Client_0044bf94,s_MD5_2_0044bf8c,
                                     (LPSTR)((int)param_1 + 0x14d),0x21);
                if ((char)uVar9 == '\0') {
                  unaff_EBP = 0;
                  unaff_ESI = s_Error_MD5_2_0044ca64;
                }
                else {
                  uVar10 = FUN_0042f860((int *)((int)param_1 + 0x2178));
                  if ((char)uVar10 == '\0') {
                    unaff_EBP = 0;
                    unaff_ESI = s_Failed_to_initialized_mail_sende_0044ca40;
                  }
                  else {
                    uVar9 = FUN_0042fdc0(DAT_00456d84,s_EMail_0044ca20,
                                         s_CharacterDeleteSubject_0044ca28,
                                         (LPSTR)((int)param_1 + 0x267c),0x400);
                    if ((char)uVar9 == '\0') {
                      unaff_EBP = 0;
                      unaff_ESI = s_Error_CharacterDeleteSubject_0044ca00;
                    }
                    else {
                      pCVar11 = (LPSTR)((int)param_1 + 0x176);
                      uVar9 = FUN_0042fdc0(DAT_00456d84,s_EMail_0044ca20,
                                           s_CharacterDeleteBodyFileName_0044c9e4,pCVar11,0x400);
                      if ((char)uVar9 == '\0') {
                        unaff_EBP = 0;
                        unaff_ESI = s_Error_CharacterDeleteBodyFileNam_0044c9c0;
                      }
                      else {
                        __mbsnbcpy((uchar *)((int)param_1 + 0x2a7c),(uchar *)&lpFilename_00455c30,
                                   DVar7);
                        iVar20 = DVar7 - (int)pCVar11;
                        do {
                          cVar1 = *pCVar11;
                          pCVar11[iVar20 + 0x2a7c + (int)param_1] = cVar1;
                          pCVar11 = pCVar11 + 1;
                        } while (cVar1 != '\0');
                        pvVar12 = CreateFileA((LPCSTR)((int)param_1 + 0x2a7c),0x80000000,2,
                                              (LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
                        if (pvVar12 != (HANDLE)0xffffffff) {
                          SetFilePointer(pvVar12,0,(PLONG)0x0,0);
                          BVar13 = ReadFile(pvVar12,(LPVOID)((int)param_1 + 0x2e7c),0x2000,
                                            (LPDWORD)&puStack_1f4,(LPOVERLAPPED)0x0);
                          if (BVar13 != 0) {
                            (puStack_1f4 + 0x2e7c)[(int)param_1] = 0;
                            CloseHandle(pvVar12);
                            bVar5 = FUN_0042fd90(DAT_00456d84,s_Debug_0044c974,
                                                 s_EnableDebugThread_0044c97c,&uStack_1fc);
                            *(uint *)((int)param_1 + 0x53a8) = -(uint)bVar5 & uStack_1fc;
                            bVar5 = FUN_0042fd90(DAT_00456d84,s_ServerList_0044c960,s_Count_0044c96c
                                                 ,&uStack_1fc);
                            if (bVar5) {
                              *(undefined1 *)((int)param_1 + 0x55) = (undefined1)uStack_1fc;
                              pvVar14 = operator_new((uStack_1fc & 0xff) << 2);
                              *(void **)((int)param_1 + 0x58) = pvVar14;
                              pvVar14 = operator_new((uint)*(byte *)((int)param_1 + 0x55) << 1);
                              *(void **)((int)param_1 + 0x5c) = pvVar14;
                              if (((*(int *)((int)param_1 + 0x58) != 0) && (pvVar14 != (void *)0x0))
                                 && (bVar18 = 0, *(char *)((int)param_1 + 0x55) != '\0')) {
                                do {
                                  param2 = (uint)bVar18;
                                  _sprintf(acStack_200,&DAT_0044c94c,param2);
                                  uVar9 = FUN_0042fdc0(DAT_00456d84,s_ServerList_0044c960,
                                                       (LPCSTR)&puStack_1f4,aCStack_1e4,0x11);
                                  if ((char)uVar9 == '\0') {
LAB_0042d513:
                                    unaff_EBP = 0;
                                    unaff_ESI = s_Error_ServerList_0044c918;
                                    goto LAB_0042d368;
                                  }
                                  uVar15 = inet_addr(aCStack_1e4);
                                  *(ulong *)(*(int *)((int)param_1 + 0x58) + param2 * 4) = uVar15;
                                  _sprintf((char *)&puStack_1f4,s_Port_u_0044c944,param2);
                                  bVar5 = FUN_0042fd90(DAT_00456d84,s_ServerList_0044c960,
                                                       acStack_1e8,&uStack_1fc);
                                  if (!bVar5) goto LAB_0042d513;
                                  uVar6 = htons((u_short)uStack_1fc);
                                  *(u_short *)(*(int *)((int)param_1 + 0x5c) + param2 * 2) = uVar6;
                                  bVar18 = bVar18 + 1;
                                } while (bVar18 < *(byte *)((int)param_1 + 0x55));
                              }
                              bVar5 = FUN_0042fd90(DAT_00456d84,s_Server_0044cb18,s_MaxUser_0044c93c
                                                   ,&uStack_1fc);
                              if (bVar5) {
                                DAT_00455828 = CONCAT22(DAT_00455828._2_2_,(undefined2)uStack_1fc);
                                UVar8 = GetPrivateProfileIntA
                                                  (s_Server_0044cb18,s_MaxField_0044c90c,0,
                                                   (LPCSTR)&lpFileName_00455830);
                                _DAT_00455820 = (undefined2)((DAT_00455828 & 0xffff) / 10);
                                DAT_00456030 = (ushort)DAT_00455828 + 500;
                                if (UVar8 == 0) {
                                  DAT_00455824 = (ushort)DAT_00455828 >> 2;
                                }
                                else {
                                  DAT_00455824 = (ushort)UVar8;
                                }
                                uVar9 = (uint)DAT_00456030;
                                puStack_1f8 = operator_new(uVar9 * 0x23b4 + 4);
                                if (puStack_1f8 == (uint *)0x0) {
                                  puVar16 = (uint *)0x0;
                                }
                                else {
                                  puVar16 = puStack_1f8 + 1;
                                  *puStack_1f8 = uVar9;
                                  _eh_vector_constructor_iterator_
                                            (puVar16,0x23b4,uVar9,FUN_0040e680,FUN_0040e560);
                                }
                                *(uint **)((int)param_1 + 0xd4) = puVar16;
                                if (puVar16 == (uint *)0x0) {
                                  unaff_ESI = s_Error_Server_Start7_0044c8f8;
                                  unaff_EBP = 0;
                                }
                                else {
                                  puStack_1f8 = operator_new(0x1f594);
                                  if (puStack_1f8 == (uint *)0x0) {
                                    puVar16 = (uint *)0x0;
                                  }
                                  else {
                                    puVar16 = puStack_1f8 + 1;
                                    *puStack_1f8 = 0x96;
                                    _eh_vector_constructor_iterator_
                                              (puVar16,0x358,0x96,
                                               (_func_void_void_ptr *)&LAB_00404f60,
                                               PerfLib::IPv4Address::~IPv4Address);
                                  }
                                  *(uint **)((int)param_1 + 0xdc) = puVar16;
                                  if (puVar16 == (uint *)0x0) {
                                    unaff_ESI = s_Error_Server_Start8_0044c8e4;
                                    unaff_EBP = 0;
                                  }
                                  else {
                                    bVar18 = 0;
                                    puStack_1f4 = (undefined1 *)((uint)puStack_1f4 & 0xffffff00);
                                    iVar20 = 0;
                                    do {
                                      FUN_00404d60((void *)(*(int *)((int)param_1 + 0xdc) + iVar20),
                                                   (char)puStack_1f4);
                                      bVar18 = bVar18 + 1;
                                      iVar20 = iVar20 + 0x358;
                                      puStack_1f4 = (undefined1 *)CONCAT31(puStack_1f4._1_3_,bVar18)
                                      ;
                                    } while (bVar18 < 0x96);
                                    *(undefined1 *)((int)param_1 + 0xd8) = 0x28;
                                    bVar18 = 0;
                                    do {
                                      wsprintfA(aCStack_1b0,s_channel_02u_0044c8d8);
                                      FUN_00404d70((void *)((uint)bVar18 * 0x358 +
                                                           *(int *)((int)param_1 + 0xdc)),
                                                   aCStack_1b0);
                                      bVar18 = bVar18 + 1;
                                    } while (bVar18 < *(byte *)((int)param_1 + 0xd8));
                                    uVar9 = (uint)DAT_00455824;
                                    puStack_1f8 = operator_new(uVar9 * 0x3c0 + 4);
                                    if (puStack_1f8 == (uint *)0x0) {
                                      puVar16 = (uint *)0x0;
                                    }
                                    else {
                                      puVar16 = puStack_1f8 + 1;
                                      *puStack_1f8 = uVar9;
                                      _eh_vector_constructor_iterator_
                                                (puVar16,0x3c0,uVar9,FUN_00406D80,
                                                 PerfLib::IPv4Address::~IPv4Address);
                                    }
                                    *(uint **)((int)param_1 + 0xe4) = puVar16;
                                    if (puVar16 == (uint *)0x0) {
                                      unaff_ESI = s_Error_Server_Start11_0044c8c0;
                                      unaff_EBP = 0;
                                    }
                                    else {
                                      uVar19 = 0;
                                      if (DAT_00455824 != 0) {
                                        do {
                                          FUN_00405430((void *)((uint)uVar19 * 0x3c0 +
                                                               *(int *)((int)param_1 + 0xe4)),uVar19
                                                      );
                                          uVar19 = uVar19 + 1;
                                        } while (uVar19 < DAT_00455824);
                                      }
                                      DVar7 = GetPrivateProfileStringA
                                                        (s_Broker_0044c8b4,
                                                         (LPCSTR)&lpKeyName_0044c8bc,(LPCSTR)0x0,
                                                         aCStack_1c4,0x11,
                                                         (LPCSTR)&lpFileName_00455830);
                                      if (DVar7 == 0) {
                                        unaff_ESI = s_Error_Server_Start13_0044c89c;
                                        unaff_EBP = 0;
                                      }
                                      else {
                                        uVar15 = inet_addr(aCStack_1c4);
                                        *(ulong *)((int)param_1 + 0xec) = uVar15;
                                        UVar8 = GetPrivateProfileIntA
                                                          (s_Broker_0044c8b4,
                                                           (LPCSTR)&lpKeyName_0044cad4,0,
                                                           (LPCSTR)&lpFileName_00455830);
                                        uVar6 = (u_short)UVar8;
                                        *(u_short *)((int)param_1 + 0xf0) = uVar6;
                                        if (uVar6 == 0) {
                                          unaff_EBP = 0;
                                          unaff_ESI = s_Error_Server_Start14_0044c884;
                                        }
                                        else {
                                          uVar6 = htons(uVar6);
                                          *(u_short *)((int)param_1 + 0xf0) = uVar6;
                                          pvVar12 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,
                                                                 (LPCSTR)0x0);
                                          *(HANDLE *)((int)param_1 + 0xf4) = pvVar12;
                                          if (pvVar12 == (HANDLE)0x0) {
                                            unaff_ESI = s_Failed_to_CreateEvent___0044c86c;
                                            unaff_EBP = 0;
                                          }
                                          else {
                                            DVar7 = GetPrivateProfileStringA
                                                              ((LPCSTR)&lpAppName_0044c868,
                                                               (LPCSTR)&lpKeyName_0044c8bc,
                                                               (LPCSTR)0x0,
                                                               (LPSTR)((int)param_1 + 0x4e98),0x30,
                                                               (LPCSTR)&lpFileName_00455830);
                                            if (DVar7 == 0) {
                                              unaff_ESI = s_Error_Server_Start16_0044c850;
                                              unaff_EBP = 0;
                                            }
                                            else {
                                              UVar8 = GetPrivateProfileIntA
                                                                ((LPCSTR)&lpAppName_0044c868,
                                                                 (LPCSTR)&lpKeyName_0044cad4,0,
                                                                 (LPCSTR)&lpFileName_00455830);
                                              *(UINT *)((int)param_1 + 0x4f28) = UVar8;
                                              if (UVar8 == 0) {
                                                unaff_ESI = s_Error_Server_Start17_0044c838;
                                                unaff_EBP = 0;
                                              }
                                              else {
                                                DVar7 = GetPrivateProfileStringA
                                                                  ((LPCSTR)&lpAppName_0044c868,
                                                                   (LPCSTR)&lpKeyName_0044c830,
                                                                   (LPCSTR)0x0,
                                                                   (LPSTR)((int)param_1 + 0x4ec8),
                                                                   0x30,(LPCSTR)&lpFileName_00455830
                                                                  );
                                                if (DVar7 == 0) {
                                                  unaff_ESI = s_Error_Server_Start18_0044c818;
                                                  unaff_EBP = 0;
                                                }
                                                else {
                                                  DVar7 = GetPrivateProfileStringA
                                                                    ((LPCSTR)&lpAppName_0044c868,
                                                                     (LPCSTR)&lpKeyName_0044c810,
                                                                     (LPCSTR)0x0,
                                                                     (LPSTR)((int)param_1 + 0x4ef8),
                                                                     0x30,(LPCSTR)&
                                                  lpFileName_00455830);
                                                  if (DVar7 == 0) {
                                                    unaff_ESI = s_Error_Server_Start19_0044c7f8;
                                                    unaff_EBP = 0;
                                                  }
                                                  else {
                                                    DVar7 = GetPrivateProfileStringA
                                                                      ((LPCSTR)&lpAppName_0044c868,
                                                                       (LPCSTR)&lpKeyName_0044c7f0,
                                                                       (LPCSTR)0x0,
                                                                       (LPSTR)((int)param_1 + 0x4f2c
                                                                              ),0x30,
                                                                       (LPCSTR)&lpFileName_00455830)
                                                    ;
                                                    if (DVar7 == 0) {
                                                      unaff_ESI = s_Error_Server_Start20_0044c7d8;
                                                      unaff_EBP = 0;
                                                    }
                                                    else {
                                                      UVar8 = GetPrivateProfileIntA
                                                                        (s_Queue_0044c7c4,
                                                                         s_DbRecvQueue_0044c7cc,0,
                                                                         (LPCSTR)&
                                                  lpFileName_00455830);
                                                  if (UVar8 == 0) {
                                                    unaff_ESI = 
                                                  s__Queue__DbRecvQueue_failed_0044c7a8;
                                                  unaff_EBP = 0;
                                                  }
                                                  else {
                                                    puStack_1f4 = (undefined1 *)
                                                                  CONCAT31(puStack_1f4._1_3_,
                                                                           *(char *)((int)param_1 +
                                                                                    0x4e7c));
                                                    *(char *)((int)param_1 + 0x4e7c) =
                                                         *(char *)((int)param_1 + 0x4e7c) + '\x01';
                                                    puStack_1f8 = operator_new(0x34);
                                                    if (puStack_1f8 == (uint *)0x0) {
                                                      puVar16 = (uint *)0x0;
                                                    }
                                                    else {
                                                      puVar16 = FUN_0042e490(puStack_1f8,puStack_1f4
                                                                             ,UVar8,4000);
                                                    }
                                                    *(uint **)((int)param_1 + 0xf8) = puVar16;
                                                    if (puVar16 == (uint *)0x0) {
                                                      unaff_ESI = 
                                                  s_Failed_to_create_m_pbfmDBResultB_0044c784;
                                                  unaff_EBP = 0;
                                                  }
                                                  else {
                                                    UVar8 = GetPrivateProfileIntA
                                                                      (s_Queue_0044c7c4,
                                                                       s_DbSendQueue_0044c778,0,
                                                                       (LPCSTR)&lpFileName_00455830)
                                                    ;
                                                    if (UVar8 == 0) {
                                                      unaff_ESI = 
                                                  s__Queue__DbSendQueue1_failed_0044c75c;
                                                  unaff_EBP = 0;
                                                  }
                                                  else {
                                                    puStack_1f4 = (undefined1 *)
                                                                  CONCAT31(puStack_1f4._1_3_,
                                                                           *(char *)((int)param_1 +
                                                                                    0x4e7c));
                                                    *(char *)((int)param_1 + 0x4e7c) =
                                                         *(char *)((int)param_1 + 0x4e7c) + '\x01';
                                                    puStack_1f8 = operator_new(0x34);
                                                    if (puStack_1f8 == (uint *)0x0) {
                                                      puVar16 = (uint *)0x0;
                                                    }
                                                    else {
                                                      puVar16 = FUN_0042e490(puStack_1f8,puStack_1f4
                                                                             ,UVar8,4000);
                                                    }
                                                    *(uint **)((int)param_1 + 0xfc) = puVar16;
                                                    if (puVar16 == (uint *)0x0) {
                                                      unaff_ESI = 
                                                  s_Failed_to_create_m_pbfmDBCommand_0044c738;
                                                  unaff_EBP = 0;
                                                  }
                                                  else {
                                                    DVar7 = GetPrivateProfileStringA
                                                                      (s_USERDB_0044c730,
                                                                       (LPCSTR)&lpKeyName_0044c8bc,
                                                                       (LPCSTR)0x0,
                                                                       (LPSTR)((int)param_1 + 0x4f5c
                                                                              ),0x11,
                                                                       (LPCSTR)&lpFileName_00455830)
                                                    ;
                                                    if (DVar7 == 0) {
LAB_0042dada:
                                                      unaff_EBP = 0;
                                                      unaff_ESI = s_Error_Server_Start46_0044c710;
                                                    }
                                                    else {
                                                      UVar8 = GetPrivateProfileIntA
                                                                        (s_USERDB_0044c730,
                                                                         (LPCSTR)&lpKeyName_0044cad4
                                                                         ,0,(LPCSTR)&
                                                  lpFileName_00455830);
                                                  *(UINT *)((int)param_1 + 0x4fec) = UVar8;
                                                  if (UVar8 == 0) {
LAB_0042db03:
                                                    unaff_EBP = 0;
                                                    unaff_ESI = s_Error_Server_Start47_0044c6f8;
                                                  }
                                                  else {
                                                    DVar7 = GetPrivateProfileStringA
                                                                      (s_USERDB_0044c730,
                                                                       (LPCSTR)&lpKeyName_0044c830,
                                                                       (LPCSTR)0x0,
                                                                       (LPSTR)((int)param_1 + 0x4f8c
                                                                              ),0x15,
                                                                       (LPCSTR)&lpFileName_00455830)
                                                    ;
                                                    if (DVar7 == 0) {
LAB_0042db2f:
                                                      unaff_EBP = 0;
                                                      unaff_ESI = s_Error_Server_Start48_0044c6e0;
                                                    }
                                                    else {
                                                      DVar7 = GetPrivateProfileStringA
                                                                        (s_USERDB_0044c730,
                                                                         (LPCSTR)&lpKeyName_0044c810
                                                                         ,(LPCSTR)0x0,
                                                                         (LPSTR)((int)param_1 +
                                                                                0x4fbc),0x15,
                                                                         (LPCSTR)&
                                                  lpFileName_00455830);
                                                  if (DVar7 == 0) {
LAB_0042db5b:
                                                    unaff_EBP = 0;
                                                    unaff_ESI = s_Error_Server_Start49_0044c6c8;
                                                  }
                                                  else {
                                                    DVar7 = GetPrivateProfileStringA
                                                                      (s_USERDB_0044c730,
                                                                       (LPCSTR)&lpKeyName_0044c7f0,
                                                                       (LPCSTR)0x0,
                                                                       (LPSTR)((int)param_1 + 0x4ff0
                                                                              ),0x15,
                                                                       (LPCSTR)&lpFileName_00455830)
                                                    ;
                                                    if (DVar7 != 0) {
                                                      DVar7 = GetPrivateProfileStringA
                                                                        (s_LOGDB_0044c728,
                                                                         (LPCSTR)&lpKeyName_0044c8bc
                                                                         ,(LPCSTR)0x0,
                                                                         (LPSTR)((int)param_1 +
                                                                                0x5020),0x11,
                                                                         (LPCSTR)&
                                                  lpFileName_00455830);
                                                  if (DVar7 == 0) goto LAB_0042dada;
                                                  UVar8 = GetPrivateProfileIntA
                                                                    (s_LOGDB_0044c728,
                                                                     (LPCSTR)&lpKeyName_0044cad4,0,
                                                                     (LPCSTR)&lpFileName_00455830);
                                                  *(UINT *)((int)param_1 + 0x50b0) = UVar8;
                                                  if (UVar8 == 0) goto LAB_0042db03;
                                                  DVar7 = GetPrivateProfileStringA
                                                                    (s_LOGDB_0044c728,
                                                                     (LPCSTR)&lpKeyName_0044c830,
                                                                     (LPCSTR)0x0,
                                                                     (LPSTR)((int)param_1 + 0x5050),
                                                                     0x15,(LPCSTR)&
                                                  lpFileName_00455830);
                                                  if (DVar7 == 0) goto LAB_0042db2f;
                                                  DVar7 = GetPrivateProfileStringA
                                                                    (s_LOGDB_0044c728,
                                                                     (LPCSTR)&lpKeyName_0044c810,
                                                                     (LPCSTR)0x0,
                                                                     (LPSTR)((int)param_1 + 0x5080),
                                                                     0x15,(LPCSTR)&
                                                  lpFileName_00455830);
                                                  if (DVar7 == 0) goto LAB_0042db5b;
                                                  DVar7 = GetPrivateProfileStringA
                                                                    (s_LOGDB_0044c728,
                                                                     (LPCSTR)&lpKeyName_0044c7f0,
                                                                     (LPCSTR)0x0,
                                                                     (LPSTR)((int)param_1 + 0x50b4),
                                                                     0x15,(LPCSTR)&
                                                  lpFileName_00455830);
                                                  if (DVar7 != 0) {
                                                    *(undefined1 *)((int)param_1 + 0x50e4) = 0;
                                                    *(undefined4 *)((int)param_1 + 0x5174) = 0;
                                                    *(undefined1 *)((int)param_1 + 0x5114) = 0;
                                                    *(undefined1 *)((int)param_1 + 0x5144) = 0;
                                                    *(undefined1 *)((int)param_1 + 0x5178) = 0;
                                                    pvVar14 = operator_new(0x50);
                                                    *(void **)((int)param_1 + 0x4e84) = pvVar14;
                                                    uVar9 = 0;
                                                    do {
                                                      *(undefined4 *)
                                                       (uVar9 + *(int *)((int)param_1 + 0x4e84)) = 0
                                                      ;
                                                      uVar9 = uVar9 + 4;
                                                    } while (uVar9 < 0x50);
                                                    puStack_1f8 = operator_new(0x38);
                                                    if (puStack_1f8 == (uint *)0x0) {
                                                      uVar10 = 0;
                                                    }
                                                    else {
                                                      uVar10 = FUN_0040e880((int)puStack_1f8);
                                                    }
                                                    **(undefined4 **)((int)param_1 + 0x4e84) =
                                                         uVar10;
                                                    if ((void *)**(undefined4 **)
                                                                  ((int)param_1 + 0x4e84) ==
                                                        (void *)0x0) {
                                                      unaff_ESI = 
                                                  s_Failed_to_create_m_DbHandlers_0__0044c68c;
                                                  unaff_EBP = 0;
                                                  }
                                                  else {
                                                    iVar20 = FUN_0041b520((void *)**(undefined4 **)
                                                                                    ((int)param_1 +
                                                                                    0x4e84),
                                                                          *(DWORD *)((int)param_1 +
                                                                                    0xf4),
                                                                          (int)param_1 + 0x4e98,
                                                                          *(undefined4 *)
                                                                           ((int)param_1 + 0x4f28),
                                                                          (int)param_1 + 0x4ec8,
                                                                          (int)param_1 + 0x4ef8,
                                                                          (int)param_1 + 0x4f2c,
                                                                          (int)param_1 + 0x4f5c,
                                                                          *(undefined4 *)
                                                                           ((int)param_1 + 0x4fec),
                                                                          (int)param_1 + 0x4f8c,
                                                                          (int)param_1 + 0x4fbc,
                                                                          (int)param_1 + 0x4ff0,
                                                                          (int)param_1 + 0x5020,
                                                                          *(undefined4 *)
                                                                           ((int)param_1 + 0x50b0),
                                                                          (int)param_1 + 0x5050,
                                                                          (int)param_1 + 0x5080,
                                                                          (int)param_1 + 0x50b4);
                                                    if (iVar20 == 0) {
                                                      unaff_ESI = 
                                                  s_Failed_to_Start___m_DbHandlers_0_0044c668;
                                                  unaff_EBP = 0;
                                                  }
                                                  else {
                                                    *(undefined4 *)((int)param_1 + 0x4e80) = 1;
                                                    *(undefined1 *)((int)param_1 + 0x4e) = 1;
                                                    iVar20 = FUN_0040f850((void *)**(undefined4 **)
                                                                                    ((int)param_1 +
                                                                                    0x4e84),
                                                                          (byte *)((int)param_1 +
                                                                                  0x60),
                                                                          (int *)((int)param_1 + 100
                                                                                 ),(int *)((int)
                                                  param_1 + 0x68));
                                                  if (iVar20 == 0) {
                                                    unaff_ESI = s_Error_Server_Start28_0044c650;
                                                    unaff_EBP = 0;
                                                  }
                                                  else {
                                                    puStack_1f8 = operator_new(0x130);
                                                    if (puStack_1f8 == (uint *)0x0) {
                                                      puVar16 = (uint *)0x0;
                                                    }
                                                    else {
                                                      puVar16 = puStack_1f8 + 1;
                                                      *puStack_1f8 = 100;
                                                      _eh_vector_constructor_iterator_
                                                                (puVar16,3,100,
                                                                 (_func_void_void_ptr *)
                                                                 &LAB_0040a890,
                                                                 PerfLib::IPv4Address::~IPv4Address)
                                                      ;
                                                    }
                                                    *(int *)((int)param_1 + 0xe8) = (int)puVar16;
                                                    iVar20 = FUN_0040fa90((void *)**(undefined4 **)
                                                                                    ((int)param_1 +
                                                                                    0x4e84),
                                                                          (int *)((int)param_1 +
                                                                                 0xe8));
                                                    if (iVar20 == 0) {
                                                      unaff_ESI = s_Error_Server_Start29_0044c638;
                                                      unaff_EBP = 0;
                                                    }
                                                    else {
                                                      puStack_1f8 = operator_new(0x838);
                                                      if (puStack_1f8 == (uint *)0x0) {
                                                        puVar16 = (uint *)0x0;
                                                      }
                                                      else {
                                                        puVar16 = puStack_1f8 + 1;
                                                        *puStack_1f8 = 5;
                                                        _eh_vector_constructor_iterator_
                                                                  (puVar16,0x1a4,5,
                                                                   (_func_void_void_ptr *)
                                                                   &LAB_00405390,
                                                                   (_func_void_void_ptr *)
                                                                   &LAB_004053e0);
                                                      }
                                                      *(int *)((int)param_1 + 0x100) = (int)puVar16;
                                                      iVar20 = FUN_0040fc30((void *)**(undefined4 **
                                                                                      )((int)param_1
                                                                                       + 0x4e84),
                                                                            (int *)((int)param_1 +
                                                                                   0x100));
                                                      if (iVar20 == 0) {
                                                        unaff_ESI = s_Error_Server_Start30_0044c620;
                                                        unaff_EBP = 0;
                                                      }
                                                      else {
                                                        puStack_1f8 = operator_new(0xc3504);
                                                        if (puStack_1f8 == (uint *)0x0) {
                                                          puVar16 = (uint *)0x0;
                                                        }
                                                        else {
                                                          puVar16 = puStack_1f8 + 1;
                                                          *puStack_1f8 = 1000;
                                                          _eh_vector_constructor_iterator_
                                                                    (puVar16,800,1000,
                                                                     PerfLib::IPv4Address::
                                                                     GetSockAddr,
                                                                     PerfLib::IPv4Address::
                                                                     ~IPv4Address);
                                                        }
                                                        *(int *)((int)param_1 + 0x104) =
                                                             (int)puVar16;
                                                        iVar20 = FUN_0040ff40((void *)**(undefined4
                                                                                         **)((int)
                                                  param_1 + 0x4e84),(int *)((int)param_1 + 0x104));
                                                  if (iVar20 == 0) {
                                                    unaff_ESI = s_Error_Server_Start31_0044c608;
                                                    unaff_EBP = 0;
                                                  }
                                                  else {
                                                    iVar20 = FUN_004100e0((void *)**(undefined4 **)
                                                                                    ((int)param_1 +
                                                                                    0x4e84),
                                                                          (int *)((int)param_1 +
                                                                                 0x10c),
                                                                          (ushort *)
                                                                          ((int)param_1 + 0x108));
                                                    if (iVar20 == 0) {
                                                      unaff_ESI = s_Error_Server_Start32_0044c5f0;
                                                      unaff_EBP = 0;
                                                    }
                                                    else {
                                                      iVar20 = FUN_004103d0((void *)**(undefined4 **
                                                                                      )((int)param_1
                                                                                       + 0x4e84),
                                                                            (int *)((int)param_1 +
                                                                                   0x114),
                                                                            (int *)((int)param_1 +
                                                                                   0x110));
                                                      if (iVar20 == 0) {
                                                        unaff_ESI = 
                                                  s_Failed_to_InitCouponInfo___0044c5d4;
                                                  unaff_EBP = 0;
                                                  }
                                                  else {
                                                    puStack_1f8 = operator_new(0x24);
                                                    if (puStack_1f8 == (uint *)0x0) {
                                                      iVar20 = 0;
                                                    }
                                                    else {
                                                      iVar20 = FUN_00403880((undefined1 *)
                                                                            puStack_1f8);
                                                    }
                                                    *(int *)((int)param_1 + 0x118) = iVar20;
                                                    if (iVar20 == 0) {
                                                      unaff_ESI = s_Error_Server_Start33_0044c5bc;
                                                      unaff_EBP = 0;
                                                    }
                                                    else {
                                                      UVar8 = GetPrivateProfileIntA
                                                                        (s_Server_0044cb18,
                                                                         (LPCSTR)&lpKeyName_0044cad4
                                                                         ,0,(LPCSTR)&
                                                  lpFileName_00455830);
                                                  uVar6 = (u_short)UVar8;
                                                  if (uVar6 == 0) {
                                                    unaff_EBP = 0;
                                                    unaff_ESI = s_Error_Server_Start34_0044c5a4;
                                                  }
                                                  else {
                                                    UVar8 = GetPrivateProfileIntA
                                                                      (s_Queue_0044c7c4,
                                                                       s_TcpRecvQueue_0044c594,0,
                                                                       (LPCSTR)&lpFileName_00455830)
                                                    ;
                                                    if (UVar8 == 0) {
                                                      unaff_ESI = s_Error_Server_Start35_0044c57c;
                                                      unaff_EBP = 0;
                                                    }
                                                    else {
                                                      UVar17 = GetPrivateProfileIntA
                                                                         (s_Queue_0044c7c4,
                                                                          s_TcpSendPoolSize_0044c56c
                                                                          ,0,(LPCSTR)&
                                                  lpFileName_00455830);
                                                  unaff_EBP = 0;
                                                  if ((short)UVar17 == 0) {
                                                    unaff_ESI = s_Error_Server_Start36_0044c554;
                                                  }
                                                  else {
                                                    bVar5 = FUN_00403f40(*(void **)((int)param_1 +
                                                                                   0x118),uVar6,
                                                                         UVar8,UVar17,4000,0);
                                                    if (CONCAT31(extraout_var,bVar5) == 0) {
                                                      unaff_ESI = s_Error_Server_Start37_0044c53c;
                                                      unaff_EBP = 0;
                                                    }
                                                    else {
                                                      UVar8 = GetPrivateProfileIntA
                                                                        (s_Queue_0044c7c4,
                                                                         s_UdpRecvQueue_0044c52c,0,
                                                                         (LPCSTR)&
                                                  lpFileName_00455830);
                                                  if (UVar8 == 0) {
                                                    unaff_ESI = s_Error_Server_Start38_0044c514;
                                                    unaff_EBP = 0;
                                                  }
                                                  else {
                                                    UVar17 = GetPrivateProfileIntA
                                                                       ((LPCSTR)&lpAppName_0044c500,
                                                                        s_SendPoolCount_0044c504,0,
                                                                        (LPCSTR)&lpFileName_00455830
                                                                       );
                                                    if (UVar17 == 0) {
                                                      unaff_ESI = s_Error_Server_Start39_0044c4e8;
                                                      unaff_EBP = 0;
                                                    }
                                                    else {
                                                      puStack_1f8 = operator_new(0x10);
                                                      if (puStack_1f8 == (uint *)0x0) {
                                                        pvVar14 = (void *)0x0;
                                                      }
                                                      else {
                                                        pvVar14 = (void *)FUN_00403fe0((int)
                                                  puStack_1f8);
                                                  }
                                                  *(void **)((int)param_1 + 0x11c) = pvVar14;
                                                  if (pvVar14 == (void *)0x0) {
                                                    unaff_ESI = s_Error_Server_Start40_0044c4d0;
                                                    unaff_EBP = 0;
                                                  }
                                                  else {
                                                    bVar5 = FUN_00404360(pvVar14,uVar6,UVar8,UVar17,
                                                                         4000);
                                                    if (CONCAT31(extraout_var_00,bVar5) == 0) {
                                                      unaff_ESI = s_Error_Server_Start42_0044c4b8;
                                                      unaff_EBP = 0;
                                                    }
                                                    else {
                                                      puStack_1f8 = operator_new(0x10);
                                                      if (puStack_1f8 == (uint *)0x0) {
                                                        pvVar14 = (void *)0x0;
                                                      }
                                                      else {
                                                        pvVar14 = (void *)FUN_00403fe0((int)
                                                  puStack_1f8);
                                                  }
                                                  *(void **)((int)param_1 + 0x120) = pvVar14;
                                                  if (pvVar14 == (void *)0x0) {
                                                    unaff_ESI = s_Error_Server_Start43_0044c4a0;
                                                    unaff_EBP = 0;
                                                  }
                                                  else {
                                                    bVar5 = FUN_00404360(pvVar14,uVar6 + 1,UVar8,
                                                                         UVar17,4000);
                                                    unaff_EBP = 0;
                                                    if (CONCAT31(extraout_var_01,bVar5) == 0) {
                                                      unaff_ESI = s_Error_Server_Start45_0044c488;
                                                    }
                                                    else {
                                                      iVar20 = FUN_0042fed0((char *)&
                                                  lpFilename_00455c30,10,1,0);
                                                  if (iVar20 == 0) {
                                                    iVar20 = FUN_00430480(s_ggauth60_dll_0044c45c);
                                                    if (iVar20 == 0) {
                                                      *(undefined1 *)((int)param_1 + 0x4e) = 2;
                                                      aDStack_1f0[0] = 0;
                                                      pvVar12 = CreateThread((LPSECURITY_ATTRIBUTES)
                                                                             0x0,0,
                                                  lpStartAddress_0042cd10,param_1,0,aDStack_1f0);
                                                  if (pvVar12 == (HANDLE)0x0) {
                                                    FUN_0041d380(param_1,
                                                  s_Errror_Server_Start_48_0044c424,0);
                                                  }
                                                  else {
                                                    CloseHandle(pvVar12);
                                                    aDStack_1f0[1] = 0;
                                                    pvVar12 = CreateThread((LPSECURITY_ATTRIBUTES)
                                                                           0x0,0,
                                                  lpStartAddress_004294d0,param_1,0,aDStack_1f0 + 1)
                                                  ;
                                                  if (pvVar12 == (HANDLE)0x0) {
                                                    FUN_0041d380(param_1,
                                                  s_Errror_Server_Start_49_0044c40c,0);
                                                  }
                                                  else {
                                                    CloseHandle(pvVar12);
                                                    FUN_0041d380(param_1,s_Server_Start_0044c3fc,0);
                                                    DVar7 = GetCurrentProcessId();
                                                    _sprintf(acStack_84,s_PID___u__0044c3f0,DVar7);
                                                    FUN_0041d380(param_1,auStack_78,0);
                                                  }
                                                  }
                                                  goto LAB_0042d378;
                                                  }
                                                  wsprintfA(aCStack_184,
                                                            s_Error_Server_Start_48_1____u_0044c43c)
                                                  ;
                                                  unaff_EBP = 0;
                                                  unaff_ESI = aCStack_184;
                                                  }
                                                  else {
                                                    wsprintfA(aCStack_104,
                                                              s_Error_Server_Start_46____u_0044c46c)
                                                    ;
                                                    unaff_EBP = 0;
                                                    unaff_ESI = aCStack_104;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_0042d368;
                                                  }
                                                  }
                                                  unaff_EBP = 0;
                                                  unaff_ESI = s_Error_Server_Start50_0044c6b0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              else {
                                unaff_EBP = 0;
                                unaff_ESI = s_Error_MaxUser_0044c92c;
                              }
                            }
                            else {
                              unaff_EBP = 0;
                              unaff_ESI = s_Error_Count_0044c954;
                            }
                            goto LAB_0042d368;
                          }
                        }
                        unaff_EBP = 0;
                        unaff_ESI = s_Error_Failed_to_read_CharacterDe_0044c990;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0042d368:
  FUN_0041d380(param_1,unaff_ESI,unaff_EBP);
  FUN_00429f70(param_1);
LAB_0042d378:
  ExceptionList = unaff_retaddr;
  FUN_00435e83(iStack_4);
  return;
}



/* METADATA: sig=undefined __fastcall FUN_0042cee0(void * param_1) xrefs=0042eae7 callees=SetFilePointer FUN_0040fa90 CreateThread FUN_0042fdc0 CloseHandle FUN_00435e83 FUN_00404d60 inet_addr _sprintf GetCurrentProcessId GetTickCount CreateFileA FUN_00403fe0 FUN_00429f70 FUN_00405430 FUN_0042e490 Initialize FUN_0042fd90 operator_new FUN_0040dbe0 FUN_004364c8 FUN_0042fed0 FUN_0040e880 FUN_00404d70 FUN_0041b520 FUN_004103d0 FUN_00404360 `eh_vector_constructor_iterator' FUN_0040ff40 FUN_00430480 GetPrivateProfileStringA GetModuleFileNameA FUN_00403880 FUN_0042ce50 operator_new FUN_0042f860 FUN_00403f40 FUN_0041d380 htons FUN_0040f850 ReadFile CreateEventA FUN_004100e0 __mbsnbcpy GetPrivateProfileIntA FUN_0040fc30 wsprintfA */
