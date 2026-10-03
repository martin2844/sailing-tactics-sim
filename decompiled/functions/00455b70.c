
void __thiscall FUN_00455b70(void *this)

{
  DAT_004911d0 = DAT_004911d0 + 1;
  if (1 < DAT_004911d0) {
    DAT_004911d0 = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

