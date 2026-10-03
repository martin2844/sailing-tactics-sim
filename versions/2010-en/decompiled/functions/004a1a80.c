
void FUN_004a1a80(char *param_1,int param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_004a19f0((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}

