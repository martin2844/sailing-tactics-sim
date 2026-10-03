
undefined4 FUN_0046a4d3(void)

{
  int iVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00457418();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd0;
  FUN_0046a576((void *)(unaff_EBP + -0x2c),extraout_ECX,*(undefined4 *)(unaff_EBP + 8));
  iVar1 = FUN_0047b5c5();
  *(undefined4 *)(unaff_EBP + 8) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar1;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar1 + 0xb8);
  *(int *)(iVar1 + 0xb8) = extraout_ECX[7];
  (**(code **)(*extraout_ECX + 0x8c))(unaff_EBP + -0x2c);
  *(undefined4 *)(unaff_EBP + 8) = 1;
  uVar2 = func_0x0046a559();
  return uVar2;
}

