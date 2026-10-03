
void * FUN_0046d531(void)

{
  undefined4 uVar1;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(void **)(unaff_EBP + -0x10) = this;
  CMap<>(this,10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CMap<>((void *)((int)this + 0x1c),4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00466ef2((void *)((int)this + 0x1c),7,0);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined4 *)((int)this + 0x38) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)((int)this + 0x3c) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)((int)this + 0x40) = *(undefined4 *)(unaff_EBP + 0x10);
  *unaff_FS_OFFSET = uVar1;
  return this;
}

