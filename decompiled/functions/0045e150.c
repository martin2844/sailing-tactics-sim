
uint __cdecl FUN_0045e150(uint param_1)

{
  bool bVar1;
  
  if (DAT_004aec48 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_004afde8);
    bVar1 = DAT_004afde4 != 0;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_004afde8);
      FUN_0045b730(0x13);
    }
    param_1 = FUN_0045e1e0(param_1);
    if (bVar1) {
      FUN_0045b7b0(0x13);
      return param_1;
    }
    InterlockedDecrement((LONG *)&DAT_004afde8);
  }
  return param_1;
}

