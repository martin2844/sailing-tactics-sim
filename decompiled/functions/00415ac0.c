
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415ac0(void)

{
  int iVar1;
  float10 fVar2;
  
  if (DAT_004aae24 != 1) goto LAB_00415b1b;
  DAT_004a4e8c = 2;
  if (DAT_004a5b80 < 0xf) {
LAB_00415af1:
    if (-0x1e < DAT_004a5b80) {
      DAT_004a4e8c = 3;
    }
  }
  else {
    if (DAT_004a5b80 < 0x1e) {
      DAT_004a4e8c = 1;
    }
    if (DAT_004a5b80 < 0xf) goto LAB_00415af1;
  }
  iVar1 = FUN_0042ad00(0x5a);
  if (iVar1 == 1) {
    DAT_004a4e8c = 3;
  }
LAB_00415b1b:
  DAT_004a460c = FUN_00415dc0(DAT_004a460c);
  if ((DAT_004a460c == 0) && (DAT_004ac930 == 0)) {
    iVar1 = DAT_004aa734 * -5;
  }
  else {
    iVar1 = -DAT_004a460c;
  }
  _DAT_004a6834 = FUN_00413cb0(DAT_004ac01c + iVar1);
  if (DAT_004a9444 == -1) {
    _DAT_004a6834 = FUN_00413cb0(DAT_004aa5b4 + 0xb4);
    DAT_004a460c = FUN_00413cb0(DAT_004ac01c - _DAT_004a6834);
  }
  if (DAT_004a9444 == 1) {
    _DAT_004a6834 = FUN_00413cb0(DAT_004aa5b4);
    DAT_004a460c = FUN_00413cb0(DAT_004ac01c - _DAT_004a6834);
  }
  if (DAT_004a9444 == 100) {
    fVar2 = FUN_0042c400((double)CONCAT44(DAT_004a49f8._4_4_,(undefined4)DAT_004a49f8),
                         (double)CONCAT44(DAT_004a4af0._4_4_,(undefined4)DAT_004a4af0),0,1);
    _DAT_004a6834 = FUN_00413cb0((int)(longlong)(fVar2 * (float10)_DAT_00484d78));
    DAT_004a460c = FUN_00413cb0(DAT_004ac01c - _DAT_004a6834);
  }
  return;
}

