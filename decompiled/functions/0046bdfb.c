
void __fastcall FUN_0046bdfb(int *param_1)

{
  LONG LVar1;
  undefined **ppuVar2;
  
  if ((LONG *)(*param_1 + -0xc) != (LONG *)PTR_DAT_0049f5c0) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      FUN_0046b541((undefined *)(*param_1 + -0xc));
    }
    ppuVar2 = FUN_0046bd74();
    *param_1 = (int)*ppuVar2;
  }
  return;
}

