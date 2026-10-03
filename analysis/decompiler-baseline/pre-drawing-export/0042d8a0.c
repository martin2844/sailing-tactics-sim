
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0042d8a0(CDC *param_1,int param_2,int param_3,int param_4,int param_5,CDC *param_6,
            undefined4 *param_7,int param_8,undefined4 param_9,int param_10,int param_11,
            int param_12,int param_13)

{
  CDC *this;
  int iVar1;
  int iVar2;
  COLORREF CVar3;
  int unaff_EBX;
  CDC *pCVar4;
  CDC *pCVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  HDC pHVar9;
  HGDIOBJ pvVar10;
  int local_2c;
  int aiStack_10 [2];
  int aiStack_8 [2];
  
  this = param_1;
  iVar1 = param_3;
  if (DAT_004a864c == 1) {
    iVar1 = FUN_00413cb0(DAT_004aa804 * 0x5a + -0x5a);
  }
  if (DAT_004a864c == 0) {
    fVar8 = (float10)fpatan((float10)((&DAT_004a6490)[(int)param_7] - DAT_004ac284),
                            (float10)(DAT_004a3a08 - (&DAT_004a68c8)[(int)param_7]));
    iVar1 = FUN_00413cb0((int)(longlong)(fVar8 * (float10)_DAT_00484d78));
    if (DAT_004a5a4c == 1) {
      iVar1 = FUN_00413cb0(iVar1 + 0xb4);
      iVar1 = FUN_00413cb0(iVar1);
    }
  }
  iVar2 = FUN_00413cb0(DAT_004ac840 - iVar1);
  if (iVar2 < 0x5a) {
LAB_0042d980:
    local_2c = 1;
  }
  else {
    iVar2 = FUN_00413cb0(DAT_004ac840 - iVar1);
    local_2c = 0;
    if (0x10e < iVar2) goto LAB_0042d980;
  }
  iVar2 = FUN_00413cb0(DAT_004ac840 - iVar1);
  if ((iVar2 < 0x4b) || (iVar2 = FUN_00413cb0(DAT_004ac840 - iVar1), 0x11d < iVar2)) {
    local_2c = 2;
  }
  iVar2 = FUN_00413cb0(DAT_004ac840 - iVar1);
  if ((iVar2 < 0x3c) || (iVar1 = FUN_00413cb0(DAT_004ac840 - iVar1), 300 < iVar1)) {
    local_2c = 3;
  }
  if (((DAT_004a5a4c == 1) && (param_3 < param_13)) && (param_5 < param_13)) {
    return;
  }
  if ((param_2 < param_8) && (param_4 < param_8)) {
    return;
  }
  if ((param_10 < param_2) && (param_10 < param_4)) {
    return;
  }
  if ((param_3 <= param_12) && (param_5 <= param_12)) {
    return;
  }
  if ((DAT_00491194 == 2) && (0x11 < (int)param_7)) {
    return;
  }
  if ((DAT_00491194 == 4) && ((int)param_7 < 0x13)) {
    return;
  }
  if (DAT_00491194 == 0xb) {
    if (0x23 < (int)param_7) {
      return;
    }
    if ((int)param_7 < 2) {
      return;
    }
    if ((0xd < (int)param_7) && ((int)param_7 < 0x14)) {
      return;
    }
  }
  if (DAT_004a5b9c == 1) {
    if ((6 < (int)param_7) && ((int)param_7 < 0xc)) {
      return;
    }
    if ((0x18 < (int)param_7) && ((int)param_7 < 0x1e)) {
      return;
    }
  }
  if ((param_11 < param_3) && (param_11 < param_5)) {
    return;
  }
  CVar3 = GetPixel(*(HDC *)(param_1 + 4),param_2,param_3 + 2);
  if (CVar3 == 0x8000) {
    return;
  }
  CVar3 = GetPixel(*(HDC *)(param_1 + 4),param_4,param_5 + 2);
  if (CVar3 == 0x8000) {
    return;
  }
  CVar3 = GetPixel(*(HDC *)(param_1 + 4),param_2,param_3 + 1);
  if (CVar3 == 0x8000) {
    return;
  }
  CVar3 = GetPixel(*(HDC *)(param_1 + 4),param_4,param_5 + 1);
  if (CVar3 == 0x8000) {
    return;
  }
  iVar2 = (param_11 - param_12) * (3 - DAT_004ac1e0);
  iVar1 = ((&DAT_004a9450)[(int)param_7] * (param_3 - param_12)) / iVar2 + 1;
  iVar2 = ((&DAT_004a9454)[(int)param_7] * (param_5 - param_12)) / iVar2 + 1;
  pCVar5 = param_1;
  if (DAT_004a5a4c == 0) {
    if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
      (**(code **)(*(int *)param_1 + 0x2c))(8);
      if (DAT_004a621c != (HGDIOBJ)0x0) {
        pHVar9 = *(HDC *)(param_1 + 4);
        pvVar10 = DAT_004a621c;
LAB_0042dc18:
        SelectObject(pHVar9,pvVar10);
      }
    }
    else {
      if (DAT_004a71bc != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a71bc);
      }
      if (DAT_004a70e4 != (HGDIOBJ)0x0) {
        pHVar9 = *(HDC *)(param_1 + 4);
        pvVar10 = DAT_004a70e4;
        goto LAB_0042dc18;
      }
    }
    if ((DAT_004ac98c == 1) &&
       ((**(code **)(*(int *)param_1 + 0x2c))(8), DAT_004aa7f4 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004aa7f4);
    }
    _DAT_004a4cac = (CDC *)(param_3 - iVar1);
    _DAT_004a4ca8 = param_2;
    _DAT_004a4cb4 = param_6;
    _DAT_004a4cbc = param_6;
    _DAT_004a4cc4 = param_5 - iVar2;
    _DAT_004a4cb0 = param_2;
    _DAT_004a4cb8 = param_4;
    _DAT_004a4cc0 = param_4;
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,4);
    if (((DAT_004a5a4c == 0) && (DAT_004ac928 == 0)) && (DAT_0049116c < 0xd)) {
      pCVar5 = (CDC *)(param_3 - iVar1);
      iVar1 = DAT_004a72d0 / 0x96 + param_12;
      param_11 = DAT_004a72d0 / 0x50 + param_12;
      if (DAT_004a4dec != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
      }
      if ((iVar1 < param_3) && (iVar1 < param_5)) {
        param_7 = &DAT_004a9458;
        do {
          iVar7 = param_2 - (int)(longlong)
                                 ((double)(int)param_7[-1] * (double)(param_4 - param_2) *
                                 _DAT_00484e28);
          pCVar4 = pCVar5 + (int)(longlong)
                                 ((double)(iVar7 - param_2) *
                                 ((double)((param_5 - iVar2) - (int)pCVar5) /
                                 (double)(param_4 - param_2)));
          param_6 = pCVar4 + (DAT_004a72d0 / 100 - param_12);
          iVar6 = (int)pCVar4 -
                  (int)(longlong)((double)(int)param_6 * (double)(int)*param_7 * _DAT_00484cc8);
          if (iVar1 < iVar6) {
            if (iVar6 < param_11) {
              if ((iVar6 < (int)pCVar4) && (DAT_004a5a4c == 0)) {
                FUN_004706bd(param_1,aiStack_10,iVar7,iVar6);
                CDC::LineTo(param_1,iVar7,iVar6 + -1);
              }
              goto LAB_0042de28;
            }
LAB_0042de2e:
            if (iVar6 < (int)pCVar4) {
              FUN_004706bd(param_1,aiStack_8,iVar7 + -1,iVar6);
              CDC::LineTo(param_1,iVar7,iVar6 + -2);
              CDC::LineTo(param_1,iVar7 + 1,iVar6);
            }
          }
          else {
LAB_0042de28:
            if (param_11 <= iVar6) goto LAB_0042de2e;
          }
          param_7 = param_7 + 1;
        } while ((int)param_7 < 0x4a946c);
      }
    }
  }
  param_1 = pCVar5;
  (**(code **)(*(int *)this + 0x2c))(8);
  if (((DAT_004ac1e0 == 1) || (DAT_004ac92c == 1)) || (DAT_004ac98c == 1)) {
    if (DAT_004a70e4 != (HGDIOBJ)0x0) {
      pHVar9 = *(HDC *)(this + 4);
      pvVar10 = DAT_004a70e4;
      goto LAB_0042dedf;
    }
  }
  else if (DAT_004a4f7c != (HGDIOBJ)0x0) {
    pHVar9 = *(HDC *)(this + 4);
    pvVar10 = DAT_004a4f7c;
LAB_0042dedf:
    SelectObject(pHVar9,pvVar10);
  }
  if ((DAT_004ac92c == 1) && (DAT_004a3efc != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(this + 4),DAT_004a3efc);
  }
  _DAT_004a4cac = (CDC *)param_2;
  _DAT_004a4cb4 = (CDC *)(param_2 - param_12);
  _DAT_004a4cbc = (CDC *)(param_5 - iVar2);
  _DAT_004a4cb8 = param_3;
  _DAT_004a4cc0 = param_3;
  _DAT_004a4ca8 = param_2;
  _DAT_004a4cb0 = param_2;
  _DAT_004a4cc4 = param_5;
  Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,4);
  if ((unaff_EBX < 1) || (DAT_004ac98c != 0)) {
    (*(code *)param_6)(6);
    FUN_004706bd(this,aiStack_10,param_2,unaff_EBX);
    CDC::LineTo(this,param_2,local_2c);
    return;
  }
  (*(code *)param_6)(8);
  if (DAT_004ac92c == 0) {
    if (DAT_004a8e04 == (HGDIOBJ)0x0) goto LAB_0042dfc8;
    pHVar9 = *(HDC *)(this + 4);
    pvVar10 = DAT_004a8e04;
  }
  else {
    if (DAT_004a70e4 == (HGDIOBJ)0x0) goto LAB_0042dfc8;
    pHVar9 = *(HDC *)(this + 4);
    pvVar10 = DAT_004a70e4;
  }
  SelectObject(pHVar9,pvVar10);
LAB_0042dfc8:
  _DAT_004a4cac = param_1;
  _DAT_004a4cb4 = param_1 + (unaff_EBX * param_11 * 2) / 3;
  _DAT_004a4cbc = (CDC *)((unaff_EBX * (int)param_6 * 2) / 3 + param_5);
  _DAT_004a4cb8 = param_2;
  _DAT_004a4cc0 = param_2;
  _DAT_004a4ca8 = param_2;
  _DAT_004a4cb0 = param_2;
  _DAT_004a4cc4 = param_5;
  Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,4);
  return;
}

