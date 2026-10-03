
DWORD __thiscall FUN_0046c652(void *this,LPVOID param_1,DWORD param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  
  if (param_2 == 0) {
    param_2 = 0;
  }
  else {
    BVar1 = ReadFile(*(HANDLE *)((int)this + 4),param_1,param_2,&param_2,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      FUN_0046e0e6(DVar2);
    }
  }
  return param_2;
}

