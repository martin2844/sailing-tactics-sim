
undefined4 * FUN_004bd249(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004bac4f();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b045a((Tact2010CString *)(extraout_ECX + 0x32));
  extraout_ECX[0x31] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_FUN_004d0614;
  FUN_004bd2af();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

