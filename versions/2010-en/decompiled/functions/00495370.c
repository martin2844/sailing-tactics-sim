
void __thiscall FUN_00495370(void *this)

{
  if (DAT_00536448 != 300) {
    DAT_00536444 = 300;
    DAT_00536448 = 300;
    DAT_005363f0 = 0;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    return;
  }
  DAT_00536444 = 0;
  DAT_00536448 = 0;
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

