
void __thiscall FUN_004540a0(void *this)

{
  bool bVar1;
  
  DAT_004ac990 = DAT_004ac990 + 1;
  bVar1 = DAT_004ac990 == 1;
  if (1 < DAT_004ac990) {
    DAT_004ac990 = 0;
  }
  if (bVar1) {
    DAT_004ac98c = 1;
  }
  DAT_004ac8fc = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

