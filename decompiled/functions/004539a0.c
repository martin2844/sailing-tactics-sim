
void __thiscall FUN_004539a0(void *this)

{
  DAT_004ac8fc = 0;
  DAT_004ac94c = DAT_004ac94c + 1;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

