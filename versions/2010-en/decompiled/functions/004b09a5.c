
void __thiscall FUN_004b09a5(int *param_1,int param_2)

{
  FUN_004b054e();
  if (param_2 == -1) {
    param_2 = lstrlenA((LPCSTR)*param_1);
  }
  *(int *)(*param_1 + -8) = param_2;
  *(undefined1 *)(*param_1 + param_2) = 0;
  return;
}

