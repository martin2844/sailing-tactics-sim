
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_0041bb10(int param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  
  fVar2 = (float10)fpatan((float10)param_1,(float10)param_2);
  iVar1 = FUN_00413cb0((int)(longlong)((float10)_DAT_00484da8 - fVar2 * (float10)_DAT_004850b8));
  return iVar1;
}

