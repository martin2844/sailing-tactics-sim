
void FUN_0041b510(void)

{
  int iVar1;
  
  if ((DAT_00491158 == 0) && (DAT_004a4958 != 4)) {
    DAT_004ac1dc = 0;
    return;
  }
  if ((0 < DAT_004a4958) && (DAT_004a4958 < 4)) {
    DAT_004ac1dc = 0;
    return;
  }
  iVar1 = FUN_00415a20(8);
  DAT_004ac1dc = iVar1 + 7;
  DAT_004aae1c = FUN_00413cb0(DAT_004aa804 * 0x5a);
  if (DAT_004a4958 == 4) {
    iVar1 = FUN_00415a20(4);
    DAT_004ac1dc = iVar1 + 0xb;
    DAT_004aae1c = (-(uint)(DAT_004ac85c != 1) & 0xffffffa6) + 0xaa;
  }
  iVar1 = FUN_00415a20(0xc);
  DAT_004a796c = iVar1 + 7;
  DAT_004a8020 = iVar1 + 1;
  if (DAT_004a8020 < 6) {
    DAT_004a8020 = iVar1 + 0xd;
  }
  return;
}

