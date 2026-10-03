
undefined4 __thiscall FUN_004b1690(int param_1,int param_2)

{
  while( true ) {
    if (param_1 == 0) {
      return 0;
    }
    if (param_1 == param_2) break;
    param_1 = *(int *)(param_1 + 0x10);
  }
  return 1;
}

