
undefined4 FUN_004b3960(void)

{
  int iVar1;
  BOOL BVar2;
  LPSTR lpTempFileName;
  PSECURITY_DESCRIPTOR pSecurityDescriptor;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  FUN_004b0530();
  if ((*(byte *)(unaff_EBP + 0xd) & 0x10) != 0) {
    iVar1 = FUN_004b2d4a(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x148);
    if (iVar1 != 0) {
      FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
      iVar1 = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004b13d9(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x10);
      BVar2 = GetDiskFreeSpaceA(*(LPCSTR *)(unaff_EBP + -0x10),(LPDWORD)(unaff_EBP + -0x14),
                                (LPDWORD)(unaff_EBP + -0x2c),(LPDWORD)(unaff_EBP + -0x30),
                                (LPDWORD)(unaff_EBP + -0x24));
      if (BVar2 != 0) {
        iVar1 = *(int *)(unaff_EBP + -0x2c) * *(int *)(unaff_EBP + -0x30) *
                *(int *)(unaff_EBP + -0x14);
      }
      if (*(int *)(unaff_EBP + -0x13c) * 2 < iVar1) {
        GetFullPathNameA(*(LPCSTR *)(unaff_EBP + 8),0x104,(LPSTR)(unaff_EBP + -0x24c),
                         (LPSTR *)(unaff_EBP + -0x1c));
        **(undefined1 **)(unaff_EBP + -0x1c) = 0;
        lpTempFileName = (LPSTR)FUN_004b0956(0x105);
        GetTempFileNameA((LPCSTR)(unaff_EBP + -0x24c),"MFC",0,lpTempFileName);
        FUN_004b09a5(0xffffffff);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
    }
  }
  iVar1 = *(int *)(extraout_ECX + 0x10);
  if (*(int *)(iVar1 + -8) != 0) {
    iVar1 = FUN_004b0c0a(iVar1,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
    if (iVar1 != 0) {
      FUN_004b06ed((Tact2010CString *)(extraout_ECX + 0xc),*(char **)(unaff_EBP + 8));
      BVar2 = GetFileTime(*(HANDLE *)(extraout_ECX + 4),(LPFILETIME)(unaff_EBP + -0x28),
                          (LPFILETIME)(unaff_EBP + -0x18),(LPFILETIME)(unaff_EBP + -0x20));
      if (BVar2 != 0) {
        FUN_004b2dfc(unaff_EBP + -0x148,unaff_EBP + -0x28);
        SetFileTime(*(HANDLE *)(extraout_ECX + 4),(FILETIME *)(unaff_EBP + -0x28),
                    (FILETIME *)(unaff_EBP + -0x18),(FILETIME *)(unaff_EBP + -0x20));
      }
      *(undefined4 *)(unaff_EBP + 0xc) = 0;
      BVar2 = GetFileSecurityA(*(LPCSTR *)(unaff_EBP + 8),4,(PSECURITY_DESCRIPTOR)0x0,0,
                               (LPDWORD)(unaff_EBP + 0xc));
      if (BVar2 != 0) {
        pSecurityDescriptor = (PSECURITY_DESCRIPTOR)FUN_004afbe5(*(undefined4 *)(unaff_EBP + 0xc));
        BVar2 = GetFileSecurityA(*(LPCSTR *)(unaff_EBP + 8),4,pSecurityDescriptor,
                                 *(DWORD *)(unaff_EBP + 0xc),(LPDWORD)(unaff_EBP + 0xc));
        if (BVar2 != 0) {
          SetFileSecurityA(*(LPCSTR *)(extraout_ECX + 0x10),4,pSecurityDescriptor);
        }
        FUN_004afc21(pSecurityDescriptor);
      }
      uVar3 = 1;
      goto LAB_004b3b16;
    }
  }
  FUN_004b0530();
  uVar3 = FUN_004b0c0a(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                       *(undefined4 *)(unaff_EBP + 0x10));
LAB_004b3b16:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

