
CWnd * __fastcall FUN_004786de(int param_1)

{
  CWnd *pCVar1;
  
  pCVar1 = FUN_004696a2(param_1);
  if (pCVar1 == (CWnd *)0x0) {
    pCVar1 = *(CWnd **)(param_1 + 0x6c);
  }
  return pCVar1;
}

