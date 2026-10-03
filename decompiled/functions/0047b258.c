
undefined4 FUN_0047b258(void)

{
  int iVar1;
  undefined4 uVar2;
  HKEY pHVar3;
  LSTATUS LVar4;
  LPBYTE lpData;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  LPDWORD lpcbData;
  LPCSTR pCVar5;
  
  FUN_00457418();
  FUN_00457b90();
  iVar1 = *(int *)((int)this + 0x7c);
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  if (iVar1 == 0) {
    if (*(int *)(unaff_EBP + 0x14) == 0) {
      *(undefined **)(unaff_EBP + 0x14) = &DAT_004ae380;
    }
    GetPrivateProfileStringA
              (*(LPCSTR *)(unaff_EBP + 0xc),*(LPCSTR *)(unaff_EBP + 0x10),
               *(LPCSTR *)(unaff_EBP + 0x14),(LPSTR)(unaff_EBP + -0x1018),0x1000,
               *(LPCSTR *)((int)this + 0x90));
    pCVar5 = (LPCSTR)(unaff_EBP + -0x1018);
  }
  else {
    pHVar3 = GetSectionKey(this,*(LPCSTR *)(unaff_EBP + 0xc));
    *(HKEY *)(unaff_EBP + -0x10) = pHVar3;
    if (pHVar3 != (HKEY)0x0) {
      FUN_0046bd7a((undefined4 *)(unaff_EBP + 0xc));
      *(undefined4 *)(unaff_EBP + -4) = 0;
      LVar4 = RegQueryValueExA(*(HKEY *)(unaff_EBP + -0x10),*(LPCSTR *)(unaff_EBP + 0x10),
                               (LPDWORD)0x0,(LPDWORD)(unaff_EBP + -0x18),(LPBYTE)0x0,
                               (LPDWORD)(unaff_EBP + -0x14));
      if (LVar4 == 0) {
        lpcbData = (LPDWORD)(unaff_EBP + -0x14);
        lpData = (LPBYTE)FUN_0046c276((void *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x14));
        LVar4 = RegQueryValueExA(*(HKEY *)(unaff_EBP + -0x10),*(LPCSTR *)(unaff_EBP + 0x10),
                                 (LPDWORD)0x0,(LPDWORD)(unaff_EBP + -0x18),lpData,lpcbData);
        FUN_0046c2c5((void *)(unaff_EBP + 0xc),-1);
      }
      RegCloseKey(*(HKEY *)(unaff_EBP + -0x10));
      if (LVar4 == 0) {
        FUN_0046bd8a(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + 0xc));
      }
      else {
        FUN_0046bf33(*(void **)(unaff_EBP + 8),*(LPCSTR *)(unaff_EBP + 0x14));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046bec5((int *)(unaff_EBP + 0xc));
      goto LAB_0047b356;
    }
    pCVar5 = *(LPCSTR *)(unaff_EBP + 0x14);
  }
  FUN_0046bf33(*(void **)(unaff_EBP + 8),pCVar5);
LAB_0047b356:
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

