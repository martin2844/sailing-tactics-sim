
void __thiscall FUN_0046c68c(void *this,LPCVOID param_1,DWORD param_2)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD DVar3;
  
  DVar1 = param_2;
  if (param_2 != 0) {
    BVar2 = WriteFile(*(HANDLE *)((int)this + 4),param_1,param_2,&param_2,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      FUN_0046e0e6(DVar3);
    }
    if (param_2 != DVar1) {
      FUN_0046e1a7();
    }
  }
  return;
}

