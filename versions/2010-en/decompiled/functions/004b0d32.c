
DWORD __thiscall FUN_004b0d32(int param_1,LPVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  
  if (param_3 == 0) {
    param_3 = 0;
  }
  else {
    BVar1 = ReadFile(*(HANDLE *)(param_1 + 4),param_2,param_3,&param_3,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      FUN_004b27c6(DVar2,BVar1);
    }
  }
  return param_3;
}

