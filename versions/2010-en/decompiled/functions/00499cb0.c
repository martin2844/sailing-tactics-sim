
void __thiscall FUN_00499cb0(void *this)

{
  DAT_00536514 = DAT_00536514 + 1;
  if (1 < DAT_00536514) {
    DAT_00536514 = 0;
  }
  if (DAT_00536514 == 0) {
    DAT_004da158 = 1;
  }
  DAT_005364fc = 1;
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

