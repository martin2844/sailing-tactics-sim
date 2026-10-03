
LPWSTR FUN_0046c382(LPWSTR param_1,LPCSTR param_2,int param_3)

{
  LPWSTR pWVar1;
  
  pWVar1 = (LPWSTR)0x0;
  if (param_2 != (LPCSTR)0x0) {
    *param_1 = L'\0';
    MultiByteToWideChar(0,0,param_2,-1,param_1,param_3);
    pWVar1 = param_1;
  }
  return pWVar1;
}

