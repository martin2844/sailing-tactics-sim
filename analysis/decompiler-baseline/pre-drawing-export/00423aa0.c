
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00423aa0(CDC *param_1,int param_2,int param_3,uint param_4,int param_5)

{
  code *pcVar1;
  longlong lVar2;
  longlong lVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  code *local_1b8;
  int local_1b0;
  undefined4 uStack_1a4;
  undefined4 local_1a0;
  undefined4 uStack_19c;
  undefined4 local_198;
  int iStack_194;
  undefined1 local_190 [8];
  uint local_188;
  undefined8 local_184;
  int local_17c;
  double local_178;
  double local_170;
  double local_168;
  double dStack_160;
  double local_158 [2];
  undefined4 local_148;
  undefined4 uStack_144;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  double local_118;
  double dStack_110;
  double dStack_108;
  double dStack_100;
  double dStack_f8;
  double dStack_f0;
  double local_c8;
  double local_c0;
  double dStack_b8;
  double dStack_b0;
  double local_a8 [2];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  double local_68;
  double dStack_60;
  double dStack_58;
  double dStack_50;
  double dStack_48;
  double dStack_40;
  double local_18;
  double local_10;
  
  uVar9 = (uint)(param_4 == 0);
  local_188 = uVar9;
  if ((DAT_004ac900 == 1) && (0 < (int)param_4)) {
    FUN_00423830(param_1,param_2,param_3,param_4,param_5);
  }
  iVar11 = param_5 * 4;
  local_178 = (_DAT_00484cf0 - _DAT_00485100 / (double)*(int *)(&DAT_004a8660 + iVar11)) *
              _DAT_004a8670 * _DAT_00484e30;
  if (uVar9 == 1) {
    local_178 = local_178 * _DAT_00484dc0;
    _DAT_004a7060 = 0;
    _DAT_004ac018 = DAT_004aa5b4;
  }
  local_17c = iVar11;
  iVar10 = FUN_00413cb0(*(int *)(&DAT_004ac018 + param_4 * 4) - *(int *)(&DAT_004ac018 + iVar11));
  if (uVar9 == 1) {
    iVar10 = FUN_00413cb0(*(int *)(&DAT_004aa5b0 + iVar11) - *(int *)(&DAT_004ac018 + iVar11));
  }
  if ((&DAT_004ab160)[param_5] == 0) {
    iVar10 = FUN_00413cb0((iVar10 - *(int *)(&DAT_004a6830 + iVar11)) +
                          *(int *)(&DAT_004ac018 + iVar11));
  }
  if ((&DAT_004ab160)[param_5] == 2) {
    iVar10 = FUN_00413cb0((iVar10 - *(int *)(&DAT_004aa5b0 + iVar11)) +
                          *(int *)(&DAT_004ac018 + iVar11));
  }
  iVar11 = FUN_00413cb0(iVar10);
  dVar7 = (double)(int)(&DAT_004a54a0)[iVar11];
  dVar4 = (double)(int)(&DAT_004a3450)[iVar11];
  local_184 = (double)(int)(&DAT_004a54a0)[iVar11];
  local_168 = (double)(int)(&DAT_004a3450)[iVar11];
  local_170 = (double)param_3;
  dVar5 = _DAT_00485120;
  dVar6 = _DAT_00485118;
  if ((DAT_004ac900 == 1) && (0 < (int)param_4)) {
    dVar5 = _DAT_00485130;
    dVar6 = _DAT_00485128;
  }
  dVar6 = (double)param_2 - local_178 * dVar7 * dVar6;
  dVar5 = local_170 - local_178 * dVar4 * dVar5;
  local_1b0 = 1;
  iVar10 = 0;
  do {
    iStack_194 = (int)((ulonglong)dVar6 >> 0x20);
    local_198 = SUB84(dVar6,0);
    uStack_19c = (undefined4)((ulonglong)dVar5 >> 0x20);
    local_1a0 = SUB84(dVar5,0);
    dVar8 = (double)local_1b0;
    iVar12 = iVar10 + 8;
    local_1b0 = local_1b0 + 1;
    *(double *)((int)local_a8 + iVar10) = dVar6 - dVar7 * dVar8 * local_178 * _DAT_00485138;
    *(double *)((int)local_158 + iVar10) = dVar5 - dVar4 * dVar8 * local_178 * _DAT_00485140;
    iVar10 = iVar12;
  } while (iVar12 < 0x11);
  local_190 = (undefined1  [8])(local_178 * _DAT_00485110 * local_168);
  dVar7 = local_178 * _DAT_00485110 * local_184;
  uStack_1a4 = (undefined4)((ulonglong)dVar7 >> 0x20);
  local_90 = local_a8[0] - (double)local_190 * _DAT_00484fb8;
  local_140 = local_158[0] - dVar7 * _DAT_00484fb8;
  local_88 = local_a8[1] - (double)local_190 * _DAT_00484cc8;
  local_138 = local_158[1] - dVar7 * _DAT_00484cc8;
  local_80 = (double)CONCAT44(uStack_94,local_98) - (double)local_190 * _DAT_00485148;
  local_130 = (double)CONCAT44(uStack_144,local_148) - dVar7 * _DAT_00485148;
  local_68 = (local_a8[0] + local_a8[0]) - local_90;
  local_118 = (local_158[0] + local_158[0]) - local_140;
  local_70 = (local_a8[1] + local_a8[1]) - local_88;
  local_120 = (local_158[1] + local_158[1]) - local_138;
  local_78 = ((double)CONCAT44(uStack_94,local_98) + (double)CONCAT44(uStack_94,local_98)) -
             local_80;
  local_128 = ((double)CONCAT44(uStack_144,local_148) + (double)CONCAT44(uStack_144,local_148)) -
              local_130;
  iVar10 = FUN_00415a20(0x32);
  local_10 = (double)local_190 / (double)(iVar10 + 0x50);
  dVar4 = dVar7 / (double)(iVar10 + 0x50);
  local_18 = local_a8[0] - local_10;
  local_10 = local_a8[0] + local_10;
  local_c8 = local_158[0] - dVar4;
  local_c0 = local_158[0] + dVar4;
  if (((DAT_004ac900 == 0) && (0x23 < *(int *)(&DAT_004a7060 + param_4 * 4))) && (uVar9 == 0)) {
    (**(code **)(*(int *)param_1 + 0x2c))(6);
    if ((*(int *)(&DAT_004a8660 + local_17c) < 10) && (DAT_004a4ee4 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
    }
    FUN_004706bd(param_1,(int *)&local_184,(int)(longlong)local_18,(int)(longlong)local_c8);
    CDC::LineTo(param_1,(int)(longlong)(double)CONCAT44(iStack_194,local_198),(int)(longlong)dVar5);
    CDC::LineTo(param_1,(int)(longlong)local_10,(int)(longlong)local_c0);
  }
  pcVar1 = *(code **)(*(int *)param_1 + 0x2c);
  (*pcVar1)(7);
  FUN_00416420((int *)param_1,param_4);
  if ((DAT_004ac900 == 0) || (param_4 == 0)) {
    _DAT_004a4ca8 = (undefined4)(longlong)(double)CONCAT44(local_198,uStack_19c);
    _DAT_004a4cac = (undefined4)(longlong)(double)CONCAT44(local_1a0,uStack_1a4);
    _DAT_004a4cb0 = (int)(longlong)(double)CONCAT44((undefined4)local_90,uStack_94);
    _DAT_004a4cb4 = (int)(longlong)(double)CONCAT44((undefined4)local_140,uStack_144);
    _DAT_004a4cb8 = (undefined4)(longlong)(double)CONCAT44((undefined4)local_88,local_90._4_4_);
    _DAT_004a4cbc = (undefined4)(longlong)(double)CONCAT44((undefined4)local_138,local_140._4_4_);
    _DAT_004a4cc0 = (undefined4)(longlong)(double)CONCAT44((undefined4)local_80,local_88._4_4_);
    _DAT_004a4cc4 = (undefined4)(longlong)(double)CONCAT44((undefined4)local_130,local_138._4_4_);
    _DAT_004a4cc8 = (undefined4)(longlong)(double)CONCAT44((undefined4)local_78,local_80._4_4_);
    _DAT_004a4ccc = (undefined4)(longlong)(double)CONCAT44((undefined4)local_128,local_130._4_4_);
    _DAT_004a4cd0 = (undefined4)(longlong)(double)CONCAT44((undefined4)local_70,local_78._4_4_);
    _DAT_004a4cd4 = (undefined4)(longlong)(double)CONCAT44((undefined4)local_120,local_128._4_4_);
    _DAT_004a4cd8 = (undefined4)(longlong)(double)CONCAT44(local_68._0_4_,local_70._4_4_);
    _DAT_004a4cdc = (undefined4)(longlong)(double)CONCAT44(local_118._0_4_,local_120._4_4_);
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,7);
  }
  (*pcVar1)(7);
  if (local_190._0_4_ != 1) {
    dVar6 = (double)CONCAT44(local_17c,local_184._4_4_) * _DAT_00484fe8;
    iVar10 = *(int *)(&DAT_004aa730 + param_4 * 4);
    unique0x100013bf = (double)(int)(&DAT_004a3450)[iVar11] * dVar6 * _DAT_00484cc8;
    local_170 = (double)(int)(&DAT_004a54a0)[iVar11] * dVar6 * _DAT_00484cc8;
    iVar12 = FUN_00415a20(3);
    iVar12 = FUN_00413cb0(iVar12 + 6 + *(int *)(&DAT_004a6ec8 + param_4 * 4) / 2);
    dVar6 = (double)(int)(&DAT_004a54a0)[iVar12] * _DAT_00484f60 * (double)iVar10;
    local_178 = (double)CONCAT44(local_17c,local_184._4_4_) * _DAT_00484da0;
    dVar8 = stack0xfffffe74 * dVar6;
    dVar6 = local_170 * dVar6;
    local_68 = dStack_b0 - dVar8 * _DAT_00484cc8;
    local_118 = dStack_160 - dVar6 * _DAT_00484cc8;
    dStack_58 = dStack_b0 - dVar8 * _DAT_00484d48;
    dStack_108 = dStack_160 - dVar6 * _DAT_00484d48;
    iVar12 = FUN_00413cb0(((*(int *)(&DAT_004a77e8 + param_4 * 4) << 1) / 3 + 10) *
                          *(int *)(&DAT_004aa730 + param_4 * 4) + iVar11);
    iVar10 = (*(int *)(&DAT_004a77e8 + param_4 * 4) << 1) / 3;
    unique0x0000aa00 = (double)(int)(&DAT_004a54a0)[iVar12];
    dVar6 = (double)(int)(&DAT_004a54a0)[iVar12] * local_178;
    dStack_60 = local_68 - dVar6 * _DAT_00484cc8;
    dStack_110 = local_118 - (double)(int)(&DAT_004a3450)[iVar12] * local_178 * _DAT_00484e28;
    dVar8 = (double)CONCAT44(local_17c,local_184._4_4_) * _DAT_00484f10;
    local_10 = (local_68 + dStack_58) * _DAT_00484da8 - dVar6 * _DAT_00485150;
    local_c0 = (local_118 + dStack_108) * _DAT_00484da8 -
               (double)(int)(&DAT_004a3450)[iVar12] * local_178 * _DAT_00485158;
    if (0x3c < iVar10) {
      iVar10 = 0x3c;
    }
    if (*(int *)(&DAT_004aa730 + param_4 * 4) == -1) {
      iVar10 = -iVar10;
    }
    iVar10 = FUN_00413cb0(iVar10 + iVar11);
    dStack_48 = dVar5 - (double)(int)(&DAT_004a54a0)[iVar10] * dVar8 * _DAT_00484cc8;
    dStack_f8 = dVar7 - (double)(int)(&DAT_004a3450)[iVar10] * dVar8 * _DAT_00484e28;
    if (DAT_00491150 == 100) {
      dStack_50 = dStack_58;
      dStack_100 = dStack_108;
    }
    else {
      dStack_50 = (dStack_b0 - dStack_58 * _DAT_00484e98) * _DAT_00484db0;
      dStack_100 = (dStack_160 - dStack_108 * _DAT_00484e98) * _DAT_00484db0;
    }
    if (0 < *(int *)(&DAT_004abb70 + param_4 * 4)) {
      iVar10 = *(int *)(&DAT_004a77e8 + param_4 * 4) + -0xa0;
      if (*(int *)(&DAT_004aa730 + param_4 * 4) == -1) {
        iVar10 = -iVar10;
      }
      iVar11 = FUN_00413cb0(iVar10 + iVar11);
      dStack_40 = dVar5 - (double)(int)(&DAT_004a54a0)[iVar11] * dVar8 * _DAT_00484cc8;
      dStack_f0 = dVar7 - (double)(int)(&DAT_004a3450)[iVar11] * dVar8 * _DAT_00484e28;
    }
    local_1b8 = SUB84(dVar4,0);
    if ((*(int *)(&DAT_004abb70 + param_4 * 4) < 1) && (1 < DAT_00491188)) {
      (*local_1b8)(0);
      if ((DAT_004ac92c == 0) && ((DAT_00491188 == 7 && (DAT_004ab17c != (HGDIOBJ)0x0)))) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004ab17c);
      }
      _DAT_004a4ca8 = (undefined4)(longlong)dVar5;
      _DAT_004a4cac = (undefined4)(longlong)dVar7;
      _DAT_004a4cb0 = (int)(longlong)dStack_48;
      _DAT_004a4cb4 = (int)(longlong)dStack_f8;
      _DAT_004a4cb8 = (undefined4)(longlong)dStack_50;
      _DAT_004a4cbc = (undefined4)(longlong)dStack_100;
      Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,3);
    }
    if (((*(int *)(&DAT_004abb70 + param_4 * 4) == 1) && (1 < DAT_00491188)) && (DAT_00491188 != 9))
    {
      if (((DAT_004ac92c == 0) && (2 < DAT_00491188)) && (DAT_00491188 < 8)) {
        (*local_1b8)(8);
        FUN_0041af70((int *)param_1,param_4);
        dVar4 = local_184;
      }
      else {
        (*local_1b8)(0);
        dVar4 = local_184;
        if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
          dVar4 = local_184;
        }
      }
      local_184._4_4_ = (undefined4)((ulonglong)dVar4 >> 0x20);
      if ((DAT_004ac92c == 0) && (DAT_00491188 == 10)) {
        local_184 = dVar4;
        (*local_1b8)(8);
        FUN_0041af70((int *)param_1,param_4);
      }
      lVar2 = (longlong)dStack_50;
      lVar3 = (longlong)dStack_100;
      _DAT_004a4cb0 = (int)(longlong)dVar5;
      _DAT_004a4cb4 = (int)(longlong)dVar7;
      _DAT_004a4cb8 = (undefined4)(longlong)dStack_40;
      _DAT_004a4cbc = (undefined4)(longlong)dStack_f0;
      _DAT_004a4ca8 = (int)lVar2;
      _DAT_004a4cac = (int)lVar3;
      local_190._0_4_ = _DAT_004a4cb0;
      local_184._0_4_ = _DAT_004a4cb4;
      Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,3);
      if ((2 < DAT_00491188) && (DAT_00491188 != 9)) {
        _DAT_004a4cb0 = local_190._0_4_;
        _DAT_004a4cb4 = (int)local_184;
        _DAT_004a4cb8 = (undefined4)(longlong)dStack_48;
        _DAT_004a4cbc = (undefined4)(longlong)dStack_f8;
        _DAT_004a4ca8 = (int)lVar2;
        _DAT_004a4cac = (int)lVar3;
        Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,3);
      }
    }
    (*local_1b8)(7);
    (*local_1b8)(0);
    if (((param_4 == 1) && (DAT_004ac9bc == 1)) && (DAT_004a6234 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a6234);
    }
    if (((param_4 == 2) && (DAT_004ac9bc == 1)) && (DAT_004aa98c != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004aa98c);
    }
    if (((10 < (int)param_4) && ((int)param_1 < 0x15)) &&
       ((DAT_004ac9bc == 1 && (DAT_004a4f7c != (HGDIOBJ)0x0)))) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4f7c);
    }
    if (((0x14 < (int)param_4) && (DAT_004ac9bc == 1)) && (DAT_004a5afc != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a5afc);
    }
    if ((DAT_004a5b80 < *(int *)(&DAT_004abf18 + param_4 * 4) + DAT_004a7644) &&
       (*(int *)(&DAT_004a89c0 + param_4 * 4) < 0xb)) {
      (*local_1b8)(4);
    }
    _DAT_004a4ca8 = (undefined4)(longlong)local_70;
    _DAT_004a4cac = (undefined4)(longlong)local_120;
    lVar2 = (longlong)dStack_60;
    lVar3 = (longlong)dStack_110;
    _DAT_004a4cb8 = (undefined4)(longlong)local_18;
    _DAT_004a4cbc = (undefined4)(longlong)local_c8;
    _DAT_004a4cc0 = (undefined4)(longlong)local_68;
    _DAT_004a4cc4 = (undefined4)(longlong)local_118;
    _DAT_004a4cb0 = (int)lVar2;
    _DAT_004a4cb4 = (int)lVar3;
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,4);
    FUN_004706bd(param_1,&iStack_194,(int)(longlong)dStack_b8,(int)(longlong)local_168);
    CDC::LineTo(param_1,(int)lVar2,(int)lVar3);
  }
  return;
}

