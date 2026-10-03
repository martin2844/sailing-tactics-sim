
void __thiscall FUN_00490400(void *this)

{
  DAT_004da194 = 0x14;
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  DAT_0053646c = 0;
  DAT_004da1e8 = 1;
  if ((((DAT_004da188 == 3) || (DAT_004da188 == 4)) || (DAT_004da188 == 6)) || (DAT_004da19c == 8))
  {
    DAT_004da1e8 = 0;
  }
  return;
}

