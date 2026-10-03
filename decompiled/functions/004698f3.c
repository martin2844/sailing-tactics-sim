
CWnd * FUN_004698f3(HWND param_1,int param_2,int param_3)

{
  HWND pHVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  
  pHVar1 = GetDlgItem(param_1,param_2);
  if (pHVar1 != (HWND)0x0) {
    pHVar2 = GetTopWindow(pHVar1);
    if ((pHVar2 != (HWND)0x0) &&
       (pCVar3 = FUN_004698f3(pHVar1,param_2,param_3), pCVar3 != (CWnd *)0x0)) {
      return pCVar3;
    }
    if (param_3 == 0) {
      pCVar3 = FUN_004680cc();
      return pCVar3;
    }
    pCVar3 = (CWnd *)FUN_004680f4((uint)pHVar1);
    if (pCVar3 != (CWnd *)0x0) {
      return pCVar3;
    }
  }
  pHVar1 = GetTopWindow(param_1);
  while( true ) {
    if (pHVar1 == (HWND)0x0) {
      return (CWnd *)0x0;
    }
    pCVar3 = FUN_004698f3(pHVar1,param_2,param_3);
    if (pCVar3 != (CWnd *)0x0) break;
    pHVar1 = GetWindow(pHVar1,2);
  }
  return pCVar3;
}

