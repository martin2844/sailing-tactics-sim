
void FUN_004b3b40(void)

{
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  FUN_004b046a((Tact2010CString *)(unaff_EBP + -0x10),(Tact2010CString *)(extraout_ECX + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b0e30();
  if (*(int *)(*(int *)(extraout_ECX + 0x10) + -8) != 0) {
    FUN_004b0f61(*(undefined4 *)(unaff_EBP + -0x10));
    FUN_004b0f3f(*(undefined4 *)(extraout_ECX + 0x10),*(undefined4 *)(unaff_EBP + -0x10));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

