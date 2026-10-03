
void __thiscall FUN_00494440(void *this)

{
  DAT_004f4520 = DAT_004f4520 + 1;
  if (1 < DAT_004f4520) {
    DAT_004f4520 = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

