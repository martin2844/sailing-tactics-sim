
undefined4 FUN_004a5d30(uint param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 < DAT_00539a40) &&
     ((*(byte *)((&DAT_00539940)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_00539940)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  puVar1 = (undefined4 *)FUN_0049d3d0();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_0049d3e0();
  *puVar1 = 0;
  return 0xffffffff;
}

