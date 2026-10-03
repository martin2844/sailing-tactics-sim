
void __thiscall FUN_00491cf0(void *this)

{
  DAT_005363f0 = DAT_005363f0 + 1;
  if (1 < DAT_005363f0) {
    DAT_005363f0 = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
  DAT_00536404 = 0;
  DAT_005233a8 = 0;
  DAT_00536444 = 0;
  DAT_004fafa0 = 1;
  return;
}

