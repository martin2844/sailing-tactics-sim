
void FUN_004b3251(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004ce5cc;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_004b32c5();
  if ((int *)extraout_ECX[9] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[9] + 0x68))(extraout_ECX);
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004ab191();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 8));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 7));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004af667();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

