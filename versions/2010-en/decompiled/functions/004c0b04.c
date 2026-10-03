
undefined4 * FUN_004c0b04(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004cd9a4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004ab132(10);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004cf69c;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

