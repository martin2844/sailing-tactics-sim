
undefined4 * FUN_0047b8b6(void)

{
  undefined4 *this;
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  this = FUN_0047ba5e(0x1074);
  *(undefined4 **)(unaff_EBP + -0x10) = this;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar1 = (undefined4 *)0x0;
  if (this != (undefined4 *)0x0) {
    FUN_0047b5fb(this,1);
    *this = &PTR_FUN_004872e4;
    puVar1 = this;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return puVar1;
}

