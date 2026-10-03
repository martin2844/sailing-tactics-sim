
void __cdecl FUN_00416420(int *param_1,int param_2)

{
  HDC hdc;
  HGDIOBJ h;
  
  if (DAT_004ac92c == 0) {
    if (param_2 == 0) {
      (**(code **)(*param_1 + 0x2c))(param_1,0);
    }
    if ((param_2 == 1) && (DAT_004a3a14 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004a3a14);
    }
    if ((param_2 == 2) && (DAT_004aa98c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004aa98c);
    }
    if ((((param_2 == 3) || (param_2 == 0xc)) || (param_2 == 0x15)) &&
       (DAT_004a6234 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004a6234);
    }
    if ((((param_2 == 4) || (param_2 == 0xd)) || (param_2 == 0x16)) &&
       (DAT_004a70e4 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004a70e4);
    }
    if ((((param_2 == 5) || (param_2 == 0xe)) || (param_2 == 0x17)) &&
       (DAT_004a4f7c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004a4f7c);
    }
    if ((((param_2 == 6) || (param_2 == 0xf)) || (param_2 == 0x18)) &&
       (DAT_004a7f24 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004a7f24);
    }
    if (((param_2 == 7) || (param_2 == 0x10)) || (param_2 == 0x19)) {
      (**(code **)(*param_1 + 0x2c))(param_1,4);
    }
    if ((((param_2 == 8) || (param_2 == 0x11)) || (param_2 == 0x1a)) &&
       (DAT_004a6484 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004a6484);
    }
    if ((((param_2 == 9) || (param_2 == 0x12)) || (param_2 == 0x1b)) &&
       (DAT_004a621c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004a621c);
    }
    if ((((param_2 == 10) || (param_2 == 0x13)) || (param_2 == 0x1c)) &&
       (DAT_004a487c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004a487c);
    }
    if ((((param_2 == 0xb) || (param_2 == 0x14)) || (0x1c < param_2)) &&
       (DAT_004a8e04 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004a8e04);
    }
    if (DAT_004ac910 == 1) {
      if (param_2 == 1) {
        (**(code **)(*param_1 + 0x2c))(param_1,0);
      }
      else if (DAT_004a3efc != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004a3efc);
      }
    }
  }
  if (DAT_004ac98c != 1) goto LAB_004166a0;
  if (param_2 == 1) {
    if (DAT_004a6484 != (HGDIOBJ)0x0) {
      hdc = (HDC)param_1[1];
      h = DAT_004a6484;
LAB_00416675:
      SelectObject(hdc,h);
    }
  }
  else if (DAT_004a70e4 != (HGDIOBJ)0x0) {
    hdc = (HDC)param_1[1];
    h = DAT_004a70e4;
    goto LAB_00416675;
  }
  if (((param_2 == 2) && (DAT_00491140 == 2)) && (DAT_004a621c != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004a621c);
  }
LAB_004166a0:
  if (DAT_004ac92c == 1) {
    if ((param_2 == 1) && (DAT_004a70e4 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004a70e4);
    }
    if (1 < param_2) {
      (**(code **)(*param_1 + 0x2c))(param_1,4);
    }
  }
  return;
}

