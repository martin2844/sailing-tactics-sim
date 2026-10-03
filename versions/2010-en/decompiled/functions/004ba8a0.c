
undefined4 * FUN_004ba8a0(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004bd249();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b9965(1);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x42] = 0;
  *extraout_ECX = &PTR_FUN_004d035c;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

