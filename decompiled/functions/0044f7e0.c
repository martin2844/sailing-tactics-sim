
void __thiscall FUN_0044f7e0(void *this)

{
  DAT_004ac978 = DAT_004ac978 + 1;
  if (1 < DAT_004ac978) {
    DAT_004ac978 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

