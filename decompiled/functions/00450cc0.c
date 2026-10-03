
void __thiscall FUN_00450cc0(void *this)

{
  DAT_004ac954 = DAT_004ac954 + 1;
  if (1 < DAT_004ac954) {
    DAT_004ac954 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

