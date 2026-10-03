
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041b5d0(void)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  float10 fVar8;
  
  fVar8 = (float10)fsin((float10)((DAT_004a4be4 + -8) * 0xf) * (float10)_DAT_00484d40);
  DAT_004ac568 = (int)(longlong)((float10)(DAT_004a7758 - DAT_004a609c) * fVar8) + DAT_004a609c;
  if (DAT_004ac568 < DAT_004a609c) {
    DAT_004ac568 = DAT_004a609c;
  }
  iVar2 = (DAT_004ac568 * DAT_004a79ec) / DAT_004a7758;
  if ((iVar2 < 0) || ((0 < DAT_004a4958 && (DAT_004a4958 < 5)))) {
    iVar2 = 0;
  }
  if ((0x16 < DAT_004a4be4) || (DAT_004a4be4 < 9)) {
    iVar2 = 0;
  }
  iVar3 = (DAT_004aa804 + 1) * 0x5a;
  if (DAT_004a4378 == 1) {
    iVar3 = iVar3 + 0x5a;
  }
  iVar4 = FUN_00413cb0(iVar3);
  iVar3 = (&DAT_004a3450)[iVar4];
  iVar4 = (&DAT_004a54a0)[iVar4];
  iVar5 = FUN_00413cb0(DAT_004a4430);
  iVar3 = ((&DAT_004a3450)[iVar5] * DAT_004a70dc) / 100 + (iVar3 * iVar2) / 100;
  iVar2 = ((&DAT_004a54a0)[iVar5] * DAT_004a70dc) / 100 + (iVar4 * iVar2) / 100;
  iVar4 = iVar3 * iVar3 + iVar2 * iVar2;
  DAT_004aa390 = DAT_004a70dc;
  if (iVar4 != 0) {
    DAT_004aa390 = (int)(longlong)SQRT((float10)iVar4);
  }
  if (0x16 < DAT_004aa390) {
    DAT_004aa390 = 0x16;
  }
  if (DAT_004aa390 < 8) {
    DAT_004aa390 = 8;
  }
  DAT_004a70f0 = DAT_004aa390;
  if (((9 < DAT_004aa390) && (0x10 < DAT_004a4be4)) || (DAT_004a4be4 < 0xb)) {
    DAT_004aa390 = DAT_004aa390 + -2;
  }
  iVar2 = FUN_0041bb10(iVar2,iVar3);
  iVar2 = FUN_00413cb0(((int)(longlong)_DAT_004ab8b8 * DAT_004abc7c) / 0x3c + iVar2);
  uVar6 = iVar2 + DAT_004aa804 * -0x5a + 0x5a;
  uVar7 = (int)uVar6 >> 0x1f;
  if ((((int)((uVar6 ^ uVar7) - uVar7) < 0x5a) || (0 < DAT_004a4958)) ||
     ((DAT_004a5b9c == 1 || (DAT_004a4378 == 1)))) {
    iVar3 = 1;
    DAT_004a71a4 = 1;
    DAT_004a888c = 1;
  }
  else {
    iVar3 = 0;
    DAT_004a888c = 0;
    DAT_004a71a4 = 0;
  }
  if (DAT_004ac9ac == 0) {
    if (DAT_004a5b80 < DAT_004a4168 + 10) {
      _DAT_004aa6f0 = (double)iVar2;
      DAT_004a4f8c = iVar2;
      DAT_004ac840 = iVar2;
      DAT_004ac9e8 = iVar2;
    }
    else {
      if (iVar3 == 1) {
        iVar3 = FUN_00415a20(0x1e);
        DAT_004aa590 = iVar3 + 0x1e;
        _DAT_004aa978 = FUN_00415a20(10);
        _DAT_004aa978 = _DAT_004aa978 + 0xf;
      }
      else {
        iVar3 = FUN_00415a20(0x14);
        DAT_004aa590 = iVar3 + 0x14;
        _DAT_004aa978 = FUN_00415a20(0x14);
        _DAT_004aa978 = _DAT_004aa978 + 0x1e;
      }
      if (DAT_004abae4 < DAT_004a5b80) {
        DAT_004ac9e8 = FUN_0041ba60(iVar2,DAT_004aa590,_DAT_004aa978);
      }
      dVar1 = (double)DAT_004ac9e8 - _DAT_004aa6f0;
      if (_DAT_00485090 < dVar1) {
        dVar1 = dVar1 - _DAT_00485098;
      }
      if (dVar1 < _DAT_004850a0) {
        dVar1 = dVar1 - _DAT_004850a8;
      }
      _DAT_004aa6f0 = _DAT_004aa6f0 - dVar1 * _DAT_004aa948 * _DAT_004850b0;
      DAT_004ac840 = FUN_00413cb0((int)(longlong)_DAT_004aa6f0);
      iVar3 = DAT_004a888c;
    }
  }
  if (DAT_004ac9ac == 1) {
    if (DAT_004a5b80 < 10) {
      _DAT_004aa6f0 = (double)iVar2;
      DAT_004a4f8c = iVar2;
      DAT_004ac840 = iVar2;
    }
    else {
      if (iVar3 == 1) {
        iVar3 = FUN_00415a20(0x1e);
        DAT_004aa590 = iVar3 + 0x1e;
        _DAT_004aa978 = FUN_00415a20(10);
        _DAT_004aa978 = _DAT_004aa978 + 0x14;
      }
      else {
        iVar3 = FUN_00415a20(0x14);
        DAT_004aa590 = iVar3 + 0x14;
        _DAT_004aa978 = FUN_00415a20(0x14);
        _DAT_004aa978 = _DAT_004aa978 + 0x28;
      }
      if (DAT_004abae4 < DAT_004a5b80) {
        DAT_004ac9e8 = FUN_0041ba60(iVar2,DAT_004aa590,_DAT_004aa978);
      }
      dVar1 = (double)DAT_004ac9e8 - _DAT_004aa6f0;
      if (_DAT_00485090 < dVar1) {
        dVar1 = dVar1 - _DAT_00485098;
      }
      if (dVar1 < _DAT_004850a0) {
        dVar1 = dVar1 - _DAT_004850a8;
      }
      _DAT_004aa6f0 = _DAT_004aa6f0 - dVar1 * _DAT_004aa948 * _DAT_004850b0;
      DAT_004ac840 = FUN_00413cb0((int)(longlong)_DAT_004aa6f0);
    }
  }
  fVar8 = (float10)fsin((float10)((DAT_004a4be4 - DAT_004a8020) * 0x1e) * (float10)_DAT_00484d40);
  DAT_004aa298 = (int)(longlong)(fVar8 * (float10)DAT_004ac1dc);
  return;
}

