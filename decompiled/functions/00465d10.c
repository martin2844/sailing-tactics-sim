
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00465d10(undefined4 param_1,int param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  DWORD DVar2;
  int iVar3;
  
  if (param_2 == 1) {
    hModule = GetModuleHandleA(s_KERNEL32_DLL_004a3380);
    pFVar1 = GetProcAddress(hModule,s_DisableThreadLibraryCalls_004a3364);
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(param_1);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
    DAT_004aff5c = param_1;
    DAT_004aff58 = param_1;
    DVar2 = GetVersion();
    DAT_004aff60 = CONCAT11((char)DVar2,(char)(DVar2 >> 8));
    if (((DVar2 & 0x80000000) == 0) || (DAT_004aff62 = 0x10, 0x35e < DAT_004aff60)) {
      DAT_004aff62 = 0x20;
    }
    _DAT_004b0a34 = GetSystemMetrics(7);
    _DAT_004b0a34 = _DAT_004b0a34 + -1;
    iVar3 = GetSystemMetrics(8);
    DAT_004b0a38 = iVar3 + -1;
    DAT_004b0a3c = GetSystemMetrics(4);
    _DAT_004b0a40 = GetSystemMetrics(0x1e);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  }
  return 1;
}

