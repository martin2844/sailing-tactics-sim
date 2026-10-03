
void FUN_00426890(int *param_1,uint param_2)

{
  uint uVar1;
  HDC hdc;
  HGDIOBJ h;
  
  if ((DAT_004da190 == 2) || (DAT_004da190 == 9)) {
    (**(code **)(*param_1 + 0x2c))(param_1,0);
    return;
  }
  uVar1 = (int)param_2 >> 0x1f;
  if (((param_2 ^ uVar1) - uVar1 & 1 ^ uVar1) == uVar1) {
    if (DAT_005233b4 == (HGDIOBJ)0x0) goto LAB_00426905;
    hdc = (HDC)param_1[1];
    h = DAT_005233b4;
  }
  else {
    if (DAT_00522fcc == (HGDIOBJ)0x0) goto LAB_00426905;
    hdc = (HDC)param_1[1];
    h = DAT_00522fcc;
  }
  SelectObject(hdc,h);
LAB_00426905:
  if ((param_2 == 1) && (DAT_004fb25c != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004fb25c);
  }
  if ((param_2 == 2) && (DAT_004f41ec != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004f41ec);
  }
  if ((((param_2 == 4) || (param_2 == 9)) || (param_2 == 0xc)) && (DAT_004fb6ac != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004fb6ac);
  }
  if (((param_2 == 5) || (param_2 == 0xd)) && (DAT_004fb244 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004fb244);
  }
  if (((param_2 == 6) || (param_2 == 0xb)) && (DAT_004ff034 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004ff034);
  }
  if (((param_2 == 3) || (param_2 == 10)) && (DAT_004f3864 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004f3864);
  }
  if (DAT_005363e4 == 1) {
    if (DAT_004f3f5c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f3f5c);
    }
    if ((param_2 == 2) && (DAT_004da140 == 2)) {
      (**(code **)(*param_1 + 0x2c))(param_1,0);
    }
  }
  if ((DAT_004da190 == 8) && (DAT_00522ad0 < 0xf)) {
    (**(code **)(*param_1 + 0x2c))(param_1,0);
  }
  if ((DAT_00536450 == 1) && (DAT_004fe07c != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004fe07c);
  }
  if ((param_2 == 1) && (DAT_004f41f4 == 1)) {
    (**(code **)(*param_1 + 0x2c))(param_1,5);
  }
  if (((param_2 == 2) && (DAT_004f41f8 == 1)) && (DAT_004da140 == 2)) {
    (**(code **)(*param_1 + 0x2c))(param_1,5);
    return;
  }
  return;
}

