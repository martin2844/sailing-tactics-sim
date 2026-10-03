
void __thiscall FUN_00496100(void *this)

{
  DAT_005363e4 = DAT_005363e4 + 1;
  if (1 < DAT_005363e4) {
    DAT_005363e4 = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

