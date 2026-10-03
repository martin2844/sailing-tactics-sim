
void __thiscall FUN_004b7933(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_1[0x1c] != 0) &&
     (iVar1 = (**(code **)(*param_1 + 0x6c))(param_3,param_4,0), iVar1 == -1)) {
    (**(code **)(*(int *)param_1[0x1d] + 8))();
    return;
  }
  FUN_004ac701(param_1);
  return;
}

