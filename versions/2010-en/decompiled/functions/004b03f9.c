
void __fastcall FUN_004b03f9(int param_1)

{
  HWND pHVar1;
  
  if ((*(int *)(param_1 + 0x20) == 0) && (*(int *)(param_1 + 0x1c) == 0)) {
    pHVar1 = GetActiveWindow();
    FUN_004ac7ac(pHVar1);
  }
  return;
}

