
undefined4 FUN_0046835b(int param_1,int param_2,int param_3)

{
  int iVar1;
  CWnd *pCVar2;
  CWnd *pCVar3;
  
  if (((param_2 == -2) && (((param_3 == 0x201 || (param_3 == 0x207)) || (param_3 == 0x204)))) &&
     (iVar1 = FUN_0046972b(param_1), iVar1 != 0)) {
    GetLastActivePopup(*(HWND *)(iVar1 + 0x1c));
    pCVar2 = FUN_004680cc();
    if (pCVar2 != (CWnd *)0x0) {
      GetForegroundWindow();
      pCVar3 = FUN_004680cc();
      if ((pCVar2 != pCVar3) && (iVar1 = FUN_0046ae73((int)pCVar2), iVar1 != 0)) {
        SetForegroundWindow(*(HWND *)(pCVar2 + 0x1c));
        return 1;
      }
    }
  }
  return 0;
}

