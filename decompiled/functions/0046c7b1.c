
void __thiscall FUN_0046c7b1(void *this,DWORD param_1,DWORD param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = LockFile(*(HANDLE *)((int)this + 4),param_1,0,param_2,0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    FUN_0046e0e6(DVar2);
  }
  return;
}

