
void FUN_0046da98(void)

{
  void *this;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00487864;
  this = (void *)extraout_ECX[2];
  *(undefined4 *)(unaff_EBP + -4) = 2;
  if (this != (void *)0x0) {
    FUN_0046da5c(this,3);
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046bec5(extraout_ECX + 7);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046bec5(extraout_ECX + 3);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

