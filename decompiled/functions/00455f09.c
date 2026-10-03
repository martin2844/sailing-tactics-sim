
void FUN_00455f09(void)

{
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0046d668(extraout_ECX);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00466f63();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00466f63();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

