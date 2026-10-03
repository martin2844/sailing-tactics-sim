
void FUN_0041f130(int param_1,int param_2)

{
  HDC hdc;
  HGDIOBJ h;
  
  if (DAT_005363e4 != 0) {
    if ((param_2 == 1) && (DAT_004f7ec4 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004f7ec4);
    }
    if (param_2 < 2) {
      return;
    }
    if (DAT_004f7084 == (HGDIOBJ)0x0) {
      return;
    }
    SelectObject(*(HDC *)(param_1 + 4),DAT_004f7084);
    return;
  }
  if ((param_2 == 1) && (DAT_004fb994 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004fb994);
  }
  if ((param_2 == 2) && (DAT_004f1cec != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004f1cec);
  }
  if ((((param_2 == 3) || (param_2 == 0xc)) || (param_2 == 0x15)) && (DAT_004fba14 != (HGDIOBJ)0x0))
  {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004fba14);
  }
  if ((((param_2 == 4) || (param_2 == 0xd)) || ((param_2 == 0x16 || (param_2 == 0)))) &&
     (DAT_00522d14 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_00522d14);
  }
  if ((((param_2 == 5) || (param_2 == 0xe)) || (param_2 == 0x17)) && (DAT_004f40a4 != (HGDIOBJ)0x0))
  {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004f40a4);
  }
  if ((((param_2 == 6) || (param_2 == 0xf)) || (param_2 == 0x18)) && (DAT_0053516c != (HGDIOBJ)0x0))
  {
    SelectObject(*(HDC *)(param_1 + 4),DAT_0053516c);
  }
  if ((((param_2 == 7) || (param_2 == 0x10)) || (param_2 == 0x19)) && (DAT_00522f1c != (HGDIOBJ)0x0)
     ) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_00522f1c);
  }
  if ((((param_2 == 8) || (param_2 == 0x11)) || (param_2 == 0x1a)) && (DAT_005230c4 != (HGDIOBJ)0x0)
     ) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_005230c4);
  }
  if ((((param_2 == 9) || (param_2 == 0x12)) || (param_2 == 0x1b)) && (DAT_004f3a2c != (HGDIOBJ)0x0)
     ) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004f3a2c);
  }
  if ((((param_2 == 10) || (param_2 == 0x13)) || (param_2 == 0x1c)) &&
     (DAT_005230ac != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_005230ac);
  }
  if ((((param_2 == 0xb) || (param_2 == 0x14)) || (0x1c < param_2)) &&
     (DAT_00535c64 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_00535c64);
  }
  if (DAT_00536450 != 1) {
    return;
  }
  if (param_2 == 1) {
    if (DAT_005230c4 == (HGDIOBJ)0x0) goto LAB_0041f361;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_005230c4;
  }
  else {
    if (DAT_00522d14 == (HGDIOBJ)0x0) goto LAB_0041f361;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_00522d14;
  }
  SelectObject(hdc,h);
LAB_0041f361:
  if (((param_2 == 2) && (DAT_004da140 == 2)) && (DAT_004f3a2c != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004f3a2c);
    return;
  }
  return;
}

