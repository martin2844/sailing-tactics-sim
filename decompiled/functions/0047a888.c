
undefined4 * FUN_0047a888(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00485d04;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a(extraout_ECX + 5);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046bd7a(extraout_ECX + 6);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0046bd7a(extraout_ECX + 7);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0046bd7a(extraout_ECX + 8);
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[4] = 0;
  *extraout_ECX = &PTR_FUN_0048669c;
  extraout_ECX[1] = 1;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

