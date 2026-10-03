
void FUN_004aebb3(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_0049bcd8();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd0;
  FUN_004aec56(extraout_ECX,*(undefined4 *)(unaff_EBP + 8));
  iVar1 = FUN_004bfca5();
  *(undefined4 *)(unaff_EBP + 8) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar1;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar1 + 0xb8);
  *(int *)(iVar1 + 0xb8) = extraout_ECX[7];
  (**(code **)(*extraout_ECX + 0x8c))(unaff_EBP + -0x2c);
  *(undefined4 *)(unaff_EBP + 8) = 1;
  func_0x004aec39();
  return;
}

