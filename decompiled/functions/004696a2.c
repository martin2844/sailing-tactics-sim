
CWnd * __fastcall FUN_004696a2(int param_1)

{
  int iVar1;
  CWnd *pCVar2;
  HWND hWnd;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  if (iVar1 != 0) {
    hWnd = *(HWND *)(param_1 + 0x1c);
    while( true ) {
      GetParent(hWnd);
      pCVar2 = FUN_004680cc();
      if (pCVar2 == (CWnd *)0x0) break;
      iVar1 = (**(code **)(*(int *)pCVar2 + 0xb8))();
      if (iVar1 != 0) {
        return pCVar2;
      }
      hWnd = *(HWND *)(pCVar2 + 0x1c);
    }
  }
  return (CWnd *)0x0;
}

