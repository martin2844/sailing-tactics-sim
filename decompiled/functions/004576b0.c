
int * __cdecl FUN_004576b0(int param_1)

{
  int *piVar1;
  uint dwBytes;
  
  dwBytes = param_1 + 0xfU & 0xfffffff0;
  if (dwBytes <= DAT_004a2084) {
    FUN_0045b730(9);
    piVar1 = FUN_0045bcc0(param_1 + 0xfU >> 4);
    FUN_0045b7b0(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  piVar1 = HeapAlloc(DAT_004afdec,0,dwBytes);
  return piVar1;
}

