
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_0043ec20(double param_1,double param_2,int param_3,int param_4)

{
  double dVar1;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  double dVar2;
  
  dVar1 = param_1;
  dVar2 = param_1;
  if (param_3 < 2) {
    dVar1 = *(double *)(&DAT_004f6c10 + param_4 * 8);
    dVar2 = *(double *)(&DAT_004f6af8 + param_4 * 8);
  }
  fVar6 = (float10)dVar2;
  fVar4 = (float10)dVar1;
  if (1 < param_3) {
    fVar6 = (float10)DAT_00536410;
    fVar4 = (float10)DAT_00536414;
  }
  fVar5 = (float10)param_1;
  fVar4 = fVar4 - (float10)param_2;
  param_1 = (double)(fVar5 - fVar6);
  _DAT_004fbb88 = (double)SQRT(fVar4 * fVar4 + (fVar5 - fVar6) * (float10)param_1);
  if (param_1 == _DAT_004cc658) {
    if (fVar4 <= (float10)_DAT_004cc658) {
      fVar6 = (float10)_DAT_004cc740;
    }
    else {
      fVar6 = (float10)_DAT_004cc658;
    }
  }
  else {
    fVar6 = (float10)fpatan((float10)param_1,fVar4);
  }
  DAT_004f4b40 = (int)(longlong)(fVar6 * (float10)_DAT_004cc3e8);
  if (param_3 == -1) {
    param_1 = (double)(fVar6 - (float10)*(int *)(&DAT_004fbb90 + param_4 * 4) *
                               (float10)_DAT_004cc568);
  }
  if ((param_3 == 1) || (param_3 == 2)) {
    iVar3 = (&DAT_00525a78)[param_4];
    if (iVar3 == 0) {
      param_1 = (double)(fVar6 - (float10)*(int *)(&DAT_004fbb90 + param_4 * 4) *
                                 (float10)_DAT_004cc568);
    }
    if (iVar3 == 1) {
      param_1 = (double)(fVar6 - (float10)*(int *)(&DAT_00535740 + param_4 * 4) *
                                 (float10)_DAT_004cc568);
    }
    if (iVar3 == 2) {
      param_1 = (double)(fVar6 - (float10)(int)(&DAT_00522b90)[param_4] * (float10)_DAT_004cc568);
    }
  }
  if ((param_3 != 0) && (param_3 < 3)) {
    return (float10)param_1;
  }
  return (float10)(double)fVar6;
}

