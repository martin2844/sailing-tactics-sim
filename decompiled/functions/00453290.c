
void __thiscall FUN_00453290(void *this)

{
  if (1 < DAT_0049116c) {
    DAT_0049116c = DAT_0049116c + -1;
  }
  FUN_0044e380();
  DAT_00491178 = DAT_0049116c;
  DAT_00491174 = DAT_00491170;
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

