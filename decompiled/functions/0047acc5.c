
undefined4 * FUN_0047acc5(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046af4b(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_0048671c;
  extraout_ECX[0x13] = 0;
  extraout_ECX[0x14] = 0;
  FUN_0047ad02((int)extraout_ECX);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

