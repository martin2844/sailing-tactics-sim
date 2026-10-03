
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00417790(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  
  bVar1 = false;
  bVar3 = false;
  bVar4 = false;
  bVar2 = false;
  DAT_004ac910 = 0;
  DAT_004ac900 = 0;
  DAT_004ac904 = 0;
  DAT_004ac908 = 0;
  DAT_004ac90c = 0;
  DAT_004ac914 = 0;
  switch(DAT_00491144) {
  case 1:
    bVar2 = true;
    DAT_00491188 = 1;
    DAT_004ac914 = 1;
    break;
  case 2:
    DAT_00491188 = 1;
    break;
  case 3:
    bVar1 = true;
    DAT_00491188 = 1;
    DAT_004ac904 = 1;
    break;
  case 4:
    DAT_00491188 = 2;
    break;
  case 5:
    bVar3 = true;
    DAT_00491188 = 2;
    DAT_004ac910 = 1;
    break;
  case 6:
    DAT_00491188 = 3;
    break;
  case 7:
    bVar4 = true;
    DAT_00491188 = 3;
    DAT_004ac90c = 1;
    break;
  case 8:
    DAT_00491188 = 4;
    break;
  case 9:
    DAT_00491188 = 5;
    break;
  case 10:
    DAT_004ac900 = 1;
    DAT_00491188 = 9;
    break;
  case 0xb:
    DAT_004ac900 = 1;
    DAT_00491188 = 10;
    break;
  case 0xc:
    DAT_00491188 = 6;
    break;
  case 0xd:
    DAT_004ac908 = 1;
    DAT_00491188 = 7;
    break;
  case 0xe:
    DAT_00491188 = 7;
    break;
  case 0xf:
    DAT_00491188 = 8;
  }
  if ((DAT_004ac91c < 8) || (0xb < DAT_004ac91c)) {
    DAT_004a4eec = 10;
  }
  else {
    DAT_004a4eec = DAT_004ac91c;
  }
  if ((DAT_004ac920 < 8) || (DAT_004a5b90 = DAT_004ac920, 0xb < DAT_004ac920)) {
    DAT_004a5b90 = 10;
  }
  if ((DAT_00491188 != 7) || (DAT_00491150 = 100, DAT_004ac908 != 0)) {
    DAT_00491150 = 0x50;
  }
  if (0 < DAT_004ac924) {
    DAT_00491150 = DAT_004ac924;
  }
  if (DAT_00491188 < 6) {
    DAT_00491150 = 0x50;
    DAT_004a4eec = 10;
    DAT_004a5b90 = 10;
  }
  if (DAT_00491188 == 1) {
    if (bVar1) {
      DAT_004a4eec = 6;
      DAT_004a5ba4 = 0x28;
      DAT_004a5b90 = 10;
    }
    else {
      DAT_004a4eec = 6;
      DAT_004a5ba4 = 0xe;
    }
  }
  if ((DAT_00491188 == 1) && (bVar2)) {
    DAT_004a5ba4 = 0xb;
    DAT_004a4eec = 10;
    DAT_004a5b90 = 10;
  }
  if (DAT_00491188 == 2) {
    if (bVar3) {
      DAT_004a5ba4 = 0xe;
      DAT_004a4eec = 6;
    }
    else {
      DAT_004a5ba4 = 0xf;
      DAT_004a4eec = 7;
    }
  }
  if (DAT_00491188 == 3) {
    DAT_004a4eec = 5;
    if (bVar4) {
      DAT_004a5ba4 = 0x1e;
      DAT_004a5b90 = 0xb;
    }
    else {
      DAT_004a5ba4 = 0x12;
      DAT_004a5b90 = 10;
    }
  }
  if (DAT_00491188 == 4) {
    DAT_004a4eec = 6;
    DAT_004a5ba4 = 0x10;
  }
  if (DAT_00491188 == 5) {
    DAT_004a4eec = 7;
    DAT_004a5ba4 = 0x11;
  }
  if ((DAT_00491188 == 6) &&
     ((DAT_004ac918 < 0x14 || (DAT_004a5ba4 = DAT_004ac918, 0x32 < DAT_004ac918)))) {
    DAT_004a5ba4 = 0x19;
  }
  if (((DAT_00491188 == 7) && (DAT_004ac908 == 0)) &&
     ((DAT_004ac918 < 0x14 || (DAT_004a5ba4 = DAT_004ac918, 0x32 < DAT_004ac918)))) {
    DAT_004a5ba4 = 0x28;
  }
  if (DAT_004ac908 == 1) {
    DAT_004a5ba4 = 0x19;
    DAT_004a4eec = 7;
    DAT_004a5b90 = 0xb;
  }
  if ((DAT_00491188 < 7) || (8 < DAT_00491188)) {
    DAT_0049114c = 0xffffffff;
  }
  if (DAT_00491188 == 8) {
    DAT_004a4eec = 10;
    DAT_004a5ba4 = 0x3d;
    DAT_004a5b90 = 0xc;
    DAT_00491150 = 0x50;
    DAT_0049114c = 1;
  }
  if ((DAT_00491188 == 9) || (DAT_00491188 == 10)) {
    DAT_004a4eec = 6;
    DAT_004a5ba4 = 0x25;
    DAT_004a5b90 = 10;
    DAT_00491150 = 0x50;
  }
  _DAT_004ab0c0 = SQRT(_DAT_00484fd8 / (double)DAT_004a5ba4);
  if ((DAT_00491188 != 7) && (DAT_004ac990 = 0, DAT_00491194 == 8)) {
    DAT_00491194 = 1;
  }
  return;
}

