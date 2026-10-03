
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041e9c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  int local_10;
  
  iVar1 = FUN_00415a20(2000);
  iVar2 = FUN_00415a20(0x8c);
  iVar2 = FUN_00413cb0(iVar2 + -0x46 + DAT_004ac840);
  if (DAT_00491140 == 1) {
    local_10 = (int)(longlong)_DAT_004a49f0;
    iVar3 = (int)(longlong)_DAT_004a4ae8;
  }
  else {
    local_10 = ((int)(longlong)DAT_004a49f8 + (int)(longlong)_DAT_004a49f0) / 2;
    iVar3 = ((int)(longlong)DAT_004a4af0 + (int)(longlong)_DAT_004a4ae8) / 2;
  }
  fVar5 = (float10)_DAT_00484d40;
  fVar4 = (float10)fsin((float10)iVar2 * fVar5);
  *(double *)(&DAT_004abd88 + param_1 * 8) =
       (double)(fVar4 * (float10)(iVar1 + 500) + (float10)local_10);
  fVar5 = (float10)fcos((float10)iVar2 * fVar5);
  *(double *)(&DAT_004a4728 + param_1 * 8) =
       (double)((float10)iVar3 - fVar5 * (float10)(iVar1 + 500));
  iVar1 = FUN_00415a20(2);
  *(int *)(&DAT_004a4e98 + param_1 * 4) = iVar1 + 2 + DAT_004a888c * 2;
  iVar1 = FUN_00415a20(300);
  *(int *)(&DAT_004aaa20 + param_1 * 4) = (iVar1 + 0x96) * DAT_0049115c + DAT_004a5b80;
  iVar1 = FUN_00415a20(300);
  *(int *)(&DAT_004a4ec0 + param_1 * 4) = iVar1 + 0x96;
  iVar1 = FUN_00415a20(DAT_004aa390 / 2);
  *(int *)(&DAT_004a4150 + param_1 * 4) = iVar1 + DAT_004aa390 / 2;
  iVar1 = FUN_00415a20(0x10);
  iVar1 = (iVar1 + -8) / (DAT_004a888c + 1);
  if (DAT_004ac998 == 0) {
    *(int *)(&DAT_004ac0a0 + param_1 * 4) =
         iVar1 + DAT_004ac840 + *(int *)(&DAT_004a4e98 + param_1 * 4);
    return;
  }
  *(int *)(&DAT_004ac0a0 + param_1 * 4) =
       (iVar1 + DAT_004ac840) - *(int *)(&DAT_004a4e98 + param_1 * 4);
  return;
}

