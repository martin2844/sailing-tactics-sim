
LRESULT __thiscall FUN_004785b7(void *this,int param_1,LRESULT param_2)

{
  SHORT SVar1;
  uint uVar2;
  HWND hWnd;
  HWND pHVar3;
  LRESULT LVar4;
  uint uVar5;
  
  SVar1 = GetKeyState(0x11);
  if (SVar1 < 0) {
    uVar5 = 8;
  }
  else {
    uVar5 = 0;
  }
  SVar1 = GetKeyState(0x10);
  if (SVar1 < 0) {
    uVar2 = 4;
  }
  else {
    uVar2 = 0;
  }
  hWnd = GetFocus();
  pHVar3 = GetDesktopWindow();
  if (hWnd == (HWND)0x0) {
    param_2 = SendMessageA(*(HWND *)((int)this + 0x1c),0x20a,param_1 << 0x10 | uVar5 | uVar2,param_2
                          );
  }
  else {
    LVar4 = param_2;
    do {
      param_2 = LVar4;
      LVar4 = SendMessageA(hWnd,0x20a,param_1 << 0x10 | uVar5 | uVar2,param_2);
      hWnd = GetParent(hWnd);
      if (LVar4 != 0) {
        return LVar4;
      }
      if (hWnd == (HWND)0x0) {
        return 0;
      }
      param_2 = 0;
      LVar4 = 0;
    } while (hWnd != pHVar3);
  }
  return param_2;
}

