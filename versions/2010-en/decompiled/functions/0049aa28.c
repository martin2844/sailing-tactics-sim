
undefined4 * FUN_0049aa28(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004ac443();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CMap<>(10);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004cfcec;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

