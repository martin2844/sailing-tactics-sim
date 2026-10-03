
void __thiscall FUN_004b4076(int *param_1,int param_2)

{
  int iVar1;
  
  AddTail(param_2);
  iVar1 = *param_1;
  *(int **)(param_2 + 0x3c) = param_1;
  (**(code **)(iVar1 + 0x70))();
  return;
}

