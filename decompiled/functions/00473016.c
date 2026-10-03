
void __fastcall FUN_00473016(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0047b5c5();
  if (*(int **)(iVar1 + 0x108) == param_1) {
    (**(code **)(*param_1 + 0xe4))(0xffffffff);
  }
  if ((void *)param_1[0x1b] != (void *)0x0) {
    FUN_004772f0((void *)param_1[0x1b],(int)param_1);
    param_1[0x1b] = 0;
  }
  FUN_00468829(param_1);
  return;
}

