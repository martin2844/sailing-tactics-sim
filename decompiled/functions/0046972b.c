
void __fastcall FUN_0046972b(int param_1)

{
  int iVar1;
  HWND__ *pHVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  if (iVar1 != 0) {
    pHVar2 = *(HWND__ **)(param_1 + 0x1c);
    do {
      pHVar2 = AfxGetParentOwner(pHVar2);
    } while (pHVar2 != (HWND__ *)0x0);
    FUN_004680cc();
    return;
  }
  return;
}

