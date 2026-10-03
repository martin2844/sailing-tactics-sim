
void __thiscall FUN_004533c0(void *this)

{
  DAT_004a85d4 = DAT_004a85d4 + -0x14;
  if (DAT_004a85d4 < 0) {
    DAT_004a85d4 = -1;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

