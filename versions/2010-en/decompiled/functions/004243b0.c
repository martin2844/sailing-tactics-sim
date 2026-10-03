
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_004243b0(int *param_1,int param_2,double param_3,int param_4,int param_5,int param_6)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  HDC hdc;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int aiStack_8 [2];
  
  if (DAT_005364c8 == 1) {
    return;
  }
  if ((param_2 != 1) && (DAT_005363e0 == 1)) {
    return;
  }
  if (param_6 < (int)((DAT_00535884 >> 0x1f & 3U) + DAT_00535884) >> 2) {
    return;
  }
  if ((param_6 < DAT_00535884) && (param_4 == 0)) {
    return;
  }
  if (((DAT_004da190 != 7) && (DAT_005363c0 == 0)) && (param_4 == 0)) {
    return;
  }
  bVar8 = DAT_005363e8 == 1;
  pcVar1 = *(code **)(*param_1 + 0x2c);
  (*pcVar1)(param_1,7);
  if ((DAT_004da190 == 7) || (1 < DAT_005363c0)) {
    iStack_30 = (int)(longlong)(param_3 * _DAT_004cc570);
    param_6 = iStack_30 / 2;
  }
  if ((param_4 == 1) || (param_4 == 2)) {
    iStack_30 = (int)(longlong)(param_3 * _DAT_004cc770);
    param_6 = (int)(longlong)(param_3 * _DAT_004cc660);
  }
  if (bVar8) {
    iStack_30 = 0;
    param_6 = 0;
  }
  iStack_28 = DAT_00522914 * 7 + DAT_00522904 * 3;
  iStack_1c = (DAT_00522a14 * 7 + DAT_00522a04 * 3) / 10;
  aiStack_8[0] = DAT_00522a14 * 3;
  iStack_20 = iStack_1c - param_6;
  iStack_2c = DAT_00522904 * 7 + DAT_00522914 * 3;
  iStack_18 = (DAT_00522a04 * 7 + aiStack_8[0]) / 10;
  iStack_24 = iStack_18 - param_6;
  iVar2 = DAT_00522918 + DAT_00522900 * 3;
  iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
  iVar7 = DAT_00522a18 + DAT_00522a00 * 3;
  iVar6 = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
  iStack_34 = iVar6 - iStack_30;
  iVar3 = DAT_00522900 + DAT_00522918 * 3;
  iVar3 = iVar3 + (iVar3 >> 0x1f & 3U);
  iVar7 = DAT_00522a00 + DAT_00522a18 * 3;
  iVar7 = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
  param_3._0_4_ = iVar7 - iStack_30;
  if (1 < DAT_005363c0) {
    iStack_28 = DAT_00522908 * 3 + DAT_00522910 * 7;
    iStack_1c = (DAT_00522a08 * 3 + DAT_00522a10 * 7) / 10;
    iStack_20 = iStack_1c - param_6;
    iStack_2c = DAT_00522910 * 3 + DAT_00522908 * 7;
    iStack_18 = (DAT_00522a10 * 3 + DAT_00522a08 * 7) / 10;
    iStack_24 = iStack_18 - param_6;
    iVar2 = DAT_00522904 * 3 + DAT_00522914;
    iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
    iVar7 = DAT_00522a14 + DAT_00522a04 * 3;
    iVar6 = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
    iStack_34 = iVar6 - iStack_30;
    iVar3 = DAT_00522914 * 3 + DAT_00522904;
    iVar3 = iVar3 + (iVar3 >> 0x1f & 3U);
    iVar7 = (int)(DAT_00522a04 + aiStack_8[0] + (DAT_00522a04 + aiStack_8[0] >> 0x1f & 3U)) >> 2;
    param_3._0_4_ = iVar7 - iStack_30;
  }
  iStack_28 = iStack_28 / 10;
  iStack_2c = iStack_2c / 10;
  iVar3 = iVar3 >> 2;
  iVar2 = iVar2 >> 2;
  if (-0x14 < param_5) {
    if (bVar8) goto LAB_00424b65;
    _DAT_004f6e30 = iStack_2c;
    _DAT_004f6e38 = iStack_2c;
    _DAT_004f6e34 = iStack_18;
    _DAT_004f6e3c = iStack_24;
    _DAT_004f6e44 = iStack_34;
    _DAT_004f6e28 = iVar2;
    _DAT_004f6e2c = iVar6;
    _DAT_004f6e40 = iVar2;
    (*pcVar1)(param_1,0);
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    if (param_4 < 5) {
      iVar5 = (iStack_34 + iVar6) / 2;
      iVar4 = (iStack_18 + iStack_24) / 2;
      if (DAT_004f7084 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f7084);
      }
      FUN_004b4d9d(param_1,aiStack_8,(iStack_2c + iVar2 * 2) / 3,(iVar4 + iVar5 * 2) / 3);
      CDC::LineTo(param_1,(iVar2 + iStack_2c * 2) / 3,(iVar5 + iVar4 * 2) / 3);
    }
    (*pcVar1)(param_1,7);
  }
  if (!bVar8) {
    if ((param_5 < 0x14) || (0xa0 < param_5)) {
      _DAT_004f6e30 = iStack_28;
      _DAT_004f6e38 = iStack_28;
      _DAT_004f6e34 = iStack_1c;
      _DAT_004f6e3c = iStack_20;
      _DAT_004f6e44 = param_3._0_4_;
      _DAT_004f6e28 = iVar3;
      _DAT_004f6e2c = iVar7;
      _DAT_004f6e40 = iVar3;
      (*pcVar1)(param_1,0);
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
      if (param_4 < 5) {
        iVar5 = (param_3._0_4_ + iVar7) / 2;
        iVar4 = (iStack_1c + iStack_20) / 2;
        if (DAT_004f7084 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004f7084);
        }
        FUN_004b4d9d(param_1,aiStack_8,(iStack_28 + iVar3 * 2) / 3,(iVar4 + iVar5 * 2) / 3);
        CDC::LineTo(param_1,(iVar3 + iStack_28 * 2) / 3,(iVar5 + iVar4 * 2) / 3);
      }
      (*pcVar1)(param_1,7);
    }
    if (!bVar8) {
      if ((param_5 ^ param_5 >> 0x1f) - (param_5 >> 0x1f) < 0x5a) {
        _DAT_004f6e34 = param_3._0_4_;
        _DAT_004f6e3c = iStack_34;
        _DAT_004f6e28 = iVar3;
        _DAT_004f6e2c = iVar7;
        _DAT_004f6e30 = iVar3;
        _DAT_004f6e38 = iVar2;
        _DAT_004f6e40 = iVar2;
        _DAT_004f6e44 = iVar6;
        (*pcVar1)(param_1,0);
        Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
        if (param_4 != 0) goto LAB_00424b65;
        _DAT_004f6e28 = (iVar2 + iVar3 * 2) / 3;
        _DAT_004f6e2c = (iVar6 + iVar7 * 2) / 3;
        _DAT_004f6e34 = (iStack_34 + param_3._0_4_ * 2) / 3;
        _DAT_004f6e38 = (iVar3 + iVar2 * 2) / 3;
        _DAT_004f6e3c = (param_3._0_4_ + iStack_34 * 2) / 3;
        _DAT_004f6e44 = (iVar7 + iVar6 * 2) / 3;
        _DAT_004f6e30 = _DAT_004f6e28;
        _DAT_004f6e40 = _DAT_004f6e38;
        (*pcVar1)(param_1,4);
        hdc = (HDC)param_1[1];
      }
      else {
        _DAT_004f6e2c = iStack_1c;
        _DAT_004f6e28 = iStack_28;
        _DAT_004f6e30 = iStack_28;
        _DAT_004f6e34 = iStack_20;
        _DAT_004f6e3c = iStack_24;
        _DAT_004f6e38 = iStack_2c;
        _DAT_004f6e40 = iStack_2c;
        _DAT_004f6e44 = iStack_18;
        (*pcVar1)(param_1,0);
        hdc = (HDC)param_1[1];
      }
      Polygon(hdc,(POINT *)&DAT_004f6e28,4);
    }
  }
LAB_00424b65:
  _DAT_004f6e2c = param_3._0_4_;
  _DAT_004f6e34 = iStack_34;
  _DAT_004f6e38 = iStack_2c;
  _DAT_004f6e3c = iStack_24;
  _DAT_004f6e40 = iStack_28;
  _DAT_004f6e44 = iStack_20;
  _DAT_004f6e28 = iVar3;
  _DAT_004f6e30 = iVar2;
  (*pcVar1)(param_1,0);
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  return;
}

