
undefined4 FUN_0046c0db(void)

{
  undefined4 uVar1;
  uint uVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (*(int *)(unaff_EBP + 0x10) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = lstrlenA(*(LPCSTR *)(unaff_EBP + 0x10));
  }
  FUN_0046c034((void *)(unaff_EBP + -0x10),((undefined4 *)**(undefined4 **)(unaff_EBP + 0xc))[-2],
               (undefined4 *)**(undefined4 **)(unaff_EBP + 0xc),uVar2,
               *(undefined4 **)(unaff_EBP + 0x10));
  FUN_0046bd8a(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5((int *)(unaff_EBP + -0x10));
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

