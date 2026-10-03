
void FUN_0046ced8(HMODULE param_1,void *param_2)

{
  LPSTR lpszShortPath;
  DWORD DVar1;
  CHAR local_108 [260];
  
  GetModuleFileNameA(param_1,local_108,0x104);
  DVar1 = 0x104;
  lpszShortPath = (LPSTR)FUN_0046c276(param_2,0x104);
  DVar1 = GetShortPathNameA(local_108,lpszShortPath,DVar1);
  if (DVar1 == 0) {
    FUN_0046c00d(param_2,local_108);
  }
  FUN_0046c2c5(param_2,-1);
  return;
}

