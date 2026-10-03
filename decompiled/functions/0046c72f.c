
void __fastcall FUN_0046c72f(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0xffffffff) {
    BVar1 = FlushFileBuffers(*(HANDLE *)(param_1 + 4));
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      FUN_0046e0e6(DVar2);
    }
  }
  return;
}

