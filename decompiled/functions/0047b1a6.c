
/* Library Function - Multiple Matches With Same Base Name
    public: struct HKEY__ * __thiscall CWinApp::GetSectionKey(char const *)
    public: struct HKEY__ * __thiscall CWinApp::GetSectionKey(wchar_t const *)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release */

HKEY __thiscall GetSectionKey(void *this,LPCSTR param_1)

{
  HKEY hKey;
  void *local_c;
  HKEY local_8;
  
  local_8 = (HKEY)0x0;
  local_c = this;
  hKey = FUN_0047b112((int)this);
  if (hKey == (HKEY)0x0) {
    local_8 = (HKEY)0x0;
  }
  else {
    RegCreateKeyExA(hKey,param_1,0,(LPSTR)0x0,0,0x2001f,(LPSECURITY_ATTRIBUTES)0x0,&local_8,
                    (LPDWORD)&local_c);
    RegCloseKey(hKey);
  }
  return local_8;
}

