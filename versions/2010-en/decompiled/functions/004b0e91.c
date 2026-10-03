
void __thiscall FUN_004b0e91(int param_1,DWORD param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = LockFile(*(HANDLE *)(param_1 + 4),param_2,0,param_3,0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    FUN_004b27c6(DVar2,BVar1);
  }
  return;
}

