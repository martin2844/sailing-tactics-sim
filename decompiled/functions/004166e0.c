
void __cdecl FUN_004166e0(int param_1,int param_2)

{
  HDC hdc;
  HGDIOBJ h;
  
  if (DAT_004ac92c != 0) {
    if ((param_2 == 1) && (DAT_004a4ee4 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
    }
    if (param_2 < 2) {
      return;
    }
    if (DAT_004a4dec == (HGDIOBJ)0x0) {
      return;
    }
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    return;
  }
  if ((param_2 == 1) && (DAT_004a676c != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a676c);
  }
  if ((param_2 == 2) && (DAT_004a39fc != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a39fc);
  }
  if ((((param_2 == 3) || (param_2 == 0xc)) || (param_2 == 0x15)) && (DAT_004a67ac != (HGDIOBJ)0x0))
  {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a67ac);
  }
  if ((((param_2 == 4) || (param_2 == 0xd)) || ((param_2 == 0x16 || (param_2 == 0)))) &&
     (DAT_004aa634 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004aa634);
  }
  if ((((param_2 == 5) || (param_2 == 0xe)) || (param_2 == 0x17)) && (DAT_004a3f9c != (HGDIOBJ)0x0))
  {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a3f9c);
  }
  if ((((param_2 == 6) || (param_2 == 0xf)) || (param_2 == 0x18)) && (DAT_004abbf4 != (HGDIOBJ)0x0))
  {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004abbf4);
  }
  if ((((param_2 == 7) || (param_2 == 0x10)) || (param_2 == 0x19)) && (DAT_004a4dec != (HGDIOBJ)0x0)
     ) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  if ((((param_2 == 8) || (param_2 == 0x11)) || (param_2 == 0x1a)) && (DAT_004aa7ec != (HGDIOBJ)0x0)
     ) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004aa7ec);
  }
  if ((((param_2 == 9) || (param_2 == 0x12)) || (param_2 == 0x1b)) && (DAT_004a3a2c != (HGDIOBJ)0x0)
     ) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a3a2c);
  }
  if ((((param_2 == 10) || (param_2 == 0x13)) || (param_2 == 0x1c)) &&
     (DAT_004aa7d4 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004aa7d4);
  }
  if ((((param_2 == 0xb) || (param_2 == 0x14)) || (0x1c < param_2)) &&
     (DAT_004ac30c != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004ac30c);
  }
  if (DAT_004ac98c != 1) {
    return;
  }
  if (param_2 == 1) {
    if (DAT_004aa7ec == (HGDIOBJ)0x0) goto LAB_00416911;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004aa7ec;
  }
  else {
    if (DAT_004aa634 == (HGDIOBJ)0x0) goto LAB_00416911;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004aa634;
  }
  SelectObject(hdc,h);
LAB_00416911:
  if (((param_2 == 2) && (DAT_00491140 == 2)) && (DAT_004a3a2c != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a3a2c);
    return;
  }
  return;
}

