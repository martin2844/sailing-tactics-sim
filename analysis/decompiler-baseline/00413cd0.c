
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_00413cd0(double param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)param_1;
  if ((float10)_DAT_00484ed8 < fVar1) {
    fVar1 = fVar1 - (float10)_DAT_00484ee0;
  }
  if (fVar1 < (float10)_DAT_00484ee8) {
    fVar1 = fVar1 - (float10)_DAT_00484ef0;
  }
  return fVar1;
}

