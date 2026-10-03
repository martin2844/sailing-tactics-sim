
void __thiscall FUN_00453ca0(void *this)

{
  DAT_0049117c = DAT_0049117c + 1;
  if (1 < DAT_0049117c) {
    DAT_0049117c = 0;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

