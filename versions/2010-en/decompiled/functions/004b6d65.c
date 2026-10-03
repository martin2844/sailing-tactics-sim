
void __thiscall FUN_004b6d65(int param_1,undefined4 param_2)

{
  undefined1 local_108 [260];
  
  if (*(int *)(param_1 + 0xa8) != 0) {
    FUN_004b1300(local_108,param_2);
    (**(code **)(**(int **)(param_1 + 0xa8) + 4))(local_108);
  }
  return;
}

