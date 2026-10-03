
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00465e90(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  
  iVar1 = (int)(longlong)*(double *)(&DAT_004f6af8 + param_4 * 8);
  iVar2 = (int)(longlong)*(double *)(&DAT_004f6c10 + param_4 * 8);
  iVar3 = iVar2;
  iVar5 = iVar1;
  if (param_3 == 1) {
    iVar3 = (&DAT_004f1740)[*(int *)(&DAT_00535740 + param_4 * 4)] + iVar2;
    iVar5 = iVar1 - (&DAT_004f85c8)[*(int *)(&DAT_00535740 + param_4 * 4)];
  }
  if (param_3 == 2) {
    iVar5 = iVar1 - (int)(&DAT_004f85c8)[*(int *)(&DAT_00535740 + param_4 * 4)] / 3;
    iVar3 = (int)(&DAT_004f1740)[*(int *)(&DAT_00535740 + param_4 * 4)] / 3 + iVar2;
  }
  iVar1 = *(int *)(&DAT_004fbb90 + param_4 * 4);
  param_1 = param_1 - iVar5;
  iVar3 = iVar3 - param_2;
  DAT_00523184 = (undefined4)(longlong)SQRT((float10)(param_1 * param_1 + iVar3 * iVar3));
  DAT_004f4b40 = FUN_00427ee0(param_1,iVar3);
  fVar6 = ABS((float10)_DAT_004f7f80 - (float10)iVar1 * (float10)_DAT_004cc568);
  if ((float10)_DAT_004cc740 < fVar6) {
    fVar6 = ABS(fVar6 - (float10)_DAT_004cc748);
  }
  uVar4 = DAT_004f4b40 - iVar1 >> 0x1f;
  iVar2 = (DAT_004f4b40 - iVar1 ^ uVar4) - uVar4;
  iVar3 = -1;
  param_4 = -1;
  if (iVar2 < 0xb4) {
    if (iVar1 < DAT_004f4b40) {
      iVar3 = 1;
      param_4 = 1;
    }
    if (iVar2 < 0xb4) goto LAB_00465fd6;
  }
  if (DAT_004f4b40 <= iVar1) {
    iVar3 = 1;
    param_4 = 1;
  }
  if (0xb4 < iVar2) {
    iVar2 = 0x168 - iVar2;
  }
LAB_00465fd6:
  DAT_00535ff4 = iVar3 * iVar2;
  return fVar6 * (float10)param_4;
}

