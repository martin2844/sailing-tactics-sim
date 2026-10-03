
undefined4 * FUN_00456338(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00467d63(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CMap<>(extraout_ECX + 0xf,10);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_0048804c;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

