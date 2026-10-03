
int __fastcall FUN_004b9ac8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x84)) {
    do {
      iVar1 = FUN_004ba70d(iVar3);
      if (iVar1 != 0) {
        iVar2 = iVar2 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x84));
  }
  return iVar2;
}

