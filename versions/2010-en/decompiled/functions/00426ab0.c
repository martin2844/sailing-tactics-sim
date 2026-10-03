
void __cdecl FUN_00426ab0(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0041e000(4);
  DAT_004fe074 = iVar1 * 3 + 10;
  if (DAT_004da154 == 1) {
    DAT_004fe074 = iVar1 / 2 + 9;
  }
  if (DAT_004da154 == 2) {
    DAT_004fe074 = iVar1 + 0xc;
  }
  if (DAT_004da154 == 3) {
    DAT_004fe074 = iVar1 / 2 + 0xf;
  }
  iVar1 = FUN_0041e000(0x4f);
  DAT_004fad38 = iVar1 / 10 + 1;
  if (DAT_004da19c == 9) {
    uVar2 = (int)DAT_004fad38 >> 0x1f;
    if (((DAT_004fad38 ^ uVar2) - uVar2 & 1 ^ uVar2) == uVar2) {
      DAT_004fad38 = iVar1 / 10 + 2;
    }
    if (DAT_004fad38 == 7) {
      DAT_004fad38 = 1;
    }
  }
  if (DAT_004da19c == 10) {
    DAT_004fad38 = ((4 < (int)DAT_004fad38) - 1 & 0xfffffffc) + 5;
  }
  if (8 < (int)DAT_004fad38) {
    DAT_004fad38 = 1;
  }
  if (DAT_004f8b78 == 1) {
    iVar1 = FUN_0041e000(0x1d);
    DAT_004fad38 = iVar1 / 10 + 4;
  }
  if (DAT_004da19c == 8) {
    if (DAT_004f8b78 == 0) {
      iVar1 = FUN_0041e000(10);
      DAT_004fad38 = ((iVar1 < 5) - 1 & 0xfffffffc) + 7;
    }
    if (DAT_004da19c == 8) goto LAB_00426c17;
  }
  if (((DAT_004f8b78 == 0) && (DAT_004da140 == 2)) && (DAT_004da1f8 == 0)) {
    DAT_004fad38 = 1;
  }
LAB_00426c17:
  iVar1 = FUN_0041e000(0xe);
  DAT_004f46a8 = FUN_0041bc20(iVar1 + -0x34 + DAT_004fad38 * 0x2d);
  if (DAT_004da1f8 == 5) {
    iVar1 = FUN_0041e000(0x1d);
    DAT_004fad38 = iVar1 / 10 + 4;
    iVar1 = FUN_0041e000(100);
    if (iVar1 < 0x19) {
      iVar1 = FUN_0041e000(100);
      DAT_0053646c = 1;
      DAT_004fad38 = (0x31 < iVar1) + 1;
      DAT_004da214 = 0xffffffff;
    }
    DAT_004f46a8 = DAT_004fad38 * 0x2d + -0x2d;
    if (DAT_004fad38 == 1) {
      DAT_004f46a8 = 0x1e;
    }
    if (DAT_004fad38 == 2) {
      DAT_004f46a8 = DAT_004f46a8 + -0x14;
    }
    if (DAT_004fad38 == 4) {
      DAT_004f46a8 = DAT_004f46a8 + 0x14;
    }
    if (5 < (int)DAT_004fad38) {
      DAT_004f46a8 = DAT_004f46a8 + -10;
    }
  }
  if (DAT_004da1f8 == 0) {
    iVar1 = FUN_0041e000(10);
    DAT_005359d8 = (uint)(iVar1 < 5);
  }
  else {
    DAT_005359d8 = 1;
  }
  if (((DAT_004da1f8 == 6) || (DAT_004da1f8 == 0x68)) || (DAT_004da1f8 == 0x69)) {
    DAT_005359d8 = 0;
  }
  iVar1 = FUN_0041e000(10);
  if (iVar1 < 6) {
    DAT_005116b0 = DAT_004fad38 + 2;
  }
  DAT_00523244 = (uint)(iVar1 >= 6);
  if (8 < DAT_005116b0) {
    DAT_005116b0 = DAT_005116b0 + -8;
  }
  if (5 < iVar1) {
    DAT_005116b0 = DAT_004fad38 - 2;
  }
  if (DAT_005116b0 < 1) {
    DAT_005116b0 = DAT_005116b0 + 8;
  }
  if ((DAT_004da1f8 == 999) && (DAT_004da248 == 2)) {
    if (DAT_0053646c == 1) {
      DAT_004da214 = 0xffffffff;
      iVar1 = DAT_004da23c + 0x5a;
    }
    else {
      DAT_004da214 = 1;
      iVar1 = DAT_004da23c + -0x5a;
    }
    DAT_004da268 = FUN_0041bc20(iVar1);
    DAT_004fad38 = DAT_004da268 / 0x2d + 1;
    if (8 < (int)DAT_004fad38) {
      DAT_004fad38 = DAT_004da268 / 0x2d - 7;
    }
    DAT_004f46a8 = DAT_004da268;
    DAT_004f7f94 = DAT_004da268;
    if ((int)DAT_004fad38 < 1) {
      DAT_004fad38 = DAT_004fad38 + 8;
    }
  }
  iVar1 = FUN_0041e000(5);
  DAT_00535204 = iVar1 - 2;
  if (((DAT_005116b0 == 1) || (DAT_005116b0 == 2)) || (DAT_005116b0 == 8)) {
    iVar1 = FUN_0041e000(3);
    DAT_00535204 = iVar1 + 3;
  }
  if (((DAT_005116b0 == 4) || (DAT_005116b0 == 5)) || (DAT_005116b0 == 6)) {
    iVar1 = FUN_0041e000(3);
    DAT_00535204 = -iVar1 - 3;
  }
  if (DAT_0053645c == 1) {
    DAT_00535204 = -DAT_00535204;
  }
  DAT_004f8b74 = (uint)(3 < (int)((DAT_00535204 ^ (int)DAT_00535204 >> 0x1f) -
                                 ((int)DAT_00535204 >> 0x1f)));
  if (DAT_004da19c == 8) {
    DAT_00535204 = (int)DAT_00535204 / 2;
  }
  iVar1 = 1;
  DAT_00511cf8 = 3;
  DAT_004fe76c = 0x55;
  DAT_004f8d78 = 1;
  if ((7 < (int)DAT_004fad38) || ((int)DAT_004fad38 < 3)) {
    DAT_00511cf8 = 1;
    DAT_004fe76c = 0x4b;
  }
  if ((DAT_004fad38 == 7) || (DAT_004fad38 == 3)) {
    DAT_00511cf8 = 2;
    DAT_004fe76c = 0x50;
  }
  if ((DAT_004fad38 == 2) || (DAT_004fad38 == 3)) {
    iVar1 = 3;
    DAT_004f8d78 = 3;
  }
  if ((DAT_004fad38 == 4) || (DAT_004fad38 == 5)) {
    iVar1 = 2;
    DAT_004f8d78 = 2;
  }
  if (iVar1 == 4) {
    DAT_00511cf8 = 3;
  }
  if (DAT_004da154 == 1) {
    DAT_004f8d78 = 3;
  }
  if (DAT_004da1f8 < 6) {
    iVar1 = FUN_0041e000(10);
    DAT_004faf8c = iVar1 + 0x30;
  }
  else {
    iVar1 = FUN_0041e000(10);
    DAT_004faf8c = iVar1 + 0x3a;
  }
  if (DAT_004da1f8 == 0x6a) {
    iVar1 = FUN_0041e000(4);
    DAT_004faf8c = iVar1 + 0x44;
  }
  DAT_004fea5c = ((DAT_004fe76c - DAT_004faf8c) * 3) / (DAT_004f8d78 * DAT_00511cf8 * 2);
  if (2 < DAT_004f8d78) {
    DAT_004fea5c = 0;
  }
  if ((DAT_004da154 == 1) && (2 < DAT_004fea5c)) {
    DAT_004fea5c = 2;
  }
  if ((DAT_004da154 == 2) && (7 < DAT_004fea5c)) {
    DAT_004fea5c = 7;
  }
  if ((0 < DAT_004f69b8) && (DAT_004f69b8 < 5)) {
    DAT_004fea5c = 0;
  }
  if ((DAT_004da1f8 == 0x67) || (DAT_004da1f8 == 0x69)) {
    DAT_004fea5c = 0;
  }
  if ((DAT_004da1f8 == 999) && (DAT_004da248 == 2)) {
    DAT_004fea5c = DAT_004fea5c / 2;
  }
  if (DAT_00536454 == 1) {
    DAT_004faa58 = 0x15;
    DAT_004f6d60 = 0x15;
    return;
  }
  iVar1 = FUN_0041e000(4);
  DAT_004faa58 = iVar1 + 10;
  DAT_004f6d60 = iVar1 + 10;
  return;
}

