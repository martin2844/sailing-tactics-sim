
undefined4 FUN_0046cf6a(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  uVar2 = 0;
  iVar1 = *(int *)(extraout_ECX + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  if (iVar1 != 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar2 = (**(code **)(extraout_ECX + 0xc))();
    *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    uVar2 = *(undefined4 *)(unaff_EBP + -0x14);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

