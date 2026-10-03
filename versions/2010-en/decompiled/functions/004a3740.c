
byte FUN_004a3740(uint param_1)

{
  if (DAT_00539a40 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_00539940)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
}

