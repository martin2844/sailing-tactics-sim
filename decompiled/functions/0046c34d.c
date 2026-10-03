
int __cdecl FUN_0046c34d(LPWSTR param_1,LPCSTR param_2,int param_3)

{
  int iVar1;
  
  if ((param_3 == 0) && (param_1 != (LPWSTR)0x0)) {
    return 0;
  }
  iVar1 = MultiByteToWideChar(0,0,param_2,-1,param_1,param_3);
  if (0 < iVar1) {
    param_1[iVar1 + -1] = L'\0';
  }
  return iVar1;
}

