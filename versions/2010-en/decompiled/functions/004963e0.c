
void __thiscall FUN_004963e0(void *this)

{
  DAT_00536484 = DAT_00536484 + 1;
  if (1 < DAT_00536484) {
    DAT_00536484 = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

