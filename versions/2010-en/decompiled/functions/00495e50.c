
void __thiscall FUN_00495e50(void *this)

{
  if (((DAT_005233a8 == 1) || (DAT_00536434 == 1)) || (DAT_00536438 == 1)) {
    DAT_004da200 = 1;
  }
  else {
    DAT_0050f6d4 = DAT_0050f6d4 * 2;
    if (DAT_004fe770 < DAT_0050f6d4) {
      DAT_0050f6d4 = DAT_004fe770;
    }
  }
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  DAT_005363b4 = 0;
  return;
}

