
DWORD __thiscall FUN_004b0db7(int param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  DVar1 = SetFilePointer(*(HANDLE *)(param_1 + 4),param_2,(PLONG)0x0,param_3);
  if (DVar1 == 0xffffffff) {
    uVar3 = 0;
    DVar2 = GetLastError();
    FUN_004b27c6(DVar2,uVar3);
  }
  return DVar1;
}

