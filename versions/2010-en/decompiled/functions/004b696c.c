
int FUN_004b696c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_004b6641(0);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_004b66c5(iVar1,param_2,1);
    iVar1 = (iVar1 != 0) - 1;
  }
  return iVar1;
}

