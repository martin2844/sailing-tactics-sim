
undefined4 FUN_0046607b(void)

{
  int iVar1;
  undefined4 uVar2;
  int *this;
  uint uVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  uVar3 = *(uint *)(unaff_EBP + 0xc);
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  else if ((int)*(uint *)(*this + -8) < (int)uVar3) {
    uVar3 = *(uint *)(*this + -8);
  }
  FUN_0046bd7a((undefined4 *)(unaff_EBP + 0xc));
  iVar1 = *(int *)(*this + -8);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0046beee(this,(undefined4 *)(unaff_EBP + 0xc),uVar3,iVar1 - uVar3,0);
  FUN_0046bd8a(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5((int *)(unaff_EBP + 0xc));
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

