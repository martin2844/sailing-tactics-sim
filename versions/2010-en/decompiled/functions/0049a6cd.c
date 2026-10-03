
void FUN_0049a6cd(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004cf0ec;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b1f25();
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004cd9a4;
  *unaff_FS_OFFSET = uVar1;
  return;
}

