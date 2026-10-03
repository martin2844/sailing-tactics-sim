
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00424bd0(int *param_1,int param_2)

{
  int *original_dc;
  int iVar1;
  int iVar2;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int local_10;
  int local_8 [2];
  
  original_dc = param_1;
  if ((DAT_005363e0 == 1) && (DAT_004da140 < param_2)) {
    return;
  }
  if (DAT_005363bc == 1) {
    return;
  }
  if (((((DAT_005364d4 == 1) || (0 < DAT_005363c0)) || (DAT_004da190 == 8)) || (DAT_004fb410 == 1))
     && (0 < param_2)) {
    if (DAT_004da190 == 8) {
      _DAT_004f6e28 = (DAT_00522904 + DAT_00522914 * 4) / 5;
      _DAT_004f6e2c = (DAT_00522a04 + DAT_00522a14 * 4) / 5;
      _DAT_004f6e30 = (DAT_00522914 + DAT_00522904 * 4) / 5;
      _DAT_004f6e34 = (DAT_00522a14 + DAT_00522a04 * 4) / 5;
      _DAT_004f6e38 = (DAT_00522918 + DAT_00522900 * 4) / 5;
      _DAT_004f6e3c = (DAT_00522a18 + DAT_00522a00 * 4) / 5;
      _DAT_004f6e50 = (DAT_00522900 + DAT_00522918 * 4) / 5;
      _DAT_004f6e54 = (DAT_00522a00 + DAT_00522a18 * 4) / 5;
      _DAT_004f6e40 = (DAT_00522920 + DAT_005228f8 * 4) / 5;
      _DAT_004f6e44 = (DAT_00522a20 + DAT_005229f8 * 4) / 5;
      _DAT_004f6e48 = (DAT_005228f8 + DAT_00522920 * 4) / 5;
      _DAT_004f6e4c = (DAT_005229f8 + DAT_00522a20 * 4) / 5;
      if (DAT_005362fc != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005362fc);
      }
      local_10 = (DAT_00522920 + DAT_005228f8 * 4) / 5;
      iVar2 = DAT_005228f8 + DAT_00522920 * 4;
      iVar3 = DAT_00522a20 + DAT_005229f8 * 4;
      iVar1 = (DAT_005229f8 + DAT_00522a20 * 4) / 5;
      if (DAT_005230cc != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005230cc);
      }
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,6);
      iVar2 = iVar2 / 5;
      iVar3 = iVar3 / 5;
    }
    else {
      iVar1 = DAT_00522904 + DAT_00522914 * 3;
      iVar2 = DAT_00522914 + DAT_00522904 * 3;
      iVar3 = DAT_00522a04 + DAT_00522a14 * 3;
      _DAT_004f6e28 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
      _DAT_004f6e2c = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
      iVar1 = DAT_00522a14 + DAT_00522a04 * 3;
      _DAT_004f6e30 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
      iVar2 = DAT_00522920 + DAT_005228f8 * 3;
      _DAT_004f6e34 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
      iVar1 = DAT_00522a20 + DAT_005229f8 * 3;
      _DAT_004f6e38 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
      iVar2 = DAT_005228f8 + DAT_00522920 * 3;
      _DAT_004f6e3c = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
      iVar1 = DAT_005229f8 + DAT_00522a20 * 3;
      _DAT_004f6e40 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
      _DAT_004f6e44 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
      if (DAT_005362fc != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005362fc);
      }
      iVar1 = DAT_00522920 + DAT_005228f8 * 3;
      iVar2 = DAT_00522a20 + DAT_005229f8 * 3;
      local_10 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
      iVar1 = DAT_005228f8 + DAT_00522920 * 3;
      iVar3 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
      iVar2 = DAT_005229f8 + DAT_00522a20 * 3;
      local_8[0] = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
      iVar1 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
      if (DAT_005230cc != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005230cc);
      }
      if ((DAT_004fb410 == 1) && (DAT_004fe07c != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004fe07c);
      }
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
      iVar2 = local_8[0];
      if (DAT_004fb410 == 1) {
        _DAT_004f6e28 = (DAT_00522914 * 3 + DAT_00522904 * 2) / 5;
        _DAT_004f6e2c = (DAT_00522a14 * 3 + DAT_00522a04 * 2) / 5;
        _DAT_004f6e30 = (DAT_00522904 * 3 + DAT_00522914 * 2) / 5;
        _DAT_004f6e34 = (DAT_00522a04 * 3 + DAT_00522a14 * 2) / 5;
        _DAT_004f6e38 = ((DAT_005228f8 + DAT_005228fc) * 3 + (DAT_0052291c + DAT_00522920) * 2) / 10
        ;
        _DAT_004f6e3c = ((DAT_005229fc + DAT_005229f8) * 3 + (DAT_00522a1c + DAT_00522a20) * 2) / 10
        ;
        _DAT_004f6e40 = ((DAT_0052291c + DAT_00522920) * 3 + (DAT_005228f8 + DAT_005228fc) * 2) / 10
        ;
        _DAT_004f6e44 = ((DAT_00522a1c + DAT_00522a20) * 3 + (DAT_005229fc + DAT_005229f8) * 2) / 10
        ;
        if (DAT_005362fc != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_005362fc);
        }
        if (DAT_005230cc != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_005230cc);
        }
        Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
        iVar2 = local_8[0];
      }
    }
    param_1 = (int *)iVar3;
    if (DAT_005362fc != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362fc);
    }
    FUN_004b4d9d(original_dc,local_8,local_10,(int)param_1 + 1);
    CDC::LineTo(original_dc,iVar2,iVar1 + 1);
    if (param_2 != 1) {
      return;
    }
    if (DAT_004fb410 != 0) {
      return;
    }
    (**(code **)(*original_dc + 0x2c))(original_dc,7);
    iVar3 = (DAT_004fb9cc - DAT_005229f8) / 2;
    if ((-10 < (int)DAT_004f4b44) && ((int)DAT_004f4b44 < 0x3c)) {
      FUN_004b4d9d(original_dc,local_8,(iVar2 + DAT_004f4514) / 2 + -1,
                   (iVar1 + DAT_004fb9cc) / 2 + 1);
      CDC::LineTo(original_dc,(DAT_005228ec + DAT_00522914) / 2,
                  (DAT_00522a14 + DAT_005229ec) / 2 + iVar3);
    }
    if (((int)DAT_004f4b44 < 10) && (-0x3c < (int)DAT_004f4b44)) {
      FUN_004b4d9d(original_dc,local_8,(DAT_004f4514 + local_10) / 2 + 1,
                   ((int)param_1 + DAT_004fb9cc) / 2 + 1);
      CDC::LineTo(original_dc,(DAT_005228ec + DAT_00522904) / 2,
                  (DAT_00522a04 + DAT_005229ec) / 2 + iVar3);
    }
    if (0x3b < (int)((DAT_004f4b44 ^ (int)DAT_004f4b44 >> 0x1f) - ((int)DAT_004f4b44 >> 0x1f))) {
      return;
    }
    FUN_004b4d9d(original_dc,local_8,(DAT_004f4514 + local_10) / 2 + 1,
                 ((int)param_1 + DAT_004fb9cc) / 2 + 1);
    CDC::LineTo(original_dc,(iVar2 + DAT_004f4514) / 2 + -1,(DAT_004fb9cc + iVar1) / 2 + 1);
    return;
  }
  _DAT_004f6e28 = (DAT_00522904 + DAT_00522914 * 2) / 3;
  _DAT_004f6e2c = (DAT_00522a04 + DAT_00522a14 * 2) / 3;
  _DAT_004f6e30 = (DAT_00522914 + DAT_00522904 * 2) / 3;
  _DAT_004f6e34 = (DAT_00522a14 + DAT_00522a04 * 2) / 3;
  if (DAT_0053652c == 1) {
    _DAT_004f6e28 = (DAT_00522900 + (DAT_00522918 + DAT_00522914) * 2 + DAT_00522904) / 6;
    _DAT_004f6e2c = (DAT_00522a00 + (DAT_00522a18 + DAT_00522a14) * 2 + DAT_00522a04) / 6;
    _DAT_004f6e30 = (DAT_00522918 + (DAT_00522900 + DAT_00522904) * 2 + DAT_00522914) / 6;
    _DAT_004f6e34 = (DAT_00522a18 + (DAT_00522a00 + DAT_00522a04) * 2 + DAT_00522a14) / 6;
  }
  _DAT_004f6e38 = (DAT_0052291c + DAT_005228fc * 2) / 3;
  _DAT_004f6e3c = (DAT_00522a1c + DAT_005229fc * 2) / 3;
  _DAT_004f6e40 = (DAT_005228fc + DAT_0052291c * 2) / 3;
  _DAT_004f6e44 = (DAT_005229fc + DAT_00522a1c * 2) / 3;
  if ((DAT_00536528 == 1) || (DAT_0053652c == 1)) {
    _DAT_004f6e38 = (DAT_0052291c + (DAT_005228fc + DAT_005228f8) * 2 + DAT_00522920) / 6;
    _DAT_004f6e3c = (DAT_00522a1c + (DAT_005229fc + DAT_005229f8) * 2 + DAT_00522a20) / 6;
    _DAT_004f6e40 = (DAT_005228fc + (DAT_0052291c + DAT_00522920) * 2 + DAT_005228f8) / 6;
    _DAT_004f6e44 = (DAT_005229fc + (DAT_00522a1c + DAT_00522a20) * 2 + DAT_005229f8) / 6;
  }
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  if ((DAT_005363c8 == 1) || (DAT_0053652c == 1)) {
    if (DAT_004f3f5c == (HGDIOBJ)0x0) goto LAB_00425648;
    hdc = (HDC)param_1[1];
    h = DAT_004f3f5c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_00425648;
    hdc = (HDC)param_1[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_00425648:
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  return;
}

