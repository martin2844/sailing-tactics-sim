
undefined4 FUN_004a8750(HWND param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_004a6f20(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  if (0x35e < DAT_00539aa0) {
    uVar2 = GetWindowLongA(param_1,-0x10);
    if ((uVar2 & 4) != 0) {
      return 0;
    }
  }
  return 1;
}

