
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_004662d0(double param_1,double param_2,double param_3,double param_4)

{
  float10 fVar1;
  
  fVar1 = ((float10)param_4 - (float10)param_2) * ((float10)param_4 - (float10)param_2) +
          ((float10)param_1 - (float10)param_3) *
          (float10)(double)((float10)param_1 - (float10)param_3);
  if (fVar1 <= (float10)_DAT_004cc658) {
    return (float10)_DAT_004cc658;
  }
  if (fVar1 < (float10)_DAT_004cccc8) {
    return SQRT(fVar1);
  }
  return (float10)_DAT_004cccc0;
}

