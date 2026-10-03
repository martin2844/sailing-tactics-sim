
undefined4 FUN_004b40c9(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)*param_1;
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    *param_1 = *piVar1;
    uVar2 = piVar1[2];
  }
  return uVar2;
}

