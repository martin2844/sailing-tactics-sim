
bool FUN_00470e25(HWND param_1,LPCSTR param_2)

{
  int iVar1;
  CHAR local_24 [32];
  
  GetClassNameA(param_1,local_24,0x20);
  iVar1 = lstrcmpiA(local_24,param_2);
  return (bool)('\x01' - (iVar1 != 0));
}

