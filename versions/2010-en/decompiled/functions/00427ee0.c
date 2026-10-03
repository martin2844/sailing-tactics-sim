
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00427ee0(int param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  
  fVar2 = (float10)fpatan((float10)param_1,(float10)param_2);
  _DAT_004f7f80 = (double)fVar2;
  iVar1 = FUN_0041bc20((int)(longlong)((float10)_DAT_004cc4f8 - fVar2 * (float10)_DAT_004cc910));
  return iVar1;
}

