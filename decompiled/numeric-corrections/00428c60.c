
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00428c60(int param_1)

{
  double dVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  float10 fVar13;
  float10 fVar14;
  double dVar15;
  int local_2c;
  double local_28;
  double local_10;
  
  iVar3 = param_1;
  iVar11 = *(int *)(&DAT_004a7060 + param_1 * 4);
  iVar8 = *(int *)(&DAT_004a6ec8 + param_1 * 4);
  DAT_004abb74 = (uint)(DAT_004a4388 == 1);
  DAT_004a7644 = 0x1e;
  if (DAT_004a438c == 1) {
    DAT_004abb78 = 1;
  }
  else if (DAT_00491140 == 2) {
    DAT_004abb78 = 0;
  }
  if ((DAT_004a60a0 == 1) && (DAT_004ac9ac == 0)) {
    *(undefined4 *)(&DAT_004a4510 + param_1 * 8) = *(undefined4 *)(&DAT_004a7f28 + param_1 * 8);
    *(undefined4 *)(&DAT_004a4514 + param_1 * 8) = *(undefined4 *)(&DAT_004a7f2c + param_1 * 8);
  }
  if (DAT_004a864c == 1) {
    FUN_00420b70((int)(longlong)*(double *)(&DAT_004a49e8 + param_1 * 8),
                 (int)(longlong)*(double *)(&DAT_004a4ae0 + param_1 * 8),param_1);
  }
  else {
    FUN_00420c40((int)(longlong)*(double *)(&DAT_004a49e8 + param_1 * 8),
                 (int)(longlong)*(double *)(&DAT_004a4ae0 + param_1 * 8),param_1);
  }
  if (param_1 == 1) {
    _DAT_004aa718 = (undefined4)(longlong)_DAT_004a7f30;
  }
  dVar15 = FUN_00429df0(*(int *)(&DAT_004a7060 + param_1 * 4),param_1);
  iVar4 = DAT_004a5b80;
  if ((param_1 <= DAT_00491140) &&
     (*(int *)(&DAT_004abf18 + param_1 * 4) + DAT_004a7644 < DAT_004a5b80)) {
    *(undefined4 *)(&DAT_004a89c0 + param_1 * 4) = 0;
  }
  if (iVar4 < -0x96) {
    *(undefined4 *)(&DAT_004a89c0 + param_1 * 4) = 0;
  }
  uVar10 = *(int *)(&DAT_004ac018 + param_1 * 4) - *(int *)(&DAT_004aa5b0 + param_1 * 4) >> 0x1f;
  iVar4 = (*(int *)(&DAT_004ac018 + param_1 * 4) - *(int *)(&DAT_004aa5b0 + param_1 * 4) ^ uVar10) -
          uVar10;
  *(int *)(&DAT_004a7bc8 + param_1 * 4) = iVar4;
  if (0xb4 < iVar4) {
    *(int *)(&DAT_004a7bc8 + param_1 * 4) = 0x168 - iVar4;
  }
  FUN_00429f40(param_1);
  iVar6 = *(int *)(&DAT_004a7bc8 + param_1 * 4);
  iVar4 = ((iVar6 + -0x28) * 0x5a) / 0x8c + -3;
  *(int *)(&DAT_004a77e8 + param_1 * 4) = iVar4;
  if (iVar4 < 5) {
    *(undefined4 *)(&DAT_004a77e8 + param_1 * 4) = 5;
  }
  iVar5 = DAT_00491188;
  iVar4 = DAT_00491140;
  if ((DAT_00491188 == 2) || (DAT_004ab180 = 0x69, DAT_00491188 == 9)) {
    DAT_004ab180 = 0x8c;
  }
  if ((((DAT_00491188 == 8) || (DAT_00491188 == 10)) || (DAT_004ac90c == 1)) || (DAT_004ac908 == 1))
  {
    DAT_004ab180 = 0x61;
  }
  iVar7 = DAT_004ab180;
  if (DAT_00491140 < param_1) {
    iVar9 = ((0x3b < iVar6) - 1 & 0xfffffff6) + 0x1e;
    local_28 = (double)CONCAT44(local_28._4_4_,iVar9);
    if ((iVar6 < 0x5a) && (0xd < *(int *)(&DAT_004a6338 + param_1 * 4))) {
      iVar9 = 10;
      local_28 = (double)CONCAT44(local_28._4_4_,10);
    }
    if (0 < *(int *)(&DAT_004a42f0 + param_1 * 4)) {
      *(int *)(&DAT_004a42f0 + param_1 * 4) = *(int *)(&DAT_004a42f0 + param_1 * 4) + -1;
    }
    if ((((iVar7 < iVar6) && (1 < iVar5)) &&
        ((iVar5 != 9 &&
         (((0x5a < *(int *)(&DAT_004abc00 + param_1 * 4) && (0 < DAT_004a5b80)) &&
          (*(int *)(&DAT_004a89c0 + param_1 * 4) != 10)))))) &&
       (*(int *)(&DAT_004a76d0 + param_1 * 4) == 0)) {
      if (*(int *)(&DAT_004a42f0 + param_1 * 4) == 0) {
        if (*(int *)(&DAT_004abb70 + param_1 * 4) == 0) {
          *(undefined4 *)(&DAT_004a42f0 + param_1 * 4) = 2;
        }
        *(undefined4 *)(&DAT_004abb70 + param_1 * 4) = 1;
      }
    }
    else if (*(int *)(&DAT_004a42f0 + param_1 * 4) == 0) {
      *(undefined4 *)(&DAT_004abb70 + param_1 * 4) = 0;
    }
    if ((*(int *)(&DAT_004a5420 + param_1 * 4) < 3) && (DAT_00491194 != 8)) {
      *(undefined4 *)(&DAT_004abb70 + param_1 * 4) = 0;
    }
  }
  else {
    iVar9 = local_28._0_4_;
  }
  if (param_1 <= iVar4) {
    iVar9 = *(int *)(&DAT_004a7768 + param_1 * 4) * 10;
    local_28 = (double)CONCAT44(local_28._4_4_,iVar9);
  }
  iVar9 = iVar9 + 0x78;
  if (((6 < iVar5) && (param_1 <= iVar4)) &&
     ((iVar5 < 9 && (*(int *)(&DAT_004abb70 + param_1 * 4) < 1)))) {
    iVar9 = iVar9 + *(int *)(&DAT_004a4ef8 + param_1 * 4) * -0x19 + 0x19;
  }
  if (iVar6 < 0x3d) {
    if (iVar5 < 8) {
      local_2c = ((iVar9 + 0x50) * iVar6) / 0x3c + -0x50;
    }
    else {
      local_2c = ((iVar9 + 0x3c) * iVar6) / 0x3c + -0x3c;
    }
  }
  else {
    local_2c = iVar9 - (iVar6 + -0x3c) / 6;
  }
  if (((iVar5 < 6) || (DAT_004ac900 == 1)) && (local_2c = iVar9, iVar6 < 0x47)) {
    local_2c = ((iVar9 + 0x46) * iVar6) / 0x46 + -0x46;
  }
  if (DAT_004ac904 == 1) {
    if (*(int *)(&DAT_004a6338 + param_1 * 4) < 10) {
      iVar9 = (iVar9 << 3) / 0xb;
      local_2c = iVar9;
      if (iVar6 <= DAT_004a4eb0 + 0x1e) {
        local_2c = ((iVar9 + 0x50) * iVar6) / (DAT_004a4eb0 + 0x1e) + -0x50;
      }
    }
    else {
      local_2c = iVar9;
      if (iVar6 <= DAT_004a4eb0 + 0x19) {
        local_2c = ((iVar9 + 0x8c) * iVar6) / (DAT_004a4eb0 + 0x19) + -0x8c;
      }
    }
  }
  if ((DAT_004ac90c == 1) && (local_2c = iVar9, iVar6 <= DAT_004a4eb0 + 0xc)) {
    local_2c = ((iVar9 + 0x96) * iVar6) / (DAT_004a4eb0 + 0xc) + -0x96;
  }
  if (iVar6 < (DAT_004a4eb0 * 2) / 3) {
    local_2c = 0;
  }
  iVar4 = *(int *)(&DAT_004abb70 + param_1 * 4);
  uVar10 = (iVar4 < 1) - 1 & 0x96;
  if (DAT_00491140 < param_1) {
    if (((iVar6 < 0x8c) && (0 < iVar4)) && (*(int *)(&DAT_004a4170 + param_1 * 4) == 3)) {
      uVar10 = uVar10 + 0x3c;
    }
    if (param_1 <= DAT_00491140) goto LAB_004290f6;
  }
  else {
LAB_004290f6:
    *(undefined4 *)(&DAT_004ac5f0 + param_1 * 4) = 0;
  }
  if ((0 < iVar4) && (param_1 <= DAT_00491140)) {
    FUN_0042a280(param_1);
    uVar10 = *(int *)(&DAT_004ac5f0 + param_1 * 4) * -4 + 0x96;
    if ((*(int *)(&DAT_004a4170 + param_1 * 4) == 3) &&
       (*(int *)(&DAT_004a7bc8 + param_1 * 4) < 0x8c)) {
      uVar10 = *(int *)(&DAT_004ac5f0 + param_1 * 4) * -4 + 0xd2;
    }
  }
  if (((DAT_00491188 == 2) || (DAT_00491188 == 9)) && (0 < *(int *)(&DAT_004abb70 + param_1 * 4))) {
    uVar10 = 0x4b;
    iVar4 = DAT_00491188;
    if (param_1 <= DAT_00491140) {
      FUN_0042a280(param_1);
      uVar10 = *(int *)(&DAT_004ac5f0 + param_1 * 4) * -2 + 0x4b;
      goto LAB_0042918a;
    }
  }
  else {
LAB_0042918a:
    iVar4 = DAT_00491188;
    if ((param_1 <= DAT_00491140) && (iVar6 = *(int *)(&DAT_004a85d0 + param_1 * 4), -1 < iVar6)) {
      *(int *)(&DAT_004a8aa8 + param_1 * 4) = iVar6;
      if ((*(int *)(&DAT_004a7bc8 + param_1 * 4) < 0x5b) || (DAT_004ac904 != 0)) {
        iVar5 = 100;
      }
      else {
        iVar5 = (0x8c - *(int *)(&DAT_004a7bc8 + param_1 * 4)) * 2;
      }
      if (iVar5 < iVar6) {
        *(int *)(&DAT_004a8aa8 + param_1 * 4) = iVar5;
      }
      if (*(int *)(&DAT_004a8aa8 + param_1 * 4) < 0) {
        *(undefined4 *)(&DAT_004a8aa8 + param_1 * 4) = 0;
      }
      if ((DAT_004ac904 == 1) && (0x50 < iVar6)) {
        local_2c = 3;
        *(undefined4 *)(&DAT_004a8aa8 + param_1 * 4) = 0x5a;
      }
      else {
        local_2c = ((100 - *(int *)(&DAT_004a8aa8 + param_1 * 4)) * local_2c) / 100;
      }
    }
  }
  local_2c = local_2c + uVar10;
  if (local_2c < 3) {
    local_2c = 3;
  }
  if (*(int *)(&DAT_004a7bc8 + param_1 * 4) < DAT_004a4eb0 + -10) {
    local_2c = 3;
  }
  uVar10 = *(uint *)(&DAT_004a6ec8 + param_1 * 4);
  if ((int)uVar10 < 1) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_00413cb0((uVar10 ^ (int)uVar10 >> 0x1f) - ((int)uVar10 >> 0x1f));
    iVar4 = DAT_00491188;
  }
  fVar13 = (float10)fcos((float10)param_1 * (float10)_DAT_00484d40);
  local_10 = (double)((float10)DAT_004a5b90 *
                      (float10)local_2c * (float10)dVar15 * fVar13 * (float10)_DAT_00484cc8 * fVar13
                     * (float10)_DAT_00484d48);
  if (1 < *(int *)(&DAT_004a7868 + iVar3 * 4)) {
    local_10 = local_10 * _DAT_00485198;
  }
  local_2c = ((9 - iVar4) * 5) / 2;
  if (iVar4 == 3) {
    local_2c = 0x16;
  }
  if (0x96 < *(int *)(&DAT_004a7bc8 + iVar3 * 4)) {
    local_2c = 0;
  }
  if (0xa0 < *(int *)(&DAT_004a7bc8 + iVar3 * 4)) {
    local_2c = local_2c + DAT_004a5b7c * -4;
  }
  if ((iVar3 <= DAT_00491140) && (iVar4 < 7)) {
    DAT_004ac9d4 = (*(int *)(&DAT_004a6338 + iVar3 * 4) < 0xd) + 5;
    if (DAT_004ac904 == 1) {
      DAT_004ac9d4 = 2;
    }
    if ((*(int *)(&DAT_004a3a18 + iVar3 * 4) <= DAT_004a5b80) &&
       (DAT_004a5b80 < *(int *)(&DAT_004a41f0 + iVar3 * 4) + DAT_004ac9d4)) {
      local_2c = iVar4 + -0xf;
    }
  }
  iVar6 = FUN_00413cb0(*(int *)(&DAT_004a77e8 + iVar3 * 4));
  iVar4 = DAT_004ac900;
  fVar13 = (float10)_DAT_00484f58;
  if ((DAT_00491188 == 1) && (fVar13 = (float10)_DAT_00484ea8, DAT_004ac914 == 0)) {
    fVar13 = (float10)_DAT_00484f48;
  }
  if (DAT_00491188 == 2) {
    fVar13 = (float10)_DAT_00484cf0;
  }
  if (DAT_004ac904 == 1) {
    fVar13 = (float10)_DAT_00484cf0;
  }
  if (DAT_00491188 == 8) {
    fVar13 = (float10)_DAT_004851a0;
  }
  if (DAT_004ac900 == 1) {
    fVar13 = (float10)_DAT_004851a8;
  }
  if (DAT_004ac908 == 1) {
    fVar13 = (float10)_DAT_00484d58;
  }
  fVar14 = (float10)fcos((float10)iVar6 * (float10)_DAT_00484d40);
  local_2c = (int)(longlong)((fVar14 * (float10)local_10) / fVar13) - local_2c;
  if ((local_2c < 0) && (*(int *)(&DAT_004a7bc8 + iVar3 * 4) < 0xa1)) {
    local_2c = 0;
  }
  iVar6 = *(int *)(&DAT_004a7bc8 + iVar3 * 4);
  if ((iVar6 < 0x3c) && (local_2c < 5)) {
    local_2c = 5;
  }
  if (0x46 < local_2c) {
    local_2c = 0x46;
  }
  iVar5 = ((DAT_00491188 < 6) - 1 & 7) + 0xf;
  if (DAT_004ac900 == 1) {
    iVar5 = 10;
  }
  if (((DAT_00491140 < iVar3) || (*(int *)(&DAT_004a85d0 + iVar3 * 4) < 0)) &&
     (*(undefined4 *)(&DAT_004a8aa8 + iVar3 * 4) = 0, iVar5 < local_2c)) {
    iVar7 = (iVar5 * 100) / local_2c;
    local_2c = iVar5 + -1;
    *(int *)(&DAT_004a8aa8 + iVar3 * 4) = (100 - iVar7) / 2;
  }
  if (iVar6 < 0x3d) {
    iVar7 = (iVar6 * 10) / 0x3c +
            (*(int *)(&DAT_004ac4e8 + iVar3 * 4) * -3 -
            ((int)(*(int *)(&DAT_004a8aa8 + iVar3 * 4) +
                  (*(int *)(&DAT_004a8aa8 + iVar3 * 4) >> 0x1f & 3U)) >> 2)) + 10;
  }
  else {
    iVar7 = 0x16 - (iVar6 + -0x3c) / 6;
    if ((iVar6 <= 0xb4 - *(int *)(&DAT_004a5f10 + iVar3 * 4)) &&
       ((iVar4 == 1 || (DAT_004ac904 == 1)))) {
      iVar7 = 0x16;
    }
  }
  if ((0x14 < local_28._0_4_) && (iVar6 < 0x3c)) {
    iVar4 = (int)((ulonglong)((longlong)(local_28._0_4_ + -0x14) * 0x55555555) >> 0x20) -
            (local_28._0_4_ + -0x14);
    iVar7 = iVar7 + ((iVar4 >> 1) - (iVar4 >> 0x1f));
  }
  if (*(int *)(&DAT_004abb70 + iVar3 * 4) < 1) {
    if (((iVar3 <= DAT_00491140) && (6 < DAT_00491188)) && (DAT_00491188 < 9)) {
      iVar7 = (*(int *)(&DAT_004a4ef8 + iVar3 * 4) + -2) * 5 + iVar7;
    }
  }
  else {
    iVar7 = iVar7 + -8;
  }
  if (1 < *(int *)(&DAT_004a7868 + iVar3 * 4)) {
    if ((0x14 < *(int *)(&DAT_004a7060 + iVar3 * 4)) && (DAT_00491140 < iVar3)) {
      iVar7 = iVar7 + -6;
    }
    if (((1 < *(int *)(&DAT_004a7868 + iVar3 * 4)) && (0x14 < *(int *)(&DAT_004a7060 + iVar3 * 4)))
       && (iVar3 <= DAT_00491140)) {
      iVar7 = iVar7 + -4;
    }
  }
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  param_1 = iVar7 + 0xc;
  if ((0x1d < local_28._0_4_) && (iVar6 < 0x3c)) {
    param_1 = iVar7 + 6;
  }
  if (((local_28._0_4_ == 0x14) && (iVar6 < 0x3c)) && (0xd < *(int *)(&DAT_004a6338 + iVar3 * 4))) {
    param_1 = param_1 + -4;
  }
  fVar13 = (float10)*(int *)(&DAT_004a77e8 + iVar3 * 4);
  if (DAT_00491140 < iVar3) {
    if (DAT_004ac908 == 1) {
      fVar13 = fVar13 - (float10)_DAT_00484dc0;
    }
    if ((DAT_00491188 == 6) || (DAT_00491188 == 2)) {
      fVar13 = fVar13 - (float10)_DAT_00484e40;
    }
  }
  fVar13 = (float10)fsin(((float10)param_1 + fVar13) * (float10)_DAT_00484d40);
  fVar13 = fVar13 * (float10)local_10 * (float10)_DAT_00484d58;
  if (((iVar3 <= DAT_00491140) && (0x50 < *(int *)(&DAT_004a8aa8 + iVar3 * 4))) && (iVar6 < 0x23)) {
    fVar13 = (float10)_DAT_00484e10;
  }
  if ((DAT_00491188 == 7) || (DAT_00491188 == 8)) {
    fVar13 = ((float10)_DAT_00485020 - (float10)*(int *)(&DAT_004a8aa8 + iVar3 * 4)) * fVar13 *
             (float10)_DAT_00484cc8;
  }
  fVar14 = (float10)((*(int *)(&DAT_004a6338 + iVar3 * 4) * (0x5a - DAT_004a7bcc)) / 0xf);
  if ((5 < DAT_00491188) && (DAT_00491188 < 9)) {
    fVar14 = fVar14 * (float10)_DAT_00484da8;
  }
  dVar15 = SQRT((double)DAT_004a5ba4) * _DAT_00484d58;
  fVar13 = fVar13 - fVar14;
  if ((float10)_DAT_00484e18 < fVar13) {
    local_28 = (double)SQRT(fVar13);
  }
  if (fVar13 < (float10)_DAT_00484e18) {
    local_28 = 0.0;
  }
  if (fVar13 == (float10)_DAT_00484e18) {
    local_28 = 0.0;
  }
  if (_DAT_004851b0 < local_28) {
    dVar1 = dVar15 - ((dVar15 * _DAT_00484fd8) / (double)DAT_004a4eec - dVar15) *
                     SQRT(local_28 - _DAT_004851b0) * _DAT_004851c8;
  }
  else {
    dVar1 = dVar15 * _DAT_00484f60 - dVar15 * local_28 * _DAT_004851b8 * _DAT_004851c0;
  }
  if (local_28 < _DAT_00484f48) {
    dVar1 = local_28 * local_28 * _DAT_00484cc8;
  }
  if ((((((DAT_00491140 < iVar3) &&
         (uVar10 = iVar6 - DAT_004a7bcc >> 0x1f,
         (int)((iVar6 - DAT_004a7bcc ^ uVar10) - uVar10) < 0x1e)) &&
        (iVar6 < 0xaa - *(int *)(&DAT_004a5f10 + iVar3 * 4))) &&
       ((DAT_004a5b80 < 10 && (_DAT_004a71d0 * _DAT_00484fd0 < dVar1)))) &&
      (dVar15 * _DAT_00484fd0 < _DAT_004a71d0)) && ((DAT_004a786c == 0 && (DAT_004a89c4 == 0)))) {
    dVar1 = _DAT_004a71d0 * _DAT_00484fd0;
  }
  if ((((DAT_00491188 < 7) || (8 < DAT_00491188)) || (iVar6 < 0x5b)) || (iVar3 <= DAT_00491140)) {
    dVar2 = (double)*(int *)(&DAT_004a6fc8 + iVar3 * 4);
  }
  else {
    dVar2 = (double)*(int *)(&DAT_004a6fc8 + iVar3 * 4) - _DAT_004851d0;
  }
  local_28 = dVar2 * dVar1 * _DAT_00484cc8;
  if ((iVar3 <= DAT_00491140) && (-1 < *(int *)(&DAT_004a85d0 + iVar3 * 4))) {
    param_1 = 0;
    if (iVar5 + 2 < local_2c) {
      iVar4 = (local_2c - iVar5) + 2;
      param_1 = iVar4 * iVar4;
    }
    if (DAT_00491188 + 0x1e < param_1) {
      param_1 = DAT_00491188 + 0x1e;
    }
    local_28 = local_28 - (double)param_1;
  }
  FUN_0042a2d0(iVar3);
  dVar1 = (double)DAT_004a4eec * _DAT_00484da8;
  if (DAT_004ac904 == 1) {
    dVar1 = (double)DAT_004a4eec;
  }
  bVar12 = DAT_004a5b80 == *(int *)(&DAT_004abf18 + iVar3 * 4);
  *(double *)(&DAT_004a71c8 + iVar3 * 8) =
       ((local_28 - *(double *)(&DAT_004a71c8 + iVar3 * 8)) * _DAT_004aa948) / dVar1 +
       *(double *)(&DAT_004a71c8 + iVar3 * 8);
  if (bVar12) {
    *(undefined4 *)(&DAT_004a71c8 + iVar3 * 8) = 0;
    *(undefined4 *)(&DAT_004a71cc + iVar3 * 8) = 0;
  }
  if (_DAT_004851d8 < *(double *)(&DAT_004a71c8 + iVar3 * 8)) {
    *(undefined4 *)(&DAT_004a71c8 + iVar3 * 8) = 0;
    *(undefined4 *)(&DAT_004a71cc + iVar3 * 8) = 0x40690000;
  }
  if (*(double *)(&DAT_004a71c8 + iVar3 * 8) < _DAT_00484d60) {
    *(undefined4 *)(&DAT_004a71c8 + iVar3 * 8) = 0;
    *(undefined4 *)(&DAT_004a71cc + iVar3 * 8) = 0xc0240000;
  }
  *(int *)(&DAT_004a7060 + iVar3 * 4) = (int)(longlong)*(double *)(&DAT_004a71c8 + iVar3 * 8);
  *(int *)(&DAT_004a6ec8 + iVar3 * 4) = (iVar8 + local_2c) / 2;
  if ((DAT_00491140 < iVar3) && (_DAT_004ac1f8 < _DAT_00484e18)) {
    iVar8 = FUN_0042a3b0(iVar3);
    iVar8 = (iVar8 * *(int *)(&DAT_004a7060 + iVar3 * 4)) / 100;
    *(int *)(&DAT_004a7060 + iVar3 * 4) = iVar8;
    if (iVar8 < 0x19) {
      *(undefined4 *)(&DAT_004a8aa8 + iVar3 * 4) = 0x28;
    }
    if (0x1e < *(int *)(&DAT_004a8aa8 + iVar3 * 4)) {
      *(undefined4 *)(&DAT_004a6ec8 + iVar3 * 4) = 7;
    }
    if (iVar11 + 6 < iVar8) {
      *(int *)(&DAT_004a7060 + iVar3 * 4) = iVar11 + 6;
    }
  }
  iVar8 = DAT_00491188;
  iVar4 = DAT_00491188 / 2;
  if (*(double *)(&DAT_004a7f28 + iVar3 * 8) < (double)(iVar4 + 3)) {
    *(undefined4 *)(&DAT_004a7060 + iVar3 * 4) = 5;
    *(undefined4 *)(&DAT_004a89c0 + iVar3 * 4) = 10;
  }
  if (*(double *)(&DAT_004a7f28 + iVar3 * 8) < (double)(iVar4 + 1)) {
    *(undefined4 *)(&DAT_004a7060 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004a89c0 + iVar3 * 4) = 10;
    *(undefined4 *)(&DAT_004ac018 + iVar3 * 4) = 0;
  }
  if ((DAT_004a6ecc <= iVar5 + 1) || (DAT_004a61f4 = 1, DAT_004a85d4 < 0)) {
    DAT_004a61f4 = 0;
  }
  if (8 < *(int *)(&DAT_004a5420 + iVar3 * 4)) {
    if (iVar3 <= DAT_00491140) goto LAB_00429b12;
    *(undefined4 *)(&DAT_004a7060 + iVar3 * 4) = 0x19;
  }
  if ((DAT_00491140 < iVar3) && (-1 < *(int *)(&DAT_004a5f90 + iVar3 * 4))) {
    *(int *)(&DAT_004a7060 + iVar3 * 4) = *(int *)(&DAT_004a5f90 + iVar3 * 4) / 2;
  }
LAB_00429b12:
  *(undefined4 *)(&DAT_004a5f90 + iVar3 * 4) = 0xffffffff;
  uVar10 = ((iVar8 < 7) - 1 & 3) + 5;
  if (iVar8 < 3) {
    uVar10 = 3;
  }
  if ((DAT_004ac900 == 1) || (DAT_004ac90c == 1)) {
    uVar10 = 8;
  }
  if (DAT_004ac904 == 1) {
    uVar10 = 10;
  }
  iVar6 = (int)(longlong)dVar15;
  iVar4 = *(int *)(&DAT_004a41f0 + iVar3 * 4);
  if (DAT_004a5b80 == iVar4) {
    *(int *)(&DAT_004ac570 + iVar3 * 4) = iVar11;
  }
  iVar5 = DAT_004a5b80;
  if (((iVar8 != 1) || (DAT_004ac904 != 0)) || (bVar12 = true, DAT_004ac914 != 0)) {
    bVar12 = false;
  }
  if (iVar8 == 2) {
    bVar12 = true;
  }
  if (*(int *)(&DAT_004a7bc8 + iVar3 * 4) < DAT_004a4eb0 + 5) {
    if ((iVar4 + 1 < DAT_004a5b80) && (DAT_004a5b80 <= (int)(uVar10 / 2 + iVar4))) {
      if ((DAT_004ac904 == 1) || (iVar11 < 5)) {
        iVar6 = 0xf;
      }
      if (*(int *)(&DAT_004ac570 + iVar3 * 4) < iVar6) {
        iVar6 = *(int *)(&DAT_004ac570 + iVar3 * 4);
      }
      if (bVar12) {
        *(int *)(&DAT_004a7060 + iVar3 * 4) = (int)(iVar6 * 3 + (iVar6 * 3 >> 0x1f & 3U)) >> 2;
        *(double *)(&DAT_004a71c8 + iVar3 * 8) = (double)*(int *)(&DAT_004a7060 + iVar3 * 4);
      }
      else {
        *(int *)(&DAT_004a7060 + iVar3 * 4) = (iVar6 * 2) / 3;
        *(double *)(&DAT_004a71c8 + iVar3 * 8) = (double)*(int *)(&DAT_004a7060 + iVar3 * 4);
      }
    }
    if (((int)(uVar10 / 2 + iVar4) < iVar5) && (iVar5 <= (int)(uVar10 + iVar4))) {
      if ((DAT_004ac904 == 1) || (iVar11 < 5)) {
        iVar6 = 0x19;
      }
      if (*(int *)(&DAT_004ac570 + iVar3 * 4) < iVar6) {
        iVar6 = *(int *)(&DAT_004ac570 + iVar3 * 4);
      }
      if (bVar12) {
        iVar11 = (iVar6 * 5) / 6;
      }
      else {
        iVar11 = (iVar6 << 2) / 5;
      }
      *(int *)(&DAT_004a7060 + iVar3 * 4) = iVar11;
      *(double *)(&DAT_004a71c8 + iVar3 * 8) = (double)*(int *)(&DAT_004a7060 + iVar3 * 4);
    }
    if ((int)(uVar10 + iVar4) < iVar5) {
      *(undefined4 *)(&DAT_004a46a8 + iVar3 * 4) = 0;
    }
  }
  if ((DAT_004ac904 == 1) && (*(int *)(&DAT_004aad20 + iVar3 * 4) == 1)) {
    if (0x1d < *(int *)(&DAT_004a7060 + iVar3 * 4)) {
      *(undefined4 *)(&DAT_004a7060 + iVar3 * 4) = 0x1e;
    }
    if (iVar4 + 6 < DAT_004a5b80) {
      *(undefined4 *)(&DAT_004aad20 + iVar3 * 4) = 0;
    }
  }
  if ((8 < *(int *)(&DAT_004a5420 + iVar3 * 4)) && (DAT_00491140 < iVar3)) {
    *(undefined4 *)(&DAT_004a71c8 + iVar3 * 8) = 0;
    *(undefined4 *)(&DAT_004a71cc + iVar3 * 8) = 0x403e0000;
    *(undefined4 *)(&DAT_004a7060 + iVar3 * 4) = 0x1e;
  }
  if (iVar3 == 1) {
    fVar13 = (float10)fcos((float10)DAT_004a7bcc * (float10)_DAT_00484d40);
    _DAT_004a71c0 = (undefined4)(longlong)(fVar13 * (float10)_DAT_004a71d0 * (float10)_DAT_00484d58)
    ;
  }
  return;
}

