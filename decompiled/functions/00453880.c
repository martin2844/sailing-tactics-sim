
void __thiscall FUN_00453880(void *this)

{
  DAT_004ac970 = DAT_004ac970 + 1;
  if (1 < DAT_004ac970) {
    DAT_004ac970 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  DAT_004ac974 = 0;
  DAT_004aa980 = 0;
  DAT_004ac938 = 0;
  DAT_004ac94c = 0;
  DAT_004ac980 = 0;
  return;
}

