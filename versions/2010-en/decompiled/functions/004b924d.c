
void __thiscall FUN_004b924d(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_c;
  int local_8;
  
  iVar1 = param_2 - *(int *)(param_1 + 4);
  iVar3 = param_3 - *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 0x8c);
  uVar4 = 2;
  if (iVar2 == 10) {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + iVar1;
  }
  else {
    if (iVar2 != 0xb) {
      uVar4 = 0x22;
      if (iVar2 == 0xc) {
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + iVar3;
      }
      else {
        *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + iVar3;
      }
      iVar2 = *(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x2c);
      goto LAB_004b92a7;
    }
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + iVar1;
  }
  iVar2 = *(int *)(param_1 + 0x30) - *(int *)(param_1 + 0x28);
LAB_004b92a7:
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  local_c = param_1;
  local_8 = param_1;
  (**(code **)(**(int **)(param_1 + 0x68) + 0xc4))(&local_c,iVar2,uVar4);
  if ((*(int *)(param_1 + 0x8c) == 10) || (*(int *)(param_1 + 0x8c) == 0xc)) {
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x40) - local_c;
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x44) - local_8;
    *(int *)(param_1 + 0x48) =
         ((*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x60)) + *(int *)(param_1 + 0x58)) -
         local_c;
    *(int *)(param_1 + 0x4c) =
         ((*(int *)(param_1 + 0x5c) - *(int *)(param_1 + 100)) + *(int *)(param_1 + 0x54)) - local_8
    ;
  }
  else {
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x38) + local_c;
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x3c) + local_8;
    *(int *)(param_1 + 0x50) =
         ((*(int *)(param_1 + 0x60) + *(int *)(param_1 + 0x48)) - *(int *)(param_1 + 0x58)) +
         local_c;
    *(int *)(param_1 + 0x54) =
         (*(int *)(param_1 + 100) - *(int *)(param_1 + 0x5c)) + *(int *)(param_1 + 0x4c) + local_8;
  }
  *(int *)(param_1 + 4) = param_2;
  *(int *)(param_1 + 8) = param_3;
  FUN_004b957c(0);
  return;
}

