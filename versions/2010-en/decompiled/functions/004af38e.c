
void __thiscall FUN_004af38e(int param_1,int param_2)

{
  HWND pHVar1;
  
  if (*(int **)(param_1 + 0x34) == (int *)0x0) {
    pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x1c),param_2);
    FUN_004ac7ac(pHVar1);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x34) + 0x78))(param_2);
  }
  return;
}

