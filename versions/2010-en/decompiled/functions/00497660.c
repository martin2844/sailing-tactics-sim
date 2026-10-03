
void __thiscall FUN_00497660(void *this)

{
  DAT_00500384 = DAT_00500384 + 5;
  if (0x5a < DAT_00500384) {
    DAT_00500384 = 0x5a;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

