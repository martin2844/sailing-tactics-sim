
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00420b20(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  
  iVar1 = FUN_00413cb0(param_4);
  fVar2 = (float10)fsin((float10)iVar1 * (float10)_DAT_00484d40);
  fVar3 = (float10)fcos((float10)iVar1 * (float10)_DAT_00484d40);
  DAT_004a70e8 = (int)(longlong)(fVar2 * (float10)param_3) + param_1;
  DAT_004aa81c = param_2 - (int)(longlong)(fVar3 * (float10)param_3);
  return;
}

