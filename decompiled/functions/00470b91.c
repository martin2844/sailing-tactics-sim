
void FUN_00470b91(void)

{
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((*(int *)(extraout_ECX + 0x20) != 0) && ((*(byte *)(extraout_ECX + 0x14) & 2) == 0)) {
    FUN_00470c19(extraout_ECX);
  }
  FUN_00470bd7(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046bec5((int *)(extraout_ECX + 0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

