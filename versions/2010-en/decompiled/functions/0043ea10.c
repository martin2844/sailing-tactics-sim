
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_0043ea10(double param_1,double param_2,int param_3)

{
  double dVar1;
  double dVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar3 = (float10)*(int *)(&DAT_004fbb90 + param_3 * 4) * (float10)_DAT_004cc568;
  fVar4 = (float10)fsin(fVar3);
  fVar5 = (float10)fcos(fVar3);
  dVar1 = _DAT_004ccb20;
  dVar2 = _DAT_004ccae0;
  if (DAT_005364c8 == 1) {
    dVar1 = _DAT_004ccb58;
    dVar2 = _DAT_004cc960;
  }
  fVar6 = (float10)param_1 -
          ((float10)*(double *)(&DAT_004f6af8 + param_3 * 8) - fVar4 * (float10)dVar2);
  fVar4 = ((float10)*(double *)(&DAT_004f6c10 + param_3 * 8) - fVar5 * (float10)dVar1) -
          (float10)param_2;
  fVar5 = fVar4 * fVar4 + fVar6 * fVar6;
  if (fVar5 <= (float10)_DAT_004cc658) {
    _DAT_004fbb88 = 0.0;
  }
  else {
    _DAT_004fbb88 = (double)SQRT(fVar5);
  }
  fVar4 = (float10)fpatan(fVar6,fVar4);
  fVar3 = FUN_0041bc40((double)(fVar4 - fVar3));
  DAT_00535ff4 = FUN_0041e3a0((int)(longlong)(fVar3 * (float10)_DAT_004cc3e8));
  return (float10)(double)fVar3;
}

