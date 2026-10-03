
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0041bfb0(double param_1,int param_2,int param_3,int param_4,int param_5,double param_6)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  float10 fVar12;
  double local_28;
  
  iVar8 = DAT_0053652c;
  iVar6 = DAT_004da190;
  if (DAT_004da140 < param_2) {
    bVar11 = DAT_004da190 == 10;
    *(undefined4 *)(&DAT_004fe778 + param_2 * 4) = 1;
    *(undefined4 *)(&DAT_004f7ee0 + param_2 * 4) = 1;
    if ((((bVar11) || (DAT_005363c4 == 1)) || (0 < DAT_005363c0)) || ((iVar6 == 8 || (iVar8 == 1))))
    {
      *(undefined4 *)(&DAT_004f42c0 + param_2 * 4) = 3;
    }
    else {
      *(undefined4 *)(&DAT_004f42c0 + param_2 * 4) = 2;
    }
    *(undefined4 *)(&DAT_00535f68 + param_2 * 4) = 0;
  }
  iVar9 = -*(int *)(&DAT_004fe778 + param_2 * 4) + 4;
  if (iVar6 == 1) {
    iVar9 = -*(int *)(&DAT_004fe778 + param_2 * 4) + 5;
  }
  if (DAT_005363cc == 1) {
    iVar9 = 1;
  }
  if (DAT_005363bc == 1) {
    iVar9 = 6;
  }
  iVar6 = (param_5 ^ param_5 >> 0x1f) - (param_5 >> 0x1f);
  dVar2 = _DAT_004cc570;
  if (iVar6 < 0xb) {
    dVar2 = _DAT_004cc770;
  }
  if (((DAT_005363b8 == 1) || (DAT_00536528 == 1)) || (iVar8 == 1)) {
    local_28 = 0.45;
  }
  else {
    local_28 = 0.4;
  }
  _DAT_004feb10 =
       (double)(*(int *)(&DAT_004fc2c0 + param_2 * 4) * *(int *)(&DAT_00522ff0 + param_2 * 4)) *
       param_6 * _DAT_004cc538;
  if (DAT_005363bc == 1) {
    _DAT_004feb10 =
         -((double)*(int *)(&DAT_00522ff0 + param_2 * 4) * (ABS(_DAT_004feb10) - _DAT_004cc780) *
          param_6);
  }
  dVar1 = (double)(iVar9 + -1) * param_1;
  _DAT_004feb10 = _DAT_004feb10 * local_28;
  dVar2 = dVar2 * dVar1;
  _DAT_004feaf0 = _DAT_004feb10 * _DAT_004cc6b8;
  _DAT_00535cf0 = _DAT_004feaf0 + (double)(&DAT_00535c68)[param_3];
  _DAT_004f3ac0 = local_28 * _DAT_004f3f50 + ((&DAT_004f3a38)[param_3] - dVar2 * _DAT_004cc570);
  _DAT_00511410 = local_28;
  if (DAT_005363bc == 1) {
    _DAT_004f3ac0 = _DAT_004f3ac0 - (local_28 + local_28);
  }
  dVar3 = local_28 * _DAT_004cc730;
  dVar2 = dVar2 * _DAT_004cc4f8;
  _DAT_004feaf8 = _DAT_004feb10 * _DAT_004cc788;
  _DAT_00535cf8 = _DAT_004feaf8 + (double)(&DAT_00535c68)[param_3];
  _DAT_004f3ac8 = ((&DAT_004f3a38)[param_3] - dVar2) + _DAT_004f3f50 * dVar3;
  if (DAT_005363bc == 1) {
    _DAT_004f3ac8 = _DAT_004f3ac8 - (dVar3 + dVar3);
  }
  dVar4 = local_28 * _DAT_004cc728;
  _DAT_004feb00 = _DAT_004feb10 * _DAT_004cc790;
  _DAT_00535d00 = _DAT_004feb00 + (double)(&DAT_00535c68)[param_3];
  _DAT_004f3ad0 = ((&DAT_004f3a38)[param_3] - dVar2) + _DAT_004f3f50 * dVar4;
  if (DAT_005363bc == 1) {
    _DAT_004f3ad0 = _DAT_004f3ad0 - (dVar4 + dVar4);
  }
  dVar2 = local_28 * _DAT_004cc7a0;
  _DAT_004feb08 = _DAT_004feb10 * _DAT_004cc798;
  _DAT_00535d08 = _DAT_004feb08 + (double)(&DAT_00535c68)[param_3];
  _DAT_004f3ad8 = _DAT_004f3f50 * dVar2 + (&DAT_004f3a38)[param_3];
  if (DAT_005363bc == 1) {
    _DAT_004f3ad8 = _DAT_004f3ad8 - (dVar2 + dVar2);
  }
  dVar5 = _DAT_004cc570;
  if (iVar6 < 0xb) {
    dVar5 = _DAT_004cc770;
  }
  _DAT_00511430 = local_28 * _DAT_004cc418;
  _DAT_004feb10 = _DAT_004feb10 * _DAT_004cc7a8;
  _DAT_00535d10 = _DAT_004feb10 + (double)(&DAT_00535c68)[param_3];
  _DAT_004f3ae0 = _DAT_004f3f50 * _DAT_00511430 + dVar5 * dVar1 + (&DAT_004f3a38)[param_3];
  if (DAT_005363bc == 1) {
    _DAT_004f3ae0 = _DAT_004f3ae0 - (_DAT_00511430 + _DAT_00511430);
  }
  if (DAT_005363cc == 1) {
    _DAT_004f3ae0 = _DAT_004f3ae0 - dVar5 * param_1 * _DAT_004cc588;
  }
  iVar8 = *(int *)(&DAT_004fe818 + param_2 * 4);
  iVar6 = iVar8 + 5;
  if (0x14 < *(int *)(&DAT_00512278 + param_2 * 4)) {
    iVar6 = iVar8 + 0xf;
  }
  if (0x46 < *(int *)(&DAT_00512278 + param_2 * 4)) {
    iVar6 = 0x28;
  }
  if (param_2 <= DAT_004da140) {
    iVar6 = *(int *)(&DAT_00500380 + param_2 * 4) / 5 + 5 + iVar8;
  }
  if (0x28 < iVar6) {
    iVar6 = 0x28;
  }
  if (DAT_005363bc == 1) {
    iVar6 = (iVar6 * 2) / 3;
    uVar7 = (int)(longlong)_DAT_005355f8 + param_2;
    uVar10 = (int)uVar7 >> 0x1f;
    if (((uVar7 ^ uVar10) - uVar10 & 3 ^ uVar10) == uVar10) {
      iVar6 = iVar6 + -2;
    }
  }
  if (DAT_005363b8 == 1) {
    if (DAT_005364c0 == 1) {
      iVar6 = iVar6 / 5;
    }
    else {
      iVar6 = iVar6 / 2;
    }
  }
  if ((DAT_005363c4 == 1) && (*(int *)(&DAT_005350d8 + param_2 * 4) == 1)) {
    iVar6 = iVar6 / 2;
  }
  if (((DAT_004da190 == 8) || (0 < DAT_005363c0)) && (*(int *)(&DAT_005350d8 + param_2 * 4) == 1)) {
    iVar6 = iVar6 / 2;
  }
  _DAT_00511418 = dVar3;
  _DAT_00511420 = dVar4;
  _DAT_00511428 = dVar2;
  iVar8 = FUN_0041bc20(param_4 / 5 + iVar6);
  dVar1 = DAT_004f3a38;
  if (4 < DAT_004da190) {
    dVar1 = (DAT_004f3a40 - DAT_004f3a38 * _DAT_004cc5c8) * _DAT_004cc7b0;
  }
  param_6 = dVar1 - (&DAT_004f3a38)[param_3];
  if (DAT_005364bc == 1) {
    param_6 = DAT_004f3a40 - _DAT_004f3a58;
  }
  if ((DAT_0053652c == 1) || (DAT_00536530 == 1)) {
    param_6 = DAT_004f3a38 - (&DAT_004f3a38)[param_3];
  }
  if ((DAT_004da190 == 8) || (DAT_005363b8 == 1)) {
    param_6 = (DAT_004f3a40 + DAT_004f3a38) * _DAT_004cc4f8 - (&DAT_004f3a38)[param_3];
  }
  if (DAT_00536528 == 1) {
    param_6 = (DAT_004f3a40 + DAT_004f3a38 + DAT_004f3a40 + DAT_004f3a38) * _DAT_004cc518 -
              (&DAT_004f3a38)[param_3];
  }
  if (DAT_005363bc == 1) {
    param_6 = DAT_004f3a38 - _DAT_004f3a50;
  }
  fVar12 = (float10)fsin((float10)iVar8 * (float10)_DAT_004cc568);
  fVar12 = (float10)_DAT_004feaf0 -
           (float10)*(int *)(&DAT_00522ff0 + param_2 * 4) * fVar12 * (float10)param_6;
  _DAT_004f3b00 =
       local_28 * _DAT_004f3f50 +
       ((&DAT_004f3a38)[param_3] - (double)(int)(&DAT_004f1740)[iVar8] * param_6 * _DAT_004cc678);
  _DAT_004feb30 = (double)fVar12;
  _DAT_00511450 = local_28;
  _DAT_00535d30 = (double)(fVar12 + (float10)(double)(&DAT_00535c68)[param_3]);
  iVar8 = FUN_0041bc20(((int)(param_4 * 2 + (param_4 * 2 >> 0x1f & 3U)) >> 2) + iVar6);
  fVar12 = (float10)fsin((float10)iVar8 * (float10)_DAT_004cc568);
  fVar12 = (float10)_DAT_004feaf8 -
           (float10)*(int *)(&DAT_00522ff0 + param_2 * 4) * fVar12 * (float10)param_6 *
           (float10)_DAT_004cc7b8;
  _DAT_004f3af8 =
       _DAT_004f3f50 * dVar3 +
       ((&DAT_004f3a38)[param_3] - (double)(int)(&DAT_004f1740)[iVar8] * param_6 * _DAT_004cc7c0);
  _DAT_004feb28 = (double)fVar12;
  _DAT_00535d28 = (double)(fVar12 + (float10)(double)(&DAT_00535c68)[param_3]);
  _DAT_00511448 = dVar3;
  iVar8 = FUN_0041bc20(((int)(param_4 * 3 + (param_4 * 3 >> 0x1f & 3U)) >> 2) + iVar6);
  fVar12 = (float10)fsin((float10)iVar8 * (float10)_DAT_004cc568);
  _DAT_004feb20 =
       (double)((float10)_DAT_004feb00 -
               (float10)*(int *)(&DAT_00522ff0 + param_2 * 4) * fVar12 * (float10)param_6 *
               (float10)_DAT_004cc600);
  _DAT_00535d20 = _DAT_004feb20 + (double)(&DAT_00535c68)[param_3];
  _DAT_004f3af0 =
       _DAT_004f3f50 * dVar4 +
       ((&DAT_004f3a38)[param_3] - (double)(int)(&DAT_004f1740)[iVar8] * param_6 * _DAT_004cc7c8);
  _DAT_00511440 = dVar4;
  iVar6 = FUN_0041bc20((param_4 * 4) / 5 + iVar6);
  fVar12 = (float10)fsin((float10)iVar6 * (float10)_DAT_004cc568);
  fVar12 = (float10)_DAT_004feb08 -
           (float10)*(int *)(&DAT_00522ff0 + param_2 * 4) * fVar12 * (float10)param_6 *
           (float10)_DAT_004cc7d0;
  _DAT_004f3ae8 =
       _DAT_004f3f50 * dVar2 +
       ((&DAT_004f3a38)[param_3] - (double)(int)(&DAT_004f1740)[iVar6] * param_6 * _DAT_004cc7d8);
  _DAT_004feb18 = (double)fVar12;
  _DAT_00535d18 = (double)(fVar12 + (float10)(double)(&DAT_00535c68)[param_3]);
  _DAT_00511438 = dVar2;
  if (DAT_004da190 != 1) {
    iVar6 = (*(int *)(&DAT_004fecc8 + param_2 * 4) + -0x1e) / 3;
    if (((DAT_005364c0 == 1) || (DAT_005363c4 == 1)) && (*(int *)(&DAT_005350d8 + param_2 * 4) == 1)
       ) {
      iVar6 = iVar6 / 2;
    }
    if (0x18 < iVar6) {
      iVar6 = 0x18;
    }
    if (iVar6 < 2) {
      iVar6 = 2;
    }
    param_6 = (*(double *)(&DAT_004f3a30 + param_3 * 8) + (&DAT_004f3a38)[param_3]) * _DAT_004cc4f8
              - _DAT_004f3a60;
    if ((6 < DAT_004da190) && (DAT_005363b8 == 0)) {
      param_6 = (_DAT_004cc418 / (double)(*(int *)(&DAT_004f7ee0 + param_2 * 4) + 6)) * param_6;
    }
    if ((DAT_005363b8 == 1) || (DAT_005364c8 == 1)) {
      param_6 = param_6 * _DAT_004cc508;
    }
    if ((DAT_004da190 == 8) || (DAT_005364c4 == 1)) {
      param_6 = param_6 * _DAT_004cc6b0;
    }
    if (DAT_004fb410 == 1) {
      param_6 = param_6 * _DAT_004cc7e0;
    }
    if ((DAT_005364bc == 1) || (DAT_0053652c == 1)) {
      param_6 = param_6 * _DAT_004cc7e0;
    }
    if (DAT_00536528 == 1) {
      param_6 = param_6 * _DAT_004cc600;
    }
    if (DAT_00536530 == 1) {
      param_6 = param_6 * _DAT_004cc600;
    }
    if ((((DAT_004da190 == 2) || (DAT_005364c4 == 1)) || (DAT_005364c8 == 1)) &&
       (*(int *)(&DAT_005350d8 + param_2 * 4) == 1)) {
      bVar11 = true;
    }
    else {
      bVar11 = false;
    }
    iVar6 = iVar6 + 0xb;
    if (bVar11) {
      iVar6 = 0x50;
    }
    iVar6 = FUN_0041bc20(iVar6);
    fVar12 = (float10)fsin((float10)iVar6 * (float10)_DAT_004cc568);
    _DAT_004f3b08 = _DAT_004f3a60 - (double)(int)(&DAT_004f1740)[iVar6] * param_6 * _DAT_004cc678;
    _DAT_004feb38 =
         (double)-((float10)*(int *)(&DAT_00522ff0 + param_2 * 4) * fVar12 * (float10)param_6);
    if (bVar11) {
      _DAT_004feb38 = _DAT_004feb38 * _DAT_004cc7e8;
    }
    _DAT_00535d38 = _DAT_004feb38 + _DAT_00535c90;
    if ((0 < *(int *)(&DAT_005350d8 + param_2 * 4)) && (2 < DAT_004da190)) {
      iVar6 = *(int *)(&DAT_004fecc8 + param_2 * 4) + -0x70;
      if (iVar6 < 0x14) {
        iVar6 = 0x14;
      }
      if ((param_2 == 1) && (DAT_004f42c4 == 3)) {
        iVar6 = 0x14;
      }
      if ((1 < param_2) && (DAT_004da190 == 8)) {
        iVar6 = 0x14;
      }
      param_6 = (&DAT_004f3a38)[param_3] - _DAT_004f3a60;
      if ((((DAT_005363b8 == 1) || (0 < DAT_005363c0)) || (DAT_005363c4 == 1)) ||
         (DAT_0053652c == 1)) {
        param_6 = param_6 * _DAT_004cc7f0;
        iVar6 = 0xd;
      }
      if ((DAT_004da190 == 3) && (DAT_005363c4 == 0)) {
        param_6 = param_6 * _DAT_004cc7f0;
      }
      iVar8 = FUN_0041bc20(iVar6);
      dVar1 = (double)(int)(&DAT_004f1740)[iVar8] * param_6;
      dVar2 = (double)*(int *)(&DAT_00522ff0 + param_2 * 4) *
              (double)(int)(&DAT_004f85c8)[iVar8] * param_6;
      DAT_004feb40 = _DAT_004feaf0 - dVar2 * _DAT_004cc678;
      DAT_004f3b10 = (&DAT_004f3a38)[param_3] - dVar1 * _DAT_004cc3f0;
      DAT_00535d40 = DAT_004feb40 + (double)(&DAT_00535c68)[param_3];
      if (DAT_005363b8 == 1) {
        DAT_00535d40 = (double)(&DAT_00535c68)[param_3];
        DAT_004f3b10 = _DAT_004f3a60 - (_DAT_004f3a60 - (&DAT_004f3a38)[param_3]) * _DAT_004cc7f8;
      }
      DAT_004feb48 = _DAT_004feaf8 - dVar2 * _DAT_004cc800;
      _DAT_004feb50 = _DAT_004feb00 - dVar2 * _DAT_004cc678;
      DAT_004f3b18 = (&DAT_004f3a38)[param_3] - dVar1 * _DAT_004cc808;
      DAT_00535d48 = DAT_004feb48 + (double)(&DAT_00535c68)[param_3];
      _DAT_004feb58 = _DAT_004feb08 - dVar2 * _DAT_004cc810;
      _DAT_004f3b20 = (&DAT_004f3a38)[param_3] - dVar1 * _DAT_004cc3f0;
      _DAT_00535d50 = _DAT_004feb50 + (double)(&DAT_00535c68)[param_3];
      _DAT_00535d58 = _DAT_004feb58 + (double)(&DAT_00535c68)[param_3];
      _DAT_004f3b28 = (&DAT_004f3a38)[param_3] - dVar1 * _DAT_004cc818;
      iVar8 = FUN_0041bc20(iVar6 + -0x3c);
      dVar2 = (double)*(int *)(&DAT_00522ff0 + param_2 * 4) *
              (double)(int)(&DAT_004f85c8)[iVar8] * param_6 * _DAT_004cc820;
      dVar1 = (double)(int)(&DAT_004f1740)[iVar8] * param_6 * _DAT_004cc820;
      _DAT_004feb60 = _DAT_004feaf0 - dVar2 * _DAT_004cc678;
      _DAT_004feb68 = _DAT_004feaf8 - dVar2 * _DAT_004cc800;
      _DAT_00535d60 = _DAT_004feb60 + (double)(&DAT_00535c68)[param_3];
      _DAT_004feb70 = _DAT_004feb00 - dVar2 * _DAT_004cc678;
      _DAT_00535d68 = _DAT_004feb68 + (double)(&DAT_00535c68)[param_3];
      _DAT_004f3b30 = (&DAT_004f3a38)[param_3] - dVar1 * _DAT_004cc3f0;
      _DAT_00535d70 = _DAT_004feb70 + (double)(&DAT_00535c68)[param_3];
      _DAT_004f3b38 = (&DAT_004f3a38)[param_3] - dVar1 * _DAT_004cc808;
      _DAT_004f3b40 = (&DAT_004f3a38)[param_3] - dVar1 * _DAT_004cc3f0;
      _DAT_004feb78 = _DAT_004feb08 - dVar2 * _DAT_004cc810;
      _DAT_00535d78 = _DAT_004feb78 + (double)(&DAT_00535c68)[param_3];
      _DAT_004f3b48 = (&DAT_004f3a38)[param_3] - dVar1 * _DAT_004cc818;
      iVar6 = FUN_0041bc20(iVar6 + -0x82);
      dVar1 = (double)*(int *)(&DAT_00522ff0 + param_2 * 4) *
              (double)(int)(&DAT_004f85c8)[iVar6] * ((&DAT_004f3a38)[param_3] - _DAT_004f3a60);
      dVar2 = (double)(int)(&DAT_004f1740)[iVar6] * ((&DAT_004f3a38)[param_3] - _DAT_004f3a60);
      _DAT_004feb80 = _DAT_004feaf0 - dVar1 * _DAT_004cc678;
      _DAT_004feb88 = _DAT_004feaf8 - dVar1 * _DAT_004cc800;
      _DAT_004f3b50 = (&DAT_004f3a38)[param_3] - dVar2 * _DAT_004cc3f0;
      _DAT_00535d80 = _DAT_004feb80 + (double)(&DAT_00535c68)[param_3];
      _DAT_004feb90 = _DAT_004feb00 - dVar1 * _DAT_004cc678;
      _DAT_00535d88 = _DAT_004feb88 + (double)(&DAT_00535c68)[param_3];
      _DAT_004f3b58 = (&DAT_004f3a38)[param_3] - dVar2 * _DAT_004cc808;
      _DAT_004feb98 = _DAT_004feb08 - dVar1 * _DAT_004cc810;
      _DAT_004f3b60 = (&DAT_004f3a38)[param_3] - dVar2 * _DAT_004cc3f0;
      _DAT_00535d90 = _DAT_004feb90 + (double)(&DAT_00535c68)[param_3];
      _DAT_00535d98 = _DAT_004feb98 + (double)(&DAT_00535c68)[param_3];
      _DAT_004f3b68 = (&DAT_004f3a38)[param_3] - dVar2 * _DAT_004cc818;
    }
  }
  return;
}

