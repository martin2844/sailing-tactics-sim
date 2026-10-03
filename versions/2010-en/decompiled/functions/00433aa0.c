
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00433aa0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  int local_8 [2];
  
  FUN_0041f130(param_1,param_4);
  if (((DAT_00536450 != 1) || (param_4 == param_5)) || (*(int *)(&DAT_0050f6d0 + param_5 * 4) < 9))
  {
    iVar2 = FUN_0041bc20((*(int *)(&DAT_00535740 + param_4 * 4) -
                         *(int *)(&DAT_00535740 + param_5 * 4)) + 0xb4);
    iVar2 = FUN_0041bc20(iVar2);
    if ((&DAT_00525a78)[param_5] == 0) {
      iVar2 = FUN_0041bc20((iVar2 - *(int *)(&DAT_004fbb90 + param_5 * 4)) +
                           *(int *)(&DAT_00535740 + param_5 * 4));
    }
    if ((&DAT_00525a78)[param_5] == 2) {
      iVar2 = FUN_0041bc20((iVar2 - (&DAT_00522b90)[param_5]) +
                           *(int *)(&DAT_00535740 + param_5 * 4));
    }
    if (2 < param_6) {
      iVar2 = *(int *)(&DAT_00535740 + param_4 * 4) + 0xb4;
    }
    iVar2 = FUN_0041bc20(iVar2);
    FUN_004b4d9d(param_1,local_8,param_2,param_3);
    fVar3 = (float10)fcos((float10)iVar2 * (float10)_DAT_004cc568);
    fVar4 = (float10)fsin((float10)iVar2 * (float10)_DAT_004cc568);
    CDC::LineTo(param_1,param_2 - (int)(longlong)(fVar4 * (float10)_DAT_004cc588),
                param_3 - (int)(longlong)(fVar3 * (float10)_DAT_004cc580));
    if (param_4 == 1) {
      FUN_004b4d9d(param_1,local_8,param_2 + -4,param_3);
      CDC::LineTo(param_1,param_2 + 4,param_3);
      FUN_004b4d9d(param_1,local_8,param_2,param_3 + -4);
      CDC::LineTo(param_1,param_2,param_3 + 4);
    }
    if ((param_4 == 2) && (DAT_004da140 == 2)) {
      iVar2 = param_3 + -3;
      iVar1 = param_2 + -3;
      FUN_004b4d9d(param_1,local_8,iVar1,iVar2);
      CDC::LineTo(param_1,param_2 + 3,iVar2);
      CDC::LineTo(param_1,param_2 + 3,param_3 + 3);
      CDC::LineTo(param_1,iVar1,param_3 + 3);
      CDC::LineTo(param_1,iVar1,iVar2);
    }
  }
  return;
}

