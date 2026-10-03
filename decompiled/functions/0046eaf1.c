
undefined4 * FUN_0046eaf1(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046af4b(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a(extraout_ECX + 7);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046bd7a(extraout_ECX + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00466a52(extraout_ECX + 10,10);
  extraout_ECX[9] = 0;
  extraout_ECX[0x11] = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x13] = 0;
  *extraout_ECX = &PTR_FUN_0048692c;
  extraout_ECX[0x12] = 1;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

