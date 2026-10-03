
void FUN_00470132(void)

{
  undefined4 uVar1;
  HDC hdc;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = (int)&PTR_FUN_00487024;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (extraout_ECX[1] != 0) {
    hdc = (HDC)FUN_00470101(extraout_ECX);
    DeleteDC(hdc);
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = (int)&PTR_FUN_00485d04;
  *unaff_FS_OFFSET = uVar1;
  return;
}

