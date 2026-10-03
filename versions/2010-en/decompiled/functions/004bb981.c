
void __fastcall FUN_004bb981(int param_1)

{
  HMENU hMenu;
  HMENU pHVar1;
  int iVar2;
  
  FUN_004bc47d();
  if (*(int *)(param_1 + 0x44) != 0) {
    hMenu = *(HMENU *)(param_1 + 0x44);
    pHVar1 = GetMenu(*(HWND *)(param_1 + 0x1c));
    if (pHVar1 != hMenu) {
      SetMenu(*(HWND *)(param_1 + 0x1c),hMenu);
    }
  }
  iVar2 = FUN_004bfff8();
  if (*(int *)(*(int *)(iVar2 + 4) + 0x1c) == param_1) {
    WinHelpA(*(HWND *)(param_1 + 0x1c),(LPCSTR)0x0,2,0);
  }
  FUN_004acf09();
  return;
}

