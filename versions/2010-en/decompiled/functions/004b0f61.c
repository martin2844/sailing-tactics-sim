
void FUN_004b0f61(LPCSTR param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = DeleteFileA(param_1);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    FUN_004b27c6(DVar2,BVar1);
  }
  return;
}

