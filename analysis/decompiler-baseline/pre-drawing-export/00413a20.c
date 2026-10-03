
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00413a20(double param_1,double param_2,double param_3,double param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9)

{
  int iVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  undefined4 local_18;
  undefined4 uStack_14;
  
  iVar11 = param_6;
  iVar10 = DAT_004ac904;
  iVar9 = DAT_00491188;
  local_18 = 0;
  uStack_14 = 0x3ff00000;
  if ((DAT_00491188 == 5) || (DAT_00491188 == 7)) {
    local_18 = 0x33333333;
    uStack_14 = 0x3fe33333;
  }
  if (DAT_00491188 == 1) {
    local_18 = 0xcccccccd;
    uStack_14 = 0x3ff4cccc;
  }
  iVar2 = *(int *)(&DAT_004aa730 + param_6 * 4);
  param_6 = iVar2;
  if (param_9 < 0) {
    param_6 = -iVar2;
  }
  dVar3 = (double)CONCAT44(uStack_14,local_18) * param_3;
  dVar4 = param_2 - dVar3;
  iVar1 = param_5 * 8;
  bVar14 = DAT_004ac904 == 1;
  (&DAT_004ac310)[param_5] = param_1;
  dVar5 = param_1 - DAT_004ac310;
  (&DAT_004a3a38)[param_5] = dVar4;
  (&DAT_004a79f8)[param_5] = dVar5;
  if ((bVar14) && (*(int *)(&DAT_004a8aa8 + iVar11 * 4) < 0x50)) {
    param_3 = 1.0;
  }
  else {
    param_3 = 0.2;
  }
  dVar6 = (double)param_6;
  dVar3 = param_2 + dVar3;
  dVar5 = param_3 * (double)CONCAT44(uStack_14,local_18) * param_4 * dVar6 + param_1;
  (&DAT_004ac318)[param_5] = dVar5;
  dVar8 = dVar5 - DAT_004ac310;
  *(double *)(&DAT_004ac320 + iVar1) = dVar5;
  dVar5 = dVar5 - DAT_004ac310;
  *(double *)(&DAT_004ac328 + iVar1) = param_1;
  dVar7 = param_1 - DAT_004ac310;
  (&DAT_004a3a40)[param_5] = dVar4;
  (&DAT_004a7a00)[param_5] = dVar8;
  *(double *)(&DAT_004a3a48 + iVar1) = dVar3;
  *(double *)(&DAT_004a7a08 + iVar1) = dVar5;
  *(double *)(&DAT_004a3a50 + iVar1) = dVar3;
  *(double *)(&DAT_004a7a10 + iVar1) = dVar7;
  if ((param_7 < 2) || (iVar9 != 7)) {
    dVar5 = (double)CONCAT44(uStack_14,local_18) * param_4 * dVar6 * _DAT_00484da8;
  }
  else {
    dVar5 = (double)CONCAT44(uStack_14,local_18) * param_4 * dVar6 * _DAT_00484ec0;
  }
  if ((param_8 <= DAT_004a7354) && (1 < iVar11)) {
    return;
  }
  if (((iVar10 == 1) && (*(int *)(&DAT_004a8aa8 + iVar11 * 4) < 0x50)) &&
     (uVar13 = iVar11 + (int)(longlong)_DAT_004abef0, uVar12 = (int)uVar13 >> 0x1f,
     ((uVar13 ^ uVar12) - uVar12 & 3 ^ uVar12) == uVar12)) {
    if (iVar2 == -1) {
      dVar5 = dVar5 * _DAT_00484ec8;
    }
    else {
      dVar5 = dVar5 * _DAT_00484ed0;
    }
  }
  dVar5 = param_1 - dVar5;
  *(double *)(&DAT_004a3a58 + param_5 * 2) = dVar4;
  *(double *)(&DAT_004ac330 + iVar1) = dVar5;
  dVar4 = dVar5 - DAT_004ac310;
  *(double *)(&DAT_004ac338 + iVar1) = dVar5;
  dVar5 = dVar5 - DAT_004ac310;
  *(double *)(&DAT_004a3a60 + iVar1) = dVar3;
  *(double *)(&DAT_004a7a18 + iVar1) = dVar4;
  *(double *)(&DAT_004a7a20 + iVar1) = dVar5;
  return;
}

