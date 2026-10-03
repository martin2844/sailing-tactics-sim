
void __fastcall FUN_00470c27(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(byte *)(param_1 + 0x14) & 1) == 0) {
    iVar1 = *(int *)(param_1 + 0x2c);
    if ((iVar1 != 0) && (*(int *)(param_1 + 0x24) == iVar1)) {
      return;
    }
    if (*(int *)(param_1 + 8) == 0) {
      (**(code **)(**(int **)(param_1 + 0x20) + 0x40))(iVar1,*(int *)(param_1 + 0x24) - iVar1);
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x20) + 0x58))(2,*(int *)(param_1 + 0x24) - iVar1,0,0);
      (**(code **)(**(int **)(param_1 + 0x20) + 0x58))
                (1,*(undefined4 *)(param_1 + 0x1c),(undefined4 *)(param_1 + 0x2c),param_1 + 0x28);
    }
    uVar2 = *(undefined4 *)(param_1 + 0x2c);
  }
  else {
    if (*(int *)(param_1 + 0x28) != *(int *)(param_1 + 0x24)) {
      (**(code **)(**(int **)(param_1 + 0x20) + 0x30))
                (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x28),1);
    }
    uVar2 = *(undefined4 *)(param_1 + 0x28);
  }
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  return;
}

