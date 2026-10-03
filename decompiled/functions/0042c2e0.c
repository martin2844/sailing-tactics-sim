
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0042c2e0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,double param_6,int param_7)

{
  double dVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  double dVar5;
  
  dVar1 = _DAT_004ab0c8 * _DAT_004851f0;
  fVar2 = FUN_0042c400((double)CONCAT44(param_5,param_4),param_6,-1,param_7);
  DAT_004ac66c = FUN_00415dc0((int)(longlong)(fVar2 * (float10)_DAT_00484d78));
  dVar5 = FUN_00413cd0((double)fVar2);
  dVar5 = FUN_00413cd0(dVar5);
  if (_DAT_00485260 < (double)CONCAT44(_DAT_004a682c,_DAT_004a6828)) {
    _DAT_004a6828 = 0;
    _DAT_004a682c = 0x40977000;
  }
  fVar2 = (float10)fcos((float10)dVar5);
  fVar3 = (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828) * (float10)_DAT_00485268;
  fVar4 = (float10)fsin((float10)dVar5);
  (&DAT_004aaa48)[param_3] =
       (int)(longlong)
            ((float10)DAT_004a4760 -
            fVar2 * (float10)dVar1 * fVar3 * (float10)(double)CONCAT44(param_2,param_1));
  (&DAT_004a7c48)[param_3] = (int)(longlong)((float10)DAT_004a3fa0 + fVar4 * (float10)dVar1 * fVar3)
  ;
  return;
}

