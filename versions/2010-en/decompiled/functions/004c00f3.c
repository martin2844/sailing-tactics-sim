
undefined4 __thiscall FUN_004c00f3(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    return 0;
  }
  if (iVar2 == param_2) {
    *param_1 = *(int *)(param_1[1] + param_2);
  }
  else {
    if (iVar2 == 0) {
      return 0;
    }
    do {
      iVar1 = *(int *)(iVar2 + param_1[1]);
      if (iVar1 == param_2) break;
      iVar2 = iVar1;
    } while (iVar1 != 0);
    if (iVar2 == 0) {
      return 0;
    }
    *(undefined4 *)(iVar2 + param_1[1]) = *(undefined4 *)(param_2 + param_1[1]);
  }
  return 1;
}

