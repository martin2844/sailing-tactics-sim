
void __thiscall FUN_004555f0(void *this)

{
  DAT_004ac9d8 = DAT_004ac9d8 + 1;
  if (1 < DAT_004ac9d8) {
    DAT_004ac9d8 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

