
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041a5e0(double param_1,double param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  double *pdVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  
  iVar5 = param_4;
  iVar1 = DAT_00536530;
  iVar12 = DAT_0053652c;
  iVar9 = DAT_005363c4;
  iVar7 = DAT_004da190;
  dVar3 = _DAT_004cc600;
  if (((DAT_005363cc != 1) && (DAT_005363c0 < 2)) && (DAT_0053652c != 1)) {
    dVar3 = _DAT_004cc650;
  }
  if ((((DAT_004fb410 == 1) || (DAT_005364d0 == 1)) ||
      ((DAT_004da190 == 4 || ((DAT_004da190 == 5 && (DAT_0053652c == 0)))))) || (DAT_005364bc == 1))
  {
    dVar3 = _DAT_004cc6b0;
  }
  if (((DAT_00536530 == 1) || (DAT_005363c8 == 1)) || (DAT_005363c4 == 1)) {
    dVar3 = _DAT_004cc600;
  }
  fVar13 = (float10)dVar3;
  if ((DAT_004da190 == 3) && (DAT_005363c4 == 0)) {
    fVar13 = (float10)_DAT_004cc600;
  }
  dVar3 = param_1 * _DAT_004cc570;
  iVar6 = 0;
  do {
    iVar11 = iVar6 + -2;
    (&DAT_00535c68)[iVar6] = _DAT_00535c78;
    iVar6 = iVar6 + 1;
    *(double *)(&DAT_004f3a30 + iVar6 * 8) = _DAT_004f3a48 - (double)iVar11 * dVar3;
  } while (iVar6 < 6);
  _DAT_004f3a90 = DAT_004f3a38 - dVar3 * _DAT_004cc6b8;
  _DAT_00535cc0 = DAT_00535c68;
  dVar2 = param_2;
  fVar14 = (float10)param_2;
  if ((iVar12 == 0) || (0 < param_4)) {
    param_1._0_4_ = 1;
    param_2._0_4_ = 0x1d;
    iVar7 = 0;
    pdVar10 = (double *)&DAT_00535cb8;
    do {
      dVar4 = (double)param_1._0_4_;
      fVar15 = (float10)_DAT_00535c90;
      fVar16 = (float10)fsin((float10)param_2._0_4_ * fVar13 * (float10)_DAT_004cc568);
      param_2._0_4_ = param_2._0_4_ + 0x1d;
      param_1._0_4_ = param_1._0_4_ + 1;
      *(double *)((int)&DAT_004f3a88 + iVar7) =
           dVar4 * dVar3 + (double)CONCAT44(_DAT_004f3a64,_DAT_004f3a60);
      fVar16 = fVar16 * fVar14 * (float10)_DAT_004cc6c0;
      *(double *)((int)&DAT_004feab8 + iVar7) = (double)fVar16;
      *pdVar10 = (double)(fVar15 + fVar16);
      iVar7 = iVar7 + -8;
      pdVar10 = pdVar10 + -1;
    } while (param_2._0_4_ < 0x92);
    iVar6 = 0xc;
    iVar11 = 0x15c;
    iVar12 = 0;
    pdVar10 = (double *)&DAT_00535cc8;
    do {
      iVar7 = iVar6 + -0xb;
      fVar15 = (float10)_DAT_00535c90;
      fVar16 = (float10)fsin((float10)(iVar11 + -0x13f) * fVar13 * (float10)_DAT_004cc568);
      iVar8 = iVar12 + 8;
      iVar6 = iVar6 + 1;
      iVar11 = iVar11 + 0x1d;
      *(double *)((int)&DAT_004f3a98 + iVar12) =
           (double)iVar7 * dVar3 + (double)CONCAT44(_DAT_004f3a64,_DAT_004f3a60);
      fVar16 = fVar16 * fVar14 * (float10)_DAT_004cc6c8;
      *(double *)((int)&DAT_004feac8 + iVar12) = (double)fVar16;
      *pdVar10 = (double)(fVar15 + fVar16);
      iVar12 = iVar8;
      iVar9 = DAT_005363c4;
      iVar7 = DAT_004da190;
      pdVar10 = pdVar10 + 1;
    } while (iVar8 < 0x21);
  }
  if (((iVar1 == 1) || (((iVar7 == 3 && (iVar9 == 0)) || (DAT_005363c8 == 1)))) &&
     ((param_4 == 0 && (DAT_0053652c == 0)))) {
    param_4 = 1;
    iVar9 = 0x122;
    iVar7 = 0;
    pdVar10 = (double *)&DAT_00535cb8;
    do {
      dVar4 = (double)param_4;
      fVar15 = (float10)_DAT_00535c90;
      iVar12 = iVar9 / 9;
      iVar9 = iVar9 + 0x122;
      param_4 = param_4 + 1;
      *(double *)((int)&DAT_004f3a88 + iVar7) =
           ((double)CONCAT44(_DAT_004f3a64,_DAT_004f3a60) - _DAT_004cc580) -
           dVar4 * dVar3 * _DAT_004cc6d0;
      fVar16 = (float10)fsin((float10)iVar12 * fVar13 * (float10)_DAT_004cc568);
      fVar16 = ((float10)_DAT_004cc6d8 - fVar16 * (float10)_DAT_004cc6c8) * fVar14;
      *(double *)((int)&DAT_004feab8 + iVar7) = (double)fVar16;
      *pdVar10 = (double)(fVar15 + fVar16);
      iVar7 = iVar7 + -8;
      pdVar10 = pdVar10 + -1;
    } while (iVar9 < 0x5ab);
    fVar15 = (float10)_DAT_004cc6d8;
    iVar9 = 0xc;
    iVar12 = 0xd98;
    iVar7 = 0;
    pdVar10 = (double *)&DAT_00535cc8;
    do {
      iVar1 = iVar12 + -0xc76;
      iVar12 = iVar12 + 0x122;
      *(double *)((int)&DAT_004f3a98 + iVar7) =
           ((double)CONCAT44(_DAT_004f3a64,_DAT_004f3a60) - _DAT_004cc580) -
           (double)(iVar9 + -0xb) * dVar3 * _DAT_004cc6d0;
      iVar6 = iVar7 + 8;
      iVar9 = iVar9 + 1;
      fVar16 = (float10)fsin((float10)(iVar1 / 9) * fVar13 * (float10)_DAT_004cc568);
      fVar16 = fVar16 * fVar14 * (float10)_DAT_004cc6c8 - fVar14 * fVar15;
      *(double *)((int)&DAT_004feac8 + iVar7) = (double)fVar16;
      *pdVar10 = (double)((float10)_DAT_00535c90 + fVar16);
      iVar7 = iVar6;
      pdVar10 = pdVar10 + 1;
    } while (iVar6 < 0x21);
  }
  if ((DAT_0053652c == 1) && (iVar5 == 0)) {
    iVar7 = 10;
    do {
      (&DAT_004f3a38)[iVar7] =
           ((double)CONCAT44(_DAT_004f3a64,_DAT_004f3a60) - _DAT_004cc580) -
           (double)(0xb - iVar7) * dVar3 * _DAT_004cc6d0;
      fVar15 = (float10)fsin((float10)(((0xb - iVar7) * 0x13f) / 9) * fVar13 *
                             (float10)_DAT_004cc568);
      (&DAT_004fea68)[iVar7] =
           (double)(((float10)_DAT_004cc668 - fVar15 * (float10)_DAT_004cc6c8) * fVar14);
      if (iVar7 == 10) {
        DAT_004feab8 = (double)(fVar14 * (float10)_DAT_004cc630);
      }
      iVar9 = iVar7 + -1;
      (&DAT_00535c68)[iVar7] = _DAT_00535c90 + (double)(&DAT_004fea68)[iVar7];
      iVar7 = iVar9;
    } while (5 < iVar9);
    fVar15 = (float10)_DAT_004cc668;
    iVar7 = 0xc;
    do {
      (&DAT_004f3a38)[iVar7] =
           ((double)CONCAT44(_DAT_004f3a64,_DAT_004f3a60) - _DAT_004cc580) -
           (double)(iVar7 + -0xb) * dVar3 * _DAT_004cc6d0;
      param_4 = ((iVar7 + -0xb) * 0x13f) / 9;
      fVar16 = (float10)fsin((float10)param_4 * fVar13 * (float10)_DAT_004cc568);
      (&DAT_004fea68)[iVar7] = (double)(fVar16 * fVar14 * (float10)_DAT_004cc6c8 - fVar14 * fVar15);
      if (iVar7 == 0xc) {
        DAT_004feac8 = (double)(fVar14 * (float10)_DAT_004cc6d0);
      }
      iVar9 = iVar7 + 1;
      (&DAT_00535c68)[iVar7] = _DAT_00535c90 + (double)(&DAT_004fea68)[iVar7];
      iVar7 = iVar9;
    } while (iVar9 < 0x11);
    if (((DAT_004f4b48 <= param_3) && (DAT_004f71c4 < 3)) || (DAT_00536458 == 1)) {
      if (DAT_004f71c4 == 1) {
        param_4 = 0x24;
      }
      if (DAT_004f71c4 == 2) {
        param_4 = 0x1b;
      }
      if (DAT_004f71c4 == 3) {
        param_4 = 0xf;
      }
      if (DAT_004da140 < param_5) {
        param_4 = param_4 + -5;
      }
      if (param_3 < (int)(longlong)(_DAT_005230b0 * _DAT_004cc660)) {
        param_4 = 5;
      }
      if (DAT_00536458 == 1) {
        param_4 = 0x17;
      }
      iVar7 = 10;
      do {
        (&DAT_004f3a38)[iVar7] =
             ((double)CONCAT44(_DAT_004f3a64,_DAT_004f3a60) - (double)param_4) -
             (double)(0xb - iVar7) * dVar3 * _DAT_004cc6e0;
        fVar16 = (float10)fsin((float10)(((0xb - iVar7) * 0x13f) / 9) * fVar13 *
                               (float10)_DAT_004cc568);
        (&DAT_004fea68)[iVar7] =
             (double)(((float10)_DAT_004cc668 - fVar16 * (float10)_DAT_004cc6c8) * fVar14);
        if (iVar7 == 10) {
          DAT_004feab8 = dVar2;
        }
        iVar9 = iVar7 + -1;
        (&DAT_00535c68)[iVar7] = _DAT_00535c90 + (double)(&DAT_004fea68)[iVar7];
        iVar7 = iVar9;
      } while (5 < iVar9);
      iVar7 = 0xc;
      do {
        (&DAT_004f3a38)[iVar7] =
             ((double)CONCAT44(_DAT_004f3a64,_DAT_004f3a60) - (double)param_4) -
             (double)(iVar7 + -0xb) * dVar3 * _DAT_004cc6e0;
        fVar16 = (float10)fsin((float10)(((iVar7 + -0xb) * 0x13f) / 9) * fVar13 *
                               (float10)_DAT_004cc568);
        (&DAT_004fea68)[iVar7] =
             (double)(fVar16 * fVar14 * (float10)_DAT_004cc6c8 - fVar14 * fVar15);
        if (iVar7 == 0xc) {
          DAT_004feac8 = (double)-fVar14;
        }
        iVar9 = iVar7 + 1;
        (&DAT_00535c68)[iVar7] = _DAT_00535c90 + (double)(&DAT_004fea68)[iVar7];
        iVar7 = iVar9;
      } while (iVar9 < 0x11);
    }
  }
  if (DAT_005363cc == 1) {
    _DAT_004f3a60 = DAT_004f3a58;
    _DAT_004f3a64 = DAT_004f3a5c;
  }
  return;
}

