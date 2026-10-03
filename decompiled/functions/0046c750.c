
void __fastcall FUN_0046c750(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  bool bVar3;
  
  bVar3 = false;
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0xffffffff) {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 4));
    bVar3 = BVar1 == 0;
  }
  *(undefined4 *)(param_1 + 4) = 0xffffffff;
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_0046be50((int *)(param_1 + 0xc));
  if (bVar3) {
    DVar2 = GetLastError();
    FUN_0046e0e6(DVar2);
  }
  return;
}

