
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00425910(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  float10 fVar12;
  longlong lVar13;
  
  iVar8 = (-(uint)(DAT_00491194 != 8) & 0xffffff9c) + 200;
  if (*(int *)(&DAT_004a5268 + param_3 * 4) < iVar8) {
    return 0;
  }
  if (0xb4 - *(int *)(&DAT_004a5f10 + param_3 * 4) < param_1) {
    bVar11 = true;
    iVar10 = -1;
    bVar2 = true;
  }
  else {
    iVar10 = *(int *)(&DAT_004a5e90 + param_3 * 4);
    bVar11 = false;
    bVar2 = false;
    if ((0xb4 - *(int *)(&DAT_004a5f10 + param_3 * 4)) - iVar10 < param_1) {
      iVar10 = iVar10 / 2;
    }
  }
  param_1 = iVar10;
  if (((DAT_0049118c == 2) || (iVar3 = FUN_00415a20(100), iVar3 < 0x32)) &&
     ((*(int *)(&DAT_004aada0 + param_3 * 4) == 1 || (*(int *)(&DAT_004a7868 + param_3 * 4) == 2))))
  {
    if ((200 < *(int *)(&DAT_004a5268 + param_3 * 4)) &&
       (*(int *)(&DAT_004a7970 + param_3 * 4) + 3 < DAT_004a5b80)) {
      iVar10 = iVar10 + 10;
      *(int *)(&DAT_004a7970 + param_3 * 4) = DAT_004a5b80;
    }
    if ((bVar11) && (iVar8 < *(int *)(&DAT_004a5268 + param_3 * 4))) {
      iVar10 = -10;
    }
    bVar7 = false;
    DAT_004a6804 = 1;
    DAT_004a681c = 0;
    if ((DAT_0049118c == 2) && (DAT_004aa738 == 1)) {
      bVar7 = true;
    }
    if ((((*(int *)(&DAT_004a7868 + param_3 * 4) != 2) || (iVar8 = FUN_00415a20(100), 0x1d < iVar8))
        || (!bVar11)) || ((DAT_004a5b80 <= *(int *)(&DAT_004a7970 + param_3 * 4) + 3 || (bVar7)))) {
      return iVar10;
    }
    param_1 = -1;
    DAT_004a6804 = 0;
  }
  fVar12 = FUN_00428ab0(param_3,(double)DAT_004aa294,(double)DAT_004aa388);
  if (((fVar12 < (float10)(DAT_0049118c * 7)) && (DAT_00491160 == 1)) && (DAT_0049118c < 0xf)) {
    if (DAT_004ac9a8 != 1) {
      *(undefined4 *)(&DAT_004aa730 + param_3 * 4) = 1;
      return -1;
    }
    *(undefined4 *)(&DAT_004aa730 + param_3 * 4) = 0xffffffff;
    return -1;
  }
  if ((DAT_0049118c < 3) || (6 < DAT_00491190)) {
    DAT_004a67f4 = 0;
  }
  else {
    DAT_004a67f4 = FUN_00415a20(0x32);
  }
  uVar4 = param_2 - *(int *)(&DAT_004ac018 + param_3 * 4) >> 0x1f;
  iVar8 = (param_2 - *(int *)(&DAT_004ac018 + param_3 * 4) ^ uVar4) - uVar4;
  if (0xb4 < iVar8) {
    iVar8 = 0x168 - iVar8;
  }
  iVar10 = *(int *)(&DAT_004a5f10 + param_3 * 4);
  if (iVar8 < iVar10 / 3) {
    DAT_004a67f4 = DAT_004a67f4 + -0x32;
  }
  iVar3 = DAT_004a67f4;
  if (iVar10 < iVar8) {
    iVar3 = DAT_004a67f4 + 0x28;
  }
  if ((iVar10 * 6) / 5 < iVar8) {
    if (*(int *)(&DAT_004aa730 + param_3 * 4) == -1) {
      iVar3 = iVar3 + 0xfa;
    }
    else {
      iVar3 = iVar3 + 100;
    }
  }
  iVar5 = iVar10 / 2;
  if ((iVar5 < iVar8) && (DAT_00491194 == 8)) {
    iVar3 = iVar3 + (iVar8 - iVar5) * 10;
  }
  if (DAT_0049118c == 2) {
    if (((iVar10 * 8) / 5 < iVar8) && (iVar8 <= (iVar10 * 9) / 5)) {
      if (*(int *)(&DAT_004aa730 + param_3 * 4) == -1) {
        iVar3 = iVar3 + 0x32;
      }
      else {
        iVar3 = iVar3 + 0x1e;
      }
    }
    if (iVar8 <= (iVar10 * 9) / 5) goto LAB_00425c8f;
    if (*(int *)(&DAT_004aa730 + param_3 * 4) == -1) {
      iVar3 = iVar3 + 0x4b0;
      goto LAB_00425c8f;
    }
  }
  else {
    if (((iVar10 * 7) / 5 < iVar8) && (iVar8 <= (iVar10 * 8) / 5)) {
      if (*(int *)(&DAT_004aa730 + param_3 * 4) == -1) {
        iVar3 = iVar3 + 0x32;
      }
      else {
        iVar3 = iVar3 + 0x1e;
      }
    }
    if (iVar8 <= (iVar10 * 8) / 5) goto LAB_00425c8f;
    if (*(int *)(&DAT_004aa730 + param_3 * 4) == -1) {
      iVar3 = iVar3 + 0x4b0;
      goto LAB_00425c8f;
    }
  }
  iVar3 = iVar3 + 0xfa;
LAB_00425c8f:
  DAT_004a67f8 = iVar3 - DAT_004a67f4;
  if (*(int *)(&DAT_004a7868 + param_3 * 4) == 2) {
    DAT_004a67d4 = (iVar3 + 600) - iVar3;
    iVar9 = iVar3 + 600;
  }
  else {
    DAT_004a67d4 = 0;
    iVar9 = iVar3;
  }
  if (*(int *)(&DAT_004a7868 + param_3 * 4) == 0xc) {
    iVar9 = iVar9 + -600;
    DAT_004a67d8 = iVar9 - iVar3;
  }
  else {
    DAT_004a67d8 = 0;
  }
  if (DAT_0049118c == 2) {
    iVar3 = iVar9;
    if ((DAT_004a786c == 2) && (iVar8 < iVar10 * 2)) {
      iVar3 = iVar9 + -300;
      DAT_004a6808 = iVar3 - iVar9;
    }
    iVar9 = iVar3;
    if (((DAT_004a786c == 0xc) && (0x5a < DAT_004a7bcc)) && (iVar8 < iVar10 * 2)) {
      iVar9 = iVar3 + 20000;
      DAT_004a680c = iVar9 - iVar3;
    }
  }
  iVar3 = iVar9;
  if ((DAT_004ac9b0 == 1) || (DAT_004ac9ac == 0)) {
    if ((*(int *)(&DAT_004a6338 + param_3 * 4) < DAT_004aa390) &&
       ((*(double *)(&DAT_004a7f28 + param_3 * 8) < *(double *)(&DAT_004a4510 + param_3 * 8) &&
        (iVar5 < iVar8)))) {
      iVar3 = iVar9 + 200;
    }
    DAT_004a67dc = iVar3 - iVar9;
    if (((*(int *)(&DAT_004a6338 + param_3 * 4) < DAT_004aa390) &&
        (*(double *)(&DAT_004a7f28 + param_3 * 8) < *(double *)(&DAT_004a4510 + param_3 * 8))) &&
       (iVar8 < (iVar10 * 7) / 5)) {
      iVar3 = iVar3 + -200;
    }
    DAT_004a67e0 = iVar3 - iVar9;
  }
  uVar4 = FUN_00413cb0(*(int *)(&DAT_004aa5b0 + param_3 * 4) - DAT_004a4f8c);
  if (0xb4 < (int)uVar4) {
    uVar4 = uVar4 - 0x168;
  }
  if ((*(int *)(&DAT_004a5f10 + param_3 * 4) / 2 < iVar8) &&
     (iVar8 < (*(int *)(&DAT_004a5f10 + param_3 * 4) * 3) / 2)) {
    uVar6 = (int)uVar4 >> 0x1f;
    if ((int)(uVar4 * *(int *)(&DAT_004aa730 + param_3 * 4)) < 0) {
      iVar10 = iVar3 - ((uVar4 ^ uVar6) - uVar6) * (DAT_00491190 / 2 + 4) * (DAT_004a71a4 + 1);
      DAT_004a67e8 = iVar10 - iVar3;
    }
    else {
      iVar10 = iVar3 + ((uVar4 ^ uVar6) - uVar6) * (DAT_00491190 / 2 + 4) * (DAT_004a71a4 + 1);
      DAT_004a67e4 = iVar10 - iVar3;
    }
    uVar4 = (int)DAT_004abc7c >> 0x1f;
    iVar3 = iVar10;
    if (((int)(DAT_004abc7c * *(int *)(&DAT_004aa730 + param_3 * 4)) < 0) &&
       (400 < *(int *)(&DAT_004a5268 + param_3 * 4))) {
      iVar3 = ((DAT_004abc7c ^ uVar4) - uVar4) * (DAT_004a5a48 + 1) * 3 + iVar10;
      DAT_004a67ec = iVar3 - iVar10;
    }
    if ((0 < (int)(DAT_004abc7c * *(int *)(&DAT_004aa730 + param_3 * 4))) &&
       (400 < *(int *)(&DAT_004a5268 + param_3 * 4))) {
      iVar3 = iVar3 + ((DAT_004abc7c ^ uVar4) - uVar4) * (DAT_004a5a48 + 1) * -3;
      DAT_004a67f0 = iVar3 - iVar10;
    }
  }
  uVar4 = ((DAT_004a4958 < 2) - 1 & 0xffffffe2) + 0x32;
  if ((*(double *)(&DAT_004a7f28 + param_3 * 8) < *(double *)(&DAT_004a4510 + param_3 * 8)) &&
     (*(double *)(&DAT_004a7f28 + param_3 * 8) < (double)(int)uVar4)) {
    iVar3 = iVar3 + 1000;
  }
  if ((DAT_0049118c == 2) && (0x37 < DAT_004a7bd0)) {
    lVar13 = FUN_0044da90(2,1);
    uVar4 = -(int)lVar13;
    iVar10 = iVar3;
    if (((int)lVar13 != -0x28 && 0x27 < (int)uVar4) &&
       ((*(int *)(&DAT_004a5f10 + param_3 * 4) < iVar8 &&
        (200 < *(int *)(&DAT_004a5268 + param_3 * 4))))) {
      iVar10 = iVar3 + 100;
    }
    DAT_004a67fc = iVar10 - iVar3;
    iVar3 = iVar10;
  }
  iVar10 = iVar3;
  if ((((*(int *)(&DAT_004a5268 + param_3 * 4) < 800) && (DAT_0049118c == 2)) &&
      (iVar5 = *(int *)(&DAT_004a5f10 + param_3 * 4),
      (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2 < iVar8)) &&
     ((iVar8 < (iVar5 * 3) / 2 &&
      ((int)((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f)) < 0x14)))) {
    if ((DAT_004ac9a8 == 0) && (*(int *)(&DAT_004aa730 + param_3 * 4) == 1)) {
      iVar10 = iVar3 + 100;
    }
    if ((DAT_004ac9a8 == 1) && (*(int *)(&DAT_004aa730 + param_3 * 4) == -1)) {
      iVar10 = iVar10 + 100;
    }
    DAT_004a6800 = iVar10 - iVar3;
  }
  DAT_004a681c = iVar10;
  iVar8 = FUN_00415a20(DAT_004911b4);
  iVar3 = DAT_004a5b80;
  if ((0 < DAT_004a5b80) && (DAT_00491194 == 8)) {
    iVar8 = iVar8 * 7;
  }
  if ((((bVar2) && (iVar8 < (int)(longlong)(_DAT_004aa948 * _DAT_00485160 * (double)(iVar10 / 10))))
      && (*(int *)(&DAT_004a7970 + param_3 * 4) + 10 < DAT_004a5b80)) &&
     (*(int *)(&DAT_004aada0 + param_3 * 4) * *(int *)(&DAT_004aa730 + param_3 * 4) != 1)) {
    uVar1 = *(undefined4 *)(&DAT_004a7f2c + param_3 * 8);
    *(int *)(&DAT_004a7970 + param_3 * 4) = DAT_004a5b80;
    *(int *)(&DAT_004aa730 + param_3 * 4) = -*(int *)(&DAT_004aa730 + param_3 * 4);
    *(undefined4 *)(&DAT_004a4510 + param_3 * 8) = *(undefined4 *)(&DAT_004a7f28 + param_3 * 8);
    bVar11 = DAT_004ac9ac == 1;
    *(undefined4 *)(&DAT_004a4398 + param_3 * 4) = 1;
    *(undefined4 *)(&DAT_004a4514 + param_3 * 8) = uVar1;
    if ((bVar11) && (param_3 == 2)) {
      DAT_00491198 = 0xfffffffa;
      DAT_0049119c = iVar3;
    }
  }
  return param_1;
}

