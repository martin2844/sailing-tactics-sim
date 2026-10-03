
bool FUN_004b110a(HKEY param_1)

{
  LSTATUS LVar1;
  LPBYTE lpData;
  bool bVar2;
  DWORD local_14 [2];
  HKEY local_c;
  HKEY local_8;
  
  bVar2 = false;
  local_c = (HKEY)0x0;
  LVar1 = RegOpenKeyA((HKEY)0x80000000,"CLSID",&local_c);
  if (LVar1 == 0) {
    local_8 = (HKEY)0x0;
    LVar1 = RegOpenKeyA(local_c,(LPCSTR)param_1,&local_8);
    if (LVar1 == 0) {
      param_1 = (HKEY)0x0;
      LVar1 = RegOpenKeyA(local_8,"InProcServer32",&param_1);
      if (LVar1 == 0) {
        lpData = (LPBYTE)FUN_004b0956(0x104);
        local_14[1] = 0x104;
        LVar1 = RegQueryValueExA(param_1,&DAT_005365a4,(LPDWORD)0x0,local_14,lpData,local_14 + 1);
        FUN_004b09a5(0xffffffff);
        bVar2 = LVar1 == 0;
        RegCloseKey(param_1);
      }
      RegCloseKey(local_8);
    }
    RegCloseKey(local_c);
  }
  return bVar2;
}

