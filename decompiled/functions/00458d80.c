
uint __cdecl FUN_00458d80(uint param_1)

{
  BOOL BVar1;
  uint uVar2;
  undefined4 local_4;
  
  if (param_1 < 0x100) {
    if (1 < DAT_004a229c) {
      uVar2 = FUN_0045c4b0(param_1,4);
      return uVar2;
    }
    return (byte)PTR_DAT_004a2090[param_1 * 2] & 4;
  }
  local_4 = 0;
  param_1 = CONCAT31(CONCAT21(param_1._2_2_,(char)param_1),(char)(param_1 >> 8));
  if (DAT_004aea6c == 0) {
    return 0;
  }
  BVar1 = FUN_0045d5d0(1,(LPCSTR)&param_1,2,(LPWORD)&local_4,DAT_004aea6c,DAT_004aea70);
  if (BVar1 == 0) {
    return 0;
  }
  if ((local_4._2_2_ == 0) && ((local_4 & 4) != 0)) {
    return 1;
  }
  return 0;
}

