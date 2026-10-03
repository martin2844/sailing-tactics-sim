
undefined4 * FUN_004708da(void)

{
  int iVar1;
  HWND hWnd;
  bool bVar2;
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
  *this = &PTR_FUN_004871a4;
  hWnd = *(HWND *)(iVar1 + 0x1c);
  this[4] = hWnd;
  pHVar3 = BeginPaint(hWnd,(LPPAINTSTRUCT)(this + 5));
  bVar2 = FUN_004700ca(this,(uint)pHVar3);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    FUN_00470a9a();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return this;
}

