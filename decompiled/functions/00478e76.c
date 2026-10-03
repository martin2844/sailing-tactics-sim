
undefined4 FUN_00478e76(int param_1)

{
  if (DAT_004ae69c != 0) {
    if ((*(uint *)(param_1 + 0x20) & 0x600) != 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x40000;
    }
    if ((*(byte *)(param_1 + 0x22) & 0xc0) != 0) {
      *(byte *)(param_1 + 0x2c) = *(byte *)(param_1 + 0x2c) | 0x80;
    }
  }
  FUN_00476d46(param_1);
  *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) & 0xfd;
  return 1;
}

