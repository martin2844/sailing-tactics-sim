
undefined4 FUN_004c05d4(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004c08ff(0x10);
  uVar1 = *unaff_ESI;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

