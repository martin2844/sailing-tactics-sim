
void __thiscall FUN_00496440(void *this)

{
  DAT_004da1b0 = DAT_004da1b0 + 1;
  if (1 < DAT_004da1b0) {
    DAT_004da1b0 = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

