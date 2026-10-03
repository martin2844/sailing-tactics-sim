
void __thiscall FUN_004556b0(void *this)

{
  DAT_004911a4 = DAT_004911a4 + 1;
  if (1 < DAT_004911a4) {
    DAT_004911a4 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

