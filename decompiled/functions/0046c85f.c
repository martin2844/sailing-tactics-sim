
void FUN_0046c85f(LPCSTR param_1,LPCSTR param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = MoveFileA(param_1,param_2);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    FUN_0046e0e6(DVar2);
  }
  return;
}

