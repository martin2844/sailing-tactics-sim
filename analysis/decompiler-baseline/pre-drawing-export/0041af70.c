
void __cdecl FUN_0041af70(int *param_1,uint param_2)

{
  uint uVar1;
  HDC hdc;
  HGDIOBJ h;
  
  if ((DAT_00491188 == 2) || (DAT_00491188 == 9)) {
    (**(code **)(*param_1 + 0x2c))(0);
    return;
  }
  uVar1 = (int)param_2 >> 0x1f;
  if (((param_2 ^ uVar1) - uVar1 & 1 ^ uVar1) == uVar1) {
    if (DAT_004aa98c == (HGDIOBJ)0x0) goto LAB_0041afe5;
    hdc = (HDC)param_1[1];
    h = DAT_004aa98c;
  }
  else {
    if (DAT_004aa714 == (HGDIOBJ)0x0) goto LAB_0041afe5;
    hdc = (HDC)param_1[1];
    h = DAT_004aa714;
  }
  SelectObject(hdc,h);
LAB_0041afe5:
  if ((param_2 == 1) && (DAT_004a3a14 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004a3a14);
  }
  if ((param_2 == 2) && (DAT_004a6234 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004a6234);
  }
  if ((((param_2 == 4) || (param_2 == 9)) || (param_2 == 0xc)) && (DAT_004a6484 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004a6484);
  }
  if (((param_2 == 5) || (param_2 == 0xd)) && (DAT_004a621c != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004a621c);
  }
  if (((param_2 == 6) || (param_2 == 0xb)) && (DAT_004a7f24 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004a7f24);
  }
  if (((param_2 == 3) || (param_2 == 10)) && (DAT_004a3a14 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004a3a14);
  }
  if (DAT_004ac92c == 1) {
    if (DAT_004a3efc != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004a3efc);
    }
    if ((param_2 == 2) && (DAT_00491140 == 2)) {
      (**(code **)(*param_1 + 0x2c))(0);
    }
  }
  if ((DAT_004ac98c == 1) && (DAT_004a70e4 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004a70e4);
  }
  if ((param_2 == 1) && (DAT_004a40c4 == 1)) {
    (**(code **)(*param_1 + 0x2c))(5);
  }
  if (((param_2 == 2) && (DAT_004a40c8 == 1)) && (DAT_00491140 == 2)) {
    (**(code **)(*param_1 + 0x2c))(5);
    return;
  }
  return;
}

