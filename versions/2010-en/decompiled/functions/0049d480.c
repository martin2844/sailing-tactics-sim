
uint FUN_0049d480(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_4;
  
  if (param_1 < 0x100) {
    if (1 < DAT_004f045c) {
      uVar2 = FUN_004a0b90(param_1,4);
      return uVar2;
    }
    return (byte)PTR_DAT_004f0250[param_1 * 2] & 4;
  }
  local_4 = 0;
  param_1 = CONCAT31(CONCAT21(param_1._2_2_,(char)param_1),(char)(param_1 >> 8));
  if (DAT_005385c4 == 0) {
    return 0;
  }
  iVar1 = FUN_004a1cb0(1,&param_1,2,&local_4,DAT_005385c4,DAT_005385c8);
  if (iVar1 == 0) {
    return 0;
  }
  if ((local_4._2_2_ == 0) && ((local_4 & 4) != 0)) {
    return 1;
  }
  return 0;
}

