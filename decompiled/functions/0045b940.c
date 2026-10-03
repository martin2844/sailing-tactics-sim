
undefined4 __cdecl FUN_0045b940(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_004aec30 != (code *)0x0) {
    iVar1 = (*DAT_004aec30)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

