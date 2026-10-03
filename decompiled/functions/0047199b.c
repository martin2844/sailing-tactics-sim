
undefined4 * FUN_0047199b(void)

{
  undefined4 uVar1;
  void *this;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  bool bVar3;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046af4b(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a(extraout_ECX + 0x18);
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *extraout_ECX = &PTR_FUN_00487b74;
  extraout_ECX[0xf] = uVar1;
  extraout_ECX[0x13] = *(undefined4 *)(unaff_EBP + 0xc);
  extraout_ECX[0x14] = *(undefined4 *)(unaff_EBP + 0x10);
  uVar1 = *(undefined4 *)(unaff_EBP + 0x14);
  extraout_ECX[0x10] = 0;
  extraout_ECX[0x11] = 0;
  extraout_ECX[0x12] = 0;
  extraout_ECX[0x15] = uVar1;
  extraout_ECX[0x16] = 0;
  extraout_ECX[0x17] = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 0;
  extraout_ECX[0xe] = 0;
  bVar3 = DAT_0049f424 == 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (bVar3) {
    extraout_ECX[7] = 1;
    FUN_00471aba((int)extraout_ECX);
  }
  else {
    extraout_ECX[7] = 0;
    if (DAT_004ae37c == (void *)0x0) {
      this = (void *)FUN_0046b505(0x1c);
      *(void **)(unaff_EBP + 8) = this;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      if (this == (void *)0x0) {
        DAT_004ae37c = (void *)0x0;
      }
      else {
        DAT_004ae37c = (void *)FUN_00466a52(this,10);
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
    }
    if (DAT_004ae378 == (undefined4 *)0x0) {
      iVar2 = FUN_0046b505(0x20);
      *(int *)(unaff_EBP + 8) = iVar2;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      if (iVar2 == 0) {
        DAT_004ae378 = (undefined4 *)0x0;
      }
      else {
        DAT_004ae378 = FUN_0047c424();
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
    }
    AddTail(DAT_004ae37c,extraout_ECX);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

