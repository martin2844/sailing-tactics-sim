
undefined4 __fastcall FUN_004b6435(int *param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int *local_8;
  
  iVar3 = *param_1;
  local_8 = param_1;
  local_8 = (int *)(**(code **)(iVar3 + 0x5c))();
  if (local_8 != (int *)0x0) {
    pcVar1 = *(code **)(iVar3 + 0x60);
    do {
      piVar2 = (int *)(*pcVar1)(&local_8);
      iVar3 = (**(code **)(*piVar2 + 0x98))();
      if (iVar3 == 0) {
        return 0;
      }
    } while (local_8 != (int *)0x0);
  }
  return 1;
}

