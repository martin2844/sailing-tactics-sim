
DWORD * __fastcall FUN_004c0170(DWORD *param_1)

{
  DWORD DVar1;
  
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[6] = 4;
  param_1[1] = 0;
  param_1[2] = 1;
  param_1[3] = 0;
  param_1[4] = 0;
  DVar1 = TlsAlloc();
  *param_1 = DVar1;
  if (DVar1 == 0xffffffff) {
    FUN_004aa740();
  }
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  return param_1;
}

