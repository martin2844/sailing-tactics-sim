
void __fastcall FUN_00474e53(void *param_1)

{
  CWnd *pCVar1;
  
  FUN_00474e9c(param_1,1);
  ReleaseCapture();
  GetDesktopWindow();
  pCVar1 = FUN_004680cc();
  LockWindowUpdate((HWND)0x0);
  if (*(int *)((int)param_1 + 0x84) != 0) {
    ReleaseDC(*(HWND *)(pCVar1 + 0x1c),*(HDC *)(*(int *)((int)param_1 + 0x84) + 4));
    *(undefined4 *)((int)param_1 + 0x84) = 0;
  }
  return;
}

