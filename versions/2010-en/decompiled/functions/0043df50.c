
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_0043df50(void)

{
  int iVar1;
  uint uVar2;
  
  FUN_0043e160();
  iVar1 = DAT_005233a4;
  if (DAT_005233a4 < DAT_004f4680) {
    iVar1 = DAT_004f4680;
  }
  if ((iVar1 < DAT_004fe2a8 / 2) || (DAT_004f71c4 == 3)) {
    iVar1 = DAT_004fe624 / 9;
    uVar2 = DAT_004fe75c - DAT_004fba18 >> 0x1f;
    if (((int)((DAT_004fe75c - DAT_004fba18 ^ uVar2) - uVar2) < iVar1) &&
       ((uVar2 = DAT_005233a4 - DAT_004fbba0 >> 0x1f,
        (int)((DAT_005233a4 - DAT_004fbba0 ^ uVar2) - uVar2) < iVar1 && (DAT_005363b4 == 0)))) {
      _DAT_004fe938 = _DAT_004fe938 - _DAT_004cc580;
      DAT_00511624 = 0;
      DAT_004fe75c = 0;
      DAT_005233a4 = 0;
      DAT_004f7094 = 0;
      DAT_005356b4 = 0;
      DAT_004f6a6c = 0;
      DAT_004fbbac = 0;
    }
    uVar2 = DAT_00525aa0 - DAT_004fba18 >> 0x1f;
    if ((((int)((DAT_00525aa0 - DAT_004fba18 ^ uVar2) - uVar2) < iVar1) &&
        (uVar2 = DAT_004f4680 - DAT_004fbba0 >> 0x1f,
        (int)((DAT_004f4680 - DAT_004fbba0 ^ uVar2) - uVar2) < iVar1)) && (DAT_005363b4 == 0)) {
      _DAT_004fe938 = _DAT_004fe938 - _DAT_004cc588;
      DAT_00511624 = 0;
      DAT_00525aa0 = 0;
      DAT_004f4680 = 0;
      DAT_004f7094 = 0;
      DAT_005356b4 = 0;
      DAT_004f6a6c = 0;
      DAT_004fbbac = 0;
    }
  }
  if (_DAT_004cc8f0 < _DAT_004fe938) {
    _DAT_004fe938 = _DAT_004fe938 - _DAT_004cc8f0;
  }
  if (_DAT_004fe938 < _DAT_004cc658) {
    _DAT_004fe938 = _DAT_004fe938 - _DAT_004cc900;
  }
  DAT_00535744 = (int)(longlong)_DAT_004fe938;
  if ((DAT_004f7094 == 1) && (DAT_00522ff4 != DAT_0053556c)) {
    DAT_00511624 = 1;
    DAT_004f7094 = 0;
    DAT_004f6a6c = 0;
    DAT_004fdfd0 = 0;
    DAT_004fbbac = 0;
    _DAT_004f399c = DAT_004f8cd0;
  }
  if ((DAT_004f7094 == -1) && (DAT_004feccc < 0x46)) {
    DAT_00511624 = 1;
    DAT_004f7094 = 0;
    DAT_004f6a6c = 0;
    DAT_004fdfd0 = 0;
    DAT_004fbbac = 0;
  }
  DAT_00535744 = FUN_0041bc20(DAT_00535744);
  return DAT_00535744;
}

