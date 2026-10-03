
void __thiscall FUN_00494c90(void *this)

{
  DAT_00523a5c = DAT_00523a5c + 1;
  if (1 < DAT_00523a5c) {
    DAT_00523a5c = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

