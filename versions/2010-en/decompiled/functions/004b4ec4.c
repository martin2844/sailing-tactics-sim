
void FUN_004b4ec4(void)

{
  HDC hDC;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004ced44;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  hDC = (HDC)FUN_004b47e1();
  ReleaseDC((HWND)extraout_ECX[4],hDC);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b4812();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

