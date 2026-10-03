
void FUN_0049a615(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_004b1d48();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004ab643();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004ab643();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

