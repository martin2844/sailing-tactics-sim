
LPVOID FUN_0049bf70(int param_1)

{
  LPVOID pvVar1;
  uint dwBytes;
  
  dwBytes = param_1 + 0xfU & 0xfffffff0;
  if (dwBytes <= DAT_004f0244) {
    FUN_0049fe10(9);
    pvVar1 = (LPVOID)FUN_004a03a0(param_1 + 0xfU >> 4);
    FUN_0049fe90(9);
    if (pvVar1 != (LPVOID)0x0) {
      return pvVar1;
    }
  }
  pvVar1 = HeapAlloc(DAT_0053992c,0,dwBytes);
  return pvVar1;
}

