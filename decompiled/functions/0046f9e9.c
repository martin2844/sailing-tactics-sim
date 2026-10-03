
int FUN_0046f9e9(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  iVar2 = 0;
  if (piVar1 != (int *)0x0) {
    *param_1 = *piVar1;
    iVar2 = piVar1[2];
  }
  return iVar2;
}

