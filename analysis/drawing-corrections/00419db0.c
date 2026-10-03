
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00419db0(CDC *param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,int param_7)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  HDC hdc;
  int iStack_2c;
  int aiStack_8 [2];
  
  if ((DAT_00491140 < param_2) && (DAT_004ac928 == 1)) {
    return;
  }
  if (param_7 < DAT_004ac13c) {
    return;
  }
  if ((DAT_00491188 != 7) && (param_5 == 0)) {
    return;
  }
  bVar16 = DAT_004ac930 == 1;
  pcVar1 = *(code **)(*(int *)param_1 + 0x2c);
  (*pcVar1)(param_1,7);
  if (DAT_00491188 == 7) {
    iStack_2c = (int)(longlong)((double)CONCAT44(param_4,param_3) * _DAT_00484d48);
    param_7 = iStack_2c / 2;
  }
  if ((param_5 == 1) || (param_5 == 2)) {
    iStack_2c = (int)(longlong)((double)CONCAT44(param_4,param_3) * _DAT_00484f10);
    param_7 = (int)(longlong)((double)CONCAT44(param_4,param_3) * _DAT_00484d90);
  }
  if (bVar16) {
    iStack_2c = 0;
    param_7 = 0;
  }
  iVar2 = (DAT_004aa1d4 * 7 + DAT_004aa1c4 * 3) / 10;
  iVar3 = (DAT_004aa2d4 * 7 + DAT_004aa2c4 * 3) / 10;
  iVar6 = iVar3 - param_7;
  iVar4 = (DAT_004aa1c4 * 7 + DAT_004aa1d4 * 3) / 10;
  iVar5 = (DAT_004aa2c4 * 7 + DAT_004aa2d4 * 3) / 10;
  iVar7 = iVar5 - param_7;
  iVar9 = DAT_004aa1d8 + DAT_004aa1c0 * 3;
  iVar14 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
  iVar9 = DAT_004aa2d8 + DAT_004aa2c0 * 3;
  iVar13 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
  iVar8 = iVar13 - iStack_2c;
  iVar9 = DAT_004aa1c0 + DAT_004aa1d8 * 3;
  iVar15 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
  iVar9 = DAT_004aa2c0 + DAT_004aa2d8 * 3;
  iVar11 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
  iVar9 = iVar11 - iStack_2c;
  if (-0x14 < param_6) {
    if (bVar16) goto LAB_0041a3e2;
    _DAT_004a4ca8 = iVar14;
    _DAT_004a4cac = iVar13;
    _DAT_004a4cb0 = iVar4;
    _DAT_004a4cb4 = iVar5;
    _DAT_004a4cb8 = iVar4;
    _DAT_004a4cbc = iVar7;
    _DAT_004a4cc0 = iVar14;
    _DAT_004a4cc4 = iVar8;
    (*pcVar1)(param_1,0);
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,4);
    if ((int)param_5 < 5) {
      iVar12 = (iVar8 + iVar13) / 2;
      iVar10 = (iVar7 + iVar5) / 2;
      if (DAT_004a4dec != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
      }
      FUN_004706bd(param_1,aiStack_8,(iVar4 + iVar14 * 2) / 3,(iVar10 + iVar12 * 2) / 3);
      CDC::LineTo(param_1,(iVar14 + iVar4 * 2) / 3,(iVar12 + iVar10 * 2) / 3);
    }
    (*pcVar1)(param_1,7);
  }
  if (!bVar16) {
    if ((param_6 < 0x14) || (0xa0 < param_6)) {
      _DAT_004a4ca8 = iVar15;
      _DAT_004a4cac = iVar11;
      _DAT_004a4cb0 = iVar2;
      _DAT_004a4cb4 = iVar3;
      _DAT_004a4cb8 = iVar2;
      _DAT_004a4cbc = iVar6;
      _DAT_004a4cc0 = iVar15;
      _DAT_004a4cc4 = iVar9;
      (*pcVar1)(param_1,0);
      Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,4);
      if ((int)param_5 < 5) {
        iVar12 = (iVar11 + iVar9) / 2;
        iVar10 = (iVar3 + iVar6) / 2;
        if (DAT_004a4dec != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
        }
        FUN_004706bd(param_1,aiStack_8,(iVar2 + iVar15 * 2) / 3,(iVar10 + iVar12 * 2) / 3);
        CDC::LineTo(param_1,(iVar15 + iVar2 * 2) / 3,(iVar12 + iVar10 * 2) / 3);
      }
      (*pcVar1)(param_1,7);
    }
    if (!bVar16) {
      if ((param_6 ^ param_6 >> 0x1f) - (param_6 >> 0x1f) < 0x5a) {
        _DAT_004a4ca8 = iVar15;
        _DAT_004a4cac = iVar11;
        _DAT_004a4cb0 = iVar15;
        _DAT_004a4cb4 = iVar9;
        _DAT_004a4cb8 = iVar14;
        _DAT_004a4cbc = iVar8;
        _DAT_004a4cc0 = iVar14;
        _DAT_004a4cc4 = iVar13;
        (*pcVar1)(param_1,0);
        Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,4);
        if (param_5 != 0) goto LAB_0041a3e2;
        _DAT_004a4ca8 = (iVar14 + iVar15 * 2) / 3;
        _DAT_004a4cac = (iVar13 + iVar11 * 2) / 3;
        _DAT_004a4cb4 = (iVar8 + iVar9 * 2) / 3;
        _DAT_004a4cb8 = (iVar15 + iVar14 * 2) / 3;
        _DAT_004a4cbc = (iVar9 + iVar8 * 2) / 3;
        _DAT_004a4cc4 = (iVar11 + iVar13 * 2) / 3;
        _DAT_004a4cb0 = _DAT_004a4ca8;
        _DAT_004a4cc0 = _DAT_004a4cb8;
        (*pcVar1)(param_1,4);
        hdc = *(HDC *)(param_1 + 4);
      }
      else {
        _DAT_004a4ca8 = iVar2;
        _DAT_004a4cac = iVar3;
        _DAT_004a4cb0 = iVar2;
        _DAT_004a4cb4 = iVar6;
        _DAT_004a4cb8 = iVar4;
        _DAT_004a4cbc = iVar7;
        _DAT_004a4cc0 = iVar4;
        _DAT_004a4cc4 = iVar5;
        (*pcVar1)(param_1,0);
        hdc = *(HDC *)(param_1 + 4);
      }
      Polygon(hdc,(POINT *)&DAT_004a4ca8,4);
    }
  }
LAB_0041a3e2:
  _DAT_004a4ca8 = iVar15;
  _DAT_004a4cac = iVar9;
  _DAT_004a4cb0 = iVar14;
  _DAT_004a4cb4 = iVar8;
  _DAT_004a4cb8 = iVar4;
  _DAT_004a4cbc = iVar7;
  _DAT_004a4cc0 = iVar2;
  _DAT_004a4cc4 = iVar6;
  (*pcVar1)(param_1,0);
  Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,4);
  return;
}

