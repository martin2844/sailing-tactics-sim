
undefined4 FUN_00459e50(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_0045b700();
  DAT_0049fe40 = TlsAlloc();
  if (DAT_0049fe40 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_00458640(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_0049fe40,lpTlsValue);
      if (BVar1 != 0) {
        FUN_00459eb0((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        *lpTlsValue = DVar2;
        lpTlsValue[1] = 0xffffffff;
        return 1;
      }
    }
  }
  return 0;
}

