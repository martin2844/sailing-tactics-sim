
void __thiscall FUN_00450d40(void *this)

{
  DAT_00491158 = DAT_00491158 + 1;
  if (1 < DAT_00491158) {
    DAT_00491158 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

