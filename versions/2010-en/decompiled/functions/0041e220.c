
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041e220(void)

{
  int iVar1;
  float10 fVar2;
  
  if (DAT_00523a60 != 1) goto LAB_0041e27b;
  _DAT_004f71c8 = 2;
  if (DAT_004f8cd0 < 0xf) {
LAB_0041e251:
    if (-0x1e < DAT_004f8cd0) {
      _DAT_004f71c8 = 3;
    }
  }
  else {
    if (DAT_004f8cd0 < 0x1e) {
      _DAT_004f71c8 = 1;
    }
    if (DAT_004f8cd0 < 0xf) goto LAB_0041e251;
  }
  iVar1 = FUN_0043ceb0(0x5a,2);
  if (iVar1 == 1) {
    _DAT_004f71c8 = 3;
  }
LAB_0041e27b:
  DAT_004f49a8 = FUN_0041e3a0(DAT_004f49a8);
  if ((DAT_004f49a8 == 0) && (DAT_005363e8 == 0)) {
    iVar1 = DAT_00522ff8 * -5;
  }
  else {
    iVar1 = -DAT_004f49a8;
  }
  _DAT_004fbb98 = FUN_0041bc20(DAT_00535748 + iVar1);
  if (DAT_00512d68 == -1) {
    _DAT_004fbb98 = FUN_0041bc20(DAT_00522b98 + 0xb4);
    DAT_004f49a8 = FUN_0041bc20(DAT_00535748 - _DAT_004fbb98);
  }
  if (DAT_00512d68 == 1) {
    _DAT_004fbb98 = FUN_0041bc20(DAT_00522b98);
    DAT_004f49a8 = FUN_0041bc20(DAT_00535748 - _DAT_004fbb98);
  }
  if ((DAT_00512d68 == 100) && (DAT_004da140 == 2)) {
    fVar2 = FUN_0043ec20((double)CONCAT44(DAT_004f6b00._4_4_,(undefined4)DAT_004f6b00),
                         (double)CONCAT44(DAT_004f6c18._4_4_,(undefined4)DAT_004f6c18),0,2);
    _DAT_004fbb98 = FUN_0041bc20((int)(longlong)(fVar2 * (float10)_DAT_004cc3e8));
    DAT_004f49a8 = FUN_0041bc20(DAT_00535748 - _DAT_004fbb98);
  }
  return;
}

