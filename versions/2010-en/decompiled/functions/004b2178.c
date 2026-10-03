
void FUN_004b2178(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004cf504;
  iVar1 = extraout_ECX[2];
  *(undefined4 *)(unaff_EBP + -4) = 2;
  if (iVar1 != 0) {
    FUN_004b213c(3);
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 7));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 4));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 3));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

