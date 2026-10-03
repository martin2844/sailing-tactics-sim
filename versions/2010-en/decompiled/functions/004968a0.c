
void __thiscall FUN_004968a0(void *this)

{
  DAT_005363e0 = DAT_005363e0 + 1;
  if (1 < DAT_005363e0) {
    DAT_005363e0 = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

