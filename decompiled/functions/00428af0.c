
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong __cdecl FUN_00428af0(int param_1,int param_2,int param_3)

{
  double dVar1;
  double dVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  double local_10;
  
  dVar1 = *(double *)(&DAT_004a49e8 + param_1 * 8);
  dVar2 = *(double *)(&DAT_004a4ae0 + param_1 * 8);
  if (param_2 == 1) {
    fVar3 = (float10)fcos((float10)*(int *)(&DAT_004ac018 + param_1 * 4) * (float10)_DAT_00484d40);
    fVar4 = (float10)fsin((float10)*(int *)(&DAT_004ac018 + param_1 * 4) * (float10)_DAT_00484d40);
    fVar3 = (float10)dVar1 -
            fVar3 * (float10)*(int *)(&DAT_004aa730 + param_1 * 4) * (float10)_DAT_00485188;
    fVar4 = (float10)dVar2 -
            fVar4 * (float10)*(int *)(&DAT_004aa730 + param_1 * 4) * (float10)_DAT_00485188;
  }
  else {
    fVar3 = (float10)fsin((float10)*(int *)(&DAT_004aa5b0 + param_1 * 4) * (float10)_DAT_00484d40);
    fVar4 = (float10)fcos((float10)*(int *)(&DAT_004aa5b0 + param_1 * 4) * (float10)_DAT_00484d40);
    fVar3 = (float10)dVar1 - fVar3 * (float10)_DAT_00485188;
    fVar4 = (float10)dVar2 - fVar4 * (float10)_DAT_00485190;
  }
  fVar5 = (fVar4 - (float10)dVar2) * (fVar4 - (float10)dVar2) +
          (fVar3 - (float10)dVar1) * (float10)(double)(fVar3 - (float10)dVar1);
  if (fVar5 <= (float10)_DAT_00484e18) {
    local_10 = 100.0;
  }
  else {
    local_10 = (double)SQRT(fVar5);
  }
  fVar3 = (fVar4 - (float10)*(double *)(&DAT_004a4ae0 + param_3 * 8)) *
          (float10)(double)(fVar4 - (float10)*(double *)(&DAT_004a4ae0 + param_3 * 8)) +
          (fVar3 - (float10)*(double *)(&DAT_004a49e8 + param_3 * 8)) *
          (float10)(double)(fVar3 - (float10)*(double *)(&DAT_004a49e8 + param_3 * 8));
  if ((float10)_DAT_00484e18 < fVar3) {
    return (longlong)((float10)local_10 - SQRT(fVar3));
  }
  return (longlong)(local_10 - _DAT_00485020);
}

