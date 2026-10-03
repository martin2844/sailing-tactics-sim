
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041e0a0(void)

{
  int iVar1;
  float10 fVar2;
  
  if (DAT_00523a5c != 1) goto LAB_0041e0fb;
  DAT_004f71c4 = 2;
  if (DAT_004f8cd0 < 0xf) {
LAB_0041e0d1:
    if (-0x1e < DAT_004f8cd0) {
      DAT_004f71c4 = 3;
    }
  }
  else {
    if (DAT_004f8cd0 < 0x1e) {
      DAT_004f71c4 = 1;
    }
    if (DAT_004f8cd0 < 0xf) goto LAB_0041e0d1;
  }
  iVar1 = FUN_0043ceb0(0x5a,1);
  if (iVar1 == 1) {
    DAT_004f71c4 = 3;
  }
LAB_0041e0fb:
  DAT_004f49a4 = FUN_0041e3a0(DAT_004f49a4);
  if ((DAT_004f49a4 == 0) && (DAT_005363e8 == 0)) {
    iVar1 = DAT_00522ff4 * -5;
  }
  else {
    iVar1 = -DAT_004f49a4;
  }
  DAT_004fbb94 = FUN_0041bc20(DAT_00535744 + iVar1);
  if (DAT_00512d64 == -1) {
    DAT_004fbb94 = FUN_0041bc20(DAT_00522b94 + 0xb4);
    DAT_004f49a4 = FUN_0041bc20(DAT_00535744 - DAT_004fbb94);
  }
  if (DAT_00512d64 == 1) {
    DAT_004fbb94 = FUN_0041bc20(DAT_00522b94);
    DAT_004f49a4 = FUN_0041bc20(DAT_00535744 - DAT_004fbb94);
  }
  if (DAT_00512d64 == 100) {
    fVar2 = FUN_0043ec20((double)CONCAT44(DAT_004f6b08._4_4_,(undefined4)DAT_004f6b08),
                         (double)CONCAT44(DAT_004f6c20._4_4_,(undefined4)DAT_004f6c20),0,1);
    DAT_004fbb94 = FUN_0041bc20((int)(longlong)(fVar2 * (float10)_DAT_004cc3e8));
    DAT_004f49a4 = FUN_0041bc20(DAT_00535744 - DAT_004fbb94);
  }
  return;
}

