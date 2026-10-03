
void __thiscall FUN_004ad21d(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  
  if (*param_3 == 1) {
    piVar1 = (int *)FUN_004b1edf(param_3[5]);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))(param_3);
      return;
    }
  }
  else {
    iVar2 = FUN_004ae5ce(param_3[5],0);
    if (iVar2 != 0) {
      return;
    }
  }
  FUN_004ac701(param_1);
  return;
}

