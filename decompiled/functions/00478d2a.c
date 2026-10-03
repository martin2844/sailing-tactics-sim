
void FUN_00478d2a(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00488974;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00468970((int)extraout_ECX);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5(extraout_ECX + 0x32);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00476651();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

