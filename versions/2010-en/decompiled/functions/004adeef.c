
int * __fastcall FUN_004adeef(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1[7];
  }
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*param_1 + 0xb8))();
    piVar3 = param_1;
    if (iVar2 == 0) {
      param_1 = (int *)FUN_004add82();
      piVar3 = param_1;
    }
    while (piVar1 = piVar3, piVar1 != (int *)0x0) {
      piVar3 = (int *)FUN_004add82();
      param_1 = piVar1;
    }
    return param_1;
  }
  return (int *)0x0;
}

