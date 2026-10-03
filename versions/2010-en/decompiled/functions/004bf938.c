
undefined4 FUN_004bf938(void)

{
  undefined4 uVar1;
  int iVar2;
  LSTATUS LVar3;
  LPBYTE lpData;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  LPDWORD lpcbData;
  char *pcVar4;
  
  FUN_0049bcd8();
  FUN_0049c450();
  iVar2 = *(int *)(extraout_ECX + 0x7c);
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  if (iVar2 == 0) {
    if (*(int *)(unaff_EBP + 0x14) == 0) {
      *(undefined **)(unaff_EBP + 0x14) = &DAT_00537ed8;
    }
    GetPrivateProfileStringA
              (*(LPCSTR *)(unaff_EBP + 0xc),*(LPCSTR *)(unaff_EBP + 0x10),
               *(LPCSTR *)(unaff_EBP + 0x14),(LPSTR)(unaff_EBP + -0x1018),0x1000,
               *(LPCSTR *)(extraout_ECX + 0x90));
    pcVar4 = (char *)(unaff_EBP + -0x1018);
  }
  else {
    iVar2 = GetSectionKey(*(undefined4 *)(unaff_EBP + 0xc));
    *(int *)(unaff_EBP + -0x10) = iVar2;
    if (iVar2 != 0) {
      FUN_004b045a((Tact2010CString *)(unaff_EBP + 0xc));
      *(undefined4 *)(unaff_EBP + -4) = 0;
      LVar3 = RegQueryValueExA(*(HKEY *)(unaff_EBP + -0x10),*(LPCSTR *)(unaff_EBP + 0x10),
                               (LPDWORD)0x0,(LPDWORD)(unaff_EBP + -0x18),(LPBYTE)0x0,
                               (LPDWORD)(unaff_EBP + -0x14));
      if (LVar3 == 0) {
        lpcbData = (LPDWORD)(unaff_EBP + -0x14);
        lpData = (LPBYTE)FUN_004b0956(*(undefined4 *)(unaff_EBP + -0x14));
        LVar3 = RegQueryValueExA(*(HKEY *)(unaff_EBP + -0x10),*(LPCSTR *)(unaff_EBP + 0x10),
                                 (LPDWORD)0x0,(LPDWORD)(unaff_EBP + -0x18),lpData,lpcbData);
        FUN_004b09a5(0xffffffff);
      }
      RegCloseKey(*(HKEY *)(unaff_EBP + -0x10));
      if (LVar3 == 0) {
        FUN_004b046a(*(Tact2010CString **)(unaff_EBP + 8),(Tact2010CString *)(unaff_EBP + 0xc));
      }
      else {
        FUN_004b0613(*(Tact2010CString **)(unaff_EBP + 8),*(char **)(unaff_EBP + 0x14));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + 0xc));
      goto LAB_004bfa36;
    }
    pcVar4 = *(char **)(unaff_EBP + 0x14);
  }
  FUN_004b0613(*(Tact2010CString **)(unaff_EBP + 8),pcVar4);
LAB_004bfa36:
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

