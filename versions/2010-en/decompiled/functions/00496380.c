
void __thiscall FUN_00496380(void *this)

{
  DAT_00536498 = DAT_00536498 + 1;
  if (1 < DAT_00536498) {
    DAT_00536498 = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

