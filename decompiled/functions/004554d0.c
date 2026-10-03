
void __thiscall FUN_004554d0(void *this)

{
  DAT_004911a0 = DAT_004911a0 + 1;
  if (1 < DAT_004911a0) {
    DAT_004911a0 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

