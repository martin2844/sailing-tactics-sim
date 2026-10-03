
void __thiscall FUN_004961d0(void *this)

{
  DAT_004da1a8 = DAT_004da1a8 + 1;
  if (1 < DAT_004da1a8) {
    DAT_004da1a8 = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

