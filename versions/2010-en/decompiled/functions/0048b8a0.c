
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0048b8a0(int param_1)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double *pdVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  double *pdVar11;
  int iVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  int local_b8c;
  int *local_b88;
  double *local_b84;
  int local_b80;
  undefined4 uStack_b7c;
  undefined4 local_b78;
  undefined4 uStack_b74;
  undefined4 local_b70;
  undefined4 uStack_b6c;
  int local_b64;
  undefined8 local_b48;
  double adStack_908 [72];
  double adStack_6c8 [72];
  double local_488 [72];
  double adStack_248 [72];
  
  if (DAT_004da248 == 1) {
    local_b78 = 0xf5c28f5c;
    uStack_b74 = 0x3fef5c28;
  }
  else {
    local_b78 = 0x9999999a;
    uStack_b74 = 0x3ff59999;
  }
  if (DAT_004da248 == 2) {
    local_b78 = 0x66666666;
    uStack_b74 = 0x3fe66666;
  }
  if (param_1 == 1) {
    if ((DAT_004da240 == -1) && (DAT_004da244 == -1)) {
      dVar1 = _DAT_004cd028;
      if (DAT_004da248 == 2) {
        dVar1 = _DAT_004cc538;
      }
      fVar13 = (float10)fsin((float10)DAT_004da23c * (float10)_DAT_004cc568);
      DAT_0053521c = (undefined4)
                     (longlong)
                     (fVar13 * (float10)DAT_004da238 * (float10)dVar1 *
                      (float10)(double)CONCAT44(uStack_b74,local_b78) * (float10)_DAT_004cd030);
      fVar13 = (float10)fcos((float10)DAT_004da23c * (float10)_DAT_004cc568);
      DAT_004f4b5c = (undefined4)
                     (longlong)
                     (fVar13 * (float10)DAT_004da238 * (float10)dVar1 *
                      (float10)(double)CONCAT44(uStack_b74,local_b78) * (float10)_DAT_004cd038);
    }
    if ((DAT_004da240 == 0) && (DAT_004da244 == 0)) {
      fVar13 = (float10)fsin((float10)DAT_004da23c * (float10)_DAT_004cc568);
      DAT_0053521c = (undefined4)
                     (longlong)
                     (fVar13 * (float10)DAT_004da238 *
                      (float10)(double)CONCAT44(uStack_b74,local_b78) * (float10)_DAT_004cd040);
      fVar13 = (float10)fcos((float10)DAT_004da23c * (float10)_DAT_004cc568);
      DAT_004f4b5c = (undefined4)
                     (longlong)
                     (fVar13 * (float10)DAT_004da238 *
                      (float10)(double)CONCAT44(uStack_b74,local_b78) * (float10)_DAT_004cd048);
    }
    if ((DAT_004da240 == 1) && (DAT_004da244 == 1)) {
      dVar1 = _DAT_004cc468;
      if (DAT_004da248 == 2) {
        dVar1 = _DAT_004cd050;
      }
      fVar13 = (float10)fsin((float10)DAT_004da23c * (float10)_DAT_004cc568);
      DAT_0053521c = (undefined4)
                     (longlong)
                     (fVar13 * (float10)DAT_004da238 * (float10)dVar1 *
                      (float10)(double)CONCAT44(uStack_b74,local_b78) * (float10)_DAT_004cd030);
      fVar13 = (float10)fcos((float10)DAT_004da23c * (float10)_DAT_004cc568);
      DAT_004f4b5c = (undefined4)
                     (longlong)
                     (fVar13 * (float10)DAT_004da238 * (float10)dVar1 *
                      (float10)(double)CONCAT44(uStack_b74,local_b78) * (float10)_DAT_004cd038);
    }
    if ((DAT_004da240 != -1) || (DAT_004da270 = 1, DAT_004da244 != 1)) {
      DAT_004da270 = 0;
    }
    if ((DAT_004da240 == 1) && (DAT_004da244 == -1)) {
      DAT_004da270 = DAT_004da244;
LAB_0048ba70:
      fVar13 = (float10)fsin((float10)DAT_004da23c * (float10)_DAT_004cc568);
      DAT_0053521c = (undefined4)
                     (longlong)
                     (fVar13 * (float10)DAT_004da238 *
                      (float10)(double)CONCAT44(uStack_b74,local_b78) * (float10)_DAT_004cd000);
      fVar13 = (float10)fcos((float10)DAT_004da23c * (float10)_DAT_004cc568);
      DAT_004f4b5c = (undefined4)
                     (longlong)
                     (fVar13 * (float10)DAT_004da238 *
                      (float10)(double)CONCAT44(uStack_b74,local_b78) * (float10)_DAT_004cd058);
    }
    else if ((DAT_004da240 == -1) && (DAT_004da244 == 1)) goto LAB_0048ba70;
    DAT_004fb5e8._0_4_ = 0xeb851eb8;
    DAT_004fb5e8._4_4_ = 0x3fdeb851;
    iVar3 = DAT_004da238 * 4;
    DAT_00534fe4 = iVar3;
    if (DAT_004da240 == -1) {
      if ((DAT_004da244 == -1) && (DAT_004da248 == 0)) {
        DAT_00534fe4 = DAT_004da238 * 5;
      }
      if ((DAT_004da244 == -1) && (DAT_004da248 == 2)) {
        DAT_00534fe4 = DAT_004da238 / 0xf + iVar3;
      }
    }
    if (DAT_004da238 == 0x5dc) {
      DAT_004fb5e8._0_4_ = 0;
      DAT_004fb5e8._4_4_ = 0x3fe00000;
    }
    if (DAT_004da238 == 0x9c4) {
      DAT_004fb5e8._0_4_ = 0xc28f5c29;
      DAT_004fb5e8._4_4_ = 0x3fdc28f5;
    }
    iVar3 = FUN_0041bc20(DAT_004da23c + 0x5a);
    DAT_004fafb0 = (double)iVar3 * _DAT_004cc568;
    if (DAT_004da270 == 1) {
      iVar3 = FUN_0041bc20(DAT_004da23c + 0x54);
      DAT_004fafb0 = (double)iVar3 * _DAT_004cc568;
    }
    if (DAT_004da270 == -1) {
      iVar3 = FUN_0041bc20(DAT_004da23c + 0x60);
      DAT_004fafb0 = (double)iVar3 * _DAT_004cc568;
    }
    DAT_0051359c = (undefined4)(longlong)(DAT_004fafb0 * _DAT_004cc3e8);
    DAT_00522cb4 = (-(uint)(DAT_004da270 != 1) & 0xfffffffe) + 0xc;
    if (DAT_004da270 == -1) {
      DAT_00522cb4 = 8;
    }
    DAT_004f45c8 = 0;
    DAT_004f45cc = 0;
    if ((DAT_004da240 == -1) && (DAT_004da244 == -1)) {
      DAT_00522cb4 = DAT_004da244;
    }
    _DAT_004f3ef4 = DAT_004da250;
    if ((DAT_004da240 == 1) && (DAT_004da244 == 1)) {
      DAT_00535314 = 0xe;
      DAT_00535374 = 0x16;
    }
    else {
      DAT_00535314 = 10;
      DAT_00535374 = 0x1a;
    }
  }
  if (param_1 == 2) {
    if (DAT_004da240 == 1) {
      local_b88 = (int *)(DAT_004da23c + 0x69);
      local_b80 = 0x33333333;
      uStack_b7c = 0x3ffb3333;
    }
    if (DAT_004da240 == 0) {
      local_b88 = (int *)(DAT_004da23c + 0x5a);
      local_b80 = DAT_004da240;
      uStack_b7c = 0x40000000;
    }
    if (DAT_004da240 == -1) {
      local_b88 = (int *)(DAT_004da23c + 0x4b);
      local_b80 = 0;
      uStack_b7c = 0x40040000;
    }
    local_b8c = DAT_004da23c + 0x2f;
    if (DAT_004da238 == 0x5dc) {
      local_b8c = DAT_004da23c + 0x32;
    }
    if (DAT_004da238 == 0x9c4) {
      local_b8c = DAT_004da23c + 0x2c;
    }
    fVar13 = (float10)fsin((float10)local_b8c * (float10)_DAT_004cc568);
    DAT_00535220 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                    * (float10)(double)CONCAT44(uStack_b7c,local_b80) * (float10)_DAT_004cca00);
    fVar13 = (float10)fcos((float10)local_b8c * (float10)_DAT_004cc568);
    DAT_004f4b60 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                    * (float10)(double)CONCAT44(uStack_b7c,local_b80) * (float10)_DAT_004cd070);
    _DAT_00534fe8 = DAT_004da238 * 6;
    if (0 < DAT_004da248) {
      _DAT_00534fe8 = DAT_004da238 * 5;
    }
    _DAT_004fb5f0 = 0x33333333;
    _DAT_004fb5f4 = 0x3fd33333;
    if (DAT_004da240 == -1) {
      _DAT_00534fe8 = (int)(longlong)((double)_DAT_00534fe8 * _DAT_004cc7b8);
    }
    iVar3 = FUN_0041bc20((int)local_b88);
    DAT_00522cb8 = 10;
    DAT_004fafb8 = (double)iVar3 * _DAT_004cc568;
    DAT_004f45d0 = 0;
    DAT_004f45d4 = 0;
    _DAT_004f3ef8 = DAT_004da250;
    if (1 < DAT_004da250) {
      _DAT_004f3ef8 = 1;
    }
    DAT_00535318 = 5;
    DAT_00535378 = 0x24;
  }
  if (param_1 == 3) {
    if (DAT_004da244 == 1) {
      local_b88 = (int *)(DAT_004da23c + 0x4b);
      local_b80 = 0x33333333;
      uStack_b7c = 0x3ffb3333;
    }
    if (DAT_004da244 == 0) {
      local_b88 = (int *)(DAT_004da23c + 0x5a);
      uStack_b7c = 0x40000000;
      local_b80 = DAT_004da244;
    }
    if (DAT_004da244 == -1) {
      local_b88 = (int *)(DAT_004da23c + 0x69);
      local_b80 = 0;
      uStack_b7c = 0x40040000;
    }
    local_b8c = DAT_004da23c + -0x2f;
    if (DAT_004da238 == 0x5dc) {
      local_b8c = DAT_004da23c + -0x32;
    }
    if (DAT_004da238 == 0x9c4) {
      local_b8c = DAT_004da23c + -0x2c;
    }
    fVar13 = (float10)fsin((float10)local_b8c * (float10)_DAT_004cc568);
    _DAT_00535224 =
         (undefined4)
         (longlong)
         (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78) *
          (float10)(double)CONCAT44(uStack_b7c,local_b80) * (float10)_DAT_004cca00);
    fVar13 = (float10)fcos((float10)local_b8c * (float10)_DAT_004cc568);
    _DAT_004f4b64 =
         (undefined4)
         (longlong)
         (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78) *
          (float10)(double)CONCAT44(uStack_b7c,local_b80) * (float10)_DAT_004cd070);
    _DAT_00534fec = DAT_004da238 * 6;
    if (0 < DAT_004da248) {
      _DAT_00534fec = DAT_004da238 * 5;
    }
    _DAT_004fb5f8 = 0x33333333;
    _DAT_004fb5fc = 0x3fd33333;
    if (DAT_004da240 == 1) {
      _DAT_00534fec = (int)(longlong)((double)_DAT_00534fec * _DAT_004cc7b8);
    }
    iVar3 = FUN_0041bc20((int)local_b88);
    _DAT_00522cbc = 9;
    _DAT_004fafc0 = (double)iVar3 * _DAT_004cc568;
    _DAT_004f45d8 = 0;
    _DAT_004f45dc = 0;
    _DAT_004f3efc = DAT_004da250;
    if (1 < DAT_004da250) {
      _DAT_004f3efc = 1;
    }
    _DAT_0053531c = 5;
    _DAT_0053537c = 0x24;
  }
  if (param_1 == 4) {
    fVar13 = (float10)(DAT_004da23c + -0x1e) * (float10)_DAT_004cc568;
    fVar14 = (float10)fsin(fVar13);
    _DAT_00535228 =
         (undefined4)
         (longlong)
         (fVar14 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78) *
         (float10)_DAT_004cc7a0);
    fVar13 = (float10)fcos(fVar13);
    _DAT_004f4b68 =
         (undefined4)
         (longlong)
         (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78) *
         (float10)_DAT_004cc798);
    _DAT_00534ff0 = DAT_004da238 * 9;
    _DAT_004fb600 = _DAT_004cc660;
    if ((DAT_004da240 == 1) && (DAT_004da244 == 1)) {
      _DAT_004fb600 = 0x3fdeb851eb851eb8;
    }
    uVar9 = -(uint)(DAT_004da270 != 0) & 0x12;
    if (DAT_004da240 == 1) {
      local_b88 = (int *)(DAT_004da23c + 0x5a + uVar9);
      local_b80 = 0x33333333;
      uStack_b7c = 0x3ffb3333;
    }
    if (DAT_004da240 == 0) {
      local_b88 = (int *)(DAT_004da23c + 0x5a);
      local_b80 = DAT_004da240;
      uStack_b7c = 0x40000000;
    }
    if (DAT_004da240 == -1) {
      local_b80 = 0;
      local_b88 = (int *)((DAT_004da23c - uVar9) + 0x5a);
      uStack_b7c = 0x40040000;
    }
    iVar3 = FUN_0041bc20((int)local_b88);
    _DAT_00522cc0 = 8;
    _DAT_004fafc8 = (double)iVar3 * _DAT_004cc568;
    _DAT_004f45e0 = 0;
    _DAT_004f45e4 = 0x3ff00000;
    _DAT_004f3f00 = 0;
    _DAT_00535320 = 0;
    _DAT_00535380 = 0;
  }
  if (param_1 == 5) {
    fVar13 = (float10)(DAT_004da23c + 0x19) * (float10)_DAT_004cc568;
    fVar14 = (float10)fsin(fVar13);
    DAT_0053522c = (undefined4)
                   (longlong)
                   (fVar14 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cc7a0);
    fVar13 = (float10)fcos(fVar13);
    DAT_004f4b6c = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cc798);
    _DAT_00534ff4 = DAT_004da238 * 9;
    _DAT_004fb608 = _DAT_004cc660;
    if ((DAT_004da240 == 1) && (DAT_004da244 == 1)) {
      _DAT_004fb608 = 0x3fdeb851eb851eb8;
    }
    uVar9 = -(uint)(DAT_004da270 != 0) & 0x12;
    if (DAT_004da244 == 1) {
      local_b80 = 0x33333333;
      uStack_b7c = 0x3ffb3333;
      local_b88 = (int *)((DAT_004da23c - uVar9) + 0x5a);
    }
    if (DAT_004da244 == 0) {
      local_b88 = (int *)(DAT_004da23c + 0x5a);
      local_b80 = DAT_004da244;
      uStack_b7c = 0x40000000;
    }
    if (DAT_004da244 == -1) {
      local_b88 = (int *)(DAT_004da23c + 0x5a + uVar9);
      local_b80 = 0;
      uStack_b7c = 0x40040000;
    }
    iVar3 = FUN_0041bc20((int)local_b88);
    _DAT_00522cc4 = 10;
    _DAT_004fafd0 = (double)iVar3 * _DAT_004cc568;
    _DAT_004f45e8 = 0;
    _DAT_004f45ec = 0x3ff00000;
    _DAT_004f3f04 = 0;
    _DAT_00535324 = 0;
    _DAT_00535384 = 0;
  }
  if (DAT_004da260 == 1) {
    local_b78 = 0;
    uStack_b74 = 0x3ff00000;
  }
  else {
    local_b78 = 0x66666666;
    uStack_b74 = 0x3ff66666;
  }
  if (param_1 != 6) goto LAB_0048c623;
  if ((DAT_004da254 == -1) && (DAT_004da258 == -1)) {
    fVar13 = (float10)fsin((float10)DAT_004da25c * (float10)_DAT_004cc568);
    DAT_00535230 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cd078);
    fVar13 = (float10)fcos((float10)DAT_004da25c * (float10)_DAT_004cc568);
    DAT_004f4b70 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cd080);
  }
  if ((DAT_004da254 == 0) && (DAT_004da258 == 0)) {
    fVar13 = (float10)fsin((float10)DAT_004da25c * (float10)_DAT_004cc568);
    DAT_00535230 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cd088);
    fVar13 = (float10)fcos((float10)DAT_004da25c * (float10)_DAT_004cc568);
    DAT_004f4b70 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cd090);
  }
  if ((DAT_004da254 == 1) && (DAT_004da258 == 1)) {
    fVar13 = (float10)fsin((float10)DAT_004da25c * (float10)_DAT_004cc568);
    DAT_00535230 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cd098);
    fVar13 = (float10)fcos((float10)DAT_004da25c * (float10)_DAT_004cc568);
    DAT_004f4b70 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cd0a0);
  }
  _DAT_00522cc8 = (-(uint)(DAT_004da274 != 1) & 0xfffffffe) + 0xc;
  if (DAT_004da274 == -1) {
    _DAT_00522cc8 = 8;
  }
  if ((DAT_004da254 != -1) || (DAT_004da274 = 1, DAT_004da258 != 1)) {
    DAT_004da274 = 0;
  }
  if ((DAT_004da254 == 1) && (DAT_004da258 == -1)) {
    DAT_004da274 = DAT_004da258;
LAB_0048c425:
    fVar13 = (float10)fsin((float10)DAT_004da25c * (float10)_DAT_004cc568);
    DAT_00535230 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cd000);
    fVar13 = (float10)fcos((float10)DAT_004da25c * (float10)_DAT_004cc568);
    DAT_004f4b70 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cd058);
  }
  else if ((DAT_004da254 == -1) && (DAT_004da258 == 1)) goto LAB_0048c425;
  _DAT_004fb610 = 0xeb851eb8;
  _DAT_004fb614 = 0x3fdeb851;
  if (DAT_00536504 == 1) {
    DAT_00534ff8 = DAT_004da238 * 5;
  }
  else {
    DAT_00534ff8 = DAT_004da238 * 4;
  }
  if (DAT_004da238 == 0x5dc) {
    _DAT_004fb610 = 0;
    _DAT_004fb614 = 0x3fe00000;
  }
  if (DAT_004da238 == 0x9c4) {
    _DAT_004fb610 = 0xc28f5c29;
    _DAT_004fb614 = 0x3fdc28f5;
  }
  iVar3 = FUN_0041bc20(DAT_004da25c + 0x5a);
  _DAT_004fafd8 = (double)iVar3 * _DAT_004cc568;
  if (DAT_004da274 == 1) {
    iVar3 = FUN_0041bc20(DAT_004da25c + 0x54);
    _DAT_004fafd8 = (double)iVar3 * _DAT_004cc568;
  }
  if (DAT_004da274 == -1) {
    iVar3 = FUN_0041bc20(DAT_004da25c + 0x60);
    _DAT_004fafd8 = (double)iVar3 * _DAT_004cc568;
  }
  DAT_004f711c = (undefined4)(longlong)(_DAT_004fafd8 * _DAT_004cc3e8);
  _DAT_00522cc8 = (-(uint)(DAT_004da274 != 1) & 0xfffffffe) + 0xc;
  if (DAT_004da274 == -1) {
    _DAT_00522cc8 = 8;
  }
  _DAT_004f45f0 = 0;
  _DAT_004f45f4 = 0;
  if ((DAT_004da254 == -1) && (DAT_004da258 == -1)) {
    _DAT_00522cc8 = -1;
  }
  _DAT_004f3f08 = DAT_00536500;
  if (0 < DAT_00536504) {
    DAT_00534ff8 = DAT_00534ff8 / 3;
    _DAT_004f3f08 = 0;
  }
  _DAT_00535328 = 10;
  _DAT_00535388 = 0x1a;
LAB_0048c623:
  local_b8c = 0;
  if (param_1 == 7) {
    if (DAT_004da254 == 1) {
      local_b88 = (int *)(DAT_004da25c + 0x69);
      local_b80 = 0x33333333;
      uStack_b7c = 0x3ffb3333;
    }
    if (DAT_004da254 == 0) {
      local_b88 = (int *)(DAT_004da25c + 0x5a);
      local_b80 = 0;
      uStack_b7c = 0x40000000;
    }
    if (DAT_004da254 == -1) {
      local_b88 = (int *)(DAT_004da25c + 0x4b);
      local_b80 = 0;
      uStack_b7c = 0x40040000;
    }
    local_b8c = DAT_004da25c + 0x2f;
    if (DAT_004da238 == 0x5dc) {
      local_b8c = DAT_004da25c + 0x32;
    }
    if (DAT_004da238 == 0x9c4) {
      local_b8c = DAT_004da25c + 0x2c;
    }
    fVar13 = (float10)fsin((float10)local_b8c * (float10)_DAT_004cc568);
    DAT_00535234 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                    * (float10)(double)CONCAT44(uStack_b7c,local_b80) * (float10)_DAT_004cca00);
    fVar13 = (float10)fcos((float10)local_b8c * (float10)_DAT_004cc568);
    DAT_004f4b74 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                    * (float10)(double)CONCAT44(uStack_b7c,local_b80) * (float10)_DAT_004cd070);
    _DAT_004fb618 = _DAT_004cc660;
    DAT_00534ffc = DAT_004da238 * 6;
    if (DAT_004da254 == -1) {
      DAT_00534ffc = (int)(longlong)((double)DAT_00534ffc * _DAT_004cc7b8);
    }
    iVar3 = FUN_0041bc20((int)local_b88);
    _DAT_00522ccc = 10;
    local_b8c = 0;
    _DAT_004fafe0 = (double)iVar3 * _DAT_004cc568;
    _DAT_004f45f8 = 0;
    _DAT_004f45fc = 0;
    _DAT_004f3f0c = DAT_00536500;
    if (1 < DAT_00536500) {
      _DAT_004f3f0c = 1;
    }
    if (DAT_00536504 == 3) {
      DAT_00534ffc = DAT_00534ffc / 3;
      _DAT_00522ccc = 0x1e;
      local_b8c = 4;
      _DAT_004f3f0c = 0;
    }
    _DAT_0053532c = 0;
    _DAT_0053538c = 0x48;
  }
  if (param_1 == 8) {
    if (DAT_004da258 == 1) {
      local_b88 = (int *)(DAT_004da25c + 0x4b);
      local_b80 = 0x33333333;
      uStack_b7c = 0x3ffb3333;
    }
    if (DAT_004da258 == 0) {
      local_b88 = (int *)(DAT_004da25c + 0x5a);
      local_b80 = 0;
      uStack_b7c = 0x40000000;
    }
    if (DAT_004da258 == -1) {
      local_b88 = (int *)(DAT_004da25c + 0x69);
      local_b80 = 0;
      uStack_b7c = 0x40040000;
    }
    local_b8c = DAT_004da25c + -0x2f;
    if (DAT_004da238 == 0x5dc) {
      local_b8c = DAT_004da25c + -0x32;
    }
    if (DAT_004da238 == 0x9c4) {
      local_b8c = DAT_004da25c + -0x2c;
    }
    fVar13 = (float10)fsin((float10)local_b8c * (float10)_DAT_004cc568);
    DAT_00535238 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                    * (float10)(double)CONCAT44(uStack_b7c,local_b80) * (float10)_DAT_004cca00);
    fVar13 = (float10)fcos((float10)local_b8c * (float10)_DAT_004cc568);
    _DAT_004f4b78 =
         (undefined4)
         (longlong)
         (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78) *
          (float10)(double)CONCAT44(uStack_b7c,local_b80) * (float10)_DAT_004cd070);
    _DAT_004fb620 = _DAT_004cc660;
    DAT_00535000 = DAT_004da238 * 6;
    if (DAT_004da254 == 1) {
      DAT_00535000 = (int)(longlong)((double)DAT_00535000 * _DAT_004cc7b8);
    }
    iVar3 = FUN_0041bc20((int)local_b88);
    _DAT_00522cd0 = 10;
    _DAT_004fafe8 = (double)iVar3 * _DAT_004cc568;
    local_b8c = 0;
    _DAT_004f4600 = 0;
    _DAT_004f4604 = 0;
    _DAT_004f3f10 = DAT_00536500;
    if (1 < DAT_00536500) {
      _DAT_004f3f10 = 1;
    }
    if (DAT_00536504 == 3) {
      DAT_00535000 = DAT_00535000 / 3;
      _DAT_00522cd0 = 1;
      local_b8c = 0x22;
      _DAT_004f3f10 = 0;
    }
    _DAT_00535330 = 0;
    _DAT_00535390 = 0x48;
  }
  if (param_1 == 9) {
    fVar13 = (float10)(DAT_004da25c + -0x1e) * (float10)_DAT_004cc568;
    fVar14 = (float10)fsin(fVar13);
    DAT_0053523c = (undefined4)
                   (longlong)
                   (fVar14 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cc7a0);
    fVar13 = (float10)fcos(fVar13);
    _DAT_004f4b7c =
         (undefined4)
         (longlong)
         (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78) *
         (float10)_DAT_004cc798);
    _DAT_00535004 = DAT_004da238 * 9;
    _DAT_004fb628 = _DAT_004cceb0;
    if ((DAT_004da254 == 1) && (DAT_004da258 == 1)) {
      _DAT_004fb628 = 0x3fe0a3d70a3d70a4;
    }
    uVar9 = -(uint)(DAT_004da274 != 0) & 0x12;
    if (DAT_004da254 == 1) {
      local_b88 = (int *)(DAT_004da25c + 0x5a + uVar9);
    }
    if (DAT_004da254 == 0) {
      local_b88 = (int *)(DAT_004da25c + 0x5a);
    }
    if (DAT_004da254 == -1) {
      local_b88 = (int *)((DAT_004da25c - uVar9) + 0x5a);
    }
    iVar3 = FUN_0041bc20((int)local_b88);
    _DAT_00522cd4 = 10;
    _DAT_004faff0 = (double)iVar3 * _DAT_004cc568;
    local_b8c = 0;
    _DAT_004f4608 = 0;
    _DAT_004f460c = 0x3ff00000;
    _DAT_004f3f14 = 0;
    _DAT_00535334 = 0;
    _DAT_00535394 = 0;
  }
  if (param_1 == 10) {
    fVar13 = (float10)(DAT_004da25c + 0x19) * (float10)_DAT_004cc568;
    fVar14 = (float10)fsin(fVar13);
    DAT_00535240 = (undefined4)
                   (longlong)
                   (fVar14 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cc7a0);
    fVar13 = (float10)fcos(fVar13);
    DAT_004f4b80 = (undefined4)
                   (longlong)
                   (fVar13 * (float10)DAT_004da238 * (float10)(double)CONCAT44(uStack_b74,local_b78)
                   * (float10)_DAT_004cc798);
    _DAT_00535008 = DAT_004da238 * 9;
    _DAT_004fb630 = _DAT_004cceb0;
    if ((DAT_004da254 == 1) && (DAT_004da258 == 1)) {
      _DAT_004fb630 = 0x3fe0a3d70a3d70a4;
    }
    uVar9 = -(uint)(DAT_004da274 != 0) & 0x12;
    if (DAT_004da254 == 1) {
      local_b88 = (int *)(DAT_004da25c + 0x5a + uVar9);
    }
    if (DAT_004da254 == 0) {
      local_b88 = (int *)(DAT_004da25c + 0x5a);
    }
    if (DAT_004da254 == -1) {
      local_b88 = (int *)((DAT_004da25c - uVar9) + 0x5a);
    }
    iVar3 = FUN_0041bc20((int)local_b88);
    _DAT_00522cd8 = 10;
    local_b8c = 0;
    _DAT_004f4610 = 0;
    _DAT_004faff8 = (double)iVar3 * _DAT_004cc568;
    _DAT_004f4614 = 0x3ff00000;
    _DAT_004f3f18 = 0;
    _DAT_00535338 = 0;
    _DAT_00535398 = 0;
  }
  iVar10 = 0;
  local_b64 = 0;
  local_b88 = &DAT_00512d70;
  fVar13 = (float10)fcos((float10)*(double *)(&DAT_004fafa8 + param_1 * 8));
  iVar3 = *(int *)(&DAT_00534fe0 + param_1 * 4);
  iVar5 = *(int *)(&DAT_00535218 + param_1 * 4);
  iVar4 = *(int *)(&DAT_004f4b58 + param_1 * 4);
  iVar2 = *(int *)(&DAT_00522cb0 + param_1 * 4);
  local_b84 = local_488;
  iVar7 = param_1 * 0x124;
  fVar14 = (float10)fsin((float10)*(double *)(&DAT_004fafa8 + param_1 * 8));
  iVar8 = iVar7;
  do {
    pdVar11 = (double *)(&local_b48 + iVar10);
    dVar1 = (double)(iVar3 - *local_b88);
    local_b70 = SUB84(dVar1,0);
    uStack_b6c = (undefined4)((ulonglong)dVar1 >> 0x20);
    *(undefined4 *)pdVar11 = local_b70;
    *(undefined4 *)((int)&local_b48 + iVar10 * 8 + 4) = uStack_b6c;
    if (0 < iVar2) {
      if (iVar10 == iVar2) {
        *pdVar11 = dVar1 * _DAT_004ccac8;
      }
      if (iVar10 == iVar2 + 1) {
        *pdVar11 = *pdVar11 * _DAT_004ccd68;
      }
      if (iVar10 == iVar2 + 2) {
        *pdVar11 = *pdVar11 * _DAT_004cc848;
      }
      if (iVar10 == iVar2 + 3) {
        *pdVar11 = *pdVar11 * _DAT_004cc6c0;
      }
      if (iVar10 == iVar2 + 4) {
        *pdVar11 = *pdVar11 * _DAT_004ccc70;
      }
      if (iVar10 == iVar2 + 5) {
        *pdVar11 = *pdVar11 * _DAT_004cc508;
      }
      if (iVar10 == iVar2 + 6) {
        *pdVar11 = *pdVar11 * _DAT_004ccc00;
      }
      if (iVar10 == iVar2 + 7) {
        *pdVar11 = *pdVar11 * _DAT_004ccbe0;
      }
      if (iVar10 == iVar2 + 8) {
        *pdVar11 = *pdVar11 * _DAT_004cc738;
      }
      if (iVar10 == iVar2 + 9) {
        *pdVar11 = *pdVar11 * _DAT_004cc738;
      }
      if (iVar10 == iVar2 + 10) {
        *pdVar11 = *pdVar11 * _DAT_004ccbe0;
      }
      if (iVar10 == iVar2 + 0xb) {
        *pdVar11 = *pdVar11 * _DAT_004ccc00;
      }
      if (iVar10 == iVar2 + 0xc) {
        *pdVar11 = *pdVar11 * _DAT_004cc508;
      }
      if (iVar10 == iVar2 + 0xd) {
        *pdVar11 = *pdVar11 * _DAT_004ccc70;
      }
      if (iVar10 == iVar2 + 0xe) {
        *pdVar11 = *pdVar11 * _DAT_004cc6c0;
      }
      if (iVar10 == iVar2 + 0xf) {
        *pdVar11 = *pdVar11 * _DAT_004cc848;
      }
      if (iVar10 == iVar2 + 0x10) {
        *pdVar11 = *pdVar11 * _DAT_004ccd68;
      }
      if (iVar10 == iVar2 + 0x11) {
        *pdVar11 = *pdVar11 * _DAT_004ccac8;
      }
    }
    if (local_b8c != 0) {
      if (iVar10 == local_b8c + -1) {
        *pdVar11 = *pdVar11 * _DAT_004ccd70;
      }
      if (iVar10 == local_b8c) {
        *pdVar11 = *pdVar11 * _DAT_004cc630;
      }
      if (iVar10 == local_b8c + 1) {
        *pdVar11 = *pdVar11 * _DAT_004ccd70;
      }
    }
    fVar15 = (float10)fsin((float10)local_b64 * (float10)_DAT_004cc568);
    fVar16 = (float10)fcos((float10)local_b64 * (float10)_DAT_004cc568);
    fVar15 = fVar15 * (float10)*(double *)(&DAT_004fb5e0 + param_1 * 8) * (float10)*pdVar11;
    dVar1 = (double)-(fVar16 * (float10)*pdVar11);
    fVar16 = fVar15 * (float10)(double)fVar13 -
             -(fVar16 * (float10)*pdVar11) * (float10)(double)fVar14;
    adStack_908[iVar10] = (double)fVar15;
    fVar15 = fVar15 * (float10)(double)fVar14 + (float10)dVar1 * (float10)(double)fVar13;
    *local_b84 = dVar1;
    adStack_6c8[iVar10] = (double)fVar16;
    adStack_248[iVar10] = (double)fVar15;
    *(int *)(&DAT_004f1cf8 + iVar8) = (int)(longlong)fVar16 + iVar5;
    local_b88 = local_b88 + 1;
    local_b64 = local_b64 + 5;
    *(int *)(&DAT_004f8ee8 + iVar8) = (int)(longlong)fVar15 + iVar4;
    iVar12 = DAT_00522f08;
    iVar10 = iVar10 + 1;
    iVar8 = iVar8 + 4;
    local_b84 = local_b84 + 1;
  } while ((int)local_b88 < 0x512e8d);
  *(undefined4 *)(&DAT_004f1e18 + iVar7) = *(undefined4 *)(&DAT_004f1cf8 + iVar7);
  *(undefined4 *)(&DAT_004f9008 + iVar7) = *(undefined4 *)(&DAT_004f8ee8 + iVar7);
  iVar3 = DAT_004da1e8;
  if (0 < iVar12) {
    iVar4 = 0;
    iVar5 = DAT_004da194 * 8;
    pdVar11 = (double *)(iVar5 + 0x4fb0a8);
    pdVar6 = (double *)(iVar5 + 0x4f83d8);
    do {
      if (iVar3 == 0) {
        iVar2 = *(int *)((int)&DAT_004f4b5c + iVar4);
        *(double *)((int)&DAT_004f83c8 + iVar5) = (double)*(int *)((int)&DAT_0053521c + iVar4);
        *(double *)((int)&DAT_004fb098 + iVar5) = (double)iVar2;
      }
      if (iVar3 == 1) {
        iVar2 = *(int *)((int)&DAT_004f4b5c + iVar4);
        *pdVar6 = (double)*(int *)((int)&DAT_0053521c + iVar4);
        *pdVar11 = (double)iVar2;
      }
      iVar5 = iVar5 + 8;
      pdVar6 = pdVar6 + 1;
      pdVar11 = pdVar11 + 1;
      iVar4 = iVar4 + 4;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  return;
}

