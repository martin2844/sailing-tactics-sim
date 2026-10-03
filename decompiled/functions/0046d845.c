
BOOL __fastcall FUN_0046d845(int param_1)

{
  HMENU hMenu;
  BOOL BVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  hMenu = (HMENU)FUN_0046d81b(param_1);
  BVar1 = DestroyMenu(hMenu);
  return BVar1;
}

