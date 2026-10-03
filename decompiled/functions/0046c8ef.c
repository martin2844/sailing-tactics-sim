
int FUN_0046c8ef(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined3 extraout_var;
  HMODULE hModule;
  int iVar4;
  FARPROC pFVar5;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  puVar2 = *(undefined4 **)(unaff_EBP + 0x10);
  *puVar2 = 0;
  FUN_0046c9bb((void *)(unaff_EBP + -0x10),puVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a((undefined4 *)(unaff_EBP + 0x10));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  bVar3 = FUN_0046ca2a(*(HKEY *)(unaff_EBP + -0x10),(void *)(unaff_EBP + 0x10));
  if (CONCAT31(extraout_var,bVar3) != 0) {
    hModule = LoadLibraryA(*(LPCSTR *)(unaff_EBP + 0x10));
    if (hModule != (HMODULE)0x0) {
      pFVar5 = GetProcAddress(hModule,"DllGetClassObject");
      if (pFVar5 == (FARPROC)0x0) {
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_0046bec5((int *)(unaff_EBP + 0x10));
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0046bec5((int *)(unaff_EBP + -0x10));
        iVar4 = -0x7ffbfe07;
      }
      else {
        iVar4 = (*pFVar5)(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),puVar2);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_0046bec5((int *)(unaff_EBP + 0x10));
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0046bec5((int *)(unaff_EBP + -0x10));
      }
      goto LAB_0046c9ab;
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5((int *)(unaff_EBP + 0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046bec5((int *)(unaff_EBP + -0x10));
  iVar4 = -0x7ffbfeac;
LAB_0046c9ab:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar4;
}

