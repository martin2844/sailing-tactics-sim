
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00417be0(int *param_1)

{
  _DAT_004a4ca8 = DAT_004aa1c8;
  _DAT_004a4cac = DAT_004aa2c8;
  _DAT_004a4cb4 = DAT_004aa2c4;
  _DAT_004a4cb0 = DAT_004aa1c4;
  _DAT_004a4cc0 = DAT_004aa1b8;
  _DAT_004a4cb8 = DAT_004aa1bc;
  _DAT_004a4ccc = DAT_004aa2c0;
  _DAT_004a4cbc = DAT_004aa2bc;
  _DAT_004a4cc4 = DAT_004aa2b8;
  _DAT_004a4cc8 = DAT_004aa1c0;
  if (DAT_004ac92c == 0) {
    if (DAT_004a4f7c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004a4f7c);
    }
  }
  else {
    (**(code **)(*param_1 + 0x2c))(0);
  }
  (**(code **)(*param_1 + 0x2c))(7);
  Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,5);
  _DAT_004a4ca8 = DAT_004aa1d0;
  _DAT_004a4cac = DAT_004aa2d0;
  _DAT_004a4cb0 = DAT_004aa1d8;
  _DAT_004a4cb4 = DAT_004aa2d8;
  _DAT_004a4cb8 = DAT_004aa1e0;
  _DAT_004a4cbc = DAT_004aa2e0;
  _DAT_004a4cc0 = DAT_004aa1dc;
  _DAT_004a4cc4 = DAT_004aa2dc;
  _DAT_004a4cc8 = DAT_004aa1d4;
  _DAT_004a4ccc = DAT_004aa2d4;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,5);
  return;
}

