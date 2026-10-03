
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_00420c40(int param_1,int param_2,int param_3)

{
  float10 fVar1;
  float10 fVar2;
  
  if (1 < DAT_004a4958) {
    fVar1 = FUN_00420d10(param_1,param_2,param_3);
    return fVar1;
  }
  fVar1 = (float10)(param_1 - DAT_004ac284) / (float10)_DAT_004a6470;
  fVar2 = (float10)(param_2 - DAT_004a3a08) / (float10)_DAT_004abe60;
  fVar1 = (float10)_DAT_004850d8 -
          (SQRT(fVar2 * fVar2 + fVar1 * (float10)(double)fVar1) / (float10)DAT_004abae8) *
          (float10)_DAT_004850d8;
  if (DAT_004a5a4c == 0) {
    fVar1 = fVar1 + fVar1;
  }
  else {
    fVar1 = -fVar1;
  }
  if (DAT_004a4378 == 1) {
    fVar1 = fVar1 + fVar1;
  }
  if (0 < param_3) {
    *(double *)(&DAT_004a7f28 + param_3 * 8) = (double)fVar1;
  }
  return fVar1;
}

