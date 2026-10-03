
int FUN_004b0fcf(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  HMODULE hModule;
  FARPROC pFVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  puVar2 = *(undefined4 **)(unaff_EBP + 0x10);
  *puVar2 = 0;
  FUN_004b109b(unaff_EBP + -0x10,uVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b045a((Tact2010CString *)(unaff_EBP + 0x10));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar3 = FUN_004b110a(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + 0x10);
  if (iVar3 != 0) {
    hModule = LoadLibraryA(*(LPCSTR *)(unaff_EBP + 0x10));
    if (hModule != (HMODULE)0x0) {
      pFVar4 = GetProcAddress(hModule,"DllGetClassObject");
      if (pFVar4 == (FARPROC)0x0) {
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_004b05a5((Tact2010CString *)(unaff_EBP + 0x10));
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
        iVar3 = -0x7ffbfe07;
      }
      else {
        iVar3 = (*pFVar4)(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),puVar2);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_004b05a5((Tact2010CString *)(unaff_EBP + 0x10));
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
      }
      goto LAB_004b108b;
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + 0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  iVar3 = -0x7ffbfeac;
LAB_004b108b:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar3;
}

