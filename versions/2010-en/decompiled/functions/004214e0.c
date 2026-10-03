
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004214e0(int *param_1,int param_2)

{
  _DAT_004f6e28 = DAT_00522908;
  _DAT_004f6e2c = DAT_00522a08;
  _DAT_004f6e34 = DAT_00522a04;
  _DAT_004f6e30 = DAT_00522904;
  _DAT_004f6e40 = DAT_005228f8;
  _DAT_004f6e38 = DAT_005228fc;
  _DAT_004f6e4c = DAT_00522a00;
  _DAT_004f6e3c = DAT_005229fc;
  _DAT_004f6e44 = DAT_005229f8;
  _DAT_004f6e48 = DAT_00522900;
  if (DAT_005363e4 == 0) {
    if (DAT_004f7f74 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7f74);
    }
  }
  else {
    (**(code **)(*param_1 + 0x2c))(param_1,0);
  }
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,5);
  _DAT_004f6e28 = DAT_00522910;
  _DAT_004f6e2c = DAT_00522a10;
  _DAT_004f6e30 = DAT_00522918;
  _DAT_004f6e34 = DAT_00522a18;
  _DAT_004f6e38 = DAT_00522920;
  _DAT_004f6e3c = DAT_00522a20;
  _DAT_004f6e40 = DAT_0052291c;
  _DAT_004f6e44 = DAT_00522a1c;
  _DAT_004f6e48 = DAT_00522914;
  _DAT_004f6e4c = DAT_00522a14;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,5);
  return;
}

