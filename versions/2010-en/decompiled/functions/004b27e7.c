
undefined4 FUN_004b27e7(void)

{
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  if (*(int **)(unaff_EBP + 0x10) != (int *)0x0) {
    **(int **)(unaff_EBP + 0x10) = *(int *)(extraout_ECX + 8) + 0xf1a0;
  }
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b046a((Tact2010CString *)(unaff_EBP + 0x10),(Tact2010CString *)(extraout_ECX + 0x10));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (*(int *)(*(int *)(unaff_EBP + 0x10) + -8) == 0) {
    FUN_004b1f41(0xf006);
  }
  FUN_004b8baa(unaff_EBP + -0x10,*(int *)(extraout_ECX + 8) + 0xf1a0,
               *(undefined4 *)(unaff_EBP + 0x10));
  lstrcpynA(*(LPSTR *)(unaff_EBP + 8),*(LPCSTR *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 0xc));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + 0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return 1;
}

