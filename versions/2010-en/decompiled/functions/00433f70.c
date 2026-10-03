
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00433f70(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  longlong lVar2;
  longlong lVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  int local_190;
  double local_170;
  double local_168;
  double local_158 [4];
  double local_138;
  double local_130;
  double local_128;
  double local_120;
  double local_118;
  double dStack_110;
  double dStack_108;
  double dStack_100;
  double dStack_f8;
  double dStack_f0;
  double dStack_e8;
  double local_c8;
  double local_c0;
  double dStack_b8;
  double local_a8 [4];
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double dStack_60;
  double dStack_58;
  double dStack_50;
  double dStack_48;
  double dStack_40;
  double dStack_38;
  double local_18;
  double local_10;
  double dStack_8;
  
  bVar15 = param_4 == 0;
  if ((DAT_005363b8 == 1) && (0 < param_4)) {
    FUN_00433c60(param_1,param_2,param_3,param_4,param_5);
  }
  if ((DAT_0053652c == 1) && (0 < param_4)) {
    FUN_00433c60(param_1,param_2,param_3,param_4,param_5);
  }
  iVar14 = param_5 * 4;
  local_168 = (_DAT_004cc980 - _DAT_004cc978 / (double)*(int *)(&DAT_0050f6d0 + iVar14)) *
              _DAT_0050f6e0 * _DAT_004cc680;
  if (bVar15) {
    local_168 = local_168 * _DAT_004cc600;
    _DAT_004fdfe8 = 0;
    _DAT_00535740 = DAT_00522b94;
  }
  iVar10 = FUN_0041bc20(*(int *)(&DAT_00535740 + param_4 * 4) - *(int *)(&DAT_00535740 + iVar14));
  if (bVar15) {
    iVar10 = FUN_0041bc20((&DAT_00522b90)[param_5] - *(int *)(&DAT_00535740 + iVar14));
  }
  if ((&DAT_00525a78)[param_5] == 0) {
    iVar10 = FUN_0041bc20((iVar10 - *(int *)(&DAT_004fbb90 + iVar14)) +
                          *(int *)(&DAT_00535740 + iVar14));
  }
  if ((&DAT_00525a78)[param_5] == 2) {
    iVar10 = FUN_0041bc20((iVar10 - (&DAT_00522b90)[param_5]) + *(int *)(&DAT_00535740 + iVar14));
  }
  iVar11 = FUN_0041bc20(iVar10);
  local_190 = 1;
  dVar5 = (double)(int)(&DAT_004f85c8)[iVar11];
  iVar10 = (&DAT_004f1740)[iVar11];
  dVar4 = (double)iVar10;
  local_170 = (double)(int)(&DAT_004f85c8)[iVar11];
  dVar8 = (double)param_2 - local_168 * dVar5 * _DAT_004cc998;
  dVar7 = (double)param_3 - local_168 * dVar4 * _DAT_004cc9a0;
  iVar12 = 0;
  do {
    dVar6 = (double)local_190;
    iVar13 = iVar12 + 8;
    local_190 = local_190 + 1;
    *(double *)((int)local_a8 + iVar12) = dVar8 - dVar5 * dVar6 * local_168 * _DAT_004cc9a8;
    *(double *)((int)local_158 + iVar12) = dVar7 - dVar4 * dVar6 * local_168 * _DAT_004cc9b0;
    iVar12 = iVar13;
  } while (iVar13 < 0x11);
  dVar5 = local_168 * _DAT_004cc990 * (double)iVar10;
  dVar4 = local_168 * _DAT_004cc990 * local_170;
  local_a8[3] = local_a8[0] - dVar5 * _DAT_004cc818;
  local_158[3] = local_158[0] - dVar4 * _DAT_004cc818;
  local_88 = local_a8[1] - dVar5 * _DAT_004cc3f0;
  local_138 = local_158[1] - dVar4 * _DAT_004cc3f0;
  local_80 = local_a8[2] - dVar5 * _DAT_004cc9b8;
  local_130 = local_158[2] - dVar4 * _DAT_004cc9b8;
  local_68 = (local_a8[0] + local_a8[0]) - local_a8[3];
  local_118 = (local_158[0] + local_158[0]) - local_158[3];
  local_70 = (local_a8[1] + local_a8[1]) - local_88;
  local_120 = (local_158[1] + local_158[1]) - local_138;
  local_78 = (local_a8[2] + local_a8[2]) - local_80;
  local_128 = (local_158[2] + local_158[2]) - local_130;
  iVar10 = FUN_0041e000(0x32);
  dVar5 = dVar5 / (double)(iVar10 + 0x50);
  dVar4 = dVar4 / (double)(iVar10 + 0x50);
  local_18 = local_a8[0] - dVar5;
  local_10 = local_a8[0] + dVar5;
  local_c8 = local_158[0] - dVar4;
  local_c0 = local_158[0] + dVar4;
  if (((DAT_005363b8 == 0) && (0x23 < *(int *)(&DAT_004fdfe8 + param_4 * 4))) && (!bVar15)) {
    (**(code **)(*param_1 + 0x2c))(param_1,6);
    if ((*(int *)(&DAT_0050f6d0 + iVar14) < 10) && (DAT_004f7ec4 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004f7ec4);
    }
    FUN_004b4d9d(param_1,(int *)&local_170,(int)(longlong)local_18,(int)(longlong)local_c8);
    CDC::LineTo(param_1,(int)(longlong)dVar8,(int)(longlong)dVar7);
    CDC::LineTo(param_1,(int)(longlong)local_10,(int)(longlong)local_c0);
  }
  pcVar1 = *(code **)(*param_1 + 0x2c);
  (*pcVar1)(param_1,7);
  FUN_0041ed90(param_1,param_4);
  if (((DAT_005363b8 == 0) || (param_4 == 0)) && (DAT_0053652c == 0)) {
    _DAT_004f6e28 = (undefined4)(longlong)dVar8;
    _DAT_004f6e2c = (undefined4)(longlong)dVar7;
    _DAT_004f6e30 = (int)(longlong)local_a8[3];
    _DAT_004f6e34 = (int)(longlong)local_158[3];
    _DAT_004f6e38 = (undefined4)(longlong)local_88;
    _DAT_004f6e3c = (undefined4)(longlong)local_138;
    _DAT_004f6e40 = (undefined4)(longlong)local_80;
    _DAT_004f6e44 = (undefined4)(longlong)local_130;
    _DAT_004f6e48 = (undefined4)(longlong)local_78;
    _DAT_004f6e4c = (undefined4)(longlong)local_128;
    _DAT_004f6e50 = (undefined4)(longlong)local_70;
    _DAT_004f6e54 = (undefined4)(longlong)local_120;
    _DAT_004f6e58 = (undefined4)(longlong)local_68;
    _DAT_004f6e5c = (undefined4)(longlong)local_118;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,7);
  }
  (*pcVar1)(param_1,7);
  if (!bVar15) {
    iVar14 = *(int *)(&DAT_00522ff0 + param_4 * 4);
    local_170 = (double)(int)(&DAT_004f1740)[iVar11] * local_168 * _DAT_004cc850 * _DAT_004cc3f0;
    dVar4 = (double)(int)(&DAT_004f85c8)[iVar11] * local_168 * _DAT_004cc850 * _DAT_004cc3f0;
    iVar10 = FUN_0041e000(3);
    iVar10 = FUN_0041bc20(iVar10 + 6 + *(int *)(&DAT_004fc2c0 + param_4 * 4) / 2);
    dVar5 = (double)(int)(&DAT_004f85c8)[iVar10] * _DAT_004cc7b0 * (double)iVar14;
    dVar9 = local_168 * _DAT_004cc668;
    dVar6 = local_170 * dVar5;
    dVar4 = dVar4 * dVar5;
    dStack_60 = local_a8[0] - dVar6 * _DAT_004cc3f0;
    dStack_110 = local_158[0] - dVar4 * _DAT_004cc3f0;
    dStack_50 = local_a8[0] - dVar6 * _DAT_004cc570;
    dStack_100 = local_158[0] - dVar4 * _DAT_004cc570;
    iVar10 = FUN_0041bc20(((*(int *)(&DAT_004fe818 + param_4 * 4) << 1) / 3 + 10) *
                          *(int *)(&DAT_00522ff0 + param_4 * 4) + iVar11);
    iVar14 = (*(int *)(&DAT_004fe818 + param_4 * 4) << 1) / 3;
    local_170 = (double)(int)(&DAT_004f85c8)[iVar10];
    dVar4 = (double)(int)(&DAT_004f85c8)[iVar10] * dVar9;
    dVar9 = (double)(int)(&DAT_004f1740)[iVar10] * dVar9;
    dStack_58 = dStack_60 - dVar4 * _DAT_004cc3f0;
    dStack_108 = dStack_110 - dVar9 * _DAT_004cc678;
    dVar5 = local_168 * _DAT_004cc770;
    dStack_8 = (dStack_60 + dStack_50) * _DAT_004cc4f8 - dVar4 * _DAT_004cc9c0;
    dStack_b8 = (dStack_110 + dStack_100) * _DAT_004cc4f8 - dVar9 * _DAT_004cc9c8;
    if (0x3c < iVar14) {
      iVar14 = 0x3c;
    }
    if (*(int *)(&DAT_00522ff0 + param_4 * 4) == -1) {
      iVar14 = -iVar14;
    }
    iVar14 = FUN_0041bc20(iVar14 + iVar11);
    dStack_40 = dVar8 - (double)(int)(&DAT_004f85c8)[iVar14] * dVar5 * _DAT_004cc3f0;
    dStack_f0 = dVar7 - (double)(int)(&DAT_004f1740)[iVar14] * dVar5 * _DAT_004cc678;
    if (DAT_004da150 == 100) {
      dStack_48 = dStack_50;
      dStack_f8 = dStack_100;
    }
    else {
      dStack_48 = (local_a8[0] - dStack_50 * _DAT_004cc5c0) * _DAT_004cc5f0;
      dStack_f8 = (local_158[0] - dStack_100 * _DAT_004cc5c0) * _DAT_004cc5f0;
    }
    if (0 < *(int *)(&DAT_005350d8 + param_4 * 4)) {
      iVar14 = *(int *)(&DAT_004fe818 + param_4 * 4) + -0xa0;
      if (*(int *)(&DAT_00522ff0 + param_4 * 4) == -1) {
        iVar14 = -iVar14;
      }
      iVar14 = FUN_0041bc20(iVar14 + iVar11);
      dStack_38 = dVar8 - (double)(int)(&DAT_004f85c8)[iVar14] * dVar5 * _DAT_004cc3f0;
      dStack_e8 = dVar7 - (double)(int)(&DAT_004f1740)[iVar14] * dVar5 * _DAT_004cc678;
    }
    if (((*(int *)(&DAT_005350d8 + param_4 * 4) < 1) && (1 < DAT_004da190)) && (DAT_005364cc == 0))
    {
      (*pcVar1)(param_1,0);
      if (((DAT_005363e4 == 0) && (DAT_004da190 == 7)) && (DAT_00525a94 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_00525a94);
      }
      _DAT_004f6e28 = (undefined4)(longlong)dVar8;
      _DAT_004f6e2c = (undefined4)(longlong)dVar7;
      _DAT_004f6e30 = (int)(longlong)dStack_40;
      _DAT_004f6e34 = (int)(longlong)dStack_f0;
      _DAT_004f6e38 = (undefined4)(longlong)dStack_48;
      _DAT_004f6e3c = (undefined4)(longlong)dStack_f8;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,3);
    }
    if (((*(int *)(&DAT_005350d8 + param_4 * 4) == 1) && (1 < DAT_004da190)) && (DAT_004da190 != 9))
    {
      if (((DAT_005363e4 == 0) && (2 < DAT_004da190)) && (DAT_004da190 < 8)) {
        (*pcVar1)(param_1,8);
        FUN_00426890(param_1,param_4);
      }
      else {
        (*pcVar1)(param_1,0);
        if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004f7ec4);
        }
      }
      if ((DAT_005363e4 == 0) && (DAT_004da190 == 10)) {
        (*pcVar1)(param_1,8);
        FUN_00426890(param_1,param_4);
      }
      lVar2 = (longlong)dStack_48;
      lVar3 = (longlong)dStack_f8;
      _DAT_004f6e38 = (undefined4)(longlong)dStack_38;
      _DAT_004f6e3c = (undefined4)(longlong)dStack_e8;
      _DAT_004f6e28 = (int)lVar2;
      _DAT_004f6e2c = (int)lVar3;
      _DAT_004f6e30 = (int)(longlong)dVar8;
      _DAT_004f6e34 = (int)(longlong)dVar7;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,3);
      if ((2 < DAT_004da190) && (DAT_004da190 != 9)) {
        _DAT_004f6e38 = (undefined4)(longlong)dStack_40;
        _DAT_004f6e3c = (undefined4)(longlong)dStack_f0;
        _DAT_004f6e28 = (int)lVar2;
        _DAT_004f6e2c = (int)lVar3;
        _DAT_004f6e30 = (int)(longlong)dVar8;
        _DAT_004f6e34 = (int)(longlong)dVar7;
        Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,3);
      }
    }
    (*pcVar1)(param_1,7);
    (*pcVar1)(param_1,0);
    if ((DAT_00536480 == 1) && (FUN_0041ed90(param_1,param_4), param_4 == 1)) {
      (*pcVar1)(param_1,0);
    }
    if ((DAT_004f8cd0 < *(int *)(&DAT_00535620 + param_4 * 4) + DAT_004fe62c) &&
       (*(int *)(&DAT_005116e0 + param_4 * 4) < 0xb)) {
      (*pcVar1)(param_1,4);
    }
    _DAT_004f6e28 = (undefined4)(longlong)dStack_60;
    _DAT_004f6e2c = (undefined4)(longlong)dStack_110;
    lVar2 = (longlong)dStack_50;
    lVar3 = (longlong)dStack_100;
    _DAT_004f6e38 = (undefined4)(longlong)dStack_8;
    _DAT_004f6e3c = (undefined4)(longlong)dStack_b8;
    _DAT_004f6e40 = (undefined4)(longlong)dStack_58;
    _DAT_004f6e44 = (undefined4)(longlong)dStack_108;
    _DAT_004f6e30 = (int)lVar2;
    _DAT_004f6e34 = (int)lVar3;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    FUN_004b4d9d(param_1,(int *)&local_170,(int)(longlong)local_a8[0],(int)(longlong)local_158[0]);
    CDC::LineTo(param_1,(int)lVar2,(int)lVar3);
  }
  return;
}

