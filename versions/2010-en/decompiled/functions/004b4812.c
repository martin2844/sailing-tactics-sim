
void FUN_004b4812(void)

{
  undefined4 uVar1;
  HDC hdc;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004cecc4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (extraout_ECX[1] != 0) {
    hdc = (HDC)FUN_004b47e1();
    DeleteDC(hdc);
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004cd9a4;
  *unaff_FS_OFFSET = uVar1;
  return;
}

