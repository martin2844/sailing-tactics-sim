
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043cf60(void)

{
  double dVar1;
  double dVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  double dVar7;
  double dVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  double *pdVar16;
  code *pcVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  undefined4 *puVar21;
  float10 fVar22;
  float10 fVar23;
  float10 fVar24;
  float10 fVar25;
  float10 fVar26;
  LPCSTR pCVar27;
  undefined4 uVar28;
  undefined4 *local_4c;
  double *local_48;
  int *local_44;
  int local_40;
  undefined4 *local_3c;
  double local_38;
  double local_28;
  
  iVar18 = 1;
  iVar19 = 0;
  if (1 < DAT_004da174) {
    DAT_004fb9ac = DAT_004fb9ac + -1;
    if (DAT_004fb9ac < 0) {
      DAT_004fb9ac = 0;
    }
    if ((DAT_004da140 == 2) && (DAT_004fb9b0 = DAT_004fb9b0 + -1, DAT_004fb9b0 < 0)) {
      DAT_004fb9b0 = 0;
    }
  }
  if ((_DAT_005359f0 < _DAT_00523378 + _DAT_00523378) && (DAT_004da1d8 < 3)) {
    iVar10 = DAT_004f7200;
    if (0 < DAT_004da194) {
      local_44 = &DAT_004fe9d4;
      local_4c = &DAT_004f853c;
      local_48 = (double *)&DAT_004fb098;
      pdVar16 = (double *)&DAT_004f6c18;
      iVar20 = 0;
      do {
        FUN_00431960(iVar18);
        iVar10 = DAT_004da140;
        *(double *)((int)&DAT_004f6b00 + iVar19) = (double)*(int *)((int)&DAT_004f4d7c + iVar20);
        *pdVar16 = (double)*(int *)((int)&DAT_004fc354 + iVar20);
        if ((iVar10 < iVar18) && (2 < DAT_004da194)) {
          iVar10 = FUN_0041e000(10);
          dVar1 = *pdVar16;
          dVar2 = (double)iVar10 / (_DAT_004cc4c0 - (double)DAT_004da198 * _DAT_004cc5c8);
          dVar7 = _DAT_004cc650 - dVar2;
          dVar8 = (double)DAT_004f7f88;
          *(double *)((int)&DAT_004f6b00 + iVar19) =
               *(double *)((int)&DAT_004f6b00 + iVar19) * dVar7 + (double)DAT_004f6d38 * dVar2;
          *pdVar16 = dVar1 * dVar7 + dVar8 * dVar2;
        }
        uVar28 = *(undefined4 *)pdVar16;
        uVar3 = *(undefined4 *)((int)&DAT_004f6b00 + iVar19 + 4);
        *(undefined4 *)((int)&DAT_004f83c8 + iVar19) = *(undefined4 *)((int)&DAT_004f6b00 + iVar19);
        *(undefined4 *)((int)&DAT_004f83cc + iVar19) = uVar3;
        uVar3 = *(undefined4 *)((int)pdVar16 + 4);
        *(undefined4 *)local_48 = uVar28;
        *(undefined4 *)((int)local_48 + 4) = uVar3;
        *local_4c = 0;
        FUN_00437570(iVar18);
        iVar10 = DAT_004f7200;
        _DAT_004fe938 = (double)(DAT_00522b94 - DAT_004f7200);
        *(int *)((int)&DAT_00535744 + iVar20) = *(int *)((int)&DAT_00522b94 + iVar20) - DAT_004f7200
        ;
        DAT_00511624 = 1;
        DAT_00511628 = 1;
        *local_44 = 0;
        iVar13 = DAT_004da194;
        local_48 = (double *)((int)local_48 + 8);
        local_44 = local_44 + 1;
        *(undefined4 *)((int)&DAT_00522ff4 + iVar20) = 1;
        *(undefined4 *)((int)&DAT_004f4354 + iVar20) = 0;
        iVar18 = iVar18 + 1;
        iVar19 = iVar19 + 8;
        pdVar16 = pdVar16 + 1;
        iVar20 = iVar20 + 4;
        local_4c = local_4c + 1;
      } while (iVar18 <= iVar13);
    }
    if ((DAT_004da19c == 8) && (DAT_004f8b78 == 0)) {
      bVar6 = DAT_005362d4 < 0xb5;
      if (bVar6) {
        iVar18 = FUN_0041bc20(DAT_005362d4 - iVar10);
        _DAT_004fe938 = (double)iVar18;
        iVar10 = DAT_004f7200;
      }
      else {
        _DAT_004fe938 = 90.0;
      }
      DAT_00511624 = (uint)bVar6;
      if (DAT_004da140 == 2) {
        if (DAT_005362d4 < 0xb5) {
          DAT_00535748 = FUN_0041bc20(DAT_005362d4 - iVar10);
          DAT_00511628 = 1;
        }
        else {
          DAT_00535748 = 0x5a;
          DAT_00511628 = 0;
        }
      }
    }
  }
  if ((_DAT_005359f0 < _DAT_00535bc0 - _DAT_00523378 * _DAT_004cc5c8) &&
     (iVar18 = 0, -1 < DAT_004da1f4)) {
    do {
      FUN_00465ff0(iVar18);
      iVar18 = iVar18 + 1;
    } while (iVar18 <= DAT_004da1f4);
  }
  pcVar17 = PlaySoundA_exref;
  if ((DAT_004f8cd0 == DAT_004f42b8) && (DAT_005364c8 == 1)) {
    DAT_00511624 = 0;
    DAT_00500384 = 0;
    if (DAT_004da140 == 2) {
      DAT_00511628 = 0;
      DAT_00500388 = 0;
    }
  }
  dVar1 = _DAT_004cc5d0;
  if ((DAT_004da19c != 8) && (DAT_004da1f8 != 5)) {
    dVar1 = _DAT_004cc5a8;
  }
  if (DAT_00525a9c < 2000) {
    dVar1 = _DAT_004ccaf0;
  }
  _DAT_00523378 = (_DAT_00523d48 * dVar1) / (double)DAT_004da178;
  DAT_004da1ec = DAT_004da1ec + 1;
  if (1000 < DAT_004da1ec) {
    DAT_004da1ec = 1;
  }
  if ((((2 < DAT_004da1d8) && (_DAT_005359f0 <= _DAT_00523378 - _DAT_004ccaf8)) &&
      (_DAT_004cc698 <= _DAT_005359f0)) && (DAT_00536484 == 0)) {
    if (DAT_005364c8 == 0) {
      pCVar27 = (LPCSTR)0x8c;
    }
    else {
      pCVar27 = (LPCSTR)0x8e;
    }
    PlaySoundA(pCVar27,DAT_005359c8,0x40005);
  }
  if (2 < DAT_004da1d8) {
    if (((_DAT_005359f0 <= _DAT_00523378 - _DAT_004ccb00) && (_DAT_004cc6a0 <= _DAT_005359f0)) &&
       (DAT_00536484 == 0)) {
      PlaySoundA((LPCSTR)0x8e,DAT_005359c8,0x40005);
    }
    if (2 < DAT_004da1d8) {
      if (((_DAT_005359f0 <= _DAT_00523378 - _DAT_004ccb08) && (_DAT_004cc6a8 <= _DAT_005359f0)) &&
         (DAT_00536484 == 0)) {
        PlaySoundA((LPCSTR)0x8e,DAT_005359c8,0x40005);
      }
      if ((((2 < DAT_004da1d8) && (_DAT_005359f0 <= _DAT_00523378 - _DAT_004ccb10)) &&
          (_DAT_004cc760 <= _DAT_005359f0)) && (DAT_00536484 == 0)) {
        if (DAT_005364c8 == 0) {
          pCVar27 = (LPCSTR)0x8c;
        }
        else {
          pCVar27 = (LPCSTR)0x8e;
        }
        PlaySoundA(pCVar27,DAT_005359c8,0x40005);
      }
    }
  }
  _DAT_005359f0 = _DAT_005359f0 + _DAT_00523378;
  if ((DAT_004da190 == 7) && (DAT_005364c8 == 0)) {
    _DAT_004da164 = 0x40040000;
  }
  else {
    _DAT_004da164 = 0x3ff80000;
  }
  _DAT_004da160 = 0;
  if (0 < DAT_004da1f8) {
    if (DAT_004da1f8 == 5) {
      _DAT_004da160 = 0x33333333;
      _DAT_004da164 = 0x3fe33333;
    }
    else {
      _DAT_004da160 = 0xcccccccd;
      _DAT_004da164 = 0x3fdccccc;
    }
  }
  if (DAT_005364c8 == 1) {
    _DAT_004da160 = 0;
    _DAT_004da164 = 0x3fe00000;
  }
  if (DAT_004da19c == 8) {
    _DAT_004da160 = 0;
    _DAT_004da164 = 0x40280000;
  }
  if (_DAT_005359f0 <= _DAT_004cc658) {
    _DAT_004da160 = 0;
    _DAT_004da164 = 0x3ff00000;
  }
  _DAT_00534d68 = (double)CONCAT44(_DAT_004da164,_DAT_004da160) * _DAT_005359f0 * _DAT_004cc768;
  iVar18 = (int)(longlong)(_DAT_00534d68 * _DAT_004ccb18);
  DAT_004f6d60 = DAT_004faa58 - iVar18;
  if (DAT_004f6d60 < 0x18) {
LAB_0043d5dc:
    if (0x2f < DAT_004f6d60) goto LAB_0043d5e1;
  }
  else {
    if (DAT_004f6d60 < 0x30) {
      DAT_004f6d60 = DAT_004f6d60 + -0x18;
      goto LAB_0043d5dc;
    }
LAB_0043d5e1:
    DAT_004f6d60 = DAT_004f6d60 + -0x30;
  }
  if ((0x14 < DAT_004f6d60) || (DAT_00536450 = 0, DAT_004f6d60 < 6)) {
    DAT_00536450 = 1;
  }
  DAT_004fad34 = (int)(longlong)_DAT_00534d68 + iVar18 * 0x3c;
  if ((DAT_004fad34 == 0x1e) || (DAT_004fad34 == 0x3b)) {
    DAT_005359d4 = DAT_005362d4;
  }
  if (_DAT_005359f0 < _DAT_004cc658) {
    DAT_004fb9b8 = DAT_004fad34 * -0x3c - (int)(longlong)(_DAT_00534d68 * _DAT_004ccb20);
  }
  _DAT_005355f8 = _DAT_00534d68 * _DAT_004ccae0;
  if (_DAT_004cc658 <= _DAT_005359f0) {
    DAT_004fb9b8 = (int)(longlong)_DAT_005355f8;
  }
  DAT_004fe6c8 = DAT_004f8cd0;
  DAT_004f8cd0 = (int)(longlong)_DAT_005359f0;
  _DAT_004faf90 = 0;
  dVar1 = _DAT_004cc5a0;
  if ((DAT_004da1f8 != 5) && (dVar1 = _DAT_004cca20, DAT_00536408 == 0)) {
    dVar1 = _DAT_004cca38;
  }
  _DAT_00536230 = (double)CONCAT44(_DAT_00536234,_DAT_00536230);
  if (dVar1 < _DAT_005359f0 - (double)CONCAT44(_DAT_00536234,_DAT_00536230)) {
    _DAT_004faf90 = 1;
    DAT_00536394 = DAT_00536394 + 1;
    _DAT_00536230 = _DAT_005359f0;
    if (6 < DAT_00536394) {
      DAT_00536394 = 1;
    }
  }
  if (0 < DAT_004da194) {
    local_3c = (undefined4 *)(&DAT_004fb090 + DAT_004da194 * 8);
    local_48 = (double *)(&DAT_004f6af8 + DAT_004da194 * 8);
    local_44 = (int *)(&DAT_004f8538 + DAT_004da194 * 4);
    iVar18 = DAT_004da194;
    do {
      uVar14 = (int)DAT_005364e8 >> 0x1f;
      if (((DAT_005364e8 ^ uVar14) - uVar14 & 7 ^ uVar14) == uVar14) {
        if (DAT_004da1f8 == 0) {
          iVar19 = FUN_0042fca0((int)(longlong)*local_48,
                                (int)(longlong)*(double *)(&DAT_004f6c10 + iVar18 * 8),iVar18);
        }
        else {
          iVar19 = FUN_00430260((int)(longlong)*local_48,
                                (int)(longlong)*(double *)(&DAT_004f6c10 + iVar18 * 8),iVar18);
        }
        iVar10 = DAT_00536418;
        *(int *)(iVar18 * 4 + 0x536308) = iVar19;
        iVar19 = FUN_0041bc20(iVar10);
        *(int *)(&DAT_004fb420 + iVar18 * 4) = iVar19;
      }
      iVar19 = FUN_0041bc20(*(int *)(&DAT_004fb420 + iVar18 * 4));
      *(int *)(&DAT_004fb420 + iVar18 * 4) = iVar19;
      if ((iVar19 < 0) || (0x167 < iVar19)) {
        iVar10 = 0;
        iVar20 = 0;
      }
      else {
        uVar14 = *(uint *)(iVar18 * 4 + 0x536308);
        uVar15 = (int)uVar14 >> 0x1f;
        iVar20 = (uVar14 ^ uVar15) - uVar15;
        iVar10 = -((&DAT_004f85c8)[iVar19] * iVar20);
        iVar20 = (&DAT_004f1740)[iVar19] * iVar20;
      }
      if (DAT_004f8cd0 < 0) {
        iVar10 = iVar10 / 3;
        iVar20 = iVar20 / 3;
        if ((((-1 < DAT_004f8cd0) || (0x13 < *(int *)(&DAT_004fdfe8 + iVar18 * 4))) ||
            (DAT_004da140 < iVar18)) || ((DAT_004da198 < 8 || (8 < *local_44)))) goto LAB_0043d8a2;
        fVar22 = (float10)fsin((float10)DAT_004f7f94 * (float10)_DAT_004cc568);
        iVar19 = (int)(longlong)(fVar22 * (float10)_DAT_004ccb28);
        fVar22 = (float10)fcos((float10)DAT_004f7f94 * (float10)_DAT_004cc568);
        local_40 = (int)(longlong)(fVar22 * (float10)_DAT_004ccb30);
      }
      else {
LAB_0043d8a2:
        iVar19 = 0;
        local_40 = 0;
      }
      iVar11 = FUN_0041bc20(*(int *)(&DAT_00535740 + iVar18 * 4));
      iVar9 = DAT_005363c4;
      iVar4 = DAT_00522ad0;
      iVar13 = *(int *)(&DAT_004fdfe8 + iVar18 * 4);
      iVar12 = iVar13 * 100;
      fVar22 = (float10)fsin((float10)((double)iVar11 * _DAT_004cc568));
      dVar1 = (double)(fVar22 * (float10)iVar12);
      fVar23 = (float10)dVar1 + (float10)(iVar19 + iVar10);
      fVar22 = (float10)fcos((float10)((double)iVar11 * _DAT_004cc568));
      local_28 = (double)((float10)(local_40 + iVar20) - (float10)iVar12 * fVar22);
      *(int *)(&DAT_004fc230 + iVar18 * 4) =
           (int)(longlong)SQRT((float10)local_28 * (float10)local_28 + fVar23 * fVar23) / 100;
      uVar14 = (9 < iVar4) - 1 & 0xfffffed4;
      local_4c = (undefined4 *)(uVar14 + 0xa28);
      if (((iVar9 == 1) || (DAT_005363b8 == 1)) || (DAT_0053652c == 1)) {
        local_4c = (undefined4 *)(uVar14 + 0xb54);
      }
      if ((DAT_004faa48 < 0x23) && (DAT_004da190 != 3)) {
        local_4c = (undefined4 *)((int)local_4c + -200);
      }
      if (DAT_005363cc == 1) {
        local_4c = (undefined4 *)((int)local_4c + -200);
      }
      iVar4 = *(int *)(&DAT_004fe638 + iVar18 * 4);
      local_38 = (double)((float10)_DAT_00523378 / (float10)(int)local_4c);
      fVar24 = (float10)local_38 * (float10)local_28 +
               (float10)*(double *)(&DAT_004f6c10 + iVar18 * 8);
      dVar2 = (double)(((float10)_DAT_00523378 / (float10)(int)local_4c) * fVar23 +
                      (float10)*local_48);
      *local_48 = dVar2;
      *(double *)(&DAT_004f6c10 + iVar18 * 8) = (double)fVar24;
      *(double *)(&DAT_004f1610 + iVar18 * 8) = dVar1 * local_38 + dVar2;
      *(double *)(&DAT_004f3868 + iVar18 * 8) =
           (double)((float10)(iVar13 * -100) * fVar22 * (float10)local_38 + fVar24);
      if (0 < iVar4) {
        *(undefined4 *)(&DAT_005350d8 + iVar18 * 4) = 0;
        *(undefined4 *)(&DAT_00511620 + iVar18 * 4) = 1;
        *(undefined4 *)(&DAT_00512278 + iVar18 * 4) = 0x46;
        *(undefined4 *)(&DAT_00522ff0 + iVar18 * 4) = 1;
        *local_48 = (double)*(int *)(&DAT_004fb548 + iVar18 * 4);
        *(double *)(&DAT_004f6c10 + iVar18 * 8) = (double)*(int *)(&DAT_00522af0 + iVar18 * 4);
      }
      if (0 < *(int *)(&DAT_004fe6d0 + iVar18 * 4)) {
        iVar13 = FUN_0041bc20((&DAT_00522b90)[iVar18] -
                              *(int *)(&DAT_00522ff0 + iVar18 * 4) * DAT_004f7200);
        fVar22 = (float10)fsin((float10)((double)iVar13 * _DAT_004cc568));
        fVar23 = fVar22 * (float10)(*(int *)(&DAT_004fdfe8 + iVar18 * 4) * 100) +
                 (float10)(iVar19 + iVar10);
        fVar22 = (float10)fcos((float10)((double)iVar13 * _DAT_004cc568));
        local_28 = (double)((float10)(local_40 + iVar20) -
                           fVar22 * (float10)(*(int *)(&DAT_004fdfe8 + iVar18 * 4) * 100));
      }
      local_28 = local_28 * _DAT_004da1b8;
      *(int *)(&DAT_00513480 + iVar18 * 4) =
           (int)(longlong)
                ((float10)*local_48 - fVar23 * (float10)_DAT_004da1b8 * (float10)_DAT_004ccb38);
      uVar28 = *(undefined4 *)((int)local_48 + 4);
      uVar3 = *(undefined4 *)(&DAT_004f6c10 + iVar18 * 8);
      *(int *)(&DAT_00513510 + iVar18 * 4) =
           (int)(longlong)(*(double *)(&DAT_004f6c10 + iVar18 * 8) - local_28 * _DAT_004ccb38);
      uVar5 = *(undefined4 *)local_48;
      *local_3c = uVar3;
      *(undefined4 *)(&DAT_004f83c0 + iVar18 * 8) = uVar5;
      *(undefined4 *)(iVar18 * 8 + 0x4f83c4) = uVar28;
      iVar19 = DAT_004da174;
      local_3c[1] = *(undefined4 *)(iVar18 * 8 + 0x4f6c14);
      if (iVar19 < 9) {
LAB_0043dbaf:
        if (6 < iVar19) {
          if (DAT_004da1ec % 3 == 0) {
            FUN_00465e10(iVar18);
            iVar19 = DAT_004da174;
          }
          goto LAB_0043dbd4;
        }
LAB_0043dbd9:
        if (4 < iVar19) {
          if (DAT_004da1ec % 6 == 0) {
            FUN_00465e10(iVar18);
            iVar19 = DAT_004da174;
          }
          goto LAB_0043dbfe;
        }
LAB_0043dc03:
        if (2 < iVar19) {
          if (DAT_004da1ec % 0xc == 0) {
            FUN_00465e10(iVar18);
            iVar19 = DAT_004da174;
          }
          goto LAB_0043dc28;
        }
LAB_0043dc2d:
        if (DAT_004da1ec % 0x18 == 0) {
          FUN_00465e10(iVar18);
        }
      }
      else {
        if (iVar19 < 0xd) {
          FUN_00465e10(iVar18);
          iVar19 = DAT_004da174;
        }
        if (iVar19 < 9) goto LAB_0043dbaf;
LAB_0043dbd4:
        if (iVar19 < 7) goto LAB_0043dbd9;
LAB_0043dbfe:
        if (iVar19 < 5) goto LAB_0043dc03;
LAB_0043dc28:
        if (iVar19 < 3) goto LAB_0043dc2d;
      }
      iVar18 = iVar18 + -1;
      local_44 = local_44 + -1;
      local_48 = local_48 + -1;
      local_3c = local_3c + -2;
      pcVar17 = PlaySoundA_exref;
    } while (0 < iVar18);
  }
  iVar19 = 0;
  iVar18 = 0;
  do {
    iVar10 = FUN_0041bc20(*(int *)((int)&DAT_005357dc + iVar19) + 0xb4);
    iVar13 = FUN_0041bc20(iVar10);
    iVar10 = *(int *)((int)&DAT_004f42a4 + iVar19);
    iVar20 = (&DAT_004f1740)[iVar13];
    iVar19 = iVar19 + 4;
    *(double *)((int)&DAT_00535468 + iVar18) =
         (double)((&DAT_004f85c8)[iVar13] * iVar10 * 10) * local_38 +
         *(double *)((int)&DAT_00535468 + iVar18);
    *(double *)((int)&DAT_004f4b10 + iVar18) =
         (double)(iVar20 * iVar10 * -10) * local_38 + *(double *)((int)&DAT_004f4b10 + iVar18);
    iVar18 = iVar18 + 8;
  } while (iVar19 < 0x11);
  iVar19 = FUN_0041bc20(DAT_005362d4 + 0xb4);
  iVar18 = DAT_004da1f4;
  fVar24 = (float10)DAT_00522ad0;
  iVar10 = 0;
  fVar25 = (float10)fsin((float10)iVar19 * (float10)_DAT_004cc568);
  fVar26 = (float10)fcos((float10)iVar19 * (float10)_DAT_004cc568);
  fVar22 = (float10)_DAT_004cc490;
  fVar23 = (float10)_DAT_004ccb40;
  if (-1 < DAT_004da1f4) {
    do {
      pdVar16 = (double *)(&DAT_004f7220 + iVar10);
      iVar10 = iVar10 + 1;
      *(double *)(iVar10 * 8 + 0x4f7218) =
           (double)((float10)local_38 * fVar25 * fVar24 * fVar22 + (float10)*pdVar16);
      *(double *)(&DAT_004ff030 + iVar10 * 8) =
           (double)(fVar26 * fVar24 * fVar23 * (float10)local_38 +
                   (float10)*(double *)(&DAT_004ff030 + iVar10 * 8));
    } while (iVar10 <= iVar18);
  }
  if (DAT_00536394 != DAT_005364b8) {
    FUN_00444760();
    DAT_00534ea8 = DAT_00534ea8 + 1;
    if (500 < DAT_00534ea8) {
      DAT_00534ea8 = 500;
    }
    DAT_005364b8 = DAT_00536394;
  }
  puVar21 = &DAT_004fb210;
  for (iVar18 = 0xb; iVar18 != 0; iVar18 = iVar18 + -1) {
    *puVar21 = 0;
    puVar21 = puVar21 + 1;
  }
  dVar1 = _DAT_00536230;
  if (((DAT_00536484 != 0) || (DAT_004f7124 != 0)) || (DAT_004f7128 != 0)) goto LAB_0043df3b;
  if ((DAT_004f8cd0 % 200 == 0) && (10 < DAT_004f8cd0)) {
    (*pcVar17)(0x86,DAT_005359c8,0x40045);
    DAT_004f8cd0 = DAT_004f8cd0 + 1;
  }
  if ((((DAT_004f7094 == 1) || ((DAT_004da140 + -1) * DAT_004f7098 == 1)) || (0x32 < DAT_0051227c))
     && ((5 < DAT_004f8cd0 && (DAT_004fe63c == 0)))) {
    uVar28 = 0x98;
LAB_0043dee7:
    (*pcVar17)(uVar28,DAT_005359c8,0x40015);
  }
  else if ((5 < DAT_004f8cd0) &&
          ((((SQRT((double)DAT_004faa48) * _DAT_004cc580 < (double)DAT_004fdfec ||
             (SQRT((double)DAT_004faa48) * _DAT_004cc580 <
              (double)((DAT_004da140 + -1) * DAT_004fdff0))) && (DAT_004f7094 == 0)) &&
           (((DAT_004da140 + -1) * DAT_004f7098 == 0 && (0x59 < DAT_004feccc)))))) {
    uVar28 = 0x8a;
    goto LAB_0043dee7;
  }
  dVar1 = _DAT_00536230;
  if (((0 < DAT_004f8cd0) && (DAT_004fe6c8 < 1)) && (DAT_00536484 == 0)) {
    if (DAT_005364c8 == 0) {
      (*pcVar17)(0x8c,DAT_005359c8,0x40004);
      return;
    }
    (*pcVar17)(0x8e,DAT_005359c8,0x40005);
    dVar1 = _DAT_00536230;
  }
LAB_0043df3b:
  _DAT_00536234 = (undefined4)((ulonglong)dVar1 >> 0x20);
  _DAT_00536230 = SUB84(dVar1,0);
  return;
}

