
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415c40(void)

{
  int iVar1;
  float10 fVar2;
  
  if (DAT_004aae28 != 1) goto LAB_00415c9b;
  _DAT_004a4e90 = 2;
  if (DAT_004a5b80 < 0xf) {
LAB_00415c71:
    if (-0x1e < DAT_004a5b80) {
      _DAT_004a4e90 = 3;
    }
  }
  else {
    if (DAT_004a5b80 < 0x1e) {
      _DAT_004a4e90 = 1;
    }
    if (DAT_004a5b80 < 0xf) goto LAB_00415c71;
  }
  iVar1 = FUN_0042ad00(0x5a);
  if (iVar1 == 1) {
    _DAT_004a4e90 = 3;
  }
LAB_00415c9b:
  DAT_004a4610 = FUN_00415dc0(DAT_004a4610);
  if ((DAT_004a4610 == 0) && (DAT_004ac930 == 0)) {
    iVar1 = DAT_004aa738 * -5;
  }
  else {
    iVar1 = -DAT_004a4610;
  }
  _DAT_004a6838 = FUN_00413cb0(DAT_004ac020 + iVar1);
  if (DAT_004a9448 == -1) {
    _DAT_004a6838 = FUN_00413cb0(DAT_004aa5b8 + 0xb4);
    DAT_004a4610 = FUN_00413cb0(DAT_004ac020 - _DAT_004a6838);
  }
  if (DAT_004a9448 == 1) {
    _DAT_004a6838 = FUN_00413cb0(DAT_004aa5b8);
    DAT_004a4610 = FUN_00413cb0(DAT_004ac020 - _DAT_004a6838);
  }
  if ((DAT_004a9448 == 100) && (DAT_00491140 == 2)) {
    fVar2 = FUN_0042c400((double)CONCAT44(DAT_004a49f4,DAT_004a49f0),
                         (double)CONCAT44(DAT_004a4aec,DAT_004a4ae8),0,2);
    _DAT_004a6838 = FUN_00413cb0((int)(longlong)(fVar2 * (float10)_DAT_00484d78));
    DAT_004a4610 = FUN_00413cb0(DAT_004ac020 - _DAT_004a6838);
  }
  return;
}

