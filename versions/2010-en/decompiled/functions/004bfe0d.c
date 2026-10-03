
undefined4 * FUN_004bfe0d(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004ce28c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  CMap<>(10);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  CMap<>(10);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004ab132(10);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004cef7c;
  extraout_ECX[3] = 0x54;
  extraout_ECX[10] = FUN_004afbc9;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

