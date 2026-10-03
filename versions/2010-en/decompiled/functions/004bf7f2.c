
HKEY __fastcall FUN_004bf7f2(int param_1)

{
  LSTATUS LVar1;
  DWORD local_14;
  HKEY local_10;
  HKEY local_c;
  HKEY local_8;
  
  local_10 = (HKEY)0x0;
  local_8 = (HKEY)0x0;
  local_c = (HKEY)0x0;
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,"Software",0,0x2001f,&local_8);
  if (LVar1 == 0) {
    LVar1 = RegCreateKeyExA(local_8,*(LPCSTR *)(param_1 + 0x7c),0,(LPSTR)0x0,0,0x2001f,
                            (LPSECURITY_ATTRIBUTES)0x0,&local_c,&local_14);
    if (LVar1 == 0) {
      RegCreateKeyExA(local_c,*(LPCSTR *)(param_1 + 0x90),0,(LPSTR)0x0,0,0x2001f,
                      (LPSECURITY_ATTRIBUTES)0x0,&local_10,&local_14);
    }
  }
  if (local_8 != (HKEY)0x0) {
    RegCloseKey(local_8);
  }
  if (local_c != (HKEY)0x0) {
    RegCloseKey(local_c);
  }
  return local_10;
}

