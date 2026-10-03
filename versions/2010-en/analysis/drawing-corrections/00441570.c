
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00441570(int *param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  double dVar2;
  double dVar3;
  int *original_dc;
  int iVar4;
  int iVar5;
  int iVar6;
  int bottom;
  int iVar7;
  int aiStack_14 [2];
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  original_dc = param_1;
  if (DAT_004da148 + 1 <= param_3) {
    pcVar1 = *(code **)(*param_1 + 0x2c);
    (*pcVar1)(param_1,7);
    dVar2 = _DAT_004cc618 -
            ((double)(param_3 + -0x1e) * _DAT_004ccb90) / (double)(DAT_004fe2a8 / 2 + -0x1e);
    dVar3 = _DAT_004ccb98;
    if (DAT_004f8b78 == 1) {
      dVar3 = _DAT_004ccad8;
    }
    iVar7 = (int)(longlong)(dVar2 * dVar3);
    if (param_4 == 1) {
      iVar7 = (int)(longlong)(dVar2 * _DAT_004ccba0);
    }
    if (DAT_004f8b78 == 1) {
      iVar7 = (int)(longlong)(dVar2 * _DAT_004cc490);
    }
    if (DAT_004f8b78 == 0) {
      if (DAT_004fe07c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe07c);
      }
      iVar4 = (iVar7 * 3) / 10;
      Ellipse((HDC)param_1[1],param_2 - iVar4,param_3,param_2 + iVar4,iVar7 / 10 + param_3);
    }
    iVar4 = param_3;
    if (DAT_004f8b78 == 1) {
      (*pcVar1)(param_1,8);
      if ((DAT_00536450 == 0) && (DAT_005363e4 == 0)) {
        FUN_00484270(param_1);
      }
      else if (DAT_004fe07c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe07c);
      }
      if ((DAT_00536450 == 1) && (DAT_005230cc != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_005230cc);
      }
      _DAT_004f6e28 = param_2 + iVar7 * -4;
      _DAT_004f6e2c = param_3;
      _DAT_004f6e30 = param_2 + iVar7 * -2;
      _DAT_004f6e38 = param_2;
      _DAT_004f6e4c = param_3;
      iVar6 = param_3 - ((int)(iVar7 * 3 + (iVar7 * 3 >> 0x1f & 7U)) >> 3);
      iVar4 = param_3 - iVar7 / 2;
      _DAT_004f6e40 = param_2 + iVar7 * 2;
      _DAT_004f6e48 = param_2 + iVar7 * 4;
      _DAT_004f6e34 = iVar6;
      _DAT_004f6e3c = iVar4;
      _DAT_004f6e44 = iVar6;
      aiStack_14[0] = _DAT_004f6e28;
      iStack_c = _DAT_004f6e30;
      iStack_8 = _DAT_004f6e40;
      iStack_4 = _DAT_004f6e48;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,5);
      (*pcVar1)(param_1,7);
      FUN_004b4d9d(param_1,aiStack_14,aiStack_14[0],param_3);
      CDC::LineTo(param_1,iStack_c,iVar6);
      CDC::LineTo(param_1,param_2,iVar4);
      CDC::LineTo(param_1,iStack_8,iVar6);
      CDC::LineTo(param_1,iStack_4,param_3);
    }
    if (DAT_00536450 == 0) {
      (*pcVar1)(param_1,0);
    }
    else if (DAT_004fe07c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
    _DAT_004f6e28 = param_2 - iVar7 / 7;
    _DAT_004f6e40 = iVar7 / 7 + param_2;
    iVar6 = (int)((ulonglong)((longlong)(iVar7 * 2) * -0x77777777) >> 0x20) + iVar7 * 2;
    iVar6 = (iVar6 >> 4) - (iVar6 >> 0x1f);
    if (param_4 == 1) {
      iVar6 = (int)((ulonglong)((longlong)(iVar7 * 4) * -0x77777777) >> 0x20) + iVar7 * 4;
      iVar6 = (iVar6 >> 4) - (iVar6 >> 0x1f);
    }
    param_1 = (int *)(iVar6 + param_2);
    iVar5 = iVar7 / (param_4 + 1);
    _DAT_004f6e38 = (int)param_1;
    bottom = iVar4 - iVar5;
    _DAT_004f6e2c = iVar4;
    _DAT_004f6e30 = param_2 - iVar6;
    _DAT_004f6e34 = bottom;
    _DAT_004f6e3c = bottom;
    _DAT_004f6e44 = iVar4;
    iStack_4 = _DAT_004f6e40;
    Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,4);
    (*pcVar1)(original_dc,4);
    if (DAT_005363e4 == 0) {
      if (DAT_004f3864 != (HGDIOBJ)0x0) {
        SelectObject((HDC)original_dc[1],DAT_004f3864);
      }
      if (DAT_004fb994 != (HGDIOBJ)0x0) {
        SelectObject((HDC)original_dc[1],DAT_004fb994);
      }
    }
    else {
      (*pcVar1)(original_dc,0);
      (*pcVar1)(original_dc,6);
    }
    Rectangle((HDC)original_dc[1],(param_2 - iVar6) + 1,(iVar4 - iVar7 / 10) - iVar5,
              (int)param_1 + 1,bottom);
  }
  return;
}

