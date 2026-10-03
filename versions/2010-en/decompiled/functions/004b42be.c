
undefined4 __thiscall
FUN_004b42be(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_004af6a3(param_2,param_3,param_4,param_5);
  if (iVar2 == 0) {
    uVar3 = 0;
    if (*(int *)(param_1 + 0x3c) != 0) {
      iVar2 = FUN_004c04f2(FUN_0049a32a);
      uVar1 = *(undefined4 *)(iVar2 + 0xc0);
      *(int *)(iVar2 + 0xc0) = param_1;
      uVar3 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x14))(param_2,param_3,param_4,param_5);
      *(undefined4 *)(iVar2 + 0xc0) = uVar1;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

