
void __thiscall FUN_004bbd69(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = FUN_004bfff8();
  piVar1 = *(int **)(iVar2 + 4);
  if ((param_2 != 0) && (piVar1[7] == param_1)) {
    FUN_004bce09(1);
    FUN_004b6db2(1);
    (**(code **)(*piVar1 + 0x70))();
  }
  return;
}

