
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00419ce0(int *param_1,double param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int aiStack_8 [2];
  
  pcVar3 = SelectObject_exref;
  _DAT_004f6e28 = DAT_005228f4;
  _DAT_004f6e2c = DAT_005229f4;
  _DAT_004f6e34 = DAT_00522a08;
  _DAT_004f6e30 = DAT_00522908;
  _DAT_004f6e40 = DAT_00522900;
  _DAT_004f6e38 = DAT_00522904;
  _DAT_004f6e4c = DAT_005229fc;
  _DAT_004f6e3c = DAT_00522a04;
  _DAT_004f6e58 = DAT_00522920;
  _DAT_004f6e44 = DAT_00522a00;
  _DAT_004f6e48 = DAT_005228fc;
  _DAT_004f6e64 = DAT_00522a1c;
  _DAT_004f6e50 = DAT_005228f8;
  _DAT_004f6e54 = DAT_005229f8;
  _DAT_004f6e70 = DAT_00522914;
  _DAT_004f6e5c = DAT_00522a20;
  _DAT_004f6e60 = DAT_0052291c;
  _DAT_004f6e7c = DAT_00522a10;
  _DAT_004f6e68 = DAT_00522918;
  _DAT_004f6e6c = DAT_00522a18;
  _DAT_004f6e74 = DAT_00522a14;
  _DAT_004f6e78 = DAT_00522910;
  if ((DAT_005363e4 == 0) && (DAT_005363c8 == 0)) {
    if (DAT_004f7f74 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7f74);
    }
  }
  else {
    (**(code **)(*param_1 + 0x2c))(param_1,0);
    pcVar3 = SelectObject_exref;
  }
  iVar1 = param_3;
  if ((DAT_004da140 < param_3) && (DAT_004f3f5c != (HGDIOBJ)0x0)) {
    (*pcVar3)((HDC)param_1[1],DAT_004f3f5c);
  }
  if ((DAT_00536450 == 1) && (DAT_004f3f5c != (HGDIOBJ)0x0)) {
    (*pcVar3)((HDC)param_1[1],DAT_004f3f5c);
  }
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  if ((((DAT_005363e4 == 0) && (DAT_005363c8 == 1)) && (iVar1 == 1)) &&
     (DAT_005362ec != (HGDIOBJ)0x0)) {
    (*pcVar3)((HDC)param_1[1],DAT_005362ec);
  }
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,0xb);
  iVar5 = param_4;
  if (((DAT_004da190 != 4) && (DAT_005363c4 != 1)) &&
     ((DAT_005363cc != 1 && (DAT_00535884 < param_4)))) {
    FUN_00424bd0(param_1,iVar1);
  }
  if (iVar1 != 0) {
    if (((DAT_004da190 < 7) && (DAT_004da190 != 4)) &&
       (((DAT_004fe33c < iVar5 && (((0 < iVar1 && (DAT_004da190 != 3)) && (1 < DAT_004da190)))) &&
        (((DAT_005363c0 == 0 && (DAT_00536528 == 0)) && (DAT_00536530 == 0)))))) {
      if (DAT_00522d14 != (HGDIOBJ)0x0) {
        (*pcVar3)((HDC)param_1[1],DAT_00522d14);
      }
      FUN_004b4d9d(param_1,aiStack_8,(DAT_005228ec + DAT_00522914 * 2) / 3,
                   (DAT_005229ec + DAT_00522a14 * 2) / 3);
      CDC::LineTo(param_1,(DAT_005228f0 + DAT_005228ec) / 2,(DAT_005229f0 + DAT_005229ec) / 2);
      CDC::LineTo(param_1,(DAT_005228ec + DAT_00522904 * 2) / 3,
                  (DAT_005229ec + DAT_00522a04 * 2) / 3);
    }
    if (DAT_00536528 == 1) {
      _DAT_004f6e30 = (DAT_005228f0 + DAT_005228ec) / 2;
      _DAT_004f6e34 = (DAT_005229ec + DAT_005229f0) / 2;
      _DAT_004f6e28 = (DAT_00522904 + DAT_00522914 * 2) / 3;
      _DAT_004f6e2c = (DAT_00522a04 + DAT_00522a14 * 2) / 3;
      _DAT_004f6e38 = (DAT_00522914 + DAT_00522904 * 2) / 3;
      _DAT_004f6e3c = (DAT_00522a14 + DAT_00522a04 * 2) / 3;
      if (DAT_00522d14 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_00522d14);
      }
      if (DAT_004f3f5c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f3f5c);
      }
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,3);
      pcVar3 = SelectObject_exref;
    }
    if ((DAT_004da190 == 4) || (DAT_005363c4 == 1)) {
      if (DAT_00522d14 != (HGDIOBJ)0x0) {
        (*pcVar3)((HDC)param_1[1],DAT_00522d14);
      }
      FUN_004b4d9d(param_1,aiStack_8,DAT_00522904,DAT_00522a04);
      CDC::LineTo(param_1,DAT_00522914,DAT_00522a14);
    }
    if (((0 < DAT_005363c0) || (DAT_005363c4 == 1)) || (DAT_0053652c == 1)) {
      if (DAT_004f7084 != (HGDIOBJ)0x0) {
        (*pcVar3)((HDC)param_1[1],DAT_004f7084);
      }
      iVar1 = DAT_005229f4 - DAT_005229ec;
      iVar5 = DAT_005228f4 - DAT_005228ec;
      if (0 < DAT_005363c0) {
        if (*(int *)(&DAT_005350d8 + param_3 * 4) == 1) {
          DAT_00523af8 = iVar5 / 2 + DAT_005228f4;
          DAT_00534d70 = (iVar1 / 2 - (int)(longlong)(param_2 * _DAT_004cc570)) + DAT_005229f4;
        }
        if ((0 < DAT_005363c0) && (*(int *)(&DAT_005350d8 + param_3 * 4) == 0)) {
          DAT_00523af8 = iVar5 / 5 + DAT_005228f4;
          DAT_00534d70 = iVar1 / 5 + DAT_005229f4;
        }
      }
      if (DAT_005363c4 == 1) {
        DAT_00523af8 = iVar5 / 2 + DAT_005228f4;
        DAT_00534d70 = (iVar1 / 2 - (int)(longlong)(param_2 * _DAT_004cc570)) + DAT_005229f4;
      }
      if (DAT_0053652c == 1) {
        DAT_00523af8 = iVar5 / 3 + DAT_005228f4;
        DAT_00534d70 = (iVar1 / 3 - (int)(longlong)(param_2 * _DAT_004cc570)) + DAT_005229f4;
      }
      if ((DAT_0053652c == 0) || (0 < *(int *)(&DAT_005350d8 + param_3 * 4))) {
        FUN_004b4d9d(param_1,aiStack_8,DAT_005228f4,DAT_005229f4);
        CDC::LineTo(param_1,DAT_00523af8,DAT_00534d70);
      }
    }
    if (DAT_005363c4 == 1) {
      iVar1 = (int)(longlong)(param_2 * _DAT_004cc570);
      param_3 = ((DAT_00522904 - DAT_005228ec) * 4) / 5 + DAT_00522904;
      iVar2 = (((DAT_00522a04 - DAT_005229ec) * 4) / 5 - iVar1) + DAT_00522a04;
      iVar5 = ((DAT_005228fc - DAT_005228e4) * 4) / 5 + DAT_005228fc;
      iVar4 = (((DAT_005229fc - DAT_005229e4) * 4) / 5 - iVar1) + DAT_005229fc;
      FUN_004b4d9d(param_1,(int *)&param_2,DAT_00522904,DAT_00522a04);
      CDC::LineTo(param_1,param_3,iVar2);
      CDC::LineTo(param_1,iVar5,iVar4);
      CDC::LineTo(param_1,DAT_005228fc,DAT_005229fc);
      param_3 = ((DAT_00522914 - DAT_005228ec) * 4) / 5 + DAT_00522914;
      iVar2 = (((DAT_00522a14 - DAT_005229ec) * 4) / 5 - iVar1) + DAT_00522a14;
      iVar5 = ((DAT_0052291c - DAT_005228e4) * 4) / 5 + DAT_0052291c;
      iVar1 = (((DAT_00522a1c - DAT_005229e4) * 4) / 5 - iVar1) + DAT_00522a1c;
      FUN_004b4d9d(param_1,(int *)&param_2,DAT_00522914,DAT_00522a14);
      CDC::LineTo(param_1,param_3,iVar2);
      CDC::LineTo(param_1,iVar5,iVar1);
      CDC::LineTo(param_1,DAT_0052291c,DAT_00522a1c);
      if (DAT_00522d14 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_00522d14);
      }
      FUN_004b4d9d(param_1,(int *)&param_2,DAT_0052291c,DAT_00522a1c);
      CDC::LineTo(param_1,DAT_005228fc,DAT_005229fc);
    }
  }
  return;
}

