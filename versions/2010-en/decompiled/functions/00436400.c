
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00436400(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  bool bVar3;
  double dVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  float10 fVar13;
  longlong lVar14;
  
  iVar6 = param_3;
  if (*(int *)(&DAT_004f8300 + param_3 * 4) < 0xa0) {
    return 0;
  }
  if (0xb4 - *(int *)(&DAT_004fae60 + param_3 * 4) < param_1) {
    bVar12 = true;
    iVar11 = -1;
    bVar5 = true;
  }
  else {
    iVar11 = *(int *)(&DAT_004fadd0 + param_3 * 4);
    bVar12 = false;
    bVar5 = false;
    if ((0xb4 - *(int *)(&DAT_004fae60 + param_3 * 4)) - iVar11 < param_1) {
      iVar11 = iVar11 / 2;
    }
  }
  param_1 = iVar11;
  if (((DAT_004da194 == 2) || (iVar7 = FUN_0041e000(100), iVar7 < 0x32)) &&
     ((iVar7 = DAT_004f8cd0, *(int *)(&DAT_005239c8 + param_3 * 4) == 1 ||
      (*(int *)(&DAT_004fe8a8 + param_3 * 4) == 2)))) {
    if ((200 < *(int *)(&DAT_004f8300 + param_3 * 4)) &&
       (*(int *)(&DAT_004fe9d0 + param_3 * 4) + 3 < DAT_004f8cd0)) {
      iVar11 = iVar11 + 10;
      *(int *)(&DAT_004fe9d0 + param_3 * 4) = DAT_004f8cd0;
    }
    if (((bVar12) && (0xa0 < *(int *)(&DAT_004f8300 + param_3 * 4))) &&
       (iVar7 - *(int *)(&DAT_00522dd0 + param_3 * 4) < 10)) {
      iVar11 = -10;
    }
    if ((DAT_004da194 == 2) && (DAT_00522ff8 == 1)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (((*(int *)(&DAT_004fe8a8 + param_3 * 4) != 2) || (iVar7 = FUN_0041e000(100), 0x1d < iVar7))
       || ((!bVar12 || ((DAT_004f8cd0 <= *(int *)(&DAT_004fe9d0 + param_3 * 4) + 3 || (bVar3)))))) {
      return iVar11;
    }
    param_1 = -1;
  }
  fVar13 = FUN_00439e80(param_3,(double)DAT_005229d4,(double)DAT_00522ac8);
  if ((((float10)(DAT_004da194 * 7) <= fVar13) || (DAT_004da168 != 1)) || (10 < DAT_004da194)) {
    if ((DAT_004da194 < 3) || (6 < DAT_004da198)) goto LAB_004365d2;
    param_3 = FUN_0041e000(0x32);
  }
  else {
    if (2 < DAT_004da194) {
      if (DAT_0053646c != 1) {
        *(undefined4 *)(&DAT_00522ff0 + param_3 * 4) = 1;
        return -1;
      }
      *(undefined4 *)(&DAT_00522ff0 + param_3 * 4) = 0xffffffff;
      return -1;
    }
LAB_004365d2:
    param_3 = 0;
  }
  uVar8 = param_2 - *(int *)(&DAT_00535740 + iVar6 * 4) >> 0x1f;
  iVar11 = (param_2 - *(int *)(&DAT_00535740 + iVar6 * 4) ^ uVar8) - uVar8;
  if (0xb4 < iVar11) {
    iVar11 = 0x168 - iVar11;
  }
  iVar7 = *(int *)(&DAT_004fae60 + iVar6 * 4);
  if (iVar11 < iVar7 / 3) {
    param_3 = param_3 + -0x32;
  }
  if (iVar7 < iVar11) {
    param_3 = param_3 + 0x28;
  }
  if ((iVar7 * 6) / 5 < iVar11) {
    if (*(int *)(&DAT_00522ff0 + iVar6 * 4) == -1) {
      param_3 = param_3 + 0xfa;
    }
    else {
      param_3 = param_3 + 100;
    }
  }
  if (DAT_004da194 == 2) {
    if (((iVar7 * 8) / 5 < iVar11) && (iVar11 <= (iVar7 * 9) / 5)) {
      if (*(int *)(&DAT_00522ff0 + iVar6 * 4) == -1) {
        param_3 = param_3 + 0x32;
        iVar9 = iVar7 * 9;
        goto LAB_00436719;
      }
      param_3 = param_3 + 0x1e;
    }
    iVar9 = iVar7 * 9;
  }
  else {
    if (((iVar7 * 7) / 5 < iVar11) && (iVar11 <= (iVar7 * 8) / 5)) {
      if (*(int *)(&DAT_00522ff0 + iVar6 * 4) == -1) {
        param_3 = param_3 + 0x32;
      }
      else {
        param_3 = param_3 + 0x1e;
      }
    }
    iVar9 = iVar7 * 8;
  }
LAB_00436719:
  if (iVar9 / 5 < iVar11) {
    if (*(int *)(&DAT_00522ff0 + iVar6 * 4) == -1) {
      param_3 = param_3 + 0x4b0;
    }
    else {
      param_3 = param_3 + 0xfa;
    }
  }
  if (*(int *)(&DAT_004fe8a8 + iVar6 * 4) == 2) {
    param_3 = param_3 + 600;
  }
  if (*(int *)(&DAT_004fe8a8 + iVar6 * 4) == 0xc) {
    param_3 = param_3 + -600;
  }
  if (DAT_004da194 == 2) {
    if ((DAT_004fe8ac == 2) && (iVar11 < iVar7 * 2)) {
      param_3 = param_3 + -300;
    }
    if (((DAT_004fe8ac == 0xc) && (0x5a < DAT_004feccc)) && (iVar11 < iVar7 * 2)) {
      param_3 = param_3 + 5000;
    }
  }
  if ((int)(&DAT_004fb380)[iVar6] < DAT_00522ad0) {
    if ((*(double *)(&DAT_004ffcb8 + iVar6 * 8) < *(double *)(&DAT_004f4888 + iVar6 * 8)) &&
       (iVar7 / 2 < iVar11)) {
      param_3 = param_3 + 200;
    }
    if ((((int)(&DAT_004fb380)[iVar6] < DAT_00522ad0) &&
        (*(double *)(&DAT_004ffcb8 + iVar6 * 8) < *(double *)(&DAT_004f4888 + iVar6 * 8))) &&
       (iVar11 < (iVar7 * 7) / 5)) {
      param_3 = param_3 + -200;
    }
  }
  uVar8 = FUN_0041bc20((&DAT_00522b90)[iVar6] - DAT_005359d4);
  if (0xb4 < (int)uVar8) {
    uVar8 = uVar8 - 0x168;
  }
  if ((*(int *)(&DAT_004fae60 + iVar6 * 4) / 2 < iVar11) &&
     (iVar11 < (*(int *)(&DAT_004fae60 + iVar6 * 4) * 3) / 2)) {
    uVar10 = (int)uVar8 >> 0x1f;
    if ((int)(uVar8 * *(int *)(&DAT_00522ff0 + iVar6 * 4)) < 0) {
      iVar7 = -(((uVar8 ^ uVar10) - uVar10) * (DAT_004fe15c + 1) * (DAT_004da198 / 2 + 4));
    }
    else {
      iVar7 = (int)((DAT_004da198 / 2 + 4) * ((uVar8 ^ uVar10) - uVar10) * (DAT_004fe15c + 1)) / 2;
    }
    param_3 = param_3 + iVar7;
    uVar8 = DAT_005364f8 + DAT_00535204;
    iVar7 = uVar8 * *(int *)(&DAT_00522ff0 + iVar6 * 4);
    uVar10 = (int)uVar8 >> 0x1f;
    if ((iVar7 < 0) && (400 < *(int *)(&DAT_004f8300 + iVar6 * 4))) {
      param_3 = ((uVar8 ^ uVar10) - uVar10) * (DAT_004f8b74 + 1) * 3 + param_3;
    }
    if ((0 < iVar7) && (400 < *(int *)(&DAT_004f8300 + iVar6 * 4))) {
      param_3 = param_3 + ((uVar8 ^ uVar10) - uVar10) * (DAT_004f8b74 + 1) * -3;
    }
  }
  if (DAT_004da1f8 == 5) {
    dVar4 = (double)DAT_004da1fc - (double)*(int *)(&DAT_005232e8 + iVar6 * 4) * _DAT_004cc9d8;
  }
  else {
    dVar4 = (double)*(int *)(&DAT_005232e8 + iVar6 * 4) * _DAT_004cc538;
  }
  if ((*(double *)(&DAT_005125f8 + iVar6 * 8) < *(double *)(&DAT_00523478 + iVar6 * 8)) &&
     (*(double *)(&DAT_005125f8 + iVar6 * 8) < dVar4)) {
    param_3 = param_3 + 1000;
    *(int *)(&DAT_004fad40 + iVar6 * 4) = iVar6 + 10 + DAT_004f8cd0;
  }
  uVar8 = param_3;
  if ((DAT_004da194 == 2) && (0x37 < DAT_004fecd0)) {
    lVar14 = FUN_00464050(2,1);
    uVar8 = -(int)lVar14;
    if (((int)lVar14 != -0x28 && 0x27 < (int)uVar8) &&
       ((*(int *)(&DAT_004fae60 + iVar6 * 4) < iVar11 && (200 < *(int *)(&DAT_004f8300 + iVar6 * 4))
        ))) {
      param_3 = param_3 + 100;
    }
  }
  if ((((*(int *)(&DAT_004f8300 + iVar6 * 4) < 800) && (DAT_004da194 == 2)) &&
      (iVar7 = *(int *)(&DAT_004fae60 + iVar6 * 4),
      (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2 < iVar11)) &&
     ((iVar11 < (iVar7 * 3) / 2 &&
      ((int)((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f)) < 0x14)))) {
    if ((DAT_0053646c == 0) && (*(int *)(&DAT_00522ff0 + iVar6 * 4) == 1)) {
      param_3 = param_3 + 100;
    }
    if ((DAT_0053646c == 1) && (*(int *)(&DAT_00522ff0 + iVar6 * 4) == -1)) {
      param_3 = param_3 + 100;
    }
  }
  iVar11 = FUN_0041e000(900);
  if (DAT_004da1f8 == 5) {
    iVar11 = FUN_0041e000(0x5dc);
  }
  iVar7 = DAT_004f8cd0;
  if ((((bVar5) &&
       (iVar11 < (int)(longlong)(_DAT_00523378 * _DAT_004cc9e0 * (double)(param_3 / 10)))) &&
      (*(int *)(&DAT_004fe9d0 + iVar6 * 4) + 10 < DAT_004f8cd0)) &&
     (*(int *)(&DAT_005239c8 + iVar6 * 4) * *(int *)(&DAT_00522ff0 + iVar6 * 4) != 1)) {
    *(undefined4 *)(&DAT_004f4530 + iVar6 * 4) = 1;
    uVar1 = *(undefined4 *)(&DAT_004ffcb8 + iVar6 * 8);
    *(int *)(&DAT_00522ff0 + iVar6 * 4) = -*(int *)(&DAT_00522ff0 + iVar6 * 4);
    uVar2 = *(undefined4 *)(&DAT_004ffcbc + iVar6 * 8);
    *(undefined4 *)(&DAT_004f4888 + iVar6 * 8) = uVar1;
    uVar1 = *(undefined4 *)(&DAT_005125f8 + iVar6 * 8);
    *(int *)(&DAT_004fe9d0 + iVar6 * 4) = iVar7;
    *(undefined4 *)(&DAT_004f488c + iVar6 * 8) = uVar2;
    *(undefined4 *)(&DAT_00523478 + iVar6 * 8) = uVar1;
    *(undefined4 *)(&DAT_0052347c + iVar6 * 8) = *(undefined4 *)(&DAT_005125fc + iVar6 * 8);
    *(int *)(&DAT_004fad40 + iVar6 * 4) = iVar6 + 10 + iVar7;
  }
  return param_1;
}

