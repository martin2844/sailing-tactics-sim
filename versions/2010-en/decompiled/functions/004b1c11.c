
int FUN_004b1c11(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  CMap<>(10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CMap<>(4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004ab5d2(7,0);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x38) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(extraout_ECX + 0x3c) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(extraout_ECX + 0x40) = *(undefined4 *)(unaff_EBP + 0x10);
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

