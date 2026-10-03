
void __fastcall FUN_0046bec5(int *param_1)

{
  LONG LVar1;
  
  if ((LONG *)(*param_1 + -0xc) != (LONG *)PTR_DAT_0049f5c0) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      FUN_0046b541((undefined *)(*param_1 + -0xc));
    }
  }
  return;
}

