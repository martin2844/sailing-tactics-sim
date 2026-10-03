
void __thiscall FUN_004b0ee3(int *param_1,undefined4 param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  
  (**(code **)(*param_1 + 0x30))(param_2,0);
  BVar1 = SetEndOfFile((HANDLE)param_1[1]);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    FUN_004b27c6(DVar2,BVar1);
  }
  return;
}

