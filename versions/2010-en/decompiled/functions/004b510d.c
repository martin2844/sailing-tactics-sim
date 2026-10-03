
bool __thiscall FUN_004b510d(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 != 0) {
    FUN_004b5087(1);
    *(int *)(param_1 + 4) = param_2;
    piVar1 = (int *)FUN_004ab73e(param_2);
    *piVar1 = param_1;
  }
  return param_2 != 0;
}

