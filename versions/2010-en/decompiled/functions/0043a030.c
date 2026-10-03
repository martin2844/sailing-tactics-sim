
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043a030(int param_1)

{
  double dVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  float10 fVar14;
  float10 fVar15;
  int local_2c;
  int local_28;
  int local_20;
  double local_18;
  double local_10;
  double local_8;
  
  iVar7 = param_1;
  uVar12 = (int)DAT_005364e8 >> 0x1f;
  if (((DAT_005364e8 ^ uVar12) - uVar12 & 1 ^ uVar12) == uVar12) {
    return;
  }
  if (DAT_005364c8 == 1) {
    *(undefined4 *)(&DAT_004fe778 + param_1 * 4) = 2;
  }
  iVar10 = DAT_0053652c;
  iVar9 = DAT_004f8cd0;
  iVar8 = DAT_004da190;
  if ((DAT_004da190 < 6) || (DAT_004f4200 = 0x16, 8 < DAT_004da190)) {
    DAT_004f4200 = 0xf;
  }
  if (DAT_005363b8 == 1) {
    DAT_004f4200 = 10;
  }
  if (0 < DAT_005363c0) {
    DAT_004f4200 = 0x13;
  }
  if (DAT_004fb410 == 1) {
    DAT_004f4200 = 0xf;
  }
  if (DAT_005364bc == 1) {
    DAT_004f4200 = 0x16;
  }
  if (DAT_0053652c == 1) {
    DAT_004f4200 = 0x12;
  }
  DAT_004fe62c = 0x1e;
  if ((param_1 <= DAT_004da140) && (*(int *)(&DAT_00535620 + param_1 * 4) + 0x1e < DAT_004f8cd0)) {
    *(undefined4 *)(&DAT_005116e0 + param_1 * 4) = 0;
  }
  if (iVar9 < -0x96) {
    *(undefined4 *)(&DAT_005116e0 + param_1 * 4) = 0;
  }
  iVar2 = *(int *)(&DAT_004fdfe8 + param_1 * 4);
  iVar3 = *(int *)(&DAT_004fc2c0 + param_1 * 4);
  *(int *)(&DAT_00522f28 + param_1 * 4) = iVar3;
  if (((iVar8 == 2) || (DAT_005364c8 == 1)) || (DAT_00525a98 = 0x69, DAT_005364c4 == 1)) {
    DAT_00525a98 = 0x8c;
  }
  if (((DAT_005364c0 == 1) || (DAT_005363c4 == 1)) || ((iVar8 == 8 || (iVar10 == 1)))) {
    DAT_00525a98 = 0x61;
  }
  iVar10 = DAT_00525a98;
  if (DAT_004da140 < param_1) {
    if (0 < *(int *)(&DAT_004f4478 + param_1 * 4)) {
      *(int *)(&DAT_004f4478 + param_1 * 4) = *(int *)(&DAT_004f4478 + param_1 * 4) + -1;
    }
    if (((iVar10 < *(int *)(&DAT_004fecc8 + param_1 * 4)) && (1 < iVar8)) &&
       ((iVar8 != 9 &&
        ((((0x5a < *(int *)(&DAT_00535178 + param_1 * 4) && (0 < iVar9)) &&
          (*(int *)(&DAT_005116e0 + param_1 * 4) != 10)) &&
         (*(int *)(&DAT_004fe6d0 + param_1 * 4) == 0)))))) {
      if (*(int *)(&DAT_004f4478 + param_1 * 4) == 0) {
        if (*(int *)(&DAT_005350d8 + param_1 * 4) == 0) {
          *(undefined4 *)(&DAT_004f4478 + param_1 * 4) = 2;
        }
        *(undefined4 *)(&DAT_005350d8 + param_1 * 4) = 1;
      }
    }
    else if (*(int *)(&DAT_004f4478 + param_1 * 4) == 0) {
      *(undefined4 *)(&DAT_005350d8 + param_1 * 4) = 0;
    }
    if ((*(int *)(&DAT_004f8538 + param_1 * 4) < 3) && (DAT_004da19c != 8)) {
      *(undefined4 *)(&DAT_005350d8 + param_1 * 4) = 0;
    }
  }
  if ((DAT_005364c8 == 1) && (param_1 <= DAT_004da140)) {
    if (param_1 == 1) {
      DAT_004f4520 = (uint)(iVar10 < DAT_004feccc);
    }
    if ((param_1 == 2) && (DAT_004da140 == 2)) {
      DAT_004f4524 = (uint)(iVar10 < DAT_004fecd0);
    }
  }
  DAT_00536494 = ((int)(&DAT_004fb380)[param_1] < 0xd) + 5;
  if ((DAT_005363b8 == 0) && (DAT_005363bc == 0)) {
    DAT_00536494 = DAT_00536494 * 2;
  }
  if (DAT_005363bc == 1) {
    DAT_00536494 = 2;
  }
  if (DAT_004da174 < 4) {
    DAT_00536494 = DAT_00536494 / 2;
  }
  if (DAT_004da174 == 1) {
    DAT_00536494 = 0;
  }
  lVar6 = 0x40280000;
  if (iVar8 != 3) {
    lVar6 = 0x40220000;
  }
  if (iVar8 == 1) {
    lVar6 = 0x40200000;
  }
  if (iVar8 == 2) {
    lVar6 = 0x40220000;
  }
  if ((iVar8 == 4) || (iVar8 == 5)) {
    lVar6 = 0x40260000;
  }
  if (DAT_005363bc == 1) {
    lVar6 = 0x40300000;
  }
  if (iVar8 == 8) {
    lVar6 = 0x402c0000;
  }
  if (DAT_005363b8 == 1) {
    lVar6 = 0x40320000;
  }
  if (DAT_005364cc == 1) {
    lVar6 = 0x402c0000;
  }
  if (DAT_005363c0 == 1) {
    lVar6 = 0x402c0000;
  }
  if (DAT_005364bc == 1) {
    lVar6 = 0x40240000;
  }
  if (DAT_0053652c == 1) {
    lVar6 = 0x40260000;
  }
  if (DAT_00536530 == 1) {
    lVar6 = 0x40280000;
  }
  local_10 = (double)(lVar6 << 0x20);
  local_28 = ((9 - iVar8) * 5) / 2;
  if (iVar8 == 3) {
    local_28 = 0x16;
  }
  if (iVar8 == 7) {
    local_28 = 0;
  }
  if (((0xa0 < *(int *)(&DAT_004fecc8 + param_1 * 4)) && (10 < (int)(&DAT_004fb380)[param_1])) &&
     (DAT_005363b8 == 0)) {
    local_28 = local_28 + DAT_004f8ccc * -3;
  }
  uVar12 = *(int *)(&DAT_00535740 + param_1 * 4) - (&DAT_00522b90)[param_1] >> 0x1f;
  iVar8 = (*(int *)(&DAT_00535740 + param_1 * 4) - (&DAT_00522b90)[param_1] ^ uVar12) - uVar12;
  *(int *)(&DAT_004fecc8 + param_1 * 4) = iVar8;
  if (0xb4 < iVar8) {
    *(int *)(&DAT_004fecc8 + param_1 * 4) = 0x168 - iVar8;
  }
  FUN_0043be00(param_1);
  DAT_005350dc = (uint)(DAT_004f4520 == 1);
  if (DAT_004f4524 == 1) {
    DAT_005350e0 = 1;
  }
  else if (DAT_004da140 == 2) {
    DAT_005350e0 = 0;
  }
  iVar8 = param_1;
  if (DAT_005363b8 == 0) {
    iVar8 = ((*(int *)(&DAT_004fecc8 + param_1 * 4) + -0x28) * 0x5a) / 0x8c;
    local_18 = (double)iVar8 - _DAT_004cca40;
    if (DAT_004da190 < 6) {
      local_18 = local_18 - _DAT_004cc660;
    }
    if (DAT_005363bc == 1) {
      if (9 < (int)(&DAT_004fb380)[param_1]) {
        local_18 = local_18 - _DAT_004cc660;
      }
      if ((int)(&DAT_004fb380)[param_1] < 10) {
        local_18 = local_18 - _DAT_004cc600;
      }
    }
    if ((DAT_004da190 == 1) && (DAT_005363bc == 0)) {
      local_18 = local_18 - _DAT_004cc660;
    }
    if (DAT_004da190 == 2) {
      dVar1 = _DAT_004cc570;
      if ((int)(&DAT_004fb380)[param_1] < 0xc) {
        dVar1 = _DAT_004cc8b0;
      }
      local_18 = local_18 - dVar1;
    }
    if (DAT_004da190 == 3) {
      local_18 = local_18 - _DAT_004cc570;
    }
    if (DAT_005363c4 == 1) {
      local_18 = local_18 - _DAT_004cc668;
    }
    if ((DAT_004da190 == 5) && ((int)(&DAT_004fb380)[param_1] < 0xc)) {
      local_18 = local_18 - _DAT_004cc5d8;
    }
    if (DAT_004da190 == 6) {
      if ((int)(&DAT_004fb380)[param_1] < 0xc) {
        local_18 = local_18 - _DAT_004cc5d8;
      }
      if (0xb < (int)(&DAT_004fb380)[param_1]) {
        local_18 = local_18 - _DAT_004cca48;
      }
    }
    if ((DAT_004da190 == 7) && (DAT_005363c0 == 0)) {
      dVar1 = _DAT_004cc690;
      if (0xc < (int)(&DAT_004fb380)[param_1]) {
        dVar1 = _DAT_004cc5e8;
      }
      local_18 = local_18 - dVar1;
    }
    if (DAT_004da190 == 8) {
      if ((int)(&DAT_004fb380)[param_1] < 0xc) {
        local_18 = local_18 - _DAT_004cc5e8;
      }
      if (0xb < (int)(&DAT_004fb380)[param_1]) {
        local_18 = local_18 - _DAT_004cc5d8;
      }
    }
    if (DAT_005363c0 == 1) {
      if (0xd < (int)(&DAT_004fb380)[param_1]) {
        local_18 = local_18 - _DAT_004cc5c8;
      }
      if ((int)(&DAT_004fb380)[param_1] < 0xe) {
        local_18 = local_18 - _DAT_004cc690;
      }
    }
  }
  param_1 = iVar8;
  if (DAT_005363b8 == 1) {
    param_1 = *(int *)(&DAT_004fecc8 + iVar7 * 4);
    dVar1 = _DAT_004cca48;
    if ((int)(&DAT_004fb380)[iVar7] < 0xc) {
      dVar1 = _DAT_004cca68;
    }
    local_18 = (((double)param_1 - _DAT_004cca50) * _DAT_004cca58 - _DAT_004cca60) - dVar1;
    if ((DAT_005364c0 == 1) && (param_1 < 0x5a)) {
      local_18 = local_18 - _DAT_004cc7a8;
    }
    if (DAT_004da190 == 9) {
      local_18 = local_18 - _DAT_004cc798;
    }
  }
  if ((DAT_004da140 < iVar7) &&
     (*(int *)(&DAT_004fe818 + iVar7 * 4) = (int)(longlong)local_18, DAT_004da140 < iVar7)) {
LAB_0043a7e3:
    local_20 = ((0x3b < *(int *)(&DAT_004fecc8 + iVar7 * 4)) - 1 & 0xfffffff6) + 0x1e;
    if ((*(int *)(&DAT_004fecc8 + iVar7 * 4) < 0x5a) && (0xd < (int)(&DAT_004fb380)[iVar7])) {
      local_20 = 10;
    }
  }
  else {
    if (*(int *)(&DAT_00500380 + iVar7 * 4) == -1) {
      *(int *)(&DAT_004fe818 + iVar7 * 4) = (int)(longlong)local_18;
    }
    else {
      iVar8 = ((*(int *)(&DAT_004fecc8 + iVar7 * 4) + -0x28) * 0x5a) / 0x8c + -3;
      *(int *)(&DAT_004fe818 + iVar7 * 4) = iVar8;
      if (iVar8 < 5) {
        *(undefined4 *)(&DAT_004fe818 + iVar7 * 4) = 5;
      }
    }
    if ((DAT_004da140 < iVar7) || (DAT_005364c8 != 0)) goto LAB_0043a7e3;
    local_20 = *(int *)(&DAT_004fe778 + iVar7 * 4) * 10;
  }
  fVar14 = FUN_0043bb70(*(int *)(&DAT_004fdfe8 + iVar7 * 4),iVar7);
  iVar8 = local_20 + 0x78;
  if ((((6 < DAT_004da190) && (iVar7 <= DAT_004da140)) && (DAT_004da190 < 9)) &&
     ((DAT_005364c8 == 0 && (*(int *)(&DAT_005350d8 + iVar7 * 4) < 1)))) {
    iVar8 = iVar8 + *(int *)(&DAT_004f7ee0 + iVar7 * 4) * -0x19 + 0x19;
  }
  if ((5 < DAT_004da190) && (DAT_004da190 < 9)) {
    iVar9 = *(int *)(&DAT_004fecc8 + iVar7 * 4);
    if (iVar9 < 0x3d) {
      if ((DAT_004da190 == 6) || (DAT_004da190 == 7)) {
        param_1 = ((iVar8 + 0x96) * iVar9) / 0x3c + -0x96;
      }
      else {
        param_1 = ((iVar8 + 0x5f) * iVar9) / 0x3c + -0x5f;
      }
    }
    else {
      param_1 = iVar8 - (iVar9 + -0x3c) / 5;
    }
  }
  if ((((DAT_004da190 < 6) && (DAT_005363c4 == 0)) && (DAT_005363bc == 0)) && (DAT_0053652c == 0)) {
    param_1 = iVar8;
    if (*(int *)(&DAT_004fecc8 + iVar7 * 4) <= DAT_004f7200 + 7) {
      param_1 = ((iVar8 + 0x96) * *(int *)(&DAT_004fecc8 + iVar7 * 4)) / (DAT_004f7200 + 7) + -0x96;
    }
  }
  if ((DAT_005363c4 == 1) || (DAT_0053652c == 1)) {
    param_1 = iVar8;
    if (*(int *)(&DAT_004fecc8 + iVar7 * 4) <= DAT_004f7200 + 0xc) {
      param_1 = ((iVar8 + 0x96) * *(int *)(&DAT_004fecc8 + iVar7 * 4)) / (DAT_004f7200 + 0xc) +
                -0x96;
    }
  }
  if (DAT_005363b8 == 1) {
    param_1 = iVar8;
    if (*(int *)(&DAT_004fecc8 + iVar7 * 4) <= DAT_004f7200 + 0x12) {
      param_1 = ((iVar8 + 0x96) * *(int *)(&DAT_004fecc8 + iVar7 * 4)) / (DAT_004f7200 + 0x12) +
                -0x96;
    }
  }
  if (DAT_005363bc == 1) {
    if ((int)(&DAT_004fb380)[iVar7] < 10) {
      iVar9 = *(int *)(&DAT_004fecc8 + iVar7 * 4);
      iVar8 = (iVar8 << 3) / 0xb;
      if (iVar9 <= DAT_004f7200 + 0x1e) {
        iVar8 = ((iVar8 + 0x50) * iVar9) / (DAT_004f7200 + 0x1e) + -0x50;
      }
    }
    else {
      iVar9 = *(int *)(&DAT_004fecc8 + iVar7 * 4);
      if (iVar9 <= DAT_004f7200 + 0x19) {
        iVar8 = ((iVar8 + 0x8c) * iVar9) / (DAT_004f7200 + 0x19) + -0x8c;
      }
    }
    param_1 = iVar8;
    if (0xb6 - *(int *)(&DAT_004fae60 + iVar7 * 4) <= iVar9) {
      param_1 = iVar8 / 2;
    }
  }
  if ((param_1 < 10) && (DAT_004f7200 + -10 < *(int *)(&DAT_004fecc8 + iVar7 * 4))) {
    param_1 = 10;
  }
  iVar8 = 0;
  if (0 < *(int *)(&DAT_005350d8 + iVar7 * 4)) {
    if (((DAT_004da190 == 2) || (DAT_005364c8 == 1)) || (iVar8 = 0x96, DAT_005364c4 == 1)) {
      iVar8 = 0x4b;
    }
    if (iVar7 <= DAT_004da140) {
      FUN_0043c140(iVar7);
      if (((DAT_004da190 == 2) || (DAT_005364c8 == 1)) || (DAT_005364c4 == 1)) {
        iVar8 = *(int *)(&DAT_00535f68 + iVar7 * 4) * -2 + 0x4b;
      }
      else {
        iVar8 = (0x32 - *(int *)(&DAT_00535f68 + iVar7 * 4)) * 3 +
                *(int *)(&DAT_004fbab0 + iVar7 * 4) * -100;
      }
    }
  }
  iVar9 = *(int *)(&DAT_004fecc8 + iVar7 * 4);
  if (iVar9 < DAT_004f7200 + -10) {
    param_1 = 3;
  }
  if ((iVar7 <= DAT_004da140) && (iVar10 = *(int *)(&DAT_00500380 + iVar7 * 4), -1 < iVar10)) {
    *(int *)(&DAT_00512278 + iVar7 * 4) = iVar10;
    if ((iVar9 < 0x5b) || (DAT_005363bc != 0)) {
      iVar9 = 100;
    }
    else {
      iVar9 = (0x8c - iVar9) * 2;
    }
    if (iVar9 < iVar10) {
      *(int *)(&DAT_00512278 + iVar7 * 4) = iVar9;
    }
    if (*(int *)(&DAT_00512278 + iVar7 * 4) < 0) {
      *(undefined4 *)(&DAT_00512278 + iVar7 * 4) = 0;
    }
    if ((DAT_005363bc == 1) && (0x50 < iVar10)) {
      *(undefined4 *)(&DAT_00512278 + iVar7 * 4) = 0x5a;
      param_1 = 3;
    }
    else {
      param_1 = ((100 - *(int *)(&DAT_00512278 + iVar7 * 4)) * param_1) / 100;
    }
  }
  if ((((0 < *(int *)(&DAT_005350d8 + iVar7 * 4)) && (1 < DAT_004da190)) && (DAT_005364cc == 0)) &&
     (DAT_004da190 != 9)) {
    param_1 = param_1 + iVar8;
  }
  if (param_1 < 1) {
    param_1 = 1;
  }
  uVar12 = *(uint *)(&DAT_004fc2c0 + iVar7 * 4);
  if ((int)uVar12 < 1) {
    local_2c = 0;
  }
  else {
    local_2c = FUN_0041bc20((uVar12 ^ (int)uVar12 >> 0x1f) - ((int)uVar12 >> 0x1f));
  }
  fVar15 = (float10)fcos((float10)local_2c * (float10)_DAT_004cc568);
  local_8 = (double)param_1 * (double)fVar14 * _DAT_004cca70;
  if ((DAT_0053652c == 1) && (*(int *)(&DAT_004fc2c0 + iVar7 * 4) < 10)) {
    local_8 = local_8 * _DAT_004cc7b8;
  }
  if (iVar7 <= DAT_004da140) {
    iVar8 = FUN_0041bc20(*(int *)(&DAT_004fe818 + iVar7 * 4));
    fVar14 = (float10)fcos((float10)iVar8 * (float10)_DAT_004cc568);
    fVar15 = (float10)fcos(((fVar14 * (float10)local_8) / (float10)local_10) *
                           (float10)_DAT_004cc568);
  }
  local_8 = (double)((float10)DAT_004f8d70 * fVar15 * fVar15 * (float10)local_8);
  if (1 < *(int *)(&DAT_004fe8a8 + iVar7 * 4)) {
    local_8 = local_8 * _DAT_004cc4f8;
  }
  iVar9 = FUN_0041bc20(*(int *)(&DAT_004fe818 + iVar7 * 4));
  iVar8 = DAT_004f4200;
  fVar14 = (float10)fcos((float10)iVar9 * (float10)_DAT_004cc568);
  param_1 = (int)(longlong)((fVar14 * (float10)local_8) / (float10)local_10) - local_28;
  if ((param_1 < 0) && (*(int *)(&DAT_004fecc8 + iVar7 * 4) < 0xa1)) {
    param_1 = 0;
  }
  iVar9 = *(int *)(&DAT_004fecc8 + iVar7 * 4);
  if ((iVar9 < 0x3c) && (param_1 < 5)) {
    param_1 = 5;
  }
  if (0x46 < param_1) {
    param_1 = 0x46;
  }
  if (((DAT_004da140 < iVar7) || (*(int *)(&DAT_00500380 + iVar7 * 4) < 0)) &&
     (*(undefined4 *)(&DAT_00512278 + iVar7 * 4) = 0, iVar8 < param_1)) {
    iVar10 = (iVar8 * 100) / param_1;
    param_1 = iVar8 + -1;
    *(int *)(&DAT_00512278 + iVar7 * 4) = (100 - iVar10) / 2;
  }
  if ((DAT_0053652c == 1) && ((double)param_1 < _DAT_004cc828)) {
    param_1 = 0xb;
  }
  if (iVar9 < 0x3d) {
    if (((DAT_004da190 == 7) || (DAT_004da190 == 8)) && (DAT_005364c8 == 0)) {
      iVar10 = *(int *)(&DAT_00535e40 + iVar7 * 4);
      iVar11 = 0x2aaaaaab;
      iVar8 = *(int *)(&DAT_00512278 + iVar7 * 4);
    }
    else {
      iVar10 = *(int *)(&DAT_00535e40 + iVar7 * 4);
      iVar11 = 0x55555556;
      iVar8 = *(int *)(&DAT_00512278 + iVar7 * 4);
    }
    iVar8 = (int)((ulonglong)((longlong)iVar11 * (longlong)iVar8) >> 0x20);
    iVar8 = (iVar9 * 10) / 0x3c + ((5 - iVar10) * 2 - (iVar8 - (iVar8 >> 0x1f)));
  }
  else {
    iVar8 = 0x16 - (iVar9 + -0x3c) / 6;
  }
  if (((0x3c < iVar9) && (iVar9 <= 0xb4 - *(int *)(&DAT_004fae60 + iVar7 * 4))) &&
     ((DAT_005363b8 == 1 || (DAT_005363bc == 1)))) {
    iVar8 = 0x16;
  }
  if ((0x14 < local_20) && (iVar9 < 0x3c)) {
    iVar10 = (int)((ulonglong)((longlong)(local_20 + -0x14) * 0x55555555) >> 0x20) -
             (local_20 + -0x14);
    iVar8 = iVar8 + ((iVar10 >> 1) - (iVar10 >> 0x1f));
  }
  if (*(int *)(&DAT_005350d8 + iVar7 * 4) < 1) {
    if (((iVar7 <= DAT_004da140) && (6 < DAT_004da190)) && (DAT_004da190 < 9)) {
      iVar8 = (*(int *)(&DAT_004f7ee0 + iVar7 * 4) + -2) * 5 + iVar8;
    }
  }
  else {
    iVar8 = iVar8 + -8;
  }
  if (1 < *(int *)(&DAT_004fe8a8 + iVar7 * 4)) {
    if ((0x14 < *(int *)(&DAT_004fdfe8 + iVar7 * 4)) && (DAT_004da140 < iVar7)) {
      iVar8 = iVar8 + -6;
    }
    if (((1 < *(int *)(&DAT_004fe8a8 + iVar7 * 4)) && (0x14 < *(int *)(&DAT_004fdfe8 + iVar7 * 4)))
       && (iVar7 <= DAT_004da140)) {
      iVar8 = iVar8 + -4;
    }
  }
  if (iVar8 < 0) {
    iVar8 = 0;
  }
  local_2c = iVar8 + 0xc;
  if ((0x1d < local_20) && (iVar9 < 0x3c)) {
    local_2c = iVar8 + 6;
  }
  if (((local_20 == 0x14) && (iVar9 < 0x3c)) && (0xd < (int)(&DAT_004fb380)[iVar7])) {
    local_2c = local_2c + -4;
  }
  fVar14 = (float10)fsin(((float10)local_2c + (float10)local_18) * (float10)_DAT_004cc568);
  fVar14 = fVar14 * (float10)local_8 * (float10)_DAT_004cc580;
  if (((iVar7 <= DAT_004da140) && (0x50 < *(int *)(&DAT_00512278 + iVar7 * 4))) && (iVar9 < 0x23)) {
    fVar14 = (float10)_DAT_004cc650;
  }
  if ((DAT_004da190 == 7) || (DAT_004da190 == 8)) {
    fVar14 = ((float10)_DAT_004cc488 - (float10)*(int *)(&DAT_00512278 + iVar7 * 4)) * fVar14 *
             (float10)_DAT_004cc3f0;
  }
  local_10 = (double)(((0x5a - DAT_004feccc) * (&DAT_004fb380)[iVar7]) / 0xf);
  if ((5 < DAT_004da190) && (DAT_004da190 < 9)) {
    local_10 = local_10 * _DAT_004cc4f8;
  }
  local_8 = (double)DAT_004f7ecc;
  dVar4 = SQRT((double)DAT_004faa48) * _DAT_004cc580;
  dVar1 = (double)(fVar14 - (float10)local_10);
  dVar5 = (dVar4 * _DAT_004cc838) / local_8;
  if (((DAT_005364c0 == 1) || (DAT_005363c4 == 1)) && (0x5a < iVar9)) {
    dVar5 = (dVar4 * _DAT_004cc5a8) / local_8;
  }
  if ((DAT_0053652c == 1) && (0x5a < iVar9)) {
    dVar5 = (dVar4 * _DAT_004cca38) / local_8;
  }
  if (((DAT_005364d0 == 1) || (DAT_00536530 == 1)) && (0x5a < iVar9)) {
    dVar5 = (dVar4 * _DAT_004cca38) / local_8;
  }
  if (((DAT_005364c0 == 0) && (DAT_005363b8 == 1)) && (0x5a < iVar9)) {
    dVar5 = (dVar4 * _DAT_004cca38) / local_8;
  }
  local_10 = dVar1;
  if (_DAT_004cc658 < dVar1) {
    local_10 = SQRT(dVar1);
  }
  if (dVar1 < _DAT_004cc658) {
    local_10 = 0.0;
  }
  if (dVar1 == _DAT_004cc658) {
    local_10 = 0.0;
  }
  if (_DAT_004cca78 < local_10) {
    dVar1 = dVar4 - (dVar5 - dVar4) * SQRT(local_10 - _DAT_004cca78) * _DAT_004cca90;
  }
  else {
    dVar1 = dVar4 * _DAT_004cc7b0 - dVar4 * local_10 * _DAT_004cca80 * _DAT_004cca88;
  }
  if (local_10 < _DAT_004cc7a0) {
    dVar1 = local_10 * local_10 * _DAT_004cc3f0;
  }
  dVar1 = (double)*(int *)(&DAT_004fc3e0 + iVar7 * 4) * dVar1 * _DAT_004cc3f0;
  if (((DAT_004da140 < iVar7) &&
      (uVar12 = iVar9 - DAT_004feccc >> 0x1f, (int)((iVar9 - DAT_004feccc ^ uVar12) - uVar12) < 0x1e
      )) && (((local_8 = _DAT_004fe188 * _DAT_004cca98, local_8 < dVar1 &&
              ((dVar4 * _DAT_004cc630 < _DAT_004fe188 && (DAT_004fe8ac == 0)))) &&
             (DAT_005116e4 == 0)))) {
    dVar1 = local_8;
  }
  if (iVar7 == 1) {
    _DAT_00522fdc = (undefined4)(longlong)(_DAT_004fe188 * _DAT_004cc488);
  }
  if (DAT_004da140 < iVar7) {
    if (iVar9 <= DAT_004f7200) {
      local_8 = _DAT_004ccaa0;
      if (DAT_005364c4 == 1) {
        local_8 = _DAT_004cc7b8;
      }
      if (DAT_005364d8 == 1) {
        local_8 = _DAT_004cc940;
      }
      if (DAT_005364d4 == 1) {
        local_8 = _DAT_004ccaa8;
      }
      if (DAT_0053652c == 1) {
        local_8 = _DAT_004ccab0;
      }
      if ((DAT_00536528 == 1) && (local_8 = _DAT_004ccaa0, DAT_00522ad0 < 0xb)) {
        local_8 = _DAT_004cc930;
      }
      if (DAT_00536530 == 1) {
        local_8 = _DAT_004ccab8;
      }
      if (DAT_004da190 == 8) {
        local_8 = _DAT_004ccab8;
      }
      if (DAT_004da190 == 6) {
        local_8 = _DAT_004ccac0;
      }
    }
    if (((DAT_004f7200 < iVar9) && (iVar9 <= DAT_004f7200 + 5)) &&
       (local_8 = _DAT_004cc650, DAT_004da190 == 6)) {
      local_8 = _DAT_004ccaa0;
    }
    if (DAT_004f7200 + 5 < iVar9) {
      if (iVar9 < 0x5a) {
        if (((DAT_004da190 == 6) || (DAT_005363c0 == 1)) ||
           ((DAT_005364d4 == 1 || (local_8 = _DAT_004cc650, DAT_005364d8 == 1)))) {
          local_8 = _DAT_004ccaa0;
        }
        goto LAB_0043b372;
      }
LAB_0043b377:
      if (((DAT_004da190 == 6) || (DAT_005363c0 == 1)) ||
         ((DAT_005364d4 == 1 || (local_8 = _DAT_004cc650, DAT_005364d8 == 1)))) {
        local_8 = _DAT_004ccaa0;
      }
      if (DAT_00536528 == 1) {
        local_8 = _DAT_004cc650;
      }
      if (DAT_0053652c == 1) {
        local_8 = _DAT_004cc940;
      }
      if (DAT_00536530 == 1) {
        local_8 = _DAT_004ccac8;
      }
    }
    else {
LAB_0043b372:
      if (0x59 < iVar9) goto LAB_0043b377;
    }
    if (0xb2 - *(int *)(&DAT_004fae60 + iVar7 * 4) <= iVar9) {
      if (((DAT_004da190 == 6) || (DAT_005364d8 == 1)) ||
         (local_8 = _DAT_004cc650, DAT_005364c8 == 1)) {
        local_8 = _DAT_004ccab8;
      }
      if (((DAT_005363c0 == 1) || (DAT_005364d4 == 1)) ||
         ((DAT_005364c0 == 1 || (DAT_005364cc == 1)))) {
        local_8 = _DAT_004ccaa0;
      }
      if (DAT_004da190 == 8) {
        local_8 = _DAT_004ccac0;
      }
      if (DAT_00536528 == 1) {
        local_8 = _DAT_004cc650;
      }
      if (DAT_0053652c == 1) {
        local_8 = _DAT_004cc940;
      }
      if (DAT_00536530 == 1) {
        local_8 = _DAT_004ccac8;
      }
    }
    if (((DAT_004da190 == 1) || (DAT_004da190 == 2)) ||
       ((DAT_004da190 == 3 || ((DAT_004da190 == 4 || (DAT_004da190 == 5)))))) {
      local_8 = _DAT_004ccad0;
    }
    if (DAT_00536530 == 1) {
      local_8 = local_8 * _DAT_004ccab8;
    }
  }
  else {
    local_8 = _DAT_004cc650;
    if (DAT_00536534 == 1) {
      local_8 = _DAT_004cc930;
    }
  }
  local_8 = local_8 * dVar1;
  if ((iVar7 <= DAT_004da140) && (-1 < *(int *)(&DAT_00500380 + iVar7 * 4))) {
    local_28 = 0;
    if (DAT_004f4200 + 2 < param_1) {
      local_28 = (param_1 - DAT_004f4200) + 2;
      local_28 = local_28 * local_28;
    }
    if (DAT_004da190 + 0x1e < local_28) {
      local_28 = DAT_004da190 + 0x1e;
    }
    if (DAT_005364c8 == 1) {
      local_28 = local_28 / 2;
    }
    local_8 = local_8 - (double)local_28;
  }
  FUN_0043c1e0(iVar7);
  dVar1 = (double)DAT_004f7ecc * _DAT_004cc4f8;
  if (DAT_005363bc == 1) {
    dVar1 = (double)DAT_004f7ecc;
  }
  bVar13 = DAT_004f8cd0 == *(int *)(&DAT_00535620 + iVar7 * 4);
  *(double *)(&DAT_004fe180 + iVar7 * 8) =
       ((local_8 - *(double *)(&DAT_004fe180 + iVar7 * 8)) * _DAT_00523378) / dVar1 +
       *(double *)(&DAT_004fe180 + iVar7 * 8);
  if (bVar13) {
    *(undefined4 *)(&DAT_004fe180 + iVar7 * 8) = 0;
    *(undefined4 *)(&DAT_004fe184 + iVar7 * 8) = 0;
  }
  if (_DAT_004ccad8 < *(double *)(&DAT_004fe180 + iVar7 * 8)) {
    *(undefined4 *)(&DAT_004fe180 + iVar7 * 8) = 0;
    *(undefined4 *)(&DAT_004fe184 + iVar7 * 8) = 0x406f4000;
  }
  if (*(double *)(&DAT_004fe180 + iVar7 * 8) < _DAT_004cc588) {
    *(undefined4 *)(&DAT_004fe180 + iVar7 * 8) = 0;
    *(undefined4 *)(&DAT_004fe184 + iVar7 * 8) = 0xc0240000;
  }
  iVar8 = DAT_004da140;
  *(int *)(&DAT_004fdfe8 + iVar7 * 4) = (int)(longlong)*(double *)(&DAT_004fe180 + iVar7 * 8);
  *(int *)(&DAT_004fc2c0 + iVar7 * 4) = (iVar3 + param_1) / 2;
  if (iVar8 < iVar7) {
    if (_DAT_005359f0 < _DAT_004cc658) {
      iVar8 = FUN_0043c2c0(iVar7);
      iVar9 = (iVar8 * *(int *)(&DAT_004fdfe8 + iVar7 * 4)) / 100;
      *(int *)(&DAT_004fdfe8 + iVar7 * 4) = iVar9;
      if (iVar9 < 0x19) {
        *(undefined4 *)(&DAT_00512278 + iVar7 * 4) = 0x28;
      }
      if (0x1e < *(int *)(&DAT_00512278 + iVar7 * 4)) {
        *(undefined4 *)(&DAT_004fc2c0 + iVar7 * 4) = 7;
      }
      iVar8 = DAT_004da140;
      if (iVar2 + 6 < iVar9) {
        *(int *)(&DAT_004fdfe8 + iVar7 * 4) = iVar2 + 6;
        iVar8 = DAT_004da140;
      }
    }
    if (iVar7 <= iVar8) goto LAB_0043b6a0;
  }
  else {
LAB_0043b6a0:
    if (*(double *)(&DAT_004ffcb8 + iVar7 * 8) < (double)DAT_004da1fc) {
      DAT_004fdfec = 1;
      *(undefined4 *)(&DAT_005116e0 + iVar7 * 4) = 10;
    }
    if (iVar7 <= iVar8) goto LAB_0043b6e4;
  }
  if (*(double *)(&DAT_004ffcb8 + iVar7 * 8) < (double)DAT_004da1fc) {
    *(undefined4 *)(&DAT_004fdfe8 + iVar7 * 4) = 1;
  }
LAB_0043b6e4:
  if ((DAT_004fc2c4 <= DAT_004f4200 + 1) || (DAT_004fb21c = 1, DAT_00500384 < 0)) {
    DAT_004fb21c = 0;
  }
  if ((iVar8 < iVar7) && (-1 < *(int *)(&DAT_004faef0 + iVar7 * 4))) {
    *(int *)(&DAT_004fdfe8 + iVar7 * 4) = *(int *)(&DAT_004faef0 + iVar7 * 4) / 2;
  }
  iVar8 = DAT_004da190;
  *(undefined4 *)(&DAT_004faef0 + iVar7 * 4) = 0xffffffff;
  uVar12 = ((iVar8 < 7) - 1 & 3) + 5;
  if (iVar8 < 3) {
    uVar12 = 3;
  }
  if ((DAT_005363b8 == 1) || (DAT_005363c4 == 1)) {
    uVar12 = 8;
  }
  if (DAT_005363bc == 1) {
    uVar12 = 10;
  }
  iVar10 = (int)(longlong)dVar4;
  iVar9 = *(int *)(&DAT_004f4350 + iVar7 * 4);
  if (DAT_004f8cd0 == iVar9) {
    *(int *)(&DAT_00535ed8 + iVar7 * 4) = iVar2;
  }
  if (((iVar8 == 1) && (DAT_005363bc == 0)) && (DAT_005363cc == 0)) {
    bVar13 = true;
  }
  else {
    bVar13 = false;
  }
  if (DAT_004da190 == 2) {
    bVar13 = true;
  }
  if (*(int *)(&DAT_004fecc8 + iVar7 * 4) < DAT_004f7200 + 5) {
    if ((iVar9 + 1 < DAT_004f8cd0) && (DAT_004f8cd0 <= (int)(uVar12 / 2 + iVar9))) {
      if ((DAT_005363bc == 1) || (iVar2 < 5)) {
        iVar10 = 0xf;
      }
      if (*(int *)(&DAT_00535ed8 + iVar7 * 4) < iVar10) {
        iVar10 = *(int *)(&DAT_00535ed8 + iVar7 * 4);
      }
      if (bVar13) {
        *(int *)(&DAT_004fdfe8 + iVar7 * 4) = (iVar10 * 4) / 5;
      }
      else {
        *(int *)(&DAT_004fdfe8 + iVar7 * 4) = (int)(iVar10 * 3 + (iVar10 * 3 >> 0x1f & 3U)) >> 2;
      }
      *(double *)(&DAT_004fe180 + iVar7 * 8) = (double)*(int *)(&DAT_004fdfe8 + iVar7 * 4);
    }
    if (((int)(uVar12 / 2 + iVar9) < DAT_004f8cd0) && (DAT_004f8cd0 <= (int)(uVar12 + iVar9))) {
      if ((DAT_005363bc == 1) || (iVar2 < 5)) {
        iVar10 = 0x19;
      }
      if (*(int *)(&DAT_00535ed8 + iVar7 * 4) < iVar10) {
        iVar10 = *(int *)(&DAT_00535ed8 + iVar7 * 4);
      }
      if (bVar13) {
        iVar8 = (iVar10 * 6) / 7;
      }
      else {
        iVar8 = (iVar10 * 5) / 6;
      }
      *(int *)(&DAT_004fdfe8 + iVar7 * 4) = iVar8;
      *(double *)(&DAT_004fe180 + iVar7 * 8) = (double)*(int *)(&DAT_004fdfe8 + iVar7 * 4);
    }
    if ((int)(uVar12 + iVar9) < DAT_004f8cd0) {
      *(undefined4 *)(&DAT_004f4a70 + iVar7 * 4) = 0;
    }
  }
  if ((DAT_005363bc == 1) && (*(int *)(&DAT_00523938 + iVar7 * 4) == 1)) {
    if (0x1d < *(int *)(&DAT_004fdfe8 + iVar7 * 4)) {
      *(undefined4 *)(&DAT_004fdfe8 + iVar7 * 4) = 0x1e;
    }
    if (iVar9 + 6 < DAT_004f8cd0) {
      *(undefined4 *)(&DAT_00523938 + iVar7 * 4) = 0;
    }
  }
  if (iVar7 == 1) {
    fVar14 = (float10)fcos((float10)DAT_004feccc * (float10)_DAT_004cc568);
    DAT_004fe178 = (undefined4)(longlong)(fVar14 * (float10)_DAT_004fe188 * (float10)_DAT_004cc580);
  }
  if ((0 < *(int *)(&DAT_004fe638 + iVar7 * 4)) &&
     (fVar14 = FUN_00439e80(iVar7,(double)*(int *)(&DAT_004fb548 + iVar7 * 4),
                            (double)*(int *)(&DAT_00522af0 + iVar7 * 4)),
     fVar14 < (float10)_DAT_004ccae0)) {
    iVar8 = DAT_005362d4 + -0x2d;
    iVar9 = (&DAT_00522b90)[iVar7] - DAT_004f7200;
    *(undefined4 *)(&DAT_004fe180 + iVar7 * 8) = 0;
    *(undefined4 *)(&DAT_004fe184 + iVar7 * 8) = 0;
    *(undefined4 *)(&DAT_004fdfe8 + iVar7 * 4) = 0;
    *(undefined4 *)(&DAT_004fc2c0 + iVar7 * 4) = 5;
    *(int *)(&DAT_00535740 + iVar7 * 4) = iVar9;
    iVar8 = FUN_0041bc20(iVar8);
    *(int *)(&DAT_00535740 + iVar7 * 4) = iVar8;
    *(undefined4 *)(&DAT_00511620 + iVar7 * 4) = 0;
    *(undefined4 *)(&DAT_004f6a68 + iVar7 * 4) = 0;
    *(undefined4 *)(&DAT_00522ff0 + iVar7 * 4) = 1;
    *(undefined4 *)(&DAT_005350d8 + iVar7 * 4) = 0;
    *(undefined4 *)(&DAT_00512278 + iVar7 * 4) = 0x1e;
    if (iVar7 == 1) {
      _DAT_004fe938 = (double)DAT_00535744;
    }
  }
  iVar8 = DAT_005363b8;
  if (DAT_005363b8 == 0) {
    iVar9 = DAT_004da190 / 2;
    if (*(double *)(&DAT_004ffcb8 + iVar7 * 8) < (double)(iVar9 + 3)) {
      *(undefined4 *)(&DAT_004fe180 + iVar7 * 8) = 0;
      *(undefined4 *)(&DAT_004fdfe8 + iVar7 * 4) = 5;
      *(undefined4 *)(&DAT_004fe184 + iVar7 * 8) = 0x40140000;
      *(undefined4 *)(&DAT_005116e0 + iVar7 * 4) = 10;
    }
    if (*(double *)(&DAT_004ffcb8 + iVar7 * 8) < (double)(iVar9 + 1)) {
      *(undefined4 *)(&DAT_004fe180 + iVar7 * 8) = 0;
      *(undefined4 *)(&DAT_004fdfe8 + iVar7 * 4) = 1;
      *(undefined4 *)(&DAT_004fe184 + iVar7 * 8) = 0x40140000;
      *(undefined4 *)(&DAT_005116e0 + iVar7 * 4) = 10;
    }
  }
  if (iVar8 == 1) {
    if (*(double *)(&DAT_004ffcb8 + iVar7 * 8) < _DAT_004cc728) {
      *(undefined4 *)(&DAT_004fe180 + iVar7 * 8) = 0;
      *(undefined4 *)(&DAT_004fdfe8 + iVar7 * 4) = 5;
      *(undefined4 *)(&DAT_004fe184 + iVar7 * 8) = 0x40140000;
      *(undefined4 *)(&DAT_005116e0 + iVar7 * 4) = 10;
    }
    if (*(double *)(&DAT_004ffcb8 + iVar7 * 8) < _DAT_004cc710) {
      *(undefined4 *)(&DAT_004fe180 + iVar7 * 8) = 0;
      *(undefined4 *)(&DAT_004fdfe8 + iVar7 * 4) = 1;
      *(undefined4 *)(&DAT_004fe184 + iVar7 * 8) = 0x3ff00000;
      *(undefined4 *)(&DAT_005116e0 + iVar7 * 4) = 10;
    }
  }
  return;
}

