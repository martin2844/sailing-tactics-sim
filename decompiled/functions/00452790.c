
void __thiscall FUN_00452790(void *this,undefined4 param_1,int param_2,int param_3)

{
  DAT_004a774c = param_2;
  DAT_004aa97c = param_3;
  if ((((0 < param_2) && (param_2 < DAT_004a763c / 3 + 2)) && (param_3 < DAT_004a600c + 0x14)) &&
     ((DAT_004a600c < param_3 && (0 < DAT_004ac980)))) {
    DAT_004a6774 = DAT_004a6774 + 1;
    if (DAT_00491184 < DAT_004a6774) {
      DAT_004a6774 = 0;
    }
    DAT_004aa97c = 0;
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((0 < DAT_004aa97c) &&
     (0 < DAT_004ac988 + DAT_004ac984 + DAT_004ac980 + DAT_004ac974 + DAT_004ac970 + DAT_004ac968 +
          DAT_004aa980 + DAT_004ac938)) {
    DAT_004ac974 = 0;
    DAT_004ac970 = 0;
    DAT_004aa980 = 0;
    DAT_004ac968 = 0;
    DAT_004ac938 = 0;
    DAT_004ac988 = 0;
    DAT_004ac980 = 0;
    DAT_004ac984 = 0;
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if (DAT_004ac8fc == 1) {
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  FUN_00468021(this);
  return;
}

