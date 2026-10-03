
void __thiscall FUN_00453800(void *this)

{
  DAT_004ac968 = DAT_004ac968 + 1;
  if (1 < DAT_004ac968) {
    DAT_004ac968 = 0;
  }
  if (DAT_004ac968 == 0) {
    DAT_004ac8fc = DAT_004ac968;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    return;
  }
  DAT_004ac8fc = 1;
  return;
}

