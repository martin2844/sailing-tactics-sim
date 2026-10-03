
BOOL __fastcall FUN_00470a84(int param_1)

{
  HGDIOBJ ho;
  BOOL BVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  ho = (HGDIOBJ)FUN_00470a5a(param_1);
  BVar1 = DeleteObject(ho);
  return BVar1;
}

