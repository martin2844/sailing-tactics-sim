
void __thiscall FUN_004931d0(void *this)

{
  bool bVar1;
  HWND hWnd;
  
  DAT_005233a8 = DAT_005233a8 + 1;
  bVar1 = DAT_005233a8 != 1;
  if (1 < DAT_005233a8) {
    DAT_005233a8 = 0;
  }
  if (bVar1) {
    hWnd = *(HWND *)((int)this + 0x1c);
  }
  else {
    hWnd = *(HWND *)((int)this + 0x1c);
  }
  DAT_005363b4 = (uint)!bVar1;
  InvalidateRect(hWnd,(RECT *)0x0,0);
  DAT_00536404 = 0;
  DAT_00536434 = 0;
  DAT_00536438 = 0;
  DAT_005363f0 = 0;
  return;
}

