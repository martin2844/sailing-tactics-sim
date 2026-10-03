
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_004060a0(int param_1,int param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)(param_1 - DAT_00491148) * (float10)_DAT_00484cc8;
  if (*(int *)(&DAT_004a4e88 + param_2 * 4) == 1) {
    fVar1 = fVar1 * (float10)_DAT_00484cd0;
  }
  if (DAT_004a763c < 900) {
    fVar1 = fVar1 * (float10)_DAT_00484cd8;
  }
  return fVar1 - (float10)_DAT_00484ce0;
}

