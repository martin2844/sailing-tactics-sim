
undefined4 * FUN_0047c424(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00485d04;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00466a52(extraout_ECX + 1,10);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004879fc;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

