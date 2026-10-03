
void FUN_004b5271(void)

{
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((*(int *)(extraout_ECX + 0x20) != 0) && ((*(byte *)(extraout_ECX + 0x14) & 2) == 0)) {
    FUN_004b52f9();
  }
  FUN_004b52b7();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

