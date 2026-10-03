
undefined4 FUN_004bd556(int param_1)

{
  if (DAT_005381f4 != 0) {
    if ((*(uint *)(param_1 + 0x20) & 0x600) != 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x40000;
    }
    if ((*(byte *)(param_1 + 0x22) & 0xc0) != 0) {
      *(byte *)(param_1 + 0x2c) = *(byte *)(param_1 + 0x2c) | 0x80;
    }
  }
  FUN_004bb426(param_1);
  *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) & 0xfd;
  return 1;
}

