
void __thiscall FUN_004546a0(void *this)

{
  if (DAT_004ac984 != 300) {
    DAT_004ac980 = 300;
    DAT_004ac984 = 300;
    DAT_004ac938 = 0;
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    return;
  }
  DAT_004ac980 = 0;
  DAT_004ac984 = 0;
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

