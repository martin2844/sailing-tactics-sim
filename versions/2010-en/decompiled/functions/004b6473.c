
void __fastcall FUN_004b6473(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  int *local_8;
  
  iVar1 = *param_1;
  local_8 = param_1;
  local_8 = (int *)(**(code **)(iVar1 + 0x5c))();
  if (local_8 != (int *)0x0) {
    pcVar2 = *(code **)(iVar1 + 0x60);
    do {
      piVar3 = (int *)(*pcVar2)(&local_8);
      (**(code **)(*piVar3 + 0x84))();
    } while (local_8 != (int *)0x0);
  }
  return;
}

