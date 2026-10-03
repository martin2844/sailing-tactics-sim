
void FUN_004b15b8(HMODULE param_1,Tact2010CString *param_2)

{
  LPSTR lpszShortPath;
  DWORD DVar1;
  CHAR local_108 [260];
  
  GetModuleFileNameA(param_1,local_108,0x104);
  DVar1 = 0x104;
  lpszShortPath = (LPSTR)FUN_004b0956(0x104);
  DVar1 = GetShortPathNameA(local_108,lpszShortPath,DVar1);
  if (DVar1 == 0) {
    FUN_004b06ed(param_2,local_108);
  }
  FUN_004b09a5(0xffffffff);
  return;
}

