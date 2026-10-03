
undefined4 * FUN_004b0ae7(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004cd9a4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b045a((Tact2010CString *)(extraout_ECX + 3));
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[2] = 0;
  extraout_ECX[1] = uVar1;
  *extraout_ECX = &PTR_FUN_004cea3c;
  *unaff_FS_OFFSET = uVar2;
  return extraout_ECX;
}

