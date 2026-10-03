
LSTATUS FUN_0047afb2(void)

{
  LSTATUS LVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  HKEY hKey;
  
  FUN_00457418();
  *(undefined4 *)(unaff_EBP + -0x1c) = extraout_ECX;
  LVar1 = RegOpenKeyA(*(HKEY *)(unaff_EBP + 8),(LPCSTR)**(undefined4 **)(unaff_EBP + 0xc),
                      (PHKEY)(unaff_EBP + -0x14));
  if (LVar1 == 0) {
    hKey = *(HKEY *)(unaff_EBP + -0x14);
    while( true ) {
      LVar1 = RegEnumKeyA(hKey,0,(LPSTR)(unaff_EBP + -0x11c),0xff);
      if (LVar1 != 0) break;
      FUN_0046bf33((void *)(unaff_EBP + -0x18),(LPCSTR)(unaff_EBP + -0x11c));
      *(undefined4 *)(unaff_EBP + -4) = 0;
      LVar1 = FUN_0047afb2();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(bool *)(unaff_EBP + -0xd) = LVar1 != 0;
      FUN_0046bec5((int *)(unaff_EBP + -0x18));
      if (*(char *)(unaff_EBP + -0xd) != '\0') break;
      hKey = *(HKEY *)(unaff_EBP + -0x14);
    }
    if ((LVar1 == 0x103) || (LVar1 == 0x3f2)) {
      LVar1 = RegDeleteKeyA(*(HKEY *)(unaff_EBP + 8),(LPCSTR)**(undefined4 **)(unaff_EBP + 0xc));
    }
  }
  RegCloseKey(*(HKEY *)(unaff_EBP + -0x14));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return LVar1;
}

