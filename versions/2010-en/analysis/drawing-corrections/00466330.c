
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00466330(int *param_1,double param_2,double param_3,int param_4,int param_5)

{
  double dVar1;
  double dVar2;
  double dVar3;
  float10 fVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  longlong lVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  float10 fVar25;
  float10 fVar26;
  float10 fVar27;
  HDC hdc;
  HGDIOBJ h;
  undefined4 uVar28;
  double local_270;
  double local_268;
  double local_260;
  int local_258;
  int local_23c;
  int local_1e4 [4];
  int iStack_1d4;
  undefined4 local_1c8;
  int local_1c4;
  int local_1c0;
  int local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  int local_1ac;
  int local_1a8;
  int local_1a4;
  undefined4 local_1a0;
  int local_194 [4];
  int iStack_184;
  undefined4 local_178;
  int local_174;
  int local_170;
  int local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  int local_15c;
  int local_158;
  int local_154;
  undefined4 local_150;
  double local_148;
  undefined8 local_138;
  double local_130;
  double local_128;
  double local_120;
  double local_118;
  double local_110;
  double local_108;
  double local_100;
  double local_f8;
  double local_f0;
  double local_e8;
  double local_e0;
  double local_d8;
  double local_d0;
  double local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  undefined8 local_98;
  double local_90;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  if (DAT_004da140 == 1) {
    local_23c = 1;
  }
  uVar23 = param_4 >> 0x1f;
  if (DAT_004da140 == 2) {
    local_23c = (((param_4 ^ uVar23) - uVar23 & 1 ^ uVar23) != uVar23) + 1;
    if ((local_23c == 1) &&
       (iVar16 = ((param_4 ^ uVar23) - uVar23 & 1 ^ uVar23) - uVar23, iVar16 != 0)) {
      return iVar16;
    }
    if ((local_23c == 2) && (((param_4 ^ uVar23) - uVar23 & 1 ^ uVar23) == uVar23)) {
      return 0;
    }
  }
  if ((param_4 < DAT_004da1f4 / 3) ||
     (DAT_004f8b70 = 0, *(int *)(&DAT_00535e40 + local_23c * 4) < 2)) {
    DAT_004f8b70 = 1;
  }
  dVar5 = (double)*(int *)(&DAT_00512d90 + param_4 * 4) * _DAT_004cccd0 - _DAT_004cc5d8;
  dVar6 = (double)*(int *)(&DAT_00512da0 + param_4 * 4) * _DAT_004cccd0 - _DAT_004cc5d8;
  dVar7 = (double)*(int *)(&DAT_00512da8 + param_4 * 4) * _DAT_004cccd0 - _DAT_004cc5d8;
  dVar8 = (double)*(int *)(&DAT_00512db8 + param_4 * 4) * _DAT_004cccd0 - _DAT_004cc5d8;
  dVar9 = (double)*(int *)(&DAT_00512d94 + param_4 * 4) * _DAT_004cccd0 - _DAT_004cccd8;
  dVar10 = (double)(int)(&DAT_00512d9c)[param_4] * _DAT_004cccd0 - _DAT_004cccd8;
  dVar11 = (double)*(int *)(&DAT_00512dac + param_4 * 4) * _DAT_004cccd0 - _DAT_004cccd8;
  dVar12 = (double)*(int *)(&DAT_00512db4 + param_4 * 4) * _DAT_004cccd0 - _DAT_004cccd8;
  dVar13 = (double)*(int *)(&DAT_00512d98 + param_4 * 4) * _DAT_004cccd0 - _DAT_004cccd8;
  dVar14 = (double)*(int *)(&DAT_00512db0 + param_4 * 4) * _DAT_004cccd0 - _DAT_004cccd8;
  lVar15 = 0x3ff00000;
  if (0x31 < (int)(&DAT_00512d70)[param_4]) {
    lVar15 = 0x3ff80000;
  }
  local_260 = (double)(lVar15 << 0x20);
  if (*(int *)(&DAT_00535e40 + local_23c * 4) < 5) {
    local_270 = _DAT_004cc980 - (double)DAT_00535e44 * _DAT_004cc5c0;
  }
  else {
    local_270 = 22.0;
  }
  if (*(int *)(&DAT_004f71c0 + local_23c * 4) == 1) {
    local_270 = local_270 - _DAT_004cc700;
  }
  if (2 < *(int *)(&DAT_004f71c0 + local_23c * 4)) {
    local_270 = local_270 - _DAT_004cc650;
  }
  if (((param_4 ^ uVar23) - uVar23 & 1 ^ uVar23) == uVar23) {
    local_268 = 0.25;
  }
  else {
    local_268 = 0.2;
  }
  uVar23 = (int)*(uint *)(&DAT_00511368 + local_23c * 4) >> 0x1f;
  iVar16 = (*(uint *)(&DAT_00511368 + local_23c * 4) ^ uVar23) - uVar23;
  if ((0x3c < iVar16) && (iVar16 < 0x78)) {
    local_268 = local_268 * _DAT_004cc600;
  }
  iVar16 = FUN_0041bc20(DAT_005362d4 + -0x5a);
  FUN_00465e90((int)(longlong)param_2,(int)(longlong)param_3,0,local_23c);
  if (0x15e < DAT_00523184) {
    iVar16 = FUN_00465ff0(param_4);
    return iVar16;
  }
  if (0x32 < DAT_00523184) {
    if (0x5a < DAT_00535ff4) {
      return DAT_00535ff4;
    }
    if (DAT_00535ff4 < -0x5a) {
      return DAT_00535ff4;
    }
  }
  if (0x78 < DAT_00535ff4) {
    return DAT_00535ff4;
  }
  if (DAT_00535ff4 < -0x78) {
    return DAT_00535ff4;
  }
  DAT_005365a0 = DAT_005365a0 + 1;
  if (DAT_004da178 * 0x136 < DAT_005365a0) {
    DAT_005365a0 = 0;
  }
  fVar25 = (float10)fsin((float10)DAT_005365a0 / (float10)(DAT_004da178 * 0x30) +
                         (float10)(int)(&DAT_00512d70)[param_4] * (float10)_DAT_004cc660);
  local_148 = (double)fVar25;
  dVar1 = (double)(fVar25 * (float10)(local_270 * _DAT_004cc518) -
                  (float10)local_270 * (float10)_DAT_004ccce8);
  if (DAT_004f8b70 == 1) {
    local_260 = local_260 * _DAT_004cc538;
  }
  fVar4 = (float10)_DAT_004cc5e8;
  fVar26 = (float10)fsin((float10)iVar16 * (float10)_DAT_004cc568);
  fVar27 = (float10)fcos((float10)(double)((float10)iVar16 * (float10)_DAT_004cc568));
  dVar2 = (double)fVar26;
  dVar3 = (double)fVar27;
  local_68 = (double)(fVar26 * (float10)local_260 * (float10)dVar1);
  local_98 = param_2 + local_68;
  local_68 = param_2 - local_68;
  local_108 = (double)(fVar27 * (float10)local_260 * (float10)dVar1);
  local_138 = param_3 - local_108;
  local_108 = param_3 + local_108;
  local_90 = (param_2 - local_98 * _DAT_004cc5c8) * _DAT_004cc7b0;
  local_130 = (param_3 - local_138 * _DAT_004cc5c8) * _DAT_004cc7b0;
  local_88 = (local_98 - param_2 * _DAT_004cc5c8) * _DAT_004cc7b0;
  local_128 = (local_138 - param_3 * _DAT_004cc5c8) * _DAT_004cc7b0;
  local_78 = (local_68 - param_2 * _DAT_004cc5c8) * _DAT_004cc7b0;
  local_118 = (local_108 - param_3 * _DAT_004cc5c8) * _DAT_004cc7b0;
  local_70 = (param_2 - local_68 * _DAT_004cc5c8) * _DAT_004cc7b0;
  local_268 = local_268 - (local_148 - _DAT_004cc700) * _DAT_004cc618;
  local_80 = param_2;
  local_120 = param_3;
  local_50 = param_2 - dVar3 * dVar13 * local_260 * local_268 * dVar1;
  local_f0 = param_3 - dVar2 * dVar13 * local_260 * local_268 * dVar1;
  local_58 = local_88 - dVar3 * dVar9 * local_260 * local_268 * dVar1;
  local_f8 = local_128 - dVar2 * dVar9 * local_260 * local_268 * dVar1;
  local_60 = local_90 - dVar3 * dVar5 * local_260 * local_268 * dVar1;
  local_100 = local_130 - dVar2 * dVar5 * local_260 * local_268 * dVar1;
  iVar16 = 0;
  iVar24 = 0;
  local_48 = local_78 - dVar3 * dVar10 * local_260 * local_268 * dVar1;
  local_110 = (param_3 - local_108 * _DAT_004cc5c8) * _DAT_004cc7b0;
  local_38 = local_68;
  local_d8 = local_108;
  local_e8 = local_118 - dVar2 * dVar10 * local_260 * local_268 * dVar1;
  local_40 = local_70 - dVar3 * dVar6 * local_260 * local_268 * dVar1;
  local_e0 = local_110 - dVar2 * dVar6 * local_260 * local_268 * dVar1;
  local_20 = dVar3 * dVar14 * local_260 * local_268 * dVar1 + param_2;
  local_c0 = dVar2 * dVar14 * local_260 * local_268 * dVar1 + param_3;
  local_28 = dVar3 * dVar11 * local_260 * local_268 * dVar1 + local_78;
  local_c8 = dVar2 * dVar11 * local_260 * local_268 * dVar1 + local_118;
  local_30 = dVar3 * dVar7 * local_260 * local_268 * dVar1 + local_70;
  local_d0 = dVar2 * dVar7 * local_260 * local_268 * dVar1 + local_110;
  local_18 = dVar3 * dVar12 * local_260 * local_268 * dVar1 + local_88;
  local_b8 = dVar2 * dVar12 * local_260 * local_268 * dVar1 + local_128;
  local_10 = dVar3 * dVar8 * local_260 * local_268 * dVar1 + local_90;
  local_b0 = dVar2 * dVar8 * local_260 * local_268 * dVar1 + local_130;
  do {
    FUN_0043e730(0,(double)CONCAT44(*(undefined4 *)((int)&local_98 + iVar16 + 4),
                                    *(undefined4 *)((int)&local_98 + iVar16)),
                 (double)CONCAT44(*(undefined4 *)((int)&local_138 + iVar16 + 4),
                                  *(undefined4 *)((int)&local_138 + iVar16)),local_23c,0);
    *(undefined4 *)((int)local_194 + iVar24) = DAT_004fed58;
    *(undefined4 *)((int)local_1e4 + iVar24) = DAT_00523660;
    iVar16 = iVar16 + 8;
    iVar24 = iVar24 + 4;
  } while (iVar16 < 0x89);
  if ((DAT_004fe624 * 4) / 3 < local_194[3]) {
    return -(DAT_004fe624 * 4 >> 0x1f);
  }
  iVar24 = (int)((ulonglong)((longlong)DAT_004fe624 * 0x55555555) >> 0x20) - DAT_004fe624;
  iVar16 = -(iVar24 >> 0x1f);
  if (local_194[3] < (iVar24 >> 1) + iVar16) {
    return iVar16;
  }
  if (DAT_004da140 == 2) {
    if ((param_5 == 2) && ((DAT_004fe624 * 2) / 3 < local_194[3])) {
      return -(DAT_004fe624 * 2 >> 0x1f);
    }
    if ((param_5 == 1) && (local_194[3] < DAT_004fe624 / 3)) {
      return DAT_004fe624 * 0x55555556;
    }
  }
  _DAT_004f6e30 = local_178;
  _DAT_004f6e34 = local_1c8;
  _DAT_004f6e38 = local_174;
  _DAT_004f6e3c = local_1c4;
  _DAT_004f6e40 = local_170;
  _DAT_004f6e44 = local_1c0;
  _DAT_004f6e48 = local_16c;
  _DAT_004f6e4c = local_1bc;
  _DAT_004f6e50 = local_168;
  _DAT_004f6e54 = local_1b8;
  _DAT_004f6e58 = local_164;
  _DAT_004f6e5c = local_1b4;
  _DAT_004f6e60 = local_160;
  _DAT_004f6e64 = local_1b0;
  _DAT_004f6e6c = local_1ac;
  _DAT_004f6e74 = local_1a8;
  _DAT_004f6e78 = local_154;
  _DAT_004f6e7c = local_1a4;
  _DAT_004f6e28 = local_194[0];
  _DAT_004f6e88 = local_194[0];
  _DAT_004f6e90 = local_194[0];
  _DAT_004f6e80 = local_150;
  _DAT_004f6e2c = local_1e4[0];
  _DAT_004f6e68 = local_15c;
  _DAT_004f6e70 = local_158;
  _DAT_004f6e84 = local_1a0;
  _DAT_004f6e8c = local_1e4[0];
  _DAT_004f6e94 = local_1e4[0];
  if (DAT_004f8b70 == 0) {
    if (DAT_005363e4 == 0) {
      if (((DAT_004da1f8 == 0x6a) || (DAT_004da1f8 == 0x69)) ||
         ((DAT_004da1f8 == 999 && (DAT_00536524 == 1)))) {
        if (DAT_005354a4 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_005354a4);
        }
        if (DAT_004fb9a4 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fb9a4);
        }
      }
      else {
        if (DAT_00523194 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_00523194);
        }
        if (DAT_004fe14c != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fe14c);
        }
        if ((200 < DAT_00523184) && (DAT_004faf9c != (HGDIOBJ)0x0)) {
          SelectObject((HDC)param_1[1],DAT_004faf9c);
        }
      }
    }
    else {
      if (DAT_005230cc != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005230cc);
      }
      (**(code **)(*param_1 + 0x2c))(param_1,8);
    }
  }
  if (DAT_004f8b70 == 1) {
    (**(code **)(*param_1 + 0x2c))(param_1,8);
    if (DAT_005363e4 == 0) {
      if (((DAT_004da1f8 == 0x69) || (DAT_004da1f8 == 0x6a)) ||
         ((DAT_004da1f8 == 999 && (DAT_00536524 == 1)))) {
        if (DAT_004f71d4 == (HGDIOBJ)0x0) goto LAB_004670ac;
        hdc = (HDC)param_1[1];
        h = DAT_004f71d4;
      }
      else {
        if (DAT_004f71b4 == (HGDIOBJ)0x0) goto LAB_004670ac;
        hdc = (HDC)param_1[1];
        h = DAT_004f71b4;
      }
    }
    else {
      if (DAT_004fe07c == (HGDIOBJ)0x0) goto LAB_004670ac;
      hdc = (HDC)param_1[1];
      h = DAT_004fe07c;
    }
    SelectObject(hdc,h);
  }
LAB_004670ac:
  if ((DAT_00536450 == 1) &&
     ((**(code **)(*param_1 + 0x2c))(param_1,4), DAT_004f4154 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004f4154);
  }
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,0xd);
  iVar16 = DAT_004f8b70;
  if (((((DAT_004f8b70 != 1) && (1 < *(int *)(&DAT_00535e40 + local_23c * 4))) &&
       (iVar16 = (&DAT_00512d70)[param_4], 0x13 < iVar16)) &&
      ((*(int *)(&DAT_00535e40 + local_23c * 4) != 2 || (0x3b < iVar16)))) && (fVar4 <= fVar25)) {
    local_270._0_4_ = 1;
    if (iVar16 < 0x32) {
      iVar16 = 2;
      local_260._0_4_ = 2;
      iVar24 = 2;
    }
    else {
      iVar16 = 1;
      iVar24 = 3;
      local_260._0_4_ = 1;
    }
    uVar23 = (int)*(uint *)(&DAT_00511368 + local_23c * 4) >> 0x1f;
    if ((int)((*(uint *)(&DAT_00511368 + local_23c * 4) ^ uVar23) - uVar23) < 0x3c) {
      iVar17 = iVar16 * local_15c + iVar24 * local_158;
      local_270._0_4_ = 3;
      iVar16 = iVar24 * local_1a8 + iVar16 * local_1ac;
      iVar18 = (local_154 + local_158) * 2;
      iVar19 = (local_1a4 + local_1a8) * 2;
      iVar17 = (int)(iVar17 + (iVar17 >> 0x1f & 3U)) >> 2;
      iVar16 = (int)(iVar16 + (iVar16 >> 0x1f & 3U)) >> 2;
      if (DAT_004faa54 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004faa54);
      }
      if ((DAT_00536450 == 1) && (DAT_00522d14 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_00522d14);
      }
      local_258 = ((iVar16 <= DAT_004fe2a8 / 5) - 1 & 0xffffffec) + 0x23;
      if (0 < local_258) {
        do {
          iVar20 = FUN_0041e000(100);
          if (DAT_004fe2a8 / 5 < iVar16) {
            uVar28 = 1;
            iVar21 = FUN_0041e000(3);
          }
          else {
            uVar28 = 0;
            iVar21 = FUN_0041e000(3);
          }
          FUN_00424320(param_1,(iVar20 * (((int)(iVar18 + (iVar18 >> 0x1f & 3U)) >> 2) - iVar17)) /
                               100 + iVar17,
                       iVar21 + (iVar20 * (((int)(iVar19 + (iVar19 >> 0x1f & 3U)) >> 2) - iVar16)) /
                                100 + iVar16,uVar28);
          local_258 = local_258 + -1;
        } while (local_258 != 0);
      }
    }
    uVar23 = (int)*(uint *)(&DAT_00511368 + local_23c * 4) >> 0x1f;
    iVar16 = (*(uint *)(&DAT_00511368 + local_23c * 4) ^ uVar23) - uVar23;
    if ((0x3b < iVar16) && (iVar16 < 0x79)) {
      iVar16 = local_260._0_4_ * local_194[2] + iVar24 * local_194[3];
      iVar17 = local_260._0_4_ * local_1e4[2] + iVar24 * local_1e4[3];
      iVar19 = ((int)(iVar16 + (iVar16 >> 0x1f & 3U)) >> 2) + local_270._0_4_;
      iVar16 = local_260._0_4_ * iStack_184 + iVar24 * local_194[3];
      iVar18 = local_260._0_4_ * iStack_1d4 + iVar24 * local_1e4[3];
      iVar17 = (int)(iVar17 + (iVar17 >> 0x1f & 3U)) >> 2;
      if (DAT_004faa54 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004faa54);
      }
      if ((DAT_00536450 == 1) && (DAT_00522d14 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_00522d14);
      }
      local_258 = ((iVar17 <= DAT_004fe2a8 / 5) - 1 & 0xffffffec) + 0x23;
      if (0 < local_258) {
        do {
          iVar20 = FUN_0041e000(100);
          iVar21 = (iVar20 * (((int)(iVar18 + (iVar18 >> 0x1f & 3U)) >> 2) - iVar17)) / 100 + iVar17
          ;
          if (DAT_004fe2a8 / 5 < iVar17) {
            uVar28 = 1;
            iVar22 = FUN_0041e000(5);
            iVar22 = iVar22 + iVar21;
            iVar21 = FUN_0041e000(5);
          }
          else {
            uVar28 = 0;
            iVar22 = FUN_0041e000(3);
            iVar22 = iVar22 + iVar21;
            iVar21 = FUN_0041e000(3);
          }
          FUN_00424320(param_1,((iVar20 * ((((int)(iVar16 + (iVar16 >> 0x1f & 3U)) >> 2) +
                                           local_270._0_4_) - iVar19)) / 100 + iVar19) - iVar21,
                       iVar22,uVar28);
          local_258 = local_258 + -1;
        } while (local_258 != 0);
      }
    }
    uVar23 = (int)*(uint *)(&DAT_00511368 + local_23c * 4) >> 0x1f;
    iVar16 = (*(uint *)(&DAT_00511368 + local_23c * 4) ^ uVar23) - uVar23;
    if (0x78 < iVar16) {
      iVar16 = local_260._0_4_ * local_174 + iVar24 * local_170;
      iVar17 = local_260._0_4_ * local_1c4 + iVar24 * local_1c0;
      iVar18 = local_260._0_4_ * local_16c + iVar24 * local_170;
      iVar24 = local_260._0_4_ * local_1bc + iVar24 * local_1c0;
      iVar19 = (int)(iVar16 + (iVar16 >> 0x1f & 3U)) >> 2;
      iVar17 = (int)(iVar17 + (iVar17 >> 0x1f & 3U)) >> 2;
      if (DAT_004faa54 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004faa54);
      }
      if ((DAT_00536450 == 1) && (DAT_00522d14 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_00522d14);
      }
      iVar16 = ((iVar17 <= DAT_004fe2a8 / 5) - 1 & 0xffffffec) + 0x23;
      if (0 < iVar16) {
        local_258 = iVar16;
        do {
          iVar16 = FUN_0041e000(100);
          if (DAT_004fe2a8 / 5 < iVar17) {
            uVar28 = 1;
            iVar20 = FUN_0041e000(5);
          }
          else {
            uVar28 = 0;
            iVar20 = FUN_0041e000(3);
          }
          FUN_00424320(param_1,(iVar16 * (((int)(iVar18 + (iVar18 >> 0x1f & 3U)) >> 2) - iVar19)) /
                               100 + iVar19,
                       iVar20 + (iVar16 * (((int)(iVar24 + (iVar24 >> 0x1f & 3U)) >> 2) - iVar17)) /
                                100 + iVar17,uVar28);
          local_258 = local_258 + -1;
          iVar16 = 0;
        } while (local_258 != 0);
      }
    }
  }
  return iVar16;
}

