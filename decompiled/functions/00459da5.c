
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00459da5(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4) = 0x459dad;
  FUN_00459f50();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

