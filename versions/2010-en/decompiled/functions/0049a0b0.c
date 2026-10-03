
void __thiscall FUN_0049a0b0(void *this)

{
  DAT_00536518 = DAT_00536518 + 1;
  if (1 < DAT_00536518) {
    DAT_00536518 = 0;
  }
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
  DAT_005363b4 = 0;
  return;
}

