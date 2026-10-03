
void __thiscall FUN_004af41f(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    FUN_004ac4bd(*(undefined4 *)(param_1 + 0x1c),param_2,param_3,param_4);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x38) + 0x80))(param_2,param_3,param_4);
  }
  return;
}

