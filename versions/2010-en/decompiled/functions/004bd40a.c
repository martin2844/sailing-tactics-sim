
void FUN_004bd40a(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004d0614;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_004ad050();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 0x32));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004bad31();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

