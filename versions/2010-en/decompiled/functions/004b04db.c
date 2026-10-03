
void __fastcall FUN_004b04db(int *param_1)

{
  LONG LVar1;
  int *piVar2;
  
  if ((LONG *)(*param_1 + -0xc) != (LONG *)PTR_DAT_004ed788) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      FUN_004afc21(*param_1 + -0xc);
    }
    piVar2 = (int *)FUN_004b0454();
    *param_1 = *piVar2;
  }
  return;
}

