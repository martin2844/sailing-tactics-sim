
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_00481350(int param_1,int param_2,int param_3,int param_4)

{
  float10 fVar1;
  
  fVar1 = (float10)(param_4 - param_2) * (float10)(param_4 - param_2) +
          (float10)(param_1 - param_3) * (float10)(param_1 - param_3);
  if (fVar1 <= (float10)_DAT_004cc658) {
    return (float10)_DAT_004cc658;
  }
  if (fVar1 < (float10)_DAT_004cccc8) {
    return (SQRT(fVar1) / (float10)DAT_004da208) * (float10)_DAT_004cc488;
  }
  return (float10)((int)(50000 / (longlong)DAT_004da208) * 100);
}

