
void FUN_004b0b2b(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004cea3c;
  iVar1 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if ((iVar1 != -1) && (extraout_ECX[2] != 0)) {
    FUN_004b0e30();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 3));
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004cd9a4;
  *unaff_FS_OFFSET = uVar2;
  return;
}

