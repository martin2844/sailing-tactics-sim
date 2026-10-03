
undefined4 FUN_004660f8(void)

{
  undefined4 uVar1;
  int *this;
  int unaff_EBP;
  uint uVar2;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  uVar2 = *(uint *)(unaff_EBP + 0xc);
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  else if ((int)*(uint *)(*this + -8) < (int)uVar2) {
    uVar2 = *(uint *)(*this + -8);
  }
  FUN_0046bd7a((undefined4 *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0046beee(this,(undefined4 *)(unaff_EBP + 0xc),uVar2,0,0);
  FUN_0046bd8a(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5((int *)(unaff_EBP + 0xc));
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

