
void FUN_004b050d(LONG *param_1)

{
  LONG LVar1;
  
  if (param_1 != (LONG *)PTR_DAT_004ed788) {
    LVar1 = InterlockedDecrement(param_1);
    if (LVar1 < 1) {
      FUN_004afc21(param_1);
    }
  }
  return;
}

