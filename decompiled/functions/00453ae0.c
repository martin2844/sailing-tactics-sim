
void __thiscall FUN_00453ae0(void *this)

{
  DAT_004a40c4 = DAT_004a40c4 + 1;
  if (1 < DAT_004a40c4) {
    DAT_004a40c4 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

