
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_0042f330(int param_1,int param_2,int param_3)

{
  float10 fVar1;
  float10 fVar2;
  int iVar3;
  
  if ((1 < DAT_004f69b8) && (DAT_004da1f8 == 0)) {
    fVar1 = FUN_0042f480(param_1,param_2);
    return fVar1;
  }
  if ((DAT_0050040c == 1) && (DAT_004da1f8 == 0)) {
    fVar1 = FUN_0042f270(param_1,param_2);
    return fVar1;
  }
  if (DAT_004da1f8 < 1) {
LAB_0042f3c2:
    fVar1 = (float10)(param_1 - DAT_00535bc8) / (float10)_DAT_004fba00;
    fVar2 = (float10)(param_2 - DAT_004f3858) / (float10)_DAT_00535558;
    fVar1 = (float10)_DAT_004cc920 -
            (SQRT(fVar2 * fVar2 + fVar1 * (float10)(double)fVar1) / (float10)DAT_004f4b00) *
            (float10)_DAT_004cc920;
    if (DAT_004f8b78 == 0) {
      fVar1 = fVar1 + fVar1;
    }
    else {
      fVar1 = -fVar1;
    }
    if (DAT_004f4510 == 1) {
      fVar1 = fVar1 + fVar1;
    }
    if (fVar1 < (float10)_DAT_004cc658) {
      fVar1 = (float10)_DAT_004cc658;
    }
    if ((float10)_DAT_004cc490 < fVar1) {
      fVar1 = (float10)_DAT_004cc490;
    }
    return fVar1;
  }
  if (DAT_005364b0 == 0) {
    iVar3 = 0;
  }
  else {
    if (DAT_005364b0 != 1) goto LAB_0042f3c2;
    iVar3 = 1;
  }
  fVar1 = FUN_0047d5f0(param_3,param_1,param_2,0,iVar3);
  return fVar1;
}

