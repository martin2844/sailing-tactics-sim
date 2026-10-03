
void __fastcall FUN_004b9533(int param_1)

{
  HWND pHVar1;
  int iVar2;
  
  FUN_004b957c(1);
  ReleaseCapture();
  pHVar1 = GetDesktopWindow();
  iVar2 = FUN_004ac7ac(pHVar1);
  LockWindowUpdate((HWND)0x0);
  if (*(int *)(param_1 + 0x84) != 0) {
    ReleaseDC(*(HWND *)(iVar2 + 0x1c),*(HDC *)(*(int *)(param_1 + 0x84) + 4));
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  return;
}

