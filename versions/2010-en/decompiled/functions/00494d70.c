
void __thiscall FUN_00494d70(void *this)

{
  DAT_00536454 = DAT_00536454 + 1;
  if (1 < DAT_00536454) {
    DAT_00536454 = 0;
  }
  DAT_00536450 = (uint)(DAT_00536454 == 1);
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

