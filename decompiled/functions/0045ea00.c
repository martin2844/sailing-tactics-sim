
int __cdecl FUN_0045ea00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_004aed30 != (FARPROC)0x0) {
LAB_0045ea50:
    if (DAT_004aed34 != (FARPROC)0x0) {
      iVar1 = (*DAT_004aed34)();
    }
    if ((iVar1 != 0) && (DAT_004aed38 != (FARPROC)0x0)) {
      iVar1 = (*DAT_004aed38)(iVar1);
    }
    iVar1 = (*DAT_004aed30)(iVar1,param_1,param_2,param_3);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_004aed30 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_004aed30 != (FARPROC)0x0) {
      DAT_004aed34 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_004aed38 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_0045ea50;
    }
  }
  return 0;
}

