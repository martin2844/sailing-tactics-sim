
undefined4 * __thiscall FUN_004b1753(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  else {
    uVar1 = FUN_004b184c(param_2);
    FUN_004b1782(param_2,uVar1);
  }
  return param_1;
}

