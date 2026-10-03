
BOOL __fastcall FUN_00468970(int param_1)

{
  void *this;
  int iVar1;
  BOOL BVar2;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    return 0;
  }
  this = (void *)FUN_0046805c();
  iVar1 = FUN_0046702b(this,*(uint *)(param_1 + 0x1c));
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    BVar2 = DestroyWindow(*(HWND *)(param_1 + 0x1c));
  }
  else {
    BVar2 = (**(code **)(**(int **)(param_1 + 0x38) + 0x58))();
  }
  if (iVar1 == 0) {
    FUN_00468149(param_1);
  }
  return BVar2;
}

