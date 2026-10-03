
int __fastcall FUN_004bae06(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1[0x12];
  piVar1 = (int *)(**(code **)(*param_1 + 0xc4))();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xb0))();
    if (iVar2 != 0) {
      iVar3 = iVar2;
    }
  }
  return iVar3;
}

