
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0041ce80(int *param_1,double param_2,int param_3,double param_4,int param_5,int param_6,
            int param_7)

{
  code *pcVar1;
  int iVar2;
  double dVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  HDC pHVar7;
  HGDIOBJ h;
  int iVar8;
  int local_14;
  int local_10;
  int local_c;
  double local_8;
  
  if (DAT_004da194 < param_3) {
    return;
  }
  local_8 = param_2 * _DAT_004cc828;
  if (DAT_004da190 == 8) {
    local_8 = local_8 * _DAT_004cc830;
  }
  if (((DAT_005363b8 == 1) || (DAT_005364bc == 1)) || (DAT_00536528 == 1)) {
    local_8 = local_8 * _DAT_004cc630;
  }
  if (DAT_0053652c == 1) {
    local_8 = local_8 * _DAT_004cc468;
  }
  if (DAT_005363cc == 1) {
    local_8 = local_8 * _DAT_004cc600;
  }
  if (DAT_00536530 == 1) {
    local_8 = local_8 * _DAT_004cc600;
  }
  iVar2 = (int)(longlong)(param_4 * _DAT_004cc838) / 3;
  if (((param_3 <= DAT_004da140) && (1 < DAT_004da190)) && (DAT_005363e8 == 0)) {
    DAT_004fe6c4 = DAT_00522934;
    DAT_004fe774 = DAT_00522a34 - (int)(longlong)(local_8 * _DAT_004cc6b0);
    if (DAT_005363b8 == 0) {
      iVar8 = DAT_00522900 + DAT_00522904 * 3;
      DAT_00522aec = (int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2;
      iVar8 = DAT_00522a00 + DAT_00522a04 * 3;
      DAT_00534f48 = (int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2;
      iVar8 = DAT_00522918 + DAT_00522914 * 3;
      DAT_004fba08 = (int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2;
      iVar8 = DAT_00522a18 + DAT_00522a14 * 3;
      DAT_00522fb4 = (int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2;
      if (DAT_0053652c == 1) {
        DAT_00522aec = (DAT_00522904 + DAT_00522900 * 2) / 3;
        DAT_00534f48 = (DAT_00522a04 + DAT_00522a00 * 2) / 3;
        DAT_004fba08 = (DAT_00522914 + DAT_00522918 * 2) / 3;
        DAT_00522fb4 = (DAT_00522a14 + DAT_00522a18 * 2) / 3;
      }
      if (DAT_00536528 == 1) {
        DAT_00534f48 = DAT_00522a04;
        DAT_00522aec = DAT_00522904;
        DAT_004fba08 = DAT_00522914;
        DAT_00522fb4 = DAT_00522a14;
      }
    }
    if (DAT_005363b8 == 1) {
      DAT_00522aec = (DAT_005228fc + DAT_00522904 * 5) / 6;
      DAT_00534f48 = (DAT_005229fc + DAT_00522a04 * 5) / 6;
      DAT_004fba08 = (DAT_00522920 + DAT_00522918 * 5) / 6;
      DAT_00522fb4 = (DAT_00522a20 + DAT_00522a18 * 5) / 6;
    }
    if (DAT_004da150 == 100) {
      DAT_004fe628 = DAT_00522934;
      DAT_004fe760 = DAT_004fe774;
    }
    else {
      DAT_004fe628 = DAT_00522930;
      DAT_004fe760 = DAT_00522a30 - (int)(longlong)(local_8 * _DAT_004cc738);
    }
    iVar8 = DAT_00522aec;
    iVar4 = DAT_00534f48;
    if (DAT_00522ff4 == 1) {
      iVar8 = DAT_004fba08;
      iVar4 = DAT_00522fb4;
    }
    FUN_0041dcd0(param_1,iVar8,iVar4,DAT_00522934,DAT_004fe774,local_8);
  }
  if (((DAT_004da190 == 10) || (DAT_004da190 == 8)) || (DAT_005364cc == 1)) {
    _DAT_004f6e2c = (int)(longlong)(local_8 * _DAT_004cc440);
    local_10 = (int)(longlong)(local_8 * _DAT_004cc660);
    local_c = (int)(longlong)(local_8 * _DAT_004cc4f8);
    local_14 = (int)(longlong)(local_8 * _DAT_004cc738);
    _DAT_004f6e4c = (int)(longlong)(local_8 * _DAT_004cc6b0);
    if (DAT_004da190 == 8) {
      _DAT_004f6e50 = (DAT_00522938 * 3 + DAT_00522934 * 2) / 5;
      _DAT_004f6e54 = (DAT_00522a38 * 3 + DAT_00522a34 * 2) / 5;
      dVar3 = _DAT_004cc840;
    }
    else {
      _DAT_004f6e50 = ((DAT_00522938 + DAT_00522934 * 2) * 2) / 6;
      _DAT_004f6e54 = ((DAT_00522a38 + DAT_00522a34 * 2) * 2) / 6;
      dVar3 = _DAT_004cc848;
    }
    _DAT_004f6e54 = _DAT_004f6e54 - (int)(longlong)(local_8 * dVar3);
    _DAT_004f6e5c = (DAT_00522a38 - iVar2) - local_14;
    _DAT_004f6e64 = (DAT_00522a3c - iVar2) - local_c;
    _DAT_004f6e60 = DAT_0052293c;
    _DAT_004f6e6c = (DAT_00522a40 - iVar2) - local_10;
    _DAT_004f6e68 = DAT_00522940;
    _DAT_004f6e58 = DAT_00522938;
    _DAT_004f6e70 = DAT_00522944;
    _DAT_004f6e74 = (DAT_00522a44 - iVar2) - _DAT_004f6e2c;
  }
  else {
    if ((((DAT_005364bc == 1) || (DAT_004da190 == 9)) || (DAT_00536528 == 1)) || (DAT_0053652c == 1)
       ) {
      _DAT_004f6e2c = (int)(longlong)(local_8 * _DAT_004cc440);
    }
    else {
      _DAT_004f6e2c = (int)(longlong)(local_8 * _DAT_004cc638);
    }
    local_10 = (int)(longlong)(local_8 * _DAT_004cc660);
    local_c = (int)(longlong)(local_8 * _DAT_004cc4f8);
    local_14 = (int)(longlong)(local_8 * _DAT_004cc738);
    _DAT_004f6e4c = (int)(longlong)(local_8 * _DAT_004cc6b0);
    _DAT_004f6e54 = (DAT_00522a38 - iVar2) - local_14;
    _DAT_004f6e50 = DAT_00522938;
    _DAT_004f6e58 = DAT_0052293c;
    _DAT_004f6e60 = DAT_00522940;
    _DAT_004f6e5c = (DAT_00522a3c - iVar2) - local_c;
    _DAT_004f6e64 = (DAT_00522a40 - iVar2) - local_10;
    dVar3 = _DAT_004cc440;
    if (((DAT_005364bc != 1) && (DAT_004da190 != 9)) && ((DAT_00536528 != 1 && (DAT_0053652c != 1)))
       ) {
      dVar3 = _DAT_004cc638;
    }
    _DAT_004f6e68 = DAT_00522944;
    _DAT_004f6e6c = (DAT_00522a44 - (int)(longlong)(local_8 * dVar3)) - iVar2;
  }
  _DAT_004f6e4c = DAT_00522a34 - _DAT_004f6e4c;
  _DAT_004f6e44 = DAT_00522a30 - local_14;
  _DAT_004f6e3c = DAT_00522a2c - local_c;
  _DAT_004f6e34 = DAT_00522a28 - local_10;
  _DAT_004f6e2c = DAT_00522a24 - _DAT_004f6e2c;
  _DAT_004f6e48 = DAT_00522934;
  _DAT_004f6e40 = DAT_00522930;
  _DAT_004f6e38 = DAT_0052292c;
  _DAT_004f6e30 = DAT_00522928;
  _DAT_004f6e28 = DAT_00522924;
  pcVar1 = *(code **)(*param_1 + 0x2c);
  (*pcVar1)(param_1,7);
  (*pcVar1)(param_1,0);
  uVar5 = param_3 >> 0x1f;
  if (((param_3 ^ uVar5) - uVar5 & 1 ^ uVar5) == uVar5) {
    if ((DAT_005364d4 == 1) || (DAT_004da190 == 8)) {
      if (DAT_004fe07c == (HGDIOBJ)0x0) goto LAB_0041d68e;
      pHVar7 = (HDC)param_1[1];
      h = DAT_004fe07c;
    }
    else {
      if (((DAT_005364d8 != 1) && (DAT_005363c0 != 1)) || (DAT_004f7f74 == (HGDIOBJ)0x0))
      goto LAB_0041d68e;
      pHVar7 = (HDC)param_1[1];
      h = DAT_004f7f74;
    }
  }
  else {
    if (((DAT_005364d4 != 1) && (DAT_004da190 != 8)) || (DAT_004f3f5c == (HGDIOBJ)0x0))
    goto LAB_0041d68e;
    pHVar7 = (HDC)param_1[1];
    h = DAT_004f3f5c;
  }
  SelectObject(pHVar7,h);
LAB_0041d68e:
  if ((DAT_00536480 == 1) && (FUN_0041ed90(param_1,param_3), param_3 == 1)) {
    (*pcVar1)(param_1,0);
  }
  if ((DAT_00536450 == 1) && (DAT_004fe07c != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004fe07c);
  }
  if (((_DAT_004cc658 < _DAT_004da230) && (DAT_00536450 == 0)) && (DAT_005363e4 == 0)) {
    if (((*(int *)(&DAT_004fe8a8 + param_3 * 4) == 2) ||
        (*(int *)(&DAT_004fe8a8 + param_3 * 4) == 0xc)) && (DAT_00522fcc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_00522fcc);
    }
    if ((*(int *)(&DAT_004fe8a8 + param_3 * 4) == 3) && (DAT_005233b4 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005233b4);
    }
  }
  iVar8 = DAT_004da140;
  if ((DAT_004da1dc == 2) && (DAT_004da1e0 + 4 < DAT_004f8cd0)) {
    DAT_004da1dc = 1;
  }
  iVar4 = DAT_004da1dc;
  if ((*(int *)(&DAT_004f7120 + param_3 * 4) == 0) && (param_3 <= DAT_004da140)) {
    *(undefined4 *)(&DAT_004faf80 + param_3 * 4) = 0;
  }
  if ((((0 < *(int *)(&DAT_004f7120 + param_3 * 4)) && (param_3 <= iVar8)) &&
      (*(int *)(&DAT_004fe638 + param_3 * 4) == 0)) && (*(int *)(&DAT_004fb9a8 + param_3 * 4) == 0))
  {
    if ((iVar4 == 1) && (*(int *)(&DAT_004faf80 + param_3 * 4) == 0)) {
      if (1 < DAT_004da174) {
        DAT_004da180 = DAT_004da174;
        DAT_004da17c = DAT_004da178;
        *(undefined4 *)(&DAT_004fb9a8 + param_3 * 4) = 0x5a;
      }
      DAT_004da178 = 0xb67;
      DAT_004da174 = 1;
    }
    if (DAT_004f3864 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f3864);
    }
    if (DAT_004fb994 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fb994);
    }
    *(undefined4 *)(&DAT_004faf80 + param_3 * 4) = *(undefined4 *)(&DAT_004f7120 + param_3 * 4);
  }
  if ((DAT_004f8cd0 < *(int *)(&DAT_00535620 + param_3 * 4) + DAT_004fe62c) &&
     (*(int *)(&DAT_005116e0 + param_3 * 4) < 0xb)) {
    (*pcVar1)(param_1,4);
  }
  if ((param_3 == 1) && (DAT_004f41f4 == 1)) {
    (*pcVar1)(param_1,5);
  }
  if (((param_3 == 2) && (DAT_004f41f8 == 1)) && (DAT_004da140 == 2)) {
    (*pcVar1)(param_1,5);
  }
  if (((DAT_004da190 == 10) || (DAT_004da190 == 8)) || (DAT_005364cc == 1)) {
    pHVar7 = (HDC)param_1[1];
    iVar8 = 10;
  }
  else {
    pHVar7 = (HDC)param_1[1];
    iVar8 = 9;
  }
  Polygon(pHVar7,(POINT *)&DAT_004f6e28,iVar8);
  (*pcVar1)(param_1,7);
  if (((param_3 <= DAT_004da140) && (1 < DAT_004da190)) && (DAT_005363e8 == 0)) {
    iVar8 = *(int *)(&DAT_004fe818 + param_3 * 4);
    if ((*(int *)(&DAT_00522ff0 + param_3 * 4) == 1) && (-(iVar8 + 10) < param_6)) {
      FUN_0041dcd0(param_1,DAT_00522aec,DAT_00534f48,DAT_004fe6c4,DAT_004fe774,local_8);
    }
    if ((*(int *)(&DAT_00522ff0 + param_3 * 4) == -1) && (param_6 < iVar8 + 10)) {
      FUN_0041dcd0(param_1,DAT_004fba08,DAT_00522fb4,DAT_004fe6c4,DAT_004fe774,local_8);
    }
    if ((*(int *)(&DAT_00522ff0 + param_3 * 4) == -1) && (param_6 == 0xb4)) {
      FUN_0041dcd0(param_1,DAT_004fba08,DAT_00522fb4,DAT_004fe6c4,DAT_004fe774,local_8);
    }
  }
  if ((DAT_004fe340 <= param_5) && ((param_3 <= DAT_004da140 || (DAT_005363e0 != 1)))) {
    (*pcVar1)(param_1,7);
    iVar8 = 10;
    iVar4 = FUN_0041e000(10);
    if (10 < *(int *)(&DAT_00512278 + param_3 * 4)) {
      iVar8 = iVar4 + 1;
    }
    iVar6 = 10;
    if (0x23 < *(int *)(&DAT_00512278 + param_3 * 4)) {
      iVar8 = iVar4 + -6;
      iVar6 = iVar4;
    }
    FUN_0041db70(param_1,iVar8,iVar6,param_7,
                 (int)(longlong)((double)(0x1e - DAT_004da190) * param_4),DAT_00522928,
                 DAT_00522a28 - local_10,DAT_00522940,(DAT_00522a40 - iVar2) - local_10,6,2);
    FUN_0041db70(param_1,iVar8,iVar6,param_7,
                 (int)(longlong)((double)(0x19 - DAT_004da190) * param_4),DAT_0052292c,
                 DAT_00522a2c - local_c,DAT_0052293c,(DAT_00522a3c - iVar2) - local_c,6,2);
    if (DAT_005363cc == 0) {
      FUN_0041db70(param_1,iVar8,iVar6,param_7,
                   (int)(longlong)((double)(0x14 - DAT_004da190) * param_4),DAT_00522930,
                   DAT_00522a30 - local_14,DAT_00522938,(DAT_00522a38 - iVar2) - local_14,6,2);
    }
  }
  return;
}

