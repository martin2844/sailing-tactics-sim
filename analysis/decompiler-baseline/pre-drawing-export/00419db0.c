
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00419db0(CDC *param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  CDC *this;
  int iVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  CDC *pCVar10;
  int unaff_EBX;
  int iVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  HDC hdc;
  int iStack_18;
  int aiStack_10 [3];
  int iStack_4;
  
  this = param_1;
  if ((DAT_00491140 < param_2) && (DAT_004ac928 == 1)) {
    return;
  }
  if (param_7 < DAT_004ac13c) {
    return;
  }
  if ((DAT_00491188 != 7) && (param_5 == 0)) {
    return;
  }
  bVar14 = DAT_004ac930 == 1;
  pcVar6 = *(code **)(*(int *)param_1 + 0x2c);
  (*pcVar6)(7);
  if (DAT_00491188 == 7) {
    unaff_EBX = (int)(longlong)((double)CONCAT44(param_3,pcVar6) * _DAT_00484d48);
    param_6 = unaff_EBX / 2;
  }
  if ((param_5 == 1) || (param_5 == 2)) {
    unaff_EBX = (int)(longlong)((double)CONCAT44(param_3,pcVar6) * _DAT_00484f10);
    param_6 = (int)(longlong)((double)CONCAT44(param_3,pcVar6) * _DAT_00484d90);
  }
  if (bVar14) {
    unaff_EBX = 0;
    param_6 = 0;
  }
  iVar1 = (DAT_004aa1d4 * 7 + DAT_004aa1c4 * 3) / 10;
  iVar2 = (DAT_004aa2d4 * 7 + DAT_004aa2c4 * 3) / 10;
  iVar4 = iVar2 - param_6;
  iVar3 = (DAT_004aa1c4 * 7 + DAT_004aa1d4 * 3) / 10;
  _DAT_004a4cb4 = (code *)((DAT_004aa2c4 * 7 + DAT_004aa2d4 * 3) / 10);
  iVar5 = (int)_DAT_004a4cb4 - param_6;
  iVar7 = DAT_004aa1d8 + DAT_004aa1c0 * 3;
  iVar12 = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
  iVar7 = DAT_004aa2d8 + DAT_004aa2c0 * 3;
  iVar11 = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
  pcVar6 = (code *)(iVar11 - unaff_EBX);
  iVar7 = DAT_004aa1c0 + DAT_004aa1d8 * 3;
  iVar13 = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
  iVar7 = DAT_004aa2c0 + DAT_004aa2d8 * 3;
  iVar9 = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
  iVar7 = iVar9 - unaff_EBX;
  aiStack_10[0] = (int)_DAT_004a4cb4;
  if (-0x14 < (int)param_5) {
    if (iStack_18 != 0) goto LAB_0041a3e2;
    _DAT_004a4ca8 = iVar12;
    _DAT_004a4cac = iVar11;
    _DAT_004a4cb0 = iVar3;
    _DAT_004a4cb8 = iVar3;
    _DAT_004a4cbc = (code *)iVar5;
    _DAT_004a4cc0 = iVar12;
    _DAT_004a4cc4 = pcVar6;
    (*(code *)param_1)(0);
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,4);
    if (param_3 < 5) {
      pCVar10 = (CDC *)((iStack_4 + iVar11) / 2);
      iVar8 = (iVar1 + iVar2) / 2;
      if (DAT_004a4dec != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
      }
      FUN_004706bd(param_1,aiStack_10,(iVar9 + iVar12 * 2) / 3,(iVar8 + (int)pCVar10 * 2) / 3);
      CDC::LineTo(param_1,(iVar12 + iVar9 * 2) / 3,(int)(pCVar10 + iVar8 * 2) / 3);
      param_1 = pCVar10;
    }
    (*pcVar6)(7);
  }
  if (iStack_18 == 0) {
    if (((int)param_5 < 0x14) || (0xa0 < (int)param_5)) {
      _DAT_004a4ca8 = iVar13;
      _DAT_004a4cac = iVar9;
      _DAT_004a4cb0 = iVar1;
      _DAT_004a4cb4 = (code *)iVar2;
      _DAT_004a4cb8 = iVar1;
      _DAT_004a4cbc = (code *)iVar4;
      _DAT_004a4cc0 = iVar13;
      _DAT_004a4cc4 = (code *)iVar7;
      (*(code *)param_1)(0);
      Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,4);
      if (param_3 < 5) {
        param_1 = (CDC *)((int)(unaff_EBX + param_5) / 2);
        if (DAT_004a4dec != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(this + 4),DAT_004a4dec);
        }
        FUN_004706bd(this,aiStack_10,(iVar3 + iVar13 * 2) / 3,(iVar5 / 2 + (int)param_1 * 2) / 3);
        CDC::LineTo(this,(iVar13 + iVar3 * 2) / 3,(int)(param_1 + (iVar5 / 2) * 2) / 3);
      }
      (*pcVar6)(7);
    }
    if ((int)((param_5 ^ (int)param_5 >> 0x1f) - ((int)param_5 >> 0x1f)) < 0x5a) {
      _DAT_004a4ca8 = iVar13;
      _DAT_004a4cac = iVar9;
      _DAT_004a4cb0 = iVar13;
      _DAT_004a4cb4 = (code *)iVar7;
      _DAT_004a4cb8 = iVar12;
      _DAT_004a4cbc = pcVar6;
      _DAT_004a4cc0 = iVar12;
      _DAT_004a4cc4 = (code *)iVar11;
      (*(code *)param_1)(0);
      Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,4);
      if (param_4 != 0) goto LAB_0041a3e2;
      _DAT_004a4ca8 = (iVar12 + iVar13 * 2) / 3;
      _DAT_004a4cac = (iVar11 + iVar9 * 2) / 3;
      _DAT_004a4cb4 = (code *)((int)(pcVar6 + iVar7 * 2) / 3);
      _DAT_004a4cb8 = (iVar13 + iVar12 * 2) / 3;
      _DAT_004a4cbc = (code *)((iVar7 + (int)pcVar6 * 2) / 3);
      _DAT_004a4cc4 = (code *)((iVar9 + iVar11 * 2) / 3);
      _DAT_004a4cb0 = _DAT_004a4ca8;
      _DAT_004a4cc0 = _DAT_004a4cb8;
      (*(code *)param_1)(4);
      hdc = *(HDC *)(this + 4);
    }
    else {
      _DAT_004a4cc4 = (code *)aiStack_10[0];
      _DAT_004a4ca8 = iVar1;
      _DAT_004a4cac = iVar2;
      _DAT_004a4cb0 = iVar1;
      _DAT_004a4cb4 = (code *)iVar4;
      _DAT_004a4cb8 = iVar3;
      _DAT_004a4cbc = (code *)iVar5;
      _DAT_004a4cc0 = iVar3;
      (*(code *)param_1)(0);
      hdc = *(HDC *)(this + 4);
    }
    Polygon(hdc,(POINT *)&DAT_004a4ca8,4);
  }
LAB_0041a3e2:
  _DAT_004a4ca8 = iVar13;
  _DAT_004a4cac = iVar7;
  _DAT_004a4cb0 = iVar12;
  _DAT_004a4cb4 = pcVar6;
  _DAT_004a4cb8 = iVar3;
  _DAT_004a4cbc = (code *)iVar5;
  _DAT_004a4cc0 = iVar1;
  _DAT_004a4cc4 = (code *)iVar4;
  (*(code *)param_1)(0);
  Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,4);
  return;
}

