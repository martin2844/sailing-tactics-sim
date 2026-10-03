
undefined4 FUN_004ace0f(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x28) == 0) {
    iVar1 = FUN_004bfff8();
    if ((*(byte *)(iVar1 + 0x18) & 1) == 0) {
      iVar1 = FUN_004af183(1);
    }
    else {
      iVar1 = 1;
    }
    if (iVar1 == 0) {
      return 0;
    }
    *(char **)(param_1 + 0x28) = "AfxWnd42s";
  }
  return 1;
}

