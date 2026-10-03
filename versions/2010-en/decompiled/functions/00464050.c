
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong __cdecl FUN_00464050(int param_1,int param_2)

{
  double dVar1;
  double dVar2;
  float10 fVar3;
  float10 fVar4;
  
  fVar3 = (float10)fsin((float10)(int)(&DAT_00522b90)[param_1] * (float10)_DAT_004cc568);
  dVar1 = (double)((float10)*(double *)(&DAT_004f6af8 + param_1 * 8) -
                  fVar3 * (float10)_DAT_004ccc98);
  fVar3 = (float10)fcos((float10)(int)(&DAT_00522b90)[param_1] * (float10)_DAT_004cc568);
  dVar2 = (double)((float10)*(double *)(&DAT_004f6c10 + param_1 * 8) -
                  fVar3 * (float10)_DAT_004ccca0);
  fVar3 = FUN_00439e80(param_2,dVar1,dVar2);
  fVar4 = FUN_00439e80(param_1,dVar1,dVar2);
  return (longlong)((float10)(double)fVar3 - fVar4);
}

