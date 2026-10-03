
undefined4 * FUN_004b4fba(void)

{
  HWND hWnd;
  HDC pHVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004b46e0();
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_004cee44;
  hWnd = *(HWND *)(iVar2 + 0x1c);
  extraout_ECX[4] = hWnd;
  pHVar1 = BeginPaint(hWnd,(LPPAINTSTRUCT)(extraout_ECX + 5));
  iVar2 = FUN_004b47aa(pHVar1);
  if (iVar2 == 0) {
    FUN_004b517a();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

