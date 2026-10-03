
void FUN_0047531c(void)

{
  uint uVar1;
  undefined4 *this;
  int unaff_EBP;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = this;
  *this = &PTR_FUN_004885cc;
  iVar2 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (0 < (int)this[0x21]) {
    do {
      uVar1 = FUN_0047602d(this,iVar2);
      if ((uVar1 != 0) && (*(undefined4 **)(uVar1 + 0x70) == this)) {
        *(undefined4 *)(uVar1 + 0x70) = 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)this[0x21]);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00466c62();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004728f8();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

