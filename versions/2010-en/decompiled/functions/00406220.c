
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00406220(int param_1,int param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)(param_1 - DAT_004da148) * (float10)_DAT_004cc3f0;
  if (*(int *)(&DAT_004f71c0 + param_2 * 4) == 1) {
    fVar1 = fVar1 * (float10)_DAT_004cc3f8;
  }
  if (DAT_004fe624 < 900) {
    fVar1 = fVar1 * (float10)_DAT_004cc400;
  }
  return fVar1 - (float10)_DAT_004cc408;
}

