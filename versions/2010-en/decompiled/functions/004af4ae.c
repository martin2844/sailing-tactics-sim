
void __thiscall FUN_004af4ae(int param_1,LPSTR param_2,int param_3)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    GetWindowTextA(*(HWND *)(param_1 + 0x1c),param_2,param_3);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x38) + 0x8c))(param_2,param_3);
  }
  return;
}

