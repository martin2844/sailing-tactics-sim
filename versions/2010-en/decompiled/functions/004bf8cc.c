
UINT __thiscall FUN_004bf8cc(UINT param_1,LPCSTR param_2,LPCSTR param_3,UINT param_4)

{
  HKEY hKey;
  LSTATUS LVar1;
  UINT local_c;
  UINT local_8;
  
  local_c = param_1;
  local_8 = param_1;
  if (*(int *)(param_1 + 0x7c) == 0) {
    param_4 = GetPrivateProfileIntA(param_2,param_3,param_4,*(LPCSTR *)(param_1 + 0x90));
  }
  else {
    hKey = (HKEY)GetSectionKey(param_2);
    if (hKey != (HKEY)0x0) {
      param_2 = (LPCSTR)0x4;
      LVar1 = RegQueryValueExA(hKey,param_3,(LPDWORD)0x0,&local_c,(LPBYTE)&local_8,(LPDWORD)&param_2
                              );
      RegCloseKey(hKey);
      if (LVar1 == 0) {
        param_4 = local_8;
      }
    }
  }
  return param_4;
}

