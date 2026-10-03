
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00434f70(int param_1)

{
  int *piVar1;
  double dVar2;
  double dVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined4 *puVar15;
  bool bVar16;
  float10 fVar17;
  
  iVar5 = param_1;
  iVar6 = DAT_004f8cd0;
  if (0 < *(int *)(&DAT_004fe638 + param_1 * 4)) {
    iVar6 = FUN_0041bc20(DAT_005362d4 + -0x2d);
    *(int *)(&DAT_00535740 + param_1 * 4) = iVar6;
    return;
  }
  iVar9 = *(int *)(&DAT_004fad40 + param_1 * 4);
  *(int *)(&DAT_004fad40 + param_1 * 4) = iVar9 + -1;
  if (iVar9 + -1 < iVar6) {
    *(int *)(&DAT_004fad40 + param_1 * 4) = iVar6;
  }
  if (iVar6 < *(int *)(&DAT_004fad40 + param_1 * 4)) {
    return;
  }
  dVar2 = *(double *)(&DAT_00523478 + param_1 * 8) * _DAT_004cc930;
  dVar3 = *(double *)(&DAT_005125f8 + param_1 * 8) * _DAT_004cc678;
  *(double *)(&DAT_004f4888 + param_1 * 8) =
       *(double *)(&DAT_004f4888 + param_1 * 8) * _DAT_004cc930 -
       *(double *)(&DAT_004ffcb8 + param_1 * 8) * _DAT_004cc678;
  iVar6 = DAT_004da1f8;
  *(double *)(&DAT_00523478 + param_1 * 8) = dVar2 - dVar3;
  if (0 < iVar6) {
    fVar17 = FUN_0047d5f0(param_1,(int)(longlong)*(double *)(&DAT_004f6af8 + param_1 * 8),
                          (int)(longlong)*(double *)(&DAT_004f6c10 + param_1 * 8),0,0);
    *(double *)(&DAT_004ffcb8 + param_1 * 8) = (double)fVar17;
    fVar17 = FUN_0047d5f0(param_1,(int)(longlong)*(double *)(&DAT_004f6af8 + param_1 * 8),
                          (int)(longlong)*(double *)(&DAT_004f6c10 + param_1 * 8),0,1);
    *(double *)(&DAT_005125f8 + param_1 * 8) = (double)fVar17;
  }
  if (DAT_004da1f8 == 0) {
    fVar17 = FUN_0042f330((int)(longlong)*(double *)(&DAT_004f6af8 + param_1 * 8),
                          (int)(longlong)*(double *)(&DAT_004f6c10 + param_1 * 8),param_1);
    *(double *)(&DAT_004ffcb8 + param_1 * 8) = (double)fVar17;
    *(double *)(&DAT_005125f8 + param_1 * 8) = (double)fVar17;
  }
  iVar6 = *(int *)(&DAT_00535740 + param_1 * 4);
  if ((DAT_004da194 == 2) && (param_1 == 2)) {
    FUN_00464050(2,1);
  }
  iVar8 = DAT_004da190;
  iVar9 = (&DAT_004fb380)[param_1];
  if ((iVar9 < 0xc) && (2 < DAT_004da190)) {
    *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x21;
  }
  else {
    *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x14;
  }
  if ((iVar8 == 7) && (DAT_005363c0 == 0)) {
    if ((0xc < iVar9) ||
       (iVar7 = (0xc - iVar9) * 6,
       *(int *)(&DAT_004fae60 + param_1 * 4) = ((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2) + 0x1a,
       0xc < iVar9)) {
      iVar7 = (0xc - iVar9) * 0xb;
      *(int *)(&DAT_004fae60 + param_1 * 4) = ((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2) + 0x1a;
    }
    if (*(int *)(&DAT_004fae60 + param_1 * 4) < 0xf) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0xf;
    }
    if (0x20 < *(int *)(&DAT_004fae60 + param_1 * 4)) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x20;
    }
  }
  if (iVar8 == 8) {
    if ((0xc < iVar9) ||
       (iVar8 = (0xc - iVar9) * 10,
       *(int *)(&DAT_004fae60 + param_1 * 4) = ((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2) + 0x1a,
       0xc < iVar9)) {
      *(int *)(&DAT_004fae60 + param_1 * 4) = iVar9 * -7 + 0x6e;
    }
    if (0x24 < *(int *)(&DAT_004fae60 + param_1 * 4)) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x24;
    }
    if (*(int *)(&DAT_004fae60 + param_1 * 4) < 0x13) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x13;
    }
  }
  iVar8 = DAT_005364c0;
  if (DAT_005364c0 == 1) {
    if ((0xc < iVar9) ||
       (iVar7 = (0xc - iVar9) * 7,
       *(int *)(&DAT_004fae60 + param_1 * 4) = ((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2) + 0x21,
       0xc < iVar9)) {
      iVar7 = (0xc - iVar9) * 3;
      *(int *)(&DAT_004fae60 + param_1 * 4) = ((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2) + 0x21;
    }
    if (0x23 < *(int *)(&DAT_004fae60 + param_1 * 4)) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x23;
    }
    if (*(int *)(&DAT_004fae60 + param_1 * 4) < 0x1e) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x1e;
    }
  }
  if (DAT_005363c4 == 1) {
    if ((0xc < iVar9) ||
       (iVar7 = (0xc - iVar9) * 7,
       *(int *)(&DAT_004fae60 + param_1 * 4) = ((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2) + 0x2b,
       0xc < iVar9)) {
      iVar7 = (0xc - iVar9) * 0xb;
      *(int *)(&DAT_004fae60 + param_1 * 4) = ((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2) + 0x2b;
    }
    if (0x32 < *(int *)(&DAT_004fae60 + param_1 * 4)) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x32;
    }
    if (*(int *)(&DAT_004fae60 + param_1 * 4) < 0x20) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x20;
    }
  }
  if (0 < DAT_005363c0) {
    if ((0xc < iVar9) || (*(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x28, 0xc < iVar9)) {
      iVar7 = (0xc - iVar9) * 0x14;
      *(int *)(&DAT_004fae60 + param_1 * 4) = ((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2) + 0x28;
    }
    if (0x28 < *(int *)(&DAT_004fae60 + param_1 * 4)) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x28;
    }
    if (*(int *)(&DAT_004fae60 + param_1 * 4) < 0x14) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x14;
    }
  }
  if (0x10 < iVar9) {
    *(int *)(&DAT_004fae60 + param_1 * 4) = *(int *)(&DAT_004fae60 + param_1 * 4) + -3;
  }
  iVar7 = DAT_004da190;
  if (DAT_004da190 == 1) {
    *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0xb;
  }
  if (iVar7 == 2) {
    *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0xc;
  }
  if ((DAT_005364c4 == 1) || (DAT_005364c8 == 1)) {
    *(uint *)(&DAT_004fae60 + param_1 * 4) = ((0xb < iVar9) - 1 & 6) + 0xb;
  }
  if ((iVar7 == 4) || (iVar7 == 5)) {
    *(uint *)(&DAT_004fae60 + param_1 * 4) = ((0xb < iVar9) - 1 & 0xf) + 0xf;
  }
  if (iVar7 == 6) {
    *(uint *)(&DAT_004fae60 + param_1 * 4) = ((0xc < iVar9) - 1 & 0xf) + 0xf;
  }
  if ((DAT_005363b8 == 1) && (iVar8 == 0)) {
    *(uint *)(&DAT_004fae60 + param_1 * 4) = ((10 < iVar9) - 1 & 8) + 0x22;
    if (0x14 < iVar9) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x1e;
    }
    if ((DAT_005364cc == 1) && (0xc < iVar9)) {
      *(int *)(&DAT_004fae60 + param_1 * 4) = *(int *)(&DAT_004fae60 + param_1 * 4) + -7;
    }
  }
  if (DAT_005363bc == 1) {
    *(uint *)(&DAT_004fae60 + param_1 * 4) = ((10 < iVar9) - 1 & 0xfffffff6) + 0x32;
    if (iVar9 < 8) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x23;
    }
    if (0xd < iVar9) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x28;
    }
    if (0x12 < iVar9) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x23;
    }
  }
  if (DAT_0053652c == 1) {
    if ((0xc < iVar9) || (*(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x2b, 0xc < iVar9)) {
      iVar9 = (0xc - iVar9) * 0xb;
      *(int *)(&DAT_004fae60 + param_1 * 4) = ((int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2) + 0x2b;
    }
    if (0x32 < *(int *)(&DAT_004fae60 + param_1 * 4)) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x32;
    }
    if (*(int *)(&DAT_004fae60 + param_1 * 4) < 0x20) {
      *(undefined4 *)(&DAT_004fae60 + param_1 * 4) = 0x20;
    }
  }
  DAT_005231ac = ((0 < DAT_004f8cd0) - 1 & 0x104) + 0x28;
  if ((DAT_005364e8 % 6 == 0) || (DAT_004f8cd0 < DAT_004f42b8 + 2)) {
    iVar9 = FUN_00436ba0((int)(longlong)*(double *)(&DAT_004f6af8 + param_1 * 8),
                         (int)(longlong)*(double *)(&DAT_004f6c10 + param_1 * 8),param_1);
    uVar4 = DAT_00523af4;
    (&DAT_004fb380)[param_1] = iVar9;
    bVar16 = DAT_004da1f8 == 0;
    (&DAT_00522b90)[param_1] = uVar4;
    if (bVar16) {
      *(undefined4 *)(&DAT_00535e40 + param_1 * 4) = DAT_00535e30;
    }
  }
  if ((DAT_00511624 == 1) && (param_1 == 1)) {
    FUN_00437520(1);
    _DAT_004fe938 = (double)DAT_00535744;
  }
  if (DAT_00511628 == 1) {
    if (param_1 == 2) {
      if (DAT_004da140 == 2) {
        FUN_00437520(2);
      }
      goto LAB_004355da;
    }
  }
  else {
LAB_004355da:
    if (((param_1 == 2) && (DAT_004f6a70 == 1)) && (DAT_004da140 == 2)) {
      DAT_00535748 = FUN_0041bc20(DAT_00522b98 -
                                  ((DAT_004f3f68 - DAT_004fae68) + 0xb4) * DAT_00522ff8);
    }
  }
  if (param_1 <= DAT_004da140) {
    *(undefined4 *)(&DAT_00535568 + param_1 * 4) = *(undefined4 *)(&DAT_00522ff0 + param_1 * 4);
    FUN_00435f90(param_1);
  }
  iVar8 = DAT_005363b8;
  *(undefined4 *)(&DAT_004f4530 + param_1 * 4) = 0;
  iVar9 = DAT_004da140;
  if ((iVar8 == 0) && (DAT_005363c4 == 0)) {
    iVar8 = (&DAT_004fb380)[param_1];
    iVar7 = (int)((ulonglong)((longlong)iVar8 * 0x55555555) >> 0x20) - iVar8;
    DAT_004f7200 = (((iVar7 >> 1) - (iVar7 >> 0x1f)) - DAT_004da190 / 6) + 0x31;
  }
  else {
    iVar8 = (&DAT_004fb380)[param_1];
    DAT_004f7200 = 0x2e - ((int)((iVar8 >> 0x1f & 7U) + iVar8) >> 3);
  }
  if (DAT_005364bc == 1) {
    DAT_004f7200 = 0x30 - iVar8 / 3;
  }
  if ((DAT_004da190 == 3) && (DAT_005363c4 == 0)) {
    DAT_004f7200 = DAT_004f7200 + 2;
  }
  if ((DAT_005363c4 == 1) && (iVar8 < 10)) {
    DAT_004f7200 = DAT_004f7200 + 4;
  }
  if (DAT_005363c0 == 1) {
    DAT_004f7200 = DAT_004f7200 + 2;
  }
  if ((DAT_004da190 == 1) && (iVar8 < 10)) {
    DAT_004f7200 = DAT_004f7200 + 5;
  }
  if (DAT_004da190 == 8) {
    DAT_004f7200 = DAT_004f7200 + -4;
  }
  if (DAT_005363bc == 1) {
    DAT_004f7200 = ((iVar8 < 10) - 1 & 0xfffffffd) + 0x3c;
  }
  if (DAT_004da190 == 1) {
    DAT_004f7200 = DAT_004f7200 + -1 + *(int *)(&DAT_004fe778 + param_1 * 4);
  }
  if ((DAT_00536528 == 1) && (iVar8 < 10)) {
    DAT_004f7200 = DAT_004f7200 + 4;
  }
  if ((DAT_0053652c == 1) && (iVar8 < 10)) {
    DAT_004f7200 = DAT_004f7200 + 4;
  }
  if ((DAT_004da16c == 1) && (10 < DAT_00536420)) {
    DAT_005363f4 = 10;
  }
  if ((0 < DAT_004da16c) && (0x104 < DAT_004f8cd0)) {
    DAT_005363f4 = 1;
  }
  uVar10 = *(int *)(&DAT_004f4d78 + param_1 * 4) -
           (int)(longlong)*(double *)(&DAT_004f6af8 + param_1 * 8);
  uVar11 = (int)uVar10 >> 0x1f;
  uVar12 = *(int *)(&DAT_004fc350 + param_1 * 4) -
           (int)(longlong)*(double *)(&DAT_004f6c10 + param_1 * 8);
  uVar13 = (int)uVar12 >> 0x1f;
  *(uint *)(&DAT_004f8300 + param_1 * 4) =
       ((uVar10 ^ uVar11) - uVar11) + ((uVar12 ^ uVar13) - uVar13);
  if ((param_1 <= iVar9) || (iVar9 = DAT_005231ac, DAT_004f8cd0 < 1)) {
    iVar9 = 400;
  }
  if (DAT_004da140 < param_1) {
LAB_00435851:
    if (*(int *)(&DAT_004f8538 + param_1 * 4) == DAT_004da1e4) {
      iVar9 = DAT_005231ac * 5;
    }
    if (param_1 <= DAT_004da140) goto LAB_00435867;
  }
  else {
    if ((0 < DAT_004f8cd0) && ((DAT_004da1f8 == 5 || (DAT_004da19c == 8)))) {
      iVar9 = 500;
    }
    if (DAT_004da140 < param_1) goto LAB_00435851;
LAB_00435867:
    if (*(int *)(&DAT_004f8538 + param_1 * 4) == DAT_004da1e4) {
      iVar9 = DAT_005231ac * 5;
    }
  }
  if ((((DAT_004f8cd0 < 0x1f) && (-4 < DAT_004f8cd0)) &&
      (*(int *)(&DAT_004f8538 + param_1 * 4) == 0)) &&
     ((FUN_0043ec20((double)((DAT_00536410 + DAT_004fe094) / 2),
                    (double)((DAT_004fe2a0 + DAT_00536414) / 2),0,param_1),
      *(int *)(&DAT_004f8300 + param_1 * 4) < iVar9 &&
      ((int)(longlong)_DAT_004fbb88 < DAT_00523598 / 2)))) {
    DAT_004f6a58 = 0;
    FUN_00437570(param_1);
  }
  if (((0x1e < DAT_004f8cd0) && (*(int *)(&DAT_004f8300 + param_1 * 4) < iVar9)) &&
     (*(int *)(&DAT_004f8538 + param_1 * 4) < DAT_004da1e4)) {
    DAT_004f6a58 = 0;
    FUN_00437570(param_1);
  }
  if ((((DAT_0053527c == 0) && (*(int *)(&DAT_004f8538 + param_1 * 4) == DAT_004da1e4)) &&
      (*(int *)(&DAT_004f8300 + param_1 * 4) < DAT_00523598)) &&
     (fVar17 = FUN_00437d40(param_1), fVar17 <= (float10)_DAT_004cc728)) {
    DAT_004f6a58 = 0;
    FUN_00437570(param_1);
  }
  if (((DAT_0053527c == 1) && (*(int *)(&DAT_004f8538 + param_1 * 4) == DAT_004da1e4)) &&
     (fVar17 = FUN_00439e80(param_1,(double)DAT_005229d4,(double)DAT_00522ac8),
     (float10)DAT_00525a9c - (float10)_DAT_004cc9d0 <= fVar17)) {
    DAT_004f6a58 = 0;
    FUN_00437570(param_1);
  }
  if ((DAT_004f8cd0 / 5 < DAT_004f8cd0 - DAT_00534d64) &&
     (*(int *)(&DAT_004f8538 + param_1 * 4) <= DAT_004da1e4)) {
    *(int *)(&DAT_004f8538 + param_1 * 4) = DAT_004da1e4;
    DAT_004f6a58 = 1;
    FUN_00437570(param_1);
  }
  if (0 < DAT_004da1ac) {
    if (DAT_004da140 < param_1) goto LAB_00435a77;
    FUN_00439100(param_1);
  }
  if (param_1 <= DAT_004da140) {
    return;
  }
LAB_00435a77:
  DAT_004f4b40 = FUN_00427ee0(*(int *)(&DAT_004f4d78 + param_1 * 4) -
                              (int)(longlong)*(double *)(&DAT_004f6af8 + param_1 * 8),
                              (int)(longlong)*(double *)(&DAT_004f6c10 + param_1 * 8) -
                              *(int *)(&DAT_004fc350 + param_1 * 4));
  iVar9 = iVar6;
  if ((*(int *)(&DAT_00522e68 + param_1 * 4) == 0) && (*(int *)(&DAT_004fe6d0 + param_1 * 4) == 0))
  {
    iVar9 = FUN_00435fe0(DAT_004f4b40,DAT_004f7200,param_1);
  }
  iVar14 = DAT_004f7200;
  iVar7 = DAT_004f4b40;
  iVar8 = DAT_004f42b8;
  if (((DAT_004f7200 < iVar9) || (*(int *)(&DAT_00522e68 + param_1 * 4) != 0)) ||
     (*(int *)(&DAT_004fe6d0 + param_1 * 4) != 0)) {
    if ((param_1 == 2) && (DAT_004da194 == 2)) {
      DAT_0053647c = 0;
      puVar15 = &DAT_004f6d68;
      for (iVar9 = 0x28; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
    }
  }
  else {
    *(int *)(&DAT_00535740 + param_1 * 4) =
         (&DAT_00522b90)[param_1] - *(int *)(&DAT_00522ff0 + param_1 * 4) * DAT_004f7200;
    if (iVar8 + 10 < DAT_004f8cd0) {
      FUN_00437e60(iVar7,param_1);
      iVar14 = DAT_004f7200;
    }
  }
  if (((param_1 == 2) && (DAT_0053647c == 1)) && (DAT_004da194 == 2)) {
    DAT_00535748 = DAT_00522b98 - (iVar14 + -5) * DAT_00522ff8;
    _DAT_004da1a0 = 0xfffffff7;
  }
  if ((((DAT_004da140 == 1) && (DAT_004f8cd0 < DAT_004da170)) && (DAT_004da194 == 2)) &&
     (param_1 == 2)) {
    if (DAT_004f8cd0 < DAT_004f42b8 + 10) {
      DAT_00535748 = DAT_004f4298;
      return;
    }
    if ((DAT_00522ff8 == 1) && ((DAT_004f42b8 + 10 + DAT_004da170) / 2 < DAT_004f8cd0)) {
      if (DAT_005239d0 == 0) {
        DAT_00535748 = FUN_0041bc20(DAT_00522b98 + 0x91);
        DAT_00522ff8 = -1;
      }
      else {
        DAT_00535748 = FUN_0041bc20(DAT_00522b98 - iVar14);
        DAT_00522ff8 = 1;
      }
    }
    if (DAT_004f8cd0 < DAT_004da170 + -5) {
      DAT_00535748 = FUN_0041bc20(DAT_00522b98 + DAT_00522ff8 * -0x91);
    }
    if (DAT_004da170 + -5 <= DAT_004f8cd0) {
      DAT_00535748 = FUN_0041bc20(DAT_00522b98 + DAT_00522ff8 * -0x32);
    }
  }
  if (((DAT_004f8cd0 < *(int *)(&DAT_004fe9d0 + param_1 * 4) + 3) &&
      (*(int *)(&DAT_004f4530 + param_1 * 4) == 0)) &&
     ((*(int *)(&DAT_00522e68 + param_1 * 4) == 0 && (DAT_004f42b8 + 10 < DAT_004f8cd0)))) {
    *(int *)(&DAT_00535740 + param_1 * 4) = iVar6;
  }
  if ((((DAT_004da140 < param_1) && (*(int *)(&DAT_00522e68 + param_1 * 4) == 0)) &&
      (*(int *)(&DAT_004f4530 + param_1 * 4) == 0)) &&
     ((*(int *)(&DAT_004fe6d0 + param_1 * 4) == 0 &&
      (((iVar9 = *(int *)(&DAT_004f8538 + param_1 * 4), iVar9 == 1 || (iVar9 == 4)) || (iVar9 == 8))
      )))) {
    iVar9 = FUN_0041bc20(iVar6 + 0x1e);
    iVar8 = FUN_0041bc20(*(int *)(&DAT_00535740 + param_1 * 4));
    if (iVar9 < iVar8) {
      iVar9 = FUN_0041bc20(iVar6 + 0xb4);
      iVar8 = FUN_0041bc20(*(int *)(&DAT_00535740 + param_1 * 4));
      if ((iVar8 < iVar9) && (DAT_0053646c == 1)) {
        iVar9 = FUN_0041bc20(iVar6 + 0x1e);
        *(int *)(&DAT_00535740 + param_1 * 4) = iVar9;
      }
    }
    iVar9 = FUN_0041bc20(iVar6 + -0x1e);
    iVar8 = FUN_0041bc20(*(int *)(&DAT_00535740 + param_1 * 4));
    if (iVar8 < iVar9) {
      iVar9 = FUN_0041bc20(iVar6 + -0xb4);
      iVar8 = FUN_0041bc20(*(int *)(&DAT_00535740 + param_1 * 4));
      if ((iVar9 < iVar8) && (DAT_0053646c == 0)) {
        iVar6 = FUN_0041bc20(iVar6 + -0x1e);
        *(int *)(&DAT_00535740 + param_1 * 4) = iVar6;
      }
    }
  }
  *(undefined4 *)(&DAT_004f4530 + param_1 * 4) = 0;
  FUN_00439100(param_1);
  iVar9 = DAT_004f8cd0;
  iVar6 = DAT_004f7200;
  if ((DAT_005363bc != 1) || (piVar1 = &DAT_004fb380 + param_1, param_1 = 5, 9 < *piVar1)) {
    param_1 = 0;
  }
  iVar8 = *(int *)(&DAT_00522e68 + iVar5 * 4);
  if ((iVar8 != 0) && (DAT_004da140 < iVar5)) {
    iVar7 = *(int *)(&DAT_004f4350 + iVar5 * 4);
    if (DAT_004f8cd0 == iVar7) {
      *(int *)(&DAT_00535740 + iVar5 * 4) = (&DAT_00522b90)[iVar5] - DAT_004f7200 * iVar8;
    }
    if (iVar9 == iVar7 + 1) {
      *(int *)(&DAT_00535740 + iVar5 * 4) = (&DAT_00522b90)[iVar5] + iVar8 * -0x1e;
    }
    if (iVar9 == iVar7 + 2) {
      iVar14 = (&DAT_00522b90)[iVar5];
      *(undefined4 *)(&DAT_004f4a70 + iVar5 * 4) = 1;
      *(int *)(&DAT_00535740 + iVar5 * 4) = iVar14 + iVar8 * -0xf;
    }
    if (iVar9 == iVar7 + 3) {
      *(int *)(&DAT_00535740 + iVar5 * 4) = (&DAT_00522b90)[iVar5] + iVar8 * 0xf;
    }
    if (iVar9 == iVar7 + 4) {
      *(int *)(&DAT_00535740 + iVar5 * 4) = (&DAT_00522b90)[iVar5] + iVar8 * 0x1e;
    }
    if (iVar7 + 5 < iVar9) {
      *(int *)(&DAT_00522ff0 + iVar5 * 4) = -iVar8;
      iVar9 = (&DAT_00522b90)[iVar5];
      *(undefined4 *)(&DAT_004fe180 + iVar5 * 8) = 0;
      *(int *)(&DAT_00535740 + iVar5 * 4) = iVar9 - (param_1 + iVar6) * -iVar8;
      *(undefined4 *)(&DAT_00522e68 + iVar5 * 4) = 0;
      *(undefined4 *)(&DAT_004fe184 + iVar5 * 8) = 0;
    }
  }
  if (0 < *(int *)(&DAT_004fe638 + iVar5 * 4)) {
    *(int *)(&DAT_00535740 + iVar5 * 4) = DAT_005362d4 + -0x2d;
  }
  iVar6 = FUN_0041bc20(*(int *)(&DAT_00535740 + iVar5 * 4));
  *(int *)(&DAT_00535740 + iVar5 * 4) = iVar6;
  FUN_00435f90(iVar5);
  return;
}

