
int FUN_00467983(void)

{
  int iVar1;
  HWND pHVar2;
  HWND unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  HWND unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(HWND *)(unaff_EBP + -0x1c) != unaff_EBX) {
    EnableWindow(unaff_EDI,1);
  }
  if (unaff_EDI != unaff_EBX) {
    pHVar2 = GetActiveWindow();
    if (pHVar2 == (HWND)unaff_ESI[7]) {
      SetActiveWindow(unaff_EDI);
    }
  }
  (**(code **)(*unaff_ESI + 0x60))();
  FUN_00467828((int)unaff_ESI);
  iVar1 = unaff_ESI[0xb];
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar1;
}

