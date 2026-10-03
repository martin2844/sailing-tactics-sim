
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041e3c0(int *param_1,double param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  (**(code **)(*param_1 + 0x2c))(param_1,8);
  FUN_0041ed90(param_1,param_4);
  iVar3 = (int)(longlong)(param_2 * _DAT_004cc4f8);
  if (param_3 == 1) {
    iVar3 = (iVar3 * 3) / 2;
  }
  if (DAT_0053652c == 1) {
    iVar3 = iVar3 + 1;
  }
  _DAT_004f6e38 = DAT_00522900;
  iVar1 = (DAT_005228e8 + DAT_00522900 * 2) / 3;
  _DAT_004f6e3c = DAT_00522a00;
  iVar4 = (DAT_005229e8 + DAT_00522a00 * 2) / 3 + iVar3;
  iVar2 = (DAT_005228ec + DAT_00522904 * 2) / 3;
  iVar5 = (DAT_005229ec + DAT_00522a04 * 2) / 3 + iVar3;
  _DAT_004f6e2c = DAT_005229f8;
  _DAT_004f6e34 = DAT_005229fc;
  _DAT_004f6e28 = DAT_005228f8;
  _DAT_004f6e4c = DAT_004fb9c4;
  _DAT_004f6e30 = DAT_005228fc;
  _DAT_004f6e48 = DAT_004f4518;
  _DAT_004f6e40 = iVar1;
  _DAT_004f6e44 = iVar4;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,5);
  _DAT_004f6e28 = DAT_00522900;
  _DAT_004f6e2c = DAT_00522a00;
  _DAT_004f6e30 = DAT_00522904;
  _DAT_004f6e34 = DAT_00522a04;
  _DAT_004f6e38 = iVar2;
  _DAT_004f6e3c = iVar5;
  _DAT_004f6e40 = iVar1;
  _DAT_004f6e44 = iVar4;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  _DAT_004f6e28 = DAT_00522904;
  _DAT_004f6e2c = DAT_00522a04;
  _DAT_004f6e34 = DAT_00522a08;
  _DAT_004f6e30 = DAT_00522908;
  _DAT_004f6e38 = DAT_005228f4;
  _DAT_004f6e3c = DAT_005229f4;
  if (((DAT_005364bc == 1) || (DAT_004da190 == 8)) || (DAT_004da190 == 3)) {
    _DAT_004f6e40 = (DAT_005362cc + DAT_005228f4 * 4) / 5;
    _DAT_004f6e44 = iVar3 / 3 + (DAT_004f4090 + DAT_005229f4 * 4) / 5;
  }
  else {
    _DAT_004f6e40 = (DAT_005362cc + DAT_005228f4) / 2;
    _DAT_004f6e44 = (DAT_004f4090 + DAT_005229f4) / 2;
  }
  if ((DAT_00536528 == 1) || (DAT_0053652c == 1)) {
    _DAT_004f6e40 = (DAT_005362cc + DAT_005228f4 * 2) / 3;
    _DAT_004f6e44 = iVar3 / 3 + (DAT_004f4090 + DAT_005229f4 * 2) / 3;
  }
  _DAT_004f6e48 = DAT_005362cc;
  _DAT_004f6e4c = DAT_004f4090;
  _DAT_004f6e50 = iVar2;
  _DAT_004f6e54 = iVar5;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,6);
  if (((DAT_00536450 == 1) && (0 < param_4)) && (DAT_005363e4 == 0)) {
    if (DAT_005233b4 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_005233b4);
    }
    if (DAT_004f1cec != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f1cec);
    }
    FUN_00433a70(param_1,2,DAT_005228f4,DAT_005229f4);
  }
  return;
}

