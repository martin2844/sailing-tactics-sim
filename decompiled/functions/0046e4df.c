
undefined4 FUN_0046e4df(void)

{
  undefined4 uVar1;
  LPSTR pCVar2;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  int iVar3;
  
  FUN_00457418();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_0046e590(this,(int *)(unaff_EBP + -300));
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x10));
  iVar3 = 0x100;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  pCVar2 = (LPSTR)FUN_0046c276((void *)(unaff_EBP + -0x10),0x100);
  FUN_0046ce82((byte *)(unaff_EBP + -0x11a),pCVar2,iVar3);
  FUN_0046c2c5((void *)(unaff_EBP + -0x10),-1);
  FUN_0046bd8a(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5((int *)(unaff_EBP + -0x10));
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

