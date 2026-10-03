
void FUN_004beff3(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004ce33c;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 8));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 7));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 6));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 5));
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004cd9a4;
  *unaff_FS_OFFSET = uVar1;
  return;
}

