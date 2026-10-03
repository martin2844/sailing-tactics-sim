
bool FUN_004ade7e(void)

{
  HWND pHVar1;
  int iVar2;
  int iVar3;
  
  pHVar1 = GetForegroundWindow();
  iVar2 = FUN_004ac7ac(pHVar1);
  iVar3 = FUN_004ade0b();
  pHVar1 = GetLastActivePopup(*(HWND *)(iVar3 + 0x1c));
  iVar3 = FUN_004ac7ac(pHVar1);
  return iVar2 == iVar3;
}

