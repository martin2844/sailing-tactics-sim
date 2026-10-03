
void __thiscall FUN_00453c30(void *this)

{
  DAT_004ac958 = DAT_004ac958 + 1;
  if (1 < DAT_004ac958) {
    DAT_004ac958 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

