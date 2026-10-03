
undefined4 * FUN_0047b72d(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004865ec;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  CMap<>(extraout_ECX + 0xc,10);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  CMap<>(extraout_ECX + 0x13,10);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00466a52(extraout_ECX + 0x1a,10);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004872dc;
  extraout_ECX[3] = 0x54;
  extraout_ECX[10] = FUN_0046b4e9;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

