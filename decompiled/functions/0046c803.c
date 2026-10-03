
void __thiscall FUN_0046c803(void *this,undefined4 param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  (**(code **)(*(int *)this + 0x30))(param_1,0);
  BVar1 = SetEndOfFile(*(HANDLE *)((int)this + 4));
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    FUN_0046e0e6(DVar2);
  }
  return;
}

