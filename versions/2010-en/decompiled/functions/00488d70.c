
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00488d70(int param_1,int param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  float10 fVar16;
  int local_1c;
  
  iVar8 = param_3;
  if (0 < param_3) {
    local_1c = (&DAT_00522b90)[param_3];
  }
  DAT_00523af4 = DAT_005362d4;
  (&DAT_004fb380)[param_3] = DAT_00522ad0;
  DAT_0053545c = 0;
  if (param_3 == 1) {
    _DAT_005364f0 = 0;
  }
  iVar9 = FUN_00488b90(1,param_1,param_2,param_3);
  iVar10 = DAT_00522ad0;
  dVar3 = (double)DAT_004da218 * _DAT_004cc4f8;
  *(undefined4 *)(&DAT_00536240 + param_3 * 4) = 0;
  if ((double)iVar9 < dVar3) {
    (&DAT_004fb380)[param_3] = (iVar10 + (int)(longlong)((double)(iVar9 * iVar10) / dVar3) * 2) / 3;
  }
  if (((DAT_004f8d78 < 3) && (iVar9 < DAT_004da218)) && (DAT_00536450 == 0)) {
    DAT_004fae5c = 1;
  }
  else {
    DAT_004fae5c = 0;
  }
  if (param_3 == 1) {
    DAT_005364ec = DAT_004fae5c;
  }
  if (DAT_004da154 < 2) {
    (&DAT_004fb380)[param_3] = (&DAT_004fb380)[param_3] + DAT_004fae5c * 2;
  }
  else {
    (&DAT_004fb380)[param_3] = (&DAT_004fb380)[param_3] + DAT_004fae5c * 4;
  }
  if ((int)(&DAT_004fb380)[param_3] < iVar10) {
    *(undefined4 *)(&DAT_00536240 + param_3 * 4) = 1;
  }
  dVar3 = (double)param_1;
  dVar5 = (double)param_2;
  dVar4 = SQRT(dVar5 * dVar5 + dVar3 * dVar3);
  iVar10 = FUN_00427ee0((int)(longlong)dVar3,-(int)(longlong)dVar5);
  uVar13 = iVar10 - DAT_005362d4 >> 0x1f;
  iVar10 = (iVar10 - DAT_005362d4 ^ uVar13) - uVar13;
  cVar1 = iVar10 < 0x1e;
  if (0x136 < iVar10) {
    cVar1 = '\x02';
  }
  param_3 = (-(uint)(DAT_004da1f8 != 7) & 0x24) + 0xe;
  if (DAT_004da1f8 == 6) {
    param_3 = 0x1d;
  }
  if (DAT_004da1f8 == 9) {
    param_3 = 0xe;
  }
  if (DAT_004da1f8 == 10) {
    param_3 = 0x10;
  }
  if (DAT_004da1f8 == 0xb) {
    param_3 = DAT_004da1f8;
  }
  if ((DAT_004da1f8 == 0xc) || (DAT_004da1f8 == 0x67)) {
    param_3 = 0x2c;
  }
  if (DAT_004da1f8 == 0x69) {
    param_3 = (-1 < param_2) - 1 & 0x14;
  }
  if (DAT_004da1f8 == 100) {
    param_3 = 0x45;
  }
  if (DAT_004da1f8 == 0x65) {
    param_3 = 0x27;
  }
  if (DAT_004da1f8 == 0x6a) {
    param_3 = 0xf;
  }
  if (DAT_004da1f8 == 0x66) {
    param_3 = 0xf;
  }
  if (DAT_004da1f8 == 999) {
    param_3 = 0x19;
  }
  fVar16 = FUN_0047d5f0(iVar8,param_1,param_2,0,0);
  if ((float10)param_3 <= fVar16) {
    DAT_004f4528 = 0;
LAB_004890a7:
    if (iVar8 == 1) {
      DAT_00522cac = 0;
    }
  }
  else {
    FUN_00431200(param_1,param_2);
    DAT_004f4528 = 0;
    iVar10 = DAT_005362d4;
    if (DAT_005362d4 < 0x3c) {
      iVar10 = DAT_005362d4 + 0x168;
    }
    uVar13 = iVar10 - DAT_005229c4 >> 0x1f;
    bVar2 = (int)((iVar10 - DAT_005229c4 ^ uVar13) - uVar13) < 0x28;
    if (bVar2) {
      DAT_004f4528 = 1;
      (&DAT_004fb380)[iVar8] = ((&DAT_004fb380)[iVar8] * 0xc) / 10;
    }
    uVar13 = (uint)bVar2;
    uVar14 = iVar10 - DAT_004fe160 >> 0x1f;
    if ((int)((iVar10 - DAT_004fe160 ^ uVar14) - uVar14) < 0x28) {
      iVar10 = (int)((&DAT_004fb380)[iVar8] << 3) / 10;
      uVar13 = 0xffffffff;
      (&DAT_004fb380)[iVar8] = iVar10;
      DAT_004f4528 = 0xffffffff;
      if (iVar10 < 6) {
        (&DAT_004fb380)[iVar8] = 6;
      }
    }
    if (iVar8 == 1) {
      if (uVar13 != 0) {
        _DAT_004f7ec8 = iVar8;
      }
      goto LAB_004890a7;
    }
  }
  if (iVar8 == 2) {
    DAT_00522d18 = 0;
  }
  iVar10 = 0;
  (&DAT_004fba20)[iVar8] = 0;
  param_3 = (int)&DAT_005357dc;
  iVar15 = 0;
  do {
    dVar6 = dVar3 - *(double *)((int)&DAT_00535468 + iVar15);
    dVar7 = dVar5 - *(double *)((int)&DAT_004f4b10 + iVar15);
    dVar6 = dVar7 * dVar7 + dVar6 * dVar6;
    if ((dVar6 <= _DAT_004cc658) || (_DAT_004cd020 <= dVar6)) {
      iVar11 = 1000;
    }
    else {
      iVar11 = (int)(longlong)SQRT(dVar6);
    }
    if (iVar11 < *(int *)((int)&DAT_004f7ea4 + iVar10)) {
      if (iVar8 == 1) {
        DAT_00522cac = 1;
      }
      if (iVar8 == 2) {
        DAT_00522d18 = 1;
      }
      iVar12 = (&DAT_004fb380)[iVar8] + *(int *)((int)&DAT_004f71dc + iVar10);
      iVar11 = DAT_00522ad0 + 5;
      (&DAT_004fb380)[iVar8] = iVar12;
      if (iVar11 < iVar12) {
        (&DAT_004fb380)[iVar8] = iVar11;
      }
      (&DAT_004fba20)[iVar8] = 1;
      DAT_00523af4 = *(int *)param_3;
    }
    iVar15 = iVar15 + 8;
    iVar10 = iVar10 + 4;
    param_3 = param_3 + 4;
  } while (iVar15 < 0x21);
  if ((&DAT_004fba20)[iVar8] == 0) {
    if (DAT_0053645c == 0) {
      iVar15 = (&DAT_004fb380)[iVar8];
      iVar10 = DAT_00522ad0;
    }
    else {
      iVar10 = (&DAT_004fb380)[iVar8];
      iVar15 = DAT_00522ad0;
    }
    DAT_00523af4 = FUN_0041bc20(DAT_005362d4 + (iVar15 - iVar10) * 3);
  }
  _DAT_005364f0 = 0;
  if ((0 < DAT_005364b4) && (param_3 = 1, 0 < DAT_005364b4)) {
    do {
      if ((param_3 != 1) || ((-1 < param_1 || (DAT_004da1f8 != 6)))) {
        iVar10 = *(int *)(param_3 * 4 + 0x4fbac0);
        uVar13 = DAT_005362d4 - iVar10 >> 0x1f;
        iVar15 = (DAT_005362d4 - iVar10 ^ uVar13) - uVar13;
        if ((iVar15 < 0x1e) &&
           (((cVar1 != '\0' && (_DAT_004cc490 < dVar4)) &&
            (DAT_0053545c = 1, DAT_00523af4 = iVar10, iVar8 == 1)))) {
          _DAT_005364f0 = 1;
        }
        if (((0x14a < iVar15) && (cVar1 != '\0')) &&
           ((_DAT_004cc490 < dVar4 && (DAT_0053545c = 2, DAT_00523af4 = iVar10, iVar8 == 1)))) {
          _DAT_005364f0 = 2;
        }
      }
      param_3 = param_3 + 1;
    } while (param_3 <= DAT_005364b4);
  }
  if (DAT_004da1f8 == 0x67) {
    if (((0xd2 < DAT_005362d4) && (DAT_005362d4 < 0x10e)) &&
       (iVar10 = FUN_0047def0(-0x11f8,0x1040,0xa7d,0x1b8,-0xe6,0x974,param_1,param_2), iVar10 == 1))
    {
      DAT_00523af4 = (DAT_005362d4 + 0xf0) / 2;
      DAT_0053545c = 1;
      if (iVar8 == 1) {
        _DAT_005364f0 = 1;
      }
    }
    if (((0x122 < DAT_005362d4) && (DAT_005362d4 < 0x15e)) &&
       (iVar10 = FUN_0047dfa0(-0x3b3,0x212,-0x11f8,-0x125c,-0x44c,0xb2c,param_1,param_2),
       iVar10 == 1)) {
      DAT_00523af4 = (DAT_005362d4 + 0x140) / 2;
      DAT_0053545c = 1;
      if (iVar8 == 1) {
        _DAT_005364f0 = 1;
      }
    }
    if (((0x23 < DAT_005362d4) && (DAT_005362d4 < 0x5f)) &&
       (iVar10 = FUN_0047def0(0x2b2,0x17c,-800,0x1450,-0xc4e,-0x640,param_1,param_2), iVar10 == 1))
    {
      DAT_00523af4 = (DAT_005362d4 + 0x41) / 2;
      DAT_0053545c = 1;
      if (iVar8 == 1) {
        _DAT_005364f0 = 1;
      }
    }
  }
  if (DAT_004da1f8 == 100) {
    if (((0x13b < DAT_005362d4) && (DAT_005362d4 < 0x168)) &&
       (iVar10 = FUN_0047dfa0(-3000,0,-0x157c,-0x14b4,-0x898,1000,param_1,param_2), iVar10 == 1)) {
      DAT_00523af4 = (DAT_005362d4 + 0x15e) / 2;
      DAT_0053545c = 1;
      if (iVar8 == 1) {
        _DAT_005364f0 = 1;
      }
    }
    if (((-1 < DAT_005362d4) && (DAT_005362d4 < 0x10)) &&
       (iVar10 = FUN_0047dfa0(-3000,0,-0x157c,-0x14b4,-0x898,1000,param_1,param_2), iVar10 == 1)) {
      DAT_00523af4 = FUN_0041bc20((DAT_005362d4 + 0x2c1) / 2);
      DAT_0053545c = 1;
      if (iVar8 == 1) {
        _DAT_005364f0 = iVar8;
      }
    }
    if (((0x2c < DAT_005362d4) && (DAT_005362d4 < 0x6a)) &&
       (iVar10 = FUN_0047def0(-0x848,0x852,-0x79e,0x254e,-0x125c,-0x104,param_1,param_2),
       iVar10 == 1)) {
      DAT_00523af4 = (DAT_005362d4 + 0x4b) / 2;
      DAT_0053545c = 1;
      if (iVar8 == 1) {
        _DAT_005364f0 = 1;
      }
    }
  }
  if (DAT_004da1f8 == 0x65) {
    if (((0x27 < DAT_005362d4) && (DAT_005362d4 < 0x65)) &&
       (iVar10 = FUN_0047def0(-400,0x3a2,-0xb54,0x189c,-0x16a8,-900,param_1,param_2), iVar10 == 1))
    {
      DAT_00523af4 = (DAT_005362d4 + 0x46) / 2;
      DAT_0053545c = 1;
      if (iVar8 == 1) {
        _DAT_005364f0 = 1;
      }
    }
    if (((0x81 < DAT_005362d4) && (DAT_005362d4 < 0xbf)) &&
       (iVar10 = FUN_0047dfa0(0xf82,0x168a,700,0,0x1518,0x16da,param_1,param_2), iVar10 == 1)) {
      DAT_0053545c = 1;
      DAT_00523af4 = (DAT_005362d4 + 0xa0) / 2;
      if (iVar8 == 1) {
        _DAT_005364f0 = 1;
      }
    }
  }
  iVar15 = DAT_0053545c;
  iVar10 = DAT_00523af4;
  if (0 < DAT_0053545c) {
    (&DAT_004fb380)[iVar8] = (&DAT_004fb380)[iVar8] + 2;
  }
  if ((iVar8 != 1) || (DAT_00534f44 = iVar8, iVar15 < 1)) {
    DAT_00534f44 = 0;
  }
  uVar13 = *(uint *)(&DAT_00535a08 + iVar8 * 4);
  iVar15 = (uVar13 ^ (int)uVar13 >> 0x1f) - ((int)uVar13 >> 0x1f);
  if (1 < iVar15) {
    uVar14 = *(int *)(&DAT_00522d30 + iVar8 * 4) - (&DAT_00522b90)[iVar8] >> 0x1f;
    iVar11 = (*(int *)(&DAT_00522d30 + iVar8 * 4) - (&DAT_00522b90)[iVar8] ^ uVar14) - uVar14;
    *(int *)(&DAT_004f8cd8 + iVar8 * 4) = iVar11;
    if (0xb4 < iVar11) {
      *(int *)(&DAT_004f8cd8 + iVar8 * 4) = 0x168 - iVar11;
    }
    (&DAT_004fb380)[iVar8] =
         (&DAT_004fb380)[iVar8] +
         (int)((&DAT_004f1740)[*(int *)(&DAT_004f8cd8 + iVar8 * 4)] * uVar13) / 1000;
  }
  iVar12 = DAT_00522ad0;
  iVar11 = DAT_00522ad0 / 10;
  (&DAT_00522b90)[iVar8] = iVar10;
  *(int *)(&DAT_00535e40 + iVar8 * 4) = iVar11 + 1;
  if ((iVar8 == 1) && (DAT_004fb384 <= iVar12)) {
    DAT_00535e44 = DAT_004fb384 / 10 + 1;
  }
  if (iVar9 < DAT_004da218) {
    *(int *)(&DAT_00535e40 + iVar8 * 4) = *(int *)(&DAT_00535e40 + iVar8 * 4) + -1;
  }
  if (*(int *)(&DAT_00535e40 + iVar8 * 4) < 0) {
    *(undefined4 *)(&DAT_00535e40 + iVar8 * 4) = 0;
  }
  if (4 < *(int *)(&DAT_00535e40 + iVar8 * 4)) {
    *(undefined4 *)(&DAT_00535e40 + iVar8 * 4) = 4;
  }
  *(undefined4 *)(&DAT_004f69c0 + iVar8 * 4) = 0;
  if ((0x87 < *(int *)(&DAT_004f8cd8 + iVar8 * 4)) && (6 < iVar15)) {
    *(undefined4 *)(&DAT_004f69c0 + iVar8 * 4) = 1;
    *(int *)(&DAT_00535e40 + iVar8 * 4) = *(int *)(&DAT_00535e40 + iVar8 * 4) + 1;
  }
  if (((*(int *)(&DAT_004f8cd8 + iVar8 * 4) < 0x2d) && (6 < iVar15)) &&
     (0 < *(int *)(&DAT_00535e40 + iVar8 * 4))) {
    *(undefined4 *)(&DAT_004f69c0 + iVar8 * 4) = 0xffffffff;
    *(int *)(&DAT_00535e40 + iVar8 * 4) = *(int *)(&DAT_00535e40 + iVar8 * 4) + -1;
  }
  if (*(int *)(&DAT_00535e40 + iVar8 * 4) < 0) {
    *(undefined4 *)(&DAT_00535e40 + iVar8 * 4) = 0;
  }
  if (5 < *(int *)(&DAT_00535e40 + iVar8 * 4)) {
    *(undefined4 *)(&DAT_00535e40 + iVar8 * 4) = 5;
  }
  DAT_00535e30 = *(undefined4 *)(&DAT_00535e40 + iVar8 * 4);
  if ((0 < iVar8) && (DAT_004f42b8 + 1 < DAT_004f8cd0)) {
    uVar13 = local_1c - iVar10 >> 0x1f;
    if ((int)((local_1c - iVar10 ^ uVar13) - uVar13) < 0xb4) {
      iVar10 = (int)((ulonglong)((longlong)(iVar10 + local_1c * 9) * 0x66666667) >> 0x20);
    }
    else {
      if ((0x10e < local_1c) && (iVar10 < 0x5a)) {
        iVar10 = FUN_0041bc20((iVar10 + (local_1c + -0x168) * 9) / 10);
        DAT_00523af4 = iVar10;
      }
      if ((0x59 < local_1c) || (0x10d < iVar10)) goto LAB_00489934;
      iVar10 = (int)((ulonglong)((longlong)(iVar10 + (local_1c + -0x28) * 9) * 0x66666667) >> 0x20);
    }
    DAT_00523af4 = FUN_0041bc20((iVar10 >> 2) - (iVar10 >> 0x1f));
  }
LAB_00489934:
  return (&DAT_004fb380)[iVar8];
}

