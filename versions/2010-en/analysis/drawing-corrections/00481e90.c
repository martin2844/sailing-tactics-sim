
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00481e90(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  COLORREF CVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  double local_58;
  int local_4c [5];
  int aiStack_38 [5];
  int aiStack_24 [5];
  int local_10 [4];
  
  iVar10 = 0;
  if (((((-1 < param_2) && (param_2 <= DAT_004fe624)) && (param_3 <= DAT_00535564)) &&
      ((CVar2 = GetPixel((HDC)param_1[1],param_2,param_3), CVar2 != 0xff0000 &&
       (CVar2 = GetPixel((HDC)param_1[1],param_2,param_3 + 4), CVar2 != 0xff0000)))) &&
     (param_3 <= (DAT_004fe2a8 * 2) / 3)) {
    if (param_4 == 1) {
      iVar10 = 0x1e;
    }
    if (param_4 == 2) {
      iVar10 = 0;
    }
    if (param_4 == 3) {
      iVar10 = 0x46;
    }
    if (param_4 == 4) {
      iVar10 = 0x14;
    }
    if (DAT_004da1f8 == 7) {
      iVar10 = 0;
    }
    if (DAT_004da1f8 == 0xc) {
      iVar10 = -0x1e;
    }
    if (DAT_004da1f8 == 9) {
      iVar10 = 0x1e;
    }
    if (DAT_004fb5d4 == 1) {
      iVar10 = 0;
    }
    local_10[0] = 0x1e;
    local_10[1] = 0x96;
    local_10[2] = 0xffffff6a;
    local_10[3] = 0xffffffe2;
    local_4c[0] = 0x1b;
    local_4c[1] = 0x1b;
    local_4c[2] = 0x1b;
    local_4c[3] = 0x1b;
    if ((param_4 == 6) || (param_4 == 0x10)) {
      local_4c[0] = 0x30;
      local_4c[1] = 0x30;
      local_4c[2] = 0x30;
      local_4c[3] = 0x30;
    }
    if (param_4 == 5) {
      local_4c[0] = 0x23;
      local_4c[1] = 0x23;
      local_4c[2] = 0x23;
      local_4c[3] = 0x23;
    }
    if (param_4 == 7) {
      local_4c[0] = 0x96;
      local_4c[1] = 0x96;
      local_4c[2] = 0x96;
      local_4c[3] = 0x96;
    }
    fVar15 = (float10)FUN_00406220(param_3,param_5);
    local_58 = (double)(fVar15 * (float10)_DAT_004cc538);
    if ((DAT_004da1f8 == 7) && (((param_4 == 1 || (param_4 == 4)) || (param_4 == 5)))) {
      fVar15 = (float10)FUN_00406220(param_3,param_5);
      local_58 = (double)(fVar15 * (float10)_DAT_004ccff8);
    }
    if ((DAT_004da1f8 == 0xc) || (DAT_004da1f8 == 100)) {
      fVar15 = (float10)FUN_00406220(param_3,param_5);
      local_58 = (double)(fVar15 * (float10)_DAT_004cc400);
    }
    if (param_4 == 6) {
      _DAT_004f6e38 = (int)(longlong)(local_58 * _DAT_004cc838);
      _DAT_004f6e2c = param_3;
      _DAT_004f6e28 = param_2 - _DAT_004f6e38;
      _DAT_004f6e30 = param_2;
      _DAT_004f6e34 = param_3 + _DAT_004f6e38 * -5;
      _DAT_004f6e38 = _DAT_004f6e38 + param_2;
      _DAT_004f6e3c = param_3;
      pcVar1 = *(code **)(*param_1 + 0x2c);
      (*pcVar1)(param_1,7);
      (*pcVar1)(param_1,0);
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,3);
    }
    FUN_0043ec20((double)param_2,(double)param_3,1,param_5);
    iVar3 = FUN_0041bc20(DAT_004f4b40 - iVar10);
    FUN_0041e3a0(iVar3);
    iVar3 = FUN_0041e3a0(*(int *)(&DAT_004f49a0 + param_5 * 4));
    iVar8 = DAT_00535744 - iVar3;
    *(int *)(&DAT_004f49a0 + param_5 * 4) = iVar3;
    iVar3 = FUN_0041bc20(iVar8);
    FUN_0041e3a0(iVar10 - iVar3);
    iVar10 = FUN_0041bc20(iVar10 - iVar3);
    param_5 = iVar10;
    if (0xb4 < iVar10) {
      param_5 = iVar10 + -0x168;
    }
    piVar11 = aiStack_38;
    piVar14 = aiStack_24;
    iVar3 = 0;
    do {
      iVar8 = FUN_0041e3a0(*(int *)((int)local_10 + iVar3) + iVar10);
      fVar15 = (float10)*(int *)((int)local_4c + iVar3) * (float10)local_58;
      fVar16 = (float10)fsin((float10)iVar8 * (float10)_DAT_004cc568);
      fVar17 = (float10)fcos((float10)iVar8 * (float10)_DAT_004cc568);
      *piVar14 = (int)(longlong)(fVar16 * fVar15) + param_2;
      iVar3 = iVar3 + 4;
      piVar14 = piVar14 + 1;
      *piVar11 = param_3 - (int)(longlong)(fVar17 * fVar15 * (float10)_DAT_004cc570);
      piVar11 = piVar11 + 1;
    } while (iVar3 < 0xd);
    pcVar1 = *(code **)(*param_1 + 0x2c);
    (*pcVar1)(param_1,7);
    iVar10 = (int)(longlong)(local_58 * _DAT_004cca20);
    uVar9 = param_4 >> 0x1f;
    uVar4 = (param_4 ^ uVar9) - uVar9 & 1 ^ uVar9;
    if (uVar4 == uVar9) {
      iVar3 = (iVar10 * 3) / 2;
    }
    else {
      iVar3 = (iVar10 * 4) / 3;
    }
    iVar3 = (iVar3 * 3) / 2;
    if (param_4 == 7) {
      iVar3 = (iVar10 * 3) / 2;
      iVar10 = iVar3;
    }
    iVar8 = aiStack_38[0] - iVar10;
    iVar12 = aiStack_38[1] - iVar10;
    iVar13 = aiStack_38[2] - iVar10;
    iVar10 = aiStack_38[3] - iVar10;
    iVar5 = (aiStack_24[2] + aiStack_24[1]) / 2;
    iVar6 = (aiStack_38[2] + aiStack_38[1]) / 2 - iVar3;
    iVar7 = (aiStack_24[3] + aiStack_24[0]) / 2;
    iVar3 = (aiStack_38[3] + aiStack_38[0]) / 2 - iVar3;
    (*pcVar1)(param_1,0);
    if (DAT_005363e4 == 0) {
      if ((param_4 == 1) && (DAT_004fb6ac != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004fb6ac);
      }
      if (param_4 == 2) {
        if (DAT_00522fcc != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_00522fcc);
        }
        if (DAT_004ff034 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004ff034);
        }
      }
      if ((param_4 == 4) && (DAT_004f3f5c != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f3f5c);
      }
    }
    if (-10 < param_5) {
      _DAT_004f6e30 = aiStack_24[0];
      _DAT_004f6e34 = aiStack_38[0];
      _DAT_004f6e38 = aiStack_24[0];
      _DAT_004f6e28 = aiStack_24[1];
      _DAT_004f6e2c = aiStack_38[1];
      _DAT_004f6e40 = aiStack_24[1];
      _DAT_004f6e3c = iVar8;
      _DAT_004f6e44 = iVar12;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    }
    if ((param_5 < 10) || (0xaa < param_5)) {
      _DAT_004f6e2c = aiStack_38[2];
      _DAT_004f6e30 = aiStack_24[3];
      _DAT_004f6e38 = aiStack_24[3];
      _DAT_004f6e28 = aiStack_24[2];
      _DAT_004f6e34 = aiStack_38[3];
      _DAT_004f6e40 = aiStack_24[2];
      _DAT_004f6e3c = iVar10;
      _DAT_004f6e44 = iVar13;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    }
    if ((param_5 ^ param_5 >> 0x1f) - (param_5 >> 0x1f) < 0x5a) {
      _DAT_004f6e2c = aiStack_38[2];
      _DAT_004f6e28 = aiStack_24[2];
      _DAT_004f6e40 = aiStack_24[1];
      _DAT_004f6e48 = aiStack_24[1];
      _DAT_004f6e30 = aiStack_24[2];
      _DAT_004f6e4c = aiStack_38[1];
      _DAT_004f6e34 = iVar13;
      _DAT_004f6e38 = iVar5;
      _DAT_004f6e3c = iVar6;
      _DAT_004f6e44 = iVar12;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,5);
      _DAT_004f6e28 = (aiStack_24[1] + aiStack_24[2] * 2) / 3;
      _DAT_004f6e2c = (aiStack_38[1] + aiStack_38[2] * 2) / 3;
      _DAT_004f6e34 = (iVar12 + iVar13 * 2) / 3;
      _DAT_004f6e38 = (aiStack_24[2] + aiStack_24[1] * 2) / 3;
      _DAT_004f6e3c = (iVar13 + iVar12 * 2) / 3;
      _DAT_004f6e44 = (aiStack_38[2] + aiStack_38[1] * 2) / 3;
      _DAT_004f6e30 = _DAT_004f6e28;
      _DAT_004f6e40 = _DAT_004f6e38;
      if (uVar4 == uVar9) {
        if (DAT_004fe07c != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fe07c);
        }
      }
      else {
        (*pcVar1)(param_1,0);
      }
      if (DAT_004fb5d4 == 0) {
        Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
      }
    }
    else {
      _DAT_004f6e28 = aiStack_24[3];
      _DAT_004f6e30 = aiStack_24[3];
      _DAT_004f6e2c = aiStack_38[3];
      _DAT_004f6e40 = aiStack_24[0];
      _DAT_004f6e48 = aiStack_24[0];
      _DAT_004f6e4c = aiStack_38[0];
      _DAT_004f6e34 = iVar10;
      _DAT_004f6e38 = iVar7;
      _DAT_004f6e3c = iVar3;
      _DAT_004f6e44 = iVar8;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,5);
    }
    if ((param_5 < 0x14) || (0xa0 < param_5)) {
      _DAT_004f6e28 = aiStack_24[2];
      _DAT_004f6e40 = aiStack_24[3];
      _DAT_004f6e2c = iVar13;
      _DAT_004f6e30 = iVar5;
      _DAT_004f6e34 = iVar6;
      _DAT_004f6e38 = iVar7;
      _DAT_004f6e3c = iVar3;
      _DAT_004f6e44 = iVar10;
      if (DAT_004fe07c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe07c);
      }
      if ((DAT_004da1f8 == 0xc) && (DAT_004f3864 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f3864);
      }
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    }
    if (-0x14 < param_5) {
      _DAT_004f6e28 = aiStack_24[1];
      _DAT_004f6e40 = aiStack_24[0];
      _DAT_004f6e2c = iVar12;
      _DAT_004f6e30 = iVar5;
      _DAT_004f6e34 = iVar6;
      _DAT_004f6e38 = iVar7;
      _DAT_004f6e3c = iVar3;
      _DAT_004f6e44 = iVar8;
      if (DAT_004fe07c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe07c);
      }
      if ((DAT_004da1f8 == 0xc) && (DAT_004f3864 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f3864);
      }
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    }
  }
  return;
}

