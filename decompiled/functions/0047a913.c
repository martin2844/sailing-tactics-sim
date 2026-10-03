
void FUN_0047a913(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0048669c;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_0046bec5(extraout_ECX + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0046bec5(extraout_ECX + 7);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046bec5(extraout_ECX + 6);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5(extraout_ECX + 5);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_00485d04;
  *unaff_FS_OFFSET = uVar1;
  return;
}

