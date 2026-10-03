
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042bda0(void)

{
  undefined4 local_4;
  
  if ((DAT_004a4e00 != 0) || (DAT_004a6850 == 3)) {
    if (DAT_004a7068 < 0x15) {
      local_4 = DAT_004aa738 * -200;
    }
    else {
      local_4 = DAT_004aa738 * -0x15e;
    }
    DAT_004ac020 = FUN_00413cb0((int)(longlong)
                                     ((double)DAT_004ac020 -
                                     (double)local_4 *
                                     (_DAT_00484d48 - _DAT_00484f50 / (double)DAT_00491170) *
                                     _DAT_00485240));
  }
  if ((DAT_004aa738 != DAT_004abe78) && (DAT_004a4e00 == 1)) {
    DAT_004a8918 = 1;
    DAT_004a4e00 = 0;
    _DAT_004a3a20 = DAT_004a5b80;
  }
  if ((DAT_004a4e00 == -1) && (DAT_004a7bd0 < 0x46)) {
    DAT_004a8918 = 1;
    DAT_004a4e00 = 0;
  }
  if (((DAT_004abfa0 != 0) || (DAT_004a6850 == 1)) || (DAT_004a6850 == 2)) {
    if (DAT_00491188 < 3) {
      local_4 = DAT_004aa738 * 0x96;
    }
    else {
      local_4 = DAT_004aa738 * 300;
    }
    DAT_004ac020 = (int)(longlong)
                        ((double)DAT_004ac020 -
                        (double)local_4 *
                        (_DAT_00484d48 - _DAT_00484f50 / (double)DAT_00491170) * _DAT_00485240);
    if (DAT_004aa738 != DAT_004abe78) {
      DAT_004a4970 = 1;
      DAT_004abfa0 = 0;
      if (DAT_004ac9c0 == 0) {
        PlaySoundA((LPCSTR)0x86,DAT_004ac1d4,0x40005);
      }
    }
    if ((DAT_004a6850 == 1) && (0xb4 - DAT_004a5f18 < DAT_004a7bd0)) {
      DAT_004a4970 = 1;
      DAT_004abfa0 = 0;
      DAT_004a6850 = 0;
    }
  }
  if ((DAT_004a6850 == 2) && (0x5a < DAT_004a7bd0)) {
    DAT_004a6850 = 0;
    DAT_004a7044 = 0;
  }
  if ((DAT_004a6850 == 3) && (DAT_004a7bd0 < 0x5a)) {
    DAT_004a6850 = 0;
    DAT_004a7044 = 0;
  }
  DAT_004ac020 = FUN_00413cb0(DAT_004ac020);
  return;
}

