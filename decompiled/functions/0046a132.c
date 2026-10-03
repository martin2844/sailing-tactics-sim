
void __fastcall FUN_0046a132(int *param_1)

{
  int iVar1;
  CWinThread *pCVar2;
  uint uVar3;
  
  iVar1 = FUN_0047b918();
  iVar1 = *(int *)(iVar1 + 4);
  FUN_0047bea7();
  if (*(int **)(iVar1 + 0x1c) == param_1) {
    FUN_0046d6c9(0x4ae638);
  }
  iVar1 = FUN_0047b918();
  if (*(char *)(iVar1 + 0x14) == '\0') {
    pCVar2 = AfxGetThread();
    if (pCVar2 != (CWinThread *)0x0) {
      pCVar2 = AfxGetThread();
      if (*(int **)(pCVar2 + 0x1c) == param_1) {
        iVar1 = FUN_0047bea7();
        if (*(code **)(iVar1 + 0x1c) != (code *)0x0) {
          (**(code **)(iVar1 + 0x1c))();
        }
      }
    }
  }
  uVar3 = FUN_0046ad0b((int)param_1);
  if ((uVar3 & 0x40000000) == 0) {
    FUN_0046996c((HWND)param_1[7],0x15,0,0,1,1);
  }
  FUN_00468021(param_1);
  return;
}

