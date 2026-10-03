
void __thiscall FUN_004ab27f(int param_1,int *param_2)

{
  if (param_2 == *(int **)(param_1 + 4)) {
    *(int *)(param_1 + 4) = *param_2;
  }
  else {
    *(int *)param_2[1] = *param_2;
  }
  if (param_2 == *(int **)(param_1 + 8)) {
    *(int *)(param_1 + 8) = param_2[1];
  }
  else {
    *(int *)(*param_2 + 4) = param_2[1];
  }
  FUN_004ab219(param_2);
  return;
}

