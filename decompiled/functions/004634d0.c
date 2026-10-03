
undefined4 FUN_004634d0(uint param_1,HDC param_2,HWND param_3)

{
  HWND pHVar1;
  LONG LVar2;
  
  if (((DAT_004aff40 == 0) || (param_1 < 0x134)) || (param_1 == 0x137)) {
    return 0;
  }
  if (param_1 == 0x134) {
    if (DAT_004aff60 < 0x35f) {
      pHVar1 = GetWindow(param_3,5);
      if (pHVar1 != (HWND)0x0) {
        LVar2 = GetWindowLongA(param_3,-0x10);
        if (((byte)LVar2 & 3) != 3) goto LAB_00463524;
      }
    }
    return 0;
  }
LAB_00463524:
  SetTextColor(param_2,DAT_004aff70);
  SetBkColor(param_2,DAT_004aff68);
  return DAT_004aff88;
}

