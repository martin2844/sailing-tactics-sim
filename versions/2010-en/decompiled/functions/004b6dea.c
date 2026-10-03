
undefined4 __thiscall FUN_004b6dea(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x80) == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x80) + 0x38))(param_2);
  }
  return uVar1;
}

