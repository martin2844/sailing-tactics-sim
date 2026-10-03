
BOOL __fastcall FUN_004ad050(int param_1)

{
  int iVar1;
  BOOL BVar2;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    return 0;
  }
  FUN_004ac73c(0);
  iVar1 = FUN_004ab70b(*(undefined4 *)(param_1 + 0x1c));
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    BVar2 = DestroyWindow(*(HWND *)(param_1 + 0x1c));
  }
  else {
    BVar2 = (**(code **)(**(int **)(param_1 + 0x38) + 0x58))();
  }
  if (iVar1 == 0) {
    FUN_004ac829();
  }
  return BVar2;
}

