
void __thiscall FUN_00499e00(void *this)

{
  DAT_00536524 = DAT_00536524 + 1;
  if (1 < DAT_00536524) {
    DAT_00536524 = 0;
  }
  DAT_005364fc = 1;
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

