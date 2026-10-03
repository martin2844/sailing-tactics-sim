
void __fastcall FUN_004bb1ad(int param_1)

{
  int *piVar1;
  BOOL BVar2;
  int iVar3;
  
  if (((*(int *)(param_1 + 0xa0) != 0) &&
      (iVar3 = *(int *)(param_1 + 0xa0) + -1, *(int *)(param_1 + 0xa0) = iVar3, iVar3 == 0)) &&
     (piVar1 = *(int **)(param_1 + 0xa4), piVar1 != (int *)0x0)) {
    if (*piVar1 != 0) {
      iVar3 = 0;
      do {
        BVar2 = IsWindow(*(HWND *)(iVar3 + (int)piVar1));
        if (BVar2 != 0) {
          EnableWindow(*(HWND *)(*(int *)(param_1 + 0xa4) + iVar3),1);
        }
        piVar1 = *(int **)(param_1 + 0xa4);
        iVar3 = iVar3 + 4;
      } while (*(int *)(iVar3 + (int)piVar1) != 0);
    }
    FUN_004afc21(*(undefined4 *)(param_1 + 0xa4));
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  return;
}

