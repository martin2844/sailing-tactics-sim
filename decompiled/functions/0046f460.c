
void FUN_0046f460(void)

{
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  FUN_0046bd8a((void *)(unaff_EBP + -0x10),(int *)(extraout_ECX + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046c750(extraout_ECX);
  if (*(int *)(*(int *)(extraout_ECX + 0x10) + -8) != 0) {
    FUN_0046c881(*(LPCSTR *)(unaff_EBP + -0x10));
    FUN_0046c85f(*(LPCSTR *)(extraout_ECX + 0x10),*(LPCSTR *)(unaff_EBP + -0x10));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046bec5((int *)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

