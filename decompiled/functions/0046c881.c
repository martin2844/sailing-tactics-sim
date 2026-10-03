
void FUN_0046c881(LPCSTR param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = DeleteFileA(param_1);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    FUN_0046e0e6(DVar2);
  }
  return;
}

