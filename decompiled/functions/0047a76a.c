
undefined4 __fastcall FUN_0047a76a(int param_1)

{
  if (DAT_004ae378 != 0) {
    if (*(int *)(param_1 + 0x80) == 0) {
      *(int *)(param_1 + 0x80) = DAT_004ae378;
    }
    DAT_004ae378 = 0;
  }
  if (*(int **)(param_1 + 0x80) == (int *)0x0) {
    DAT_0049f424 = 0;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x80) + 0x14))(0);
  }
  return 1;
}

