
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
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  int local_1b0;
  double local_1a0;
  double local_198;
  double local_184;
  int local_17c;
  double local_178;
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
  
  bVar11 = param_4 == 0;
  if ((DAT_004ac900 == 1) && (0 < (int)param_4)) {
    FUN_00423830(param_1,param_2,param_3,param_4,param_5);
  }
  iVar9 = param_5 * 4;
  local_178 = (_DAT_00484cf0 - _DAT_00485100 / (double)*(int *)(&DAT_004a8660 + iVar9)) *
              _DAT_004a8670 * _DAT_00484e30;
  if (bVar11) {
    local_178 = local_178 * _DAT_00484dc0;
    _DAT_004a7060 = 0;
    _DAT_004ac018 = DAT_004aa5b4;
  }
  local_17c = iVar9;
  iVar8 = FUN_00413cb0(*(int *)(&DAT_004ac018 + param_4 * 4) - *(int *)(&DAT_004ac018 + iVar9));
  if (bVar11) {
    iVar8 = FUN_00413cb0(*(int *)(&DAT_004aa5b0 + iVar9) - *(int *)(&DAT_004ac018 + iVar9));
  }
  if ((&DAT_004ab160)[param_5] == 0) {
    iVar8 = FUN_00413cb0((iVar8 - *(int *)(&DAT_004a6830 + iVar9)) + *(int *)(&DAT_004ac018 + iVar9)
                        );
  }
  if ((&DAT_004ab160)[param_5] == 2) {
    iVar8 = FUN_00413cb0((iVar8 - *(int *)(&DAT_004aa5b0 + iVar9)) + *(int *)(&DAT_004ac018 + iVar9)
                        );
  }
  iVar9 = FUN_00413cb0(iVar8);
  dVar5 = (double)(int)(&DAT_004a54a0)[iVar9];
  dVar4 = (double)(int)(&DAT_004a3450)[iVar9];
  local_184 = (double)(int)(&DAT_004a54a0)[iVar9];
  local_168 = (double)(int)(&DAT_004a3450)[iVar9];
  local_170 = (double)param_3;
  dVar6 = _DAT_00485120;
  dVar7 = _DAT_00485118;
  if ((DAT_004ac900 == 1) && (0 < (int)param_4)) {
    dVar6 = _DAT_00485130;
    dVar7 = _DAT_00485128;
  }
  local_198 = (double)param_2 - local_178 * dVar5 * dVar7;
  local_1a0 = local_170 - local_178 * dVar4 * dVar6;
  local_1b0 = 1;
  iVar8 = 0;
  do {
    dVar6 = (double)local_1b0;
    iVar10 = iVar8 + 8;
    local_1b0 = local_1b0 + 1;
    *(double *)((int)local_a8 + iVar8) = local_198 - dVar5 * dVar6 * local_178 * _DAT_00485138;
    *(double *)((int)local_158 + iVar8) = local_1a0 - dVar4 * dVar6 * local_178 * _DAT_00485140;
    iVar8 = iVar10;
  } while (iVar10 < 0x11);
  dVar5 = local_178 * _DAT_00485110 * local_168;
  dVar4 = local_178 * _DAT_00485110 * local_184;
  local_a8[3] = local_a8[0] - dVar5 * _DAT_00484fb8;
  local_158[3] = local_158[0] - dVar4 * _DAT_00484fb8;
  local_88 = local_a8[1] - dVar5 * _DAT_00484cc8;
  local_138 = local_158[1] - dVar4 * _DAT_00484cc8;
  local_80 = local_a8[2] - dVar5 * _DAT_00485148;
  local_130 = local_158[2] - dVar4 * _DAT_00485148;
  local_68 = (local_a8[0] + local_a8[0]) - local_a8[3];
  local_118 = (local_158[0] + local_158[0]) - local_158[3];
  local_70 = (local_a8[1] + local_a8[1]) - local_88;
  local_120 = (local_158[1] + local_158[1]) - local_138;
  local_78 = (local_a8[2] + local_a8[2]) - local_80;
  local_128 = (local_158[2] + local_158[2]) - local_130;
  iVar8 = FUN_00415a20(0x32);
  dVar5 = dVar5 / (double)(iVar8 + 0x50);
  dVar4 = dVar4 / (double)(iVar8 + 0x50);
  local_18 = local_a8[0] - dVar5;
  local_10 = local_a8[0] + dVar5;
  local_c8 = local_158[0] - dVar4;
  local_c0 = local_158[0] + dVar4;
  if (((DAT_004ac900 == 0) && (0x23 < *(int *)(&DAT_004a7060 + param_4 * 4))) && (!bVar11)) {
    (**(code **)(*(int *)param_1 + 0x2c))(param_1,6);
    if ((*(int *)(&DAT_004a8660 + local_17c) < 10) && (DAT_004a4ee4 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
    }
    FUN_004706bd(param_1,(int *)&local_184,(int)(longlong)local_18,(int)(longlong)local_c8);
    CDC::LineTo(param_1,(int)(longlong)local_198,(int)(longlong)local_1a0);
    CDC::LineTo(param_1,(int)(longlong)local_10,(int)(longlong)local_c0);
  }
  pcVar1 = *(code **)(*(int *)param_1 + 0x2c);
  (*pcVar1)(param_1,7);
  FUN_00416420((int *)param_1,param_4);
  if ((DAT_004ac900 == 0) || (param_4 == 0)) {
    _DAT_004a4ca8 = (undefined4)(longlong)local_198;
    _DAT_004a4cac = (undefined4)(longlong)local_1a0;
    _DAT_004a4cb0 = (int)(longlong)local_a8[3];
    _DAT_004a4cb4 = (int)(longlong)local_158[3];
    _DAT_004a4cb8 = (undefined4)(longlong)local_88;
    _DAT_004a4cbc = (undefined4)(longlong)local_138;
    _DAT_004a4cc0 = (undefined4)(longlong)local_80;
    _DAT_004a4cc4 = (undefined4)(longlong)local_130;
    _DAT_004a4cc8 = (undefined4)(longlong)local_78;
    _DAT_004a4ccc = (undefined4)(longlong)local_128;
    _DAT_004a4cd0 = (undefined4)(longlong)local_70;
    _DAT_004a4cd4 = (undefined4)(longlong)local_120;
    _DAT_004a4cd8 = (undefined4)(longlong)local_68;
    _DAT_004a4cdc = (undefined4)(longlong)local_118;
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,7);
  }
  (*pcVar1)(param_1,7);
  if (!bVar11) {
    iVar8 = *(int *)(&DAT_004aa730 + param_4 * 4);
    local_184 = (double)(int)(&DAT_004a3450)[iVar9] * local_178 * _DAT_00484fe8 * _DAT_00484cc8;
    local_168 = (double)(int)(&DAT_004a54a0)[iVar9] * local_178 * _DAT_00484fe8 * _DAT_00484cc8;
    iVar10 = FUN_00415a20(3);
    iVar10 = FUN_00413cb0(iVar10 + 6 + *(int *)(&DAT_004a6ec8 + param_4 * 4) / 2);
    dVar4 = (double)(int)(&DAT_004a54a0)[iVar10] * _DAT_00484f60 * (double)iVar8;
    local_170 = local_178 * _DAT_00484da0;
    dVar5 = local_184 * dVar4;
    dVar4 = local_168 * dVar4;
    dStack_60 = local_a8[0] - dVar5 * _DAT_00484cc8;
    dStack_110 = local_158[0] - dVar4 * _DAT_00484cc8;
    dStack_50 = local_a8[0] - dVar5 * _DAT_00484d48;
    dStack_100 = local_158[0] - dVar4 * _DAT_00484d48;
    iVar10 = FUN_00413cb0(((*(int *)(&DAT_004a77e8 + param_4 * 4) << 1) / 3 + 10) *
                          *(int *)(&DAT_004aa730 + param_4 * 4) + iVar9);
    iVar8 = (*(int *)(&DAT_004a77e8 + param_4 * 4) << 1) / 3;
    local_184 = (double)(int)(&DAT_004a54a0)[iVar10];
    dVar4 = (double)(int)(&DAT_004a54a0)[iVar10] * local_170;
    dStack_58 = dStack_60 - dVar4 * _DAT_00484cc8;
    dStack_108 = dStack_110 - (double)(int)(&DAT_004a3450)[iVar10] * local_170 * _DAT_00484e28;
    dVar5 = local_178 * _DAT_00484f10;
    dStack_8 = (dStack_60 + dStack_50) * _DAT_00484da8 - dVar4 * _DAT_00485150;
    dStack_b8 = (dStack_110 + dStack_100) * _DAT_00484da8 -
                (double)(int)(&DAT_004a3450)[iVar10] * local_170 * _DAT_00485158;
    if (0x3c < iVar8) {
      iVar8 = 0x3c;
    }
    if (*(int *)(&DAT_004aa730 + param_4 * 4) == -1) {
      iVar8 = -iVar8;
    }
    iVar8 = FUN_00413cb0(iVar8 + iVar9);
    dStack_40 = local_198 - (double)(int)(&DAT_004a54a0)[iVar8] * dVar5 * _DAT_00484cc8;
    dStack_f0 = local_1a0 - (double)(int)(&DAT_004a3450)[iVar8] * dVar5 * _DAT_00484e28;
    if (DAT_00491150 == 100) {
      dStack_48 = dStack_50;
      dStack_f8 = dStack_100;
    }
    else {
      dStack_48 = (local_a8[0] - dStack_50 * _DAT_00484e98) * _DAT_00484db0;
      dStack_f8 = (local_158[0] - dStack_100 * _DAT_00484e98) * _DAT_00484db0;
    }
    if (0 < *(int *)(&DAT_004abb70 + param_4 * 4)) {
      iVar8 = *(int *)(&DAT_004a77e8 + param_4 * 4) + -0xa0;
      if (*(int *)(&DAT_004aa730 + param_4 * 4) == -1) {
        iVar8 = -iVar8;
      }
      iVar9 = FUN_00413cb0(iVar8 + iVar9);
      dStack_38 = local_198 - (double)(int)(&DAT_004a54a0)[iVar9] * dVar5 * _DAT_00484cc8;
      dStack_e8 = local_1a0 - (double)(int)(&DAT_004a3450)[iVar9] * dVar5 * _DAT_00484e28;
    }
    if ((*(int *)(&DAT_004abb70 + param_4 * 4) < 1) && (1 < DAT_00491188)) {
      (*pcVar1)(param_1,0);
      if ((DAT_004ac92c == 0) && ((DAT_00491188 == 7 && (DAT_004ab17c != (HGDIOBJ)0x0)))) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004ab17c);
      }
      _DAT_004a4ca8 = (undefined4)(longlong)local_198;
      _DAT_004a4cac = (undefined4)(longlong)local_1a0;
      _DAT_004a4cb0 = (int)(longlong)dStack_40;
      _DAT_004a4cb4 = (int)(longlong)dStack_f0;
      _DAT_004a4cb8 = (undefined4)(longlong)dStack_48;
      _DAT_004a4cbc = (undefined4)(longlong)dStack_f8;
      Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,3);
    }
    if (((*(int *)(&DAT_004abb70 + param_4 * 4) == 1) && (1 < DAT_00491188)) && (DAT_00491188 != 9))
    {
      if (((DAT_004ac92c == 0) && (2 < DAT_00491188)) && (DAT_00491188 < 8)) {
        (*pcVar1)(param_1,8);
        FUN_0041af70((int *)param_1,param_4);
      }
      else {
        (*pcVar1)(param_1,0);
        if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
        }
      }
      if ((DAT_004ac92c == 0) && (DAT_00491188 == 10)) {
        (*pcVar1)(param_1,8);
        FUN_0041af70((int *)param_1,param_4);
      }
      lVar2 = (longlong)dStack_48;
      lVar3 = (longlong)dStack_f8;
      _DAT_004a4cb4 = (int)(longlong)local_1a0;
      _DAT_004a4cb8 = (undefined4)(longlong)dStack_38;
      _DAT_004a4cbc = (undefined4)(longlong)dStack_e8;
      _DAT_004a4ca8 = (int)lVar2;
      _DAT_004a4cac = (int)lVar3;
      _DAT_004a4cb0 = (int)(longlong)local_198;
      local_17c = _DAT_004a4cb4;
      Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,3);
      if ((2 < DAT_00491188) && (DAT_00491188 != 9)) {
        _DAT_004a4cb4 = local_17c;
        _DAT_004a4cb8 = (undefined4)(longlong)dStack_40;
        _DAT_004a4cbc = (undefined4)(longlong)dStack_f0;
        _DAT_004a4ca8 = (int)lVar2;
        _DAT_004a4cac = (int)lVar3;
        _DAT_004a4cb0 = (int)(longlong)local_198;
        Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,3);
      }
    }
    (*pcVar1)(param_1,7);
    (*pcVar1)(param_1,0);
    if (((param_4 == 1) && (DAT_004ac9bc == 1)) && (DAT_004a6234 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a6234);
    }
    if (((param_4 == 2) && (DAT_004ac9bc == 1)) && (DAT_004aa98c != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004aa98c);
    }
    if (((10 < (int)param_4) && (param_5 < 0x15)) &&
       ((DAT_004ac9bc == 1 && (DAT_004a4f7c != (HGDIOBJ)0x0)))) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4f7c);
    }
    if (((0x14 < (int)param_4) && (DAT_004ac9bc == 1)) && (DAT_004a5afc != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a5afc);
    }
    if ((DAT_004a5b80 < *(int *)(&DAT_004abf18 + param_4 * 4) + DAT_004a7644) &&
       (*(int *)(&DAT_004a89c0 + param_4 * 4) < 0xb)) {
      (*pcVar1)(param_1,4);
    }
    _DAT_004a4ca8 = (undefined4)(longlong)dStack_60;
    _DAT_004a4cac = (undefined4)(longlong)dStack_110;
    lVar2 = (longlong)dStack_50;
    lVar3 = (longlong)dStack_100;
    _DAT_004a4cb8 = (undefined4)(longlong)dStack_8;
    _DAT_004a4cbc = (undefined4)(longlong)dStack_b8;
    _DAT_004a4cc0 = (undefined4)(longlong)dStack_58;
    _DAT_004a4cc4 = (undefined4)(longlong)dStack_108;
    _DAT_004a4cb0 = (int)lVar2;
    _DAT_004a4cb4 = (int)lVar3;
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,4);
    FUN_004706bd(param_1,(int *)&local_184,(int)(longlong)local_a8[0],(int)(longlong)local_158[0]);
    CDC::LineTo(param_1,(int)lVar2,(int)lVar3);
  }
  return;
}

