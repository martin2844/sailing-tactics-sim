
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00420c00(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  
  iVar5 = 0;
  bVar4 = false;
  bVar2 = false;
  bVar1 = false;
  bVar3 = false;
  DAT_005363c8 = 0;
  DAT_005363b8 = 0;
  DAT_005363bc = 0;
  DAT_005363c0 = 0;
  DAT_005363c4 = 0;
  DAT_005363cc = 0;
  DAT_004fb410 = 0;
  DAT_005364bc = 0;
  DAT_005364cc = 0;
  DAT_005364d4 = 0;
  DAT_005364d8 = 0;
  DAT_005364c4 = 0;
  DAT_005364c8 = 0;
  DAT_005364c0 = 0;
  DAT_005364d0 = 0;
  DAT_00513478 = 0;
  DAT_00536528 = 0;
  DAT_0053652c = 0;
  DAT_00536530 = 0;
  switch(DAT_004da144) {
  case 1:
    DAT_004da190 = 1;
    DAT_005363cc = 1;
    break;
  case 2:
    DAT_004da190 = 1;
    DAT_005364d0 = 1;
    break;
  case 3:
    DAT_004da190 = 1;
    DAT_005363bc = 1;
    break;
  case 4:
    DAT_004da190 = 2;
    break;
  case 5:
    DAT_005363c8 = 1;
    DAT_004da190 = 2;
    break;
  case 6:
    DAT_004da190 = 3;
    break;
  case 7:
    DAT_005363c4 = 1;
    DAT_004da190 = 3;
    break;
  case 8:
    bVar3 = false;
    DAT_004da190 = 4;
    DAT_0053652c = 0;
    break;
  case 9:
    DAT_004da190 = 5;
    break;
  case 10:
    bVar4 = true;
    DAT_004da190 = 9;
    DAT_005363b8 = 1;
    break;
  case 0xb:
    bVar4 = true;
    bVar1 = true;
    DAT_004da190 = 10;
    DAT_005363b8 = 1;
    DAT_005364c0 = 1;
    break;
  case 0xc:
    DAT_004da190 = 6;
    break;
  case 0xd:
    iVar5 = 1;
    DAT_004da190 = 7;
    DAT_005363c0 = 1;
    break;
  case 0xe:
    DAT_005364d4 = 1;
    DAT_004da190 = 7;
    break;
  case 0xf:
    DAT_004da14c = 1;
    DAT_004da190 = 8;
    break;
  case 0x10:
    DAT_005364bc = 1;
    DAT_004da190 = 2;
    break;
  case 0x11:
    bVar4 = true;
    DAT_004da190 = 9;
    DAT_005364cc = 1;
    DAT_005363b8 = 1;
    break;
  case 0x12:
    DAT_005364d8 = 1;
    DAT_004da190 = 7;
    break;
  case 0x13:
    DAT_005364c4 = 1;
    DAT_004da190 = 7;
    break;
  case 0x14:
    bVar2 = true;
    DAT_004da190 = 7;
    DAT_005364c8 = 1;
    break;
  case 0x15:
    iVar5 = 2;
    DAT_004da190 = 6;
    DAT_005363c0 = 2;
    DAT_004da14c = 0xffffffff;
    break;
  case 0x16:
    iVar5 = 3;
    DAT_004da190 = 6;
    DAT_005363c0 = 3;
    break;
  case 0x17:
    bVar4 = true;
    DAT_004da190 = 10;
    DAT_005363b8 = 1;
    DAT_005363c0 = 0;
    DAT_004da14c = 1;
    DAT_00513478 = 1;
    break;
  case 0x18:
    DAT_004fb410 = 1;
    DAT_004da190 = 6;
    break;
  case 0x19:
    DAT_00536528 = 1;
    DAT_004da190 = 6;
    break;
  case 0x1a:
    bVar3 = true;
    DAT_004da190 = 5;
    DAT_0053652c = 1;
    break;
  case 0x1b:
    DAT_00536530 = 1;
    DAT_004da190 = 5;
  }
  if ((((((DAT_004da190 == 1) || (DAT_005363c8 == 1)) || (DAT_004da190 == 3)) ||
       ((DAT_005363c4 == 1 || (DAT_004da190 == 2)))) ||
      ((bVar1 || ((bVar2 || (DAT_004fb410 == 1)))))) || (_DAT_0053573c = 1, DAT_00536530 == 1)) {
    _DAT_0053573c = 0;
  }
  if ((DAT_005364bc == 1) || (bVar3)) {
    _DAT_0053573c = 1;
  }
  if (((DAT_005363bc == 1) || (bVar4)) || (_DAT_004f6d28 = 1, bVar2)) {
    _DAT_004f6d28 = 0;
  }
  if (((((DAT_004da190 == 1) || (DAT_004da190 == 4)) ||
       ((DAT_005363c8 == 1 || ((bVar4 || (DAT_005363c4 == 1)))))) || (bVar2)) ||
     ((DAT_004fb410 == 0 || (_DAT_004f4294 = 1, DAT_00536530 == 0)))) {
    _DAT_004f4294 = 0;
  }
  if ((DAT_005363d4 < 8) || (DAT_004f7ecc = DAT_005363d4, 0xb < DAT_005363d4)) {
    DAT_004f7ecc = (iVar5 != 1) + 9;
  }
  if ((DAT_005363d8 < 8) || (0xb < DAT_005363d8)) {
    DAT_004f8d70 = 10;
  }
  else {
    DAT_004f8d70 = DAT_005363d8;
  }
  if (((DAT_004da190 != 7) || (iVar5 != 0)) || (DAT_004da150 = 100, DAT_00536528 != 0)) {
    DAT_004da150 = 0x50;
  }
  if (0 < DAT_005363dc) {
    DAT_004da150 = DAT_005363dc;
  }
  if (DAT_004da190 < 6) {
    DAT_004da150 = 0x50;
    DAT_004f7ecc = 10;
    DAT_004f8d70 = 10;
  }
  if (DAT_005364d0 == 1) {
    DAT_004f7ecc = 5;
    DAT_004faa48 = 8;
  }
  if ((DAT_004da190 == 1) && (DAT_005363bc == 1)) {
    DAT_004f7ecc = 6;
    DAT_004faa48 = 0x28;
    DAT_004f8d70 = 10;
  }
  if ((DAT_004da190 == 1) && (DAT_005363cc == 1)) {
    DAT_004f7ecc = 10;
    DAT_004faa48 = 9;
    DAT_004f8d70 = 10;
  }
  if (DAT_004da190 == 2) {
    DAT_004faa48 = 8;
    DAT_004f7ecc = (DAT_005363c8 != 1) + 5;
    if (DAT_005364bc == 1) {
      DAT_004faa48 = 0x13;
      DAT_004f7ecc = 9;
      DAT_004f8d70 = 0xc;
    }
  }
  if (DAT_004da190 == 3) {
    DAT_004f7ecc = 5;
    if (DAT_005363c4 == 0) {
      DAT_004faa48 = 0x10;
      DAT_004f8d70 = 10;
    }
    else {
      DAT_004f7ecc = 6;
      DAT_004faa48 = 0x18;
      DAT_004f8d70 = 0xb;
    }
  }
  if (DAT_004da190 == 4) {
    DAT_004f7ecc = 6;
    DAT_004faa48 = 10;
  }
  if (DAT_004da190 == 5) {
    DAT_004f7ecc = 7;
    DAT_004faa48 = 0xb;
  }
  if ((((DAT_004da190 == 6) && (iVar5 == 0)) && (DAT_00536528 == 0)) &&
     ((DAT_005363d0 < 0x14 || (DAT_004faa48 = DAT_005363d0, 0x32 < DAT_005363d0)))) {
    DAT_004faa48 = 0x19;
  }
  if ((DAT_004da190 == 7) && (DAT_00536528 == 0)) {
    if ((DAT_005363d0 < 0x14) || (0x32 < DAT_005363d0)) {
      DAT_004faa48 = 0x28;
      if (iVar5 == 1) {
        DAT_004faa48 = 0x28;
      }
    }
    else {
      DAT_004faa48 = DAT_005363d0;
    }
  }
  if (((DAT_004da190 < 7) && (iVar5 != 3)) || (8 < DAT_004da190)) {
    DAT_004da14c = 0xffffffff;
  }
  if (DAT_004da190 == 8) {
    DAT_004f7ecc = 10;
    DAT_004faa48 = 0x5a;
    DAT_004f8d70 = 0xc;
    DAT_004da150 = 0x50;
    DAT_004da14c = 1;
  }
  if (DAT_004da190 == 9) {
    DAT_004f7ecc = 7;
    DAT_004faa48 = 0x1e;
    DAT_004f8d70 = 0xe;
    DAT_004da150 = 0x50;
  }
  if (DAT_004da190 == 10) {
    DAT_004f7ecc = 7;
    DAT_004faa48 = 0x24;
    DAT_004f8d70 = 0xe;
    DAT_004da150 = 0x50;
  }
  if (DAT_005364cc == 1) {
    DAT_004f7ecc = 7;
    DAT_004faa48 = 0x1c;
    DAT_004f8d70 = 0xc;
    DAT_004da150 = 0x50;
  }
  if (DAT_005364c8 == 1) {
    DAT_004faa48 = 0xe;
    DAT_004f7ecc = 10;
    DAT_004f8d70 = 10;
    DAT_004da150 = 0x50;
  }
  if ((iVar5 == 2) || (iVar5 == 3)) {
    DAT_004f8d70 = 0xb;
    DAT_004faa48 = (-(uint)(iVar5 != 2) & 5) + 0x10;
    DAT_004f7ecc = 6;
  }
  if (DAT_00513478 == 1) {
    DAT_004f7ecc = 6;
    DAT_004faa48 = 0x1e;
    DAT_004f8d70 = 0xb;
    DAT_004da150 = 0x50;
    DAT_004da14c = 1;
  }
  if (DAT_004fb410 == 1) {
    DAT_004f7ecc = 9;
    DAT_004faa48 = 0x12;
    DAT_004f8d70 = 0xc;
    DAT_004da150 = 0x50;
  }
  if (DAT_00536528 == 1) {
    DAT_004f7ecc = 8;
    DAT_004faa48 = 0x16;
    DAT_004f8d70 = 10;
    DAT_004da150 = 0x50;
  }
  if (DAT_0053652c == 1) {
    DAT_004f7ecc = 5;
    DAT_004faa48 = 0x1b;
    DAT_004f8d70 = 8;
    DAT_004da150 = 0x50;
  }
  if (DAT_00536530 == 1) {
    DAT_004da150 = 0x50;
    DAT_004faa48 = 10;
    DAT_004f7ecc = 6;
    DAT_004f8d70 = 10;
  }
  _DAT_00523d48 = SQRT(_DAT_004cc838 / (double)DAT_004faa48);
  if (((DAT_004da190 != 7) && (DAT_00513478 == 0)) && (DAT_00536454 = 0, DAT_004da19c == 8)) {
    DAT_004da19c = 1;
  }
  return;
}

