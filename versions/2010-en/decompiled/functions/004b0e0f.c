
void __fastcall FUN_004b0e0f(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0xffffffff) {
    BVar1 = FlushFileBuffers(*(HANDLE *)(param_1 + 4));
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      FUN_004b27c6(DVar2,BVar1);
    }
  }
  return;
}

