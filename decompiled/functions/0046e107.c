
undefined4 FUN_0046e107(void)

{
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  if (*(int **)(unaff_EBP + 0x10) != (int *)0x0) {
    **(int **)(unaff_EBP + 0x10) = *(int *)(extraout_ECX + 8) + 0xf1a0;
  }
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd8a((void *)(unaff_EBP + 0x10),(int *)(extraout_ECX + 0x10));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (*(int *)(*(int *)(unaff_EBP + 0x10) + -8) == 0) {
    FUN_0046d861(0xf006);
  }
  FUN_004744ca((int *)(unaff_EBP + -0x10),*(int *)(extraout_ECX + 8) + 0xf1a0);
  lstrcpynA(*(LPSTR *)(unaff_EBP + 8),*(LPCSTR *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 0xc));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5((int *)(unaff_EBP + 0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046bec5((int *)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return 1;
}

