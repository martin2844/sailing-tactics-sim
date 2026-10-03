
HWND __thiscall FUN_004be455(void *this)

{
  HWND hWnd;
  HWND pHVar1;
  
  hWnd = GetParent(*(HWND *)((int)this + 0x1c));
  pHVar1 = (HWND)SendMessageA(hWnd,0x36b,0,0);
  if (pHVar1 == (HWND)0x0) {
    pHVar1 = hWnd;
  }
  return pHVar1;
}

