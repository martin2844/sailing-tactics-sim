
void __fastcall FUN_004ade0b(int param_1)

{
  int iVar1;
  HWND__ *pHVar2;
  HWND__ *pHVar3;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  if (iVar1 != 0) {
    pHVar2 = *(HWND__ **)(param_1 + 0x1c);
    do {
      pHVar3 = pHVar2;
      pHVar2 = AfxGetParentOwner(pHVar3);
    } while (pHVar2 != (HWND__ *)0x0);
    FUN_004ac7ac(pHVar3);
    return;
  }
  return;
}

