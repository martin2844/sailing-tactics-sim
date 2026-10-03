
undefined4 __cdecl FUN_00461650(uint param_1)

{
  DWORD *pDVar1;
  
  if ((param_1 < DAT_004aff00) &&
     ((*(byte *)((&DAT_004afe00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_004afe00)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_00458cd0();
  *pDVar1 = 9;
  pDVar1 = FUN_00458ce0();
  *pDVar1 = 0;
  return 0xffffffff;
}

