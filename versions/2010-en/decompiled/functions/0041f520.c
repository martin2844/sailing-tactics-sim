
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041f520(int *param_1,double param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_10;
  
  iVar3 = DAT_00522948;
  if (param_3 <= DAT_004da194) {
    dVar2 = param_2 * _DAT_004cc828;
    if (DAT_004da190 == 8) {
      dVar2 = dVar2 * _DAT_004cc830;
    }
    if (((DAT_005363b8 == 1) || (DAT_005364bc == 1)) || (DAT_00536528 == 1)) {
      dVar2 = dVar2 * _DAT_004cc630;
    }
    if (DAT_00536530 == 1) {
      dVar2 = dVar2 * _DAT_004cc738;
    }
    if (DAT_004da150 == 100) {
      local_10 = DAT_00522934;
      iVar4 = (int)(longlong)(dVar2 * _DAT_004cc6b0);
      iVar7 = DAT_00522a34;
    }
    else {
      local_10 = DAT_00522930;
      iVar4 = (int)(longlong)(dVar2 * _DAT_004cc738);
      iVar7 = DAT_00522a30;
    }
    iVar8 = DAT_00522a48 - (int)(longlong)(dVar2 * _DAT_004cc440);
    iVar5 = (int)(longlong)(dVar2 * _DAT_004cc888);
    if (((DAT_004fb410 == 1) || (DAT_005364bc == 1)) ||
       ((DAT_00536530 == 1 || ((DAT_00536528 == 1 || (DAT_0053652c == 1)))))) {
      iVar5 = iVar5 / 2;
    }
    if (param_5 == 1) {
      iVar5 = -iVar5;
    }
    if ((*(int *)(&DAT_005350d8 + param_3 * 4) == 1) &&
       ((((DAT_004da190 == 2 || (DAT_005364bc == 1)) || (DAT_005364c4 == 1)) &&
        ((param_3 <= DAT_004da140 && (0x1e < *(int *)(&DAT_00535f68 + param_3 * 4))))))) {
      iVar5 = (iVar5 * -3) / 2;
    }
    if (DAT_005363b8 == 1) {
      param_5 = (int)(longlong)(param_2 * _DAT_004cc5f0);
    }
    else {
      param_5 = 0;
    }
    if (DAT_004da190 == 8) {
      iVar6 = (DAT_005229f0 + DAT_005229f4) / 2;
      iVar9 = (DAT_005228f0 + DAT_005228f4) / 2;
    }
    else {
      iVar6 = DAT_005229f4 - param_5;
      iVar9 = DAT_005228f4;
    }
    if (((DAT_004da144 == 4) || (DAT_004da190 == 6)) || (DAT_005364bc == 1)) {
      iVar9 = DAT_005228f0 + DAT_005228f4 * 3;
      iVar6 = DAT_005229f0 + DAT_005229f4 * 3;
      iVar9 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
      iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;
    }
    if ((DAT_00536528 == 1) || (DAT_0053652c == 1)) {
      iVar9 = (DAT_005228f0 + DAT_005228f4) / 2;
      iVar6 = (DAT_005229f0 + DAT_005229f4) / 2;
    }
    if (DAT_005364cc == 1) {
      (**(code **)(*param_1 + 0x2c))(param_1,7);
      FUN_004b4d9d(param_1,(int *)&param_2,DAT_005228f4,
                   DAT_005229f4 - (int)(longlong)(param_2 * _DAT_004cc570));
      CDC::LineTo(param_1,local_10,iVar7 - iVar4);
      return;
    }
    _DAT_004f6e28 = iVar9;
    _DAT_004f6e2c = iVar6;
    if (DAT_005363b8 != 0) {
      _DAT_004f6e28 = DAT_005228f4;
      _DAT_004f6e2c = DAT_005229f4 - param_5;
    }
    _DAT_004f6e30 = local_10;
    _DAT_004f6e34 = (iVar7 - iVar4) - param_5;
    _DAT_004f6e38 = DAT_00522948;
    pcVar1 = *(code **)(*param_1 + 0x2c);
    _DAT_004f6e3c = iVar8;
    _DAT_004f6e40 = (DAT_00522948 + DAT_005228f4) / 2;
    _DAT_004f6e44 = (iVar8 + DAT_005229f4) / 2 + iVar5;
    param_2._0_4_ = pcVar1;
    (*pcVar1)(param_1,7);
    (*pcVar1)(param_1,0);
    if ((DAT_005364d4 == 1) || (DAT_004da190 == 8)) {
      if (DAT_004f3f5c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f3f5c);
      }
    }
    else if (((DAT_005364d8 == 1) || (DAT_005363c0 == 1)) && (DAT_004f7f74 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004f7f74);
    }
    if ((DAT_00536450 == 1) && (DAT_004fe07c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
    iVar4 = param_3;
    if ((param_3 == 1) && (DAT_004f41f4 == 1)) {
      (*pcVar1)(param_1,5);
    }
    if (((iVar4 == 2) && (DAT_004f41f8 == 1)) && (DAT_004da140 == 2)) {
      (*pcVar1)(param_1,5);
    }
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    pcVar1 = param_2._0_4_;
    if ((*(int *)(&DAT_005350d8 + iVar4 * 4) == 1) && ((DAT_004da190 == 2 || (DAT_005364c8 == 1))))
    {
      param_5 = -*(int *)(&DAT_00522ff0 + iVar4 * 4);
    }
    else {
      param_5 = *(int *)(&DAT_00522ff0 + iVar4 * 4);
    }
    if ((param_5 == -1) && (DAT_005363b8 == 0)) {
      DAT_004f41fc = (DAT_00522918 + DAT_00522900 * 4) / 5;
      DAT_004fb40c = (DAT_00522a18 + DAT_00522a00 * 4) / 5;
      if ((6 < DAT_004da190) && ((*(int *)(&DAT_004f7ee0 + param_3 * 4) < 2 && (DAT_004da190 < 8))))
      {
        DAT_004f41fc = (DAT_00522918 + DAT_005228fc * 4) / 5;
        DAT_004fb40c = (DAT_00522a18 + DAT_005229fc * 4) / 5;
      }
      if (DAT_004da190 == 8) {
        DAT_004f41fc = (DAT_00522900 + DAT_005228fc) / 2;
        DAT_004fb40c = (DAT_00522a00 + DAT_005229fc) / 2;
      }
      if (DAT_004fb410 == 1) {
        DAT_004f41fc = (DAT_00522914 + DAT_00522904 * 2) / 3;
        DAT_004fb40c = (DAT_00522a14 + DAT_00522a04 * 2) / 3;
      }
      if ((DAT_005364bc == 1) || (DAT_00536528 == 1)) {
        DAT_004f41fc = (DAT_00522914 + DAT_00522904 * 3 + DAT_00522900) / 5;
        DAT_004fb40c = (DAT_00522a14 + DAT_00522a04 * 3 + DAT_00522a00) / 5;
      }
      if ((DAT_0053652c == 1) || (DAT_00536530 == 1)) {
        iVar4 = DAT_00522900 * 3 + DAT_00522918 + DAT_00522904 * 4;
        DAT_004f41fc = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
        iVar4 = DAT_00522a00 * 3 + DAT_00522a18 + DAT_00522a04 * 4;
        DAT_004fb40c = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
      }
    }
    if ((param_5 == 1) && (DAT_005363b8 == 0)) {
      DAT_004f41fc = (DAT_00522900 + DAT_00522918 * 4) / 5;
      DAT_004fb40c = (DAT_00522a00 + DAT_00522a18 * 4) / 5;
      if ((6 < DAT_004da190) && ((*(int *)(&DAT_004f7ee0 + param_3 * 4) < 2 && (DAT_004da190 < 8))))
      {
        DAT_004f41fc = (DAT_00522900 + DAT_0052291c * 4) / 5;
        DAT_004fb40c = (DAT_00522a00 + DAT_00522a1c * 4) / 5;
      }
      if (DAT_004da190 == 8) {
        DAT_004f41fc = (DAT_00522918 + DAT_0052291c) / 2;
        DAT_004fb40c = (DAT_00522a18 + DAT_00522a1c) / 2;
      }
      if (DAT_004fb410 == 1) {
        DAT_004f41fc = (DAT_00522904 + DAT_00522914 * 2) / 3;
        DAT_004fb40c = (DAT_00522a04 + DAT_00522a14 * 2) / 3;
      }
      if ((DAT_005364bc == 1) || (DAT_00536528 == 1)) {
        DAT_004f41fc = (DAT_00522904 + DAT_00522914 * 3 + DAT_00522918) / 5;
        DAT_004fb40c = (DAT_00522a04 + DAT_00522a14 * 3 + DAT_00522a18) / 5;
      }
      if (((DAT_0053652c == 1) || (DAT_00536530 == 1)) || (DAT_00536528 == 1)) {
        iVar4 = DAT_00522918 * 3 + DAT_00522900 + DAT_00522914 * 4;
        DAT_004f41fc = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
        iVar4 = DAT_00522a18 * 3 + DAT_00522a00 + DAT_00522a14 * 4;
        DAT_004fb40c = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
      }
    }
    if ((param_5 == -1) && (DAT_005363b8 == 1)) {
      DAT_004f41fc = (DAT_005228f8 + (DAT_00522914 + DAT_00522900 * 2) * 2) / 7;
      DAT_004fb40c = (DAT_005229f8 + (DAT_00522a14 + DAT_00522a00 * 2) * 2) / 7;
    }
    if ((param_5 == 1) && (DAT_005363b8 == 1)) {
      DAT_004f41fc = (DAT_0052291c + (DAT_00522900 + DAT_00522914 * 2) * 2) / 7;
      DAT_004fb40c = (DAT_00522a1c + (DAT_00522a00 + DAT_00522a14 * 2) * 2) / 7;
    }
    (*param_2._0_4_)(param_1,6);
    FUN_004b4d9d(param_1,(int *)&param_2,DAT_004f41fc,DAT_004fb40c);
    CDC::LineTo(param_1,iVar3,iVar8);
    (*pcVar1)(param_1,4);
    (*pcVar1)(param_1,7);
    if (*(int *)(&DAT_004f71c0 + param_3 * 4) == 1) {
      FUN_00433a70(param_1,2,DAT_004f41fc,DAT_004fb40c);
    }
  }
  return;
}

