
void FUN_0046c44b(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00486d9c;
  iVar1 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if ((iVar1 != -1) && (extraout_ECX[2] != 0)) {
    FUN_0046c750((int)extraout_ECX);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5(extraout_ECX + 3);
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_00485d04;
  *unaff_FS_OFFSET = uVar2;
  return;
}

