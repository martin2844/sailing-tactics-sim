
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00421f10(int *param_1,double param_2,double param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  HDC hdc;
  HGDIOBJ h;
  
  _DAT_004f6e30 = DAT_00522900;
  _DAT_004f6e38 = (DAT_00522900 + DAT_005228f8 * 2) / 3;
  _DAT_004f6e28 = DAT_00522914;
  _DAT_004f6e3c = (DAT_00522a00 + DAT_005229f8 * 2) / 3;
  _DAT_004f6e34 = DAT_00522a00;
  _DAT_004f6e2c = DAT_00522a14;
  _DAT_004f6e40 = (DAT_00522914 + DAT_0052291c * 2) / 3;
  _DAT_004f6e44 = (DAT_00522a14 + DAT_00522a1c * 2) / 3;
  iVar1 = (DAT_00522904 + DAT_005228fc * 2) / 3;
  iVar2 = (DAT_00522a04 + DAT_005229fc * 2) / 3;
  iVar3 = (DAT_00522918 + DAT_00522920 * 2) / 3;
  iVar4 = (DAT_00522a18 + DAT_00522a20 * 2) / 3;
  if (DAT_004f3f5c != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f3f5c);
  }
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  if (param_3 <= _DAT_004cc738) {
    if (DAT_004fe174 == (HGDIOBJ)0x0) goto LAB_004220b7;
    hdc = (HDC)param_1[1];
    h = DAT_004fe174;
  }
  else {
    if (DAT_00522d14 == (HGDIOBJ)0x0) goto LAB_004220b7;
    hdc = (HDC)param_1[1];
    h = DAT_00522d14;
  }
  SelectObject(hdc,h);
LAB_004220b7:
  FUN_004b4d9d(param_1,(int *)&param_3,DAT_00522904,DAT_00522a04);
  CDC::LineTo(param_1,DAT_00522918,DAT_00522a18);
  FUN_004b4d9d(param_1,(int *)&param_3,iVar1,iVar2);
  CDC::LineTo(param_1,iVar3,iVar4);
  DAT_004f4d70 = iVar1;
  DAT_004f4d74 = iVar4;
  DAT_004f69b0 = iVar3;
  DAT_004f7088 = iVar2;
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  FUN_004b4d9d(param_1,(int *)&param_3,DAT_00522910,DAT_00522a10);
  CDC::LineTo(param_1,DAT_005228f4,DAT_005229f4 - (int)(longlong)(param_2 * _DAT_004cc570));
  CDC::LineTo(param_1,DAT_00522908,DAT_00522a08);
  if (DAT_004da190 == 10) {
    iVar1 = (int)(longlong)(param_2 * _DAT_004cc5f0);
    DAT_00523af8 = (DAT_005228f4 - DAT_005228ec) / 3 + DAT_005228f4;
    DAT_00534d70 = (((DAT_005229f4 - iVar1) - DAT_005229ec) / 3 - iVar1) + DAT_005229f4;
    FUN_004b4d9d(param_1,(int *)&param_2,DAT_005228ec,DAT_005229ec);
    CDC::LineTo(param_1,DAT_00523af8,DAT_00534d70);
  }
  return;
}

