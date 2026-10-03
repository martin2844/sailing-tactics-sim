
void __fastcall FUN_004ae89c(CWnd *param_1)

{
  int iVar1;
  CWinThread *pCVar2;
  
  iVar1 = FUN_004bfff8();
  if (*(char *)(iVar1 + 0x14) == '\0') {
    iVar1 = FUN_004c0587(FUN_0049a382);
    pCVar2 = AfxGetThread();
    if (pCVar2 != (CWinThread *)0x0) {
      pCVar2 = AfxGetThread();
      if ((*(CWnd **)(pCVar2 + 0x1c) == param_1) && (*(code **)(iVar1 + 0x24) != (code *)0x0)) {
        (**(code **)(iVar1 + 0x24))();
      }
    }
  }
  FUN_004b5715(1);
  CWnd::OnDisplayChange(param_1,0,0);
  return;
}

