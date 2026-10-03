
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0041b970(double param_1,double param_2,double param_3,double param_4,int param_5,int param_6,
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
  int iVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  undefined4 local_18;
  undefined4 uStack_14;
  
  iVar12 = param_6;
  iVar11 = DAT_005363c0;
  iVar10 = DAT_005363bc;
  iVar9 = DAT_004da190;
  local_18 = 0;
  uStack_14 = 0x3ff00000;
  if (((DAT_004da190 == 5) || (DAT_004da190 == 7)) || ((1 < DAT_005363c0 && (DAT_00523198 == 2)))) {
    local_18 = 0x33333333;
    uStack_14 = 0x3fe33333;
  }
  if (DAT_004da190 == 1) {
    local_18 = 0xcccccccd;
    uStack_14 = 0x3ff4cccc;
  }
  iVar2 = *(int *)(&DAT_00522ff0 + param_6 * 4);
  param_6 = iVar2;
  if (param_9 < 0) {
    param_6 = -iVar2;
  }
  dVar3 = (double)CONCAT44(uStack_14,local_18) * param_3;
  dVar4 = param_2 - dVar3;
  iVar1 = param_5 * 8;
  bVar15 = DAT_005363bc == 1;
  (&DAT_00535c68)[param_5] = param_1;
  dVar5 = param_1 - DAT_00535c68;
  (&DAT_004f3a38)[param_5] = dVar4;
  (&DAT_004fea68)[param_5] = dVar5;
  if ((bVar15) && (*(int *)(&DAT_00512278 + iVar12 * 4) < 0x50)) {
    param_3 = 1.0;
  }
  else {
    param_3 = 0.2;
  }
  dVar6 = (double)param_6;
  dVar3 = param_2 + dVar3;
  dVar5 = param_3 * (double)CONCAT44(uStack_14,local_18) * param_4 * dVar6 + param_1;
  (&DAT_00535c70)[param_5] = dVar5;
  dVar8 = dVar5 - DAT_00535c68;
  *(double *)(&DAT_00535c78 + iVar1) = dVar5;
  dVar5 = dVar5 - DAT_00535c68;
  *(double *)(&DAT_00535c80 + iVar1) = param_1;
  dVar7 = param_1 - DAT_00535c68;
  (&DAT_004f3a40)[param_5] = dVar4;
  (&DAT_004fea70)[param_5] = dVar8;
  *(double *)(&DAT_004f3a48 + iVar1) = dVar3;
  *(double *)(&DAT_004fea78 + iVar1) = dVar5;
  *(double *)(&DAT_004f3a50 + iVar1) = dVar3;
  *(double *)(&DAT_004fea80 + iVar1) = dVar7;
  if ((param_7 < 2) || ((iVar9 != 7 && ((iVar11 < 2 || (DAT_00523198 != 2)))))) {
    dVar5 = (double)CONCAT44(uStack_14,local_18) * param_4 * dVar6 * _DAT_004cc4f8;
  }
  else {
    dVar5 = (double)CONCAT44(uStack_14,local_18) * param_4 * dVar6 * _DAT_004cc5d8;
  }
  if ((param_8 <= DAT_004fe33c) && (1 < iVar12)) {
    return;
  }
  if (((iVar10 == 1) && (*(int *)(&DAT_00512278 + iVar12 * 4) < 0x50)) &&
     (uVar14 = iVar12 + (int)(longlong)_DAT_005355f8, uVar13 = (int)uVar14 >> 0x1f,
     ((uVar14 ^ uVar13) - uVar13 & 3 ^ uVar13) == uVar13)) {
    if (iVar2 == -1) {
      dVar5 = dVar5 * _DAT_004cc738;
    }
    else {
      dVar5 = dVar5 * _DAT_004cc468;
    }
  }
  dVar5 = param_1 - dVar5;
  *(double *)(&DAT_004f3a58 + param_5 * 2) = dVar4;
  *(double *)(&DAT_00535c88 + iVar1) = dVar5;
  dVar4 = dVar5 - DAT_00535c68;
  *(double *)(&DAT_00535c90 + iVar1) = dVar5;
  dVar5 = dVar5 - DAT_00535c68;
  *(double *)(&DAT_004f3a60 + iVar1) = dVar3;
  *(double *)(&DAT_004fea88 + iVar1) = dVar4;
  *(double *)(&DAT_004fea90 + iVar1) = dVar5;
  return;
}

