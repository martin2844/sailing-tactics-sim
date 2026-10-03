
undefined4 * FUN_004b9965(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004c0926();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004ab30f();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *extraout_ECX = &PTR_FUN_004d026c;
  extraout_ECX[0x1e] = uVar1;
  extraout_ECX[0xf] = 1;
  uVar1 = extraout_ECX[0x21];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004ab49c(uVar1,0);
  extraout_ECX[0x24] = 0;
  SetRectEmpty((LPRECT)(extraout_ECX + 0x25));
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x12] = 0;
  extraout_ECX[0x13] = 0;
  extraout_ECX[0x11] = 0;
  extraout_ECX[0x10] = 0;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

