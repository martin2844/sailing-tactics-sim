
undefined4 __thiscall FUN_004baf7f(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    iVar1 = FUN_004af305();
    if (iVar1 == 0) {
      param_3 = *(int *)(param_1 + 0x8c) + 0x20000;
    }
    else {
      param_3 = *(int *)(param_1 + 0x90) + 0x10000;
    }
    if (param_3 == 0) {
      return 0;
    }
  }
  iVar1 = FUN_004bfff8();
  (**(code **)(**(int **)(iVar1 + 4) + 0xa0))(param_3,1);
  return 1;
}

