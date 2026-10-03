
void FUN_004b3c5d(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 == 0) {
    (**(code **)(iVar1 + 0x54))();
  }
  else {
    (**(code **)(iVar1 + 0x4c))();
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(iVar1 + 4))(1);
  }
  return;
}

