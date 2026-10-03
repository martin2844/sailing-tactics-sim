
BOOL __fastcall FUN_004b5164(int param_1)

{
  HGDIOBJ ho;
  BOOL BVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  ho = (HGDIOBJ)FUN_004b513a();
  BVar1 = DeleteObject(ho);
  return BVar1;
}

