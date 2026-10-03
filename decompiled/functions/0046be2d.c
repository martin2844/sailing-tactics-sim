
void FUN_0046be2d(LONG *param_1)

{
  LONG LVar1;
  
  if (param_1 != (LONG *)PTR_DAT_0049f5c0) {
    LVar1 = InterlockedDecrement(param_1);
    if (LVar1 < 1) {
      FUN_0046b541((undefined *)param_1);
    }
  }
  return;
}

