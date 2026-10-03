
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00411000(CDC *param_1,int param_2,undefined *param_3,uint param_4,uint param_5,int param_6,
            int param_7)

{
  double *pdVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  double *pdVar7;
  uint uVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  double dVar12;
  undefined8 local_5d0;
  double *local_5bc;
  int local_5b8;
  int local_5b4;
  int local_5b0;
  int local_5a4;
  undefined8 local_5a0;
  int local_594;
  double local_590;
  double local_580;
  int local_574;
  double local_570;
  double local_568;
  undefined8 uStack_560;
  undefined8 uStack_488;
  undefined8 uStack_428;
  undefined8 local_398;
  undefined8 local_2c0;
  undefined8 local_260;
  double adStack_1d0 [27];
  double adStack_f8 [12];
  double adStack_98 [18];
  
  if ((DAT_004ac98c == 1) && ((int)param_3 < DAT_00491148 * 2)) {
    return;
  }
  uVar4 = (uint)(param_4 == 0);
  if ((param_5 == 1) && (param_4 == 1)) {
    DAT_004a67b0 = param_2;
    DAT_004a6840 = param_3;
  }
  if ((param_5 == 2) && (param_4 == 2)) {
    _DAT_004a67b4 = param_2;
    _DAT_004a6844 = param_3;
  }
  if ((DAT_00491188 != 1) || (local_574 = 4, DAT_004ac904 != 0)) {
    local_574 = 3;
  }
  iVar2 = *(int *)(&DAT_004a4e88 + param_5 * 4);
  local_5a0 = _DAT_00484dd8 -
              ((double)((int)param_3 - param_7) * _DAT_00484dd0) / (double)(param_6 - param_7);
  if ((iVar2 == 2) && (DAT_004ac994 != 1)) {
    local_5a0 = local_5a0 * _DAT_00484de0;
  }
  if (500 < DAT_004ac980) {
    local_5a0 = local_5a0 * _DAT_00484de8;
  }
  if ((iVar2 == 3) &&
     (local_5a0 = _DAT_00484db0 -
                  ((double)((int)param_3 - param_7) * _DAT_00484df0) / (double)(param_6 - param_7),
     0 < DAT_004ac980)) {
    local_5a0 = local_5a0 * _DAT_00484cd8;
  }
  if ((uVar4 == 1) && (DAT_004ac980 != 0x6d)) {
    local_5a0 = local_5a0 * _DAT_00484dc0;
  }
  iVar9 = (param_6 + param_7 * 2) / 3;
  if (iVar2 == 1) {
    DAT_004ac930 = 0;
    DAT_004a7354 = iVar9;
    DAT_004a7358 = iVar9;
    DAT_004ac13c = iVar9;
  }
  if (iVar2 == 2) {
    DAT_004ac930 = 0;
    DAT_004a7354 = iVar9;
    DAT_004a7358 = (param_7 + param_6) / 2;
    DAT_004ac13c = iVar9;
  }
  if (iVar2 == 3) {
    DAT_004a7358 = 0;
    DAT_004ac13c = 0;
    DAT_004a7354 = 0;
    DAT_004ac930 = 1;
  }
  if (param_4 == 1) {
    FUN_004304d0();
  }
  uVar5 = (int)param_4 >> 0x1f;
  iVar2 = DAT_004a5b7c;
  if (((param_4 ^ uVar5) - uVar5 & 1 ^ uVar5) != uVar5) {
    iVar2 = -DAT_004a5b7c;
  }
  if ((int)param_3 < DAT_004ac13c) {
    iVar2 = iVar2 / 2;
  }
  _DAT_004a3ef0 = (double)(iVar2 / 2);
  if (DAT_00491188 == 1) {
    local_5b4 = 0x2c;
  }
  if (((DAT_00491188 == 2) || (DAT_00491188 == 3)) || (DAT_00491188 == 9)) {
    local_5b4 = 0x32;
  }
  if (DAT_00491188 == 10) {
    local_5b4 = 0x38;
  }
  if ((3 < DAT_00491188) && (DAT_00491188 < 8)) {
    local_5b4 = 0x38;
  }
  if ((DAT_00491188 == 8) || ((int)param_3 <= DAT_004ac13c)) {
    local_5b4 = 0x26;
  }
  if ((((int)param_3 <= DAT_004a7354) && (DAT_00491188 != 8)) && (1 < (int)param_4)) {
    local_5b4 = local_5b4 + -2;
  }
  if (((int)param_3 <= DAT_004ac13c) && (*(int *)(&DAT_004abb70 + param_4 * 4) < 1)) {
    local_5b4 = 0x1a;
  }
  if ((param_4 != 1) && (DAT_004ac928 == 1)) {
    local_5b4 = 0x26;
  }
  if (((param_4 != 1) && (DAT_004ac928 == 1)) && (*(int *)(&DAT_004abb70 + param_4 * 4) < 1)) {
    local_5b4 = 0x1a;
  }
  if (uVar4 == 1) {
    local_5b4 = 0x10;
  }
  if ((DAT_00491188 < 8) || (uVar4 == 1)) {
    dVar12 = (double)DAT_004a72d0 * local_5a0;
    local_5d0 = dVar12 * _DAT_00484d50;
  }
  else {
    dVar12 = (double)DAT_004a72d0 * local_5a0;
    local_5d0 = dVar12 * _DAT_00484df8;
  }
  if (DAT_004ac904 == 1) {
    local_5d0 = dVar12 * _DAT_00484df8;
  }
  if (DAT_004ac900 == 1) {
    local_5d0 = dVar12 * _DAT_00484e00;
  }
  iVar9 = *(int *)(&DAT_004ac018 + param_4 * 4) - *(int *)(&DAT_004a6830 + param_5 * 4);
  FUN_00413cb0(iVar9);
  if (((*(int *)(&DAT_004a4608 + param_5 * 4) == 0) && (*(int *)(&DAT_004a4e88 + param_5 * 4) < 3))
     && (param_4 != param_5)) {
    iVar6 = (int)(longlong)((double)(param_2 - DAT_004a763c / 2) * _DAT_004ab0c8);
    iVar6 = (int)((ulonglong)((longlong)iVar6 * 0x77777777) >> 0x20) - iVar6;
    iVar9 = iVar9 + ((iVar6 >> 5) - (iVar6 >> 0x1f));
  }
  uVar5 = FUN_00413cb0(iVar9);
  if (0xb4 < (int)uVar5) {
    uVar5 = uVar5 - 0x168;
  }
  if ((param_5 == 1) && (param_4 == 1)) {
    DAT_004a475c = uVar5;
  }
  if ((param_5 == 2) && (param_4 == 2)) {
    DAT_004a4770 = uVar5;
  }
  local_5b8 = 0;
  iVar9 = *(int *)(&DAT_004a77e8 + param_4 * 4) + 5;
  local_580 = _DAT_00484e10 - (double)DAT_004a72d0 * local_5a0 * _DAT_00484e08;
  if (0x28 < iVar9) {
    iVar9 = 0x28;
  }
  iVar6 = iVar9 + 2;
  if (*(int *)(&DAT_004aa730 + param_4 * 4) == 1) {
    if (((int)uVar5 < 0xb4 - iVar6) && (-1 < (int)uVar5)) {
      local_5b8 = 1;
    }
    if ((-iVar6 < (int)uVar5) && ((int)uVar5 < 0)) {
      local_5b8 = 1;
    }
  }
  if (*(int *)(&DAT_004aa730 + param_4 * 4) == -1) {
    if (-1 < (int)uVar5) {
      if ((int)uVar5 < iVar6) {
        local_5b8 = 1;
      }
      if (-1 < (int)uVar5) goto LAB_004114ac;
    }
    if (iVar9 + -0xb2 < (int)uVar5) {
      local_5b8 = 1;
    }
  }
LAB_004114ac:
  _DAT_004a3a48 = (double)(int)param_3;
  _DAT_004ac320 = (double)param_2;
  if ((DAT_004ac900 == 1) && (uVar4 == 0)) {
    FUN_00413100(local_580,local_5d0);
  }
  else {
    FUN_00412f60(local_580,local_5d0);
  }
  if (uVar4 == 0) {
    FUN_00414010(local_5d0,param_4,local_574,0xf,uVar5,local_5a0);
  }
  if ((DAT_004ac13c < (int)param_3) && (uVar4 == 0)) {
    FUN_00413370(local_5d0,param_4,(int)param_3);
  }
  if (local_5b4 < 0x1a) {
    local_594 = local_5b4;
  }
  else {
    local_594 = 0x1a;
  }
  iVar9 = 0;
  if (-1 < local_594) {
    pdVar7 = (double *)&DAT_004a8688;
    do {
      fVar10 = -((float10)(double)(&DAT_004a3a38)[iVar9] - (float10)_DAT_004a3a48);
      dVar12 = (double)((float10)(double)(&DAT_004ac310)[iVar9] - (float10)_DAT_004ac320);
      fVar11 = (float10)fpatan((float10)(double)(&DAT_004ac310)[iVar9] - (float10)_DAT_004ac320,
                               fVar10);
      *pdVar7 = (double)fVar10;
      fVar10 = fVar10 * fVar10 + (float10)dVar12 * (float10)dVar12;
      if (fVar10 <= (float10)_DAT_00484e18) {
        *(undefined4 *)(&uStack_560 + iVar9) = 0;
        *(undefined4 *)(&local_398 + iVar9) = 0;
        *(undefined4 *)((int)&uStack_560 + iVar9 * 8 + 4) = 0;
        *(undefined4 *)((int)&local_398 + iVar9 * 8 + 4) = 0;
      }
      else {
        (&local_398)[iVar9] = (double)fVar11;
        (&uStack_560)[iVar9] = SQRT((double)fVar10);
      }
      iVar9 = iVar9 + 1;
      pdVar7 = pdVar7 + 1;
    } while (iVar9 <= local_594);
  }
  if (*(int *)(&DAT_004abb70 + param_4 * 4) == 1) {
    pdVar7 = (double *)&DAT_004a8760;
    iVar9 = 0;
    do {
      fVar10 = (float10)*(double *)((int)&DAT_004ac3e8 + iVar9) - (float10)_DAT_004ac320;
      fVar11 = -((float10)*(double *)((int)&DAT_004a3b10 + iVar9) - (float10)_DAT_004a3a48);
      dVar12 = (double)fVar10;
      fVar10 = (float10)fpatan(fVar10,fVar11);
      *pdVar7 = (double)fVar11;
      fVar11 = fVar11 * fVar11 + (float10)dVar12 * (float10)dVar12;
      if (fVar11 <= (float10)_DAT_00484e18) {
        *(undefined4 *)((int)&uStack_488 + iVar9) = 0;
        *(undefined4 *)((int)&local_2c0 + iVar9) = 0;
        *(undefined4 *)((int)&uStack_488 + iVar9 + 4) = 0;
        *(undefined4 *)((int)&local_2c0 + iVar9 + 4) = 0;
      }
      else {
        *(double *)((int)&local_2c0 + iVar9) = (double)fVar10;
        *(double *)((int)&uStack_488 + iVar9) = SQRT((double)fVar11);
      }
      iVar9 = iVar9 + 8;
      pdVar7 = pdVar7 + 1;
    } while (iVar9 < 0x59);
  }
  if ((DAT_004ac13c < (int)param_3) && (0x26 < local_5b4)) {
    pdVar7 = (double *)&DAT_004a87c0;
    iVar6 = 0;
    iVar9 = local_5b4 + -0x26;
    do {
      fVar10 = (float10)*(double *)((int)&DAT_004ac448 + iVar6) - (float10)_DAT_004ac320;
      fVar11 = -((float10)*(double *)((int)&DAT_004a3b70 + iVar6) - (float10)_DAT_004a3a48);
      dVar12 = (double)fVar10;
      fVar10 = (float10)fpatan(fVar10,fVar11);
      *pdVar7 = (double)fVar11;
      fVar11 = fVar11 * fVar11 + (float10)dVar12 * (float10)dVar12;
      if (fVar11 <= (float10)_DAT_00484e18) {
        *(undefined4 *)((int)&uStack_428 + iVar6) = 0;
        *(undefined4 *)((int)&local_260 + iVar6) = 0;
        *(undefined4 *)((int)&uStack_428 + iVar6 + 4) = 0;
        *(undefined4 *)((int)&local_260 + iVar6 + 4) = 0;
      }
      else {
        *(double *)((int)&local_260 + iVar6) = (double)fVar10;
        *(double *)((int)&uStack_428 + iVar6) = SQRT((double)fVar11);
      }
      iVar6 = iVar6 + 8;
      pdVar7 = pdVar7 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  local_590 = 0.3;
  if (2 < *(int *)(&DAT_004a4e88 + param_5 * 4)) {
    local_590 = 0.6;
  }
  local_5a4 = FUN_00413cb0(*(int *)(&DAT_004a6ec8 + param_4 * 4));
  if (DAT_004ac904 == 1) {
    local_5a4 = 0;
  }
  if (-1 < local_594) {
    local_570 = (double)iVar2;
    local_580 = (double)(int)uVar5 * _DAT_00484e20;
    fVar10 = (float10)fsin((float10)local_5a4 * (float10)_DAT_00484d40);
    local_5bc = (double *)&local_398;
    local_568 = (double)fVar10;
    iVar9 = 0;
    do {
      dVar12 = *local_5bc;
      adStack_1d0[iVar9] =
           (double)*(int *)(&DAT_004aa730 + param_4 * 4) *
           (double)(&DAT_004a79f8)[iVar9] * local_568 * _DAT_00484dc0 -
           (double)(&DAT_004a8688)[iVar9] * local_570 * _DAT_00484e28;
      dVar12 = FUN_00413cd0(dVar12 - local_580);
      fVar10 = (float10)fsin((float10)dVar12);
      fVar11 = (float10)fcos((float10)dVar12);
      (&DAT_004aa1a0)[iVar9] =
           (int)(longlong)(fVar10 * (float10)(double)(&uStack_560)[iVar9]) + param_2;
      local_5bc = local_5bc + 1;
      iVar6 = iVar9 + 1;
      (&DAT_004aa2a0)[iVar9] =
           (int)param_3 -
           (int)(longlong)
                (fVar11 * (float10)local_590 * (float10)(double)(&uStack_560)[iVar9] +
                (float10)adStack_1d0[iVar9]);
      iVar9 = iVar6;
    } while (iVar6 <= local_594);
  }
  if (*(int *)(&DAT_004abb70 + param_4 * 4) == 1) {
    local_570 = (double)iVar2;
    local_580 = (double)(int)uVar5 * _DAT_00484e20;
    fVar10 = (float10)fsin((float10)local_5a4 * (float10)_DAT_00484d40);
    local_5bc = (double *)&local_2c0;
    iVar9 = 0;
    local_594 = 0;
    local_568 = (double)fVar10;
    do {
      dVar12 = *local_5bc;
      *(double *)((int)adStack_f8 + iVar9) =
           (double)*(int *)(&DAT_004aa730 + param_4 * 4) *
           *(double *)((int)&DAT_004a7ad0 + iVar9) * local_568 * _DAT_00484dc0 -
           *(double *)((int)&DAT_004a8760 + iVar9) * local_570 * _DAT_00484e28;
      dVar12 = FUN_00413cd0(dVar12 - local_580);
      fVar10 = (float10)fsin((float10)dVar12);
      fVar11 = (float10)fcos((float10)dVar12);
      *(int *)((int)&DAT_004aa20c + local_594) =
           (int)(longlong)(fVar10 * (float10)*(double *)((int)&uStack_488 + iVar9)) + param_2;
      pdVar7 = (double *)((int)&uStack_488 + iVar9);
      pdVar1 = (double *)((int)adStack_f8 + iVar9);
      iVar9 = iVar9 + 8;
      local_5bc = local_5bc + 1;
      *(int *)((int)&DAT_004aa30c + local_594) =
           (int)param_3 -
           (int)(longlong)(fVar11 * (float10)local_590 * (float10)*pdVar7 + (float10)*pdVar1);
      local_594 = local_594 + 4;
    } while (iVar9 < 0x59);
  }
  if ((DAT_004ac13c < (int)param_3) && (0x26 < local_5b4)) {
    local_570 = (double)iVar2;
    local_580 = (double)(int)uVar5 * _DAT_00484e20;
    fVar10 = (float10)fsin((float10)local_5a4 * (float10)_DAT_00484d40);
    local_5b0 = local_5b4 + -0x26;
    local_5bc = (double *)&local_260;
    iVar2 = 0;
    local_5a4 = 0;
    local_568 = (double)fVar10;
    do {
      dVar12 = *local_5bc;
      *(double *)((int)adStack_98 + iVar2) =
           (double)*(int *)(&DAT_004aa730 + param_4 * 4) *
           *(double *)((int)&DAT_004a7b30 + iVar2) * local_568 * _DAT_00484dc0 -
           *(double *)((int)&DAT_004a87c0 + iVar2) * local_570 * _DAT_00484e28;
      dVar12 = FUN_00413cd0(dVar12 - local_580);
      fVar10 = (float10)fsin((float10)dVar12);
      fVar11 = (float10)fcos((float10)dVar12);
      *(int *)(&DAT_004aa23c + local_5a4) =
           (int)(longlong)(fVar10 * (float10)*(double *)((int)&uStack_428 + iVar2)) + param_2;
      pdVar7 = (double *)((int)&uStack_428 + iVar2);
      pdVar1 = (double *)((int)adStack_98 + iVar2);
      iVar2 = iVar2 + 8;
      local_5bc = local_5bc + 1;
      *(int *)(&DAT_004aa33c + local_5a4) =
           (int)param_3 -
           (int)(longlong)(fVar11 * (float10)local_590 * (float10)*pdVar7 + (float10)*pdVar1);
      local_5a4 = local_5a4 + 4;
      local_5b0 = local_5b0 + -1;
    } while (local_5b0 != 0);
  }
  iVar2 = (int)(longlong)(local_5d0 * _DAT_00484e30);
  if (uVar4 == 1) {
    iVar2 = (iVar2 * 3) / 2;
  }
  if (DAT_004ac904 == 1) {
    iVar2 = iVar2 / 2;
  }
  DAT_004a437c = DAT_004aa1a0;
  DAT_004a678c = iVar2 + DAT_004aa2a0;
  DAT_004a4384 = (DAT_004aa1e0 + DAT_004aa1a0) / 2;
  iVar9 = (DAT_004aa2e0 + DAT_004aa2a0) / 2;
  DAT_004a4380 = (DAT_004aa1a0 + DAT_004aa1b8) / 2;
  iVar6 = (DAT_004aa2a0 + DAT_004aa2b8) / 2;
  if (DAT_004ac914 == 1) {
    iVar9 = DAT_004aa1a0 + DAT_004aa1e0 * 3;
    DAT_004a4384 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
    iVar9 = DAT_004aa2a0 + DAT_004aa2e0 * 3;
    iVar9 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
    iVar6 = DAT_004aa1a0 + DAT_004aa1b8 * 3;
    DAT_004a4380 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;
    iVar6 = DAT_004aa2a0 + DAT_004aa2b8 * 3;
    iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;
  }
  DAT_004a6788 = iVar9 + iVar2;
  DAT_004a6784 = iVar6 + iVar2;
  iVar2 = (int)(longlong)(local_5d0 * _DAT_00484e38);
  if (uVar4 == 1) {
    iVar2 = (iVar2 * 3) / 2;
  }
  if (((DAT_00491188 == 4) || (DAT_00491188 == 8)) || (param_4 == 0)) {
    DAT_004ac838 = DAT_004aa1b4;
    iVar9 = DAT_004aa2b4;
  }
  else {
    DAT_004ac838 = (DAT_004aa1b0 + DAT_004aa1b4 * 2) / 3;
    iVar9 = (DAT_004aa2b0 + DAT_004aa2b4 * 2) / 3;
  }
  if (DAT_004ac904 == 1) {
    DAT_004ac838 = DAT_004aa1b0;
    iVar9 = DAT_004aa2b0;
  }
  DAT_004a3f88 = iVar9 + iVar2;
  if ((((int)param_4 <= DAT_00491140) && (0x1a < *(int *)(&DAT_004a7060 + param_4 * 4))) &&
     ((0 < (int)param_4 && (DAT_004ac900 == 0)))) {
    FUN_00419ca0(param_1,param_4,(int)local_5d0,local_5d0._4_4_,DAT_004aa1cc,DAT_004aa2cc);
  }
  if (0 < DAT_004ac994) {
    FUN_00419ca0(param_1,param_4,(int)local_5d0,local_5d0._4_4_,DAT_004aa1cc,DAT_004aa2cc);
  }
  if ((((int)param_4 <= DAT_00491140) || (0 < DAT_004ac994)) &&
     ((0x1e < *(int *)(&DAT_004a7060 + param_4 * 4) &&
      (((0 < (int)param_4 && (DAT_004ac900 == 1)) && (uVar4 == 0)))))) {
    iVar9 = (DAT_004aa1b8 + DAT_004aa1bc) / 2;
    iVar2 = (int)(longlong)(local_5d0 * _DAT_00484e40);
    iVar6 = (DAT_004aa2b8 + DAT_004aa2bc) / 2 - iVar2;
    iVar3 = (DAT_004aa1e0 + DAT_004aa1dc) / 2;
    iVar2 = (DAT_004aa2e0 + DAT_004aa2dc) / 2 - iVar2;
    if ((*(int *)(&DAT_004aa730 + param_4 * 4) == 1) &&
       (FUN_00419ca0(param_1,param_4,(int)local_5d0,local_5d0._4_4_,iVar3,iVar2),
       *(int *)(&DAT_004a6ec8 + param_4 * 4) < 8)) {
      FUN_00419ca0(param_1,param_4,(int)local_5d0,local_5d0._4_4_,iVar9,iVar6);
    }
    if (*(int *)(&DAT_004aa730 + param_4 * 4) == -1) {
      if (*(int *)(&DAT_004a6ec8 + param_4 * 4) < 8) {
        FUN_00419ca0(param_1,param_4,(int)local_5d0,local_5d0._4_4_,iVar3,iVar2);
      }
      FUN_00419ca0(param_1,param_4,(int)local_5d0,local_5d0._4_4_,iVar9,iVar6);
    }
  }
  if ((DAT_004ac900 == 0) || (uVar4 == 1)) {
    if ((0 < (int)uVar5) || ((int)uVar5 < -0xa9)) {
      FUN_00415de0((int *)param_1,(int)local_5d0,(int)local_5d0._4_4_,uVar4);
    }
    if (((int)uVar5 < 0) || (0xa9 < (int)uVar5)) {
      FUN_00416070((int *)param_1,(int)local_5d0,(int)local_5d0._4_4_,uVar4);
    }
    if ((-0x5a < (int)uVar5) && ((int)uVar5 < 0x5a)) {
      FUN_00416300((int)param_1,local_5d0,param_4,uVar4,(int)param_3);
    }
  }
  if ((DAT_004ac900 == 1) && (uVar4 == 0)) {
    if ((0 < (int)uVar5) || ((int)uVar5 < -0xa9)) {
      FUN_00417d30(param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4);
      FUN_00418a10(param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4);
    }
    if (((int)uVar5 < 0) || (0xa9 < (int)uVar5)) {
      FUN_00418890(param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4);
      FUN_00417fb0(param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4);
    }
    if ((-0x5b < (int)uVar5) && ((int)uVar5 < 0x5b)) {
      FUN_00418120((int *)param_1,(int)local_5d0,local_5d0._4_4_);
    }
  }
  if (((0x1e < *(int *)(&DAT_004a7060 + param_4 * 4)) && (uVar4 == 0)) && (DAT_004ac900 == 0)) {
    if (((int)uVar5 < 0xf) || (0xaa < (int)uVar5)) {
      FUN_00419b40(param_1,param_4,(int)local_5d0,local_5d0._4_4_,1,(int)param_3,uVar5);
    }
    if ((-0xf < (int)uVar5) || ((int)uVar5 < -0xaa)) {
      FUN_00419b40(param_1,param_4,(int)local_5d0,local_5d0._4_4_,0,(int)param_3,uVar5);
    }
  }
  if ((DAT_004ac900 == 1) && (uVar4 == 0)) {
    FUN_00417be0((int *)param_1);
    FUN_00418580(param_1,(int)local_5d0,local_5d0._4_4_,local_5a0);
  }
  else {
    FUN_00412810(param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4);
  }
  uVar8 = (int)uVar5 >> 0x1f;
  if (((DAT_00491188 == 7) && (uVar4 == 0)) && ((int)((uVar5 ^ uVar8) - uVar8) < 0x5b)) {
    FUN_00419db0(param_1,param_4,(int)local_5d0,(int)local_5d0._4_4_,uVar5,0,(int)param_3);
  }
  if ((uVar4 == 1) || (param_4 == 0)) {
    iVar2 = (uVar5 ^ uVar8) - uVar8;
    if (iVar2 < 0x5b) {
      FUN_00419db0(param_1,param_4,(int)local_5d0,(int)local_5d0._4_4_,1,uVar5,(int)param_3);
    }
    _DAT_004a7bc8 = 0;
    iVar9 = (int)(longlong)local_5d0;
    FUN_00417570(param_1,DAT_004aa1a8,DAT_004aa2a8 + iVar9 * -3,0,uVar5,(int)param_3,uVar4);
    FUN_00417570(param_1,DAT_004aa1a8,DAT_004aa2a8 + iVar9 * -2,0,uVar5,(int)param_3,2);
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
    FUN_004706bd(param_1,(int *)&local_580,DAT_004aa1a8,DAT_004aa2a8);
    CDC::LineTo(param_1,DAT_004aa1a8,DAT_004aa2a8 + iVar9 * -3);
    if (0x5a < iVar2) {
      FUN_00419db0(param_1,param_4,(int)local_5d0,(int)local_5d0._4_4_,1,uVar5,(int)param_3);
    }
  }
  else {
    if ((DAT_00491188 == 7) && (0x5a < (int)((uVar5 ^ uVar8) - uVar8))) {
      FUN_00419db0(param_1,param_4,(int)local_5d0,(int)local_5d0._4_4_,uVar5,uVar4,(int)param_3);
    }
    if (DAT_0049114c < 1) {
      FUN_004194b0(param_1,(int)local_5d0,local_5d0._4_4_,param_4,(int)param_3);
    }
    if (DAT_004ac904 == 1) {
      FUN_00416d10(param_1,param_4,local_5d0,local_574,0xf,param_3,(undefined *)local_5a0,
                   local_5a0._4_4_,uVar5,uVar4,local_5b8);
    }
    if (local_5b8 == 1) {
      if (((*(int *)(&DAT_004abb70 + param_4 * 4) == 1) && (2 < DAT_00491188)) &&
         (DAT_00491188 != 9)) {
        FUN_0041a5d0(param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4,(int)param_3,1);
      }
      iVar2 = *(int *)(&DAT_004abb70 + param_4 * 4);
      if (iVar2 == 1) {
        if (DAT_00491188 == 2) {
          FUN_00416ad0((int *)param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4,param_3,1);
        }
        iVar2 = *(int *)(&DAT_004abb70 + param_4 * 4);
      }
      if ((iVar2 < 1) && (1 < DAT_00491188)) {
        FUN_00416ad0((int *)param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4,param_3,1);
      }
      FUN_00414d00(param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4,(int)(undefined *)local_5a0,
                   local_5a0._4_4_);
      FUN_00416d10(param_1,param_4,local_5d0,local_574,0xf,param_3,(undefined *)local_5a0,
                   local_5a0._4_4_,uVar5,uVar4,1);
      if (DAT_00491188 == 8) {
        FUN_004198f0(param_1,(int)local_5d0,local_5d0._4_4_,param_4,1,uVar5,(int)param_3);
        FUN_004198f0(param_1,(int)local_5d0,local_5d0._4_4_,param_4,-1,uVar5,(int)param_3);
      }
      if (((int)uVar5 < 0x5a) && (-0x5a < (int)uVar5)) {
        if ((3 < DAT_00491188) && (DAT_00491188 < 9)) {
          FUN_00418b80(param_1,3,param_4,(int)local_5d0,(int)local_5d0._4_4_,(int)param_3,1,uVar5);
        }
        if (1 < DAT_00491188) {
          FUN_00418b80(param_1,2,param_4,(int)local_5d0,(int)local_5d0._4_4_,(int)param_3,1,uVar5);
        }
        FUN_00418b80(param_1,1,param_4,(int)local_5d0,(int)local_5d0._4_4_,(int)param_3,1,uVar5);
        if ((DAT_0049114c == 1) && (DAT_00491188 < 8)) {
          FUN_004198f0(param_1,(int)local_5d0,local_5d0._4_4_,param_4,0,uVar5,(int)param_3);
          return;
        }
      }
      else {
        if ((DAT_0049114c == 1) && (DAT_00491188 < 8)) {
          FUN_004198f0(param_1,(int)local_5d0,local_5d0._4_4_,param_4,0,uVar5,(int)param_3);
        }
        FUN_00418b80(param_1,1,param_4,(int)local_5d0,(int)local_5d0._4_4_,(int)param_3,1,uVar5);
        if (1 < DAT_00491188) {
          FUN_00418b80(param_1,2,param_4,(int)local_5d0,(int)local_5d0._4_4_,(int)param_3,1,uVar5);
        }
        if ((3 < DAT_00491188) && (DAT_00491188 < 9)) {
          FUN_00418b80(param_1,3,param_4,(int)local_5d0,(int)local_5d0._4_4_,(int)param_3,1,uVar5);
          return;
        }
      }
    }
    else {
      if (DAT_00491188 == 8) {
        FUN_004198f0(param_1,(int)local_5d0,local_5d0._4_4_,param_4,1,uVar5,(int)param_3);
        FUN_004198f0(param_1,(int)local_5d0,local_5d0._4_4_,param_4,-1,uVar5,(int)param_3);
      }
      if (((int)uVar5 < 0x5a) && (-0x5a < (int)uVar5)) {
        if ((3 < DAT_00491188) && (DAT_00491188 < 9)) {
          FUN_00418b80(param_1,3,param_4,(int)local_5d0,(int)local_5d0._4_4_,(int)param_3,local_5b8,
                       uVar5);
        }
        if (1 < DAT_00491188) {
          FUN_00418b80(param_1,2,param_4,(int)local_5d0,(int)local_5d0._4_4_,(int)param_3,local_5b8,
                       uVar5);
        }
        FUN_00418b80(param_1,1,param_4,(int)local_5d0,(int)local_5d0._4_4_,(int)param_3,local_5b8,
                     uVar5);
        if ((DAT_0049114c == 1) && (DAT_00491188 < 8)) {
          FUN_004198f0(param_1,(int)local_5d0,local_5d0._4_4_,param_4,0,uVar5,(int)param_3);
        }
      }
      else {
        if ((DAT_0049114c == 1) && (DAT_00491188 < 8)) {
          FUN_004198f0(param_1,(int)local_5d0,local_5d0._4_4_,param_4,0,uVar5,(int)param_3);
        }
        FUN_00418b80(param_1,1,param_4,(int)local_5d0,(int)local_5d0._4_4_,(int)param_3,local_5b8,
                     uVar5);
        if (1 < DAT_00491188) {
          FUN_00418b80(param_1,2,param_4,(int)local_5d0,(int)local_5d0._4_4_,(int)param_3,local_5b8,
                       uVar5);
        }
        if ((3 < DAT_00491188) && (DAT_00491188 < 9)) {
          FUN_00418b80(param_1,3,param_4,(int)local_5d0,(int)local_5d0._4_4_,(int)param_3,local_5b8,
                       uVar5);
        }
      }
      FUN_00414d00(param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4,(int)(undefined *)local_5a0,
                   local_5a0._4_4_);
      FUN_00416d10(param_1,param_4,local_5d0,local_574,0xf,param_3,(undefined *)local_5a0,
                   local_5a0._4_4_,uVar5,uVar4,local_5b8);
      if (((*(int *)(&DAT_004abb70 + param_4 * 4) == 1) && (2 < DAT_00491188)) &&
         (DAT_00491188 != 9)) {
        FUN_0041a5d0(param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4,(int)param_3,local_5b8);
      }
      iVar2 = *(int *)(&DAT_004abb70 + param_4 * 4);
      if (iVar2 == 1) {
        if (DAT_00491188 == 2) {
          FUN_00416ad0((int *)param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4,param_3,local_5b8)
          ;
        }
        iVar2 = *(int *)(&DAT_004abb70 + param_4 * 4);
      }
      if ((iVar2 < 1) && (1 < DAT_00491188)) {
        FUN_00416ad0((int *)param_1,(int)local_5d0,(int)local_5d0._4_4_,param_4,param_3,local_5b8);
        return;
      }
    }
  }
  return;
}

