
void FUN_004ab342(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004d082c;
  uVar1 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004afc21(uVar1);
  *extraout_ECX = &PTR_FUN_004cd9a4;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

