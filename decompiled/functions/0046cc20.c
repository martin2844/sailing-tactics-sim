
undefined4 FUN_0046cc20(void)

{
  LPSTR lpBuffer;
  DWORD DVar1;
  BOOL BVar2;
  undefined4 uVar3;
  HANDLE hFindFile;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  lpBuffer = *(LPSTR *)(unaff_EBP + 8);
  DVar1 = GetFullPathNameA(*(LPCSTR *)(unaff_EBP + 0xc),0x104,lpBuffer,(LPSTR *)(unaff_EBP + -0x14))
  ;
  if (DVar1 == 0) {
    lstrcpynA(lpBuffer,*(LPCSTR *)(unaff_EBP + 0xc),0x104);
  }
  else {
    FUN_0046bd7a((undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0046ccf9(lpBuffer,(void *)(unaff_EBP + 8));
    BVar2 = GetVolumeInformationA
                      (*(LPCSTR *)(unaff_EBP + 8),(LPSTR)0x0,0,(LPDWORD)0x0,
                       (LPDWORD)(unaff_EBP + -0x18),(LPDWORD)(unaff_EBP + -0x10),(LPSTR)0x0,0);
    if (BVar2 != 0) {
      if ((*(byte *)(unaff_EBP + -0x10) & 2) == 0) {
        CharUpperA(lpBuffer);
      }
      if ((*(byte *)(unaff_EBP + -0x10) & 4) == 0) {
        hFindFile = FindFirstFileA(*(LPCSTR *)(unaff_EBP + 0xc),
                                   (LPWIN32_FIND_DATAA)(unaff_EBP + -0x158));
        if (hFindFile != (HANDLE)0xffffffff) {
          FindClose(hFindFile);
          lstrcpyA(*(LPSTR *)(unaff_EBP + -0x14),(LPCSTR)(unaff_EBP + -300));
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046bec5((int *)(unaff_EBP + 8));
      uVar3 = 1;
      goto LAB_0046cce9;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046bec5((int *)(unaff_EBP + 8));
  }
  uVar3 = 0;
LAB_0046cce9:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

