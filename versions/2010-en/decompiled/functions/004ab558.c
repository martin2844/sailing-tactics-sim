
void __thiscall FUN_004ab558(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (*(int *)(param_1 + 8) - param_2) - param_3;
  if (iVar1 != 0) {
    FUN_0049c110(*(int *)(param_1 + 4) + param_2 * 4,*(int *)(param_1 + 4) + (param_3 + param_2) * 4
                 ,iVar1 * 4);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) - param_3;
  return;
}

