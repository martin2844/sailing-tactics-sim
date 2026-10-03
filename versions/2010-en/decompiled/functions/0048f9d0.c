
void __thiscall FUN_0048f9d0(void *this)

{
  DAT_0053643c = DAT_0053643c + 1;
  if (1 < DAT_0053643c) {
    DAT_0053643c = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

