
int * __thiscall FUN_004be47b(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_004b164a();
  if (piVar1 == (int *)0x0) {
    FUN_004aa740();
  }
  iVar2 = (**(code **)(*piVar1 + 0xfc))(param_1,param_2);
  if (iVar2 == 0) {
    FUN_004b517a();
  }
  return piVar1;
}

