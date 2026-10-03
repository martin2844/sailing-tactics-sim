
void __fastcall FUN_004b76f6(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_004bfca5();
  if (*(int **)(iVar1 + 0x108) == param_1) {
    (**(code **)(*param_1 + 0xe4))(0xffffffff);
  }
  if (param_1[0x1b] != 0) {
    FUN_004bb9d0(param_1);
    param_1[0x1b] = 0;
  }
  FUN_004acf09();
  return;
}

