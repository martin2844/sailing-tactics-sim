
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048f650(int *param_1,double param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8)

{
  int iVar1;
  
  if ((DAT_00535884 < param_5) && ((param_3 < 2 || (DAT_005363e0 != 1)))) {
    iVar1 = (int)(longlong)
                 ((_DAT_004cc650 - (double)DAT_004faa48 * _DAT_004cc9b8) * param_2 * _DAT_004cc660);
    if (*(int *)(&DAT_00522ff0 + param_3 * 4) == 1) {
      if (-1 < param_8) {
LAB_0048f6be:
        FUN_0048f720(param_1,param_6,param_7,2,iVar1,param_3);
        FUN_0048f720(param_1,param_4,param_5,1,iVar1,param_3);
        return;
      }
    }
    else if (param_8 < 0) goto LAB_0048f6be;
    FUN_0048f720(param_1,param_4,param_5,1,iVar1,param_3);
    FUN_0048f720(param_1,param_6,param_7,2,iVar1,param_3);
  }
  return;
}

