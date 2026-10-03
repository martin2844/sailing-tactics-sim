
BOOL __fastcall FUN_004b1f25(int param_1)

{
  HMENU hMenu;
  BOOL BVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  hMenu = (HMENU)FUN_004b1efb();
  BVar1 = DestroyMenu(hMenu);
  return BVar1;
}

