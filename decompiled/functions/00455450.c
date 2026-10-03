
void __thiscall FUN_00455450(void *this)

{
  DAT_004ac9c8 = DAT_004ac9c8 + 1;
  if (1 < DAT_004ac9c8) {
    DAT_004ac9c8 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

