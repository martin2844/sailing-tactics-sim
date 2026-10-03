
void __thiscall FUN_004af5e6(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x38) == 0)) && (param_2 != 0)) &&
     (*(int *)(param_2 + 0x34) != 0)) {
    iVar2 = FUN_004ab70b(*(undefined4 *)(param_1 + 0x1c));
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x24);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x38) == iVar2)) {
        *(undefined4 *)(iVar1 + 0x38) = 0;
      }
      *(int *)(param_1 + 0x38) = iVar2;
      *(int *)(iVar2 + 0x24) = param_1;
    }
  }
  return;
}

