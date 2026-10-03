
void __thiscall FUN_004af52c(int param_1,int param_2)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    ShowWindow(*(HWND *)(param_1 + 0x1c),param_2);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x38) + 0xa8))(param_2);
  }
  return;
}

