
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043eb00(double param_1,int param_2,double param_3,double param_4,int param_5)

{
  double dVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  
  dVar1 = _DAT_004ccb70;
  if (param_1 < _DAT_004cc4f8) {
    dVar1 = _DAT_004cc5a0;
  }
  dVar1 = _DAT_005259d0 * dVar1;
  fVar2 = FUN_0043ec20(param_3,param_4,-1,param_5);
  DAT_00535ff4 = FUN_0041e3a0((int)(longlong)(fVar2 * (float10)_DAT_004cc3e8));
  fVar2 = FUN_0041bc40((double)fVar2);
  fVar2 = FUN_0041bc40((double)fVar2);
  if (_DAT_004ccb78 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
    _DAT_004fbb88 = 0;
    _DAT_004fbb8c = 0x40977000;
  }
  fVar3 = (float10)fcos(fVar2);
  fVar4 = (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) * (float10)_DAT_004ccb80;
  fVar2 = (float10)fsin(fVar2);
  (&DAT_00523660)[param_2] =
       (int)(longlong)((float10)DAT_004f4b48 - fVar3 * (float10)dVar1 * fVar4 * (float10)param_1);
  (&DAT_004fed58)[param_2] = (int)(longlong)((float10)DAT_004f40a8 + fVar2 * (float10)dVar1 * fVar4)
  ;
  return;
}

