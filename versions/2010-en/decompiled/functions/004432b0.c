
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004432b0(void)

{
  int in_ECX;
  float10 fVar1;
  undefined4 local_4;
  
  DAT_00536430 = DAT_00536430 + 1;
  _DAT_004f4b38 = 0;
  _DAT_004f4b3c = 0;
  if ((DAT_004feccc < 0x50) && (1 < DAT_00535e44)) {
    _DAT_00536550 = DAT_00536558;
    _DAT_00536554 = DAT_0053655c;
    fVar1 = FUN_00466230((double)CONCAT44(DAT_004f6b00._4_4_,(undefined4)DAT_004f6b00),
                         (double)CONCAT44(DAT_004f6c18._4_4_,(undefined4)DAT_004f6c18),-1);
    _DAT_00536558 = (double)fVar1;
    _DAT_00536560 = _DAT_00536560 - _DAT_004cc650;
    if (_DAT_00536560 < _DAT_004cc658) {
      _DAT_00536560 = 0.0;
    }
    if ((((_DAT_00536558 < _DAT_004cc710) &&
         (_DAT_00536558 < (double)CONCAT44(_DAT_00536554,_DAT_00536550))) &&
        (_DAT_00536560 == _DAT_004cc658)) && (1 < DAT_00535e44)) {
      DAT_00536430 = DAT_004da178 / 5;
      _DAT_00536560 = 20.0;
      if (((DAT_00536484 == 0) && (DAT_004f7124 == 0)) && (DAT_004f7128 == 0)) {
        PlaySoundA((LPCSTR)0x99,DAT_005359c8,0x40045);
      }
      _DAT_004f4b38 = 1;
    }
  }
  if (((DAT_004fecd0 < 0x50) && (1 < DAT_00535e48)) && (DAT_004da140 == 2)) {
    _DAT_00536568 = DAT_00536570;
    _DAT_0053656c = DAT_00536574;
    fVar1 = FUN_00466230((double)CONCAT44(DAT_004f6b08._4_4_,(undefined4)DAT_004f6b08),
                         (double)CONCAT44(DAT_004f6c20._4_4_,(undefined4)DAT_004f6c20),-1);
    _DAT_00536570 = (double)fVar1;
    _DAT_00536578 = _DAT_00536578 - _DAT_004cc650;
    if (_DAT_00536578 < _DAT_004cc658) {
      _DAT_00536578 = 0.0;
    }
    if ((((_DAT_00536570 < _DAT_004cc710) &&
         (_DAT_00536570 < (double)CONCAT44(_DAT_0053656c,_DAT_00536568))) &&
        (_DAT_00536578 == _DAT_004cc658)) && (1 < DAT_00535e48)) {
      _DAT_00536578 = 20.0;
      if (((DAT_00536484 == 0) && (DAT_004f7124 == 0)) && (DAT_004f7128 == 0)) {
        PlaySoundA((LPCSTR)0x99,DAT_005359c8,0x40045);
      }
      _DAT_004f4b3c = 1;
    }
  }
  if (((DAT_00536430 == 1) && (DAT_004feccc < 0x5b)) &&
     ((DAT_00536484 == 0 && ((DAT_004f7124 == 0 && (DAT_004f7128 == 0)))))) {
    PlaySoundA((LPCSTR)0x97,DAT_005359c8,0x40015);
  }
  if (DAT_004da178 / 3 < DAT_00536430) {
    DAT_00536430 = 0;
  }
  local_4 = in_ECX;
  if (DAT_004feccc < 0x5a) {
    local_4 = DAT_00535e44 + 2;
  }
  if (DAT_004feccc < 0x3c) {
    local_4 = DAT_00535e44 * 2 + 2;
  }
  if (0x59 < DAT_004feccc) {
    local_4 = (0xc < DAT_004fb384) + 1;
  }
  fVar1 = (float10)fsin(((float10)DAT_00536430 * (float10)_DAT_004ccbb0) / (float10)DAT_004da178);
  DAT_004f8ccc = (int)(longlong)((float10)local_4 * fVar1);
  return;
}

