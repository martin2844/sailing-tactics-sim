
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042dea0(int param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  bool bVar12;
  uint local_10;
  int *local_8;
  
  DAT_004da214 = (-(uint)(DAT_0053646c != 1) & 2) - 1;
  iVar9 = 1000;
  DAT_00535208 = DAT_004f7f94;
  DAT_00525a9c = 1000;
  if ((DAT_004da1f8 == 0) && (DAT_0053527c == 1)) {
    if (DAT_005364c8 == 0) {
      iVar9 = 0x758;
      DAT_00525a9c = 0x758;
    }
    if (DAT_005364c8 == 1) {
      iVar9 = 800;
      DAT_00525a9c = 800;
    }
  }
  if (DAT_004da1f8 == 999) {
    DAT_00525a9c = DAT_004da238;
    iVar9 = DAT_004da238;
  }
  uVar5 = (8 < DAT_004da198) - 1 & 6;
  iVar6 = uVar5 + 0x2c;
  if (DAT_004da194 == 2) {
    iVar6 = uVar5 + 0x29;
  }
  if (DAT_005363cc == 1) {
    iVar6 = iVar6 + 2;
  }
  if ((((DAT_005363b8 == 1) || (DAT_005363c4 == 1)) || (DAT_005363bc == 1)) || (DAT_0053652c == 1))
  {
    iVar6 = iVar6 + 5;
  }
  if (DAT_004f8b78 == 1) {
    iVar6 = iVar6 + 3;
  }
  iVar7 = iVar6;
  if (DAT_004da19c == 8) {
    if (DAT_004f8b78 == 0) {
      iVar9 = 0xce4;
      DAT_00535208 = 0x5a;
      DAT_00525a9c = 0xce4;
      DAT_004da168 = 1;
    }
    if (DAT_004f8b78 == 1) {
      iVar9 = 0x898;
      DAT_00525a9c = 0x898;
    }
    iVar7 = iVar6 + 0x14;
    if (DAT_004f8b78 == 0) {
      iVar7 = iVar6 + 0x1e;
    }
  }
  if (DAT_004da1f8 == 5) {
    iVar7 = iVar7 + 7;
  }
  if (7 < DAT_005359d0) {
    iVar7 = iVar7 + 3;
  }
  if (0xe < DAT_005359d0) {
    iVar7 = iVar7 + 2;
  }
  DAT_00523598 = (DAT_004da194 + 10) * 10;
  if (DAT_004da194 == 2) {
    DAT_00523598 = 0x7d;
  }
  iVar10 = 0;
  iVar6 = 0;
  DAT_00536410 = 0;
  DAT_00536414 = 0;
  if (DAT_004da19c == 1) {
    iVar6 = 0x15e;
    DAT_00536414 = 0x15e;
  }
  if (DAT_004da19c == 2) {
    iVar10 = -0xfa;
    DAT_00536410 = -0xfa;
  }
  if (DAT_004da19c == 3) {
    iVar6 = -0x15e;
    DAT_00536414 = -0x15e;
  }
  if (DAT_004da19c == 4) {
    iVar10 = 0xfa;
    DAT_00536410 = 0xfa;
  }
  if (DAT_004f4510 == 1) {
    iVar10 = 500;
    DAT_00536410 = 500;
  }
  if (DAT_004da19c == 9) {
    iVar10 = 0;
    iVar6 = -400;
    DAT_00536410 = 0;
    DAT_00536414 = -400;
  }
  if (DAT_004da19c == 10) {
    iVar10 = 0;
    iVar6 = 400;
    DAT_00536410 = 0;
    DAT_00536414 = 400;
  }
  if (DAT_004da1f8 == 5) {
    iVar10 = 4000;
    iVar6 = -1000;
    DAT_00536410 = 4000;
    DAT_00536414 = -1000;
    if (DAT_004fad38 == 4) {
      iVar10 = 1000;
      iVar6 = 0;
      DAT_00536410 = 1000;
      DAT_00536414 = 0;
    }
  }
  if ((DAT_004da1f8 == 5) && (DAT_004fad38 < 4)) {
    iVar10 = 4000;
    iVar6 = -1000;
    DAT_00536410 = 4000;
    DAT_00536414 = -1000;
  }
  if (DAT_004da1f8 == 1) {
    iVar9 = 0x5dc;
    DAT_00525a9c = 0x5dc;
  }
  if (DAT_004da1f8 == 2) {
    iVar9 = 2000;
    iVar10 = 700;
    iVar6 = 0x44c;
    DAT_00525a9c = 2000;
    DAT_00536410 = 700;
    DAT_00536414 = 0x44c;
  }
  if (DAT_004da1f8 == 3) {
    iVar9 = 2000;
    DAT_00525a9c = 2000;
  }
  if (DAT_004da1f8 == 4) {
    iVar9 = 0x960;
    DAT_00525a9c = 0x960;
  }
  if (DAT_004da1f8 == 5) {
    iVar9 = 3000;
    DAT_00525a9c = 3000;
  }
  if (DAT_004da1f8 == 6) {
    iVar9 = 2000;
    DAT_00525a9c = 2000;
  }
  if (DAT_004da1f8 == 7) {
    iVar9 = 1000;
    DAT_00525a9c = 1000;
  }
  if (DAT_004da1f8 == 9) {
    iVar9 = 0x5dc;
    DAT_00525a9c = 0x5dc;
  }
  if (DAT_004da1f8 == 10) {
    iVar9 = 0x5dc;
    DAT_00525a9c = 0x5dc;
  }
  if (DAT_004da1f8 == 0xb) {
    iVar9 = 2000;
    DAT_00525a9c = 2000;
  }
  if (DAT_004da1f8 == 0xc) {
    iVar9 = 0x9c4;
    DAT_00525a9c = 0x9c4;
  }
  if (DAT_004da1f8 == 100) {
    iVar9 = 0x708;
    DAT_00525a9c = 0x708;
  }
  if (DAT_004da1f8 == 0x65) {
    iVar9 = 2000;
    DAT_00525a9c = 2000;
  }
  if (DAT_004da1f8 == 0x66) {
    iVar9 = 2000;
    DAT_00525a9c = 2000;
  }
  if (DAT_004da1f8 == 0x67) {
    iVar9 = 0x5dc;
    DAT_00525a9c = 0x5dc;
  }
  if (DAT_004da1f8 == 0x69) {
    iVar9 = 0x73a;
    DAT_00525a9c = 0x73a;
  }
  if (DAT_004da1f8 == 0x68) {
    iVar9 = 0x76c;
    iVar10 = 0x96;
    DAT_00525a9c = 0x76c;
    DAT_00536410 = 0x96;
  }
  if (DAT_004da1f8 == 0x6a) {
    iVar9 = 0x5dc;
    DAT_00525a9c = 0x5dc;
  }
  if (DAT_004da1f8 == 999) {
    DAT_00525a9c = DAT_004da238;
    iVar9 = DAT_004da238;
  }
  if ((0 < DAT_004da1f8) && (DAT_0053527c == 1)) {
    iVar9 = (iVar9 * 9) / 5;
    DAT_00525a9c = iVar9;
  }
  if (DAT_0053640c == 1) {
    iVar9 = (iVar9 / 10) * 7;
    DAT_00525a9c = iVar9;
  }
  if (DAT_005363cc == 1) {
    iVar9 = (iVar9 / 10) * 7;
    DAT_00525a9c = iVar9;
  }
  if (DAT_005364c8 == 1) {
    iVar9 = iVar9 / 2;
    DAT_00525a9c = iVar9;
  }
  if (DAT_0053527c == 1) {
    iVar9 = FUN_0041bc20(DAT_00535208 + 0xb4);
    if (DAT_005364c8 == 0) {
      iVar6 = DAT_00525a9c / 2;
    }
    else {
      iVar6 = 800;
    }
    FUN_0042f220(DAT_00536410,DAT_00536414,iVar6,iVar9);
    DAT_00536410 = DAT_004fe080;
    DAT_00536414 = DAT_00523180;
    iVar6 = DAT_00523180;
    iVar9 = DAT_00525a9c;
    iVar10 = DAT_004fe080;
  }
  iVar4 = iVar9;
  if (DAT_004f8b78 != 1) {
    iVar4 = (int)(iVar9 * 3 + (iVar9 * 3 >> 0x1f & 3U)) >> 2;
  }
  if (DAT_004da19c == 10) {
    iVar4 = iVar9 / 3;
  }
  if ((DAT_004da168 == 1) && (iVar4 = iVar9, DAT_004da194 < 0xf)) {
    iVar4 = 1;
  }
  if ((DAT_0053646c == 1) && (DAT_004f8b78 == 0)) {
    DAT_004da214 = -1;
  }
  else {
    DAT_004da214 = 1;
  }
  if ((param_1 < 3) || (DAT_005363f8 == 0)) {
    FUN_0042f220(iVar10,iVar6,DAT_00523598,DAT_00535208 + DAT_004da214 * 0x5a);
    DAT_004fe094 = DAT_004fe080;
    DAT_004fe2a0 = DAT_00523180;
    if (DAT_004da194 == 2) {
      FUN_0042f220(DAT_00536410,DAT_00536414,DAT_00523598,DAT_00535208 + 0x5a);
    }
    DAT_004fe094 = DAT_004fe080;
    DAT_004fe2a0 = DAT_00523180;
    _DAT_004fb518 = FUN_0041bc20(DAT_00535208 + DAT_004da214 * 0x5a);
    _DAT_004fb530 = DAT_00523598;
    iVar6 = DAT_00536414;
    iVar9 = DAT_00525a9c;
    iVar10 = DAT_00536410;
  }
  if ((DAT_004da1f8 != 5) && (param_1 < 2)) {
    FUN_0042f220((DAT_004fe094 + iVar10) / 2,(DAT_004fe2a0 + iVar6) / 2,iVar9,DAT_00535208);
    DAT_005229d4 = DAT_004fe080;
    DAT_00522ac8 = DAT_00523180;
    iVar6 = DAT_00536414;
    iVar10 = DAT_00536410;
  }
  dVar1 = (double)(DAT_005229d4 - iVar10);
  dVar2 = (double)(iVar6 - DAT_00522ac8);
  DAT_004fb51c = FUN_00427ee0(DAT_005229d4 - iVar10,iVar6 - DAT_00522ac8);
  _DAT_004fb534 = (undefined4)(longlong)SQRT(dVar2 * dVar2 + dVar1 * dVar1);
  FUN_0042f330(DAT_005229d4,DAT_00522ac8,0);
  if ((DAT_004f8b78 == 1) || (DAT_004da19c == 9)) {
    iVar9 = DAT_00535208 + DAT_004da214 * -0x5a;
  }
  else {
    iVar9 = FUN_0041e000(0x3c);
    iVar9 = (iVar9 + -0x78) * DAT_004da214 + DAT_00535208;
  }
  if (DAT_004da19c == 10) {
    iVar9 = DAT_00535208 + DAT_004da214 * -0x6e;
  }
  if ((DAT_004da168 == 1) && (0xe < DAT_004da194)) {
    iVar9 = DAT_00535208 + DAT_004da214 * -5;
    iVar4 = DAT_00525a9c;
  }
  FUN_0042f220(DAT_00536410,DAT_00536414,iVar4,iVar9);
  DAT_00522acc = DAT_004fe080;
  DAT_00522ae0 = DAT_00523180;
  DAT_004fb520 = FUN_0041bc20(iVar9);
  _DAT_004fb538 = iVar4;
  FUN_0042f330(DAT_00522acc,DAT_00522ae0,0);
  if (DAT_004f8b78 == 0) {
    FUN_0042f220(DAT_00536410,DAT_00536414,DAT_00525a9c,DAT_00535208 + DAT_004da214 * -0xb4);
    iVar9 = DAT_004da214 * 0xb4;
  }
  else {
    FUN_0042f220(DAT_00536410,DAT_00536414,DAT_00525a9c,DAT_00535208 + DAT_004da214 * -200);
    iVar9 = DAT_004da214 * 200;
  }
  DAT_005229c8 = DAT_004fe080;
  DAT_00522ac4 = DAT_00523180;
  DAT_004fb524 = FUN_0041bc20(DAT_00535208 - iVar9);
  if (DAT_0053527c == 1) {
    if (DAT_00536408 == 1) {
      DAT_005229c8 = DAT_00536410;
      DAT_00522ac4 = DAT_00536414;
    }
    else {
      FUN_0042f220((DAT_00536410 + DAT_004fe094) / 2,(DAT_004fe2a0 + DAT_00536414) / 2,0x14,
                   DAT_004f7f94 + 0xb4);
      DAT_005229c8 = DAT_004fe080;
      DAT_00522ac4 = DAT_00523180;
    }
    DAT_004fb524 = FUN_0041bc20(DAT_00535208 + DAT_004da214 * -0xb4);
  }
  if (DAT_004da1e8 == 1) {
    FUN_0042f220(DAT_005229c8,DAT_00522ac4,0x5a,DAT_00535208 + DAT_004da214 * -0x55);
    DAT_004f4a68 = DAT_004fe080;
    DAT_004f6d34 = DAT_00523180;
    FUN_0042f220(DAT_005229c8,DAT_00522ac4,0x5a,DAT_00535208 + DAT_004da214 * 0x55);
    DAT_00523248 = DAT_004fe080;
    DAT_0052359c = DAT_00523180;
  }
  DAT_004fb53c = DAT_00525a9c;
  if (DAT_004da1f8 == 5) {
    if (DAT_004fad38 < 4) {
      iVar9 = 0x27b0;
      iVar6 = -0x24cc;
      DAT_005229c8 = 0x113;
      DAT_00522ac4 = 0x2274;
      DAT_005229d4 = 0x27b0;
      DAT_00522ac8 = -0x24cc;
      DAT_004da214 = -1;
    }
    else {
      iVar9 = 0x113;
      iVar6 = 0x2274;
      DAT_005229d4 = 0x113;
      DAT_00522ac8 = 0x2274;
      DAT_005229c8 = 0x27b0;
      DAT_00522ac4 = -0x24cc;
      DAT_004da214 = 1;
    }
    DAT_0053646c = (uint)(DAT_004fad38 < 4);
    DAT_00522ae0 = -0xce4;
    DAT_00522acc = 0x386c;
    dVar1 = (double)(iVar9 - DAT_00536410);
    dVar2 = (double)(DAT_00536414 - iVar6);
    DAT_004fb51c = FUN_00427ee0(iVar9 - DAT_00536410,DAT_00536414 - iVar6);
    _DAT_004fb534 = (undefined4)(longlong)SQRT(dVar2 * dVar2 + dVar1 * dVar1);
    dVar1 = (double)(DAT_00522acc - DAT_00536410);
    dVar2 = (double)(DAT_00536414 - DAT_00522ae0);
    DAT_004fb520 = FUN_00427ee0(DAT_00522acc - DAT_00536410,DAT_00536414 - DAT_00522ae0);
    _DAT_004fb538 = (int)(longlong)SQRT(dVar2 * dVar2 + dVar1 * dVar1);
    dVar1 = (double)(DAT_005229c8 - DAT_00536410);
    dVar2 = (double)(DAT_00536414 - DAT_00522ac4);
    DAT_004fb524 = FUN_00427ee0(DAT_005229c8 - DAT_00536410,DAT_00536414 - DAT_00522ac4);
    DAT_004fb53c = (int)(longlong)SQRT(dVar2 * dVar2 + dVar1 * dVar1);
  }
  FUN_0042f330(DAT_005229c8,DAT_00522ac4,0);
  FUN_0042f220(DAT_00536410,DAT_00536414,200,DAT_00535208 + 0xaa);
  DAT_004f6d38 = DAT_004fe080;
  DAT_004f7f88 = DAT_00523180;
  local_10 = 1;
  if (0 < DAT_004da194) {
    uVar5 = (uint)(iVar7 * 2) / 3;
    local_8 = &DAT_00511d44;
    piVar8 = &DAT_005117b4;
    iVar9 = 0;
    do {
      FUN_0042f220(DAT_005229d4,DAT_00522ac8,iVar7,DAT_00535208 + DAT_004da214 * 0x5a);
      iVar10 = DAT_00535208;
      iVar6 = DAT_00523180;
      *(int *)((int)&DAT_005117ac + iVar9) = DAT_004fe080;
      *(int *)((int)&DAT_00511d2c + iVar9) = iVar6;
      FUN_0042f220(DAT_005229d4,DAT_00522ac8,uVar5,iVar10);
      iVar10 = DAT_00523180;
      *(int *)((int)&DAT_005117b0 + iVar9) = DAT_004fe080;
      iVar6 = DAT_005229d4;
      iVar4 = DAT_00535208 + DAT_004da214 * -0x3c;
      *(int *)((int)&DAT_00511d30 + iVar9) = iVar10;
      FUN_0042f220(iVar6,DAT_00522ac8,iVar7,iVar4);
      iVar6 = DAT_00523180;
      *piVar8 = DAT_004fe080;
      bVar12 = DAT_004da168 == 1;
      *(int *)((int)&DAT_00511d34 + iVar9) = iVar6;
      if ((bVar12) && (DAT_004da194 < 0xf)) {
        uVar11 = (uint)(iVar7 * 3) / 2;
        FUN_0042f220(DAT_005229d4,DAT_00522ac8,uVar11,DAT_00535208 + DAT_004da214 * 0x5a);
        iVar10 = DAT_00523180;
        iVar6 = DAT_004da214;
        *(int *)((int)&DAT_005117ac + iVar9) = DAT_004fe080;
        *(int *)((int)&DAT_00511d2c + iVar9) = iVar10;
        FUN_0042f220(DAT_005229d4,DAT_00522ac8,iVar7,DAT_00535208 + iVar6 * -0xf);
        iVar10 = DAT_004fe080;
        *(int *)((int)&DAT_00511d30 + iVar9) = DAT_00523180;
        iVar6 = DAT_004da214;
        *(int *)((int)&DAT_005117b0 + iVar9) = iVar10;
        FUN_0042f220(DAT_005229d4,DAT_00522ac8,uVar11,DAT_00535208 + iVar6 * -0x5a);
        iVar6 = DAT_00523180;
        *piVar8 = DAT_004fe080;
        *(int *)((int)&DAT_00511d34 + iVar9) = iVar6;
      }
      if (DAT_004da168 == 1) {
        if ((((0xe < DAT_004da194) && (DAT_005363b8 == 0)) && (DAT_005363c4 == 0)) &&
           (DAT_0053652c == 0)) {
          FUN_0042f220(DAT_00522acc,DAT_00522ae0,uVar5,DAT_00535208 + DAT_004da214 * -10);
        }
        if (((DAT_004da168 == 1) && (0xe < DAT_004da194)) &&
           ((DAT_005363b8 == 1 || ((DAT_005363c4 == 1 || (DAT_0053652c == 1)))))) {
          FUN_0042f220(DAT_00522acc,DAT_00522ae0,iVar7 * 3 >> 2,DAT_00535208 + DAT_004da214 * -10);
        }
      }
      if (DAT_004da168 == 0) {
        FUN_0042f220(DAT_00522acc,DAT_00522ae0,iVar7,DAT_00535208 + DAT_004da214 * -0x37);
      }
      iVar10 = DAT_00523180;
      *(int *)((int)&DAT_005117b8 + iVar9) = DAT_004fe080;
      iVar6 = DAT_004da214;
      bVar12 = DAT_004da1f8 == 5;
      *(int *)((int)&DAT_00511d38 + iVar9) = iVar10;
      if ((bVar12) && (iVar6 == 1)) {
        *(undefined4 *)((int)&DAT_005117b8 + iVar9) = 0x3908;
        *(undefined4 *)((int)&DAT_00511d38 + iVar9) = 0x10cc;
      }
      FUN_0042f220(DAT_00522acc,DAT_00522ae0,iVar7,DAT_00535208 + iVar6 * -0x87);
      iVar4 = DAT_00523180;
      iVar10 = DAT_004da1f8;
      *(int *)((int)&DAT_005117bc + iVar9) = DAT_004fe080;
      iVar6 = DAT_004da214;
      *(int *)((int)&DAT_00511d3c + iVar9) = iVar4;
      if ((iVar10 == 5) && (iVar6 == -1)) {
        *(undefined4 *)((int)&DAT_005117bc + iVar9) = 0x3afc;
        *(undefined4 *)((int)&DAT_00511d3c + iVar9) = 0xa8c;
      }
      if (DAT_004da19c == 8) {
        iVar6 = iVar6 * 0x87;
      }
      else {
        iVar6 = iVar6 * 0x73;
      }
      FUN_0042f220(DAT_005229c8,DAT_00522ac4,iVar7,DAT_00535208 - iVar6);
      iVar10 = DAT_00523180;
      *(int *)((int)&DAT_005117c0 + iVar9) = DAT_004fe080;
      iVar6 = DAT_004da214;
      *(int *)((int)&DAT_00511d40 + iVar9) = iVar10;
      FUN_0042f220(DAT_005229c8,DAT_00522ac4,iVar7,DAT_00535208 + iVar6 * 0x87);
      iVar6 = DAT_004fe080;
      *local_8 = DAT_00523180;
      bVar12 = DAT_004da19c == 8;
      *(int *)((int)&DAT_005117c4 + iVar9) = iVar6;
      if (bVar12) {
        FUN_0042f220(DAT_005229c8,DAT_00522ac4,iVar7,DAT_00535208 + DAT_004da214 * -0x87);
        iVar6 = DAT_00523180;
        *(int *)((int)&DAT_005117c0 + iVar9) = DAT_004fe080;
        *(int *)((int)&DAT_00511d40 + iVar9) = iVar6;
      }
      if ((DAT_004da168 == 1) && (DAT_004da194 < 0xf)) {
        DAT_00522acc = DAT_005229c8;
        DAT_00522ae0 = DAT_00522ac4;
        *(undefined4 *)((int)&DAT_005117b8 + iVar9) = *(undefined4 *)((int)&DAT_005117c0 + iVar9);
        *(undefined4 *)((int)&DAT_00511d38 + iVar9) = *(undefined4 *)((int)&DAT_00511d40 + iVar9);
        DAT_004fb520 = DAT_004fb524;
        *(undefined4 *)((int)&DAT_005117bc + iVar9) = *(undefined4 *)((int)&DAT_005117c0 + iVar9);
        _DAT_004fb538 = DAT_004fb53c;
        *(undefined4 *)((int)&DAT_00511d3c + iVar9) = *(undefined4 *)((int)&DAT_00511d40 + iVar9);
      }
      iVar6 = DAT_00536414;
      *(int *)((int)&DAT_005117c8 + iVar9) = (DAT_00536410 + DAT_004fe094) / 2;
      iVar6 = DAT_004fe2a0 + iVar6;
      *(undefined4 *)((int)&DAT_005117cc + iVar9) = *(undefined4 *)((int)&DAT_005117ac + iVar9);
      *(int *)((int)&DAT_00511d48 + iVar9) = iVar6 / 2;
      iVar6 = DAT_004da1e8;
      *(undefined4 *)((int)&DAT_00511d4c + iVar9) = *(undefined4 *)((int)&DAT_00511d2c + iVar9);
      if (param_1 == 3) {
        if (iVar6 == 1) {
          if ((int)local_10 <= DAT_004da140) goto LAB_0042efe8;
          goto LAB_0042f013;
        }
      }
      else {
LAB_0042efe8:
        if ((iVar6 == 1) &&
           ((((DAT_004da188 == 7 && (DAT_005364e0 == 0)) || (DAT_004da188 == 2)) ||
            (DAT_004da188 == 1)))) {
LAB_0042f013:
          uVar11 = (int)local_10 >> 0x1f;
          if (((local_10 ^ uVar11) - uVar11 & 1 ^ uVar11) == uVar11) {
            FUN_0042f220(DAT_004f4a68,DAT_004f6d34,iVar7,DAT_004f7f94 + DAT_004da214 * 0x6e);
            iVar10 = DAT_004fe080;
            *(int *)((int)&DAT_00511d40 + iVar9) = DAT_00523180;
            iVar6 = DAT_004da214;
            *(int *)((int)&DAT_005117c0 + iVar9) = iVar10;
            FUN_0042f220(DAT_004f4a68,DAT_004f6d34,iVar7,DAT_004f7f94 + iVar6 * -0x91);
            iVar6 = DAT_00523180;
            *(int *)((int)&DAT_005117c4 + iVar9) = DAT_004fe080;
            *local_8 = iVar6;
          }
          else {
            FUN_0042f220(DAT_00523248,DAT_0052359c,iVar7,DAT_004f7f94 + DAT_004da214 * -0x6e);
            iVar10 = DAT_00523180;
            *(int *)((int)&DAT_005117c0 + iVar9) = DAT_004fe080;
            iVar6 = DAT_004da214;
            *(int *)((int)&DAT_00511d40 + iVar9) = iVar10;
            FUN_0042f220(DAT_00523248,DAT_0052359c,iVar7,DAT_004f7f94 + iVar6 * 0x91);
            iVar6 = DAT_00523180;
            *(int *)((int)&DAT_005117c4 + iVar9) = DAT_004fe080;
            *local_8 = iVar6;
          }
        }
      }
      local_10 = local_10 + 1;
      iVar9 = iVar9 + 0x28;
      piVar8 = piVar8 + 10;
      local_8 = local_8 + 10;
    } while ((int)local_10 <= DAT_004da194);
  }
  iVar9 = DAT_004da194;
  _DAT_004f83a0 = (double)DAT_00536410;
  _DAT_004fb070 = (double)DAT_00536414;
  _DAT_004f83a8 = (double)DAT_004fe094;
  _DAT_004fb078 = (double)DAT_004fe2a0;
  _DAT_004f83b0 = (double)DAT_005229d4;
  _DAT_004fb080 = (double)DAT_00522ac8;
  _DAT_004f83b8 = (double)DAT_00522acc;
  _DAT_004fb088 = (double)DAT_00522ae0;
  _DAT_004f83c0 = (double)DAT_005229c8;
  _DAT_004fb090 = (double)DAT_00522ac4;
  dVar1 = (double)DAT_004f6d34;
  dVar2 = (double)DAT_00523248;
  dVar3 = (double)DAT_0052359c;
  *(double *)(&DAT_004f83c8 + DAT_004da194 * 2) = (double)DAT_004f4a68;
  *(double *)(&DAT_004fb098 + iVar9 * 2) = dVar1;
  *(double *)(iVar9 * 8 + 0x4f83d0) = dVar2;
  *(double *)(&DAT_004fb0a0 + iVar9 * 8) = dVar3;
  return;
}

