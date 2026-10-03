
void __thiscall FUN_004b5381(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_8;
  
  uVar1 = *(uint *)(param_1 + 0x24);
  local_8 = *(int *)(param_1 + 0x28) - uVar1;
  uVar2 = param_2 + local_8;
  if (*(int *)(param_1 + 8) == 0) {
    uVar3 = *(uint *)(param_1 + 0x2c);
    if (uVar3 < uVar1) {
      if (0 < (int)local_8) {
        FUN_0049c740(uVar3,uVar1,local_8);
        uVar3 = *(uint *)(param_1 + 0x2c);
        *(uint *)(param_1 + 0x24) = uVar3;
        *(int *)(param_1 + 0x28) = local_8 + uVar3;
      }
      iVar5 = *(int *)(param_1 + 0x1c) - local_8;
      iVar6 = local_8 + uVar3;
      do {
        iVar4 = (**(code **)(**(int **)(param_1 + 0x20) + 0x3c))(iVar6,iVar5);
        local_8 = local_8 + iVar4;
        iVar6 = iVar6 + iVar4;
        iVar5 = iVar5 - iVar4;
        if ((iVar4 == 0) || (iVar5 == 0)) break;
      } while (local_8 < param_2);
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x2c);
      *(uint *)(param_1 + 0x28) = local_8 + *(int *)(param_1 + 0x2c);
    }
  }
  else {
    if (local_8 != 0) {
      (**(code **)(**(int **)(param_1 + 0x20) + 0x30))(-local_8,1);
    }
    (**(code **)(**(int **)(param_1 + 0x20) + 0x58))
              (0,*(undefined4 *)(param_1 + 0x1c),(undefined4 *)(param_1 + 0x2c),
               (int *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x2c);
  }
  if ((uint)(*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24)) < uVar2) {
    FUN_004b65c6(3,0);
  }
  return;
}

