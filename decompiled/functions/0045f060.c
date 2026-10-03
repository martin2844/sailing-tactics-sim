
byte __cdecl FUN_0045f060(uint param_1)

{
  if (DAT_004aff00 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_004afe00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
}

