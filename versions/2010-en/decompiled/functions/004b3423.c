
undefined4 __fastcall FUN_004b3423(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int *local_8;
  
  iVar1 = *param_1;
  local_8 = param_1;
  local_8 = (int *)(**(code **)(iVar1 + 0x68))();
  if (local_8 != (int *)0x0) {
    pcVar2 = *(code **)(iVar1 + 0x6c);
    do {
      (*pcVar2)(&local_8);
      iVar3 = FUN_004add82();
      if ((iVar3 != 0) && (0 < *(int *)(iVar3 + 0x40))) {
        return 1;
      }
    } while (local_8 != (int *)0x0);
  }
  uVar4 = (**(code **)(iVar1 + 0x98))();
  return uVar4;
}

