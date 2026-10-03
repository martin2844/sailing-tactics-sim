
undefined4 * FUN_0047656f(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00467d63(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00466a52(extraout_ECX + 0x1b,10);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046bd7a(extraout_ECX + 0x2b);
  extraout_ECX[0x10] = 0xffffffff;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_FUN_004861bc;
  extraout_ECX[0xf] = 1;
  extraout_ECX[0x27] = 0;
  extraout_ECX[0x11] = 0;
  extraout_ECX[0x12] = 0;
  extraout_ECX[0x23] = 0;
  extraout_ECX[0x24] = 0;
  extraout_ECX[0x25] = 0;
  extraout_ECX[0x26] = 0;
  extraout_ECX[0x28] = 0;
  extraout_ECX[0x29] = 0;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x2a] = 0;
  extraout_ECX[0x2e] = 0;
  SetRectEmpty((LPRECT)(extraout_ECX + 0x16));
  extraout_ECX[0x22] = 0xffffffff;
  extraout_ECX[0x14] = 0;
  extraout_ECX[0x13] = 0;
  extraout_ECX[0x15] = 0;
  extraout_ECX[0x2c] = 0;
  extraout_ECX[0x2d] = 0;
  FUN_004766b8((int)extraout_ECX);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

