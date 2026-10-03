
undefined4 FUN_004aa7d8(void)

{
  undefined4 uVar1;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  iVar2 = *(int *)(unaff_EBP + 0xc);
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (*(int *)(*extraout_ECX + -8) < iVar2) {
    iVar2 = *(int *)(*extraout_ECX + -8);
  }
  FUN_004b045a((Tact2010CString *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_004b05ce(unaff_EBP + 0xc,iVar2,0,0);
  FUN_004b046a(*(Tact2010CString **)(unaff_EBP + 8),(Tact2010CString *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + 0xc));
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

