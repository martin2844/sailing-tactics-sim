
LRESULT __thiscall FUN_004bcc97(int param_1,int param_2,LRESULT param_3)

{
  LPARAM LVar1;
  SHORT SVar2;
  uint uVar3;
  HWND hWnd;
  HWND pHVar4;
  LRESULT LVar5;
  uint uVar6;
  
  SVar2 = GetKeyState(0x11);
  if (SVar2 < 0) {
    uVar6 = 8;
  }
  else {
    uVar6 = 0;
  }
  SVar2 = GetKeyState(0x10);
  if (SVar2 < 0) {
    uVar3 = 4;
  }
  else {
    uVar3 = 0;
  }
  hWnd = GetFocus();
  pHVar4 = GetDesktopWindow();
  if (hWnd == (HWND)0x0) {
    param_3 = SendMessageA(*(HWND *)(param_1 + 0x1c),0x20a,param_2 << 0x10 | uVar6 | uVar3,param_3);
  }
  else {
    LVar1 = param_3;
    do {
      param_3 = LVar1;
      LVar5 = SendMessageA(hWnd,0x20a,param_2 << 0x10 | uVar6 | uVar3,param_3);
      hWnd = GetParent(hWnd);
      if (LVar5 != 0) {
        return LVar5;
      }
      if (hWnd == (HWND)0x0) {
        return 0;
      }
      param_3 = 0;
      LVar1 = 0;
    } while (hWnd != pHVar4);
  }
  return param_3;
}

