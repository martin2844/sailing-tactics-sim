
void * __thiscall FUN_0047b1ec(void *this,LPCSTR param_1,LPCSTR param_2,void *param_3)

{
  HKEY hKey;
  LSTATUS LVar1;
  void *local_c;
  void *local_8;
  
  local_c = this;
  local_8 = this;
  if (*(int *)((int)this + 0x7c) == 0) {
    param_3 = (void *)GetPrivateProfileIntA
                                (param_1,param_2,(INT)param_3,*(LPCSTR *)((int)this + 0x90));
  }
  else {
    hKey = GetSectionKey(this,param_1);
    if (hKey != (HKEY)0x0) {
      param_1 = (LPCSTR)0x4;
      LVar1 = RegQueryValueExA(hKey,param_2,(LPDWORD)0x0,(LPDWORD)&local_c,(LPBYTE)&local_8,
                               (LPDWORD)&param_1);
      RegCloseKey(hKey);
      if (LVar1 == 0) {
        param_3 = local_8;
      }
    }
  }
  return param_3;
}

