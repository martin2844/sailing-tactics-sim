
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004817a0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10)

{
  code *pcVar1;
  int *original_dc;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  code *pcVar8;
  int iVar9;
  float10 fVar10;
  HDC pHVar11;
  HGDIOBJ pvVar12;
  
  original_dc = param_1;
  if (DAT_00535564 < param_5) {
    return;
  }
  if (param_4 < 0) {
    return;
  }
  if (DAT_004fe624 < param_4) {
    return;
  }
  fVar10 = (float10)FUN_00406220(param_5,param_10);
  iVar2 = (int)(longlong)(fVar10 * (float10)_DAT_004ccad8);
  if ((DAT_004da1f8 == 6) || (DAT_004da1f8 == 0xc)) {
    iVar2 = (iVar2 * 3) / 2;
  }
  if (1000 < iVar2) {
    iVar2 = 1000;
  }
  if (param_7 == 1) {
    param_10 = iVar2 / 5;
  }
  else {
    param_10 = iVar2 / 2;
  }
  if (param_7 == 2) {
    param_10 = (int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3;
  }
  param_10 = param_5 - param_10;
  if (param_6 == 0) {
    if (DAT_00536450 < 1) {
      FUN_00471160(param_1);
    }
    else {
      FUN_00469650(param_1);
    }
    if (DAT_004da1f8 == 100) {
      iVar4 = (iVar2 * 3) / 10;
      iVar3 = iVar2 / 10;
    }
    else {
      iVar4 = (iVar2 * 3) / 0x14;
      iVar3 = iVar2 / 0x14;
    }
    iVar3 = iVar3 + (iVar2 >> 0x1f);
    Ellipse((HDC)param_1[1],param_4 - iVar4,param_5,param_4 + iVar4,
            (iVar3 - (iVar3 >> 0x1f)) + param_5);
  }
  pcVar1 = *(code **)(*param_1 + 0x2c);
  (*pcVar1)(param_1,7);
  if (DAT_00536450 == 0) {
    if (param_2 == 0x62) {
      if (DAT_004fb6ac != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fb6ac);
      }
    }
    else {
      (*pcVar1)(param_1,0);
    }
  }
  if (DAT_00536450 == 1) {
    if (DAT_004da210 == 0) {
      FUN_00469650(param_1);
    }
    if (((DAT_00536450 == 1) && (DAT_004da210 == 1)) && (DAT_005230cc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
  }
  iVar3 = iVar2 / 0x14;
  iVar7 = param_4 - iVar3;
  iVar4 = param_4 + iVar3;
  param_1 = (int *)iVar4;
  param_6 = iVar7;
  if (param_3 != 0) {
    param_1 = (int *)(param_4 + iVar2 / 0x1e);
    param_6 = param_4 - iVar2 / 0x1e;
  }
  param_5 = iVar2 / 0x28 + param_5;
  _DAT_004f6e34 = param_10;
  _DAT_004f6e3c = param_10;
  _DAT_004f6e30 = param_6;
  _DAT_004f6e38 = (int)param_1;
  _DAT_004f6e28 = iVar7;
  _DAT_004f6e2c = param_5;
  _DAT_004f6e40 = iVar4;
  _DAT_004f6e44 = param_5;
  Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,4);
  (*pcVar1)(original_dc,4);
  if (0x59 < param_2) {
    _DAT_004f6e28 = iVar7 - iVar2 / 0x32;
    _DAT_004f6e34 = (param_5 * 3 + param_10 * 2) / 5;
    _DAT_004f6e40 = iVar4 + iVar2 / 0x32;
    _DAT_004f6e2c = param_5;
    _DAT_004f6e30 = iVar7;
    _DAT_004f6e38 = iVar4;
    _DAT_004f6e3c = _DAT_004f6e34;
    _DAT_004f6e44 = param_5;
    Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,4);
  }
  _DAT_004f6e28 = param_6;
  param_6 = param_6 + iVar2 / 0x3c;
  iVar7 = param_10 - iVar2 / 0x23;
  iVar4 = (int)param_1 - iVar2 / 0x3c;
  _DAT_004f6e2c = param_10;
  _DAT_004f6e40 = (int)param_1;
  _DAT_004f6e44 = param_10;
  _DAT_004f6e30 = param_6;
  _DAT_004f6e34 = iVar7;
  _DAT_004f6e38 = iVar4;
  _DAT_004f6e3c = iVar7;
  Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,4);
  if (param_8 == -1) {
    return;
  }
  if ((((param_8 == 1) || (param_8 == 5)) || (pcVar8 = SelectObject_exref, param_8 == 6)) &&
     (((*pcVar1)(original_dc,0), pcVar8 = SelectObject_exref, DAT_00536450 == 1 &&
      (DAT_004f7ec4 != (HGDIOBJ)0x0)))) {
    SelectObject((HDC)original_dc[1],DAT_004f7ec4);
  }
  if (param_8 == 2) {
    if (DAT_004f3864 != (HGDIOBJ)0x0) {
      (*pcVar8)((HDC)original_dc[1],DAT_004f3864);
    }
    if ((DAT_00536450 == 1) && (DAT_004fb994 != (HGDIOBJ)0x0)) {
      (*pcVar8)((HDC)original_dc[1],DAT_004fb994);
    }
  }
  if (param_8 == 3) {
    if (DAT_005233b4 != (HGDIOBJ)0x0) {
      (*pcVar8)((HDC)original_dc[1],DAT_005233b4);
    }
    if ((DAT_00536450 == 1) && (DAT_004f1cec != (HGDIOBJ)0x0)) {
      (*pcVar8)((HDC)original_dc[1],DAT_004f1cec);
    }
  }
  if (param_8 == 4) {
    uVar6 = (int)(DAT_004fad34 + param_2) / 3;
    uVar5 = (int)uVar6 >> 0x1f;
    if (((uVar6 ^ uVar5) - uVar5 & 3 ^ uVar5) == uVar5) {
      if (DAT_004f3864 != (HGDIOBJ)0x0) {
        (*pcVar8)((HDC)original_dc[1],DAT_004f3864);
      }
      if ((DAT_00536450 == 1) && (DAT_004fb994 != (HGDIOBJ)0x0)) {
        pHVar11 = (HDC)original_dc[1];
        pvVar12 = DAT_004fb994;
override_prt_481cc6_6059bb06:
        (*pcVar8)(pHVar11,pvVar12);
      }
    }
    else {
      (*pcVar1)(original_dc,0);
      if ((DAT_00536450 == 1) && (DAT_004f7ec4 != (HGDIOBJ)0x0)) {
        pHVar11 = (HDC)original_dc[1];
        pvVar12 = DAT_004f7ec4;
        goto override_prt_481cc6_6059bb06;
      }
    }
  }
  if (param_8 == 6) {
    uVar6 = (int)(param_2 + DAT_004fad34) / 3;
    uVar5 = (int)uVar6 >> 0x1f;
    if (((uVar6 ^ uVar5) - uVar5 & 3 ^ uVar5) == uVar5) {
      if (DAT_004f3864 != (HGDIOBJ)0x0) {
        (*pcVar8)((HDC)original_dc[1],DAT_004f3864);
      }
      if ((DAT_00536450 != 1) || (DAT_004fb994 == (HGDIOBJ)0x0)) goto LAB_00481d7f;
      pHVar11 = (HDC)original_dc[1];
      pvVar12 = DAT_004fb994;
    }
    else {
      if (DAT_005233b4 != (HGDIOBJ)0x0) {
        (*pcVar8)((HDC)original_dc[1],DAT_005233b4);
      }
      if ((DAT_00536450 != 1) || (DAT_004f1cec == (HGDIOBJ)0x0)) goto LAB_00481d7f;
      pHVar11 = (HDC)original_dc[1];
      pvVar12 = DAT_004f1cec;
    }
    (*pcVar8)(pHVar11,pvVar12);
  }
LAB_00481d7f:
  if (param_8 == 5) {
    (*pcVar1)(original_dc,0);
    if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
      (*pcVar8)((HDC)original_dc[1],DAT_004f7ec4);
    }
    FUN_00433a70(original_dc,iVar3,param_4,param_10 - iVar3);
    return;
  }
  iVar9 = 5;
  if (param_9 != 1) {
    iVar9 = 10;
  }
  iVar9 = (DAT_004fb9b8 + param_2 * 2) % iVar9;
  if (param_9 == -1) {
    uVar6 = (int)DAT_004fad34 >> 0x1f;
    iVar9 = ((DAT_004fad34 ^ uVar6) - uVar6 & 1 ^ uVar6) - uVar6;
  }
  if (iVar9 == 0) {
    (*pcVar1)(original_dc,8);
    FUN_00433a70(original_dc,iVar3,param_4 + 1,param_10 - iVar2 / 0xf);
    return;
  }
  FUN_00469650(original_dc);
  Rectangle((HDC)original_dc[1],param_6,param_10 - iVar2 / 0xf,iVar4,iVar7);
  return;
}

