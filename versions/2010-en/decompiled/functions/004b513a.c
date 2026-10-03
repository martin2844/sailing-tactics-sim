
int __fastcall FUN_004b513a(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = FUN_004b5087(0);
    if (iVar2 != 0) {
      FUN_004ab78e(*(undefined4 *)(param_1 + 4));
    }
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return iVar1;
}

