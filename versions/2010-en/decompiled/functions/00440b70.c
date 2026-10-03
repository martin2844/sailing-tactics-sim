
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00440b70(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11,int param_12,int param_13)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  COLORREF CVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  HDC pHVar12;
  HGDIOBJ pvVar13;
  int local_34;
  int aiStack_10 [2];
  int aiStack_8 [2];
  
  iVar2 = param_3;
  if (DAT_0050040c == 1) {
    iVar2 = FUN_0041bc20(DAT_005230dc * 0x5a + -0x5a);
  }
  if (DAT_0050040c == 0) {
    fVar11 = (float10)fpatan((float10)((&DAT_004fb6b8)[param_7] - DAT_00535bc8),
                             (float10)(DAT_004f3858 - (&DAT_004fbc38)[param_7]));
    iVar2 = FUN_0041bc20((int)(longlong)(fVar11 * (float10)_DAT_004cc3e8));
    if (DAT_004f8b78 == 1) {
      iVar2 = FUN_0041bc20(iVar2 + 0xb4);
      iVar2 = FUN_0041bc20(iVar2);
    }
  }
  iVar3 = FUN_0041bc20(DAT_005362d4 - iVar2);
  if (iVar3 < 0x5a) {
LAB_00440c50:
    local_34 = 1;
  }
  else {
    iVar3 = FUN_0041bc20(DAT_005362d4 - iVar2);
    local_34 = 0;
    if (0x10e < iVar3) goto LAB_00440c50;
  }
  iVar3 = FUN_0041bc20(DAT_005362d4 - iVar2);
  if ((iVar3 < 0x4b) || (iVar3 = FUN_0041bc20(DAT_005362d4 - iVar2), 0x11d < iVar3)) {
    local_34 = 2;
  }
  iVar3 = FUN_0041bc20(DAT_005362d4 - iVar2);
  if ((iVar3 < 0x3c) || (iVar2 = FUN_0041bc20(DAT_005362d4 - iVar2), 300 < iVar2)) {
    local_34 = 3;
  }
  if (((DAT_004f8b78 == 1) && (param_3 < param_13)) && (param_5 < param_13)) {
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
  if ((DAT_004da19c == 2) && (0x11 < param_7)) {
    return;
  }
  if ((DAT_004da19c == 4) && (param_7 < 0x13)) {
    return;
  }
  if (DAT_004da19c == 0xb) {
    if (0x23 < param_7) {
      return;
    }
    if (param_7 < 2) {
      return;
    }
    if ((0xd < param_7) && (param_7 < 0x14)) {
      return;
    }
  }
  if (DAT_004f8db8 == 1) {
    if ((6 < param_7) && (param_7 < 0xc)) {
      return;
    }
    if ((0x18 < param_7) && (param_7 < 0x1e)) {
      return;
    }
  }
  if ((param_11 < param_3) && (param_11 < param_5)) {
    return;
  }
  CVar4 = GetPixel((HDC)param_1[1],param_2,param_3 + 2);
  if (CVar4 == 0x8000) {
    return;
  }
  CVar4 = GetPixel((HDC)param_1[1],param_4,param_5 + 2);
  if (CVar4 == 0x8000) {
    return;
  }
  CVar4 = GetPixel((HDC)param_1[1],param_2,param_3 + 1);
  if (CVar4 == 0x8000) {
    return;
  }
  CVar4 = GetPixel((HDC)param_1[1],param_4,param_5 + 1);
  if (CVar4 == 0x8000) {
    return;
  }
  iVar2 = (param_11 - param_12) * (3 - DAT_005359d8);
  iVar3 = ((&DAT_00512d70)[param_7] * (param_3 - param_12)) / iVar2 + 1;
  iVar2 = ((&DAT_00512d74)[param_7] * (param_5 - param_12)) / iVar2 + 1;
  if (DAT_004f8b78 == 0) {
    if ((DAT_005363e4 == 0) && (DAT_00536450 == 0)) {
      (**(code **)(*param_1 + 0x2c))(param_1,8);
      if (DAT_005363a4 != (HGDIOBJ)0x0) {
        pHVar12 = (HDC)param_1[1];
        pvVar13 = DAT_005363a4;
override_prt_440ee3_6059bb06:
        SelectObject(pHVar12,pvVar13);
      }
    }
    else {
      if (DAT_004fe174 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe174);
      }
      if (DAT_004fe07c != (HGDIOBJ)0x0) {
        pHVar12 = (HDC)param_1[1];
        pvVar13 = DAT_004fe07c;
        goto override_prt_440ee3_6059bb06;
      }
    }
    if ((DAT_00536450 == 1) &&
       ((**(code **)(*param_1 + 0x2c))(param_1,8), DAT_005230cc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
    _DAT_004f6e28 = param_2;
    _DAT_004f6e30 = param_2;
    _DAT_004f6e34 = param_6;
    _DAT_004f6e3c = param_6;
    _DAT_004f6e2c = param_3 - iVar3;
    _DAT_004f6e44 = param_5 - iVar2;
    _DAT_004f6e38 = param_4;
    _DAT_004f6e40 = param_4;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    if (((DAT_004f8b78 == 0) && (DAT_005363e0 == 0)) && (DAT_004da174 < 0xd)) {
      iVar6 = DAT_004fe2a8 / 0x96 + param_12;
      iVar7 = DAT_004fe2a8 / 0x50 + param_12;
      if (DAT_004f7084 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f7084);
      }
      if ((iVar6 < param_3) && (iVar6 < param_5)) {
        uVar8 = param_7 >> 0x1f;
        if ((DAT_004da174 < 0xc) && (DAT_005363e0 == 0)) {
          iVar5 = (-(uint)(((param_7 ^ uVar8) - uVar8 & 1 ^ uVar8) - uVar8 != 1) & 0xfffffffe) + 0xe
          ;
          if (param_7 % 3 == 1) {
            iVar5 = 0x10;
          }
        }
        else {
          iVar5 = 7 - (uint)(((param_7 ^ uVar8) - uVar8 & 1 ^ uVar8) - uVar8 != 1);
          if (param_7 % 3 == 1) {
            iVar5 = 8;
          }
        }
        if (1 < iVar5) {
          param_10 = iVar5 + -1;
          param_7 = (int)&DAT_00512d78;
          do {
            iVar10 = param_2 - (int)(longlong)
                                    ((double)*(int *)(param_7 + -4) * (double)(param_4 - param_2) *
                                    _DAT_004cc678);
            iVar5 = (int)(longlong)
                         ((double)(iVar10 - param_2) *
                         ((double)((param_5 - iVar2) - (param_3 - iVar3)) /
                         (double)(param_4 - param_2))) + (param_3 - iVar3);
            iVar9 = iVar5 - (int)(longlong)
                                 ((double)((DAT_004fe2a8 / 100 - param_12) + iVar5) *
                                  (double)*(int *)param_7 * _DAT_004cc3f0);
            if (iVar6 < iVar9) {
              if (iVar9 < iVar7) {
                if ((iVar9 < iVar5) && (DAT_004f8b78 == 0)) {
                  FUN_004b4d9d(param_1,aiStack_10,iVar10,iVar9);
                  CDC::LineTo(param_1,iVar10,iVar9 + -1);
                }
                goto LAB_00441172;
              }
LAB_00441178:
              if (iVar9 < iVar5) {
                FUN_004b4d9d(param_1,aiStack_8,iVar10 + -1,iVar9);
                CDC::LineTo(param_1,iVar10,iVar9 + -2);
                CDC::LineTo(param_1,iVar10 + 1,iVar9);
              }
            }
            else {
LAB_00441172:
              if (iVar7 <= iVar9) goto LAB_00441178;
            }
            param_7 = param_7 + 4;
            param_10 = param_10 + -1;
          } while (param_10 != 0);
        }
      }
    }
  }
  pcVar1 = *(code **)(*param_1 + 0x2c);
  (*pcVar1)(param_1,8);
  if (((DAT_005359d8 == 1) || (DAT_005363e4 == 1)) || (DAT_00536450 == 1)) {
    if (DAT_004fe07c != (HGDIOBJ)0x0) {
      pHVar12 = (HDC)param_1[1];
      pvVar13 = DAT_004fe07c;
      goto override_prt_44122f_6059bb06;
    }
  }
  else if (DAT_004f7f74 != (HGDIOBJ)0x0) {
    pHVar12 = (HDC)param_1[1];
    pvVar13 = DAT_004f7f74;
override_prt_44122f_6059bb06:
    SelectObject(pHVar12,pvVar13);
  }
  if ((DAT_005363e4 == 1) && (DAT_004f3f5c != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004f3f5c);
  }
  _DAT_004f6e28 = param_2;
  _DAT_004f6e2c = param_3;
  _DAT_004f6e30 = param_2;
  _DAT_004f6e34 = param_3 - iVar3;
  _DAT_004f6e3c = param_5 - iVar2;
  _DAT_004f6e38 = param_4;
  _DAT_004f6e40 = param_4;
  _DAT_004f6e44 = param_5;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  if ((local_34 == 0) || (DAT_00536450 != 0)) {
    (*pcVar1)(param_1,6);
    FUN_004b4d9d(param_1,aiStack_8,param_2,param_3 + 1);
    CDC::LineTo(param_1,param_4,param_5 + 1);
    return;
  }
  (*pcVar1)(param_1,8);
  if (DAT_005363e4 == 0) {
    if (DAT_004f71b4 == (HGDIOBJ)0x0) goto LAB_00441312;
    pHVar12 = (HDC)param_1[1];
    pvVar13 = DAT_004f71b4;
  }
  else {
    if (DAT_004fe07c == (HGDIOBJ)0x0) goto LAB_00441312;
    pHVar12 = (HDC)param_1[1];
    pvVar13 = DAT_004fe07c;
  }
  SelectObject(pHVar12,pvVar13);
LAB_00441312:
  _DAT_004f6e2c = param_3;
  _DAT_004f6e28 = param_2;
  _DAT_004f6e30 = param_2;
  _DAT_004f6e44 = param_5;
  _DAT_004f6e34 = (local_34 * iVar3 * 2) / 3 + param_3;
  _DAT_004f6e38 = param_4;
  _DAT_004f6e3c = (local_34 * iVar2 * 2) / 3 + param_5;
  _DAT_004f6e40 = param_4;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  return;
}

