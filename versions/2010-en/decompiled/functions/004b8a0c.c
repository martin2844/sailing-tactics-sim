
void FUN_004b8a0c(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = (**(code **)(iVar1 + 0x34))(unaff_EBP + -0x10,0xf000,0x1004,1,0);
  if (iVar1 != 0) {
    iVar1 = FUN_004bfff8();
    (**(code **)(**(int **)(iVar1 + 4) + 0x84))(*(undefined4 *)(unaff_EBP + -0x10));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

