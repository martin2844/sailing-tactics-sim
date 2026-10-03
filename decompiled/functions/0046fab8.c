
undefined4 FUN_0046fab8(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x28) == 0) {
    iVar1 = FUN_0047b918();
    if ((*(byte *)(iVar1 + 0x18) & 8) == 0) {
      iVar1 = FUN_0046aaa3(8);
    }
    else {
      iVar1 = 1;
    }
    if (iVar1 == 0) {
      return 0;
    }
    *(char **)(param_1 + 0x28) = "AfxFrameOrView42s";
  }
  if ((DAT_004ae694 != 0) && ((*(uint *)(param_1 + 0x20) & 0x800000) != 0)) {
    *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 2;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xff7fffff;
  }
  return 1;
}

