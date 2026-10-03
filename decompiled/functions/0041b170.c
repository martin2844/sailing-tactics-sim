
void FUN_0041b170(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00415a20(4);
  DAT_004a70dc = iVar1 * 3 + 10;
  if (DAT_00491154 == 1) {
    DAT_004a70dc = iVar1 + 8;
  }
  if (DAT_00491154 == 2) {
    DAT_004a70dc = iVar1 + 0xc;
  }
  if (DAT_00491154 == 3) {
    DAT_004a70dc = iVar1 + 0x10;
  }
  iVar1 = FUN_00415a20(7);
  DAT_004a5e88 = iVar1 + 1;
  if (DAT_00491194 == 9) {
    uVar2 = (int)DAT_004a5e88 >> 0x1f;
    if (((DAT_004a5e88 ^ uVar2) - uVar2 & 1 ^ uVar2) == uVar2) {
      DAT_004a5e88 = iVar1 + 2;
    }
    if (DAT_004a5e88 == 7) {
      DAT_004a5e88 = 1;
    }
  }
  if (DAT_00491194 == 10) {
    DAT_004a5e88 = ((4 < (int)DAT_004a5e88) - 1 & 0xfffffffc) + 5;
  }
  if (8 < (int)DAT_004a5e88) {
    DAT_004a5e88 = 1;
  }
  if (DAT_004a5a4c == 1) {
    iVar1 = FUN_00415a20(0x1d);
    DAT_004a5e88 = iVar1 / 10 + 4;
  }
  if (DAT_00491194 == 8) {
    if (DAT_004a5a4c == 0) {
      iVar1 = FUN_00415a20(10);
      DAT_004a5e88 = ((iVar1 < 5) - 1 & 0xfffffffc) + 7;
    }
    if (DAT_00491194 == 8) goto LAB_0041b2a8;
  }
  if ((DAT_004a5a4c == 0) && (DAT_00491140 == 2)) {
    DAT_004a5e88 = 1;
  }
LAB_0041b2a8:
  iVar1 = FUN_00415a20(0xe);
  DAT_004a4430 = FUN_00413cb0(iVar1 + -0x34 + DAT_004a5e88 * 0x2d);
  iVar1 = FUN_00415a20(10);
  DAT_004ac1e0 = (uint)(iVar1 < 5);
  iVar1 = FUN_00415a20(10);
  if (iVar1 < 6) {
    DAT_004a8990 = DAT_004a5e88 + 2;
  }
  DAT_004aa8bc = (uint)(iVar1 >= 6);
  if (8 < DAT_004a8990) {
    DAT_004a8990 = DAT_004a8990 + -8;
  }
  if (5 < iVar1) {
    DAT_004a8990 = DAT_004a5e88 - 2;
  }
  if (DAT_004a8990 < 1) {
    DAT_004a8990 = DAT_004a8990 + 8;
  }
  iVar1 = FUN_00415a20(5);
  DAT_004abc7c = iVar1 - 2;
  if (((DAT_004a8990 == 1) || (DAT_004a8990 == 2)) || (DAT_004a8990 == 3)) {
    iVar1 = FUN_00415a20(3);
    DAT_004abc7c = iVar1 + 3;
  }
  if (((DAT_004a8990 == 4) || (DAT_004a8990 == 5)) || (DAT_004a8990 == 6)) {
    iVar1 = FUN_00415a20(3);
    DAT_004abc7c = -iVar1 - 3;
  }
  if (DAT_004ac998 == 1) {
    DAT_004abc7c = -DAT_004abc7c;
  }
  DAT_004a5a48 = (uint)(4 < (int)((DAT_004abc7c ^ (int)DAT_004abc7c >> 0x1f) -
                                 ((int)DAT_004abc7c >> 0x1f)));
  if (DAT_00491194 == 8) {
    DAT_004abc7c = (int)DAT_004abc7c / 2;
  }
  iVar1 = 1;
  DAT_004a8a78 = 3;
  DAT_004a7758 = 0x55;
  DAT_004a5b98 = 1;
  if ((7 < (int)DAT_004a5e88) || ((int)DAT_004a5e88 < 3)) {
    DAT_004a8a78 = 1;
    DAT_004a7758 = 0x4b;
  }
  if ((DAT_004a5e88 == 7) || (DAT_004a5e88 == 3)) {
    DAT_004a8a78 = 2;
    DAT_004a7758 = 0x50;
  }
  if ((DAT_004a5e88 == 2) || (DAT_004a5e88 == 3)) {
    iVar1 = 3;
    DAT_004a5b98 = 3;
  }
  if ((DAT_004a5e88 == 4) || (DAT_004a5e88 == 5)) {
    iVar1 = 2;
    DAT_004a5b98 = 2;
  }
  if (iVar1 == 4) {
    DAT_004a8a78 = 3;
  }
  iVar1 = FUN_00415a20(10);
  DAT_004a609c = iVar1 + 0x3a;
  DAT_004a79ec = ((DAT_004a7758 - DAT_004a609c) * 3) / (DAT_004a5b98 * DAT_004a8a78 * 2);
  if ((DAT_00491154 == 2) || (DAT_00491154 == 1)) {
    DAT_004a79ec = DAT_004a79ec / 2;
  }
  if ((0 < DAT_004a4958) && (DAT_004a4958 < 5)) {
    DAT_004a79ec = 0;
  }
  if (DAT_004ac990 == 1) {
    DAT_004a5bac = 0x15;
    DAT_004a4be4 = 0x15;
    return;
  }
  iVar1 = FUN_00415a20(4);
  DAT_004a5bac = iVar1 + 10;
  DAT_004a4be4 = iVar1 + 10;
  return;
}

