
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_0043e510(void)

{
  undefined4 local_4;
  
  if ((DAT_004f7098 != 0) || (DAT_004fbbb0 == 3)) {
    if (DAT_004fdff0 < 0x15) {
      local_4 = DAT_00522ff8 * -200;
    }
    else {
      local_4 = DAT_00522ff8 * -0x15e;
    }
    DAT_00535748 = FUN_0041bc20((int)(longlong)
                                     ((double)DAT_00535748 -
                                     (double)local_4 *
                                     (_DAT_004cc570 - _DAT_004cc7a8 / (double)DAT_004da178) *
                                     _DAT_004ccb48));
  }
  if ((DAT_00522ff8 != DAT_00535570) && (DAT_004f7098 == 1)) {
    DAT_00511628 = 1;
    DAT_004f7098 = 0;
    _DAT_004f39a0 = DAT_004f8cd0;
  }
  if ((DAT_004f7098 == -1) && (DAT_004fecd0 < 0x46)) {
    DAT_00511628 = 1;
    DAT_004f7098 = 0;
  }
  if (((DAT_005356b8 != 0) || (DAT_004fbbb0 == 1)) || (DAT_004fbbb0 == 2)) {
    if (DAT_004da190 < 3) {
      local_4 = DAT_00522ff8 * 0x96;
    }
    else {
      local_4 = DAT_00522ff8 * 300;
    }
    DAT_00535748 = (int)(longlong)
                        ((double)DAT_00535748 -
                        (double)local_4 *
                        (_DAT_004cc570 - _DAT_004cc7a8 / (double)DAT_004da178) * _DAT_004ccb48);
    if (DAT_00522ff8 != DAT_00535570) {
      DAT_004f6a70 = 1;
      DAT_005356b8 = 0;
      if (DAT_00536484 == 0) {
        PlaySoundA((LPCSTR)0x86,DAT_005359c8,0x40005);
      }
    }
    if ((DAT_004fbbb0 == 1) && (0xb4 - DAT_004fae68 < DAT_004fecd0)) {
      DAT_004f6a70 = 1;
      DAT_005356b8 = 0;
      DAT_004fbbb0 = 0;
    }
  }
  if ((DAT_004fbbb0 == 2) && (0x5a < DAT_004fecd0)) {
    DAT_004fbbb0 = 0;
    DAT_004fdfd0 = 0;
  }
  if ((DAT_004fbbb0 == 3) && (DAT_004fecd0 < 0x5a)) {
    DAT_004fbbb0 = 0;
    DAT_004fdfd0 = 0;
  }
  DAT_00535748 = FUN_0041bc20(DAT_00535748);
  return DAT_00535748;
}

