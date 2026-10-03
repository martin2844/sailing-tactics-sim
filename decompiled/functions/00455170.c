
void __thiscall FUN_00455170(void *this)

{
  DAT_004a776c = DAT_004a776c + 1;
  if (3 < DAT_004a776c) {
    DAT_004a776c = 1;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

