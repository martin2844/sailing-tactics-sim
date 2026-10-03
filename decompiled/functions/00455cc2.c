
void FUN_00455cc2(void)

{
  HLOCAL pvVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  pvVar1 = FUN_0047ba5e(0x84);
  *(HLOCAL *)(unaff_EBP + -0x10) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 != (HLOCAL)0x0) {
    FUN_0047b72d();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

