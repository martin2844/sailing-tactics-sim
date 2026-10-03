
void FUN_0047cea6(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004865e4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00470f1d(extraout_ECX + 1);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004865ec;
  *unaff_FS_OFFSET = uVar1;
  return;
}

