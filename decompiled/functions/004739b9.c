
bool FUN_004739b9(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  FUN_00466428();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x14));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046d861(*(UINT *)(unaff_EBP + 0xc));
  *(uint *)(unaff_EBP + -0x180) = *(uint *)(unaff_EBP + -0x180) | *(uint *)(unaff_EBP + 0x10);
  FUN_0046bd7a((undefined4 *)(unaff_EBP + 0x14));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x10));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (*(int *)(unaff_EBP + 0x18) == 0) {
    puVar2 = *(undefined4 **)(extraout_ECX + 8);
    while (puVar2 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)*puVar2;
      FUN_00473b65();
    }
  }
  else {
    FUN_00473b65();
  }
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x18));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_0046d861(0xf002);
  FUN_0046c25e((void *)(unaff_EBP + 0x14),(undefined4 *)(unaff_EBP + -0x18));
  FUN_0046c249((void *)(unaff_EBP + 0x14));
  FUN_0046c222((void *)(unaff_EBP + 0x14),"*.*");
  FUN_0046c249((void *)(unaff_EBP + 0x14));
  *(int *)(unaff_EBP + -0x1a0) = *(int *)(unaff_EBP + -0x1a0) + 1;
  *(undefined4 *)(unaff_EBP + -0x1a8) = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -0x184) = *(undefined4 *)(unaff_EBP + -0x14);
  iVar1 = FUN_0046c276(*(void **)(unaff_EBP + 8),0x104);
  *(int *)(unaff_EBP + -0x198) = iVar1;
  iVar1 = FUN_0046659a(unaff_EBP + -0x210);
  FUN_0046c2c5(*(void **)(unaff_EBP + 8),-1);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0046bec5((int *)(unaff_EBP + -0x18));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0046bec5((int *)(unaff_EBP + -0x10));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046bec5((int *)(unaff_EBP + 0x14));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5((int *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 5;
  FUN_0046bec5((int *)(unaff_EBP + -0x164));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CDialog::~CDialog((CDialog *)(unaff_EBP + -0x210));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return (bool)('\x01' - (iVar1 != 1));
}

