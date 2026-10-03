
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00427540(void)

{
  double dVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  float10 fVar7;
  
  fVar7 = (float10)fsin((float10)((DAT_004f6d60 + -8) * 0xf) * (float10)_DAT_004cc568);
  DAT_00535ed0 = (int)(longlong)((float10)(DAT_004fe76c - DAT_004faf8c) * fVar7) + DAT_004faf8c;
  if (DAT_00535ed0 < DAT_004faf8c) {
    DAT_00535ed0 = DAT_004faf8c;
  }
  DAT_004f8b7c = (DAT_00535ed0 * DAT_004fea5c) / DAT_004fe76c;
  if ((DAT_004f8b7c < 0) || ((0 < DAT_004f69b8 && (DAT_004f69b8 < 5)))) {
    DAT_004f8b7c = 0;
  }
  if ((0x16 < DAT_004f6d60) || (DAT_004f6d60 < 10)) {
    DAT_004f8b7c = 0;
  }
  iVar2 = (DAT_005230dc + 1) * 0x5a;
  if (DAT_004f4510 == 1) {
    iVar2 = iVar2 + 0x5a;
  }
  iVar2 = FUN_0041bc20(iVar2);
  if ((DAT_004da1f8 == 7) || (iVar6 = iVar2, DAT_004da1f8 == 1)) {
    iVar6 = 0xbe;
  }
  if ((DAT_004fb5d4 == 1) || (DAT_004da1f8 == 3)) {
    iVar6 = 0xdc;
  }
  if (DAT_004da1f8 == 2) {
    iVar6 = 0x87;
  }
  if (DAT_004da1f8 == 3) {
    iVar6 = 0xd2;
  }
  if (DAT_004da1f8 == 6) {
    iVar6 = 0x96;
  }
  if (DAT_004da1f8 == 9) {
    iVar6 = 0x96;
  }
  if (DAT_004da1f8 == 10) {
    iVar6 = 0xe1;
  }
  if (DAT_004da1f8 == 0xb) {
    iVar6 = 0x78;
  }
  if (DAT_004da1f8 == 0xc) {
    iVar6 = 0x50;
  }
  if (DAT_004da1f8 == 0x68) {
    iVar6 = 0x10e;
  }
  if (DAT_004da1f8 == 100) {
    iVar6 = 0xdc;
  }
  if (DAT_004da1f8 == 0x65) {
    iVar6 = 0xdc;
  }
  if (DAT_004da1f8 == 0x66) {
    iVar6 = 0xdc;
  }
  if (DAT_004da1f8 == 0x6a) {
    iVar6 = 0x78;
  }
  if (DAT_004da1f8 == 999) {
    DAT_004f8b7c = DAT_004f8b7c / 2;
    iVar6 = DAT_004da268;
  }
  if (((DAT_004fea5c < 5) || (DAT_004f6d60 < 0xb)) || (0x11 < DAT_004f6d60)) {
    DAT_005364f8 = 0;
  }
  else {
    DAT_005364f8 = (-(uint)(DAT_0053645c != 0) & 0xfffffffa) + 3;
  }
  if (0 < DAT_004da1f8) {
    iVar2 = FUN_0041bc20(iVar6);
  }
  iVar6 = (&DAT_004f1740)[iVar2] * DAT_004f8b7c;
  iVar4 = (&DAT_004f85c8)[iVar2] * DAT_004f8b7c;
  iVar2 = FUN_0041bc20(DAT_004f46a8);
  iVar6 = ((&DAT_004f1740)[iVar2] * DAT_004fe074) / 100 + iVar6 / 100;
  iVar2 = ((&DAT_004f85c8)[iVar2] * DAT_004fe074) / 100 + iVar4 / 100;
  iVar4 = iVar6 * iVar6 + iVar2 * iVar2;
  DAT_00522ad0 = DAT_004fe074;
  if (iVar4 != 0) {
    DAT_00522ad0 = (int)(longlong)SQRT((float10)iVar4);
  }
  if (0x16 < DAT_00522ad0) {
    DAT_00522ad0 = 0x16;
  }
  if (DAT_00522ad0 < 9) {
    DAT_00522ad0 = 9;
  }
  DAT_004fe08c = DAT_00522ad0;
  if (((9 < DAT_00522ad0) && (0x10 < DAT_004f6d60)) || (DAT_004f6d60 < 0xb)) {
    DAT_00522ad0 = DAT_00522ad0 + -2;
  }
  if ((DAT_004da19c == 8) || (DAT_004fb5d4 == 1)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 3;
  }
  iVar2 = FUN_00427ee0(iVar2,iVar6);
  iVar2 = FUN_0041bc20(((DAT_005364f8 + DAT_00535204) * iVar4 * (int)(longlong)_DAT_00534d68) / 0x3c
                       + iVar2);
  _DAT_00522fe0 = ((DAT_005364f8 + DAT_00535204) * iVar4 * (int)(longlong)_DAT_00534d68) / 0x3c;
  if (DAT_004da1f8 == 0) {
    uVar3 = iVar2 + DAT_005230dc * -0x5a + 0x5a;
    uVar5 = (int)uVar3 >> 0x1f;
    if (((((int)((uVar3 ^ uVar5) - uVar5) < 0x5a) || (0 < DAT_004f69b8)) || (DAT_004f8db8 == 1)) ||
       (DAT_004f4510 == 1)) {
      DAT_0051158c = 1;
      DAT_004fe15c = 1;
    }
    else {
      DAT_0051158c = 0;
      DAT_004fe15c = 0;
    }
  }
  if (0 < DAT_004da1f8) {
    DAT_0051158c = 0;
    DAT_004fe15c = 0;
  }
  if (((DAT_004da1f8 == 1) || (DAT_004da1f8 == 7)) || ((DAT_004da1f8 == 9 || (DAT_004da1f8 == 10))))
  {
    DAT_0051158c = 1;
    DAT_004fe15c = 1;
  }
  if (((DAT_004da1f8 == 2) && (0xfa < DAT_005362d4)) && (DAT_005362d4 < 0x168)) {
    DAT_0051158c = 1;
    DAT_004fe15c = 1;
  }
  if ((DAT_004da1f8 == 3) && ((0xfa < DAT_005362d4 || (DAT_005362d4 < 0x46)))) {
    DAT_0051158c = 1;
    DAT_004fe15c = 1;
  }
  if ((DAT_004da1f8 == 6) && ((0xe6 < DAT_005362d4 || (DAT_005362d4 < 0x82)))) {
    DAT_0051158c = 1;
    DAT_004fe15c = 1;
  }
  if ((DAT_004da1f8 == 0xb) && ((0xe6 < DAT_005362d4 || (DAT_005362d4 < 0x5a)))) {
    DAT_0051158c = 1;
    DAT_004fe15c = 1;
  }
  if (((DAT_004da1f8 == 0xc) && (0xdc < DAT_005362d4)) && (DAT_005362d4 < 300)) {
    DAT_0051158c = 1;
    DAT_004fe15c = 1;
  }
  if (DAT_004da1f8 == 0x67) {
    DAT_0051158c = 1;
    DAT_004fe15c = 1;
  }
  if ((DAT_004da1f8 == 0x69) && ((0x122 < DAT_005362d4 || (DAT_005362d4 < 0x46)))) {
    DAT_0051158c = 1;
    DAT_004fe15c = 1;
  }
  if ((DAT_004da1f8 == 0x6a) && ((0x82 < DAT_005362d4 || (DAT_005362d4 < 0x46)))) {
    DAT_0051158c = 1;
    DAT_004fe15c = 1;
  }
  if (((DAT_004da1f8 == 0x68) && (0xbe < DAT_005362d4)) && (DAT_005362d4 < 0x15e)) {
    DAT_0051158c = 1;
    DAT_004fe15c = 1;
  }
  if ((DAT_004da1f8 == 100) && ((0x104 < DAT_005362d4 || (DAT_005362d4 < 0xd2)))) {
    DAT_0051158c = 1;
    DAT_004fe15c = 1;
  }
  if (DAT_004da1f8 == 0x65) {
    if ((0x6e < DAT_005362d4) || (DAT_005362d4 < 0x23)) {
      DAT_0051158c = 1;
      DAT_004fe15c = 1;
    }
    if ((DAT_005362d4 < 0x6f) && (0x22 < DAT_005362d4)) {
      DAT_0051158c = 0;
      DAT_004fe15c = 0;
    }
  }
  if ((DAT_004da1f8 == 0x66) && ((0x6e < DAT_005362d4 || (DAT_005362d4 < 0x2d)))) {
    DAT_0051158c = 1;
    DAT_004fe15c = 1;
  }
  if (DAT_004da1f8 == 999) {
    iVar6 = FUN_0041bc20(DAT_005362d4 - DAT_004da23c);
    if (((iVar6 < 0x5b) || (6 < DAT_00522f08)) || (DAT_004da248 == 2)) {
      DAT_0051158c = 1;
      DAT_004fe15c = 1;
    }
    else {
      DAT_0051158c = 0;
      DAT_004fe15c = 0;
    }
  }
  if (DAT_00536470 == 0) {
    if (DAT_004f8cd0 < DAT_004f42b8 + 10) {
      _DAT_00522f10 = (double)iVar2;
      DAT_004f7f94 = iVar2;
      DAT_005359d4 = iVar2;
      DAT_005362d4 = iVar2;
      DAT_005364a8 = iVar2;
    }
    else {
      if (DAT_0051158c == 1) {
        iVar6 = FUN_0041e000(0x14);
        DAT_00522ae8 = iVar6 + 0x14;
        iVar6 = FUN_0041e000(0x14);
        iVar6 = iVar6 + 0x3c;
      }
      else {
        iVar6 = FUN_0041e000(0xf);
        DAT_00522ae8 = iVar6 + 0xf;
        iVar6 = FUN_0041e000(0x1e);
        iVar6 = iVar6 + 0x55;
      }
      _DAT_005233a0 = iVar6 + 10;
      if (DAT_004da1f8 == 0) {
        _DAT_005233a0 = iVar6 + -0xf;
      }
      if ((DAT_004da1f8 == 5) && (DAT_0051158c == 0)) {
        iVar6 = FUN_0041e000(0x14);
        DAT_00522ae8 = iVar6 + 0x14;
        _DAT_005233a0 = FUN_0041e000(0x3c);
        _DAT_005233a0 = _DAT_005233a0 + 200;
        DAT_004fe15c = 0;
      }
      if ((((DAT_004da1f8 == 7) || (DAT_004da1f8 == 1)) ||
          ((DAT_004da1f8 == 9 || (DAT_004da1f8 == 10)))) && (DAT_0051158c == 0)) {
        iVar6 = FUN_0041e000(0x1e);
        DAT_00522ae8 = iVar6 + 0x1e;
        _DAT_005233a0 = FUN_0041e000(0x28);
        _DAT_005233a0 = _DAT_005233a0 + 100;
        DAT_004fe15c = 1;
      }
      if ((DAT_004da1f8 == 0x68) && (DAT_0051158c == 0)) {
        iVar6 = FUN_0041e000(0x19);
        DAT_00522ae8 = iVar6 + 0x19;
        _DAT_005233a0 = FUN_0041e000(0x28);
        _DAT_005233a0 = _DAT_005233a0 + 100;
        DAT_004fe15c = 1;
      }
      if (((DAT_004da1f8 == 0x69) || (DAT_004da1f8 == 0x6a)) && (DAT_0051158c == 0)) {
        iVar6 = FUN_0041e000(0x19);
        DAT_00522ae8 = iVar6 + 0x19;
        _DAT_005233a0 = FUN_0041e000(0x28);
        _DAT_005233a0 = _DAT_005233a0 + 100;
        DAT_004fe15c = 1;
      }
      if (((DAT_004da1f8 == 999) && (DAT_0051158c == 0)) && (DAT_00536524 == 1)) {
        iVar6 = FUN_0041e000(0x19);
        DAT_00522ae8 = iVar6 + 0x19;
        _DAT_005233a0 = FUN_0041e000(0x28);
        _DAT_005233a0 = _DAT_005233a0 + 100;
        DAT_004fe15c = 1;
      }
      if (DAT_004da1f8 == 0x67) {
        iVar6 = FUN_0041e000(0x1e);
        DAT_00522ae8 = iVar6 + 0x1e;
        _DAT_005233a0 = FUN_0041e000(0x28);
        _DAT_005233a0 = _DAT_005233a0 + 100;
        DAT_004fe15c = 1;
      }
      if ((((DAT_004da1f8 == 0xb) || (DAT_004da1f8 == 0x68)) ||
          ((DAT_004da1f8 == 0x69 || (DAT_004da1f8 == 0x6a)))) && (DAT_004fe15c == 0)) {
        iVar6 = FUN_0041e000(0x19);
        DAT_00522ae8 = iVar6 + 0x19;
        _DAT_005233a0 = FUN_0041e000(0x28);
        _DAT_005233a0 = _DAT_005233a0 + 100;
      }
      if (DAT_00534fdc < DAT_004f8cd0) {
        DAT_005364a8 = FUN_00427e30(iVar2,DAT_00522ae8,_DAT_005233a0);
      }
      dVar1 = (double)DAT_005364a8 - _DAT_00522f10;
      if (_DAT_004cc4d0 < dVar1) {
        dVar1 = dVar1 - _DAT_004cc8f0;
      }
      if (dVar1 < _DAT_004cc8f8) {
        dVar1 = dVar1 - _DAT_004cc900;
      }
      _DAT_00522f10 = _DAT_00522f10 - dVar1 * _DAT_00523378 * _DAT_004cc908;
      DAT_005362d4 = FUN_0041bc20((int)(longlong)_DAT_00522f10);
    }
  }
  fVar7 = (float10)fsin((float10)((DAT_004f6d60 - DAT_004ffdd0) * 0x1e) * (float10)_DAT_004cc568);
  DAT_005229d8 = (int)(longlong)(fVar7 * (float10)DAT_005359d0);
  return;
}

