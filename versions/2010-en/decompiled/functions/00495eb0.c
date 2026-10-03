
void __thiscall FUN_00495eb0(void *this)

{
  DAT_004fe77c = DAT_004fe77c + 1;
  if (3 < DAT_004fe77c) {
    DAT_004fe77c = 1;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

