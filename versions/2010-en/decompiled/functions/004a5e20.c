
int FUN_004a5e20(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    return 0;
  }
  iVar1 = FUN_004a67a0(DAT_005385c8,1,param_1,param_3,param_2,param_3,DAT_005385c4);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}

