
void FUN_004b6be3(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_0049a2e0();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xb8))();
    if ((iVar2 != 0) && ((int *)piVar1[0x1a] != (int *)0x0)) {
      (**(code **)(*(int *)piVar1[0x1a] + 0x6c))(param_1);
    }
  }
  return;
}

