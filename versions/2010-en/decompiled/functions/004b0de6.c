
DWORD __fastcall FUN_004b0de6(int param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  DVar1 = SetFilePointer(*(HANDLE *)(param_1 + 4),0,(PLONG)0x0,1);
  if (DVar1 == 0xffffffff) {
    uVar3 = 0;
    DVar2 = GetLastError();
    FUN_004b27c6(DVar2,uVar3);
  }
  return DVar1;
}

