
void __fastcall FUN_004772a1(int *param_1)

{
  HMENU hMenu;
  HMENU pHVar1;
  int iVar2;
  
  FUN_00477d9d();
  if (param_1[0x11] != 0) {
    hMenu = (HMENU)param_1[0x11];
    pHVar1 = GetMenu((HWND)param_1[7]);
    if (pHVar1 != hMenu) {
      SetMenu((HWND)param_1[7],hMenu);
    }
  }
  iVar2 = FUN_0047b918();
  if (*(int **)(*(int *)(iVar2 + 4) + 0x1c) == param_1) {
    WinHelpA((HWND)param_1[7],(LPCSTR)0x0,2,0);
  }
  FUN_00468829(param_1);
  return;
}

