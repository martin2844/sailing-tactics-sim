
undefined4 * FUN_00478b69(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0047656f();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a(extraout_ECX + 0x32);
  extraout_ECX[0x31] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_FUN_00488974;
  FUN_00478bcf();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

