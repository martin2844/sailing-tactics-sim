
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0042ba00(void)

{
  uint uVar1;
  int local_4;
  
  if ((((DAT_004aa824 - DAT_004a72d0 / 0x32 < DAT_004a5ba0 - DAT_004a3f04 / 0xf) &&
       (DAT_004aa808 + -0x14 < DAT_004a4f80)) && (DAT_004a4f80 < DAT_004ab150 + 0x14)) &&
     (DAT_00491140 == 1)) {
    uVar1 = DAT_004a4f80 - DAT_004a70ec >> 0x1f;
    if (DAT_004a763c / 0xc < (int)((DAT_004a4f80 - DAT_004a70ec ^ uVar1) - uVar1)) {
      local_4 = (int)(longlong)((double)(DAT_004a70ec - DAT_004a4f80) / _DAT_004ab0c8) * 3;
    }
    else {
      local_4 = (int)(longlong)((double)(DAT_004a70ec - DAT_004a4f80) / _DAT_004ab0c8);
    }
  }
  else {
    local_4 = 0;
    if ((DAT_004a4dfc == 0) && (DAT_004abf9c == 0)) {
      DAT_004a7044 = 0;
    }
  }
  if (local_4 != 0) {
    DAT_004a7044 = local_4 / 10;
    DAT_004a8914 = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
    DAT_004a496c = 0;
    DAT_004a684c = 0;
  }
  if ((DAT_004a4dfc != 0) || (DAT_004a684c == 3)) {
    if (DAT_004a7064 < 0x15) {
      local_4 = DAT_0049114c * DAT_004aa734 * -300;
    }
    else {
      local_4 = DAT_0049114c * DAT_004aa734 * -600;
    }
    DAT_004a7044 = local_4 / 10;
  }
  if (DAT_004abf9c == 1) {
    local_4 = DAT_0049114c * DAT_004aa734 * 0xfa;
    DAT_004a7044 = local_4 / 10;
  }
  if ((DAT_004a684c == 1) || (DAT_004a684c == 2)) {
    if (DAT_00491188 < 3) {
      local_4 = DAT_0049114c * DAT_004aa734 * 300;
    }
    else {
      local_4 = DAT_0049114c * DAT_004aa734 * 400;
    }
    DAT_004a7044 = local_4 / 10;
  }
  _DAT_004a78e8 =
       _DAT_004a78e8 -
       (double)DAT_0049114c *
       (double)local_4 *
       (((_DAT_00484d48 - _DAT_00484f50 / (double)DAT_00491170) * _DAT_00484dd8) / _DAT_004ab0c8);
  if ((DAT_004abf9c == 1) && (DAT_004aa734 != DAT_004abe74)) {
    DAT_004abf9c = 0;
    _DAT_004a78e8 = (double)(DAT_004aa5b4 - (0xb4 - DAT_004a5f14) * DAT_004aa734);
    DAT_004a496c = 1;
    DAT_004a7044 = 0;
    if (DAT_004ac9c0 == 0) {
      PlaySoundA((LPCSTR)0x86,DAT_004ac1d4,0x40005);
    }
  }
  if ((DAT_004a684c == 1) && (0xb4 - DAT_004a5f14 < DAT_004a7bcc)) {
    DAT_004a684c = 0;
    DAT_004a496c = 1;
    DAT_004a7044 = 0;
    _DAT_004a78e8 = (double)(DAT_004aa5b4 - DAT_004aa734 * (0xb4 - DAT_004a5f14));
  }
  if ((DAT_004a684c == 2) && (0x5a < DAT_004a7bcc)) {
    DAT_004a7044 = 0;
    DAT_004a684c = 0;
  }
  if ((DAT_004a684c == 3) && (DAT_004a7bcc < 0x5a)) {
    DAT_004a684c = 0;
    DAT_004a7044 = 0;
  }
  if (DAT_004a496c == 1) {
    _DAT_004a78e8 = (double)(DAT_004aa5b4 - (0xb4 - DAT_004a5f14) * DAT_004aa734);
  }
  return local_4;
}

