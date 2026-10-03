
void __thiscall FUN_00493e10(void *this)

{
  if (DAT_004da174 < 0xf) {
    DAT_004da174 = DAT_004da174 + 1;
  }
  FUN_00464940();
  DAT_004da180 = DAT_004da174;
  DAT_004da17c = DAT_004da178;
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

