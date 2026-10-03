
int __fastcall FUN_004b9af5(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x84)) {
    do {
      piVar1 = (int *)FUN_004ba70d(iVar4);
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0xd0))();
        if (iVar2 != 0) {
          iVar3 = iVar3 + 1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x84));
  }
  return iVar3;
}

