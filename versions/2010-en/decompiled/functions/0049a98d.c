
BOOL __fastcall FUN_0049a98d(int param_1)

{
  HIMAGELIST himl;
  BOOL BVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  himl = (HIMAGELIST)FUN_0049a8f3();
  BVar1 = ImageList_Destroy(himl);
  return BVar1;
}

