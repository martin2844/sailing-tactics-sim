
Tact2010CString * FUN_004b082f(Tact2010CString *param_1,char *param_2,Tact2010CString *param_3)

{
  Tact2010CString *pTVar1;
  int iVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = lstrlenA(*(LPCSTR *)(unaff_EBP + 0xc));
  }
  FUN_004b0714(iVar2,*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(**(int **)(unaff_EBP + 0x10) + -8),**(int **)(unaff_EBP + 0x10));
  FUN_004b046a(*(Tact2010CString **)(unaff_EBP + 8),(Tact2010CString *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  pTVar1 = *(Tact2010CString **)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return pTVar1;
}

