
undefined4 FUN_004b56c3(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_004bfca5();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) != 0)) {
    uVar2 = FUN_0049cbe0(*(int *)(iVar1 + 0xc));
    if (param_1 + 4U < uVar2) {
      FUN_0049cb30(*(undefined4 *)(iVar1 + 0xc),(uVar2 - param_1) + -4);
    }
    else {
      FUN_0049bfd0(*(undefined4 *)(iVar1 + 0xc));
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    return 1;
  }
  FUN_004aa740();
  return 0;
}

