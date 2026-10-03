
DWORD __fastcall FUN_0046c706(int param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  
  DVar1 = SetFilePointer(*(HANDLE *)(param_1 + 4),0,(PLONG)0x0,1);
  if (DVar1 == 0xffffffff) {
    DVar2 = GetLastError();
    FUN_0046e0e6(DVar2);
  }
  return DVar1;
}

