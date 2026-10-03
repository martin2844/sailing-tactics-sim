
void FUN_004ba8ff(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b99fc();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004bd40a();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

