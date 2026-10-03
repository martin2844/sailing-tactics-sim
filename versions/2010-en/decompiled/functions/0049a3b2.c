
void FUN_0049a3b2(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar2;
  
  FUN_0049bcd8();
  uVar2 = extraout_ECX;
  iVar1 = FUN_004c013e(0x84);
  *(int *)(unaff_EBP + -0x10) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    FUN_004bfe0d(uVar2);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

