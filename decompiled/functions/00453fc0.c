
void __thiscall FUN_00453fc0(void *this)

{
  DAT_004aae24 = DAT_004aae24 + 1;
  if (1 < DAT_004aae24) {
    DAT_004aae24 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

