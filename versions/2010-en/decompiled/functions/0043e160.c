
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_0043e160(void)

{
  uint uVar1;
  int local_4;
  
  if ((((DAT_0052318c - DAT_004fe2a8 / 0x32 < DAT_004f8ee4 - DAT_004f3ff0 / 0xf) &&
       (DAT_005230e0 + -0x14 < DAT_004f7f78)) && (DAT_004f7f78 < DAT_00525a68 + 0x14)) &&
     (DAT_004da140 == 1)) {
    uVar1 = DAT_004f7f78 - DAT_004fe088 >> 0x1f;
    if (DAT_004fe624 / 0xc < (int)((DAT_004f7f78 - DAT_004fe088 ^ uVar1) - uVar1)) {
      local_4 = (int)(longlong)((double)(DAT_004fe088 - DAT_004f7f78) / _DAT_005259d0) * 3;
    }
    else {
      local_4 = (int)(longlong)((double)(DAT_004fe088 - DAT_004f7f78) / _DAT_005259d0);
    }
  }
  else {
    local_4 = 0;
    if ((DAT_004f7094 == 0) && (DAT_005356b4 == 0)) {
      DAT_004fdfd0 = 0;
    }
  }
  if (local_4 != 0) {
    DAT_004fdfd0 = local_4 / 10;
    DAT_00511624 = 0;
    DAT_004f7094 = 0;
    DAT_005356b4 = 0;
    DAT_004f6a6c = 0;
    DAT_004fbbac = 0;
  }
  if ((DAT_004f7094 != 0) || (DAT_004fbbac == 3)) {
    if (DAT_004fdfec < 0x15) {
      local_4 = DAT_004da14c * DAT_00522ff4 * -300;
    }
    else {
      local_4 = DAT_004da14c * DAT_00522ff4 * -400;
    }
    DAT_004fdfd0 = local_4 / 10;
  }
  if (DAT_005356b4 == 1) {
    local_4 = DAT_004da14c * DAT_00522ff4 * 0xfa;
    DAT_004fdfd0 = local_4 / 10;
  }
  if ((DAT_004fbbac == 1) || (DAT_004fbbac == 2)) {
    if (DAT_004da190 < 3) {
      local_4 = DAT_004da14c * DAT_00522ff4 * 300;
    }
    else {
      local_4 = DAT_004da14c * DAT_00522ff4 * 400;
    }
    DAT_004fdfd0 = local_4 / 10;
  }
  _DAT_004fe938 =
       _DAT_004fe938 -
       (double)DAT_004da14c *
       (double)local_4 *
       (((_DAT_004cc570 - _DAT_004cc7a8 / (double)DAT_004da178) * _DAT_004cc530) / _DAT_005259d0);
  if ((DAT_005356b4 == 1) && (DAT_00522ff4 != DAT_0053556c)) {
    DAT_005356b4 = 0;
    _DAT_004fe938 = (double)(DAT_00522b94 - (0xb4 - DAT_004fae64) * DAT_00522ff4);
    DAT_004f6a6c = 1;
    DAT_004fdfd0 = 0;
    if (DAT_00536484 == 0) {
      PlaySoundA((LPCSTR)0x86,DAT_005359c8,0x40045);
    }
  }
  if ((DAT_004fbbac == 1) && (0xb4 - DAT_004fae64 < DAT_004feccc)) {
    DAT_004fbbac = 0;
    DAT_004f6a6c = 1;
    DAT_004fdfd0 = 0;
    _DAT_004fe938 = (double)(DAT_00522b94 - DAT_00522ff4 * (0xb4 - DAT_004fae64));
  }
  if ((DAT_004fbbac == 2) && (0x5a < DAT_004feccc)) {
    DAT_004fdfd0 = 0;
    DAT_004fbbac = 0;
  }
  if ((DAT_004fbbac == 3) && (DAT_004feccc < 0x5a)) {
    DAT_004fbbac = 0;
    DAT_004fdfd0 = 0;
  }
  if (DAT_004f6a6c == 1) {
    _DAT_004fe938 = (double)(DAT_00522b94 - ((DAT_004f3f64 - DAT_004fae64) + 0xb4) * DAT_00522ff4);
  }
  return local_4;
}

