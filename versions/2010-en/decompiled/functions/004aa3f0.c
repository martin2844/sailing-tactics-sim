
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004aa3f0(undefined4 param_1,int param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  DWORD DVar2;
  int iVar3;
  
  if (param_2 == 1) {
    hModule = GetModuleHandleA(s_KERNEL32_DLL_004f1540);
    pFVar1 = GetProcAddress(hModule,s_DisableThreadLibraryCalls_004f1524);
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(param_1);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
    DAT_00539a9c = param_1;
    DAT_00539a98 = param_1;
    DVar2 = GetVersion();
    DAT_00539aa0 = CONCAT11((char)DVar2,(char)(DVar2 >> 8));
    if (((DVar2 & 0x80000000) == 0) || (DAT_00539aa2 = 0x10, 0x35e < DAT_00539aa0)) {
      DAT_00539aa2 = 0x20;
    }
    _DAT_0053a574 = GetSystemMetrics(7);
    _DAT_0053a574 = _DAT_0053a574 + -1;
    iVar3 = GetSystemMetrics(8);
    DAT_0053a578 = iVar3 + -1;
    DAT_0053a57c = GetSystemMetrics(4);
    _DAT_0053a580 = GetSystemMetrics(0x1e);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  }
  return 1;
}

