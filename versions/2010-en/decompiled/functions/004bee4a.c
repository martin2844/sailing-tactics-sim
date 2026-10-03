
undefined4 __fastcall FUN_004bee4a(int param_1)

{
  if (DAT_00537ed0 != 0) {
    if (*(int *)(param_1 + 0x80) == 0) {
      *(int *)(param_1 + 0x80) = DAT_00537ed0;
    }
    DAT_00537ed0 = 0;
  }
  if (*(int **)(param_1 + 0x80) == (int *)0x0) {
    DAT_004ed5ec = 0;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x80) + 0x14))(0);
  }
  return 1;
}

