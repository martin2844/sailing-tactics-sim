
void FUN_00484270(int *param_1)

{
  HDC hdc;
  HGDIOBJ h;
  
  if ((DAT_005363e4 == 0) && (DAT_00536450 == 0)) {
    (**(code **)(*param_1 + 0x2c))(param_1,8);
    if (DAT_005363a4 == (HGDIOBJ)0x0) goto LAB_004842ef;
    hdc = (HDC)param_1[1];
    h = DAT_005363a4;
  }
  else {
    if (DAT_004fe174 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe174);
    }
    if (DAT_004fe07c == (HGDIOBJ)0x0) goto LAB_004842ef;
    hdc = (HDC)param_1[1];
    h = DAT_004fe07c;
  }
  SelectObject(hdc,h);
LAB_004842ef:
  if (DAT_00536450 == 1) {
    (**(code **)(*param_1 + 0x2c))(param_1,8);
    if (DAT_005230cc != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
  }
  return;
}

