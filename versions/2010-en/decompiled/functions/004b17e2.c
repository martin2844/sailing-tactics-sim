
void __fastcall FUN_004b17e2(undefined4 *param_1)

{
  if ((HGLOBAL)*param_1 != (HGLOBAL)0x0) {
    GlobalFree((HGLOBAL)*param_1);
  }
  return;
}

