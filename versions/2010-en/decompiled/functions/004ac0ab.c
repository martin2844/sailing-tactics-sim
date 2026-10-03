
void __thiscall FUN_004ac0ab(int *param_1,INT_PTR param_2)

{
  if ((*(byte *)(param_1 + 9) & 0x18) != 0) {
    (**(code **)(*param_1 + 0x7c))(param_2);
  }
  EndDialog((HWND)param_1[7],param_2);
  return;
}

