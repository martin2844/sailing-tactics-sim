
void __thiscall FUN_004944e0(void *this)

{
  DAT_0053642c = DAT_0053642c + 1;
  if (1 < DAT_0053642c) {
    DAT_0053642c = 0;
  }
  if (DAT_0053642c == 0) {
    DAT_005363b4 = DAT_0053642c;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    return;
  }
  DAT_005363b4 = 1;
  return;
}

