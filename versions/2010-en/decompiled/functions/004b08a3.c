
void __thiscall FUN_004b08a3(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = *param_1;
    if ((*(int *)(iVar1 + -0xc) < 2) && (param_2 + *(int *)(iVar1 + -8) <= *(int *)(iVar1 + -4))) {
      FUN_0049c110(*(int *)(iVar1 + -8) + iVar1,param_3,param_2);
      *(int *)(*param_1 + -8) = *(int *)(*param_1 + -8) + param_2;
      *(undefined1 *)(*(int *)(*param_1 + -8) + *param_1) = 0;
    }
    else {
      FUN_004b0714(*(undefined4 *)(iVar1 + -8),iVar1,param_2,param_3);
      FUN_004b050d(iVar1 + -0xc);
    }
  }
  return;
}

