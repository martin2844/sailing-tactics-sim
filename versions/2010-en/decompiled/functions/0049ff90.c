
undefined4 FUN_0049ff90(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    FUN_0049e630();
    return 1;
  }
  if (DAT_00538780 != (code *)0x0) {
    iVar2 = FUN_004a2660(DAT_00538780);
    if (iVar2 != 0) {
      uVar3 = (*DAT_00538780)(param_1);
      return uVar3;
    }
  }
  return 0;
}

