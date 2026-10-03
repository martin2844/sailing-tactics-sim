
undefined4 __thiscall
FUN_004b40dd(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004af6a3(param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    if (*(int **)(param_1 + 0x24) != (int *)0x0) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x24) + 0x14))(param_2,param_3,param_4,param_5);
      if (iVar1 != 0) goto LAB_004b4114;
    }
    uVar2 = 0;
  }
  else {
LAB_004b4114:
    uVar2 = 1;
  }
  return uVar2;
}

