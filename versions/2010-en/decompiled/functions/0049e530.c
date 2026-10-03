
undefined4 FUN_0049e530(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_0049fde0();
  DAT_004ee000 = TlsAlloc();
  if (DAT_004ee000 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_0049cf00(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_004ee000,lpTlsValue);
      if (BVar1 != 0) {
        FUN_0049e590(lpTlsValue);
        DVar2 = GetCurrentThreadId();
        *lpTlsValue = DVar2;
        lpTlsValue[1] = 0xffffffff;
        return 1;
      }
    }
  }
  return 0;
}

