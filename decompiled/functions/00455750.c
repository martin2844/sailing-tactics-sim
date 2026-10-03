
void __thiscall FUN_00455750(void *this)

{
  DAT_004ac9ec = DAT_004ac9ec + 1;
  if (1 < DAT_004ac9ec) {
    DAT_004ac9ec = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

