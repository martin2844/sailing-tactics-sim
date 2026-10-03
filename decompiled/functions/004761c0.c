
undefined4 * FUN_004761c0(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00478b69();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00475285();
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x42] = 0;
  *extraout_ECX = &PTR_FUN_004886bc;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

