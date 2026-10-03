
void __thiscall FUN_00452610(void *this)

{
  bool bVar1;
  HWND hWnd;
  
  DAT_004aa980 = DAT_004aa980 + 1;
  bVar1 = DAT_004aa980 != 1;
  if (1 < DAT_004aa980) {
    DAT_004aa980 = 0;
  }
  if (bVar1) {
    hWnd = *(HWND *)((int)this + 0x1c);
  }
  else {
    hWnd = *(HWND *)((int)this + 0x1c);
  }
  DAT_004ac8fc = (uint)!bVar1;
  InvalidateRect(hWnd,(RECT *)0x0,0);
  DAT_004ac94c = 0;
  DAT_004ac970 = 0;
  DAT_004ac974 = 0;
  DAT_004ac938 = 0;
  return;
}

