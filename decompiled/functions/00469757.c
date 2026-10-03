
void __fastcall FUN_00469757(int param_1)

{
  int iVar1;
  uint uVar2;
  HWND hWnd;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  if (iVar1 != 0) {
    hWnd = *(HWND *)(param_1 + 0x1c);
    uVar2 = GetWindowLongA(hWnd,-0x10);
    while ((uVar2 & 0x40000000) != 0) {
      hWnd = GetParent(hWnd);
      if (hWnd == (HWND)0x0) break;
      uVar2 = GetWindowLongA(hWnd,-0x10);
    }
    FUN_004680cc();
  }
  return;
}

