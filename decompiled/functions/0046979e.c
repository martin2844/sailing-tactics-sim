
bool __fastcall FUN_0046979e(int param_1)

{
  CWnd *pCVar1;
  int iVar2;
  CWnd *pCVar3;
  
  GetForegroundWindow();
  pCVar1 = FUN_004680cc();
  iVar2 = FUN_0046972b(param_1);
  GetLastActivePopup(*(HWND *)(iVar2 + 0x1c));
  pCVar3 = FUN_004680cc();
  return pCVar1 == pCVar3;
}

