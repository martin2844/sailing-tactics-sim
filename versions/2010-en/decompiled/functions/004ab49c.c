
void __thiscall FUN_004ab49c(int param_1,int param_2,undefined4 param_3)

{
  if (*(int *)(param_1 + 8) <= param_2) {
    FUN_004ab379(param_2 + 1,0xffffffff);
  }
  *(undefined4 *)(*(int *)(param_1 + 4) + param_2 * 4) = param_3;
  return;
}

