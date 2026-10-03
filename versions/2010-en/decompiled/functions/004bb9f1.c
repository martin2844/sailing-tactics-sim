
undefined4 FUN_004bb9f1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_004bbf0e();
  if (((piVar1 == (int *)0x0) ||
      (iVar2 = (**(code **)(*piVar1 + 0x14))(param_1,param_2,param_3,param_4), iVar2 == 0)) &&
     (iVar2 = FUN_004af6a3(param_1,param_2,param_3,param_4), iVar2 == 0)) {
    iVar2 = FUN_004bfff8();
    if ((*(int **)(iVar2 + 4) == (int *)0x0) ||
       (iVar2 = (**(code **)(**(int **)(iVar2 + 4) + 0x14))(param_1,param_2,param_3,param_4),
       iVar2 == 0)) {
      return 0;
    }
  }
  return 1;
}

