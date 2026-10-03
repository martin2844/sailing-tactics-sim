
void __thiscall FUN_00496e30(void *this)

{
  DAT_004da1e8 = DAT_004da1e8 + 1;
  if (1 < DAT_004da1e8) {
    DAT_004da1e8 = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

