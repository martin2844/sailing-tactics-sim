
void __thiscall FUN_004976a0(void *this)

{
  DAT_00500384 = DAT_00500384 + -5;
  if (DAT_00500384 < 0) {
    DAT_00500384 = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

