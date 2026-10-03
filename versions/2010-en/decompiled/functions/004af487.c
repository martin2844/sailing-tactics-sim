
void __thiscall FUN_004af487(int param_1,LPCSTR param_2)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    SetWindowTextA(*(HWND *)(param_1 + 0x1c),param_2);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x38) + 0x88))(param_2);
  }
  return;
}

