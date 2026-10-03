
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041a450(int *param_1,int param_2)

{
  HDC hdc;
  HGDIOBJ h;
  
  if ((DAT_004ac928 == 1) && (DAT_00491140 < param_2)) {
    return;
  }
  if (DAT_004ac904 == 1) {
    return;
  }
  _DAT_004a4ca8 = (DAT_004aa1c4 + DAT_004aa1d4 * 2) / 3;
  _DAT_004a4cac = (DAT_004aa2c4 + DAT_004aa2d4 * 2) / 3;
  _DAT_004a4cb0 = (DAT_004aa1d4 + DAT_004aa1c4 * 2) / 3;
  _DAT_004a4cb4 = (DAT_004aa2d4 + DAT_004aa2c4 * 2) / 3;
  _DAT_004a4cb8 = (DAT_004aa1dc + DAT_004aa1bc * 2) / 3;
  _DAT_004a4cbc = (DAT_004aa2dc + DAT_004aa2bc * 2) / 3;
  _DAT_004a4cc0 = (DAT_004aa1bc + DAT_004aa1dc * 2) / 3;
  _DAT_004a4cc4 = (DAT_004aa2bc + DAT_004aa2dc * 2) / 3;
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  if (DAT_004ac910 == 1) {
    if (DAT_004a3efc == (HGDIOBJ)0x0) goto LAB_0041a5b6;
    hdc = (HDC)param_1[1];
    h = DAT_004a3efc;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0041a5b6;
    hdc = (HDC)param_1[1];
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0041a5b6:
  Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,4);
  return;
}

