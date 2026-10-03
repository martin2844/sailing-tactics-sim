
void FUN_004a1a40(undefined4 param_1,int param_2,undefined4 param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_004a19f0(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}

