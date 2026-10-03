
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong __cdecl FUN_0044da90(int param_1,int param_2)

{
  double dVar1;
  double dVar2;
  float10 fVar3;
  float10 fVar4;
  
  fVar3 = (float10)fsin((float10)*(int *)(&DAT_004aa5b0 + param_1 * 4) * (float10)_DAT_00484d40);
  dVar1 = (double)((float10)*(double *)(&DAT_004a49e8 + param_1 * 8) -
                  fVar3 * (float10)_DAT_004853f0);
  fVar3 = (float10)fcos((float10)*(int *)(&DAT_004aa5b0 + param_1 * 4) * (float10)_DAT_00484d40);
  dVar2 = (double)((float10)*(double *)(&DAT_004a4ae0 + param_1 * 8) -
                  fVar3 * (float10)_DAT_004853f8);
  fVar3 = FUN_00428ab0(param_2,dVar1,dVar2);
  fVar4 = FUN_00428ab0(param_1,dVar1,dVar2);
  return (longlong)((float10)(double)fVar3 - fVar4);
}

