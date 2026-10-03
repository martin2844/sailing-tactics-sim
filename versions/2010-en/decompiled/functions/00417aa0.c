
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00417aa0(int *param_1,int param_2,int param_3,uint param_4,uint param_5,int param_6,
                 int param_7)

{
  double *pdVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  double *pdVar10;
  float10 fVar11;
  float10 fVar12;
  double local_5c0;
  int local_5b4;
  double *local_5b0;
  int local_5ac;
  int local_5a8;
  int local_5a0;
  int local_59c;
  double local_598;
  int local_590;
  int local_58c;
  double local_588;
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
  
  if ((param_6 < param_3) && (DAT_00536458 == 0)) {
    return 0;
  }
  if (DAT_004fe624 / 10 + DAT_004fe624 < param_2) {
    return -(DAT_004fe624 >> 0x1f);
  }
  iVar7 = (int)((ulonglong)((longlong)DAT_004fe624 * -0x66666667) >> 0x20);
  if (param_2 < (iVar7 >> 2) - (iVar7 >> 0x1f)) {
    return (uint)((longlong)DAT_004fe624 * -0x66666667);
  }
  if ((DAT_00536450 == 1) && (param_3 < (int)(DAT_004da148 * 2))) {
    return DAT_004da148;
  }
  if (((int)param_4 < 1) || (local_5b4 = 0, param_4 == 0x1f)) {
    local_5b4 = 1;
  }
  if ((param_5 == 1) && (param_4 == 1)) {
    DAT_004fba18 = param_2;
    DAT_004fbba0 = param_3;
  }
  if ((param_5 == 2) && (param_4 == 2)) {
    _DAT_004fba1c = param_2;
    _DAT_004fbba4 = param_3;
  }
  if ((DAT_004da190 != 1) || (local_58c = 4, DAT_005363bc != 0)) {
    local_58c = 3;
  }
  if (DAT_0053652c == 1) {
    local_58c = 3;
  }
  iVar7 = *(int *)(&DAT_004f71c0 + param_5 * 4);
  local_598 = _DAT_004cc618 -
              ((double)(param_3 - param_7) * _DAT_004cc610) / (double)(param_6 - param_7);
  if ((iVar7 == 2) && (DAT_00536458 != 1)) {
    local_598 = local_598 * _DAT_004cc620;
  }
  if (500 < DAT_00536444) {
    local_598 = local_598 * _DAT_004cc508;
  }
  if ((iVar7 == 3) &&
     (local_598 = _DAT_004cc5f0 -
                  ((double)(param_3 - param_7) * _DAT_004cc628) / (double)(param_6 - param_7),
     0 < DAT_00536444)) {
    local_598 = local_598 * _DAT_004cc400;
  }
  if ((local_5b4 == 1) && (DAT_00536444 != 0x6d)) {
    local_598 = local_598 * _DAT_004cc600;
  }
  if (param_4 == 0x1f) {
    local_598 = local_598 * _DAT_004cc538;
  }
  if ((((0x44c < DAT_004fe624) && (DAT_00536444 == 0)) && (DAT_00536458 == 0)) && (1 < iVar7)) {
    local_598 = local_598 * _DAT_004cc630;
  }
  iVar9 = (param_6 + param_7 * 2) / 3;
  if (iVar7 == 1) {
    DAT_005363e8 = 0;
    DAT_004fe33c = iVar9;
    DAT_004fe340 = iVar9;
    DAT_00535884 = iVar9;
  }
  if (iVar7 == 2) {
    DAT_005363e8 = 0;
    DAT_004fe33c = iVar9;
    DAT_004fe340 = (param_7 + param_6) / 2;
    DAT_00535884 = iVar9;
  }
  if (iVar7 == 3) {
    DAT_005363e8 = 1;
    DAT_00535884 = 0;
    DAT_004fe340 = 0;
    DAT_004fe33c = 0;
  }
  if (param_4 == 1) {
    FUN_004432b0();
  }
  uVar8 = (int)param_4 >> 0x1f;
  local_574 = DAT_004f8ccc;
  if (((param_4 ^ uVar8) - uVar8 & 1 ^ uVar8) != uVar8) {
    local_574 = -DAT_004f8ccc;
  }
  if (param_3 < DAT_00535884) {
    local_574 = local_574 / 2;
  }
  _DAT_004f3f50 = (double)(local_574 / 2);
  if (DAT_004da190 == 1) {
    local_5a0 = 0x2c;
  }
  if (((DAT_004da190 == 2) || (DAT_004da190 == 3)) || (DAT_004da190 == 9)) {
    local_5a0 = 0x32;
  }
  if (DAT_004da190 == 10) {
    local_5a0 = 0x38;
  }
  if ((3 < (int)DAT_004da190) && ((int)DAT_004da190 < 8)) {
    local_5a0 = 0x38;
  }
  if ((DAT_004da190 == 8) || (param_3 <= DAT_00535884)) {
    local_5a0 = 0x26;
  }
  if (((param_3 <= DAT_004fe33c) && (DAT_004da190 != 8)) && (1 < (int)param_4)) {
    local_5a0 = local_5a0 + -2;
  }
  if ((param_3 <= DAT_00535884) && (*(int *)(&DAT_005350d8 + param_4 * 4) < 1)) {
    local_5a0 = 0x1a;
  }
  if ((param_4 != 1) && (DAT_005363e0 == 1)) {
    local_5a0 = 0x26;
  }
  if (((param_4 != 1) && (DAT_005363e0 == 1)) && (*(int *)(&DAT_005350d8 + param_4 * 4) < 1)) {
    local_5a0 = 0x1a;
  }
  if (local_5b4 == 1) {
    local_5a0 = 0x10;
  }
  if ((DAT_004da190 == 8) && (local_5b4 == 0)) {
    dVar2 = (double)DAT_004fe2a8 * local_598;
    local_5c0 = dVar2 * _DAT_004cc528;
  }
  else {
    dVar2 = (double)DAT_004fe2a8 * local_598;
    local_5c0 = dVar2 * _DAT_004cc578;
  }
  if ((DAT_00536528 == 1) && (local_5b4 == 0)) {
    local_5c0 = dVar2 * _DAT_004cc528;
  }
  if ((DAT_0053652c == 1) && (local_5b4 == 0)) {
    local_5c0 = dVar2 * _DAT_004cc440;
  }
  if ((DAT_005364bc == 1) && (local_5b4 == 0)) {
    local_5c0 = dVar2 * _DAT_004cc638;
  }
  if ((DAT_00536530 == 1) && (local_5b4 == 0)) {
    local_5c0 = dVar2 * _DAT_004cc640;
  }
  if (local_5b4 == 1) {
    local_5c0 = dVar2 * _DAT_004cc578;
  }
  if (DAT_005363bc == 1) {
    local_5c0 = dVar2 * _DAT_004cc528;
  }
  if (DAT_005363b8 == 1) {
    local_5c0 = dVar2 * _DAT_004cc638;
  }
  iVar7 = *(int *)(&DAT_00535740 + param_4 * 4) - *(int *)(&DAT_004fbb90 + param_5 * 4);
  FUN_0041bc20(iVar7);
  if (((*(int *)(&DAT_004f49a0 + param_5 * 4) == 0) && (*(int *)(&DAT_004f71c0 + param_5 * 4) < 3))
     && (param_4 != param_5)) {
    iVar9 = (int)(longlong)((double)(param_2 - DAT_004fe624 / 2) * _DAT_005259d0);
    iVar9 = (int)((ulonglong)((longlong)iVar9 * 0x15f15f15) >> 0x20) - iVar9;
    iVar7 = iVar7 + ((iVar9 >> 5) - (iVar9 >> 0x1f));
  }
  uVar8 = FUN_0041bc20(iVar7);
  if (0xb4 < (int)uVar8) {
    uVar8 = uVar8 - 0x168;
  }
  if ((param_5 == 1) && (param_4 == 1)) {
    DAT_004f4b44 = uVar8;
  }
  if ((param_5 == 2) && (param_4 == 2)) {
    DAT_004f4bb8 = uVar8;
  }
  local_5ac = 0;
  iVar7 = *(int *)(&DAT_004fe818 + param_4 * 4) + 5;
  local_580 = _DAT_004cc650 - (double)DAT_004fe2a8 * local_598 * _DAT_004cc648;
  if (0x28 < iVar7) {
    iVar7 = 0x28;
  }
  if (DAT_005364c0 == 1) {
    if (*(int *)(&DAT_005350d8 + param_4 * 4) == 1) {
      iVar7 = iVar7 / 5;
    }
    if (*(int *)(&DAT_005350d8 + param_4 * 4) == 0) {
      iVar7 = iVar7 / 2;
    }
  }
  if ((DAT_005363c4 == 1) && (*(int *)(&DAT_005350d8 + param_4 * 4) == 1)) {
    iVar7 = iVar7 / 2;
  }
  if ((((DAT_004da190 == 8) || (0 < DAT_005363c0)) || (DAT_00513478 == 1)) &&
     (*(int *)(&DAT_005350d8 + param_4 * 4) == 1)) {
    iVar7 = iVar7 / 2;
  }
  iVar9 = iVar7 + 2;
  if (*(int *)(&DAT_00522ff0 + param_4 * 4) == 1) {
    if (((int)uVar8 < 0xb4 - iVar9) && (-1 < (int)uVar8)) {
      local_5ac = 1;
    }
    if ((-iVar9 < (int)uVar8) && ((int)uVar8 < 0)) {
      local_5ac = 1;
    }
  }
  if (*(int *)(&DAT_00522ff0 + param_4 * 4) == -1) {
    if (-1 < (int)uVar8) {
      if ((int)uVar8 < iVar9) {
        local_5ac = 1;
      }
      if (-1 < (int)uVar8) goto LAB_0041810d;
    }
    if (iVar7 + -0xb2 < (int)uVar8) {
      local_5ac = 1;
    }
  }
LAB_0041810d:
  _DAT_004f3a48 = (double)param_3;
  _DAT_00535c78 = (double)param_2;
  if ((DAT_005363b8 == 1) && (local_5b4 == 0)) {
    FUN_0041acb0(local_580,local_5c0);
  }
  else {
    FUN_0041a5e0(local_580,local_5c0,param_3,local_5b4,param_4);
  }
  if (local_5b4 == 0) {
    FUN_0041bfb0(local_5c0,param_4,local_58c,0xf,uVar8,local_598);
  }
  if ((DAT_00535884 < param_3) && (local_5b4 == 0)) {
    FUN_0041af20(local_5c0,param_4,param_3);
  }
  if (local_5a0 < 0x1a) {
    local_590 = local_5a0;
  }
  else {
    local_590 = 0x1a;
  }
  iVar7 = 0;
  if (-1 < local_590) {
    pdVar10 = (double *)&DAT_00511388;
    do {
      fVar11 = -((float10)(double)(&DAT_004f3a38)[iVar7] - (float10)_DAT_004f3a48);
      dVar2 = (double)((float10)(double)(&DAT_00535c68)[iVar7] - (float10)_DAT_00535c78);
      fVar12 = (float10)fpatan((float10)(double)(&DAT_00535c68)[iVar7] - (float10)_DAT_00535c78,
                               fVar11);
      *pdVar10 = (double)fVar11;
      fVar11 = fVar11 * fVar11 + (float10)dVar2 * (float10)dVar2;
      if (fVar11 <= (float10)_DAT_004cc658) {
        *(undefined4 *)(&uStack_560 + iVar7) = 0;
        *(undefined4 *)(&local_398 + iVar7) = 0;
        *(undefined4 *)((int)&uStack_560 + iVar7 * 8 + 4) = 0;
        *(undefined4 *)((int)&local_398 + iVar7 * 8 + 4) = 0;
      }
      else {
        (&local_398)[iVar7] = (double)fVar12;
        (&uStack_560)[iVar7] = SQRT((double)fVar11);
      }
      iVar7 = iVar7 + 1;
      pdVar10 = pdVar10 + 1;
    } while (iVar7 <= local_590);
  }
  if (*(int *)(&DAT_005350d8 + param_4 * 4) == 1) {
    pdVar10 = (double *)&DAT_00511460;
    iVar7 = 0;
    do {
      fVar11 = (float10)*(double *)((int)&DAT_00535d40 + iVar7) - (float10)_DAT_00535c78;
      fVar12 = -((float10)*(double *)((int)&DAT_004f3b10 + iVar7) - (float10)_DAT_004f3a48);
      dVar2 = (double)fVar11;
      fVar11 = (float10)fpatan(fVar11,fVar12);
      *pdVar10 = (double)fVar12;
      fVar12 = fVar12 * fVar12 + (float10)dVar2 * (float10)dVar2;
      if (fVar12 <= (float10)_DAT_004cc658) {
        *(undefined4 *)((int)&uStack_488 + iVar7) = 0;
        *(undefined4 *)((int)&local_2c0 + iVar7) = 0;
        *(undefined4 *)((int)&uStack_488 + iVar7 + 4) = 0;
        *(undefined4 *)((int)&local_2c0 + iVar7 + 4) = 0;
      }
      else {
        *(double *)((int)&local_2c0 + iVar7) = (double)fVar11;
        *(double *)((int)&uStack_488 + iVar7) = SQRT((double)fVar12);
      }
      iVar7 = iVar7 + 8;
      pdVar10 = pdVar10 + 1;
    } while (iVar7 < 0x59);
  }
  if ((DAT_00535884 < param_3) && (0x26 < local_5a0)) {
    pdVar10 = (double *)&DAT_005114c0;
    iVar9 = 0;
    iVar7 = local_5a0 + -0x26;
    do {
      fVar11 = (float10)*(double *)((int)&DAT_00535da0 + iVar9) - (float10)_DAT_00535c78;
      fVar12 = -((float10)*(double *)((int)&DAT_004f3b70 + iVar9) - (float10)_DAT_004f3a48);
      dVar2 = (double)fVar11;
      fVar11 = (float10)fpatan(fVar11,fVar12);
      *pdVar10 = (double)fVar12;
      fVar12 = fVar12 * fVar12 + (float10)dVar2 * (float10)dVar2;
      if (fVar12 <= (float10)_DAT_004cc658) {
        *(undefined4 *)((int)&uStack_428 + iVar9) = 0;
        *(undefined4 *)((int)&local_260 + iVar9) = 0;
        *(undefined4 *)((int)&uStack_428 + iVar9 + 4) = 0;
        *(undefined4 *)((int)&local_260 + iVar9 + 4) = 0;
      }
      else {
        *(double *)((int)&local_260 + iVar9) = (double)fVar11;
        *(double *)((int)&uStack_428 + iVar9) = SQRT((double)fVar12);
      }
      iVar9 = iVar9 + 8;
      pdVar10 = pdVar10 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  local_588 = 0.3;
  if (2 < *(int *)(&DAT_004f71c0 + param_5 * 4)) {
    local_588 = 0.6;
  }
  local_59c = FUN_0041bc20(*(int *)(&DAT_004fc2c0 + param_4 * 4));
  if (DAT_005363bc == 1) {
    local_59c = 0;
  }
  if (-1 < local_590) {
    local_570 = (double)local_574;
    local_580 = (double)(int)uVar8 * _DAT_004cc670;
    fVar11 = (float10)fsin((float10)local_59c * (float10)_DAT_004cc568);
    local_5b0 = (double *)&local_398;
    local_568 = (double)fVar11;
    iVar7 = 0;
    do {
      dVar2 = *local_5b0;
      adStack_1d0[iVar7] =
           (double)*(int *)(&DAT_00522ff0 + param_4 * 4) *
           (double)(&DAT_004fea68)[iVar7] * local_568 * _DAT_004cc600 -
           (double)(&DAT_00511388)[iVar7] * local_570 * _DAT_004cc678;
      fVar11 = FUN_0041bc40(dVar2 - local_580);
      fVar12 = (float10)fsin(fVar11);
      fVar11 = (float10)fcos(fVar11);
      (&DAT_005228e0)[iVar7] =
           (int)(longlong)(fVar12 * (float10)(double)(&uStack_560)[iVar7]) + param_2;
      local_5b0 = local_5b0 + 1;
      iVar9 = iVar7 + 1;
      (&DAT_005229e0)[iVar7] =
           param_3 - (int)(longlong)
                          (fVar11 * (float10)local_588 * (float10)(double)(&uStack_560)[iVar7] +
                          (float10)adStack_1d0[iVar7]);
      iVar7 = iVar9;
    } while (iVar9 <= local_590);
  }
  if (*(int *)(&DAT_005350d8 + param_4 * 4) == 1) {
    local_570 = (double)local_574;
    local_580 = (double)(int)uVar8 * _DAT_004cc670;
    fVar11 = (float10)fsin((float10)local_59c * (float10)_DAT_004cc568);
    local_5b0 = (double *)&local_2c0;
    iVar7 = 0;
    local_590 = 0;
    local_568 = (double)fVar11;
    do {
      dVar2 = *local_5b0;
      *(double *)((int)adStack_f8 + iVar7) =
           (double)*(int *)(&DAT_00522ff0 + param_4 * 4) *
           *(double *)((int)&DAT_004feb40 + iVar7) * local_568 * _DAT_004cc600 -
           *(double *)((int)&DAT_00511460 + iVar7) * local_570 * _DAT_004cc678;
      fVar11 = FUN_0041bc40(dVar2 - local_580);
      fVar12 = (float10)fsin(fVar11);
      fVar11 = (float10)fcos(fVar11);
      *(int *)((int)&DAT_0052294c + local_590) =
           (int)(longlong)(fVar12 * (float10)*(double *)((int)&uStack_488 + iVar7)) + param_2;
      pdVar10 = (double *)((int)&uStack_488 + iVar7);
      pdVar1 = (double *)((int)adStack_f8 + iVar7);
      iVar7 = iVar7 + 8;
      local_5b0 = local_5b0 + 1;
      *(int *)((int)&DAT_00522a4c + local_590) =
           param_3 - (int)(longlong)
                          (fVar11 * (float10)local_588 * (float10)*pdVar10 + (float10)*pdVar1);
      local_590 = local_590 + 4;
    } while (iVar7 < 0x59);
  }
  if ((DAT_00535884 < param_3) && (0x26 < local_5a0)) {
    local_570 = (double)local_574;
    local_580 = (double)(int)uVar8 * _DAT_004cc670;
    fVar11 = (float10)fsin((float10)local_59c * (float10)_DAT_004cc568);
    local_5b0 = (double *)&local_260;
    local_5a8 = local_5a0 + -0x26;
    iVar7 = 0;
    local_59c = 0;
    local_568 = (double)fVar11;
    do {
      dVar2 = *local_5b0;
      *(double *)((int)adStack_98 + iVar7) =
           (double)*(int *)(&DAT_00522ff0 + param_4 * 4) *
           *(double *)((int)&DAT_004feba0 + iVar7) * local_568 * _DAT_004cc600 -
           *(double *)((int)&DAT_005114c0 + iVar7) * local_570 * _DAT_004cc678;
      fVar11 = FUN_0041bc40(dVar2 - local_580);
      fVar12 = (float10)fsin(fVar11);
      fVar11 = (float10)fcos(fVar11);
      *(int *)((int)&DAT_0052297c + local_59c) =
           (int)(longlong)(fVar12 * (float10)*(double *)((int)&uStack_428 + iVar7)) + param_2;
      pdVar10 = (double *)((int)&uStack_428 + iVar7);
      pdVar1 = (double *)((int)adStack_98 + iVar7);
      iVar7 = iVar7 + 8;
      local_5b0 = local_5b0 + 1;
      *(int *)((int)&DAT_00522a7c + local_59c) =
           param_3 - (int)(longlong)
                          (fVar11 * (float10)local_588 * (float10)*pdVar10 + (float10)*pdVar1);
      local_59c = local_59c + 4;
      local_5a8 = local_5a8 + -1;
    } while (local_5a8 != 0);
  }
  iVar7 = (int)(longlong)(local_5c0 * _DAT_004cc680);
  if ((local_5b4 == 1) || (0x1f < (int)param_4)) {
    iVar7 = (iVar7 * 3) / 2;
  }
  if ((DAT_005363bc == 1) && (local_5b4 == 0)) {
    iVar7 = iVar7 / 2;
  }
  DAT_004f4514 = DAT_005228e0;
  DAT_004fb9cc = iVar7 + DAT_005229e0;
  DAT_004f451c = (DAT_005228e0 + DAT_00522920) / 2;
  iVar9 = (DAT_005229e0 + DAT_00522a20) / 2;
  DAT_004f4518 = (DAT_005228f8 + DAT_005228e0) / 2;
  iVar3 = (DAT_005229f8 + DAT_005229e0) / 2;
  if (DAT_005363cc == 1) {
    iVar9 = DAT_005228e0 + DAT_00522920 * 3;
    DAT_004f451c = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
    iVar9 = DAT_005229e0 + DAT_00522a20 * 3;
    iVar9 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
    iVar3 = DAT_005228e0 + DAT_005228f8 * 3;
    DAT_004f4518 = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
    iVar3 = DAT_005229e0 + DAT_005229f8 * 3;
    iVar3 = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
  }
  DAT_004fb9c8 = iVar9 + iVar7;
  DAT_004fb9c4 = iVar3 + iVar7;
  iVar3 = DAT_005228e0 - DAT_005228ec;
  iVar9 = DAT_004fb9cc - DAT_005229ec;
  iVar7 = (int)(longlong)(local_5c0 * _DAT_004cc688);
  if ((local_5b4 == 1) || (0x1f < (int)param_4)) {
    iVar7 = (iVar7 * 3) / 2;
  }
  if (((DAT_005364d4 == 1) || (((DAT_004da190 == 4 && (DAT_0053652c == 0)) || (param_4 == 0)))) ||
     ((DAT_005363c4 == 1 || (0 < DAT_005363c0)))) {
    DAT_005362cc = DAT_005228f4;
    iVar4 = DAT_005229f4;
  }
  else {
    DAT_005362cc = (DAT_005228f0 + DAT_005228f4 * 2) / 3;
    iVar4 = (DAT_005229f0 + DAT_005229f4 * 2) / 3;
  }
  DAT_004f4090 = iVar4 + iVar7;
  if (DAT_0053652c == 1) {
    iVar7 = (iVar7 * 9) / 10;
    DAT_005362cc = DAT_005228f0;
    DAT_004f4090 = iVar7 + DAT_005229f0;
  }
  if (((DAT_005364bc == 1) || ((DAT_004da190 == 3 && (DAT_005363c4 == 0)))) || (DAT_00536528 == 1))
  {
    DAT_005362cc = (DAT_005228f0 + DAT_005228f4) / 2;
    DAT_004f4090 = (DAT_005229f0 + DAT_005229f4) / 2 + iVar7;
  }
  if ((DAT_005363c0 == 1) || (DAT_00536530 == 1)) {
    DAT_005362cc = (DAT_005228f0 + DAT_005228f4 * 6) / 7;
    DAT_004f4090 = (DAT_005229f0 + DAT_005229f4 * 6) / 7 + iVar7;
  }
  if ((DAT_005363bc == 1) && (local_5b4 == 0)) {
    DAT_004f4090 = iVar7 + DAT_005229f0;
    DAT_005362cc = DAT_005228f0;
  }
  if (((((DAT_00535884 < param_3) && (0x19 < *(int *)(&DAT_004fdfe8 + param_4 * 4))) ||
       ((DAT_005364c8 == 1 &&
        ((10 < *(int *)(&DAT_004fdfe8 + param_4 * 4) &&
         (DAT_00535884 - DAT_004fe2a8 / 100 < param_3)))))) && (DAT_005363b8 == 0)) &&
     ((((DAT_004da174 < 0xd && (DAT_005363b4 == 0)) && (DAT_0053642c == 0)) &&
      ((0 < DAT_005363b0 && ((int)param_4 <= DAT_004da194)))))) {
    local_59c = param_4 * 8;
    local_5b0 = (double *)0x14;
    do {
      FUN_0043e730(0,*(double *)(&DAT_00510ea8 + local_59c),*(double *)(&DAT_00525510 + local_59c),
                   param_5,0);
      FUN_00423fe0(param_1,param_4,local_5c0,iVar3 + DAT_004fed58,iVar9 + DAT_00523660,
                   (int)local_5b0,param_3);
      local_5b0 = (double *)((int)local_5b0 + -1);
      local_59c = local_59c + -0x130;
    } while (1 < (int)local_5b0);
  }
  if (((0x1e < *(int *)(&DAT_004fdfe8 + param_4 * 4)) && (0 < (int)param_4)) &&
     ((DAT_005363b8 == 1 && (local_5b4 == 0)))) {
    iVar9 = (DAT_005228f8 + DAT_005228fc) / 2;
    iVar7 = (int)(longlong)(local_5c0 * _DAT_004cc690);
    iVar3 = (DAT_005229fc + DAT_005229f8) / 2 - iVar7;
    iVar4 = (DAT_0052291c + DAT_00522920) / 2;
    iVar7 = (DAT_00522a1c + DAT_00522a20) / 2 - iVar7;
    if ((*(int *)(&DAT_00522ff0 + param_4 * 4) == 1) &&
       (FUN_00424130(param_1,param_4,local_5c0,iVar4,iVar7,param_5),
       *(int *)(&DAT_004fc2c0 + param_4 * 4) < 8)) {
      FUN_00424130(param_1,param_4,local_5c0,iVar9,iVar3,param_5);
    }
    if (*(int *)(&DAT_00522ff0 + param_4 * 4) == -1) {
      if (*(int *)(&DAT_004fc2c0 + param_4 * 4) < 8) {
        FUN_00424130(param_1,param_4,local_5c0,iVar4,iVar7,param_5);
      }
      FUN_00424130(param_1,param_4,local_5c0,iVar9,iVar3,param_5);
    }
  }
  if ((DAT_005363b8 == 0) || (local_5b4 == 1)) {
    if ((0 < (int)uVar8) || ((int)uVar8 < -0xa9)) {
      FUN_0041e3c0(param_1,local_5c0,local_5b4,param_4);
    }
    if (((int)uVar8 < 0) || (0xa9 < (int)uVar8)) {
      FUN_0041e750(param_1,local_5c0,local_5b4,param_4);
    }
    if ((-0x5a < (int)uVar8) && ((int)uVar8 < 0x5a)) {
      FUN_0041eaf0(param_1,local_5c0,param_4,local_5b4,param_3);
    }
  }
  if ((DAT_005363b8 == 1) && (local_5b4 == 0)) {
    if ((0 < (int)uVar8) || ((int)uVar8 < -0xa9)) {
      FUN_00421630(param_1,local_5c0,param_4,param_3);
      FUN_004223c0(param_1,local_5c0,param_4,param_3);
    }
    if (((int)uVar8 < 0) || (0xa9 < (int)uVar8)) {
      FUN_00422220(param_1,local_5c0,param_4,param_3);
      FUN_004218d0(param_1,local_5c0,param_4,param_3);
    }
    if ((-0x5b < (int)uVar8) && ((int)uVar8 < 0x5b)) {
      FUN_00421ab0(param_1,local_5c0,param_4,uVar8);
    }
  }
  if (((0x1e < *(int *)(&DAT_004fdfe8 + param_4 * 4)) && (local_5b4 == 0)) && (DAT_005363b8 == 0)) {
    if (((int)uVar8 < 0xf) || (0xaa < (int)uVar8)) {
      if (DAT_0053652c == 0) {
        FUN_00423e80(param_1,param_4,local_5c0,1,param_3,uVar8);
      }
      if ((DAT_0053652c == 1) && (*(int *)(&DAT_00522ff0 + param_4 * 4) == 1)) {
        FUN_00423e80(param_1,param_4,local_5c0,1,param_3,uVar8);
      }
      if (((DAT_0053652c == 1) && (*(int *)(&DAT_00522ff0 + param_4 * 4) == 1)) &&
         (*(int *)(&DAT_004fc2c0 + param_4 * 4) < 0xb)) {
        FUN_00423e80(param_1,param_4,local_5c0,0,param_3,uVar8);
      }
    }
    if ((-0xf < (int)uVar8) || ((int)uVar8 < -0xaa)) {
      if (DAT_0053652c == 0) {
        FUN_00423e80(param_1,param_4,local_5c0,0,param_3,uVar8);
      }
      if (DAT_0053652c == 1) {
        if (*(int *)(&DAT_00522ff0 + param_4 * 4) == -1) {
          FUN_00423e80(param_1,param_4,local_5c0,0,param_3,uVar8);
        }
        if (((DAT_0053652c == 1) && (*(int *)(&DAT_00522ff0 + param_4 * 4) == -1)) &&
           (*(int *)(&DAT_004fc2c0 + param_4 * 4) < 0xb)) {
          FUN_00423e80(param_1,param_4,local_5c0,1,param_3,uVar8);
        }
      }
    }
  }
  if ((DAT_005363b8 == 1) && (local_5b4 == 0)) {
    FUN_004214e0(param_1,param_4);
    FUN_00421f10(param_1,local_5c0,local_598);
    if (DAT_00513478 == 1) {
      FUN_0048e730(param_1,param_4,local_5c0,uVar8);
    }
  }
  else {
    FUN_00419ce0(param_1,local_5c0,param_4,param_3);
  }
  uVar5 = (int)uVar8 >> 0x1f;
  if ((((DAT_004da190 == 7) || (1 < DAT_005363c0)) && (local_5b4 == 0)) &&
     ((int)((uVar8 ^ uVar5) - uVar5) < 0x5b)) {
    FUN_004243b0(param_1,param_4,local_5c0,uVar8,0,param_3);
  }
  if ((local_5b4 == 1) || (param_4 == 0x1f)) {
    uVar5 = (uVar8 ^ uVar5) - uVar5;
    uVar6 = uVar5;
    if ((int)uVar5 < 0x5b) {
      uVar6 = FUN_004243b0(param_1,param_4,local_5c0,1,uVar8,param_3);
    }
    _DAT_004fecc8 = 0;
    if (param_4 != 0) {
      _DAT_004fecc8 = 0;
      return uVar6;
    }
    iVar7 = (int)(longlong)local_5c0;
    FUN_00420920(param_1,DAT_005228e8,DAT_005229e8 + iVar7 * -3,0,uVar8,param_3,local_5b4);
    if ((_DAT_004cc698 <= _DAT_005359f0) && (_DAT_005359f0 <= _DAT_004cc658)) {
      FUN_00420920(param_1,DAT_005228e8,DAT_005229e8 + iVar7 * -2,0,uVar8,param_3,2);
    }
    if ((_DAT_004cc6a0 <= _DAT_005359f0) && (_DAT_005359f0 <= _DAT_004cc6a8)) {
      FUN_00420920(param_1,DAT_005228e8,DAT_005229e8 - iVar7,0,uVar8,param_3,3);
    }
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    FUN_004b4d9d(param_1,(int *)&local_580,DAT_005228e8,DAT_005229e8);
    uVar6 = CDC::LineTo(param_1,DAT_005228e8,DAT_005229e8 + iVar7 * -3);
    if ((int)uVar5 < 0x5b) {
      return uVar6;
    }
    uVar8 = FUN_004243b0(param_1,0,local_5c0,1,uVar8,param_3);
    return uVar8;
  }
  if (((DAT_004da190 == 7) || (1 < DAT_005363c0)) && (0x5a < (int)((uVar8 ^ uVar5) - uVar5))) {
    FUN_004243b0(param_1,param_4,local_5c0,uVar8,local_5b4,param_3);
  }
  if ((int)DAT_004da14c < 1) {
    FUN_004235a0(param_1,local_5c0,param_4,param_3);
  }
  if (DAT_005363bc == 1) {
    FUN_0041fe70(param_1,param_4,local_5c0,local_58c,0xf,param_3,local_598,uVar8,local_5b4,local_5ac
                );
  }
  if (local_5ac != 1) {
    if ((DAT_004da190 == 8) || (DAT_005364c8 == 1)) {
      FUN_00423c30(param_1,local_5c0,param_4,1,uVar8,param_3);
      FUN_00423c30(param_1,local_5c0,param_4,-1,uVar8,param_3);
    }
    if (((int)uVar8 < 0x5a) && (-0x5a < (int)uVar8)) {
      if ((3 < (int)DAT_004da190) && ((int)DAT_004da190 < 9)) {
        FUN_004225b0(param_1,3,param_4,local_5c0,param_3,local_5ac,uVar8);
      }
      if (((DAT_005364d4 == 1) || (DAT_005363c0 == 1)) || (DAT_005363c0 == 3)) {
        FUN_004225b0(param_1,5,param_4,local_5c0,param_3,local_5ac,uVar8);
      }
      if (1 < (int)DAT_004da190) {
        FUN_004225b0(param_1,2,param_4,local_5c0,param_3,local_5ac,uVar8);
      }
      if (((DAT_005364d4 == 1) || (DAT_005363c0 == 1)) ||
         ((DAT_005363c0 == 3 || (DAT_00536528 == 1)))) {
        FUN_004225b0(param_1,4,param_4,local_5c0,param_3,local_5ac,uVar8);
      }
      FUN_004225b0(param_1,1,param_4,local_5c0,param_3,local_5ac,uVar8);
      if (((DAT_004da14c == 1) && ((int)DAT_004da190 < 8)) && (DAT_005364c8 == 0)) {
        FUN_00423c30(param_1,local_5c0,param_4,0,uVar8,param_3);
      }
    }
    else {
      if ((DAT_004da14c == 1) && (((int)DAT_004da190 < 8 && (DAT_005364c8 == 0)))) {
        FUN_00423c30(param_1,local_5c0,param_4,0,uVar8,param_3);
      }
      FUN_004225b0(param_1,1,param_4,local_5c0,param_3,local_5ac,uVar8);
      if ((((DAT_005364d4 == 1) || (DAT_005363c0 == 1)) || (DAT_005363c0 == 3)) ||
         (DAT_00536528 == 1)) {
        FUN_004225b0(param_1,4,param_4,local_5c0,param_3,local_5ac,uVar8);
      }
      if (1 < (int)DAT_004da190) {
        FUN_004225b0(param_1,2,param_4,local_5c0,param_3,local_5ac,uVar8);
      }
      if (((DAT_005364d4 == 1) || (DAT_005363c0 == 1)) || (DAT_005363c0 == 3)) {
        FUN_004225b0(param_1,5,param_4,local_5c0,param_3,local_5ac,uVar8);
      }
      if ((3 < (int)DAT_004da190) && ((int)DAT_004da190 < 9)) {
        FUN_004225b0(param_1,3,param_4,local_5c0,param_3,local_5ac,uVar8);
      }
    }
    FUN_0041ce80(param_1,local_5c0,param_4,local_598,param_3,uVar8,local_5ac);
    FUN_0041fe70(param_1,param_4,local_5c0,local_58c,0xf,param_3,local_598,uVar8,local_5b4,local_5ac
                );
    if ((((*(int *)(&DAT_005350d8 + param_4 * 4) == 1) && (2 < (int)DAT_004da190)) &&
        (DAT_004da190 != 9)) && ((DAT_005364c4 == 0 && (DAT_005364c8 == 0)))) {
      FUN_00425670(param_1,local_5c0,param_4,param_3,local_5ac);
    }
    iVar7 = *(int *)(&DAT_005350d8 + param_4 * 4);
    if (iVar7 == 1) {
      if (((DAT_004da190 == 2) || (DAT_005364c4 == 1)) || (DAT_005364c8 == 1)) {
        FUN_0041f520(param_1,local_5c0,param_4,param_3,local_5ac);
      }
      iVar7 = *(int *)(&DAT_005350d8 + param_4 * 4);
    }
    uVar5 = 1;
    if ((iVar7 < 1) && (1 < (int)DAT_004da190)) {
      uVar5 = FUN_0041f520(param_1,local_5c0,param_4,param_3,local_5ac);
    }
    goto LAB_00419ad3;
  }
  if ((((*(int *)(&DAT_005350d8 + param_4 * 4) == 1) && (2 < (int)DAT_004da190)) &&
      (DAT_004da190 != 9)) && ((DAT_005364c4 == 0 && (DAT_005364c8 == 0)))) {
    FUN_00425670(param_1,local_5c0,param_4,param_3,1);
  }
  if ((*(int *)(&DAT_005350d8 + param_4 * 4) == 1) &&
     (((DAT_004da190 == 2 || (DAT_005364c4 == 1)) || (DAT_005364c8 == 1)))) {
    FUN_0041f520(param_1,local_5c0,param_4,param_3,1);
  }
  if ((*(int *)(&DAT_005350d8 + param_4 * 4) < 1) && (1 < (int)DAT_004da190)) {
    FUN_0041f520(param_1,local_5c0,param_4,param_3,1);
  }
  if (((int)DAT_00523198 < 0) && ((int)DAT_004da190 < 7)) {
    if (((int)uVar8 < 0x5a) && (-0x5a < (int)uVar8)) {
      if ((3 < (int)DAT_004da190) && ((int)DAT_004da190 < 9)) {
        FUN_004225b0(param_1,3,param_4,local_5c0,param_3,1,uVar8);
      }
      if (DAT_005363c0 == 3) {
        FUN_004225b0(param_1,5,param_4,local_5c0,param_3,1,uVar8);
      }
      if (1 < (int)DAT_004da190) {
        FUN_004225b0(param_1,2,param_4,local_5c0,param_3,1,uVar8);
      }
      if ((DAT_005363c0 == 3) || (DAT_00536528 == 1)) {
        FUN_004225b0(param_1,4,param_4,local_5c0,param_3,1,uVar8);
      }
      iVar7 = 1;
    }
    else {
      FUN_004225b0(param_1,1,param_4,local_5c0,param_3,1,uVar8);
      if ((DAT_005363c0 == 3) || (DAT_00536528 == 1)) {
        FUN_004225b0(param_1,4,param_4,local_5c0,param_3,1,uVar8);
      }
      if (1 < (int)DAT_004da190) {
        FUN_004225b0(param_1,2,param_4,local_5c0,param_3,1,uVar8);
      }
      if (DAT_005363c0 == 3) {
        FUN_004225b0(param_1,5,param_4,local_5c0,param_3,1,uVar8);
      }
      if (((int)DAT_004da190 < 4) || (8 < (int)DAT_004da190)) goto LAB_004193bb;
      iVar7 = 3;
    }
    FUN_004225b0(param_1,iVar7,param_4,local_5c0,param_3,1,uVar8);
  }
LAB_004193bb:
  FUN_0041ce80(param_1,local_5c0,param_4,local_598,param_3,uVar8,1);
  FUN_0041fe70(param_1,param_4,local_5c0,local_58c,0xf,param_3,local_598,uVar8,local_5b4,1);
  if ((DAT_004da190 == 8) || (DAT_005364c8 == 1)) {
    FUN_00423c30(param_1,local_5c0,param_4,1,uVar8,param_3);
    FUN_00423c30(param_1,local_5c0,param_4,-1,uVar8,param_3);
  }
  if ((-1 < (int)DAT_00523198) || (uVar5 = DAT_00523198, 6 < (int)DAT_004da190)) {
    if (((int)uVar8 < 0x5a) && (-0x5a < (int)uVar8)) {
      if ((3 < (int)DAT_004da190) && ((int)DAT_004da190 < 9)) {
        FUN_004225b0(param_1,3,param_4,local_5c0,param_3,1,uVar8);
      }
      if (((DAT_005364d4 == 1) || (DAT_005363c0 == 1)) || (DAT_005363c0 == 3)) {
        FUN_004225b0(param_1,5,param_4,local_5c0,param_3,1,uVar8);
      }
      if (1 < (int)DAT_004da190) {
        FUN_004225b0(param_1,2,param_4,local_5c0,param_3,1,uVar8);
      }
      if (((DAT_005364d4 == 1) || (DAT_005363c0 == 1)) ||
         ((DAT_005363c0 == 3 || (DAT_00536528 == 1)))) {
        FUN_004225b0(param_1,4,param_4,local_5c0,param_3,1,uVar8);
      }
      FUN_004225b0(param_1,1,param_4,local_5c0,param_3,1,uVar8);
      uVar5 = DAT_004da14c;
      if (((DAT_004da14c == 1) && ((int)DAT_004da190 < 8)) &&
         (uVar5 = DAT_005364c8, DAT_005364c8 == 0)) {
        uVar5 = FUN_00423c30(param_1,local_5c0,param_4,0,uVar8,param_3);
      }
    }
    else {
      if (((DAT_004da14c == 1) && ((int)DAT_004da190 < 8)) && (DAT_005364c8 == 0)) {
        FUN_00423c30(param_1,local_5c0,param_4,0,uVar8,param_3);
      }
      FUN_004225b0(param_1,1,param_4,local_5c0,param_3,1,uVar8);
      if (((DAT_005364d4 == 1) || (DAT_005363c0 == 1)) ||
         ((DAT_005363c0 == 3 || (DAT_00536528 == 1)))) {
        FUN_004225b0(param_1,4,param_4,local_5c0,param_3,1,uVar8);
      }
      if (1 < (int)DAT_004da190) {
        FUN_004225b0(param_1,2,param_4,local_5c0,param_3,1,uVar8);
      }
      if (((DAT_005364d4 == 1) || (DAT_005363c0 == 1)) || (DAT_005363c0 == 3)) {
        FUN_004225b0(param_1,5,param_4,local_5c0,param_3,1,uVar8);
      }
      uVar5 = DAT_004da190;
      if ((3 < (int)DAT_004da190) && ((int)DAT_004da190 < 9)) {
        uVar5 = FUN_004225b0(param_1,3,param_4,local_5c0,param_3,1,uVar8);
      }
    }
  }
LAB_00419ad3:
  if ((((((DAT_004da190 == 10) && (DAT_005364dc == 1)) && (0xc < (int)(&DAT_004fb380)[param_4])) &&
       ((0x5a < DAT_004feccc && (uVar5 = uVar8, -0x47 < (int)uVar8)))) && ((int)uVar8 < 0x5b)) &&
     (uVar5 = *(uint *)(&DAT_005356b0 + param_4 * 4), uVar5 == 0)) {
    uVar8 = FUN_004225b0(param_1,2,param_4,local_5c0,param_3,local_5ac,uVar8);
    return uVar8;
  }
  return uVar5;
}

