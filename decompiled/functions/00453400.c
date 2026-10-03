
void __thiscall FUN_00453400(void *this)

{
  DAT_004a85d4 = DAT_004a85d4 + 0x14;
  if (0x5a < DAT_004a85d4) {
    DAT_004a85d4 = 0x5a;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

