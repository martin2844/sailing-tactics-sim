
bool __thiscall FUN_004afd02(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = param_2;
  if (param_2 < 1) {
    FUN_004aff81(param_2);
    param_2 = 0;
    if (*(int **)(param_1 + 0x80) != (int *)0x0) {
      param_2 = (**(code **)(**(int **)(param_1 + 0x80) + 0x18))();
    }
    while (param_2 != 0) {
      piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0x80) + 0x1c))(&param_2);
      (**(code **)(*piVar2 + 0x90))();
    }
  }
  else if (param_2 == 1) {
    FUN_004aff81(1);
  }
  return iVar1 < 1;
}

