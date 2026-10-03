
void FUN_004b3164(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = (**(code **)(iVar1 + 0x6c))(unaff_EBP + -0x10,1);
  if ((iVar1 == 0) || (*(int *)(*(int *)(unaff_EBP + -0x10) + -8) == 0)) {
    FUN_004b1f41(0xf003);
  }
  (**(code **)(**(int **)(unaff_EBP + 8) + 0x58))(*(undefined4 *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

