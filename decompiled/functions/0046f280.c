
LPCSTR FUN_0046f280(void)

{
  int *this;
  int iVar1;
  BOOL BVar2;
  LPSTR lpTempFileName;
  LPCSTR pCVar3;
  undefined *pSecurityDescriptor;
  void *this_00;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  this = (int *)((int)this_00 + 0x10);
  FUN_0046be50(this);
  if ((*(byte *)(unaff_EBP + 0xd) & 0x10) != 0) {
    iVar1 = FUN_0046e66a(*(LPCSTR *)(unaff_EBP + 8),(int *)(unaff_EBP + -0x148));
    if (iVar1 != 0) {
      FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x10));
      iVar1 = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0046ccf9(*(LPCSTR *)(unaff_EBP + 8),(void *)(unaff_EBP + -0x10));
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
        lpTempFileName = (LPSTR)FUN_0046c276(this,0x105);
        GetTempFileNameA((LPCSTR)(unaff_EBP + -0x24c),"MFC",0,lpTempFileName);
        FUN_0046c2c5(this,-1);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046bec5((int *)(unaff_EBP + -0x10));
    }
  }
  if (*(int *)((LPCSTR)*this + -8) != 0) {
    pCVar3 = FUN_0046c52a(this_00,(LPCSTR)*this,*(uint *)(unaff_EBP + 0xc),
                          *(int *)(unaff_EBP + 0x10));
    if (pCVar3 != (LPCSTR)0x0) {
      FUN_0046c00d((void *)((int)this_00 + 0xc),*(LPCSTR *)(unaff_EBP + 8));
      BVar2 = GetFileTime(*(HANDLE *)((int)this_00 + 4),(LPFILETIME)(unaff_EBP + -0x28),
                          (LPFILETIME)(unaff_EBP + -0x18),(LPFILETIME)(unaff_EBP + -0x20));
      if (BVar2 != 0) {
        FUN_0046e71c((void *)(unaff_EBP + -0x148),(LPFILETIME)(unaff_EBP + -0x28));
        SetFileTime(*(HANDLE *)((int)this_00 + 4),(FILETIME *)(unaff_EBP + -0x28),
                    (FILETIME *)(unaff_EBP + -0x18),(FILETIME *)(unaff_EBP + -0x20));
      }
      *(undefined4 *)(unaff_EBP + 0xc) = 0;
      BVar2 = GetFileSecurityA(*(LPCSTR *)(unaff_EBP + 8),4,(PSECURITY_DESCRIPTOR)0x0,0,
                               (LPDWORD)(unaff_EBP + 0xc));
      if (BVar2 != 0) {
        pSecurityDescriptor = (undefined *)FUN_0046b505(*(uint *)(unaff_EBP + 0xc));
        BVar2 = GetFileSecurityA(*(LPCSTR *)(unaff_EBP + 8),4,pSecurityDescriptor,
                                 *(DWORD *)(unaff_EBP + 0xc),(LPDWORD)(unaff_EBP + 0xc));
        if (BVar2 != 0) {
          SetFileSecurityA((LPCSTR)*this,4,pSecurityDescriptor);
        }
        FUN_0046b541(pSecurityDescriptor);
      }
      pCVar3 = (LPCSTR)0x1;
      goto LAB_0046f436;
    }
  }
  FUN_0046be50(this);
  pCVar3 = FUN_0046c52a(this_00,*(LPCSTR *)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),
                        *(int *)(unaff_EBP + 0x10));
LAB_0046f436:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return pCVar3;
}

