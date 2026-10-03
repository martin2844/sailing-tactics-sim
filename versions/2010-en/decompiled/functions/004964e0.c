
void __thiscall FUN_004964e0(void *this)

{
  DAT_005364ac = DAT_005364ac + 1;
  if (1 < DAT_005364ac) {
    DAT_005364ac = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

