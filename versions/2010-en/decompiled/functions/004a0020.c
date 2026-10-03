
undefined4 FUN_004a0020(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_00538788 != (code *)0x0) {
    iVar1 = (*DAT_00538788)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

