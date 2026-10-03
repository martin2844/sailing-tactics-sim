
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_0042c210(double param_1,double param_2,int param_3)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  double dVar5;
  
  fVar1 = (float10)*(int *)(&DAT_004a6830 + param_3 * 4) * (float10)_DAT_00484d40;
  fVar2 = (float10)fcos(fVar1);
  fVar3 = (float10)fsin(fVar1);
  fVar2 = ((float10)*(double *)(&DAT_004a4ae0 + param_3 * 8) - fVar2 * (float10)_DAT_00485258) -
          (float10)param_2;
  fVar3 = (float10)param_1 -
          ((float10)*(double *)(&DAT_004a49e8 + param_3 * 8) - fVar3 * (float10)_DAT_00484cc0);
  fVar4 = fVar2 * fVar2 + fVar3 * fVar3;
  if (fVar4 <= (float10)_DAT_00484e18) {
    _DAT_004a6828 = 0.0;
  }
  else {
    _DAT_004a6828 = (double)SQRT(fVar4);
  }
  fVar2 = (float10)fpatan(fVar3,fVar2);
  dVar5 = FUN_00413cd0((double)(fVar2 - fVar1));
  DAT_004ac66c = FUN_00415dc0((int)(longlong)(dVar5 * _DAT_00484d78));
  return (float10)dVar5;
}

