
void FUN_00470898(void)

{
  HDC hDC;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = (int)&PTR_FUN_00487124;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  hDC = (HDC)FUN_00470101(extraout_ECX);
  ReleaseDC((HWND)extraout_ECX[4],hDC);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470132();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

