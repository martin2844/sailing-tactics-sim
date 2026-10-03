
int __thiscall FUN_004061b0(int param_1,undefined4 param_2)

{
  if (*(uint *)(param_1 + 0x28) < *(int *)(param_1 + 0x24) + 4U) {
    FUN_004b5307();
  }
  **(undefined4 **)(param_1 + 0x24) = param_2;
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 4;
  return param_1;
}

