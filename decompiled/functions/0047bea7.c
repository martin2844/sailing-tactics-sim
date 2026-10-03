
int FUN_0047bea7(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  if (*extraout_ECX == 0) {
    FUN_0047c1af(0x10);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (*extraout_ECX == 0) {
      iVar1 = (**(code **)(unaff_EBP + 8))();
      *extraout_ECX = iVar1;
      iVar1 = FUN_0047bef4();
      return iVar1;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0047c21f(0x10);
  }
  iVar1 = *extraout_ECX;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar1;
}

