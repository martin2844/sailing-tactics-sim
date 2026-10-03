
DWORD __thiscall FUN_0046c6d7(void *this,LONG param_1,DWORD param_2)

{
  DWORD DVar1;
  DWORD DVar2;
  
  DVar1 = SetFilePointer(*(HANDLE *)((int)this + 4),param_1,(PLONG)0x0,param_2);
  if (DVar1 == 0xffffffff) {
    DVar2 = GetLastError();
    FUN_0046e0e6(DVar2);
  }
  return DVar1;
}

