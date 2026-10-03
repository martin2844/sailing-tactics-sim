
void FUN_0046af87(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00485ca4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (extraout_ECX[4] != 0) {
    (**(code **)(extraout_ECX[4] + 0x1c))();
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_00485d04;
  *unaff_FS_OFFSET = uVar1;
  return;
}

