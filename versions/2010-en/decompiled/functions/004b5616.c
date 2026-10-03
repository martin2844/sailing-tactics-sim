
void FUN_004b5616(HWND param_1)

{
  HWND hWnd;
  int iVar1;
  uint uVar2;
  HWND pHVar3;
  HWND pHVar4;
  
  hWnd = GetFocus();
  if (hWnd == (HWND)0x0) {
    return;
  }
  if (hWnd == param_1) {
    return;
  }
  iVar1 = FUN_004b54bb(hWnd,3);
  if (iVar1 == 0) {
    hWnd = GetParent(hWnd);
    if (hWnd == param_1) {
      return;
    }
    iVar1 = FUN_004b54bb(hWnd,2);
    if (iVar1 == 0) {
      return;
    }
  }
  if ((param_1 != (HWND)0x0) && (uVar2 = GetWindowLongA(param_1,-0x10), (uVar2 & 0x40000000) != 0))
  {
    pHVar3 = GetParent(param_1);
    pHVar4 = GetDesktopWindow();
    if (pHVar3 == pHVar4) {
      return;
    }
  }
  SendMessageA(hWnd,0x14f,0,0);
  return;
}

