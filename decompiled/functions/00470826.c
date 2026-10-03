
undefined4 * FUN_00470826(void)

{
  int iVar1;
  bool bVar2;
  HWND hWnd;
  HDC pHVar3;
  undefined3 extraout_var;
  undefined4 *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = this;
  FUN_00470000(this);
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *this = &PTR_FUN_00487124;
  hWnd = (HWND)0x0;
  if (iVar1 != 0) {
    hWnd = *(HWND *)(iVar1 + 0x1c);
  }
  this[4] = hWnd;
  pHVar3 = GetWindowDC(hWnd);
  bVar2 = FUN_004700ca(this,(uint)pHVar3);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    FUN_00470a9a();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return this;
}

