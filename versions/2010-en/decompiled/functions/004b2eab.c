
undefined4 FUN_004b2eab(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0xffffffff;
  iVar2 = FUN_004bfff8();
  piVar1 = *(int **)(iVar2 + 4);
  iVar2 = FUN_004c12e4(param_1,param_2,param_3,param_4);
  if (iVar2 != 0) {
    iVar2 = *piVar1;
    iVar3 = (**(code **)(iVar2 + 0x8c))();
    if (iVar3 != 0) {
      iVar3 = (**(code **)(iVar2 + 0x58))();
      if (iVar3 == 0) {
        piVar1 = (int *)piVar1[7];
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x60))();
        }
        uVar4 = (**(code **)(iVar2 + 0x70))();
      }
      else {
        uVar4 = (**(code **)(iVar2 + 0x5c))();
      }
    }
  }
  FUN_004c16aa();
  return uVar4;
}

