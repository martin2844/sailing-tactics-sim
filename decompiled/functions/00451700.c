
void __thiscall FUN_00451700(void *this)

{
  DAT_004ac938 = DAT_004ac938 + 1;
  if (1 < DAT_004ac938) {
    DAT_004ac938 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
  DAT_004ac94c = 0;
  DAT_004aa980 = 0;
  DAT_004ac980 = 0;
  DAT_004a60a8 = 1;
  return;
}

