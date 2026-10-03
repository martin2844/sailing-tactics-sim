
undefined4 * FUN_0046c407(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00485d04;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a(extraout_ECX + 3);
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[2] = 0;
  extraout_ECX[1] = uVar1;
  *extraout_ECX = &PTR_FUN_00486d9c;
  *unaff_FS_OFFSET = uVar2;
  return extraout_ECX;
}

