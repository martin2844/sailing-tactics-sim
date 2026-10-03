
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042adb0(void)

{
  double dVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  double *pdVar14;
  code *pcVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined4 *puVar19;
  float10 fVar20;
  float10 fVar21;
  undefined4 uVar22;
  double local_40;
  undefined4 *local_38;
  int *local_34;
  double *local_30;
  undefined4 *local_2c;
  double local_20;
  
  iVar16 = 1;
  if ((_DAT_004ac1f8 < _DAT_004aa948 + _DAT_004aa948) && (DAT_004911cc < 3)) {
    iVar9 = DAT_004a4eb0;
    if (0 < DAT_0049118c) {
      iVar18 = 0;
      local_30 = (double *)&DAT_004a7974;
      local_38 = &DAT_004a5424;
      local_40 = (double)CONCAT44(local_40._4_4_,&DAT_004a60e0);
      pdVar14 = (double *)&DAT_004a4ae8;
      iVar17 = 0;
      do {
        FUN_00421c40(iVar16);
        iVar9 = DAT_00491140;
        *(double *)((int)&DAT_004a49f0 + iVar17) = (double)*(int *)((int)&DAT_004a488c + iVar18);
        *pdVar14 = (double)*(int *)((int)&DAT_004a6f4c + iVar18);
        if ((iVar9 < iVar16) && (2 < DAT_0049118c)) {
          iVar9 = FUN_00415a20(10);
          dVar1 = *pdVar14;
          dVar6 = (double)iVar9 / (_DAT_004850c8 - (double)DAT_00491190 * _DAT_00484e80);
          dVar7 = _DAT_00484e10 - dVar6;
          dVar8 = (double)DAT_004a4f84;
          *(double *)((int)&DAT_004a49f0 + iVar17) =
               *(double *)((int)&DAT_004a49f0 + iVar17) * dVar7 + (double)DAT_004a4be0 * dVar6;
          *pdVar14 = dVar1 * dVar7 + dVar8 * dVar6;
        }
        uVar22 = *(undefined4 *)pdVar14;
        *(undefined4 *)((int)&DAT_004a5320 + iVar17) = *(undefined4 *)((int)&DAT_004a49f0 + iVar17);
        *(undefined4 *)((int)&DAT_004a5324 + iVar17) = *(undefined4 *)((int)&DAT_004a49f4 + iVar17);
        uVar2 = *(undefined4 *)((int)pdVar14 + 4);
        *local_40._0_4_ = uVar22;
        local_40._0_4_[1] = uVar2;
        *local_38 = 0;
        FUN_00426ad0(iVar16);
        iVar9 = DAT_004a4eb0;
        _DAT_004a78e8 = (double)(DAT_004aa5b4 - DAT_004a4eb0);
        *(int *)((int)&DAT_004ac01c + iVar18) = *(int *)((int)&DAT_004aa5b4 + iVar18) - DAT_004a4eb0
        ;
        DAT_004a8914 = 1;
        DAT_004a8918 = 1;
        *(undefined4 *)local_30 = 0;
        iVar10 = DAT_0049118c;
        local_30 = (double *)((int)local_30 + 4);
        local_40 = (double)CONCAT44(local_40._4_4_,local_40._0_4_ + 2);
        *(undefined4 *)((int)&DAT_004aa734 + iVar18) = 1;
        *(undefined4 *)((int)&DAT_004a41f4 + iVar18) = 0;
        iVar16 = iVar16 + 1;
        iVar17 = iVar17 + 8;
        pdVar14 = pdVar14 + 1;
        iVar18 = iVar18 + 4;
        local_38 = local_38 + 1;
      } while (iVar16 <= iVar10);
    }
    if ((DAT_00491194 == 8) && (DAT_004a5a4c == 0)) {
      bVar5 = DAT_004ac840 < 0xb5;
      if (bVar5) {
        iVar16 = FUN_00413cb0(DAT_004ac840 - iVar9);
        _DAT_004a78e8 = (double)iVar16;
        iVar9 = DAT_004a4eb0;
      }
      else {
        _DAT_004a78e8 = 90.0;
      }
      DAT_004a8914 = (uint)bVar5;
      if (DAT_00491140 == 2) {
        if (DAT_004ac840 < 0xb5) {
          DAT_004ac020 = FUN_00413cb0(DAT_004ac840 - iVar9);
          DAT_004a8918 = 1;
        }
        else {
          DAT_004ac020 = 0x5a;
          DAT_004a8918 = 0;
        }
      }
    }
  }
  pcVar15 = PlaySoundA_exref;
  _DAT_004aa948 = (_DAT_004ab0c0 * _DAT_00484d88) / (double)DAT_00491170;
  if (((_DAT_004ac1f8 <= _DAT_004aa948 - _DAT_00485208) && (_DAT_00484f00 < _DAT_004ac1f8)) &&
     (DAT_004ac9c0 == 0)) {
    PlaySoundA((LPCSTR)0x8c,DAT_004ac1d4,0x40005);
  }
  if (((DAT_004911cc == 10) && (_DAT_004ac1f8 <= _DAT_004aa948 - _DAT_00485210)) &&
     ((_DAT_00485218 <= _DAT_004ac1f8 && (DAT_004ac9c0 == 0)))) {
    PlaySoundA((LPCSTR)0x8c,DAT_004ac1d4,0x40005);
  }
  _DAT_004ac1f8 = _DAT_004ac1f8 + _DAT_004aa948;
  DAT_0049115c = (DAT_00491188 == 7) + 2;
  if (DAT_00491194 == 8) {
    DAT_0049115c = 0xc;
  }
  if (_DAT_004ac1f8 <= _DAT_00484e18) {
    DAT_0049115c = 1;
  }
  _DAT_004ab8b8 = (double)DAT_0049115c * _DAT_004ac1f8 * _DAT_00484f08;
  iVar16 = (int)(longlong)(_DAT_004ab8b8 * _DAT_00485220);
  DAT_004a4be4 = DAT_004a5bac - iVar16;
  if (0x17 < DAT_004a4be4) {
    DAT_004a4be4 = DAT_004a4be4 + -0x18;
  }
  if ((DAT_004a4be4 < 0x15) && (5 < DAT_004a4be4)) {
    DAT_004ac98c = 0;
  }
  else {
    DAT_004ac98c = 1;
  }
  DAT_004a5e84 = (int)(longlong)_DAT_004ab8b8 + iVar16 * 0x3c;
  if (_DAT_00484e18 <= _DAT_004ac1f8) {
    DAT_004a6778 = 0;
  }
  else {
    DAT_004a6778 = (int)(longlong)(_DAT_004ab8b8 * _DAT_00484cc0) + DAT_004a5e84 * -0x3c;
  }
  _DAT_004abef0 = _DAT_004ab8b8 * _DAT_00484cc0;
  DAT_004a76c8 = DAT_004a5b80;
  DAT_004a5b80 = (int)(longlong)_DAT_004ac1f8;
  DAT_004a60a0 = 0;
  _DAT_004ac828 = (double)CONCAT44(_DAT_004ac82c,_DAT_004ac828);
  if (_DAT_00484eb8 < _DAT_004ac1f8 - (double)CONCAT44(_DAT_004ac82c,_DAT_004ac828)) {
    DAT_004a60a0 = 1;
    DAT_004ac8dc = DAT_004ac8dc + 1;
    _DAT_004ac828 = _DAT_004ac1f8;
    if (6 < DAT_004ac8dc) {
      DAT_004ac8dc = 1;
    }
  }
  if (0 < DAT_0049118c) {
    local_2c = (undefined4 *)(&DAT_004a60d8 + DAT_0049118c * 8);
    local_30 = (double *)(&DAT_004a4ae0 + DAT_0049118c * 8);
    local_34 = (int *)(&DAT_004a5420 + DAT_0049118c * 4);
    iVar16 = DAT_0049118c;
    do {
      if (DAT_004a60a0 == 1) {
        iVar17 = FUN_00421560((int)(longlong)*(double *)(&DAT_004a49e8 + iVar16 * 8),
                              (uint)(longlong)*local_30,iVar16);
        iVar9 = DAT_004aa960;
        *(int *)(iVar16 * 4 + 0x4ac860) = iVar17;
        iVar9 = FUN_00413cb0(iVar9);
        *(int *)(iVar16 * 4 + 0x4a63c0) = iVar9;
      }
      iVar18 = FUN_00413cb0(*(int *)(iVar16 * 4 + 0x4a63c0));
      uVar12 = *(uint *)(iVar16 * 4 + 0x4ac860);
      uVar13 = (int)uVar12 >> 0x1f;
      iVar9 = (&DAT_004a54a0)[iVar18];
      iVar10 = (uVar12 ^ uVar13) - uVar13;
      iVar17 = (&DAT_004a3450)[iVar18] * iVar10;
      *(int *)(iVar16 * 4 + 0x4a63c0) = iVar18;
      iVar9 = -(iVar9 * iVar10);
      if (DAT_004a5b80 < 0) {
        iVar9 = iVar9 / 3;
        iVar17 = iVar17 / 3;
        if ((((-1 < DAT_004a5b80) || (0x13 < *(int *)(&DAT_004a7060 + iVar16 * 4))) ||
            (DAT_00491140 < iVar16)) || ((DAT_00491190 < 8 || (8 < *local_34)))) goto LAB_0042b3cb;
        fVar20 = (float10)fsin((float10)DAT_004a4f8c * (float10)_DAT_00484d40);
        iVar18 = (int)(longlong)(fVar20 * (float10)_DAT_00485228);
        fVar20 = (float10)fcos((float10)DAT_004a4f8c * (float10)_DAT_00484d40);
        local_40._0_4_ = (undefined4 *)(longlong)(fVar20 * (float10)_DAT_00485230);
      }
      else {
LAB_0042b3cb:
        iVar18 = 0;
        local_40._0_4_ = (undefined4 *)0x0;
      }
      iVar11 = FUN_00413cb0(*(int *)(&DAT_004ac018 + iVar16 * 4));
      iVar3 = DAT_004ac90c;
      iVar10 = DAT_004aa390;
      iVar17 = (int)local_40._0_4_ + iVar17;
      fVar20 = (float10)fsin((float10)((double)iVar11 * _DAT_00484d40));
      fVar21 = fVar20 * (float10)(*(int *)(&DAT_004a7060 + iVar16 * 4) * 100) +
               (float10)(iVar18 + iVar9);
      fVar20 = (float10)fcos((float10)((double)iVar11 * _DAT_00484d40));
      local_20 = (double)((float10)iVar17 -
                         fVar20 * (float10)(*(int *)(&DAT_004a7060 + iVar16 * 4) * 100));
      *(int *)(&DAT_004a6e48 + iVar16 * 4) =
           (int)(longlong)SQRT((float10)local_20 * (float10)local_20 + fVar21 * fVar21) / 100;
      uVar12 = (9 < iVar10) - 1 & 0xfffffed4;
      iVar10 = uVar12 + 0xa28;
      if ((iVar3 == 1) || (DAT_004ac900 == 1)) {
        iVar10 = uVar12 + 0xb54;
      }
      if ((DAT_004a5ba4 < 0x23) && (DAT_00491188 != 3)) {
        iVar10 = iVar10 + -200;
      }
      if (DAT_004ac914 == 1) {
        iVar10 = iVar10 + -200;
      }
      iVar3 = *(int *)(&DAT_004a76d0 + iVar16 * 4);
      local_40 = (double)((float10)_DAT_004aa948 / (float10)iVar10);
      dVar1 = *local_30;
      *(double *)(&DAT_004a49e8 + iVar16 * 8) =
           (double)(((float10)_DAT_004aa948 / (float10)iVar10) * fVar21 +
                   (float10)*(double *)(&DAT_004a49e8 + iVar16 * 8));
      *local_30 = local_40 * local_20 + dVar1;
      if (0 < iVar3) {
        iVar10 = FUN_00413cb0(*(int *)(&DAT_004aa5b0 + iVar16 * 4) -
                              *(int *)(&DAT_004aa730 + iVar16 * 4) * DAT_004a4eb0);
        fVar20 = (float10)fsin((float10)((double)iVar10 * _DAT_00484d40));
        fVar21 = fVar20 * (float10)(*(int *)(&DAT_004a7060 + iVar16 * 4) * 100) +
                 (float10)(iVar18 + iVar9);
        fVar20 = (float10)fcos((float10)((double)iVar10 * _DAT_00484d40));
        local_20 = (double)((float10)iVar17 -
                           fVar20 * (float10)(*(int *)(&DAT_004a7060 + iVar16 * 4) * 100));
      }
      local_20 = local_20 * _DAT_004911a8;
      *(int *)(&DAT_004a9908 + iVar16 * 4) =
           (int)(longlong)
                ((float10)*(double *)(&DAT_004a49e8 + iVar16 * 8) -
                fVar21 * (float10)_DAT_004911a8 * (float10)_DAT_00485238);
      uVar22 = *(undefined4 *)(&DAT_004a49e8 + iVar16 * 8);
      uVar2 = *(undefined4 *)local_30;
      *(int *)(&DAT_004a9988 + iVar16 * 4) = (int)(longlong)(*local_30 - local_20 * _DAT_00485238);
      uVar4 = *(undefined4 *)(iVar16 * 8 + 0x4a49ec);
      *(undefined4 *)(&DAT_004a5318 + iVar16 * 8) = uVar22;
      uVar22 = *(undefined4 *)((int)local_30 + 4);
      *(undefined4 *)(iVar16 * 8 + 0x4a531c) = uVar4;
      iVar16 = iVar16 + -1;
      local_34 = local_34 + -1;
      local_30 = local_30 + -1;
      *local_2c = uVar2;
      local_2c[1] = uVar22;
      local_2c = local_2c + -2;
      pcVar15 = PlaySoundA_exref;
    } while (0 < iVar16);
  }
  iVar9 = 0;
  iVar16 = 0;
  do {
    iVar10 = FUN_00413cb0(*(int *)((int)&DAT_004ac0a4 + iVar9) + 0xb4);
    iVar17 = *(int *)((int)&DAT_004a4154 + iVar9);
    iVar18 = (&DAT_004a3450)[iVar10];
    iVar9 = iVar9 + 4;
    *(double *)((int)&DAT_004abd90 + iVar16) =
         (double)((&DAT_004a54a0)[iVar10] * iVar17 * 10) * local_40 +
         *(double *)((int)&DAT_004abd90 + iVar16);
    *(double *)((int)&DAT_004a4730 + iVar16) =
         (double)(iVar18 * iVar17 * -10) * local_40 + *(double *)((int)&DAT_004a4730 + iVar16);
    iVar16 = iVar16 + 8;
  } while (iVar9 < 0x11);
  if (DAT_004ac8dc != DAT_004ac9f8) {
    FUN_004313a0();
    DAT_004ab9d8 = DAT_004ab9d8 + 1;
    if (0x96 < DAT_004ab9d8) {
      DAT_004ab9d8 = 0x96;
    }
    DAT_004ac9f8 = DAT_004ac8dc;
  }
  puVar19 = &DAT_004a61e8;
  for (iVar16 = 0xb; iVar16 != 0; iVar16 = iVar16 + -1) {
    *puVar19 = 0;
    puVar19 = puVar19 + 1;
  }
  dVar1 = _DAT_004ac828;
  if (((DAT_004ac9c0 != 0) || (DAT_004a4e7c != 0)) || (DAT_004a4e80 != 0)) goto LAB_0042b7de;
  if (DAT_004a5b80 % 200 == 0) {
    (*pcVar15)(0x86,DAT_004ac1d4,0x40045);
  }
  if (((DAT_004a4dfc == 1) || (DAT_004a4e00 * (DAT_00491140 + -1) == 1)) || (0x32 < DAT_004a8aac)) {
    uVar22 = 0x88;
LAB_0042b7af:
    (*pcVar15)(uVar22,DAT_004ac1d4,0x40015);
  }
  else if ((0x14 < DAT_004a7064) || (0x14 < DAT_004a7068 * (DAT_00491140 + -1))) {
    if (DAT_004a7bcc < 0x5a) {
      uVar22 = 0x8b;
    }
    else {
      uVar22 = 0x8a;
    }
    goto LAB_0042b7af;
  }
  dVar1 = _DAT_004ac828;
  if (((0 < DAT_004a5b80) && (DAT_004a76c8 < 1)) && (DAT_004ac9c0 == 0)) {
    (*pcVar15)(0x8c,DAT_004ac1d4,0x40005);
    dVar1 = _DAT_004ac828;
  }
LAB_0042b7de:
  _DAT_004ac82c = (undefined4)((ulonglong)dVar1 >> 0x20);
  _DAT_004ac828 = SUB84(dVar1,0);
  return;
}

