
undefined4 FUN_004aa75b(void)

{
  int iVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int iVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  iVar3 = *(int *)(unaff_EBP + 0xc);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (*(int *)(*extraout_ECX + -8) < iVar3) {
    iVar3 = *(int *)(*extraout_ECX + -8);
  }
  FUN_004b045a((Tact2010CString *)(unaff_EBP + 0xc));
  iVar1 = *(int *)(*extraout_ECX + -8);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_004b05ce(unaff_EBP + 0xc,iVar3,iVar1 - iVar3,0);
  FUN_004b046a(*(Tact2010CString **)(unaff_EBP + 8),(Tact2010CString *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + 0xc));
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

