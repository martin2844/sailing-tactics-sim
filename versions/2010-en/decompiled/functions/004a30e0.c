
int FUN_004a30e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00538888 != (FARPROC)0x0) {
LAB_004a3130:
    if (DAT_0053888c != (FARPROC)0x0) {
      iVar1 = (*DAT_0053888c)();
    }
    if ((iVar1 != 0) && (DAT_00538890 != (FARPROC)0x0)) {
      iVar1 = (*DAT_00538890)(iVar1);
    }
    iVar1 = (*DAT_00538888)(iVar1,param_1,param_2,param_3);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_00538888 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_00538888 != (FARPROC)0x0) {
      DAT_0053888c = GetProcAddress(hModule,"GetActiveWindow");
      DAT_00538890 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_004a3130;
    }
  }
  return 0;
}

