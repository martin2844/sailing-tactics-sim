
int __thiscall FUN_004b0a0e(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0049c670(*param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = iVar1 - *param_1;
  }
  return iVar1;
}

