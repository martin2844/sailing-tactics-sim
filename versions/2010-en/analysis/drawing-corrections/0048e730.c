
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0048e730(int *param_1,int param_2,double param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
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
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  code *pcVar24;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int local_44;
  int local_18;
  int local_14;
  int aiStack_8 [2];
  
  if ((DAT_00536450 != 1) || (param_2 < 2)) {
    iVar6 = DAT_00522900 + DAT_005228f8 + DAT_005228fc + DAT_00522904;
    iVar7 = DAT_00522a00 + DAT_005229f8 + DAT_005229fc + DAT_00522a04;
    iVar8 = DAT_00522914 + DAT_0052291c + DAT_00522920 + DAT_00522918;
    iVar9 = DAT_00522a14 + DAT_00522a1c + DAT_00522a20 + DAT_00522a18;
    iVar10 = (DAT_00522918 + DAT_00522914) / 2;
    iVar11 = (DAT_00522a18 + DAT_00522a14) / 2;
    iVar12 = (DAT_00522904 + DAT_00522900) / 2;
    iVar13 = (DAT_00522a04 + DAT_00522a00) / 2;
    iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;
    iVar23 = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
    iVar8 = (int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2;
    iVar7 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
    if (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) {
      local_14 = (DAT_005228f8 + iVar6 * 4 + iVar8) / 6;
      local_18 = (DAT_005229f8 + iVar23 * 4 + iVar7) / 6;
    }
    else {
      local_14 = (DAT_0052291c + iVar8 * 5 + iVar6) / 7;
      local_18 = (DAT_00522a1c + iVar7 * 5 + iVar23) / 7;
    }
    iVar9 = DAT_0052291c + (iVar6 + iVar8) * 3 + DAT_005228f8;
    iVar14 = DAT_00522a1c + (iVar23 + iVar7) * 3 + DAT_005229f8;
    iVar14 = (int)(iVar14 + (iVar14 >> 0x1f & 7U)) >> 3;
    iVar15 = (param_4 ^ param_4 >> 0x1f) - (param_4 >> 0x1f);
    iVar9 = (int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3;
    if (0x5a < iVar15) {
      FUN_0048f650(param_1,param_3,param_2,local_14,local_18,iVar9,iVar14,param_4);
    }
    pcVar2 = *(code **)(*param_1 + 0x2c);
    (*pcVar2)(param_1,7);
    iVar18 = (int)(longlong)(param_3 * _DAT_004cc778);
    iVar21 = (iVar18 * 10) / DAT_004faa48 + iVar18 / 2;
    iVar18 = (iVar21 * 3) / 5;
    iVar3 = (iVar7 + iVar23 * 6 + iVar21 * -7) / 7;
    iVar4 = (iVar8 + iVar6 * 6) / 7;
    iVar5 = (iVar23 + iVar7 * 6 + iVar21 * -7) / 7;
    iVar21 = (iVar6 + iVar8 * 6) / 7;
    iVar16 = iVar5 + iVar11 * 6 + iVar13 + iVar18 * -7;
    iVar16 = (int)(iVar16 + (iVar16 >> 0x1f & 7U)) >> 3;
    iVar17 = iVar8 + iVar10 * 6 + iVar12;
    iVar17 = (int)(iVar17 + (iVar17 >> 0x1f & 7U)) >> 3;
    iVar18 = iVar3 + iVar13 * 6 + iVar11 + iVar18 * -7;
    iVar18 = (int)(iVar18 + (iVar18 >> 0x1f & 7U)) >> 3;
    iVar19 = iVar6 + iVar12 * 6 + iVar10;
    iVar19 = (int)(iVar19 + (iVar19 >> 0x1f & 7U)) >> 3;
    if (DAT_00536450 == 0) {
      (*pcVar2)(param_1,0);
    }
    else if (DAT_004f3f5c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f3f5c);
    }
    if (-0x14 < param_4) {
      _DAT_004f6e28 = iVar6;
      _DAT_004f6e2c = iVar23;
      _DAT_004f6e30 = iVar12;
      _DAT_004f6e34 = iVar13;
      _DAT_004f6e38 = iVar19;
      _DAT_004f6e3c = iVar18;
      _DAT_004f6e40 = iVar4;
      _DAT_004f6e44 = iVar3;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
      iStack_54 = (iVar3 + iVar23) / 2;
      iStack_4c = (iVar4 + iVar6) / 2;
      iStack_50 = (iVar19 + iVar12) / 2;
      iVar22 = (iVar18 + iVar13) / 2;
      if (DAT_004f7084 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f7084);
      }
      iVar1 = iStack_54 + iVar22 * 3;
      iVar20 = iStack_50 + iStack_4c + iStack_50 * 2;
      FUN_004b4d9d(param_1,aiStack_8,(int)(iVar20 + (iVar20 >> 0x1f & 3U)) >> 2,
                   (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2);
      CDC::LineTo(param_1,((iStack_4c + iStack_50 * 2) * 2) / 6,((iStack_54 + iVar22 * 2) * 2) / 6);
      FUN_004b4d9d(param_1,aiStack_8,((iStack_50 + iStack_4c * 2) * 2) / 6,
                   ((iVar22 + iStack_54 * 2) * 2) / 6);
      CDC::LineTo(param_1,(iStack_4c + iStack_50 + iStack_4c * 4) / 6,(iVar22 + iStack_54 * 5) / 6);
      (*pcVar2)(param_1,7);
    }
    if ((param_4 < 0x14) || (0xa0 < param_4)) {
      _DAT_004f6e28 = iVar8;
      _DAT_004f6e2c = iVar7;
      _DAT_004f6e30 = iVar10;
      _DAT_004f6e34 = iVar11;
      _DAT_004f6e38 = iVar17;
      _DAT_004f6e3c = iVar16;
      _DAT_004f6e40 = iVar21;
      _DAT_004f6e44 = iVar5;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
      iStack_54 = (iVar5 + iVar7) / 2;
      iStack_4c = (iVar21 + iVar8) / 2;
      iStack_50 = (iVar17 + iVar10) / 2;
      iVar22 = (iVar16 + iVar11) / 2;
      if (DAT_004f7084 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f7084);
      }
      iVar1 = iStack_54 + iVar22 * 3;
      iVar20 = iStack_50 + iStack_4c + iStack_50 * 2;
      FUN_004b4d9d(param_1,aiStack_8,(int)(iVar20 + (iVar20 >> 0x1f & 3U)) >> 2,
                   (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2);
      CDC::LineTo(param_1,((iStack_4c + iStack_50 * 2) * 2) / 6,((iStack_54 + iVar22 * 2) * 2) / 6);
      FUN_004b4d9d(param_1,aiStack_8,((iStack_50 + iStack_4c * 2) * 2) / 6,
                   ((iVar22 + iStack_54 * 2) * 2) / 6);
      CDC::LineTo(param_1,(iStack_4c + iStack_50 + iStack_4c * 4) / 6,(iVar22 + iStack_54 * 5) / 6);
      (*pcVar2)(param_1,7);
    }
    pcVar24 = Polygon_exref;
    local_44 = iVar23;
    if (iVar15 < 0x5a) {
      _DAT_004f6e28 = iVar8;
      _DAT_004f6e2c = iVar7;
      _DAT_004f6e30 = iVar21;
      _DAT_004f6e34 = iVar5;
      _DAT_004f6e38 = iVar4;
      _DAT_004f6e3c = iVar3;
      _DAT_004f6e40 = iVar6;
      _DAT_004f6e44 = iVar23;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
      if (DAT_005363b8 == 1) {
        iStack_54 = (iVar4 + (iVar21 + iVar8) * 4 + iVar6) / 10;
        iStack_50 = (iVar3 + (iVar5 + iVar7) * 4 + iVar23) / 10;
        iStack_4c = (iVar21 + (iVar4 + iVar6) * 4 + iVar8) / 10;
        local_44 = (iVar5 + (iVar3 + iVar23) * 4 + iVar7) / 10;
      }
      _DAT_004f6e28 = (iVar8 * 3 + iVar6 * 2) / 5;
      _DAT_004f6e2c = (iVar7 * 3 + iVar23 * 2) / 5;
      _DAT_004f6e30 = (iVar4 + iVar21 * 2) / 3;
      _DAT_004f6e34 = (iVar3 + iVar5 * 2) / 3;
      _DAT_004f6e38 = (iVar21 + iVar4 * 2) / 3;
      _DAT_004f6e3c = (iVar5 + iVar3 * 2) / 3;
      _DAT_004f6e40 = (iVar6 * 3 + iVar8 * 2) / 5;
      _DAT_004f6e44 = (iVar23 * 3 + iVar7 * 2) / 5;
      (*pcVar2)(param_1,4);
      pcVar24 = Polygon_exref;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    }
    if (0x32 < iVar15) {
      _DAT_004f6e28 = iVar10;
      _DAT_004f6e2c = iVar11;
      _DAT_004f6e30 = iVar17;
      _DAT_004f6e34 = iVar16;
      _DAT_004f6e40 = iVar12;
      _DAT_004f6e44 = iVar13;
      if (DAT_00536450 == 0) {
        _DAT_004f6e38 = iVar19;
        _DAT_004f6e3c = iVar18;
        (*pcVar2)(param_1,0);
      }
      else {
        _DAT_004f6e38 = iVar19;
        _DAT_004f6e3c = iVar18;
        if (DAT_004f3f5c != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004f3f5c);
        }
      }
      (*pcVar24)((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    }
    _DAT_004f6e28 = iVar21;
    _DAT_004f6e2c = iVar5;
    _DAT_004f6e30 = iVar4;
    _DAT_004f6e34 = iVar3;
    _DAT_004f6e40 = iVar17;
    _DAT_004f6e44 = iVar16;
    if (DAT_00536450 == 0) {
      _DAT_004f6e38 = iVar19;
      _DAT_004f6e3c = iVar18;
      (*pcVar2)(param_1,0);
    }
    else {
      _DAT_004f6e38 = iVar19;
      _DAT_004f6e3c = iVar18;
      if (DAT_004f3f5c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f3f5c);
      }
    }
    (*pcVar24)((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    _DAT_004f6e40 = (iVar21 + iVar4 * 2) / 3;
    _DAT_004f6e44 = (iVar5 + iVar3 * 2) / 3;
    _DAT_004f6e28 = (iVar4 + iVar21 * 2) / 3;
    _DAT_004f6e2c = (iVar3 + iVar5 * 2) / 3;
    _DAT_004f6e30 = (DAT_005228f4 + _DAT_004f6e28 * 10) / 0xb;
    _DAT_004f6e34 = (DAT_005229f4 + _DAT_004f6e2c * 10) / 0xb;
    _DAT_004f6e38 = (DAT_005228f4 + _DAT_004f6e40 * 10) / 0xb;
    _DAT_004f6e3c = (DAT_005229f4 + _DAT_004f6e44 * 10) / 0xb;
    (*pcVar2)(param_1,4);
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    if ((iVar15 < 0x5a) && (DAT_004da14c == 1)) {
      FUN_0048f420(param_1,param_3,1,0xffffffff,iStack_4c,local_44,param_4);
      FUN_0048f420(param_1,param_3,1,1,iStack_54,iStack_50,param_4);
    }
    DAT_00522aec = DAT_00522900;
    DAT_00534f48 = DAT_00522a00;
    DAT_004fba08 = DAT_00522914;
    DAT_00522fb4 = DAT_00522a14;
    if (iVar15 < 0x5b) {
      FUN_0048f650(param_1,param_3,param_2,local_14,local_18,iVar9,iVar14,param_4);
    }
  }
  return;
}

