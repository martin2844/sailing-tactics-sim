
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00414010(double param_1,int param_2,int param_3,int param_4,int param_5,double param_6)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  float10 fVar11;
  float10 fVar12;
  double local_28;
  
  iVar6 = DAT_00491188;
  if (DAT_00491140 < param_2) {
    bVar10 = DAT_00491188 == 10;
    *(undefined4 *)(&DAT_004a7768 + param_2 * 4) = 1;
    *(undefined4 *)(&DAT_004a4ef8 + param_2 * 4) = 1;
    if ((((bVar10) || (DAT_004ac90c == 1)) || (DAT_004ac908 == 1)) || (iVar6 == 8)) {
      *(undefined4 *)(&DAT_004a4170 + param_2 * 4) = 3;
    }
    else {
      *(undefined4 *)(&DAT_004a4170 + param_2 * 4) = 2;
    }
    *(undefined4 *)(&DAT_004ac5f0 + param_2 * 4) = 0;
  }
  iVar8 = -*(int *)(&DAT_004a7768 + param_2 * 4) + 4;
  if (iVar6 == 1) {
    iVar8 = -*(int *)(&DAT_004a7768 + param_2 * 4) + 5;
  }
  if (DAT_004ac914 == 1) {
    iVar8 = 1;
  }
  if (DAT_004ac904 == 1) {
    iVar8 = 6;
  }
  iVar6 = (param_5 ^ param_5 >> 0x1f) - (param_5 >> 0x1f);
  dVar2 = _DAT_00484d48;
  if (iVar6 < 0xb) {
    dVar2 = _DAT_00484f10;
  }
  if (DAT_004ac900 == 1) {
    local_28 = 0.45;
  }
  else {
    local_28 = 0.4;
  }
  _DAT_004a7aa0 =
       (double)(*(int *)(&DAT_004a6ec8 + param_2 * 4) * *(int *)(&DAT_004aa730 + param_2 * 4)) *
       param_6 * _DAT_00484f20;
  if (DAT_004ac904 == 1) {
    _DAT_004a7aa0 =
         -((double)*(int *)(&DAT_004aa730 + param_2 * 4) * (ABS(_DAT_004a7aa0) - _DAT_00484f28) *
          param_6);
  }
  dVar1 = (double)(iVar8 + -1) * param_1;
  _DAT_004a7aa0 = _DAT_004a7aa0 * local_28;
  dVar2 = dVar2 * dVar1;
  _DAT_004a7a80 = _DAT_004a7aa0 * _DAT_00484e48;
  _DAT_004ac398 = _DAT_004a7a80 + (double)(&DAT_004ac310)[param_3];
  _DAT_004a3ac0 = local_28 * _DAT_004a3ef0 + ((&DAT_004a3a38)[param_3] - dVar2 * _DAT_00484d48);
  _DAT_004a8710 = local_28;
  if (DAT_004ac904 == 1) {
    _DAT_004a3ac0 = _DAT_004a3ac0 - (local_28 + local_28);
  }
  dVar3 = local_28 * _DAT_00484eb8;
  dVar2 = dVar2 * _DAT_00484da8;
  _DAT_004a7a88 = _DAT_004a7aa0 * _DAT_00484f30;
  _DAT_004ac3a0 = _DAT_004a7a88 + (double)(&DAT_004ac310)[param_3];
  _DAT_004a3ac8 = ((&DAT_004a3a38)[param_3] - dVar2) + _DAT_004a3ef0 * dVar3;
  if (DAT_004ac904 == 1) {
    _DAT_004a3ac8 = _DAT_004a3ac8 - (dVar3 + dVar3);
  }
  dVar4 = local_28 * _DAT_00484ea8;
  _DAT_004a7a90 = _DAT_004a7aa0 * _DAT_00484f38;
  _DAT_004ac3a8 = _DAT_004a7a90 + (double)(&DAT_004ac310)[param_3];
  _DAT_004a3ad0 = ((&DAT_004a3a38)[param_3] - dVar2) + _DAT_004a3ef0 * dVar4;
  if (DAT_004ac904 == 1) {
    _DAT_004a3ad0 = _DAT_004a3ad0 - (dVar4 + dVar4);
  }
  dVar2 = local_28 * _DAT_00484f48;
  _DAT_004a7a98 = _DAT_004a7aa0 * _DAT_00484f40;
  _DAT_004ac3b0 = _DAT_004a7a98 + (double)(&DAT_004ac310)[param_3];
  _DAT_004a3ad8 = _DAT_004a3ef0 * dVar2 + (&DAT_004a3a38)[param_3];
  if (DAT_004ac904 == 1) {
    _DAT_004a3ad8 = _DAT_004a3ad8 - (dVar2 + dVar2);
  }
  dVar5 = _DAT_00484d48;
  if (iVar6 < 0xb) {
    dVar5 = _DAT_00484f10;
  }
  _DAT_004a8730 = local_28 * _DAT_00484f58;
  _DAT_004a7aa0 = _DAT_004a7aa0 * _DAT_00484f50;
  _DAT_004ac3b8 = _DAT_004a7aa0 + (double)(&DAT_004ac310)[param_3];
  _DAT_004a3ae0 = _DAT_004a3ef0 * _DAT_004a8730 + dVar5 * dVar1 + (&DAT_004a3a38)[param_3];
  if (DAT_004ac904 == 1) {
    _DAT_004a3ae0 = _DAT_004a3ae0 - (_DAT_004a8730 + _DAT_004a8730);
  }
  if (DAT_004ac914 == 1) {
    _DAT_004a3ae0 = _DAT_004a3ae0 - dVar5 * param_1 * _DAT_00484d60;
  }
  iVar8 = *(int *)(&DAT_004a77e8 + param_2 * 4);
  iVar6 = iVar8 + 5;
  if (0x14 < *(int *)(&DAT_004a8aa8 + param_2 * 4)) {
    iVar6 = iVar8 + 0xf;
  }
  if (0x46 < *(int *)(&DAT_004a8aa8 + param_2 * 4)) {
    iVar6 = 0x28;
  }
  if (param_2 <= DAT_00491140) {
    iVar6 = *(int *)(&DAT_004a85d0 + param_2 * 4) / 5 + 5 + iVar8;
  }
  if (0x28 < iVar6) {
    iVar6 = 0x28;
  }
  if (DAT_004ac904 == 1) {
    iVar6 = (iVar6 * 2) / 3;
    uVar7 = (int)(longlong)_DAT_004abef0 + param_2;
    uVar9 = (int)uVar7 >> 0x1f;
    if (((uVar7 ^ uVar9) - uVar9 & 3 ^ uVar9) == uVar9) {
      iVar6 = iVar6 + -2;
    }
  }
  _DAT_004a8718 = dVar3;
  _DAT_004a8720 = dVar4;
  _DAT_004a8728 = dVar2;
  iVar8 = FUN_00413cb0(param_4 / 5 + iVar6);
  if ((DAT_00491188 < 5) || (DAT_004ac900 == 1)) {
    fVar11 = (float10)DAT_004a3a38;
  }
  else {
    fVar11 = ((float10)DAT_004a3a40 - (float10)DAT_004a3a38 * (float10)_DAT_00484e80) *
             (float10)_DAT_00484f60;
  }
  fVar11 = fVar11 - (float10)(&DAT_004a3a38)[param_3];
  dVar1 = (double)fVar11;
  fVar12 = (float10)fsin((float10)iVar8 * (float10)_DAT_00484d40);
  fVar12 = (float10)_DAT_004a7a80 - (float10)*(int *)(&DAT_004aa730 + param_2 * 4) * fVar12 * fVar11
  ;
  _DAT_004a7ac0 = (double)fVar12;
  _DAT_004a8750 = local_28;
  _DAT_004a3b00 =
       (double)((float10)local_28 * (float10)_DAT_004a3ef0 +
               ((float10)(&DAT_004a3a38)[param_3] -
               (float10)(int)(&DAT_004a3450)[iVar8] * fVar11 * (float10)_DAT_00484e28));
  _DAT_004ac3d8 = (double)(fVar12 + (float10)(double)(&DAT_004ac310)[param_3]);
  iVar8 = FUN_00413cb0(((int)(param_4 * 2 + (param_4 * 2 >> 0x1f & 3U)) >> 2) + iVar6);
  fVar11 = (float10)fsin((float10)iVar8 * (float10)_DAT_00484d40);
  fVar11 = (float10)_DAT_004a7a88 -
           (float10)*(int *)(&DAT_004aa730 + param_2 * 4) * fVar11 * (float10)dVar1 *
           (float10)_DAT_00484d70;
  _DAT_004a3af8 =
       _DAT_004a3ef0 * dVar3 +
       ((&DAT_004a3a38)[param_3] - (double)(int)(&DAT_004a3450)[iVar8] * dVar1 * _DAT_00484f68);
  _DAT_004a7ab8 = (double)fVar11;
  _DAT_004ac3d0 = (double)(fVar11 + (float10)(double)(&DAT_004ac310)[param_3]);
  _DAT_004a8748 = dVar3;
  iVar8 = FUN_00413cb0(((int)(param_4 * 3 + (param_4 * 3 >> 0x1f & 3U)) >> 2) + iVar6);
  fVar11 = (float10)fsin((float10)iVar8 * (float10)_DAT_00484d40);
  _DAT_004a7ab0 =
       (double)((float10)_DAT_004a7a90 -
               (float10)*(int *)(&DAT_004aa730 + param_2 * 4) * fVar11 * (float10)dVar1 *
               (float10)_DAT_00484dc0);
  _DAT_004ac3c8 = _DAT_004a7ab0 + (double)(&DAT_004ac310)[param_3];
  _DAT_004a3af0 =
       _DAT_004a3ef0 * dVar4 +
       ((&DAT_004a3a38)[param_3] - (double)(int)(&DAT_004a3450)[iVar8] * dVar1 * _DAT_00484f70);
  _DAT_004a8740 = dVar4;
  iVar6 = FUN_00413cb0((param_4 << 2) / 5 + iVar6);
  fVar11 = (float10)fsin((float10)iVar6 * (float10)_DAT_00484d40);
  fVar11 = (float10)_DAT_004a7a98 -
           (float10)*(int *)(&DAT_004aa730 + param_2 * 4) * fVar11 * (float10)dVar1 *
           (float10)_DAT_00484f78;
  _DAT_004a3ae8 =
       _DAT_004a3ef0 * dVar2 +
       ((&DAT_004a3a38)[param_3] - (double)(int)(&DAT_004a3450)[iVar6] * dVar1 * _DAT_00484f80);
  _DAT_004a7aa8 = (double)fVar11;
  _DAT_004ac3c0 = (double)(fVar11 + (float10)(double)(&DAT_004ac310)[param_3]);
  _DAT_004a8738 = dVar2;
  if (DAT_00491188 != 1) {
    iVar6 = (*(int *)(&DAT_004a7bc8 + param_2 * 4) + -0x1e) / 3;
    if (0x18 < iVar6) {
      iVar6 = 0x18;
    }
    if (iVar6 < 2) {
      iVar6 = 2;
    }
    param_6 = (*(double *)(&DAT_004a3a30 + param_3 * 8) + (&DAT_004a3a38)[param_3]) * _DAT_00484da8
              - _DAT_004a3a60;
    if ((6 < DAT_00491188) && (DAT_004ac900 == 0)) {
      param_6 = (_DAT_00484f58 / (double)(*(int *)(&DAT_004a4ef8 + param_2 * 4) + 6)) * param_6;
    }
    if (DAT_004ac900 == 1) {
      param_6 = param_6 * _DAT_00484de8;
    }
    if ((DAT_00491188 == 2) && (*(int *)(&DAT_004abb70 + param_2 * 4) == 1)) {
      bVar10 = true;
    }
    else {
      bVar10 = false;
    }
    iVar6 = iVar6 + 0xb;
    if (bVar10) {
      iVar6 = 0x50;
    }
    iVar6 = FUN_00413cb0(iVar6);
    fVar11 = (float10)fsin((float10)iVar6 * (float10)_DAT_00484d40);
    _DAT_004a3b08 = _DAT_004a3a60 - (double)(int)(&DAT_004a3450)[iVar6] * param_6 * _DAT_00484e28;
    _DAT_004a7ac8 =
         (double)-((float10)*(int *)(&DAT_004aa730 + param_2 * 4) * fVar11 * (float10)param_6);
    if (bVar10) {
      _DAT_004a7ac8 = _DAT_004a7ac8 * _DAT_00484f88;
    }
    _DAT_004ac3e0 = _DAT_004a7ac8 + _DAT_004ac338;
    if ((0 < *(int *)(&DAT_004abb70 + param_2 * 4)) && (2 < DAT_00491188)) {
      iVar6 = *(int *)(&DAT_004a7bc8 + param_2 * 4) + -0x70;
      if (iVar6 < 0x14) {
        iVar6 = 0x14;
      }
      if ((param_2 == 1) && (DAT_004a4174 == 3)) {
        iVar6 = 0x14;
      }
      if (((1 < param_2) && (DAT_00491188 == 8)) && (DAT_004aa390 < 0xc)) {
        iVar6 = 0x14;
      }
      param_6 = (&DAT_004a3a38)[param_3] - _DAT_004a3a60;
      if (((DAT_004ac900 == 1) || (DAT_004ac908 == 1)) || (DAT_004ac90c == 1)) {
        param_6 = param_6 * _DAT_00484f90;
        iVar6 = 0xd;
      }
      if ((DAT_00491188 == 3) && (DAT_004ac90c == 0)) {
        param_6 = param_6 * _DAT_00484f90;
      }
      iVar8 = FUN_00413cb0(iVar6);
      dVar1 = (double)(int)(&DAT_004a3450)[iVar8] * param_6;
      dVar2 = (double)*(int *)(&DAT_004aa730 + param_2 * 4) *
              (double)(int)(&DAT_004a54a0)[iVar8] * param_6;
      DAT_004a7ad0 = _DAT_004a7a80 - dVar2 * _DAT_00484e28;
      DAT_004a3b10 = (&DAT_004a3a38)[param_3] - dVar1 * _DAT_00484cc8;
      DAT_004ac3e8 = DAT_004a7ad0 + (double)(&DAT_004ac310)[param_3];
      if (DAT_004ac900 == 1) {
        DAT_004ac3e8 = (double)(&DAT_004ac310)[param_3];
        DAT_004a3b10 = _DAT_004a3a60 - (_DAT_004a3a60 - (&DAT_004a3a38)[param_3]) * _DAT_00484f98;
      }
      DAT_004a7ad8 = _DAT_004a7a88 - dVar2 * _DAT_00484fa0;
      _DAT_004a7ae0 = _DAT_004a7a90 - dVar2 * _DAT_00484e28;
      DAT_004a3b18 = (&DAT_004a3a38)[param_3] - dVar1 * _DAT_00484fa8;
      DAT_004ac3f0 = DAT_004a7ad8 + (double)(&DAT_004ac310)[param_3];
      _DAT_004a7ae8 = _DAT_004a7a98 - dVar2 * _DAT_00484fb0;
      _DAT_004a3b20 = (&DAT_004a3a38)[param_3] - dVar1 * _DAT_00484cc8;
      _DAT_004ac3f8 = _DAT_004a7ae0 + (double)(&DAT_004ac310)[param_3];
      _DAT_004ac400 = _DAT_004a7ae8 + (double)(&DAT_004ac310)[param_3];
      _DAT_004a3b28 = (&DAT_004a3a38)[param_3] - dVar1 * _DAT_00484fb8;
      iVar8 = FUN_00413cb0(iVar6 + -0x3c);
      dVar2 = (double)*(int *)(&DAT_004aa730 + param_2 * 4) *
              (double)(int)(&DAT_004a54a0)[iVar8] * param_6 * _DAT_00484db8;
      dVar1 = (double)(int)(&DAT_004a3450)[iVar8] * param_6 * _DAT_00484db8;
      _DAT_004a7af0 = _DAT_004a7a80 - dVar2 * _DAT_00484e28;
      _DAT_004a7af8 = _DAT_004a7a88 - dVar2 * _DAT_00484fa0;
      _DAT_004ac408 = _DAT_004a7af0 + (double)(&DAT_004ac310)[param_3];
      _DAT_004a7b00 = _DAT_004a7a90 - dVar2 * _DAT_00484e28;
      _DAT_004ac410 = _DAT_004a7af8 + (double)(&DAT_004ac310)[param_3];
      _DAT_004a3b30 = (&DAT_004a3a38)[param_3] - dVar1 * _DAT_00484cc8;
      _DAT_004ac418 = _DAT_004a7b00 + (double)(&DAT_004ac310)[param_3];
      _DAT_004a3b38 = (&DAT_004a3a38)[param_3] - dVar1 * _DAT_00484fa8;
      _DAT_004a3b40 = (&DAT_004a3a38)[param_3] - dVar1 * _DAT_00484cc8;
      _DAT_004a7b08 = _DAT_004a7a98 - dVar2 * _DAT_00484fb0;
      _DAT_004ac420 = _DAT_004a7b08 + (double)(&DAT_004ac310)[param_3];
      _DAT_004a3b48 = (&DAT_004a3a38)[param_3] - dVar1 * _DAT_00484fb8;
      iVar6 = FUN_00413cb0(iVar6 + -0x82);
      dVar1 = (double)*(int *)(&DAT_004aa730 + param_2 * 4) *
              (double)(int)(&DAT_004a54a0)[iVar6] * ((&DAT_004a3a38)[param_3] - _DAT_004a3a60);
      dVar2 = (double)(int)(&DAT_004a3450)[iVar6] * ((&DAT_004a3a38)[param_3] - _DAT_004a3a60);
      _DAT_004a7b10 = _DAT_004a7a80 - dVar1 * _DAT_00484e28;
      _DAT_004a7b18 = _DAT_004a7a88 - dVar1 * _DAT_00484fa0;
      _DAT_004a3b50 = (&DAT_004a3a38)[param_3] - dVar2 * _DAT_00484cc8;
      _DAT_004ac428 = _DAT_004a7b10 + (double)(&DAT_004ac310)[param_3];
      _DAT_004a7b20 = _DAT_004a7a90 - dVar1 * _DAT_00484e28;
      _DAT_004ac430 = _DAT_004a7b18 + (double)(&DAT_004ac310)[param_3];
      _DAT_004a3b58 = (&DAT_004a3a38)[param_3] - dVar2 * _DAT_00484fa8;
      _DAT_004a7b28 = _DAT_004a7a98 - dVar1 * _DAT_00484fb0;
      _DAT_004a3b60 = (&DAT_004a3a38)[param_3] - dVar2 * _DAT_00484cc8;
      _DAT_004ac438 = _DAT_004a7b20 + (double)(&DAT_004ac310)[param_3];
      _DAT_004ac440 = _DAT_004a7b28 + (double)(&DAT_004ac310)[param_3];
      _DAT_004a3b68 = (&DAT_004a3a38)[param_3] - dVar2 * _DAT_00484fb8;
    }
  }
  return;
}

