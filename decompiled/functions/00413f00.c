
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00413f00(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_0041f0b0();
  iVar2 = 1;
  DAT_004ac93c = 0;
  _DAT_004a8658 = (-(uint)(DAT_00491194 != 8) & 0xfffffe89) + 0x2a3;
  DAT_004a4168 = 0xffffff56;
  DAT_004ac1fc = 0xc0655000;
  DAT_004a5b80 = 0xffffff56;
  if (DAT_004ac9ac == 1) {
    DAT_004a4168 = 0;
    DAT_004a5b80 = 0;
    DAT_004ac1fc = 0;
  }
  if (DAT_004911cc < 3) {
    DAT_004a4168 = 0;
    DAT_004a5b80 = 0;
    DAT_004ac1fc = 0;
  }
  if (DAT_004911cc == 10) {
    DAT_004a4168 = 0xfffffeac;
    DAT_004a5b80 = 0xfffffeac;
    DAT_004ac1fc = 0xc0755000;
  }
  DAT_004ac1f8 = 0;
  _DAT_004ab8b8 = (double)((ulonglong)DAT_004ac1fc << 0x20) * _DAT_00484f08;
  FUN_0041b170();
  FUN_0041b510();
  FUN_0041b5d0();
  FUN_0042e0a0();
  FUN_004201a0(10);
  FUN_0041eb80();
  puVar1 = &DAT_004aaa24;
  do {
    *puVar1 = 0xfffffed4;
    FUN_0041e9c0(iVar2);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x4aaa35);
  return;
}

