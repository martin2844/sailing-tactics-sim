
BOOL __fastcall FUN_0045629d(int param_1)

{
  HIMAGELIST himl;
  BOOL BVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  himl = (HIMAGELIST)FUN_00456203(param_1);
  BVar1 = ImageList_Destroy(himl);
  return BVar1;
}

