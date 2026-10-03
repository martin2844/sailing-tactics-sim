
undefined4 FUN_00476d46(int param_1)

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
  if ((*(uint *)(param_1 + 0x20) & 0x8000) != 0) {
    if (DAT_004ae694 == 0) {
      return 1;
    }
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x4000;
  }
  if (DAT_004ae694 != 0) {
    *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 2;
  }
  return 1;
}

