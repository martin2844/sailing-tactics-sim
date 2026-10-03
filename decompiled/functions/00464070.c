
undefined4 __cdecl FUN_00464070(HWND param_1)

{
  HANDLE pvVar1;
  uint uVar2;
  
  pvVar1 = FUN_00462840(param_1);
  if (pvVar1 == (HANDLE)0x0) {
    return 0;
  }
  if (0x35e < DAT_004aff60) {
    uVar2 = GetWindowLongA(param_1,-0x10);
    if ((uVar2 & 4) != 0) {
      return 0;
    }
  }
  return 1;
}

