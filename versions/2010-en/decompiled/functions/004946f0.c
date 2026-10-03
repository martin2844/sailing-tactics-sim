
void __thiscall FUN_004946f0(void *this)

{
  DAT_004f71c4 = DAT_004f71c4 + 1;
  if (3 < DAT_004f71c4) {
    DAT_004f71c4 = 1;
  }
  DAT_00523a5c = 0;
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

