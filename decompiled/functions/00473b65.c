
void FUN_00473b65(void)

{
  code *pcVar1;
  undefined4 *this;
  void *this_00;
  int iVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x14));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  pcVar1 = *(code **)(**(int **)(unaff_EBP + 0x10) + 0x6c);
  iVar2 = (*pcVar1)(unaff_EBP + -0x10,4);
  if ((iVar2 != 0) && (*(int *)(*(int *)(unaff_EBP + -0x10) + -8) != 0)) {
    iVar2 = (*pcVar1)(unaff_EBP + -0x14,3);
    if ((iVar2 != 0) && (*(int *)(*(int *)(unaff_EBP + -0x14) + -8) != 0)) {
      this = *(undefined4 **)(unaff_EBP + 0x14);
      iVar2 = *(int *)(unaff_EBP + 0xc);
      if (this != (undefined4 *)0x0) {
        FUN_0046c00d(this,(LPCSTR)(*(int *)(unaff_EBP + -0x10) + 1));
        *(undefined4 *)(iVar2 + 0x3c) = *this;
        *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x14) + 1;
      }
      this_00 = *(void **)(unaff_EBP + 8);
      FUN_0046c25e(this_00,(undefined4 *)(unaff_EBP + -0x14));
      FUN_0046c249(this_00);
      FUN_0046c249(this_00);
      FUN_0046c25e(this_00,(undefined4 *)(unaff_EBP + -0x10));
      FUN_0046c249(this_00);
      *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5((int *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046bec5((int *)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

