
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_0042c400(double param_1,double param_2,int param_3,int param_4)

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
    dVar1 = *(double *)(&DAT_004a4ae0 + param_4 * 8);
    dVar2 = *(double *)(&DAT_004a49e8 + param_4 * 8);
  }
  fVar6 = (float10)dVar2;
  fVar4 = (float10)dVar1;
  if (1 < param_3) {
    fVar6 = (float10)DAT_004aa594;
    fVar4 = (float10)DAT_004aa59c;
  }
  fVar5 = (float10)param_1;
  fVar4 = fVar4 - (float10)param_2;
  param_1 = (double)(fVar5 - fVar6);
  _DAT_004a6828 = (double)SQRT(fVar4 * fVar4 + (fVar5 - fVar6) * (float10)param_1);
  if (param_1 == _DAT_00484e18) {
    if (fVar4 <= (float10)_DAT_00484e18) {
      fVar6 = (float10)_DAT_00484ed8;
    }
    else {
      fVar6 = (float10)_DAT_00484e18;
    }
  }
  else {
    fVar6 = (float10)fpatan((float10)param_1,fVar4);
  }
  DAT_004a4758 = (int)(longlong)(fVar6 * (float10)_DAT_00484d78);
  if (param_3 == -1) {
    param_1 = (double)(fVar6 - (float10)*(int *)(&DAT_004a6830 + param_4 * 4) *
                               (float10)_DAT_00484d40);
  }
  if ((param_3 == 1) || (param_3 == 2)) {
    iVar3 = (&DAT_004ab160)[param_4];
    if (iVar3 == 0) {
      param_1 = (double)(fVar6 - (float10)*(int *)(&DAT_004a6830 + param_4 * 4) *
                                 (float10)_DAT_00484d40);
    }
    if (iVar3 == 1) {
      param_1 = (double)(fVar6 - (float10)*(int *)(&DAT_004ac018 + param_4 * 4) *
                                 (float10)_DAT_00484d40);
    }
    if (iVar3 == 2) {
      param_1 = (double)(fVar6 - (float10)*(int *)(&DAT_004aa5b0 + param_4 * 4) *
                                 (float10)_DAT_00484d40);
    }
  }
  if ((param_3 != 0) && (param_3 < 3)) {
    return (float10)param_1;
  }
  return (float10)(double)fVar6;
}

