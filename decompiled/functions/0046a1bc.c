
void __fastcall FUN_0046a1bc(CWnd *param_1)

{
  int iVar1;
  CWinThread *pCVar2;
  
  iVar1 = FUN_0047b918();
  if (*(char *)(iVar1 + 0x14) == '\0') {
    iVar1 = FUN_0047bea7();
    pCVar2 = AfxGetThread();
    if (pCVar2 != (CWinThread *)0x0) {
      pCVar2 = AfxGetThread();
      if ((*(CWnd **)(pCVar2 + 0x1c) == param_1) && (*(code **)(iVar1 + 0x24) != (code *)0x0)) {
        (**(code **)(iVar1 + 0x24))();
      }
    }
  }
  FUN_00471035((HKEY)0x1);
  CWnd::OnDisplayChange(param_1,0,0);
  return;
}

